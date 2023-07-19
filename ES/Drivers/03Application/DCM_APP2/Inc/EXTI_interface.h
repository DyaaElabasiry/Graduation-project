/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     MCAL                     */
/*     Component: EXTI                     */
/*     Version:   2.00                     */
/******************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_RISING_EDGE=1,  //01
	EXTI_FALLING_EDGE,   //10
	EXTI_ON_CHANGE,      //11

}Trigger_Mode_t;

typedef enum
{
	EXTI_Line0,
	EXTI_Line1,
	EXTI_Line2,
	EXTI_Line3,
	EXTI_Line4,
	EXTI_Line5,
	EXTI_Line6,
	EXTI_Line7,
	EXTI_Line8,
	EXTI_Line9,
	EXTI_Line10,
	EXTI_Line11,
	EXTI_Line12,
	EXTI_Line13,
	EXTI_Line14,
	EXTI_Line15,

}EXTI_LINE_t;


typedef struct
{
	EXTI_LINE_t      EXTI_LINE_NUM;     /*(From 0 to 15)*/
    Trigger_Mode_t   EXTI_TRIG_MODE;    /*Rising
                                          Falling
                                          On change*/
}EXTI_LINEx;

/*
 Function Name:        EXTI_voidInit
 Function Arguments:   copy_EXTILine--> EXTI_LINEx*
 Function Return:      void
 Function Description: initialize of External interrupt
*/


void EXTI_voidInit(EXTI_LINEx* copy_EXTILine);

/*
 Function Name:        EXTI_voidTriggerSelection
 Function Arguments:   copy_EXTILine-->EXTI_LINEx*
 Function Return:      void
 Function Description: select trigger Mode for External interrupt 1.Falling
                                                                  2.Rising
																  3.On change
*/
void EXTI_voidTriggerSelection(EXTI_LINEx* copy_EXTILine);

/*
 Function Name:        EXTI_voidEnableEXTI
 Function Arguments:   copy_EXTILine-->EXTI_LINEx*
 Function Return:      void
 Function Description: enable External interrupt
*/
void EXTI_voidEnableEXTI(EXTI_LINEx* copy_EXTILine);

/*
 Function Name:        EXTI_voidDisableEXTI
 Function Arguments:   copy_EXTILine-->EXTI_LINEx*
 Function Return:      void
 Function Description: disable External interrupt
*/
void EXTI_voidDisableEXTI(EXTI_LINEx* copy_EXTILine);

/*
 Function Name:        EXTI_voidClearPendingFlag
 Function Arguments:   copy_EXTILine-->EXTI_LINEx*
 Function Return:      void
 Function Description: clear External interrupt pending flag
*/
void EXTI_voidClearPendingFlag(EXTI_LINEx* copy_EXTILine);

/*
 Function Name:        EXTI_voidSoftwareTrigger
 Function Arguments:   copy_EXTILine-->EXTI_LINEx*
 Function Return:      void
 Function Description: trigger software interrupt to set pending flag to 1
*/
void EXTI_voidSoftwareTrigger(EXTI_LINEx* copy_EXTILine);

/*
 Function Name:        EXTI_voidSetCallBack
 Function Arguments:   copy_EXTILine        -->EXTI_LINEx*
                       *Copy_pvCallBackFunc -->PTR to FUNC
 Function Return:      void
 Function Description: call interrupt function
*/
void EXTI_voidSetCallBack(EXTI_LINEx* copy_EXTILine,void (*Copy_pvCallBackFunc) (void));


#endif
