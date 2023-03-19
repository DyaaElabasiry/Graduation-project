/*********************************************************************************/
/* Author    : Habeba Hamada                                                       */
/* Version   : V1                                                               */
/* Date      : 18 Mar 2023                                                     */
/*********************************************************************************/

#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#define TIM1 1
#define TIM2 2
#define TIM3 3
#define TIM4 4

#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4


void  PWM_voidSetPinDirection(u8 Copy_u8tim, u8 Copy_u8ch);
void  PWM_voidWrite(u8 Copy_u8tim, u8 Copy_u8ch,u16 Copy_u16dutyCycle);


#endif