#include "STD_Types.h"
#include "Software_Delay.h"


void _delay_ms(u32 Copy_u8Time)
{
	for(int i = 0; i < 1000 * Copy_u8Time; i++)
	{
		asm("NOP");
	}
}
