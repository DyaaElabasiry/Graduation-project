/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


typedef enum
{
	USART_SR_PE,                  /* Start of USART SR Register*/
	USART_SR_FE,
	USART_SR_NF,
	USART_SR_ORE,
	USART_SR_IDLE,
	USART_SR_RXNE,
	USART_SR_TC,
	USART_SR_TXE,
	USART_SR_LBD,
	USART_SR_CTS,
	USART_BRR_DIV_Fractions = 0,  /* Start of USART BRR Register*/
	USART_BRR_DIV_Mantissa = 4,
	USART_CR1_SBK = 0,             /* Start of USART CR1 Register*/
	USART_CR1_RWU,
	USART_CR1_RE,
	USART_CR1_TE,
	USART_CR1_IDLEIE,
	USART_CR1_RXNEIE,
	USART_CR1_TCIE,
	USART_CR1_TXEIE,
	USART_CR1_PEIE,
	USART_CR1_PS,
	USART_CR1_PCE,
	USART_CR1_WAKE,
	USART_CR1_M,
	USART_CR1_UE,
	USART_CR1_OVER8 = 15,
	USART_CR2_ADD = 0,            /* Start of USART CR2 Register*/
	USART_CR2_LBDL = 5,
	USART_CR2_LBDIE,
	USART_CR2_LBCL = 8,
	USART_CR2_CPHA,
	USART_CR2_CPOL,
	USART_CR2_CLKEN,
	USART_CR2_STOP,
	USART_CR2_LINEN = 14,
	USART_CR3_EIE = 0,            /* Start of USART CR3 Register*/
	USART_CR3_IREN,
	USART_CR3_IRLP,
	USART_CR3_HDSEL,
	USART_CR3_NACK,
	USART_CR3_SCEN,
	USART_CR3_DMAR,
	USART_CR3_DMAT,
	USART_CR3_RTSE,
	USART_CR3_CTSE,
	USART_CR3_CTSIE,
	USART_CR3_ONEBIT,
	USART_GTPR_PSC = 0,           /* Start of USART GPTR Register*/
	USART_GTPR_GT = 8,
}USART_Reg_Pins_t;





#endif



