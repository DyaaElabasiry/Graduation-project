/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 3.00            ****************/
/*************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
	
#define GPIO_u8NumOfPins   16
#define GPIO_u8NumOfPorts  3

typedef struct{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_Port_t;


#define GPIOA     ((volatile GPIO_Port_t*)(0x40020000))
#define GPIOB     ((volatile GPIO_Port_t*)(0x40020400))
#define GPIOC     ((volatile GPIO_Port_t*)(0x40020800))

/**********************************************************************************************************************/

#endif
