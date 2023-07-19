/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: Seven_Segment ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/



#ifndef _SEVENSEG_INTERFACE_H_
#define _SEVENSEG_INTERFACE_H_


#define Common_Cathode_Mode    0x00
#define Common_Anode_Mode      0xFF


typedef struct _SSD_ Seven_Segment_Object;

struct _SSD_
{
	u8 Mode;
	u8 Port;
	u8 Start_Pin;
	u8 Enable_port;
	u8 Enable_Pin;
};

void SSD_Display_Number(Seven_Segment_Object Seven_Segment, u8 Copy_u8Number);



#endif
