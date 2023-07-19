
#include <stdint.h>

#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_Manipulation.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-GPIO/GPIO_interface.h"
#include"01-MCAL/03-EXTI/EXTI_interface.h"
#include"01-MCAL/04-NVIC/NVIC_interface.h"
#include"01-MCAL/06-USART/USART_interface.h"
#include"01-MCAL/07-PWM/PWM_interface.h"


#include"02-HAL/00-ENCODER/ENCODER_interface.h"




TIM_COMP Timer3CH1;
TIM_COMP Timer3CH2;

void SPEED_1_init(TIM_COMP* TIM);
void SPEED_2_init(TIM_COMP* TIM);


Encoder_variables Encoder_1;
Encoder_variables Encoder_2;

void Encoder_1_init(Encoder_variables* encoder);
void Encoder_2_init(Encoder_variables* encoder);


void forward_1()  				{ Encoder_Forward (&Encoder_1) ; }
void backward_1()   			{ Encoder_Backward(&Encoder_1); }

void forward_2()  				{ Encoder_Forward (&Encoder_2) ; }
void backward_2()   			{ Encoder_Backward(&Encoder_2); }

void RCC_Init(void);
void USART_Init(void);

int main(void)
{
	RCC_Init();

	PORT_voidInit();

	SPEED_1_init(&Timer3CH1);
	SPEED_2_init(&Timer3CH2);


	/* ENCODER 1 & 2 init */
	Encoder_1_init(&Encoder_1);
	Encoder_2_init(&Encoder_2);


	//USART_Init();


	/* motor A | B output pins */

	/*PWM_voidWrite(&Timer3CH1,50);
	GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_PIN_LOW);
    */

	/* motor C | D output pins */

	/*PWM_voidWrite(&Timer3CH2,170);
	GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_PIN_LOW);
    */
	/* Loop forever */
	for(;;)
	{


	}
}


void RCC_Init(void)
{
	/*configure System Clock*/
	RCC_voidSystemClockInit();

	/* Enable GPIOA clock */
	RCC_voidPeripheralClockEnable(RCC_AHB1,RCC_GPIOA);
	/* Enable GPIOB clock */
	RCC_voidPeripheralClockEnable(RCC_AHB1,RCC_GPIOB);

	/* Enable TIM2 clock */
	RCC_voidPeripheralClockEnable(RCC_APB1,RCC_TIM2);

	/* Enable TIM3 clock */
	RCC_voidPeripheralClockEnable(RCC_APB1,RCC_TIM3);
	/* Enable TIM4 clock */
	RCC_voidPeripheralClockEnable(RCC_APB1,RCC_TIM4);

	/* Enable Selection line of MUX*/
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_SYSCFG);

	/* Enable USART clock */
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_USART1);



}


void USART_Init(void)
{
	USART_InitType UART_Config={.BaudRate=USART_9600_16MHZ,
					.DataWidth=USART_8_Data_Bits,
					.StopBits=USART_1_Stop_Bit,
					.Parity_Enable=USART_Parity_DISABLE,
					.Parity_Selection=USART_Odd_Parity,
					.TransferDirection=USART_TX_RX,
					.Oversampling=OVER_SAMPLING_16,
			};

			USART_ClockInitTypeDef UART_CLOCK={
					.ClockOutput=0,
					.ClockPhase=0,
					.ClockPolarity=0,
			};

		USART_voidInit(&UART_Config,&UART_CLOCK,USART_1);

}

/*
 * speed 1 Init
 * Timer3 CH1   PA6
 */
void SPEED_1_init(TIM_COMP* TIM)
{
	TIM->TIM_NUM = TIM3;
	TIM->TIM_CHANNEL_NUM=CH1;
	TIM->PWM_MODE=PWM_MODE1;
	TIM->PWM_PERIOD=200;   //APB1 timer clock = 1 MHZ
	TIM->PWM_POLARITY=active_high;
	TIM->TIM_PRESCALER=1;

	PWM_voidInit(TIM);
}

/*
 * speed 2 Init
 * Timer3 CH2   PA7
 */
void SPEED_2_init(TIM_COMP* TIM)
{
	TIM->TIM_NUM = TIM3;
	TIM->TIM_CHANNEL_NUM=CH2;
	TIM->PWM_MODE=PWM_MODE1;
	TIM->PWM_PERIOD=200;   //APB1 timer clock = 1 MHZ
	TIM->PWM_POLARITY=active_high;
	TIM->TIM_PRESCALER=1;

	PWM_voidInit(TIM);
}

/*
 * ENCODER 1 Init
 */
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

