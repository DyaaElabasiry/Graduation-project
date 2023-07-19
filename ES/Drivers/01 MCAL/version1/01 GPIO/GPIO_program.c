/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GPIO_interface.h"
#include "GPIO_register.h"
#include "GPIO_private.h"


u8  GPIO_SetPinValue( u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Value)
{	
	u8 Local_u8ErrorState=FALSE;
	if ((Copy_u8Pin < GPIO_NumOfPins)&&(Copy_u8Port < GPIO_NumOfPorts))
	{
	   ASSIGN_BIT(*GPIO_u8Arr_ODR[Copy_u8Port],Copy_u8Pin, Copy_u8Value);
	   Local_u8ErrorState=TRUE;
	   
	}
		
	return Local_u8ErrorState;
}

u8  GPIO_SetPortValue(u8 Copy_u8Port, u16 Copy_u8Value)
{
	u8 Local_u8ErrorState=FALSE;
	
  if (Copy_u8Port <GPIO_NumOfPorts)
  {
	  Assign_Reg(*GPIO_u8Arr_ODR[Copy_u8Port],Copy_u8Value);
	  Local_u8ErrorState=TRUE;
  } 
  			
	return Local_u8ErrorState;
}

u8  GPIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8PTRvalue)
{
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8PTRvalue!=NULL) && (Copy_u8Pin<GPIO_NumOfPins))
	{
		
		*Copy_u8PTRvalue =GET_BIT(*GPIO_u8Arr_IDR[Copy_u8Port], Copy_u8Pin);
		Local_u8ErrorState=TRUE;
		
	} 

	return Local_u8ErrorState;
}
u8  GPIO_GetPortValue(u8 Copy_u8Port, u16* Copy_u8PTRvalue)
{
	
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8PTRvalue!=NULL) && (Copy_u8Port< GPIO_NumOfPorts))
	{
		
		*Copy_u8PTRvalue =*GPIO_u8Arr_IDR[Copy_u8Port];
		Local_u8ErrorState=TRUE;
		
	}
	return Local_u8ErrorState;
	
}

void GPIO_SetGroupChannel(u8 Copy_u8Port,u8 Copy_u8StartPin,u8 Copy_u8ChannelWidth,u16 Copy_u8Value)
{
	*GPIO_u8Arr_ODR[Copy_u8Port]=BitManipulationSetBits(*GPIO_u8Arr_ODR[Copy_u8Port],Copy_u8StartPin,Copy_u8ChannelWidth,Copy_u8Value);

}

