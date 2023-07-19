/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component:STK             ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_


/*
 * NAME:STK_voidInit
 * RETURN TYPE: void
 * ARGUMENTS: void
 * DESCRIPTION: Initiate Systick Timer
 */
void STK_voidInit(void);

/*
 * NAME:STK_voidStopTimer
 * RETURN TYPE: void
 * ARGUMENTS: void
 * DESCRIPTION: Stop Systick Timer
 */
void STK_voidStopTimer(void);

/*
 * NAME:STK_voidSetBusyWait
 * RETURN TYPE: void
 * ARGUMENTS: Copy_u32TickCount:u32 
 * DESCRIPTION: Starts a synchronous wait (delay)
 */
void STK_voidSetBusyWait(u32 Copy_u32TickCount);


 /*
 * NAME:STK_voidSetPeriodicInterval
 * RETURN TYPE: void
 * ARGUMENTS: Copy_u32TickCount:u32 
 *            CallBackFunction: Pointer to void Function
 * DESCRIPTION: Starts a periodic interval asynchronous wait
 */
void STK_voidSetPeriodicInterval(u32 Copy_u32TickCount, void (*CallBackFunction)(void));


 /*
 * NAME:STK_voidSetSingleInterval
 * RETURN TYPE: void
 * ARGUMENTS: Copy_u32TickCount:u32 
 *            CallBackFunction: Pointer to void Function
 * DESCRIPTION: Starts a Single interval asynchronous wait
 */
void STK_voidSetSingleInterval(u32 Copy_u32TickCount, void (*CallBackFunction)(void));

 /*
 * NAME:STK_u32GetRemainingTime
 * RETURN TYPE: u32
 * ARGUMENTS: void
 * DESCRIPTION: Gets the number of ticks remaining until we reach zero
 */
u32 STK_u32GetRemainingTime(void);


 /*
 * NAME:STK_u32GetElapsedTime
 * RETURN TYPE: u32
 * ARGUMENTS: void
 * DESCRIPTION: Gets the number of ticks elapsed since we started counting
 */
u32 STK_u32GetElapsedTime(void);


#endif