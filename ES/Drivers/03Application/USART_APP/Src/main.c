
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"STD_TYPES.h"
#include"BIT_Manipulation.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"

#include"PORT_interface.h"
#include"USART_interface.h"

#include"LED_interface.h"
#include"ESP8266_interface.h"

int main(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnablePeripheralClk(RCC_AHB1,GPIOA);
	RCC_voidEnablePeripheralClk(RCC_APB2,USART1);

	PORT_voidInit();


	USART_InitType UART_Config={.BaudRate=USART_115200_16MHZ,
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


	ESP_ESP8266_RetrunInit(&UART_Config,&UART_CLOCK,USART_1);

	ESP_ESP8266_RetrunConnectToWIFI(USART_1);

		while(1)
		{

		}
}
