/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


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


#define USART_1                        ((volatile USART_t*)(USART1_BASE_ADD))
#define USART_2                        ((volatile USART_t*)(USART2_BASE_ADD))
#define USART_6                        ((volatile USART_t*)(USART6_BASE_ADD))

typedef struct
{
	u32 BaudRate;

	u8 DataWidth;

	u8 StopBits;

	u8 Parity_Enable;

	u8 Parity_Selection;

	u8 TransferDirection;

	u8 Oversampling;
}USART_InitType;

typedef struct
{
	u8 ClockOutput;
	u8 ClockPolarity;
	u8 ClockPhase;
}USART_ClockInitTypeDef;

/* Baud Rates configurations*/
#define USART_9600_16MHZ         0x682
#define USART_9600_25MHZ         0xA2C
#define USART_19200_16MHZ        0x341
#define USART_19200_25MHZ        0x516
#define USART_115200_16MHZ       0x8A
#define USART_115200_25MHZ       0xD8

#define GetBaudRate(Fpclk, Over8, BaudRate) \
	((Fpclk) / ((8 * (2 - Over8)) * (BaudRate)))



#define OVER_SAMPLING_16          0
#define OVER_SAMPLING_8 	      1

#define USART_TX                  0
#define USART_RX                  1
#define USART_TX_RX               2

#define USART_Even_Parity         0
#define USART_Odd_Parity          1

#define USART_Parity_DISABLE      0
#define USART_Parity_ENABLE       1

#define USART_8_Data_Bits         0
#define USART_9_Data_Bits         1

#define USART_Disable             0
#define USART_Enable              1

#define USART_1_Stop_Bit          0b00
#define USART_05_Stop_Bit         0b01
#define USART_2_Stop_Bit          0b10
#define USART_15_Stop_Bit         0b11



/***************************************************
 * Name        : USART_voidInit                               *
 * Return type : void                                         *
 * Arguments   : A_InitStruct     ->  USART_InitType          *
 *               A_ClockInitStruct->  USART_ClockInitTypeDef  *
 *               USARTx           ->  USART_t                 *
 * Description : set the UART configuration                   *
 **************************************************/
void USART_voidInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx);

/***************************************************
 * Name        : USART_voidSendByte                           *
 * Return type : void                                         *
 * Arguments   : Copy_u8Data      ->u8                        *
 *               USARTx           ->  USART_t                 *
 * Description : Transmit only one byte at a time             *
 **************************************************/
void USART_voidSendByte(USART_t *USARTx,u8 Copy_u8Data);

/***************************************************
 * Name        : USART_voidTransmitString                     *
 * Return type : void                                         *
 * Arguments   : A_ptru8String    ->u8*                       *
 *               USARTx           ->  USART_t                 *
 * Description : Transmit  String                             *
 **************************************************/
void USART_voidSendString (USART_t *USARTx, u8* A_ptru8String );

/***************************************************
 * Name        : USART_u8ReadDataRegister                     *
 * Return type : u8                                           *
 * Arguments   : USARTx           ->  USART_t                 *
 * Description : Read Register Data                           *
 **************************************************/
u8   USART_u8ReadDataRegister(USART_t *USARTx);

/***************************************************
 * Name        : USART_voidReceiveByteSynchBlocking           *
 * Return type : void                                         *
 * Arguments   : USARTx           ->  USART_t                 *
 *               Ptr_u8Data       ->  u8*                     *
 * Description : receive data synchronous blocking            *
 **************************************************/
void USART_voidReceiveByteSynchBlocking(USART_t *USARTx, u8* Ptr_u8Data);

/***************************************************
 * Name        : USART_voidSynchReceiveData                   *
 * Return type : void                                         *
 * Arguments   : USARTx           ->  USART_t                 *
 *               Ptr_u8Data       ->  u8*                     *
 * Description : receive data synchronous Nonblocking         *
 **************************************************/
void USART_voidSynchReceiveDataNonBlocking (USART_t *USARTx, u8* Ptr_u8Data);

void USART1_voidSetCallBack( void (*ptr) (void) );
void USART2_voidSetCallBack( void (*ptr) (void) );
void USART6_voidSetCallBack( void (*ptr) (void) );





#endif



