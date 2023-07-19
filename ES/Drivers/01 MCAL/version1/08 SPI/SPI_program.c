/*************************************************************/
/************ Author  : Habeba Hamada             ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SPI                       ************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"




void SPI1_voidMasterInit(u8 Copy_u8DataOrder, u8 Copy_u8ClockPolatrity, u8 Copy_u8ClockPhase, u8 Copy_u8ClockRate)
{
	
	/*
	 * Set the Baud Rate
	 * 000: FPCLK/2
     * 001: FPCLK/4
     * 010: FPCLK/8
     * 011: FPCLK/16
     * 100: FPCLK/32
     * 101: FPCLK/64
     * 110: FPCLK/128
     * 111: FPCLK/256
	 */
	SPI1->CR1 |= (Copy_u8ClockRate << BR);
	
	
	
		/*
	 * Set Clock Polarity
	 * 0: CK to 0 when idle
	 * 1: CK to 1 when idle
	 */
	SPI1->CR1 |= (Copy_u8ClockPolatrity << CPOL);

	/*
	 * Set Clock Phase
	 * 0: The first clock transition is the first data capture edge
	 * 1: The second clock transition is the first data capture edge
	 */
	SPI1->CR1 |= (Copy_u8ClockPhase << CHPA);




	/* Set the Data Frame Format to 8-bits */
	CLEAR_BIT(SPI1->CR1, DFF);



	/*
	 * Set Data Order
	 * 0: MSB transmitted first
	 * 1: LSB transmitted first
	 */
	SPI1->CR1 |= (Copy_u8DataOrder << LSBFIRST);


	/* Set Software Slave management */
	SPI1->CR1 |= (3 << SSI);



	/* Choose Master Configurations */
	SPI1->CR1 |= (1 << MSTR);



	/* SPI Enable */
	SET_BIT(SPI1->CR1, SPE);
}




void SPI1_voidSlaveInit(u8 Copy_u8DataOrder, u8 Copy_u8ClockPolatrity, u8 Copy_u8ClockPhase)
{
	
	
	/* Set the Data Frame Format to 8-bits */
	CLEAR_BIT(SPI1->CR1, DFF);
	
	/*
	 * Set Clock Phase
	 * 0: The first clock transition is the first data capture edge
	 * 1: The second clock transition is the first data capture edge
	 */
	SPI1->CR1 |= (Copy_u8ClockPhase << CHPA);


	/*
	 * Set Clock Polarity
	 * 0: CK to 0 when idle
	 * 1: CK to 1 when idle
	 */
	SPI1->CR1 |= (Copy_u8ClockPolatrity << CPOL);

	/*
	 * Set Data Order
	 * 0: MSB transmitted first
	 * 1: LSB transmitted first
	 */
	SPI1->CR1 |= (Copy_u8DataOrder << LSBFIRST);


	/* Set Software Slave management */
	SPI1->CR1 |= (0 << SSM);


	/* Choose Slave Configurations */
	SPI1->CR1 &= ~(1 << MSTR);



	/* Set Mode to Full duplex */
	SPI1->CR1 &= ~(1 << RXONLY);


	/* SPI Enable */
	SPI1->CR1 |= (1 << SPE);
}


u8 SPI1_u8SynchTransceive(u8 Copy_u8Data)
{
	/* Put the Data to Data Register */
	SPI1->DR = Copy_u8Data;

	/* Wait until Transmission and Reception is complete */
	while(!GET_BIT(SPI1->SR, TXE));
	while(GET_BIT(SPI1->SR, BSY));

	/* Return the Received Data */
	return SPI1->DR;
}


void SPI2_voidMasterInit(u8 Copy_u8DataOrder, u8 Copy_u8ClockPolatrity, u8 Copy_u8ClockPhase, u8 Copy_u8ClockRate)
{

	/*
	 * Set the Baud Rate
	 * 000: FPCLK/2
     * 001: FPCLK/4
     * 010: FPCLK/8
     * 011: FPCLK/16
     * 100: FPCLK/32
     * 101: FPCLK/64
     * 110: FPCLK/128
     * 111: FPCLK/256
	 */
	SPI2->CR1 |= (Copy_u8ClockRate << BR);



		/*
	 * Set Clock Polarity
	 * 0: CK to 0 when idle
	 * 1: CK to 1 when idle
	 */
	SPI2->CR1 |= (Copy_u8ClockPolatrity << CPOL);

	/*
	 * Set Clock Phase
	 * 0: The first clock transition is the first data capture edge
	 * 1: The second clock transition is the first data capture edge
	 */
	SPI2->CR1 |= (Copy_u8ClockPhase << CHPA);




	/* Set the Data Frame Format to 8-bits */
	CLEAR_BIT(SPI2->CR1, DFF);



	/*
	 * Set Data Order
	 * 0: MSB transmitted first
	 * 1: LSB transmitted first
	 */
	SPI2->CR1 |= (Copy_u8DataOrder << LSBFIRST);


	/* Set Software Slave management */
	SPI2->CR1 |= (3 << SSI);



	/* Choose Master Configurations */
	SPI2->CR1 |= (1 << MSTR);



	/* SPI Enable */
	SET_BIT(SPI2->CR1, SPE);
}



u8 SPI2_u8SynchTransceive(u8 Copy_u8Data)
{
	/* Put the Data to Data Register */
	SPI2->DR = Copy_u8Data;

	/* Wait until Transmission and Reception is complete */
	while(!GET_BIT(SPI2->SR, TXE));
	while(GET_BIT(SPI2->SR, BSY));

	/* Return the Received Data */
	return SPI2->DR;
}

/******************************************************************************************************************/



/*u8* SPI1_u8SynchTransceiveString(u8* Copy_u8Data)
{
	/* Counter to iterate through the String Elements */
/*	u8 Local_u8Counter = 0;

	/* Array to Save the Received String */
/*	u8* Local_pu8Received;


	/* Wait till the end of the String */
/*	while(Copy_u8Data[Local_u8Counter] != '\0')
	{
		/* Send and Receive the String byte by byte */
/*		Local_pu8Received[Local_u8Counter] = SPI1_u8SynchTransceive(Copy_u8Data[Local_u8Counter]);

		/* Increment the Counter to go to the next Element in the String */
/*		Local_u8Counter++;
	}

	/* Last Element of the Received String must be Null character */
/*	Local_pu8Received[Local_u8Counter] = '\0';

	/* Return the Received String */
/*	return Local_pu8Received;
}*/



