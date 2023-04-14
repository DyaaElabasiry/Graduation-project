/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     HAL                      */
/*     Component: ENCODER                  */
/*     Version:   2.00                     */
/******************************************/

#include "STD_TYPES.h"
#include "GPIO_interface.h"
//#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"

#include "ENCODER_interface.h"


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
	NVIC_voidEnableInterrupt(copy_Encoder->Encoder_A_IRQn);
	NVIC_voidEnableInterrupt(copy_Encoder->Encoder_B_IRQn);

	/*set call back functions*/
	EXTI_voidSetCallBack(&EXTI_L0,copy_Encoder->ptr_forward);
	EXTI_voidSetCallBack(&EXTI_L1,copy_Encoder->ptr_backward);

	EXTI_voidInit(&EXTI_L0);
	EXTI_voidInit(&EXTI_L1);
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

