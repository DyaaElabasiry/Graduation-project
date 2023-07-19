/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include"STD_TYPES.h"
#include"BIT_Manipulation.h"
#include"RCC_register.h"
#include"RCC_private.h"
#include"RCC_config.h"
#include"RCC_interface.h"


void	RCC_voidSysClkInit(void)
{
	/****************** AHB Prescaler ******************/
	RCC_CFGR= BitManipulationSetBits(RCC_CFGR,RCC_CFGR_HPRE0,4,RCC_u8SYSCLK_Division_by_2);

	/****************** APB1 Prescaler ******************/
	ASSIGN_BIT(RCC_CFGR,RCC_CFGR_PPRE10,GET_BIT(RCC_u8APB1_PRESCALER,0));
	ASSIGN_BIT(RCC_CFGR,RCC_CFGR_PPRE11,GET_BIT(RCC_u8APB1_PRESCALER,1));
	ASSIGN_BIT(RCC_CFGR,RCC_CFGR_PPRE12,GET_BIT(RCC_u8APB1_PRESCALER,2));
	/****************** APB2 Prescaler ******************/
	ASSIGN_BIT(RCC_CFGR,RCC_CFGR_PPRE20,GET_BIT(RCC_u8APB2_PRESCALER,0));
	ASSIGN_BIT(RCC_CFGR,RCC_CFGR_PPRE21,GET_BIT(RCC_u8APB2_PRESCALER,1));
	ASSIGN_BIT(RCC_CFGR,RCC_CFGR_PPRE22,GET_BIT(RCC_u8APB2_PRESCALER,2));
	
    /*************** Clock Security System ***************/
  	ASSIGN_BIT(RCC_CR,RCC_CR_CSSON,GET_BIT(RCC_u8CSSON,0));
	/*************** Clock Source Switch ***************/
   RCC_CFGR= BitManipulationSetBits(RCC_CFGR,RCC_CFGR_SW0,2,System_Clk_Source);
   
   /******************MCO1,2 Source Selection*************/
   RCC_CFGR = BitManipulationSetBits(RCC_CFGR,RCC_CFGR_MCO10,2,Microcontroller_Clk_Output1);
   RCC_CFGR = BitManipulationSetBits(RCC_CFGR,RCC_CFGR_MCO20,2,Microcontroller_Clk_Output2);
	
   /******************MCO1,2 Prescaler*************/
   RCC_CFGR= BitManipulationSetBits(RCC_CFGR,RCC_CFGR_MCO1PRE0,3,Microcontroller_Clk1_Prescaler);
   RCC_CFGR= BitManipulationSetBits(RCC_CFGR,RCC_CFGR_MCO2PRE0,3,Microcontroller_Clk2_Prescaler);

	
	#if RCC_u8PLL_Mode==RCC_u8Clk_Enable
	RCC_PLLCFGR=BitManipulationSetBits(RCC_PLLCFGR,RCC_PLLCFGR_PLLM0,6,PLL_InClk_Division_Factor);
    RCC_PLLCFGR=BitManipulationSetBits(RCC_PLLCFGR,RCC_PLLCFGR_PLLN0,9,PLL_VCO_Multiplication_Factor);
	RCC_PLLCFGR=BitManipulationSetBits(RCC_PLLCFGR,RCC_PLLCFGR_PLLP0,2,PLL_MainClk_Division_Factor);
    ASSIGN_BIT(RCC_PLLCFGR,RCC_PLLCFGR_PLLSRC,PLL_Clk_Source);
	RCC_PLLCFGR=BitManipulationSetBits(RCC_PLLCFGR,RCC_PLLCFGR_PLLQ0,4,PLL_USB_OTG_Division_Factor);
	
	
	
	ASSIGN_BIT(RCC_CR,RCC_CR_PLLON,GET_BIT(RCC_u8PLL_Mode  ,0));
	while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY));

	#endif
	
	#if RCC_u8HSEON_Mode==RCC_u8Clk_Enable
	/*************** Clock By Pass Enable ***************/
  	ASSIGN_BIT(RCC_CR,RCC_CR_HSEBYP,GET_BIT(RCC_u8HSEPYB,0));
	ASSIGN_BIT(RCC_CR,RCC_CR_HSEON,GET_BIT(RCC_u8HSEON_Mode,0));
	
	while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY));

    #endif
	
	#if RCC_u8HSION_Mode==RCC_u8Clk_Enable

    ASSIGN_BIT(RCC_CR,RCC_CR_HSION,GET_BIT(RCC_u8HSION_Mode,0));
	while(!GET_BIT(RCC_CR,RCC_CR_HSERDY));

    #endif	
	
}
  
u8	RCC_voidEnablePerClk(u8 RCC_u8CopyBus,u8 RCC_u8CopyPer)
{
	u8 Local_u8Error=OK;
	if (RCC_u8CopyPer<32)
	{
		switch(RCC_u8CopyBus)
		{
			case RCC_AHB1: SET_BIT(RCC_AHB1ENR,RCC_u8CopyPer);break;
			case RCC_AHB2: SET_BIT(RCC_AHB2ENR,RCC_u8CopyPer);break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR,RCC_u8CopyPer);break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR,RCC_u8CopyPer);break;
			default : Local_u8Error =NOK;

			
		}
			
	}
	else
	{
		
		Local_u8Error =NOK;
		
	}
		
		
	return Local_u8Error;
	
	
}

u8	RCC_voidDisablePerClk(u8 RCC_u8CopyBus,u8 RCC_u8CopyPer)
{
	u8 Local_u8Error=OK;
	if (RCC_u8CopyPer<32)
	{
		switch(RCC_u8CopyBus)
		{
			case RCC_AHB1: CLEAR_BIT(RCC_AHB1ENR,RCC_u8CopyPer);break;
			case RCC_AHB2: CLEAR_BIT(RCC_AHB2ENR,RCC_u8CopyPer);break;
			case RCC_APB1: CLEAR_BIT(RCC_APB1ENR,RCC_u8CopyPer);break;
			case RCC_APB2: CLEAR_BIT(RCC_APB2ENR,RCC_u8CopyPer);break;
			default : Local_u8Error =NOK;

			
		}
			
	}
	else
	{
		
		Local_u8Error =NOK;
		
	}
		
		
	return Local_u8Error;
	
	
}

