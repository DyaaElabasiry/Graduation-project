/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    USART			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*Timeout of sending data*/
#define USART_u32TIMEOUT					50000

/*Choosing the data size will be transmitted*/
/*Options:
 *FIVE_BITS
 *SIX_BITS
 *SEVEN_BITS
 *EIGHT_BITS
 *NINE_BITS
 * */
#define DATA_SIZE				EIGHT_BITS

/*Choosing the mode of USART*
 *Options:
 *SYNCHRONOUS
 *ASYNCHRONOUS
 */
#define USART_OPERATION_MODE	ASYNCHRONOUS

/*Selecting Stop bits*/
/*Options:
 * ONE_STOP_BIT
 * TWO_STOP_BITS
 */
#define STOP_BITS				ONE_STOP_BIT

/*Selecting Parity Mode*/
/*Options:
 * DISABLED
 * ENABLED_EVEN_PARITY
 * ENABLED_ODD_PARITY
 * */
#define PARITY_MODE				DISABLED

/*Selecting baud rate with Fos 8MHz*/
/*Options:
 *RATE_2400
 *RATE_4800
 *RATE_9600
 *RATE_14_4K
 *RATE_19_2K
 *RATE_28_8K
 *RATE_38_4K
 *RATE_57_6K
 *RATE_76_8K
 *RATE_115_2K
 *RATE_230_4K
 *RATE_250K
 * */
#define BAUD_RATE				RATE_9600

#endif
