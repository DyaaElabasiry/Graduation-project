/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_Manipulation.h"


#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void (*USART1_CallBack)(void);
void (*USART2_CallBack)(void);
void (*USART6_CallBack)(void);

void USART_voidInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx)
{
	/* Set the Baud Rate */
	USARTx->BRR = A_InitStruct->BaudRate;


	USARTx->CR1 = (A_InitStruct->Oversampling << USART_CR1_OVER8)    |
			(A_InitStruct->DataWidth <<USART_CR1_M)                  |
			(A_InitStruct->Parity_Enable <<USART_CR1_PCE)            |
			(A_InitStruct->Parity_Selection <<USART_CR1_PS)          ;

	switch (A_InitStruct->TransferDirection)
	{
	case USART_TX:               SET_BIT(USARTx->CR1, USART_CR1_TE); break;
	case USART_RX:               SET_BIT(USARTx->CR1, USART_CR1_RE); break;
	case USART_TX_RX:            SET_BIT(USARTx->CR1, USART_CR1_TE);
	                             SET_BIT(USARTx->CR1, USART_CR1_RE); break;
	}

	USARTx->CR2 =  (A_InitStruct->StopBits<<USART_CR2_STOP)	         |
			(A_ClockInitStruct->ClockOutput <<USART_CR2_CLKEN)       |
			(A_ClockInitStruct->ClockPhase <<USART_CR2_CPHA)         |
			(A_ClockInitStruct->ClockPolarity <<USART_CR2_CPOL)      ;

	/*    USART ENABLE */
	SET_BIT(USARTx->CR1, USART_CR1_UE);

}


void USART_voidSendByte(USART_t *USARTx,u8 Copy_u8Data)
{
	/* wait until transmission data is empty */
	while(GET_BIT(USARTx->SR, USART_SR_TXE) == 0);

	/* put data to data register this step will clear the TXE flag */
	USARTx->DR = Copy_u8Data;

	/* wait until transmission is complete */
	while(GET_BIT(USARTx->SR, USART_SR_TC) == 0);

	/* clear TC flag */
	CLEAR_BIT(USARTx->SR, USART_SR_TC);
}



void USART_voidSendString (USART_t *USARTx, u8* A_ptru8String )
{
	/*Iterator to iterate over the string*/
	u8 local_u8Iterator =0;

	/*while the string is not End*/
	while (A_ptru8String[local_u8Iterator] != '\0')
	{
		/*send string byte by byte*/
		USART_voidSendByte(USARTx, A_ptru8String[local_u8Iterator]);
		local_u8Iterator++;
	}
}


u8   USART_u8ReadDataRegister(USART_t *USARTx)
{
	return USARTx -> DR;
}


void USART_voidReceiveByteSynchBlocking(USART_t *USARTx, u8* Ptr_u8Data)
{
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(GET_BIT(USARTx->SR, USART_SR_RXNE)==0);

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USARTx->DR;
	}
	else
	{

	}

}



void USART_voidSynchReceiveDataNonBlocking ( USART_t *USARTx, u8* Ptr_u8Data )
{

	u32 loc_u8TimeOut = 0;
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(!(GET_BIT(USARTx->SR, USART_SR_RXNE)) && (loc_u8TimeOut < THRESHOLD_VALUE))
		{
			loc_u8TimeOut++;
		}

		if (loc_u8TimeOut==THRESHOLD_VALUE)
		{
			*(Ptr_u8Data) =255;
		}
		else
		{
			/* Store the Data to the Pointer */
			*(Ptr_u8Data) = USARTx->DR;
		}
	}
	else
	{

	}
}



void USART1_voidSetCallBack( void (*ptr) (void) )
{
	USART1_CallBack = ptr ;
}

void USART2_voidSetCallBack( void (*ptr) (void) )
{
	USART2_CallBack = ptr ;
}

void USART6_voidSetCallBack( void (*ptr) (void) )
{
	USART6_CallBack = ptr ;
}

void USART1_IRQHandler(void)
{
	USART_1 -> SR = 0 ;
	USART1_CallBack();
}

void USART2_IRQHandler(void)
{
	USART_2 -> SR = 0 ;
	USART2_CallBack();
}

void USART6_IRQHandler(void)
{
	USART_6 -> SR = 0 ;
	USART6_CallBack();
}
