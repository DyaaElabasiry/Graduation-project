/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: NVIC            ***************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include"STD_TYPES.h"
#include"BIT_Manipulation.h"


#include"NVIC_private.h"
#include"NVIC_config.h"
#include"NVIC_interface.h"

static u32 GlobalStatic_32GroupConfig;

void NVIC_voidEnableInterrupt(INT_PRIO_t Copy_u8InterruptPriority)
{
	Copy_u8InterruptPriority-=7;
	NVIC->ISER[Copy_u8InterruptPriority / 32] = 1 << (Copy_u8InterruptPriority % 32);
}

void NVIC_voidDisableInterrupt(INT_PRIO_t Copy_u8InterruptPriority)
{
	Copy_u8InterruptPriority-=7;
	NVIC->ICER[Copy_u8InterruptPriority / 32] = 1 << (Copy_u8InterruptPriority % 32);
	
}

void NVIC_voidSetPendingFlag(INT_PRIO_t Copy_u8InterruptPriority)
{
	Copy_u8InterruptPriority-=7;
	NVIC->ISPR[Copy_u8InterruptPriority / 32] = 1 << (Copy_u8InterruptPriority % 32);
}

void NVIC_voidClearPendingFlag(INT_PRIO_t Copy_u8InterruptPriority)
{
	Copy_u8InterruptPriority-=7;
	NVIC->ICPR[Copy_u8InterruptPriority / 32] = 1 << (Copy_u8InterruptPriority % 32);
}

u8 NVIC_u8GetActiveFlag(INT_PRIO_t Copy_u8InterruptPriority)
{
	Copy_u8InterruptPriority-=7;
	u8 Local_u8ActiveState = GET_BIT((NVIC->IAPR[Copy_u8InterruptPriority / 32]), (Copy_u8InterruptPriority % 32));
    return Local_u8ActiveState;
}

void NVIC_voidSetPriorityConfig(void)
{
    GlobalStatic_32GroupConfig = 0x05FA0000 | (NVIC_PRIORITY_CONFIGURATION << 8);
    SCB->AIRCR = GlobalStatic_32GroupConfig;
}

void NVIC_voidSetPriority(INT_PRIO_t Copy_InterruptPriority, Priority_t Copy_u8GroupPriority, Priority_t Copy_u8SubPriority)
{
	u8 Local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((GlobalStatic_32GroupConfig - 0x05FA0300) / 256);
	
	if (Copy_InterruptPriority == MemManage || Copy_InterruptPriority == BusFault || Copy_InterruptPriority == UsageFault)
        {
        	
            SCB->SHPR1 = (Local_u8Priority << ((8 * Copy_InterruptPriority) + 4));
        }
    else if (Copy_InterruptPriority == SVCall)
        {
        	
            SCB->SHPR2 = (Local_u8Priority << 28);
        }
    else if (Copy_InterruptPriority == PendSV || Copy_InterruptPriority == Systick)
        {
    	Copy_InterruptPriority -= 3;
            SCB->SHPR3 = (Local_u8Priority << ((8 * Copy_InterruptPriority) + 4));
        }
	 else if (Copy_InterruptPriority > 6)
       {
		Copy_InterruptPriority-=7;
        NVIC->IPR[Copy_InterruptPriority] = (Local_u8Priority << 4);
       }

	
	
}
