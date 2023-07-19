/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*******************************USART1***************************************/
void USART1_voidInit(void);
void USART1_voidSendData(u8 Copy_u8Data);
void USART1_voidSynchReceiveData(u8* Ptr_u8Data);



/******************************USART2****************************************/

void USART2_voidInit(void);
void USART2_voidSendData(u8 Copy_u8Data);
void USART2_voidSynchReceiveData(u8* Ptr_u8Data);



/******************************USART6****************************************/

void USART6_voidInit(void);
void USART6_voidSendData(u8 Copy_u8Data);
void USART6_voidSynchReceiveData(u8* Ptr_u8Data);




#endif



