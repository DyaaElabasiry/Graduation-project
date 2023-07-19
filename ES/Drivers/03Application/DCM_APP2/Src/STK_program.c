/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component:STK             ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"


static void (*STK_CallBack)(void);
static u8 STK_u8ModeOFInterval;

void STK_voidInit(void){

	/*Disable the Timer*/
	CLEAR_BIT(STK->CTRL,ENABLE);

	/*Disable the Timer Interrupt*/
	CLEAR_BIT(STK->CTRL,TICKINT);

	/*Choosing Systick Clock Source*/
	#if STK_CLK_SOURCE==STK_AHB_DIV_8
		CLEAR_BIT(STK->CTRL,CLKSOURCE);

	#elif STK_CLK_SOURCE==STK_AHB
	    SET_BIT(STK->CTRL,CLKSOURCE);
	
	#endif

}

void STK_voidStopTimer(void)
{
	/*Stop Timer Interrupt*/
	CLEAR_BIT(STK->CTRL,TICKINT);
	
	/*Stop Timer Enable*/
	CLEAR_BIT(STK->CTRL,ENABLE);
	
	/*Clear LOAD , VAL Registers to stop reload*/
	STK -> LOAD = 0;
	STK -> VAL = 0;
}

void STK_voidSetBusyWait(u32 Copy_u32TickCount){
	
	/*LOAD Ticks TO Load Register */
	STK->LOAD = (Copy_u32TickCount) & 0x00FFFFFF;

	/*Start The Timer*/
	SET_BIT(STK->CTRL, ENABLE);

	/*Wait till Flag is Raised*/
	while((GET_BIT(STK->CTRL, COUNTFLAG)==0));

	/*Disable Timer*/
	CLEAR_BIT(STK->CTRL, ENABLE);

	/*Clear LOAD , VAL Registers to stop reload*/
	STK->LOAD=0;
	STK->VAL=0;


}

void STK_voidSetSingleInterval(u32 Copy_u32TickCount, void (*CallBackFunction)(void))
{
	/*LOAD Ticks TO Load Register */
	STK->LOAD = (Copy_u32TickCount) & 0x00FFFFFF;

	/*Save Call back function*/
	STK_CallBack = CallBackFunction;

	/*Set Mode to Single Interval*/
	STK_u8ModeOFInterval = STK_SINGLE_INTERVAL;
	
	/*Enable Systick Interrupt*/
	SET_BIT(STK->CTRL, TICKINT);
	
	/*Start Timer*/
	SET_BIT(STK->CTRL, ENABLE);
}

void STK_voidSetPeriodicInterval(u32 Copy_u32TickCount, void (*CallBackFunction)(void))
{

	/*LOAD Ticks TO Load Register */
	STK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

	/*Save Call back function*/
	STK_CallBack = CallBackFunction;

	/*Set Mode to Periodic Interval*/
	STK_u8ModeOFInterval = STK_PERIODIC_INTERVAL;

	/*Enable Systick Interrupt*/
	SET_BIT(STK->CTRL, TICKINT);

	/*Start Timer*/
	SET_BIT(STK->CTRL, ENABLE);
}

u32 STK_u32GetElapsedTime(void)
{
	return STK->LOAD-STK->VAL;
}

u32 STK_u32GetRemainingTime(void)
{
	return STK->VAL;
}


void SysTick_Handler(void){

	u8 Local_u8Temporary;

	if(STK_u8ModeOFInterval == STK_SINGLE_INTERVAL)
	{
		/*Disable Systick Interrupt*/
		CLEAR_BIT(STK->CTRL, TICKINT);

		/*Stop Timer*/
		CLEAR_BIT(STK->CTRL, ENABLE);

		/*Clear LOAD , VAL Registers to stop reload*/
		STK->LOAD=0;
		STK->VAL=0;


	}

	/*Call Back Notification*/
	STK_CallBack();

	/*Clear Interrupt Flag by Reading it*/
	Local_u8Temporary=GET_BIT(STK->CTRL, COUNTFLAG);
}
