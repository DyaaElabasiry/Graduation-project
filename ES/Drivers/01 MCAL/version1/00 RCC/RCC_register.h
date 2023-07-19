/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_

#define RCC_BASE_ADD                (u32)(0x40023800)
						           
#define RCC_CR                      *((volatile u32*)(RCC_BASE_ADD +0X00))
						           
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
						            
#define RCC_PLLCFGR                 *((volatile u32*)(RCC_BASE_ADD +0X04))

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
						            
#define RCC_CFGR                    *((volatile u32*)(RCC_BASE_ADD +0X08))

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

#define RCC_CIR                     *((volatile u32*)(RCC_BASE_ADD +0X0c))
					             
					             
#define RCC_AHB1RSTR                *((volatile u32*)(RCC_BASE_ADD +0X10))

#define RCC_AHB1RSTR_GPIOARST       0
#define RCC_AHB1RSTR_GPIOBRST       1
#define RCC_AHB1RSTR_GPIOCRST       2

#define RCC_AHB2RSTR                *((volatile u32*)(RCC_BASE_ADD +0X14))
#define RCC_APB1RSTR                *((volatile u32*)(RCC_BASE_ADD +0X20))
#define RCC_APB2RSTR                *((volatile u32*)(RCC_BASE_ADD +0X24))
						            
#define RCC_AHB1ENR                 *((volatile u32*)(RCC_BASE_ADD +0X30))

#define RCC_AHB1ENR_GPIOAEN         0
#define RCC_AHB1ENR_GPIOBEN         1
#define RCC_AHB1ENR_GPIOCEN         2

#define RCC_AHB2ENR                 *((volatile u32*)(RCC_BASE_ADD +0X34))
#define RCC_APB1ENR                 *((volatile u32*)(RCC_BASE_ADD +0X40))
#define RCC_APB2ENR                 *((volatile u32*)(RCC_BASE_ADD +0X44))
						            
#define RCC_BDCR                    *((volatile u32*)(RCC_BASE_ADD +0X70))
#define RCC_CSR                     *((volatile u32*)(RCC_BASE_ADD +0X74))


#endif