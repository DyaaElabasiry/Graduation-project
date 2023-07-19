/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component:STK             ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_


#define STK_BASE_ADDRESS		(u32)0xE000E010

typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;


#define  STK	               ((volatile STK_t *)STK_BASE_ADDRESS)

typedef enum
{
	ENABLE,
	TICKINT,
	CLKSOURCE,
	COUNTFLAG=16,	
}CTRL_t;

#define STK_CTRL_ENABLE            0
#define STK_CTRL_TICKINT           1
#define STK_CTRL_CLKSOURCE         2
#define STK_CTRL_COUNTFLAG         16


#define   STK_AHB_DIV_8	           0
#define   STK_AHB             	   1       

#define   STK_PERIODIC_INTERVAL 	0
#define   STK_SINGLE_INTERVAL 	    1

#endif
