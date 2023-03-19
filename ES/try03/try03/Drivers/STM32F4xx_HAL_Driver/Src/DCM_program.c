/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     HAL                      */
/*     Component: DCM                      */
/*     Version:   1.00                     */
/******************************************/


#include "STD_TYPES.h"
#include "Bit_Manipulation.h"

#include "DCM_private.h"
#include "DCM_config.h"
#include "DCM_interface.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "USART_interface.h"

u8 Global_u8MotorFeedback=0;
u8 Global_u8Counter=0;

void DCM_voidInit(DCM_t* DCM)
{

	/*set initial value to zero*/
	GPIO_SetPinValue(DCM->PORT,DCM->Direction_Pin,GPIO_PIN_LOW);
	GPIO_SetPinValue(DCM->PORT,DCM->PWM_Pin,GPIO_PIN_LOW);
	GPIO_SetPinValue(DCM->PORT,DCM->ENCA,GPIO_PIN_LOW);
	GPIO_SetPinValue(DCM->PORT,DCM->ENCB,GPIO_PIN_LOW);
}


//ENCA Pin Feedback
u8 DCM_u8DetectDirection_ENCA()
{
	// ISR happens at Rising edge on ENCA
	u8 ENCB_PIN_VALUE=0;

	GPIO_GetPinValue(GPIO_PORTA ,GPIO_PIN1, &ENCB_PIN_VALUE);

	if(ENCB_PIN_VALUE > 0)
	{
		Global_u8Counter++;  // CW rotations are increased by one
	}
	else
	{
		Global_u8Counter--;  // CCW rotations are increased by one"stepped back"
	}


	//USART_voidSendByte(USART_1,Global_u8Counter);
	return Global_u8Counter;
}


void DCM_voidENCAISR(void)
{

	Global_u8MotorFeedback = DCM_u8DetectDirection_ENCA();
}

//ENCA Pin Feedback
u8 DCM_u8DetectDirection_ENCB()
{
	// ISR happens at Rising edge on ENCB
	u8 ENCA_PIN_VALUE=0;

	GPIO_GetPinValue(GPIO_PORTA ,GPIO_PIN0, &ENCA_PIN_VALUE);

	if(ENCA_PIN_VALUE > 0)
	{
		Global_u8Counter--;  // CCW rotations are increased by one"stepped back"
	}
	else
	{
		Global_u8Counter++;  // CW rotations are increased by one
	}


	//USART_voidSendByte(USART_1,Global_u8Counter);
	return Global_u8Counter;
}

void DCM_voidENCBISR(void)
{

	Global_u8MotorFeedback = DCM_u8DetectDirection_ENCB();
}


void DCM_voidRotateCW(DCM_t* DCM)
{

	/*Direction is LOW so output A is high , output B is low*/
	GPIO_SetPinValue(DCM->PORT,DCM->Direction_Pin,GPIO_PIN_LOW);

}

void DCM_voidRotateCCW(DCM_t* DCM)
{

	/*Direction is HIGH so output A is low , output B is high*/
	GPIO_SetPinValue(DCM->PORT,DCM->Direction_Pin,GPIO_PIN_HIGH);

}


void DCM_voidSTOP(DCM_t* DCM)
{

	/*PWM is LOW*/
	GPIO_SetPinValue(DCM->PORT,DCM->PWM_Pin,GPIO_PIN_LOW);
}

