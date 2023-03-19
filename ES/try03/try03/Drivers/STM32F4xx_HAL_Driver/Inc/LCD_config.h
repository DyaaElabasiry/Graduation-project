/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HCAL " STM32F401 "        ************/
/************ Version : 1.00                      ************/
/************ SWC     : Character LCD             ************/
/*************************************************************/
/*************************************************************/


#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_


/*
	Choose Port for both Data pins and Control pins:
	Options:
		1) GPIO_PORTA
		2) GPIO_PORTB
		3) GPIO_PORTC
*/
#define LCD_DATA_PORT             GPIO_PORTA
#define LCD_CONTROL_PORT          GPIO_PORTC


/*
	Choose Data pins and Control pins:
	NOTE --> make sure to choose 8 consecutive pins for Data pins
	Options:
		1)  GPIO_PORTA_Pin0
		2)  GPIO_PORTA_Pin1
		3)  GPIO_PORTA_Pin2
		4)  GPIO_PORTA_Pin3
		5)  GPIO_PORTA_Pin4
		6)  GPIO_PORTA_Pin5
		7)  GPIO_PORTA_Pin6
		8)  GPIO_PORTA_Pin7
		9)  GPIO_PORTA_Pin8
		10) GPIO_PORTA_Pin9
		11) GPIO_PORTA_Pin10
		12) GPIO_PORTA_Pin11
		13) GPIO_PORTA_Pin12
		14) GPIO_PORTA_Pin15


		15) GPIO_PORTB_Pin0
		16) GPIO_PORTB_Pin1
		17) GPIO_PORTB_Pin2
		18) GPIO_PORTB_Pin5
		19) GPIO_PORTB_Pin6
		20) GPIO_PORTB_Pin7
		21) GPIO_PORTB_Pin8
		22) GPIO_PORTB_Pin9
		23) GPIO_PORTB_Pin10
		24) GPIO_PORTB_Pin11
		25) GPIO_PORTB_Pin12
		26) GPIO_PORTB_Pin13
		27) GPIO_PORTB_Pin14
		28) GPIO_PORTB_Pin15


		29) GPIO_PORTC_Pin13
		30) GPIO_PORTC_Pin14
		31) GPIO_PORTC_Pin15
*/
#define LCD_DATA_STARTING_PIN     GPIO_PIN0
#define LCD_RS_PIN                GPIO_PIN13
#define LCD_RW_PIN                GPIO_PIN14
#define LCD_E_PIN                 GPIO_PIN15


/*
	Display Options:
		1) Display_OFF_Cursor_OFF
		2) Display_ON_Cursor_OFF
		3) Display_ON_Cursor_ON
		4) Display_ON_Cursor_Blinking
*/
#define LCD_Display              Display_ON_Cursor_OFF




#endif /* _LCD_CONFIG_H_ */
