/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: CLCD          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GPIO_interface.h"

#include "LED_interface.h"


void LED_Status(LED_Object Copy_LED,u8 Copy_u8LED_Status)
{
	GPIO_SetPinValue(Copy_LED.LED_Pin, Copy_LED.LED_Port,(Copy_u8LED_Status) ^ (Copy_LED.Connection_Type));
	
}
