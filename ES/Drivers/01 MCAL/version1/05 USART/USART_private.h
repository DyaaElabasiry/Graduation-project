/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define USART1_BASE_ADD                (u32)(0x40011000)
#define USART2_BASE_ADD                (u32)(0x40004400)
#define USART6_BASE_ADD                (u32)(0x40011400)


typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR ;
}USART_t;


#define USART1                        ((volatile USART_t*)(USART1_BASE_ADD))
#define USART2                        ((volatile USART_t*)(USART2_BASE_ADD))
#define USART6                        ((volatile USART_t*)(USART6_BASE_ADD))


#define USART_SR_PE                    0
#define USART_SR_FE                    1
#define USART_SR_NF                    2
#define USART_SR_ORE                   3
#define USART_SR_IDLE                  4
#define USART_SR_RXNE                  5
#define USART_SR_TC                    6
#define USART_SR_TXE                   7


#define USART_BRR_DIV_Fraction0        0
#define USART_BRR_DIV_Mantissa0        4

#define USART_CR1_SBK                  0
#define USART_CR1_RWU                  1
#define USART_CR1_RE                   2
#define USART_CR1_TE                   3
#define USART_CR1_IDLEIE               4
#define USART_CR1_RXNEIE               5
#define USART_CR1_TCIE                 6
#define USART_CR1_TXEIE                7
#define USART_CR1_PEIE                 8
#define USART_CR1_PS                   9
#define USART_CR1_PCE                  10
#define USART_CR1_WAKE                 11
#define USART_CR1_M                    12
#define USART_CR1_UE                   13
#define USART_CR1_OVER8                15


#define USART_CR2_CPHA                 9
#define USART_CR2_CPOL                 10
#define USART_CR2_CLKEN                11
#define USART_CR2_STOP0                12
#define USART_CR2_STOP1                13


/********************************************************************************************/

#define USART_Rx_Disable         0
#define USART_Rx_Enable          1

#define USART_Tx_Disable         0
#define USART_Tx_Enable          1

#define USART_Even_Parity        0
#define USART_Odd_Parity         1

#define USART_Parity_Control_Disable   0
#define USART_Parity_Control_Enable    1

#define USART_8_Data_Bits        0
#define USART_9_Data_Bits        1

#define USART_Disable            0
#define USART_Enable             1

#define USART_1_Stop_Bit          0b00
#define USART_05_Stop_Bit         0b01
#define USART_2_Stop_Bit          0b10
#define USART_15_Stop_Bit         0b11


/* Baud Rates */
#define USART_9600_16MHZ         0x682
#define USART_9600_25MHZ         0xA2C
#define USART_19200_16MHZ        0x341
#define USART_19200_25MHZ        0x516
#define USART_115200_16MHZ       0x8A
#define USART_115200_25MHZ       0xD8

#define GetBaudRate(Fpclk, Over8, BaudRate) \
	((Fpclk) / ((8 * (2 - Over8)) * (BaudRate)))


#endif



