/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: Shift Register ***************/
/*************       Version: 1.00            ****************/
/*************************************************************/





#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GPIO_interface.h"

#include "ShiftReg_interface.h"
#include "ShiftReg_private.h"
#include "ShiftReg_config.h"


void ShiftRegister_voidSendData(ShiftRegister Copy_ShiftReg, u8 Copy_u8Data)
{
	GPIO_SetPinValue(Copy_ShiftReg.Output_Enable_Port, Copy_ShiftReg.Output_Enable_Pin, GPIO_PIN_LOW);
	GPIO_SetPinValue(Copy_ShiftReg.Latch_Clock_Port, Copy_ShiftReg.Latch_Clock_Pin, GPIO_PIN_LOW);

	for(int Local_intIterator = 7; Local_intIterator > -1 ; Local_intIterator--)
	{
		GPIO_SetPinValue(Copy_ShiftReg.Shift_Clock_Port, Copy_ShiftReg.Shift_Clock_Pin, GPIO_PIN_LOW);
		GPIO_SetPinValue(Copy_ShiftReg.Data_Port, Copy_ShiftReg.Data_Pin, GET_BIT(Copy_u8Data, Local_intIterator));
		GPIO_SetPinValue(Copy_ShiftReg.Shift_Clock_Port, Copy_ShiftReg.Shift_Clock_Pin, GPIO_PIN_HIGH);
	}

	GPIO_SetPinValue(Copy_ShiftReg.Latch_Clock_Port, Copy_ShiftReg.Latch_Clock_Pin, GPIO_PIN_HIGH);
}
