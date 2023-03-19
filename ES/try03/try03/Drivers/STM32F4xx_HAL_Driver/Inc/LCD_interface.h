/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HCAL " STM32F401 "        ************/
/************ Version : 1.00                      ************/
/************ SWC     : Character LCD             ************/
/*************************************************************/
/*************************************************************/
/*************************************************************

     VSS  VDD  V0   RS   RW    E   D0   D1   D2   D3   D4   D5   D6   D7    A    K
      |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	 ------------------------------------------------------------------------------
	| ---------------------------------------------------------------------------- |
	||																			  ||
	||																			  ||
	||																			  ||
	| ---------------------------------------------------------------------------- |
	 ------------------------------------------------------------------------------

Power Pins:
	VSS     --> GND
	VDD     --> 5v
	V0      --> Power Supply to control contrast " You can use potentiometer to control contrast "

Control Pins:
	RS      --> Register Select:   0 for Command -- 1 for Data
	RW      --> Read\!Write:       0 for writing -- 1 for reading
	E       --> Enable

Data Pins:
	D0--D7  --> 8-bit data pins used to send information to the LCD

LED Backlight Pins:
	A       --> LED power supply 5v
	K       --> LED power supply 0v

**************************************************************/


#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_


#define LCD_Row_1              		0
#define LCD_Row_2              		1

#define LCD_Column_1           		0
#define LCD_Column_2           		1
#define LCD_Column_3           		2
#define LCD_Column_4           		3
#define LCD_Column_5           		4
#define LCD_Column_6           		5
#define LCD_Column_7           		6
#define LCD_Column_8           		7
#define LCD_Column_9           		8
#define LCD_Column_10          		9
#define LCD_Column_11          		10
#define LCD_Column_12          		11
#define LCD_Column_13          		12
#define LCD_Column_14          		13
#define LCD_Column_15          		14
#define LCD_Column_16          		15

#define LCD_CGRAM_Block_1      		0
#define LCD_CGRAM_Block_2      		1
#define LCD_CGRAM_Block_3      		2
#define LCD_CGRAM_Block_4      		3
#define LCD_CGRAM_Block_5      		4
#define LCD_CGRAM_Block_6      		5
#define LCD_CGRAM_Block_7      		6
#define LCD_CGRAM_Block_8     	    7

#define LCD_Second_Line_Pos0        0xC0

#define LCD_Clear_Display           0x01

#define LCD_Special_Character_Size  8


void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_voidSetCursor(u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void LCD_voidSendString(const char* Ptr_u8Data, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void LCD_voidWriteSpecialCharacter(const char* Ptr_u8Data, u8 Copy_u8BlockNumber, u8 Copy_u8XPosition, u8 Copy_u8YPosition);

void LCD_voidWriteNumber(u32 Copy_u32Number, u8 Copy_u8XPosition, u8 Copy_u8YPosition);


#endif /* _LCD_INTERFACE_H_ */
