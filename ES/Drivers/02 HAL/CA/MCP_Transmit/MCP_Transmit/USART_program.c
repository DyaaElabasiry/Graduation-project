/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    USART			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "USART_register.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"

/*For Characters*/
static void (*USART_pvTransmitterNotificationFunction)(void) = NULL;
static void (*USART_pvRecieverNotificationFunction)(void) = NULL;

static void(*USART_pvStringTransmittedNotifiFunc)(void)=NULL;
static void(*USART_pvBufferNotificationFunction)(void)=NULL;

static u8* USART_pu8TransmittedData;
static u8* USART_pu8RecievedData = NULL;

static char* USART_pStringTransmitted = NULL;
static u8* USART_pu8BufferRecieved = NULL;
static u8 GLobal_u8StringCounter = 0;
static u8 GLobal_u8BufferCounter = 0;
static u8 Global_u8BufferSize;

/*State of USART Sending*/
u8	USART_u8TransmitterBusyState = IDLE;
u8	USART_u8RecieverBusyState = IDLE;
/*Source of Transmitter ISR*/
u8 USART_u8TransmitterISRSource = SINGLE_CHAR;
/*Source of Reciever ISR*/
u8 USART_u8RecieverISRSource = RECIEVE_CHAR;

void USART_voidInit(void)
{
	u8 Local_u8UCSRC=0b10000000;
	/*Choosing the mode of USART */
#if USART_OPERATION_MODE == ASYNCHRONOUS
	SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#elif USART_OPERATION_MODE ==SYNCHRONOUS
	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#endif

	/*Initialize the size of data*/
#if DATA_SIZE == FIVE_BITS
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
#elif DATA_SIZE == SIX_BITS
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
#elif DATA_SIZE == SEVEN_BITS
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
#elif DATA_SIZE == EIGHT_BITS
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
#elif DATA_SIZE == NINE_BITS
	SET_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
#endif

	/*Selecting Parity Mode*/
#if PARITY_MODE == DISABLED
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
#elif PARITY_MODE == ENABLED_EVEN_PARITY
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
#elif PARITY_MODE == ENABLED_ODD_PARITY
	SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
	SET_BIT(Local_u8UCSRC,UCSRC_UPM0);
#endif

	/*Selecting Stop bits*/
#if STOP_BITS == ONE_STOP_BIT
	CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#elif STOP_BITS == TWO_STOP_BITS
	SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);
#endif

	/*Finally put the values in UCSRC*/
	UCSRC = Local_u8UCSRC;

	//Do calculation of baud rates with eqns by putting in variable the first 8 bit by typecasting in UBBRL
	//then take the same variable and shift it 8 times in UBBRH
	/*Selecting Baud rate with Fos 8MHz*/
#if BAUD_RATE == RATE_2400
	UBRRL = 207;
#elif BAUD_RATE == RATE_4800
	UBRRL = 103;
#elif BAUD_RATE == RATE_9600
	UBRRL = 51;
#elif BAUD_RATE == RATE_14_4K
	UBRRL = 34;
#elif BAUD_RATE == RATE_19_2K
	UBRRL = 25;
#elif BAUD_RATE == RATE_28_8K
	UBRRL = 16;
#elif BAUD_RATE == RATE_38_4K
	UBRRL = 12;
#elif BAUD_RATE == RATE_57_6K
	UBRRL = 8;
#elif BAUD_RATE == RATE_76_8K
	UBRRL = 6;
#elif BAUD_RATE == RATE_115_2K
	UBRRL = 3;
#elif BAUD_RATE == RATE_230_4K
	UBRRL = 1;
#elif BAUD_RATE == RATE_250K
	UBRRL = 1;
