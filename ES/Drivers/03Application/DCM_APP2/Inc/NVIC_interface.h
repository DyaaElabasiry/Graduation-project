/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: NVIC            ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum
{
	MemManage,
	BusFault,
	UsageFault,
	SVCall,
	DebugMonitor,
	PendSV,
	Systick,
	NVIC_WWDG,
	EXTI16,
	EXTI21,
	EXTI22,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	EXTI9_5,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	NVIC_TIM2,
	NVIC_TIM3,
	NVIC_TIM4,
    I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	NVIC_SPI1,
	NVIC_SPI2,
	NVIC_USART1,
	NVIC_USART2,
	EXTI15_10,
	RTC_Alarm,
	OTG_FS_WKUP,
	DMA1_Stream7,
	NVIC_SDIO ,
	NVIC_TIM5,
	NVIC_SPI3,
	DMA2_Stream0,
	DMA2_Stream1,
	DMA2_Stream2,
	DMA2_Stream3,
	DMA2_Stream4,
	OTG_FS,
	DMA2_Stream5,
	DMA2_Stream6,
	DMA2_Stream7,
	NVIC_USART6,
	I3C1_EV,
	I3C1_ER,
	FPU,
	NVIC_SPI4,
}INT_PRIO_t;

typedef enum
{
    PRIORITY_0,
	PRIORITY_1,
	PRIORITY_2,
	PRIORITY_3,
	PRIORITY_4,
	PRIORITY_5,
	PRIORITY_6,
	PRIORITY_7,
	PRIORITY_8,
	PRIORITY_9,
	PRIORITY_10,
	PRIORITY_11,
	PRIORITY_12,
	PRIORITY_13,
	PRIORITY_14,
	PRIORITY_15,
	
}Priority_t;
/******************************************************************************/
/*Function      : NVIC_voidEnableInterrupt                             		  */
/*Parameters    : Copy_u8InterruptPriority  --> INT_PRIO_t      			  */
/*Return        : void	                                     				  */
/*Description   :This Function Enables the Interrupt of the peripheral in NVIC*/
/******************************************************************************/
void NVIC_voidEnableInterrupt(INT_PRIO_t Copy_u8InterruptPriority);

/******************************************************************************/
/*Function      : NVIC_voidDisableInterrupt                           		  */
/*Parameters    : Copy_u8InterruptPriority  --> INT_PRIO_t     				  */
/*Return        : void	                                     				  */
/*Description   :This Function Disables the Interrupt of the peripheral in NVIC*/
/******************************************************************************/
void NVIC_voidDisableInterrupt(INT_PRIO_t Copy_u8InterruptPriority);

/******************************************************************************/
/*Function      : NVIC_voidDisableInterrupt                           		  */
/*Parameters    : Copy_u8InterruptPriority  --> INT_PRIO_t     				  */
/*Return        : void	                                     				  */
/*Description   :This Function sets the pending flag of the interrupt         */
/******************************************************************************/
void NVIC_voidSetPendingFlag(INT_PRIO_t Copy_u8InterruptPriority);


/******************************************************************************/
/*Function      : NVIC_voidDisableInterrupt                           		  */
/*Parameters    : Copy_u8InterruptPriority  --> INT_PRIO_t 					  */
/*Return        : void	                                     				  */
/*Description   :This Function clears the pending flag of the interrupt       */
/******************************************************************************/
void NVIC_voidClearPendingFlag(INT_PRIO_t Copy_u8InterruptPriority);

/******************************************************************************/
/*Function      : NVIC_voidDisableInterrupt                           		  */
/*Parameters    : Copy_u8InterruptPriority  --> INT_PRIO_t  				  */
/*Return        : void	                                     				  */
/*Description   :This Function gets the state of Active flag of the interrupt */
/******************************************************************************/
u8 NVIC_u8GetActiveFlag(INT_PRIO_t Copy_u8InterruptPriority);

/******************************************************************************/
/*Function      : NVIC_voidDisableInterrupt                           		  */
/*Parameters    : void                                  					  */
/*Return        : void	                                     				  */
/*Description   :This Function sets the Groups ans SUBGroups priority         */
/******************************************************************************/
void NVIC_voidSetPriorityConfig(void);

/******************************************************************************/
/*Function      : NVIC_VoidSetPriority                               		  */
/*Parameters    : Copy_s8InterruptPosition -->INT_PRIO_t      
                  Copy_u8GroupPriority     -->u8  
                  Copy_u8SubPriority       -->u8             				  */
/*Return        : void	                                     				  */
/*Description   :This Function sets the interrupt priority                    */
/******************************************************************************/
void NVIC_voidSetPriority(INT_PRIO_t Copy_InterruptPosition, Priority_t Copy_u8GroupPriority, Priority_t Copy_u8SubPriority);

#endif
