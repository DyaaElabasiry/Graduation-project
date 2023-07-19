/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/


#ifndef		RCC_INTERFACE_H_
#define		RCC_INTERFACE_H_

#define		RCC_AHB1		0
#define		RCC_AHB2		1
#define		RCC_APB1		2
#define		RCC_APB2		3

typedef enum{  
        RCC_GPIOA,
		RCC_GPIOB,
		RCC_GPIOC,
		RCC_GPIOD,
		RCC_GPIOE,
		RCC_GPIOH=7,
		RCC_CRC =12,
		RCC_DMA1=21,
		RCC_DMA2,
		RCC_OTGFS=7,
		RCC_TIM2=0,
		RCC_TIM3,
		RCC_TIM4,
		RCC_TIM5,
		RCC_WWDG=11,
		RCC_SPI2=14,
		RCC_SPI3,
		RCC_USART2=17,
		RCC_I2C1=21,
		RCC_I2C2,
		RCC_I2C3,
		RCC_PWR=28,
		RCC_TIM1=0,
		RCC_USART1=4,
		RCC_USART6,
		RCC_ADC1=8,
		RCC_SDIO=11,
		RCC_SPI1,
		RCC_SPI4,
		RCC_SYSCFG,
		RCC_TIM9=16,
		RCC_TIM10,
		RCC_TIM11,
}Peripherals_t;

void	RCC_voidSystemClockInit(void);

/*
 * NAME:RCC_voidPeripheralClockEnable
 * RETURN TYPE: u8
 * ARGUMENTS: RCC_u8CopyBus:U8 , (AHB,APB1,ABP2)
 * 			  RCC_u8CopyPer : Peripherals_t , (ENUM VALUES)
 * DESCRIPTION: ENABLES PREPHIRAL CLK FOR CERTAIN PREPHIRAL
 */
u8	RCC_voidPeripheralClockEnable(u8 RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral);

/*
 * NAME:RCC_voidPeripheralClockDisable
 * RETURN TYPE: u8
 * ARGUMENTS: RCC_u8CopyBus:U8 , (AHB,APB1,ABP2)
 * 			  RCC_u8CopyPer : Peripherals_t , (ENUM VALUES)
 * DESCRIPTION: DISABLES PREPHIRAL CLK FOR CERTAIN PERIRHERAL
 */
u8	RCC_voidPeripheralClockDisable(u8 RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral);

#endif
