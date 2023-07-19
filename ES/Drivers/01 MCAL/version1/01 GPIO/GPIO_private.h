/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

u16* const GPIO_u8Arr_ODR[3]={&GPIOA_ODR,&GPIOB_ODR,&GPIOC_ODR};
u16* const GPIO_u8Arr_IDR[3]= {&GPIOA_IDR,&GPIOB_IDR,&GPIOC_IDR};

	
#define GPIO_NumOfPins   16
#define GPIO_NumOfPorts  3


	
#endif
