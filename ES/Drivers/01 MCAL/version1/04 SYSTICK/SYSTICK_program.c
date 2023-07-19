/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: SYSTICK        ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"
#include "SYSTICK_register.h"


#include "GPIO_interface.h"

void (*CallBack)(void) = (void *) 0;
u8  IntervalState;

void STK_voidInit(void){

	#if Copy_u8ClkSRC==SYSTICK_AHB_8
		CLEAR_BIT(SYSTICK->CTRL,STK_CTRL_CLKSOURCE);

	#elif Copy_u8ClkSRC==SYSTICK_AHB_8
	    SET_BIT(SYSTICK->CTRL,STK_CTRL_CLKSOURCE);
	
	#endif

}

void STK_voidStopTimer(void)
{
	CLEAR_BIT(SYSTICK->CTRL,STK_CTRL_TICKINT);
	CLEAR_BIT(SYSTICK->CTRL,STK_CTRL_ENABLE);
	
	
	SYSTICK -> LOAD = 0;
	SYSTICK -> VAL = 0;	
}

void STK_voidSetBusyWait(u32 Copy_u32TickCount){
	
    CLEAR_BIT(SYSTICK->CTRL, STK_CTRL_TICKINT);
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;
	SYSTICK->VAL = 0;   //why
	SET_BIT(SYSTICK->CTRL, STK_CTRL_ENABLE);
	while(!(GET_BIT(SYSTICK->CTRL, STK_CTRL_COUNTFLAG))){
		__asm("NOP");
	}
	CLEAR_BIT(SYSTICK->CTRL, STK_CTRL_ENABLE);
	SYSTICK->VAL = 0; //why


}


void STK_voidSetPeriodicInterval(u32 Copy_u32TickCount, void (*ptr)(void))
{
	
	IntervalState = SYSTICK_PERIODIC_INTERVAL;
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;
	CallBack = ptr;
	SET_BIT(SYSTICK->CTRL, STK_CTRL_TICKINT);
	SET_BIT(SYSTICK->CTRL, STK_CTRL_ENABLE);
	
}

void STK_voidSetSingleInterval(u32 Copy_u32TickCount, void (*ptr)(void))
{

	IntervalState = SYSTICK_SINGLE_INTERVAL;
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;
	CallBack = ptr;
	SET_BIT(SYSTICK->CTRL, STK_CTRL_TICKINT);
	SET_BIT(SYSTICK->CTRL, STK_CTRL_ENABLE);
}

void SysTick_Handler(void){
	CallBack();
	if(IntervalState == SYSTICK_PERIODIC_INTERVAL){

	}else{
		CLEAR_BIT(SYSTICK->CTRL, 0);
	}
	SYSTICK->VAL = 0;
}
