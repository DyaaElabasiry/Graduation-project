/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*************************************************************************************************/
#define  GPIO_PORTA    0
#define  GPIO_PORTB    1
#define  GPIO_PORTC    2


/*Note: PORTA doesn't have pin 13,14 and PORTC has only 13,14,15 pins*/
#define  GPIO_PIN0     0
#define  GPIO_PIN1     1
#define  GPIO_PIN2     2
#define  GPIO_PIN3     3
#define  GPIO_PIN4     4
#define  GPIO_PIN5     5
#define  GPIO_PIN6     6
#define  GPIO_PIN7     7
#define  GPIO_PIN8     8
#define  GPIO_PIN9     9
#define  GPIO_PIN10    10
#define  GPIO_PIN11    11
#define  GPIO_PIN12    12
#define  GPIO_PIN13    13
#define  GPIO_PIN14    14
#define  GPIO_PIN15    15



#define  GPIO_PIN_HIGH    1
#define  GPIO_PIN_LOW     0


#define  GPIO_PORT_HIGH      0XFFFF
#define  GPIO_PORT_LOW        0


/**********************************************************************************************************/



u8  GPIO_SetPortValue(u8 Copy_u8Port, u16 Copy_u8Value);

u8  GPIO_GetPortValue(u8 Copy_u8Port, u16* Copy_u8PTRvalue);

u8  GPIO_SetPinValue( u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Value);

u8  GPIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8PTRvalue);

void GPIO_SetGroupChannel(u8 Copy_u8Port,u8 Copy_u8StartPin,u8 Copy_u8ChannelWidth,u16 Copy_u8Value);

#endif



