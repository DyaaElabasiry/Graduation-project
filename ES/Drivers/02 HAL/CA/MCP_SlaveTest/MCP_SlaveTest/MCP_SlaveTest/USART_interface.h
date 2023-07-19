/*****************************************************************/
/*****************************************************************/
/*****************		Author: Mohamed Magdy	******************/
/*****************		Layer:  MCAL			******************/
/*****************		SWC:    USART			******************/
/*****************		Version:1.00 			******************/
/*****************************************************************/
/*****************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);

u8 USART_u8SendCharSynch(u8 Copy_u8Data);
u8 USART_u8SendCharAsynch(u8* Copy_u8Data,void(*Copy_pvNotificationFunc)(void));

u8 USART_u8RecieveCharSynch(void);
u8 USART_u8RecieveCharAsynch(u8* Copy_u8RecievedData,void(*Copy_pvNotificationFunc)(void));

u8 USART_u8SendStringSynch(const char* Copy_charString);
u8 USART_u8SendStringAsynch(char* Copy_charString,void(*Copy_pvNotificationFunc)(void));

u8 USART_u8RecieveBufferSynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize);
u8 USART_u8RecieveBufferAsynch(u8* Copy_pu8Buffer,u8 Copy_u8BufferSize,void(*Copy_pvNotificationFunc)(void));

#endif
