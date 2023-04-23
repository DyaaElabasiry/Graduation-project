/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/


#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"


u8  GPIO_SetPinValue(u8 Copy_u8Port,Pins_t Copy_u8Pin, u8 Copy_u8Value)
{	
	u8 Local_u8ErrorState=FALSE;
	if ((Copy_u8Pin < GPIO_u8NumOfPins)&&(Copy_u8Port < GPIO_u8NumOfPorts))
	{
		switch(Copy_u8Port)
		{ case GPIO_PORTA: ASSIGN_BIT(REG_GPIO_PORTA->ODR,Copy_u8Pin, Copy_u8Value);break;
		  case GPIO_PORTB: ASSIGN_BIT(REG_GPIO_PORTB->ODR,Copy_u8Pin, Copy_u8Value);break;
		  case GPIO_PORTC: ASSIGN_BIT(REG_GPIO_PORTC->ODR,Copy_u8Pin, Copy_u8Value);break;
		}
	   Local_u8ErrorState=TRUE;
	   
	}
		
	return Local_u8ErrorState;
}

u8  GPIO_SetPortValue(u8 Copy_u8Port, u16 Copy_u8Value)
{
	u8 Local_u8ErrorState=FALSE;
	
  if (Copy_u8Port <GPIO_u8NumOfPorts)
  {
	 switch(Copy_u8Port)
		{ case GPIO_PORTA: Assign_Reg(REG_GPIO_PORTA->ODR,Copy_u8Value);break;
		  case GPIO_PORTB: Assign_Reg(REG_GPIO_PORTB->ODR,Copy_u8Value);break;
		  case GPIO_PORTC: Assign_Reg(REG_GPIO_PORTC->ODR,Copy_u8Value);break;
		} 
	  Local_u8ErrorState=TRUE;
  } 
  			
	return Local_u8ErrorState;
}

u8  GPIO_GetPinValue(u8 Copy_u8Port, Pins_t Copy_u8Pin, u8* Copy_u8PTRvalue)
{
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8PTRvalue!=NULL) && (Copy_u8Pin<GPIO_u8NumOfPins))
	{
		switch(Copy_u8Port)
		{ case GPIO_PORTA:*Copy_u8PTRvalue =GET_BIT(REG_GPIO_PORTA->IDR, Copy_u8Pin);break;
		  case GPIO_PORTB:*Copy_u8PTRvalue =GET_BIT(REG_GPIO_PORTB->IDR, Copy_u8Pin);break;
		  case GPIO_PORTC:*Copy_u8PTRvalue =GET_BIT(REG_GPIO_PORTC->IDR, Copy_u8Pin);break;
		}
		
		Local_u8ErrorState=TRUE;
		
	} 

	return Local_u8ErrorState;
}
u8  GPIO_GetPortValue(u8 Copy_u8Port, u16* Copy_u8PTRvalue)
{
	
	u8 Local_u8ErrorState=FALSE;
	
	if ((Copy_u8PTRvalue!=NULL) && (Copy_u8Port< GPIO_u8NumOfPorts))
	{
		switch(Copy_u8Port)
		{ case GPIO_PORTA:*Copy_u8PTRvalue =REG_GPIO_PORTA->IDR;break;
		  case GPIO_PORTB:*Copy_u8PTRvalue =REG_GPIO_PORTB->IDR;break;
		  case GPIO_PORTC:*Copy_u8PTRvalue =REG_GPIO_PORTC->IDR;break;
		}
		Local_u8ErrorState=TRUE;
		
	}
	return Local_u8ErrorState;
	
}

void GPIO_voidSetGroupChannel(u8 Copy_u8Port,Pins_t Copy_u8StartPin,u8 Copy_u8ChannelWidth,u16 Copy_u8Value)
{
	switch(Copy_u8Port)
	{ case GPIO_PORTA:REG_GPIO_PORTA->ODR=BitManipulationSetBits(REG_GPIO_PORTA->ODR,Copy_u8StartPin,Copy_u8ChannelWidth,Copy_u8Value);break;
	  case GPIO_PORTB:REG_GPIO_PORTB->ODR=BitManipulationSetBits(REG_GPIO_PORTB->ODR,Copy_u8StartPin,Copy_u8ChannelWidth,Copy_u8Value);break;
	  case GPIO_PORTC:REG_GPIO_PORTC->ODR=BitManipulationSetBits(REG_GPIO_PORTC->ODR,Copy_u8StartPin,Copy_u8ChannelWidth,Copy_u8Value);break;
	}

}

void  GPIO_SetPinValue_BSRR(u8 Copy_u8Port,Pins_t Copy_u8Pin, u8 Copy_u8Value)
{
	
	if ((Copy_u8Pin < GPIO_u8NumOfPins)&&(Copy_u8Port < GPIO_u8NumOfPorts))
	{
		switch(Copy_u8Port)
		{ case GPIO_PORTA: ASSIGN_BIT(REG_GPIO_PORTA->BSRR,Copy_u8Pin, Copy_u8Value);break;
		  case GPIO_PORTB: ASSIGN_BIT(REG_GPIO_PORTB->BSRR,Copy_u8Pin, Copy_u8Value);break;
		  case GPIO_PORTC: ASSIGN_BIT(REG_GPIO_PORTC->BSRR,Copy_u8Pin, Copy_u8Value);break;
		}	   
	}
		
	
	
}
