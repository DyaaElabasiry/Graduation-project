/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: LED           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

/**	1) Source Connection --> Connect the +ve of the led with the Microcontroller Pin and the -ve of the led to ground   **/
/**		to make the led on --> put 5 volt on Microcontroller Pin                                                        **/
/**		to make the led on --> put 0 volt on Microcontroller Pin                                                        **/
/**																														**/
/**	2) Sink Connection   --> Connect the -ve of the led with the Microcontroller Pin and the +ve of the led to 5 volt   **/
/**		to make the led on --> put 0 volt on Microcontroller Pin                                                        **/
/**		to make the led on --> put 5 volt on Microcontroller Pin                                                        **/


#define Source_Connection_type    0
#define Sink_Connection_type      1


#define LED_OFF                  0
#define LED_ON                   1

typedef struct _LED_ LED_Object;

struct _LED_
{
	u8 Connection_Type;
	u8 LED_Port;
	u8 LED_Pin;
};


void LED_Status(LED_Object Copy_LED, u8 Copy_u8LED_Status);

#endif
