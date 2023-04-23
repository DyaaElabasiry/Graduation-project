/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: NVIC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADD                (u32)(0xE000E100)

typedef struct
{

    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IAPR[32];
    volatile u32 RESERVED[32];
    volatile u8  IPR[128];

}NVIC_t;


#define NVIC  ((volatile NVIC_t*)(NVIC_BASE_ADD))

#define NVIC_STIR ((volatile u32*)(NVIC_BASE_ADD+E00))

/******************************************SCB Registers*****************************************************/

#define SCB_BASE_ADD                (u32)(0xE000ED00)

typedef struct
{

    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR1;
    volatile u32 SHPR2;
    volatile u32 SHPR3;
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;

}SCB_t;

#define SCB ((volatile SCB_t*)SCB_BASE_ADD)

/***********************************************************************************************************/
/* choose the number of groups,
   subgroups config in 
   NVIC_voidSetPriorityConfig  Function*/
#define _16GROUP_NONE_SUBGROUP     0b011
#define _8GROUP_2SUBGROUP          0b100
#define _4GROUP_4SUBGROUP          0b101
#define _NONE_GROUP_16SUBGROUP     0b111

#endif
