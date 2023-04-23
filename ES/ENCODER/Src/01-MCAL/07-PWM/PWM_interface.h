/*********************************************************************************/
/* Author    : Habeba Hamada                                                       */
/* Version   : V1                                                               */
/* Date      : 18 Mar 2023                                                     */
/*********************************************************************************/

#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

typedef enum
{
	 TIM1,
	 TIM2,
	 TIM3,
	 TIM4,

}T_NUM;


typedef enum
{
	 CH1=1,
	 CH2,
	 CH3,
	 CH4,

}CH_NUM;

typedef enum
{
	active_high,
	active_low,

}POLARITY;


typedef enum
{
	PWM_MODE1=0b110,
	PWM_MODE2,

}mode_t;


typedef struct
{
	T_NUM     TIM_NUM;
	CH_NUM    TIM_CHANNEL_NUM;
	mode_t    PWM_MODE;
	POLARITY  PWM_POLARITY;
	u16       PWM_PERIOD;
	u8        TIM_PRESCALER;

}TIM_COMP;




/*
 Function Name:        PWM_voidInit
 Function Arguments:   Copy_TIM--> TIM_COMP*
 Function Return:      void
 Function Description: initialize the timer
*/
void  PWM_voidInit(TIM_COMP* Copy_TIM);

/*
 Function Name:        PWM_voidWrite
 Function Arguments:   Copy_TIM         --> TIM_COMP*
                       Copy_u16dutyCycle-->u16
 Function Return:      void
 Function Description: set duty cycle
*/
void  PWM_voidWrite(TIM_COMP* Copy_TIM,u16 Copy_u16dutyCycle);


#endif
