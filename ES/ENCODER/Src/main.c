
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include"STD_TYPES.h"
#include"BIT_Manipulation.h"


#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"PORT_interface.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"
#include"PWM_interface.h"
//#include"USART_interface.h"

#include"ENCODER_interface.h"

//#include"LCD_interface.h"

Encoder_variables Encoder_1;
Encoder_variables Encoder_2;

void Encoder_1_init(Encoder_variables* encoder);
void Encoder_2_init(Encoder_variables* encoder);


void forward_1()  				{ Encoder_Forward (&Encoder_1) ; }
void backward_1()   			{ Encoder_Backward(&Encoder_1); }

void forward_2()  				{ Encoder_Forward (&Encoder_2) ; }
void backward_2()   			{ Encoder_Backward(&Encoder_2); }

void RCC_Init(void);

int main(void)
{
	RCC_Init();

	PORT_voidInit();

	/* ENCODER 1 & 2 init */
	Encoder_1_init(&Encoder_1);
	Encoder_2_init(&Encoder_2);

	/* motor A | B output pins */
	PWM_voidSetPinDirection(TIM1,CH1); /* PA8 PWM */ /* PB0 Direction */

	PWM_voidWrite(TIM1,CH1,0);
	GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_LOW);

	/* motor C | D output pins */
	PWM_voidSetPinDirection(TIM1,CH2); /* PA9 PWM */ /* PB1 Direction */

	PWM_voidWrite(TIM1,CH2,0);
	GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_LOW);
	/* Loop forever */
	for(;;);
}


void RCC_Init(void)
{
	/*configure System Clock*/
	RCC_voidSystemClockInit();

	/* Enable GPIOA clock */
	RCC_voidPeripheralClockEnable(RCC_AHB1,RCC_GPIOA);
	/* Enable GPIOB clock */
	RCC_voidPeripheralClockEnable(RCC_AHB1,RCC_GPIOB);

	/* Enable TIM1 clock */
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_TIM1);

	/* Enable TIM2 clock */
	RCC_voidPeripheralClockEnable(RCC_APB1,RCC_TIM2);

	/* Enable Selection line of MUX*/
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_SYSCFG);



}

void Encoder_1_init(Encoder_variables* encoder)
{

	/* Set Pins and Variables */
	encoder->EncoderResolution = 2050;

	encoder->Encoder_A_Pin = GPIO_PIN0;
	encoder->Encoder_A_Port = GPIO_PORTA;
	encoder->Encoder_A_IRQn = EXTI_Line0;

	encoder->Encoder_B_Pin = GPIO_PIN1;
	encoder->Encoder_B_Port = GPIO_PORTA;
	encoder->Encoder_B_IRQn = EXTI_Line1;

	encoder->ptr_forward = forward_1;
	encoder->ptr_backward = backward_1;

	Encoder_init(encoder);

}
/*
 * ENCODER 2 Init
 */
void Encoder_2_init(Encoder_variables* encoder)
{
	/* Set Pins and Variables */
	encoder->EncoderResolution = 2050;

	encoder->Encoder_A_Pin = GPIO_PIN2;
	encoder->Encoder_A_Port = GPIO_PORTA;
	encoder->Encoder_A_IRQn = EXTI_Line2;

	encoder->Encoder_B_Pin = GPIO_PIN3;
	encoder->Encoder_B_Port = GPIO_PORTA;
	encoder->Encoder_B_IRQn = EXTI_Line3;

	encoder->ptr_forward = forward_2;
	encoder->ptr_backward = backward_2;

	Encoder_init(encoder);

}
