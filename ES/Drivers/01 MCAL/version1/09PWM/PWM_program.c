/*********************************************************************************/
/* Author    : Habeba Hamada                                                       */
/* Version   : V1                                                                  */
/* Date      : 18 Mar 2023                                                         */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

// PWM signal is at edge aligned mode

void  PWM_voidInit(TIM_COMP* Copy_TIM){


	switch (Copy_TIM->TIM_NUM)
	{
	case TIM2:
		if (Copy_TIM->TIM_CHANNEL_NUM == 1)

		{
			/*PWM Mode is configured */
			TIMER2->CCMR1|=(Copy_TIM->PWM_MODE)<<OC1M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER2->CCMR1,CC1S0);
			CLEAR_BIT(TIMER2->CCMR1,CC1S1);
		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 2)
		{
			/*PWM Mode is configured */
			TIMER2->CCMR1|=(Copy_TIM->PWM_MODE)<<OC2M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER2->CCMR1,CC2S0);
			CLEAR_BIT(TIMER2->CCMR1,CC2S1);
		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 3)
		{
			/*PWM Mode is configured */
			TIMER2->CCMR2|=(Copy_TIM->PWM_MODE)<<OC3M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER2->CCMR2,CC3S0);
			CLEAR_BIT(TIMER2->CCMR2,CC3S1);

		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 4)
		{
			/*PWM Mode is configured */
			TIMER2->CCMR2|=(Copy_TIM->PWM_MODE)<<OC4M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER2->CCMR2,CC4S0);
			CLEAR_BIT(TIMER2->CCMR2,CC4S1);

		}

		TIMER2->CCER=(Copy_TIM->PWM_POLARITY)<<CC1P;
		break;

		/*** TIM3 ***/

	case TIM3:
		if (Copy_TIM->TIM_CHANNEL_NUM == 1)

		{/*PWM Mode is configured */
			TIMER3->CCMR1|=(Copy_TIM->PWM_MODE)<<OC1M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER3->CCMR1,CC1S0);
			CLEAR_BIT(TIMER3->CCMR1,CC1S1);
		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 2)
		{
			/*PWM Mode is configured */
			TIMER3->CCMR1|=(Copy_TIM->PWM_MODE)<<OC2M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER3->CCMR1,CC2S0);
			CLEAR_BIT(TIMER3->CCMR1,CC2S1);
		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 3)
		{
			/*PWM Mode is configured */
			TIMER3->CCMR2|=(Copy_TIM->PWM_MODE)<<OC3M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER3->CCMR2,CC3S0);
			CLEAR_BIT(TIMER3->CCMR2,CC3S1);

		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 4)
		{
			/*PWM Mode is configured */
			TIMER3->CCMR2|=(Copy_TIM->PWM_MODE)<<OC4M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER3->CCMR2,CC4S0);
			CLEAR_BIT(TIMER3->CCMR2,CC4S1);

		}

		TIMER2->CCER=(Copy_TIM->PWM_POLARITY)<<CC1P;
		break;

		/*** TIM4 ***/

	case TIM4:
		if (Copy_TIM->TIM_CHANNEL_NUM == 1)

		{/*PWM Mode is configured */
			TIMER4->CCMR1|=(Copy_TIM->PWM_MODE)<<OC1M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER4->CCMR1,CC1S0);
			CLEAR_BIT(TIMER4->CCMR1,CC1S1);
		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 2)
		{
			/*PWM Mode is configured */
			TIMER4->CCMR1|=(Copy_TIM->PWM_MODE)<<OC2M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER4->CCMR1,CC2S0);
			CLEAR_BIT(TIMER4->CCMR1,CC2S1);
		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 3)
		{
			/*PWM Mode is configured */
			TIMER4->CCMR2|=(Copy_TIM->PWM_MODE)<<OC3M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER4->CCMR2,CC3S0);
			CLEAR_BIT(TIMER4->CCMR2,CC3S1);

		}

		else if (Copy_TIM->TIM_CHANNEL_NUM == 4)
		{
			/*PWM Mode is configured */
			TIMER4->CCMR2|=(Copy_TIM->PWM_MODE)<<OC4M0;

			/*the CC1 channel is configured as output.*/
			CLEAR_BIT(TIMER4->CCMR2,CC4S0);
			CLEAR_BIT(TIMER4->CCMR2,CC4S1);

		}

		TIMER4->CCER=(Copy_TIM->PWM_POLARITY)<<CC1P;
		break;


	default:       break;
	}



}

void  PWM_voidWrite(TIM_COMP* Copy_TIM,u16 Copy_u16dutyCycle){

	switch (Copy_TIM->TIM_NUM)
	{

	case TIM2:
		if (Copy_TIM->TIM_CHANNEL_NUM == 1)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER2->CCMR1,OC1PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER2->CCER,CC1E);
			TIMER2->CCR1 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM == 2)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER2->CCMR1,OC2PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER2->CCER,CC2E);
			TIMER2->CCR2 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM == CH3)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER2->CCMR2,OC3PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER2->CCER,CC3E);
			TIMER2->CCR3 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM== CH4)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER2->CCMR2,OC4PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER2->CCER,CC4E);
			TIMER2->CCR4 = Copy_u16dutyCycle;
		}

		/*Reload the Period time in the ARR*/
		TIMER2->ARR=Copy_TIM->PWM_PERIOD;
		/*initialize all the registers by setting the UG bit*/
		SET_BIT(TIMER2->EGR,UG);
		/*Counter enable*/
		SET_BIT(TIMER2->CR1,CEN);

		break;




	case TIM3:
		if (Copy_TIM->TIM_CHANNEL_NUM == 1)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER3->CCMR1,OC1PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER3->CCER,CC1E);
			TIMER3->CCR1 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM == 2)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER3->CCMR1,OC2PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER3->CCER,CC2E);
			TIMER3->CCR2 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM == CH3)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER3->CCMR2,OC3PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER3->CCER,CC3E);
			TIMER3->CCR3 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM== CH4)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER3->CCMR2,OC4PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER3->CCER,CC4E);
			TIMER3->CCR4 = Copy_u16dutyCycle;
		}

		/*Reload the Period time in the ARR*/
		TIMER3->ARR=Copy_TIM->PWM_PERIOD;
		/*initialize all the registers by setting the UG bit*/
		SET_BIT(TIMER3->EGR,UG);
		/*Counter enable*/
		SET_BIT(TIMER3->CR1,CEN);

		break;



	case TIM4:
		if (Copy_TIM->TIM_CHANNEL_NUM == 1)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER4->CCMR1,OC1PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER4->CCER,CC1E);
			TIMER4->CCR1 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM == 2)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER4->CCMR1,OC2PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER4->CCER,CC2E);
			TIMER4->CCR2 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM == CH3)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER4->CCMR2,OC3PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER4->CCER,CC3E);
			TIMER4->CCR3 = Copy_u16dutyCycle;
		}
		else if (Copy_TIM->TIM_CHANNEL_NUM== CH4)
		{
			/*Output compare preload enable*/
			SET_BIT(TIMER4->CCMR2,OC4PE);
			/*Output compare channel 1 enable */
			SET_BIT(TIMER4->CCER,CC4E);
			TIMER4->CCR4 = Copy_u16dutyCycle;
		}

		/*Reload the Period time in the ARR*/
		TIMER4->ARR=Copy_TIM->PWM_PERIOD;
		/*initialize all the registers by setting the UG bit*/
		SET_BIT(TIMER4->EGR,UG);
		/*Counter enable*/
		SET_BIT(TIMER4->CR1,CEN);

		break;

	default: break;
	}
}
