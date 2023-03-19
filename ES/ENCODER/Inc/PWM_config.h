/*********************************************************************************/
/* Author    : Habeba Hamada                                                       */
/* Version   : V1                                                               */
/* Date      : 18 Mar 2023                                                     */
/*********************************************************************************/

#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

// pwm_freq=f_clk/(PSC+1)/(ARR+1)

//prescaler=1 and arr=65534 at clk=72MHZ
#define PSC_TIM1 1
#define PSC_TIM2 1
#define PSC_TIM3 1
#define PSC_TIM4 1

#define ARR_TIM1 65534
#define ARR_TIM2 65534
#define ARR_TIM3 65534
#define ARR_TIM4 65534



#endif