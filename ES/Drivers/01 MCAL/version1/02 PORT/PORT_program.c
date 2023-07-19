/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: PORT           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include"STD_TYPES.h"
#include"BIT_Manipulation.h"
#include"PORT_register.h"
#include"PORT_private.h"
#include"PORT_config.h"
#include"PORT_interface.h"

void PORT_VoidInit(void)
{
	
	GPIOA_MODER = GPIOA_Mode;
	GPIOB_MODER = GPIOB_Mode;
	GPIOC_MODER = GPIOC_Mode;
	
	GPIOA_OTYPER = GPIOA_Output_Type ;
	GPIOB_OTYPER = GPIOB_Output_Type ;
	GPIOC_OTYPER = GPIOC_Output_Type ;
	
	GPIOA_OSPEEDR = GPIOA_Speed;
	GPIOB_OSPEEDR = GPIOB_Speed;
	GPIOC_OSPEEDR = GPIOC_Speed;
	
	GPIOA_PUPDR = GPIOA_PUPD;
	GPIOB_PUPDR = GPIOB_PUPD;
	GPIOC_PUPDR = GPIOC_PUPD;
	
#if Lock_key ==Not_Active_Lock	 //Problem
	SET_BIT(GPIOA_LCKR,GPIOx_LCKR_LCKK)  ;
	SET_BIT(GPIOB_LCKR,GPIOx_LCKR_LCKK)  ;
	SET_BIT(GPIOC_LCKR,GPIOx_LCKR_LCKK)  ;

    CLEAR_BIT(GPIOA_LCKR,GPIOx_LCKR_LCKK)  ;
	CLEAR_BIT(GPIOB_LCKR,GPIOx_LCKR_LCKK)  ;
	CLEAR_BIT(GPIOC_LCKR,GPIOx_LCKR_LCKK)  ;

	GPIOA_LCKR = GPIOA_Lock;
	GPIOB_LCKR = GPIOB_Lock;
	GPIOC_LCKR = GPIOC_Lock;
	
	SET_BIT(GPIOA_LCKR,GPIOx_LCKR_LCKK)  ;
	SET_BIT(GPIOB_LCKR,GPIOx_LCKR_LCKK)  ;
	SET_BIT(GPIOC_LCKR,GPIOx_LCKR_LCKK)  ;
	
#endif

  
    GPIOA_AFRL|=(GPIOA_AF<< GPIOx_AFRL0);
	GPIOB_AFRL|=(GPIOB_AF<< GPIOx_AFRL0);
	GPIOC_AFRL|=(GPIOC_AF<< GPIOx_AFRL0);
								
    GPIOA_AFRH|= (GPIOA_AF>> 32);
	GPIOB_AFRH|= (GPIOB_AF>> 32);
	GPIOC_AFRH|= (GPIOC_AF>> 32);
	
	
	
}


