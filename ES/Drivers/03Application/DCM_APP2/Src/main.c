#include <stdint.h>


#include"STD_TYPES.h"
#include"BIT_Manipulation.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"PORT_interface.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"
#include"USART_interface.h"
#include"STK_interface.h"

#include"DCM_interface.h"

	/*DC Motor*/
	DCM_t DC_Motor={
			GPIO_PORTA,
			GPIO_PIN2,
			GPIO_PIN3,
			GPIO_PIN0, //EXTI Pin
			GPIO_PIN1, //EXTI Pin
	};

int main(void)
{
	RCC_voidSystemClockInit();
	RCC_voidPeripheralClockEnable(RCC_AHB1,GPIOA);
	RCC_voidPeripheralClockEnable(RCC_APB2,USART1);

	/*Selection line of MUX*/
	RCC_voidPeripheralClockEnable(RCC_APB2,SYSCFG);

	PORT_voidInit();
	STK_voidInit();

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
	u8 counter='0';
	u8 i=10;
	counter=counter+i;
	USART_voidSendByte(USART_1,counter);

	/*DCM_voidInit(&DC_Motor);

	DCM_voidRotateCW(&DC_Motor);*/

	//DCM_voidSTOP(&DC_Motor)


	while(1);
}

