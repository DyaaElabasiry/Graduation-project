/*********************************************************/
/* Author  :              H    H                         */
/* Date    :  18 February 2023                           */
/* Version : V1.0                                        */
/*********************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"


volatile TIMER_t* TIMERx;
static void(*Timer1_CallBack_PTR)(void);
static void(*Timer2_CallBack_PTR)(void);
static void(*Timer3_CallBack_PTR)(void);
static void(*Timer4_CallBack_PTR)(void);

void MTimer_voidInit(u8 Copy_u8TimerNum, u8 Copy_u8TimerMode, u16 Copy_u16TimerPreScaler, u16 Copy_u16TimerARRValue)
{
	/* Selecting Which Timer Will Operate*/
	if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMER1->CR1, 4);
			
			/* SET PRESCALER */
			TIMER1->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMER1->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMER1->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMER1->CR1, 4);
			
			/* SET PRESCALER */
			TIMER1->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMER1->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMER1->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer 2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMERx->CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3*/
		TIMERx = (volatile TIMER_t*)TIMER3_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMERx->CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4*/
		TIMERx = (volatile TIMER_t*)TIMER4_BASE_ADDRESS;
		
		/* Select Timer Mode */
		if(Copy_u8TimerMode == UPCOUNTING_MODE)
		{
			/* SET UPCOUNTING_MODE */
			CLEAR_BIT(TIMERx->CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  DOWNCOUNTING_MODE)
		{
			/* SET DOWNCOUNTING_MODE */
			SET_BIT(TIMERx->CR1, 4);
			
			/* SET PRESCALER */
			TIMERx->PSC = Copy_u16TimerPreScaler;
			
			/* SET ARR VALUE */
			TIMERx->ARR = Copy_u16TimerARRValue;
			
			/* ENABLE TIMER */
			SET_BIT(TIMERx->CR1, 0);
		}
		else if(Copy_u8TimerMode ==  CENTER_ALIGNED_MODE)
		{
			
		}
	}
	
}

void MTimer_voidSetCallBack(u8 Copy_u8TimerNum, void (*PTR2FUNC)(u8))
{
	if(Copy_u8TimerNum == TIM1)
	{
		Timer1_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		Timer2_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		Timer3_CallBack_PTR = PTR2FUNC;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		Timer4_CallBack_PTR = PTR2FUNC;
	}		
}


void MTimer_Delay_us(u16 Copy_Time_US)
{
	 /*Initialize Timer 4*/
	MTimer_voidInit(TIM4, UPCOUNTING_MODE, PRESCALAR, OVERFLOW_VALUE);

	/* Re-initialize the counter */
	SET_BIT(TIMER4->EGR, 0);

	while(TIMER4->CNT < Copy_Time_US)
	{
		/* Loop Until Reaching The Required Count(Time) */
	}
}

void MTimer_Delay_ms(u16 Copy_Time_MS)
{
	for(u16 Local_Iterator =0; Local_Iterator < Copy_Time_MS; Local_Iterator++)
	{
		/* Delay In Milliseconds*/
		MTimer_Delay_us(ONE_MILLISECOND);
	}
}

void MTimer_EnableInputCapture(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum)
{
	if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;
		if(Copy_u8ChannelNum == CHANNEL2)
		{
			/* Write CC2S Bites */
			SET_BIT(TIMER1->CCMR1, 8);
			CLEAR_BIT(TIMER1->CCMR1, 9);

			/*IC2F Bites*/
			SET_BIT(TIMER1->CCMR1, 12);
			SET_BIT(TIMER1->CCMR1, 13);
			CLEAR_BIT(TIMER1->CCMR1, 14);
			CLEAR_BIT(TIMER1->CCMR1, 15);

			/* Rising Edge*/
			CLEAR_BIT(TIMER1->CCER, 5);

			/* Enable Capture The Value From Counter */
			SET_BIT(TIMER1->CCER, 4);

			/* Enable Interrupt */
			SET_BIT(TIMER1->DIER, 2);
		}
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer  2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}
	
	if(Copy_u8ChannelNum == CHANNEL1)
	{
		/* Write CC1S Bites */
		SET_BIT(TIMERx->CCMR1, 0);
		CLEAR_BIT(TIMERx->CCMR1, 1);
		
		/*IC1F Bites*/
		SET_BIT(TIMERx->CCMR1, 4);
		SET_BIT(TIMERx->CCMR1, 5);
		CLEAR_BIT(TIMERx->CCMR1, 6);
		CLEAR_BIT(TIMERx->CCMR1, 7);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, 1);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, 0);
		
		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->DIER, 1);
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		/* Write CC2S Bites */
		SET_BIT(TIMERx->CCMR1, 8);
		CLEAR_BIT(TIMERx->CCMR1, 9);
		
		/*IC2F Bites*/
		SET_BIT(TIMERx->CCMR1, 12);
		SET_BIT(TIMERx->CCMR1, 13);
		CLEAR_BIT(TIMERx->CCMR1, 14);
		CLEAR_BIT(TIMERx->CCMR1, 15);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, 5);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, 4);
		
		/* Enable Interrupt */
		SET_BIT(TIMERx->DIER, 2);
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		/* Write CC3S Bites */
		SET_BIT(TIMERx->CCMR2, 0);
		CLEAR_BIT(TIMERx->CCMR2, 1);
		
		/*IC3F Bites*/
		SET_BIT(TIMERx->CCMR2, 4);
		SET_BIT(TIMERx->CCMR2, 5);
		CLEAR_BIT(TIMERx->CCMR2, 6);
		CLEAR_BIT(TIMERx->CCMR2, 7);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, 9);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, 8);
		
		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->DIER, 3);
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		/* Write CC4S Bites */
		SET_BIT(TIMERx->CCMR2, 8);
		CLEAR_BIT(TIMERx->CCMR2, 9);
		
		/*IC4F Bites*/
		SET_BIT(TIMERx->CCMR2, 12);
		SET_BIT(TIMERx->CCMR2, 13);
		CLEAR_BIT(TIMERx->CCMR2, 14);
		CLEAR_BIT(TIMERx->CCMR2, 15);
		
		/* Rising Edge*/
		CLEAR_BIT(TIMERx->CCER, 13);

		/* Enable Capture The Value From Counter */
		SET_BIT(TIMERx->CCER, 12);
		
		/* Enable Interrupt */
		SET_BIT(TIMERx->DIER, 4);
	}
}

