#include <stdint.h>


#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_Manipulation.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-GPIO/GPIO_interface.h"
#include "01-MCAL/03-EXTI/EXTI_interface.h"
#include "01-MCAL/04-NVIC/NVIC_interface.h"
#include "01-MCAL/05-SYSTICK/STK_interface.h"
#include "01-MCAL/06-USART/USART_interface.h"
#include "01-MCAL/08-TIMER/TIMER_interface.h"


#include "02-HAL/ULTRA_SONIC_interface.h"

ULTRA_SONIC_variables ultrasonic;

void RCC_Init (void);
void USART_Init(void);
void ultra_init(ULTRA_SONIC_variables* local_ultrasonic);

//extern u16 Distance;
int main(void)
{
	/*u8 flag = 0;
u16 before =0;
u16 after = 0;
u16	Difference =0;
u8 release = 1;*/
	/* RCC init */
	RCC_Init();
	/* UART init */
	USART_Init();
	u8 str[] ="here";
	USART_voidSendString(USART_1,str);
	NVIC_voidEnableInterrupt(TIM1_CC);
	NVIC_voidEnableInterrupt(NVIC_TIM2);
	NVIC_voidEnableInterrupt(NVIC_TIM3);
	NVIC_voidEnableInterrupt(NVIC_TIM4);

	ultra_init(&ultrasonic);

	//u16 dist=0;
	while(1)
	{
		/*GPIO_voidSetPinValue(GPIOA, PIN1, HIGH);
		GPIO_voidSetPinValue(GPIOA, PIN1, LOW);*/
	   Ultrasonic_voidTrigger();
		//dist = HUltrasonic_u16GetDistance(TIMER2);
	   USART_voidSendString(USART_1,&(ultrasonic.Distance));
	   USART_voidSendByte( USART_1 , '\r'  );
	   USART_voidSendByte( USART_1 , '\n' );
		MTimer_Delay_ms(30);


	/*if(GPIO_u8GetPinValue(GPIOA,PIN0) == HIGH)
		{
		  if(flag == 0)
			{
				before = MTimer_GetCounteValue(TIMER2);
				flag =1;
				release =0;
			}
		}
		if (GPIO_u8GetPinValue(GPIOA,PIN0) == LOW)
		{
			if(release == 0)
			{
				release =1;
				flag =0;
				after = MTimer_GetCounteValue(TIMER2);
				Difference = (after - before);
				Difference = Difference * (.034/2);
				USART_voidTransmit(UART1,&Difference,INT);
				USART_voidTransmit(UART1,"\n",STRING);
				MTimer_Delay_ms(25);
			}
		}	*/
	}
}
/****************************************************/
/*
 * RCC init
 */

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

	/* Enable TIM3 clock */
	RCC_voidPeripheralClockEnable(RCC_APB1,RCC_TIM3);
	/* Enable TIM4 clock */
	RCC_voidPeripheralClockEnable(RCC_APB1,RCC_TIM4);

	/* Enable Selection line of MUX*/
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_SYSCFG);

	/* Enable USART clock */
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_USART1);

	/* Enable SPI clock */
	RCC_voidPeripheralClockEnable(RCC_APB2,RCC_SPI1);



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


void ultra_init(ULTRA_SONIC_variables* local_ultrasonic)
{
	local_ultrasonic->copy_u8EchoPort = GPIO_PORTA;
	local_ultrasonic->copy_u8EchoPin = GPIO_PIN9;

	local_ultrasonic->copy_u8TriggerPort = GPIO_PORTA;
	local_ultrasonic->copy_u8TriggerPin = GPIO_PIN10;

	local_ultrasonic->copy_u8EchoTimerNum = TIM1;
	local_ultrasonic->Copy_u8EchoChannelNum = CHANNEL2;

	Ultrasonic_voidInit(local_ultrasonic );
}

/*void TIM1_CC_IRQHandler(void)
{
	Ultrasonic_voidGetDistance_CallBack();
}*/
