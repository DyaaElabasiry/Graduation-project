#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#include "MCP2515_Interface.h"
#include "USART_interface.h"
#include "GIE_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"



extern u8 readBuffer[];
u8 dataR =0;

int main(void)
{
	PORT_voidInit();
	USART_voidInit();

	GIE_voidEnable();
	
	MCP2515_VidReceiveInit();
	
	DIO_VidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);  //InT pin
	
	while(1)
	{
		if(DIO_U8GetPinValue(DIO_PORTD, DIO_PIN2) == 0)      //InT0 pin (set LOW when receiving message)
		{
			MCP2515_VidReceiveCANmsg();

			for(u8 i=0; i<8; i++)
			{
				dataR = readBuffer[6+i];   //start of data Bytes
				USART_u8SendCharSynch(dataR);
			}
			USART_u8SendCharSynch('\r');
			USART_u8SendCharSynch('\n');
		}
		
		/*USART_u8SendCharSynch('m');
		USART_u8SendCharSynch('\r');
		USART_u8SendCharSynch('\n');

		_delay_ms(1000);*/
	}
  

}
