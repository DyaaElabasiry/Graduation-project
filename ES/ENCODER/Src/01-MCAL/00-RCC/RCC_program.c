/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"

#include"RCC_private.h"
#include"RCC_config.h"
#include"RCC_interface.h"


void	RCC_voidSystemClockInit(void)
{

    /******************MCO1,2 Prescaler*************/
  	RCC->CFGR|=(Microcontroller_Clk1_Prescaler<<RCC_CFGR_MCO1PRE0);
	RCC->CFGR|=(Microcontroller_Clk2_Prescaler<<RCC_CFGR_MCO2PRE0);

    /******************MCO1,2 Source Selection*************/
	RCC->CFGR|=(Microcontroller_Clk_Output1<<RCC_CFGR_MCO10);
  	RCC->CFGR|=(Microcontroller_Clk_Output2<<RCC_CFGR_MCO20);


    /*************** Clock Security System ***************/
  	RCC->CR|=(RCC_u8CSSON<<RCC_CR_CSSON);

	/*************** Clock Source Switch ***************/
  	RCC->CFGR|=(System_Clk_Source<<RCC_CFGR_SW0);

	/****************** AHB Prescaler ******************/
  	RCC->CFGR|=(RCC_u8AHB_PRESCALER<<RCC_CFGR_HPRE0);


	/****************** APB1 Prescaler ******************/
  	RCC->CFGR|=(RCC_u8APB1_PRESCALER<<RCC_CFGR_PPRE10);
	/****************** APB2 Prescaler ******************/
	
  	RCC->CFGR|=(RCC_u8APB2_PRESCALER<<RCC_CFGR_PPRE20);



	
	#if RCC_u8PLL_Mode==RCC_u8Clk_Enable
  	RCC->PLLCFGR=0;
  	RCC->PLLCFGR|=(PLL_InClk_Division_Factor<<RCC_PLLCFGR_PLLM0);
  	RCC->PLLCFGR|=(PLL_VCO_Multiplication_Factor<<RCC_PLLCFGR_PLLN0);
  	RCC->PLLCFGR|=(PLL_MainClk_Division_Factor<<RCC_PLLCFGR_PLLP0);
  	RCC->PLLCFGR|=(PLL_Clk_Source<<RCC_PLLCFGR_PLLSRC);
  	RCC->PLLCFGR|=(PLL_USB_OTG_Division_Factor<<RCC_PLLCFGR_PLLQ0);

	
  	RCC->CR|=(RCC_u8PLL_Mode<<RCC_CR_PLLON);

	while(!GET_BIT(RCC->CR,RCC_CR_PLLRDY));

	#endif
	
	#if RCC_u8HSEON_Mode==RCC_u8Clk_Enable
	/*************** Clock By Pass Enable ***************/
  	RCC->CR|=(RCC_u8HSEPYB<<RCC_CR_HSEBYP);
  	RCC->CR|=(RCC_u8HSEON_Mode<<RCC_CR_HSEON);

	while(!GET_BIT(RCC->CR,RCC_CR_HSIRDY));

    #endif
	
	#if RCC_u8HSION_Mode==RCC_u8Clk_Enable
  	RCC->CR|=(RCC_u8HSION_Mode<<RCC_CR_HSION);

	while(!GET_BIT(RCC->CR,RCC_CR_HSERDY));

    #endif	
	
}
  
u8	RCC_voidPeripheralClockEnable(u8 RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral)
{
	u8 Local_u8Error=OK;
	if (RCC_u8CopyPeripheral<32)
	{
		switch(RCC_u8CopyBus)
		{
			case RCC_AHB1: SET_BIT(RCC->AHB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_AHB2: SET_BIT(RCC->AHB2ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB1: SET_BIT(RCC->APB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB2: SET_BIT(RCC->APB2ENR,RCC_u8CopyPeripheral);break;
			default : Local_u8Error =NOK;

			
		}
			
	}
	else
	{
		
		Local_u8Error =NOK;
		
	}
		
		
	return Local_u8Error;
	
	
}

u8	RCC_voidPeripheralClockDisable(u8 RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral)
{
	u8 Local_u8Error=OK;
	if (RCC_u8CopyPeripheral<32)
	{
		switch(RCC_u8CopyBus)
		{
			case RCC_AHB1: CLEAR_BIT(RCC->AHB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_AHB2: CLEAR_BIT(RCC->AHB2ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB1: CLEAR_BIT(RCC->APB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB2: CLEAR_BIT(RCC->APB2ENR,RCC_u8CopyPeripheral);break;
			default : Local_u8Error =NOK;

			
		}
			
	}
	else
	{
		
		Local_u8Error =NOK;
		
	}
		
		
	return Local_u8Error;
	
	
}

