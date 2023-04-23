/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef		RCC_PRIVATE_H_
#define		RCC_PRIVATE_H_

#define RCC_BASE_ADD                (u32)(0x40023800)

typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1 ;
	u32 reserved2 ;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved3 ;
	u32 reserved4 ;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved5 ;
	u32 reserved6 ;
	u32 APB1ENR;
	u32 APB2ENR;
}RCC_t;


#define RCC  ((volatile RCC_t*)(RCC_BASE_ADD))



#define RCC_CR_HSION                0
#define RCC_CR_HSIRDY               1
#define RCC_CR_HSEON                16
#define RCC_CR_HSERDY               17
#define RCC_CR_HSEBYP               18
#define RCC_CR_CSSON                19
#define RCC_CR_PLLON                24
#define RCC_CR_PLLRDY               25
#define RCC_CR_PLLI2SON             26
#define RCC_CR_PLLI2SRDY            27


#define RCC_PLLCFGR_PLLM0           0
#define RCC_PLLCFGR_PLLM1           1
#define RCC_PLLCFGR_PLLM2           2
#define RCC_PLLCFGR_PLLM3           3
#define RCC_PLLCFGR_PLLM4           4
#define RCC_PLLCFGR_PLLM5           5
#define RCC_PLLCFGR_PLLN0           6
#define RCC_PLLCFGR_PLLN1           7
#define RCC_PLLCFGR_PLLN2           8
#define RCC_PLLCFGR_PLLN3           9
#define RCC_PLLCFGR_PLLN4           10
#define RCC_PLLCFGR_PLLN5           11
#define RCC_PLLCFGR_PLLN6           12
#define RCC_PLLCFGR_PLLN7           13
#define RCC_PLLCFGR_PLLN8           14
#define RCC_PLLCFGR_PLLP0           16
#define RCC_PLLCFGR_PLLP1           17
#define RCC_PLLCFGR_PLLSRC          22
#define RCC_PLLCFGR_PLLQ0           24
#define RCC_PLLCFGR_PLLQ1           25
#define RCC_PLLCFGR_PLLQ2           26
#define RCC_PLLCFGR_PLLQ3           27


#define RCC_CFGR_SW0                0
#define RCC_CFGR_SW1                1
#define RCC_CFGR_SWS0               2         /*Read only*/
#define RCC_CFGR_SWS1               3         /*Read only*/
#define RCC_CFGR_HPRE0              4
#define RCC_CFGR_HPRE1              5
#define RCC_CFGR_HPRE2              6
#define RCC_CFGR_HPRE3              7
#define RCC_CFGR_PPRE10             10
#define RCC_CFGR_PPRE11             11
#define RCC_CFGR_PPRE12             12
#define RCC_CFGR_PPRE20             13
#define RCC_CFGR_PPRE21             14
#define RCC_CFGR_PPRE22             15
#define RCC_CFGR_RTCPRE0            16
#define RCC_CFGR_RTCPRE1            17
#define RCC_CFGR_RTCPRE2            18
#define RCC_CFGR_RTCPRE3            19
#define RCC_CFGR_RTCPRE4            20
#define RCC_CFGR_MCO10              21
#define RCC_CFGR_MCO11              22
#define RCC_CFGR_I2SSRC             23
#define RCC_CFGR_MCO1PRE0           24
#define RCC_CFGR_MCO1PRE1           25
#define RCC_CFGR_MCO1PRE2           26
#define RCC_CFGR_MCO2PRE0           27
#define RCC_CFGR_MCO2PRE1           28
#define RCC_CFGR_MCO2PRE2           29
#define RCC_CFGR_MCO20              30
#define RCC_CFGR_MCO21              31



#define RCC_AHB1RSTR_GPIOARST       0
#define RCC_AHB1RSTR_GPIOBRST       1
#define RCC_AHB1RSTR_GPIOCRST       2


#define RCC_AHB1ENR_GPIOAEN         0
#define RCC_AHB1ENR_GPIOBEN         1
#define RCC_AHB1ENR_GPIOCEN         2



/****************************************************************************/

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
#define RCC_u8HSI_SYSCLK              0b00
#define RCC_u8HSE_SYSCLK              0b01
#define RCC_u8PLL_SYSCLK              0b10

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
#define HSI_MCO1_Selected               0b00
#define LSE_MCO1_Selected               0b01
#define HSE_MCO1_Selected               0b10
#define PLL_MCO1_Selected               0b11

/* Microcontroller clock output 2 selection  */
#define SYSCLK_MCO2_Selected            0b00
#define PLLI2S_MCO2_Selected            0b01
#define HSE_MCO2_Selected               0b10
#define PLL_MCO2_Selected               0b11


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
