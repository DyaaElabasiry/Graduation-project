/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: Seven_Segmen  ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/



/*
--> interfacing stm32f401cc6  with 7 segment display

      --------------------------
     |             A            |
     |	        -------         |
0 <--|A	      ||	   ||       |
1 <--|B     F ||       || B     |
2 <--|C       ||   G   ||       |
3 <--|D		    -------         |
4 <--|E       ||       ||       |
5 <--|F	    E ||       || C     |
6 <--|G       ||       ||       |
7 <--|DP        -------	        | 
     |             D            |
      --------------------------
	   
--> Firstly for common anode : to turn a led on put '0' on the pin

                                           7 6 5 4 3 2 1 0
                                          DP G F E D C B A
for number 0 --> A, B, C, D, E, F      --> 1 1 0 0 0 0 0 0 --> 0xC0
for number 1 --> B, C                  --> 1 1 1 1 1 0 0 1 --> 0xF9
for number 2 --> A, B, D, E, G         --> 1 0 1 0 0 1 0 0 --> 0xA4
for number 3 --> A, B, C, D, G         --> 1 0 1 1 0 0 0 0 --> 0xB0
for number 4 --> B, C, F, G            --> 1 0 0 1 1 0 0 1 --> 0x99
for number 5 --> A, C, D, F, G         --> 1 0 0 1 0 0 1 0 --> 0x92
for number 6 --> A, C, D, E, F, G      --> 1 0 0 0 0 0 1 0 --> 0x82
for number 7 --> A, B, C               --> 1 1 1 1 1 0 0 0 --> 0xF8
for number 8 --> A, B, C, D, E, F, G   --> 1 0 0 0 0 0 0 0 --> 0x80
for number 9 --> A, B, C, D, F, G      --> 1 0 0 1 0 0 0 0 --> 0x90

----------------------------------------------------------------------

--> Secondly for common cathode : to turn a led on put '1' on the pin
                                  or you can easily change any '0' in 
								  common anode with '1'

                                           7 6 5 4 3 2 1 0
                                          DP G F E D C B A
for number 0 --> A, B, C, D, E, F      --> 0 0 1 1 1 1 1 1 --> 0x3F
for number 1 --> B, C                  --> 0 0 0 0 0 1 1 0 --> 0x06
for number 2 --> A, B, D, E, G         --> 0 1 0 1 1 0 1 1 --> 0x5B
for number 3 --> A, B, C, D, G         --> 0 1 0 0 1 1 1 1 --> 0x4F
for number 4 --> B, C, F, G            --> 0 1 1 0 0 1 1 0 --> 0x66
for number 5 --> A, C, D, F, G         --> 0 1 1 0 1 1 0 1 --> 0x6D
for number 6 --> A, C, D, E, F, G      --> 0 1 1 1 1 1 0 1 --> 0x7D
for number 7 --> A, B, C               --> 0 0 0 0 0 1 1 1 --> 0x07
for number 8 --> A, B, C, D, E, F, G   --> 0 1 1 1 1 1 1 1 --> 0x7F
for number 9 --> A, B, C, D, F, G      --> 0 1 1 0 1 1 1 1 --> 0x6F
*/


#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GPIO_interface.h"

#include "SevenSeg_Interface.h"
#include "SevenSeg_Private.h"
#include "SevenSeg_Config.h"


void SSD_Display_Number(Seven_Segment_Object Copy_Seven_Segment, u8 Copy_u8Number)
{
	/* 
		This Equation is used to limit the indices used to the array if the user entered a wrong index. 
		if the user entered a number between 0 - 10 the SSD will display the the corresponding value of this index.
		but if the user entered a number greater than the array size the index will be the index of Error.
	*/
	u8 SSD_NUMBER_INDEX = ((Copy_u8Number <= SSD_MAX_DISPLAY) * Copy_u8Number) + (SSD_ERROR_INDEX * (Copy_u8Number > SSD_MAX_DISPLAY));
	GPIO_u8WritePinValue(Copy_Seven_Segment.Enable_Pin, Copy_Seven_Segment.Enable_port,GET_BIT(Copy_Seven_Segment.Mode, 0));
	GPIO_u8SetGroupChannel(Copy_Seven_Segment.Port,Copy_Seven_Segment.Start_Pin,8,(Copy_Seven_Segment.Mode) ^ (SSD_NUMBER_ARRAY[SSD_NUMBER_INDEX]));
}


