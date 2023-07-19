/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_Manipulation.h"


#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

/***************************************************
 * Name        : USART1_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Sets the Baud Rate                *
 **************************************************/
void USART1_voidInit(void)
{
	/* Set the Baud Rate */
	USART1->BRR = USART1_BAUD_RATE;

	/**************Stop Bit*********************/
	USART1->CR2|=(USART1_Stop_Bit<<USART_CR2_STOP0);
	
	/**************Parity Bit*********************/
	USART1->CR1|=(USART1_Parity_Selection<<USART_CR1_PS);
	USART1->CR1|=(USART1_Parity_Mode<<USART_CR1_PCE);

	/*************Word Length*********************/
	USART1->CR1|=(USART1_Word_Length<<USART_CR1_M);

	/*************Transmitter Enable*********************/
	USART1->CR1|=(USART1_Transmitter_Mode<<USART_CR1_TE);
	/*************Receiver Enable*********************/
	USART1->CR1|=(USART1_Receiver_Mode<<USART_CR1_RE);

	/*************USART Enable*********************/
	USART1->CR1|=(USART1_Mode<<USART_CR1_UE);



}
void USART1_voidSendData(u8 Copy_u8Data)
{
	while(GET_BIT(USART1->SR,USART_SR_TXE)==0);
	USART1->DR=Copy_u8Data;
	
}
void USART1_voidSynchReceiveData(u8* Ptr_u8Data)
{
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(!(GET_BIT(USART1->SR, USART_SR_RXNE)));

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USART1->DR;
	}
	else
	{
		
	}
	
}
