/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     MCAL                     */
/*     Component: EXTI                     */
/*     Version:   2.00                     */
/******************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADD     (u32)(0x40013C00)

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;

#define EXTI		((volatile EXTI_t*)EXTI_BASE_ADD)



#define Clear_Pending_Flags      0xffffff



#endif
