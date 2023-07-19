/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* options : USART_Rx_Disable                                                                                   */
/*           USART_Rx_Enable                                                                               */
#define USART1_Receiver_Mode         USART_Rx_Enable
#define USART2_Receiver_Mode         USART_Rx_Enable
#define USART6_Receiver_Mode         USART_Rx_Enable


/* options : USART_Tx_Disable                                                                                   */
/*           USART_Tx_Enable                                                                               */
#define USART1_Transmitter_Mode      USART_Tx_Enable
#define USART2_Transmitter_Mode      USART_Tx_Enable
#define USART6_Transmitter_Mode      USART_Tx_Enable


/* options : USART_Even_Parity                                                                                   */
/*           USART_Odd_Parity                                                                               */
#define USART1_Parity_Selection      USART_Even_Parity
#define USART2_Parity_Selection      USART_Even_Parity
#define USART6_Parity_Selection      USART_Even_Parity


/* options : USART_Parity_Control_Disable                                                                                 */
/*           USART_Parity_Control_Enable                                                                               */
#define USART1_Parity_Mode          USART_Parity_Control_Disable
#define USART2_Parity_Mode          USART_Parity_Control_Disable
#define USART6_Parity_Mode          USART_Parity_Control_Disable

/* options : USART_8_Data_Bits                                                                                 */
/*           USART_9_Data_Bits                                                                               */
#define USART1_Word_Length         USART_8_Data_Bits
#define USART2_Word_Length         USART_8_Data_Bits
#define USART6_Word_Length         USART_8_Data_Bits

/* options : USART_Disable                                                                                   */
/*           USART_Enable                                                                               */
#define USART1_Mode                USART_Enable
#define USART2_Mode                USART_Enable
#define USART6_Mode                USART_Enable

/* options : USART_1_Stop_Bit                                                                                   */
/*           USART_0.5_Stop_Bit
 *           USART_2_Stop_Bit
 *           USART_1.5_Stop_Bit                                                                              */
#define USART1_Stop_Bit            USART_1_Stop_Bit
#define USART2_Stop_Bit            USART_1_Stop_Bit
#define USART6_Stop_Bit            USART_1_Stop_Bit

/************************************
 * Baud Rate                        *
 * Options:                         *
 * 		1 -->  USART_9600_16MHZ     *
 * 		2 -->  USART_9600_25MHZ     *
 * 		3 -->  USART_19200_16MHZ    *
 * 		4 -->  USART_19200_25MHZ    *
 * 		5 -->  USART_115200_16MHZ   *
 * 		6 -->  USART_115200_25MHZ   *
 ************************************/
#define USART1_BAUD_RATE       USART_9600_16MHZ
#define USART2_BAUD_RATE       USART_9600_16MHZ
#define USART6_BAUD_RATE       USART_9600_16MHZ

#endif
