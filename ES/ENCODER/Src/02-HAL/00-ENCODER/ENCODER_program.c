/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     HAL                      */
/*     Component: ENCODER                  */
/*     Version:   2.00                     */
/******************************************/


#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"

#include "../../01-MCAL/02-GPIO/GPIO_interface.h"
#include "../../01-MCAL/05-SYSTICK/STK_interface.h"
#include "../../01-MCAL/03-EXTI/EXTI_interface.h"
#include "../../01-MCAL/04-NVIC/NVIC_interface.h"
#include "../../01-MCAL/06-USART/USART_interface.h"

#include "ENCODER_interface.h"
#include "LED_interface.h"


	LED_Object LED1={
			Source_Connection_type,
			GPIO_PORTB,
			GPIO_PIN2
	};

	LED_Object LED2={
				Source_Connection_type,
				GPIO_PORTB,
				GPIO_PIN3
		};
void Encoder_init(Encoder_variables* copy_Encoder)
{

	copy_Encoder->CurrentTime = 0;
	copy_Encoder->LastTime = 0;
	copy_Encoder->delta_time  = 0;

	copy_Encoder->EncoderCounter = 0;
	copy_Encoder->LastEncoderCounter = 0;

	copy_Encoder->RPM = 0;

	EXTI_LINEx  EXTI_L0={copy_Encoder->Encoder_A_IRQn,
			EXTI_RISING_EDGE};
	EXTI_LINEx  EXTI_L1={copy_Encoder->Encoder_B_IRQn,
			EXTI_RISING_EDGE}; //ONCHANGE

	/* Enable Interrupt*/
	NVIC_voidEnableInterrupt(EXTI0);
	NVIC_voidEnableInterrupt(EXTI1);
	NVIC_voidEnableInterrupt(EXTI2);
	NVIC_voidEnableInterrupt(EXTI3);

	EXTI_voidInit(&EXTI_L0);
	EXTI_voidInit(&EXTI_L1);

	/*set call back functions*/
	EXTI_voidSetCallBack(&EXTI_L0,copy_Encoder->ptr_forward);
	EXTI_voidSetCallBack(&EXTI_L1,copy_Encoder->ptr_backward);
}

void Encoder_Forward(Encoder_variables *local_encoder)
{

	u8 a = 0, b = 0;
	GPIO_GetPinValue(local_encoder->Encoder_A_Port ,local_encoder->Encoder_A_Pin, &a);

	GPIO_GetPinValue(local_encoder->Encoder_B_Port ,local_encoder->Encoder_B_Pin, &b);
	if(a != b)
		local_encoder->EncoderCounter++;
	else
		local_encoder->EncoderCounter--;

	LED_Status(LED1,LED_ON);
	//USART_voidSendByte(USART_1,local_encoder->EncoderCounter);

}

void Encoder_Backward(Encoder_variables *local_encoder)
{

	u8 a = 0, b = 0;
	GPIO_GetPinValue(local_encoder->Encoder_A_Port ,local_encoder->Encoder_A_Pin, &a);

	GPIO_GetPinValue(local_encoder->Encoder_B_Port ,local_encoder->Encoder_B_Pin, &b);
	if(a == b)
		local_encoder->EncoderCounter++;
	else
		local_encoder->EncoderCounter--;

	LED_Status(LED2,LED_ON);
	//USART_voidSendByte(USART_1,local_encoder->EncoderCounter);
}

void RPM_Calculate(Encoder_variables *local_encoder)
{
	//local_encoder->CurrentTime = Millis();
	local_encoder->delta_time = ((local_encoder->CurrentTime - local_encoder->LastTime) * 1.0);  /* delta_time in  mSec*/

	local_encoder->RPM =( ( (local_encoder->EncoderCounter - local_encoder->LastEncoderCounter) * 1.0)
													/ (local_encoder->EncoderResolution * local_encoder->delta_time) ) * (1000*60); /* time in min */


	local_encoder->LastTime = local_encoder->CurrentTime;
	local_encoder->LastEncoderCounter = local_encoder->EncoderCounter ;

}

