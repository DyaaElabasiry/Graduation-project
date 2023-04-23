/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*************************************************************************************************/
#define  GPIO_PORTA    0
#define  GPIO_PORTB    1
#define  GPIO_PORTC    2


#define  GPIO_PIN_HIGH    1
#define  GPIO_PIN_LOW     0


#define  GPIO_PORT_HIGH      0XFFFF
#define  GPIO_PORT_LOW        0

/*Note: PORTA doesn't have pin 13,14 and PORTC has only 13,14,15 pins*/
typedef enum{  
        GPIO_PIN0 ,
	    GPIO_PIN1 ,
	    GPIO_PIN2 ,
	    GPIO_PIN3 ,
	    GPIO_PIN4 ,
	    GPIO_PIN5 ,
		GPIO_PIN6 ,
	    GPIO_PIN7 ,
	    GPIO_PIN8 ,
		GPIO_PIN9 ,
		GPIO_PIN10,
		GPIO_PIN11,
		GPIO_PIN12,
		GPIO_PIN13,
	    GPIO_PIN14,
        GPIO_PIN15,
	
}Pins_t;





/**********************************************************************************************************/



u8  GPIO_SetPortValue(u8 Copy_u8Port, u16 Copy_u8Value);

u8  GPIO_GetPortValue(u8 Copy_u8Port, u16* Copy_u8PTRvalue);

u8  GPIO_SetPinValue(u8 Copy_u8Port,Pins_t Copy_u8Pin, u8 Copy_u8Value);

u8  GPIO_GetPinValue(u8 Copy_u8Port, Pins_t Copy_u8Pin, u8* Copy_u8PTRvalue);

void  GPIO_SetPinValue_BSRR(u8 Copy_u8Port,Pins_t Copy_u8Pin, u8 Copy_u8Value);


void GPIO_voidSetGroupChannel(u8 Copy_u8Port,Pins_t Copy_u8StartPin,u8 Copy_u8ChannelWidth,u16 Copy_u8Value);

#endif



