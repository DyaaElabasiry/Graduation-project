/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HCAL " STM32F401 "        ************/
/************ Version : 1.00                      ************/
/************ SWC     : Character LCD             ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"
#include "Software_Delay.h"

#include "GPIO_interface.h"

#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/* Set RS pin to low for command */
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_PIN_LOW);

	/* Set RW pin to low for write*/
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, GPIO_PIN_LOW);

	/* Send the command to the data pins*/
	GPIO_voidSetGroupChannel(LCD_DATA_PORT, LCD_DATA_STARTING_PIN, LCD_DATA_WIDTH, Copy_u8Command);

	/* Send Enable pulse */
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_PIN_HIGH);
	_delay_ms(Enable_Wait);
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_PIN_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS pin to high for Data */
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, GPIO_PIN_HIGH);

	/* Set RW pin to low for write*/
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, GPIO_PIN_LOW);

	/* Send the command to the data pins*/
	GPIO_voidSetGroupChannel(LCD_DATA_PORT, LCD_DATA_STARTING_PIN, LCD_DATA_WIDTH, Copy_u8Data);

	/* Send Enable pulse */
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_PIN_HIGH);
	_delay_ms(Enable_Wait);
	GPIO_SetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, GPIO_PIN_LOW);
}

void LCD_voidInit(void)
{
	/* Wait for more than 30ms */
	_delay_ms(Starting_Wait);

	/* Function Set Command : 2 Lines and 5*7 Font size */
	LCD_voidSendCommand(_2Lines_5Mul7);

	/* Display ON/OFF Command : Display Enable, Cursor Disable and No Blinking Cursor*/
	LCD_voidSendCommand(LCD_Display);

	/* Display Clear Command */
	LCD_voidSendCommand(CLR_SCREEN);

	/* Set Cursor Start Position */
	LCD_voidSendCommand(Start_Position);
}

void LCD_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	/* For the second line display add 0x40 to the Address */
	u8 Local_u8Address = (Copy_u8XPosition * 0x40) + (Copy_u8YPosition);

	/* Set bit 7 for DDRAM Address Command then send the Command */
	LCD_voidSendCommand(Local_u8Address + 128);
}

void LCD_voidSendString(const char* Ptr_u8Data, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	u8 Local_u8DataCounter = 0;
	u8 Local_u8AddressCounter = 0;

	LCD_voidSetCursor(Copy_u8XPosition, Copy_u8YPosition);

	while(Ptr_u8Data[Local_u8DataCounter] != '\0')
	{
		LCD_voidSendData(Ptr_u8Data[Local_u8DataCounter++]);
		Local_u8AddressCounter++;

		if((Local_u8AddressCounter) == (16 - Copy_u8YPosition) && Copy_u8XPosition == LCD_Row_1)
		{
			LCD_voidSendCommand(SECOND_LINE);
			Local_u8AddressCounter = 0;
			Copy_u8YPosition = 0;
			Copy_u8XPosition = LCD_Row_2;
		}
	}
}

void LCD_voidWriteSpecialCharacter(const char* Ptr_u8Data, u8 Copy_u8BlockNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	u8 Local_u8Counter;

	/* Calculate CGRAM address whose each block is 8 bytes */
	u8 Local_u8CGRAMAddress = 8 * Copy_u8BlockNumber;

	/* Send CGRAM command to LCD, with setting bit 6 and clearing bit 7 */
	LCD_voidSendCommand(Local_u8CGRAMAddress + 64);

	/* Writing The pattern to the CGRAM */
	for(Local_u8Counter = 0; Local_u8Counter < CGRAM_BLOCK_NUMBER; Local_u8Counter++)
	{
		LCD_voidSendData(Ptr_u8Data[Local_u8Counter]);
	}

	/* Go back to the DDRAM to display data */
	LCD_voidSetCursor(Copy_u8XPosition, Copy_u8YPosition);

	/* Display the pattern written in the CGRAM */
	LCD_voidSendData(Copy_u8BlockNumber);
}

void LCD_voidWriteNumber(u32 Copy_u32Number, u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	u8 Local_u8Counter = 0;
	u32 Local_u32Number = Copy_u32Number;

	while(Local_u32Number != 0)
	{
		Local_u32Number /= 10;
		Local_u8Counter++;
	}

	while(Copy_u32Number != 0)
	{
		LCD_voidSetCursor(Copy_u8XPosition, (Copy_u8YPosition + (--Local_u8Counter)));
		LCD_voidSendData((Copy_u32Number % 10) + 48);
		Copy_u32Number /= 10;
	}
}
