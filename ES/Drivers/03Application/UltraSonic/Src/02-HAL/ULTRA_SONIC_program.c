/*********************************************************/
/* Author  :              H    H                         */
/* Date    :  18 February 2023                           */
/* Version : V1.0                                        */
/*********************************************************/

#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_Manipulation.h"

#include "../01-MCAL/02-GPIO/GPIO_interface.h"
#include "../01-MCAL/01-PORT/PORT_interface.h"
#include "../01-MCAL/00-RCC/RCC_interface.h"
#include "../01-MCAL/08-TIMER/TIMER_interface.h"
#include "ULTRA_SONIC_interface.h"
#include "kalman_filter.h"

volatile ULTRA_SONIC_variables* local_volatile_ultrasonic;

static void KalmanFilter_init(void);
volatile kalman_variables local_filter;

void Ultrasonic_voidInit(ULTRA_SONIC_variables* local_ultrasonic)
{
	/*Initialize Trigger Pin*/
	//GPIO_voidSetPinDirection(local_ultrasonic->copy_u8TriggerPort, local_ultrasonic->copy_u8TriggerPin, OUTPUT_SPEED_50MHZ_PP);

	/*Initialize Echo Pin*/
	//GPIO_voidSetPinDirection(local_ultrasonic->copy_u8EchoPort, local_ultrasonic->copy_u8EchoPin, INPUT_FLOATING);

	/* Initialize Timer */
	MTimer_voidInit(local_ultrasonic->copy_u8EchoTimerNum, UPCOUNTING_MODE, PRESCALAR,  OVERFLOW_VALUE);
	
	/* Initialize Input Capture */
	MTimer_EnableInputCapture(local_ultrasonic->copy_u8EchoTimerNum, local_ultrasonic->Copy_u8EchoChannelNum);
	
	/*Set CallBack Function*/
	MTimer_voidSetCallBack(local_ultrasonic->copy_u8EchoTimerNum,Ultrasonic_voidGetDistance_CallBack);

	/* reset all variables to equal zero */
	local_ultrasonic->RisingEdge_Captured = 0;
	local_ultrasonic->Rising_CaputredValue = 0;
	local_ultrasonic->Falling_CaputredValue = 0;
	local_ultrasonic->Difference = 0;
	local_ultrasonic->Distance = 0;
	
	KalmanFilter_init();
	
	local_volatile_ultrasonic = local_ultrasonic;
}

void Ultrasonic_voidTrigger()
{
	GPIO_SetPinValue(local_volatile_ultrasonic->copy_u8TriggerPort, local_volatile_ultrasonic->copy_u8TriggerPin, GPIO_PIN_HIGH);
	MTimer_Delay_us(10);
	GPIO_SetPinValue(local_volatile_ultrasonic->copy_u8TriggerPort, local_volatile_ultrasonic->copy_u8TriggerPin, GPIO_PIN_LOW);
}

void Ultrasonic_voidGetDistance_CallBack()
{
	if (local_volatile_ultrasonic->RisingEdge_Captured == 0) // If The Rising Is Not Captured Before
		{
			// Read The Time Of Rising Edge
			local_volatile_ultrasonic->Rising_CaputredValue = MTimer_GetCCRValue(local_volatile_ultrasonic->copy_u8EchoTimerNum,local_volatile_ultrasonic->Copy_u8EchoChannelNum);
			
			// Set The Rising Edge Flag (Rising Is Detected)		
			local_volatile_ultrasonic->RisingEdge_Captured = 1;  
			
			// Change The Polarity to Falling Edge
			MTimer_SetInputCapturePolarity(local_volatile_ultrasonic->copy_u8EchoTimerNum, FallingEdge, local_volatile_ultrasonic->Copy_u8EchoChannelNum);
		}
		else if (local_volatile_ultrasonic->RisingEdge_Captured == 1) //If The Rising Is Already Captured 
		{
			// Read The Time Of Falling Edge
			local_volatile_ultrasonic->Falling_CaputredValue = MTimer_GetCCRValue(local_volatile_ultrasonic->copy_u8EchoTimerNum,local_volatile_ultrasonic->Copy_u8EchoChannelNum);
			
			// Re-Initialize the counter 
			MTimer_ClearCounter(local_volatile_ultrasonic->copy_u8EchoTimerNum);

			if (local_volatile_ultrasonic->Falling_CaputredValue > local_volatile_ultrasonic->Rising_CaputredValue)
			{
				local_volatile_ultrasonic->Difference = local_volatile_ultrasonic->Falling_CaputredValue - local_volatile_ultrasonic->Rising_CaputredValue;
			}

			else if (local_volatile_ultrasonic->Rising_CaputredValue > local_volatile_ultrasonic->Falling_CaputredValue)
			{
				local_volatile_ultrasonic->Difference = (0xffff - local_volatile_ultrasonic->Rising_CaputredValue) + local_volatile_ultrasonic->Falling_CaputredValue;
			}
			local_volatile_ultrasonic->Distance = local_volatile_ultrasonic->Difference * .034/2;
			KalmanFilter_calculate(&local_filter,local_volatile_ultrasonic->Distance);
			local_volatile_ultrasonic->filter_Distance = local_filter.x;
			
			// Clear The Flag Again
			local_volatile_ultrasonic->RisingEdge_Captured = 0; 
			
			// Change The Polarity to Rising Edge// set polarity to rising edge
			MTimer_SetInputCapturePolarity(local_volatile_ultrasonic->copy_u8EchoTimerNum, RisingEdge,local_volatile_ultrasonic->Copy_u8EchoChannelNum);
		}
}

void KalmanFilter_init(void)
{
	local_filter.x  = 0; // initial_state;
	local_filter.p  = 1;//initial_variance;
	local_filter.ps = 0.5; //sensor_variance;
	local_filter.Q  = 0.009; //variance_over_time;
	local_filter.k  = 2;
}



