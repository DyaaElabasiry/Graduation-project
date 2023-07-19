/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: Shift Register ***************/
/*************       Version: 1.00            ****************/
/*************************************************************/



#ifndef _SHIFTREG_INTERFACE_H_
#define _SHIFTREG_INTERFACE_H_



typedef struct ShiftRegister ShiftRegister;

struct ShiftRegister
{
	u8 Data_Port;
	u8 Data_Pin;
	u8 Shift_Clock_Port;
	u8 Shift_Clock_Pin;
	u8 Latch_Clock_Port;
	u8 Latch_Clock_Pin;
	u8 Output_Enable_Port;
	u8 Output_Enable_Pin;
};


/*****************
 * Name        : ShiftRegister_voidSendData        *
 * Return type : void                              *
 * Arguments   : Copy_ShiftReg  --> ShiftRegister  *
 *               Copy_u8Data    --> u8             *
 * description : Sends Data to Shift Register      *
 *****************/
void ShiftRegister_voidSendData(ShiftRegister Copy_ShiftReg, u8 Copy_u8Data);
void ShiftReg_voidInit(void);


#endif
