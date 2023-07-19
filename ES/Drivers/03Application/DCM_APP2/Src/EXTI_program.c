/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     MCAL                     */
/*     Component: EXTI                     */
/*     Version:   2.00                     */
/******************************************/


#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"


//ISR functions array prototype
static void (* EXTI_CallBack[16]) (void) = {NULL};

void EXTI_voidInit(EXTI_LINEx* copy_EXTILine)
{
	/*First: clear all Pending Flags*/
    EXTI->PR=Clear_Pending_Flags;

    /*disable Interrupt mask for selected Interrupt Line*/

    EXTI->IMR|=(1<<(copy_EXTILine->EXTI_LINE_NUM));

    /*Set Trigger Mode for selected Interrupt Line*/

    EXTI->RTSR|=((copy_EXTILine->EXTI_TRIG_MODE)<<(copy_EXTILine->EXTI_LINE_NUM));
    EXTI->FTSR|=(((copy_EXTILine->EXTI_TRIG_MODE)>>1)<<(copy_EXTILine->EXTI_LINE_NUM));

}


void EXTI_voidTriggerSelection(EXTI_LINEx* copy_EXTILine)
{
	switch(copy_EXTILine->EXTI_TRIG_MODE)
	{
	case EXTI_RISING_EDGE:  SET_BIT( EXTI->RTSR,copy_EXTILine->EXTI_LINE_NUM);

	case EXTI_FALLING_EDGE: SET_BIT( EXTI->FTSR,copy_EXTILine->EXTI_LINE_NUM);

	case EXTI_ON_CHANGE:    SET_BIT( EXTI->RTSR,copy_EXTILine->EXTI_LINE_NUM);
	                        SET_BIT( EXTI->FTSR,copy_EXTILine->EXTI_LINE_NUM);
	}
}

void EXTI_voidEnableEXTI(EXTI_LINEx* copy_EXTILine)
{
    EXTI->IMR|=(1<<(copy_EXTILine->EXTI_LINE_NUM));
}

void EXTI_voidDisableEXTI(EXTI_LINEx* copy_EXTILine)
{
	EXTI->IMR&=~(1<<(copy_EXTILine->EXTI_LINE_NUM));
}

void EXTI_voidClearPendingFlag(EXTI_LINEx* copy_EXTILine)
{
	EXTI->PR|=(1<<(copy_EXTILine->EXTI_LINE_NUM));
}

void EXTI_voidSoftwareTrigger(EXTI_LINEx* copy_EXTILine)
{
	EXTI->SWIER|=(1<<(copy_EXTILine->EXTI_LINE_NUM));
}

void EXTI_voidSetCallBack(EXTI_LINEx* copy_EXTILine,void (*Copy_pvCallBackFunc) (void))
{
	EXTI_CallBack[(copy_EXTILine->EXTI_LINE_NUM)] = Copy_pvCallBackFunc;
}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[EXTI_Line0]();
	/*	Clear pending Bit  */
	SET_BIT(EXTI->PR, EXTI_Line0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[EXTI_Line1]();
	/*	Clear pending Bit  */
	SET_BIT(EXTI->PR, EXTI_Line1);
}

void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[EXTI_Line2]();
	/*	Clear pending Bit  */
	SET_BIT(EXTI->PR, EXTI_Line2);
}

void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[EXTI_Line3]();
	/*	Clear pending Bit  */
	SET_BIT(EXTI->PR, EXTI_Line3);
}

void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[EXTI_Line4]();
	/*	Clear pending Bit  */
	SET_BIT(EXTI->PR, EXTI_Line4);
}

