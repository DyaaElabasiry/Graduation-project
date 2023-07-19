/*********************************************************/
/* Author  : H  H                                        */
/* Date    : 18 February 2023                            */
/* Version : V1.0                                        */
/*********************************************************/
#ifndef ULTRA_SONIC_INTERFACE_H
#define ULTRA_SONIC_INTERFACE_H

#define OVERFLOW_VALUE (0xFFFF)
#define PRESCALAR (72-1) // Tick Time is 1 Micro Second

/***
typedef struct for all varibiles
you need to init this variables
*/
typedef struct
{	
	u8 copy_u8TriggerPort , copy_u8TriggerPin;
	u8 copy_u8EchoPort	  , copy_u8EchoPin;
	u8 copy_u8EchoTimerNum, Copy_u8EchoChannelNum;
	
	u8  RisingEdge_Captured;
	u16 Rising_CaputredValue;
	u16 Falling_CaputredValue;
	
	u16 Difference;
	u16 Distance;
	u16 filter_Distance;

}ULTRA_SONIC_variables;

/*******
	Function Description              : This Function Initialize UltraSonic Pins and Timer 
	parameter:  local_ultrasonic		: all varibles needed and help to calculate distance
				copy_u8TimerNum        : Selects Which Timer to Be Used
							copy_u8PortName       : Selects Which Port to Be Used
							copy_u8TriggerPin     : Selects Trigger Pin
							copy_u8EchoPin        :  Selects Echo Pin
	return:    none
*/
void Ultrasonic_voidInit(ULTRA_SONIC_variables* local_ultrasonic);

/*******
	Function Description              : This Function Sets The Trigger High For 10 Micro Seconds 
	parameter:  copy_u8PortName       : Selects Which Port to Be Used
							copy_u8TriggerPin     : Selects Trigger Pin
	return:    none
*/
void Ultrasonic_voidTrigger();

/*******
	Function Description              : This Function Calculate The Distance in CallBack
	parameter:  local_ultrasonic	  : all varibles needed and help to calculate distance
				copy_u8TimerNum       : Selects Which Timer to Be Used
	return:    none
*/
void Ultrasonic_voidGetDistance_CallBack();

#endif
  
