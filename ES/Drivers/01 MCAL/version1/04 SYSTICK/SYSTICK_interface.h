/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component:SYSTICK         ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */
void STK_voidInit(void);


/*
 * STK_voidStopTimer
 * description: Stops the Timer
 */
void STK_voidStopTimer(void);

/*
 * STK_voidSetBusyWait
 * description: Starts a synchronous wait (delay)
 */
void STK_voidSetBusyWait(u32 Copy_u32TickCount);


/*
 * STK_voidSetPeriodicInterval
 * description: Starts a periodic interval asynchronous wait
 */
void STK_voidSetPeriodicInterval(u32 Copy_u32TickCount, void (*ptr)(void));


/*
 * STK_voidSetSingleInterval
 * description: Starts a single interval asynchronous wait
 */
void STK_voidSetSingleInterval(u32 Copy_u32TickCount, void (*ptr)(void));


/*
 * STK_u32GetRemainingTicks
 * description: Gets the number of ticks remaining until we reach zero
 */
u32 STK_u32GetRemainingTicks(void);

/*
 * STK_u32GetElapsedTicks
 * description: Gets the number of ticks elapsed since we started counting
 */
u32 STK_u32GetElapsedTicks(void);


#endif