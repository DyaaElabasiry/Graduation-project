/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/


#ifndef		RCC_INTERFACE_H_
#define		RCC_INTERFACE_H_

#define		RCC_AHB1		0
#define		RCC_AHB2		1
#define		RCC_APB1		2
#define		RCC_APB2		3

typedef enum{  
        GPIOA,
	    GPIOB,
	    GPIOC,
	    GPIOD,
	    GPIOE,
	    GPIOH=7,
		CRC =12,
	    DMA1=21,
	    DMA2,
		OTGFS=7,
		TIM2=0,
		TIM3,
		TIM4,
		TIM5,
	    WWDG=11,
        SPI2=14,
		SPI3,
		USART2=17,
		I2C1=21,
		I2C2,
		I2C3,
		PWR=28,
		TIM1=0,
		USART1=4,
		USART6,
		ADC1=8,
		SDIO=11,
		SPI1,
		SPI4,
		SYSCFG,
		TIM9=16,
		TIM10,
		TIM11,
}Peripherals_t;

/*
 * NAME       : RCC_voidSystemClockInit
 * RETURN TYPE: void
 * ARGUMENTS  : void
 * DESCRIPTION: initialize system clock
 */

void  RCC_voidSystemClockInit(void);

/*
 * NAME       : RCC_voidPeripheralClockEnable
 * RETURN TYPE: u8
 * ARGUMENTS:   RCC_u8CopyBus:U8   (AHB,APB1,ABP2)
 * 			    RCC_u8CopyPer : Peripherals_t  (ENUM VALUES)
 * DESCRIPTION: ENABLES PREPHIRAL CLK FOR CERTAIN PERIRHERAL
 */
u8	RCC_voidPeripheralClockEnable(u8 RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral);

/*
 * NAME       : RCC_voidPeripheralClockDisable
 * RETURN TYPE: u8
 * ARGUMENTS:   RCC_u8CopyBus:U8  (AHB,APB1,ABP2)
 * 			    RCC_u8CopyPer : Peripherals_t  (ENUM VALUES)
 * DESCRIPTION: DISABLES PREPHIRAL CLK FOR CERTAIN PERIRHERAL
 */
u8	RCC_voidPeripheralClockDisable(u8 RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral);

#endif
