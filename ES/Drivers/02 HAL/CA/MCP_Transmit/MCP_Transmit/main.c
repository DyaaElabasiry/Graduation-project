
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"
#include "USART_interface.h"

#include "MCP2515_Interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"

int  main(void)
{
	u8 read;
	DIO_VidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);    // to control which message to send
	
	MCP2515_VidInit();

	u8 msgData1[] = {'M', 'o', 'h', 'a', 'm', 'm', 'e', 'd'};
	u8 msgData2[] = {'H', 'a', 'b', 'e', 'b', '0', '0', '0'};
		

	while(1)
	{
		read = DIO_U8GetPinValue(DIO_PORTD, DIO_PIN2);
		
		if ( read == 0 )
		{
			MCP2515_VidSendCANmsg(0, 0x7E1, msgData1, 8);	
		}
		else
		{
			MCP2515_VidSendCANmsg(0, 0x7AA, msgData2, 8);
		}
	
		_delay_ms(1000);
	}
}
