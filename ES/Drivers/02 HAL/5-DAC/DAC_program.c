/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: DAC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "DAC_Sound.h"

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"



/*
 * NAME:DAC_voidStartAudio
 * RETURN TYPE: void
 * ARGUMENTS: void
 * DESCRIPTION: Start DAC
 */
void DAC_voidStartAudio()
{
	STK_voidSetPeriodicInterval(TICK_TIME,DAC_voidSendAudio);
	
}



