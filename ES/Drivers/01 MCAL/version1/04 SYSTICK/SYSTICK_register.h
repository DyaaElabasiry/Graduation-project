/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component:SYSTICK         ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_

typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_t;

#define SYSTICK_BASE_ADDRESS		0xE000E010

#define  SYSTICK	               ((volatile SYSTICK_t *)SYSTICK_BASE_ADDRESS)

#define STK_CTRL_ENABLE            0
#define STK_CTRL_TICKINT           1
#define STK_CTRL_CLKSOURCE         2
#define STK_CTRL_COUNTFLAG         16

#endif
