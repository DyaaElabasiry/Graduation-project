/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HCAL " STM32F401 "        ************/
/************ Version : 1.00                      ************/
/************ SWC     : Character LCD             ************/
/*************************************************************/
/*************************************************************/


#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#define Starting_Wait                 40
#define Enable_Wait                   2

#define LCD_DATA_WIDTH                8

#define CLR_SCREEN                    0x01

#define _2Lines_5Mul7                 0x38


#define Display_OFF_Cursor_OFF        0x08
#define Display_ON_Cursor_OFF         0x0C
#define Display_ON_Cursor_ON          0x0E
#define Display_ON_Cursor_Blinking    0x0F

#define Start_Position                0x80

#define SECOND_LINE                   0xC0

#define CGRAM_BLOCK_NUMBER            8



#endif /* _LCD_PRIVATE_H_ */