#endif

	/*Enable Transmitter and Reciever*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
}

u8 USART_u8SendCharSynch(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter = 0;

	if(USART_u8TransmitterBusyState == IDLE)
	{
		/*Make USART State busy*/
		USART_u8TransmitterBusyState = BUSY;

		//Wait untill the transmit buffer is empty
		while((GET_BIT(UCSRA,UCSRA_UDRE) == 0) && (Local_u32Counter!=USART_u32TIMEOUT))
		{
			Local_u32Counter++;
		}
		if(USART_u32TIMEOUT == Local_u32Counter)
		{
			Local_u8ErrorState = NOT_OK;
		}
		else
		{
			UDR = Copy_u8Data;
			USART_u8TransmitterBusyState = IDLE;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}


u8 USART_u8SendCharAsynch(u8* Copy_u8Data,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(USART_u8TransmitterBusyState == IDLE)
	{
		if(Copy_pvNotificationFunc == NULL || Copy_u8Data == NULL)
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/*Make the USART State busy*/
			USART_u8TransmitterBusyState = BUSY;

			/*Let ISR Know the source of interrupt*/
			USART_u8TransmitterISRSource = SINGLE_CHAR;

			/*Initialize USART call back notification function will be used in ISR*/
			USART_pvTransmitterNotificationFunction = Copy_pvNotificationFunc;

			/*Initialize the transmitted data*/
			USART_pu8TransmittedData = Copy_u8Data;

			/*Store the in UDR*/
			UDR = *USART_pu8TransmittedData;

			/*Enable Trasmitter Interrupt*/
			SET_BIT(UCSRB,UCSRB_UDRIE);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

u8 USART_u8SendStringSynch(const char* Copy_charString)
{
	u8 Local_u8Indexing=0;
	u8 Local_u8ErrorState = OK;
	if(Copy_charString == NULL)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else
	{
		while(*(Copy_charString+Local_u8Indexing) != '\0')
		{
			USART_u8SendCharSynch(*(Copy_charString+Local_u8Indexing));
			Local_u8Indexing++;
		}
	}
	return Local_u8ErrorState;
}


u8 USART_u8SendStringAsynch(char* Copy_charString,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(USART_u8TransmitterBusyState == IDLE)
	{
		if(Copy_charString == NULL || Copy_pvNotificationFunc == NULL)
		{
			Local_u8ErrorState = NOT_OK;
		}
		else
		{
			/*Make the USART State busy*/
			USART_u8TransmitterBusyState = BUSY;

			/*Let ISR Know the source of interrupt*/
			USART_u8TransmitterISRSource = STRING;

			/*Initialize call back notification Function*/
			USART_pvStringTransmittedNotifiFunc = Copy_pvNotificationFunc;

			/*Initialize string Data*/
			USART_pStringTransmitted = Copy_charString;

			/*Make first counter point to the first char in string and send it*/
//			UDR = *(USART_pStringTransmitted+GLobal_u8StringCounter);

			/*Enable Trasmitter Interrupt*/
			SET_BIT(UCSRB,UCSRB_UDRIE);
		}
	}
	else
	{
		Local_u8ErrorState =BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

u8 USART_u8RecieveCharSynch(void)
{
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter=0;
	while((GET_BIT(UCSRA,UCSRA_RXC) == 0) && (Local_u32Counter!=USART_u32TIMEOUT)) //Polling untill the recieving process complete
	{
		Local_u32Counter++;
	}

	if(Local_u32Counter == USART_u32TIMEOUT)
	{
		Local_u8ErrorState = NOT_OK;
	}
	else
	{
		return UDR;
	}
	return Local_u8ErrorState;
}

u8 USART_u8RecieveCharAsynch(u8* Copy_u8RecievedData,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if (USART_u8RecieverBusyState == IDLE)
	{
		if((Copy_pvNotificationFunc == NULL) || (Copy_u8RecievedData == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/*Make the reciever state busy*/
			USART_u8RecieverBusyState = BUSY;

			/*Setting the Source of ISR*/
			USART_u8RecieverISRSource = RECIEVE_CHAR;

			/*Initialize the recieved data reading*/
			USART_pu8RecievedData = Copy_u8RecievedData;

			/*Initialize Call back notification Function*/
			USART_pvRecieverNotificationFunction = Copy_pvNotificationFunc;

			/*Enable Reciever Interrupt*/
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}
	}
	else
	{
		Local_u8ErrorState =BUSY_FUNC;
	}

	return Local_u8ErrorState;
}


u8 USART_u8RecieveBufferSynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8Counter = 0;
	if(Copy_pu8Buffer == NULL)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else
	{
		for(Local_u8Counter = 0 ; Local_u8Counter< Copy_u8BufferSize ; Local_u8Counter++)
		{
			Copy_pu8Buffer[Local_u8Counter]=USART_u8RecieveCharSynch();
		}
	}
	return Local_u8ErrorState;
}


u8 USART_u8RecieveBufferAsynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(USART_u8RecieverBusyState == IDLE)
	{
		if ((*Copy_pu8Buffer == NULL) || (*Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState =NULL_POINTER;
		}
		else
		{
			/*Setting the Source of ISR*/
			USART_u8RecieverISRSource = BUFFER;

			/*Initialize Buffer Globally*/
			USART_pu8BufferRecieved = Copy_pu8Buffer;

			/*Initialize call back function*/
			USART_pvBufferNotificationFunction = Copy_pvNotificationFunc;

			/*Initialize the buffer size*/
			Global_u8BufferSize = Copy_u8BufferSize;

			/*Initialize first index in buffer*/
			GLobal_u8BufferCounter=0;

			/*Enable Reciever Interrupt*/
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

/*ISR of Tx USART*/
void __vector_14(void) __attribute((signal));
void __vector_14(void)
{
	if(USART_u8TransmitterISRSource == SINGLE_CHAR)
	{

		/*Let the state of USART back to idle*/
		USART_u8TransmitterBusyState = IDLE;

		/*Disable Transmitter Interrupt*/
		CLR_BIT(UCSRB,UCSRB_UDRIE);

		/*Invoke call back notification function*/
		USART_pvTransmitterNotificationFunction();
	}
	else if(USART_u8TransmitterISRSource == STRING)
	{
//		/*Store the char in UDR*/
		UDR = *(USART_pStringTransmitted+GLobal_u8StringCounter);

		/*Increasing the counter of string iterator */
		GLobal_u8StringCounter++;

		/*Check string is transmitted or not*/
		if(*(USART_pStringTransmitted+GLobal_u8StringCounter) == '\0')
		{
			/*Let the state of USART back to idle*/
			USART_u8TransmitterBusyState = IDLE;

			/*Disable Transmitter Interrupt*/
			CLR_BIT(UCSRB,UCSRB_UDRIE);

			/*Invoke call back notification function*/
			USART_pvStringTransmittedNotifiFunc();

			GLobal_u8StringCounter=0;
		}

	}
}

/*ISR of Rx USART*/
void __vector_13(void) __attribute((signal));
void __vector_13(void)
{
	if(USART_u8RecieverISRSource == RECIEVE_CHAR)
	{
		/*READ the Recieved data from UDR register*/
		*USART_pu8RecievedData = UDR;

		/*Let the state of reciever back idle*/
		USART_u8RecieverBusyState =IDLE;

		/*Disable Reciever Interrupt*/
		CLR_BIT(UCSRB,UCSRB_RXCIE);

		/*Invoke call back notification function*/
		USART_pvRecieverNotificationFunction();
	}
	else if(USART_u8RecieverISRSource == BUFFER)
	{
		/*Recieve elements of buffer*/
		*(USART_pu8BufferRecieved+GLobal_u8BufferCounter) = UDR;

		/*Increment to the next element*/
		GLobal_u8BufferCounter++;

		if(GLobal_u8BufferCounter == Global_u8BufferSize)
		{
			/*Make the busy state idle again*/
			USART_u8RecieverBusyState = IDLE;

			/*Disable Reciever Interrupt*/
			CLR_BIT(UCSRB,UCSRB_RXCIE);

			/*Invoke call back function*/
			USART_pvBufferNotificationFunction();

			GLobal_u8BufferCounter=0;
		}
	}
}
