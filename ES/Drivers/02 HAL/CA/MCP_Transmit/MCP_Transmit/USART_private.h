/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    USART			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define FIVE_BITS				0
#define SIX_BITS				1
#define SEVEN_BITS				2
#define EIGHT_BITS				3
#define NINE_BITS				4

#define SYNCHRONOUS				0
#define ASYNCHRONOUS			1

#define ONE_STOP_BIT			0
#define TWO_STOP_BITS			1

#define DISABLED           		0
#define ENABLED_EVEN_PARITY		1
#define ENABLED_ODD_PARITY 		2

#define RATE_2400				0
#define RATE_4800				1
#define RATE_9600				2
#define RATE_14_4K				3
#define RATE_19_2K				4
#define RATE_28_8K				5
#define RATE_38_4K				6
#define RATE_57_6K				7
#define RATE_76_8K				8
#define RATE_115_2K				9
#define RATE_230_4K				10
#define RATE_250K				11

#define IDLE					0
#define BUSY					1

#define SINGLE_CHAR				0
#define STRING					1

#define RECIEVE_CHAR			0
#define BUFFER					1

#endif
