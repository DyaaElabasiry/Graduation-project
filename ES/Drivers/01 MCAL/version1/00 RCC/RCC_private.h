/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

/* CLK Security system enable modes       */
#define RCC_u8CLK_DETECTOR_ON         1
#define RCC_u8CLK_DETECTOR_OFF        0

#define RCC_u8BYPASSED                1
#define RCC_u8NOT_BYPASSED            0

#define RCC_u8Clk_Enable              1
#define RCC_u8Clk_Disable             0

/* PLL Clock Source Selection */     
#define HSIClk_Selected               0
#define HSEClk_Selected               1

/* System clock switch modes to select SYSCLK source  */
#define RCC_u8HSI_SYSCLK              00
#define RCC_u8HSE_SYSCLK              01
#define RCC_u8PLL_SYSCLK              10

/* AHB prescaler modes to control AHB clock division factor      */
#define RCC_u8SYSCLK_Division_by_1           0b0000
#define RCC_u8SYSCLK_Division_by_2           0b1000
#define RCC_u8SYSCLK_Division_by_4           0b1001
#define RCC_u8SYSCLK_Division_by_8           0b1010
#define RCC_u8SYSCLK_Division_by_16          0b1011
#define RCC_u8SYSCLK_Division_by_64          0b1100
#define RCC_u8SYSCLK_Division_by_128         0b1101
#define RCC_u8SYSCLK_Division_by_256         0b1110
#define RCC_u8SYSCLK_Division_by_512         0b1111

/* APB1, APB2 prescaler modes control APB1,APB2 clock division factor   */
#define RCC_u8AHB_CLK_Division_by_1          0b000
#define RCC_u8AHB_CLK_Division_by_2          0b100
#define RCC_u8AHB_CLK_Division_by_4          0b101
#define RCC_u8AHB_CLK_Division_by_8          0b110
#define RCC_u8AHB_CLK_Division_by_16         0b111

/* Microcontroller clock output 1 selection  */
#define HSI_MCO1_Selected               00
#define LSE_MCO1_Selected               01
#define HSE_MCO1_Selected               10
#define PLL_MCO1_Selected               11

/* Microcontroller clock output 2 selection  */
#define SYSCLK_MCO2_Selected            00
#define PLLI2S_MCO2_Selected            01
#define HSE_MCO2_Selected               10
#define PLL_MCO2_Selected               11


/* MCO1, MCO2 prescaler modes control MCO1, MCO2 clock division factor */
#define RCC_u8MCO_CLK_Division_No            0b000
#define RCC_u8MCO_CLK_Division_by_2          0b100
#define RCC_u8MCO_CLK_Division_by_3          0b101
#define RCC_u8MCO_CLK_Division_by_4          0b110
#define RCC_u8MCO_CLK_Division_by_5          0b111

/*GPIO A,B,C Reset options*/
#define RCC_u8GPIO_Reset               1
#define RCC_u8GPIO_Reset_NO            0
	

#endif