u16 MTimer_GetCCRValue(u8 Copy_u8TimerNum, u8 Copy_u8ChannelNum)
{
	u16 Local_u16Counter_Value = 0;
		
  if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;

	  if(Copy_u8ChannelNum == CHANNEL1)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR1;
	  }
	  else if(Copy_u8ChannelNum == CHANNEL2)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR2;
	  }
	  else if(Copy_u8ChannelNum == CHANNEL3)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR3;
	  }
	  else if(Copy_u8ChannelNum == CHANNEL4)
	  {
		  Local_u16Counter_Value =	TIMER1->CCR4;
	  }

	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer  2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}
		
if(Copy_u8ChannelNum == CHANNEL1)
	{
			Local_u16Counter_Value =	TIMERx->CCR1;
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		Local_u16Counter_Value =	TIMERx->CCR2;
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		Local_u16Counter_Value =	TIMERx->CCR3;
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		Local_u16Counter_Value =	TIMERx->CCR4;
	}
		
		return Local_u16Counter_Value;
}

void MTimer_SetInputCapturePolarity(u8 Copy_u8TimerNum, u8 Copy_u8Plority, u8 Copy_u8ChannelNum)
{
		
	if(Copy_u8TimerNum == TIM1)
	{
		/* Select Timer 1 */
		//TIMERx = (volatile TIM1_t*) TIMER1_BASE_ADDRESS;
		if(Copy_u8ChannelNum == CHANNEL2)
		{
			if(Copy_u8Plority == RisingEdge)
			{
				CLEAR_BIT(TIMER1->CCER, 5);
			}
			else if(Copy_u8Plority == FallingEdge)
			{
				SET_BIT(TIMER1->CCER, 5);
			}
		}
	}
	else if(Copy_u8TimerNum == TIM2)
	{
		/* Select Timer  2*/
		TIMERx = (volatile TIMER_t*) TIMER2_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM3)
	{
		/* Select Timer 3 */
		TIMERx = (volatile TIMER_t*) TIMER3_BASE_ADDRESS;
	}
	else if(Copy_u8TimerNum == TIM4)
	{
		/* Select Timer 4 */
		TIMERx = (volatile TIMER_t*) TIMER4_BASE_ADDRESS;
	}	
		
	if(Copy_u8ChannelNum == CHANNEL1)
	{
		if(Copy_u8Plority == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, 1);
		}
		else if(Copy_u8Plority == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, 1);
		}
	}
	else if(Copy_u8ChannelNum == CHANNEL2)
	{
		if(Copy_u8Plority == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, 5);
		}
		else if(Copy_u8Plority == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, 5);
		}
	}
	else if(Copy_u8ChannelNum == CHANNEL3)
	{
		if(Copy_u8Plority == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, 9);
		}
		else if(Copy_u8Plority == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, 9);
		}
	}
	else if(Copy_u8ChannelNum == CHANNEL4)
	{
		if(Copy_u8Plority == RisingEdge)
		{
			CLEAR_BIT(TIMERx->CCER, 13);
		}
		else if(Copy_u8Plority == FallingEdge)
		{
			SET_BIT(TIMERx->CCER, 13);
		}
	}

		
}
void MTimer_ClearCounter(u8 Copy_u8TimerNum)
{
	if(Copy_u8TimerNum == TIM1)
		{
			/* Select Timer 1 */
			TIMER1->CNT=0;
		}
		else if(Copy_u8TimerNum == TIM2)
		{
			/* Select Timer 2 */
			TIMER2->CNT=0;
		}
		else if(Copy_u8TimerNum == TIM3)
		{
			/* Select Timer 3 */
			TIMER3->CNT=0;
		}
		else if(Copy_u8TimerNum == TIM4)
		{
			/* Select Timer 4 */
			TIMER4->CNT=0;
		}
}


void TIM1_CC_IRQHandler(void)
{
	Timer1_CallBack_PTR();
}

void TIM2_IRQHandler(void)
{
	Timer2_CallBack_PTR();
}
void TIM3_IRQHandler(void)
{
	Timer3_CallBack_PTR();
}
void TIM4_IRQHandler(void)
{
	Timer4_CallBack_PTR();
}	
