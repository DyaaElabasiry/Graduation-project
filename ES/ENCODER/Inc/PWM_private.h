/*********************************************************************************/
/* Author    : Habeba Hamada                                                       */
/* Version   : V1                                                                  */
/* Date      : 18 Mar 2023                                                         */
/*********************************************************************************/

#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H


#define TIM1_Base_Address      (u32)(0x40010000)
#define TIM2_Base_Address      (u32)(0x40000000)
#define TIM3_Base_Address      (u32)(0x40000400)
#define TIM4_Base_Address      (u32)(0x40000800)


typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;

}TIM1_t;

#define TIMER1		((volatile TIM1_t*)TIM1_Base_Address)


/***********   REGISTER ADDRESSES FOR TIM2     ***********************/

typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;

	volatile u32 RESERVED;   //Empty

	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;

	volatile u32 RESERVED1;   //Empty

	volatile u32 DCR;
	volatile u32 DMAR;

}TIM_t;


#define TIMER2		((volatile TIM_t*)TIM2_Base_Address)
#define TIMER3		((volatile TIM_t*)TIM3_Base_Address)
#define TIMER4		((volatile TIM_t*)TIM4_Base_Address)

typedef enum
{
	CEN,
	UDIS,
	URS	,
	OPM	,
	DIR	,
	CMS0,
	CMS1,
	ARPE,
	CKD0,
	CKD1,

}CR1_PINS_t;


typedef enum
{
	CC1S0,
	CC1S1,
	OC1PE=3,
	OC1M0,
	OC1M1,
	OC1M2,
	CC2S0=8,
	CC2S1,
	OC2PE=11,
	OC2M0,
	OC2M1,
	OC2M2,

}CCMR1_PINS_t;

typedef enum
{
	CC3S0,
	CC3S1,
	OC3PE=3,
	OC3M0,
	OC3M1,
	OC3M2,
	CC4S0=8,
	CC4S1,
	OC4PE=11,
	OC4M0,
	OC4M1,
	OC4M2,

}CCMR2_PINS_t;

typedef enum
{
	CC1E,
	CC1P,
	CC1NP=3,
	CC2E,
	CC2P,
	CC2NP=7,
	CC3E,
	CC3P,
	CC3NP=11,
	CC4E,
	CC4P,
	CC4NP=15,

}CCER_PINS_t;

typedef enum
{
	UG,
}EGR_PINS_t;



#define ENABLE    1
#define DISABLE   0

#endif
