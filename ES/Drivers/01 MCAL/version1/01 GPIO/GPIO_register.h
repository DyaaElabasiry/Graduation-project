/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_

#define GPIOA_BASE_ADD     (u32)(0x40020000)
#define GPIOB_BASE_ADD     (u32)(0x40020400)
#define GPIOC_BASE_ADD     (u32)(0x40020800)


#define GPIOA_MODER       *((volatile u32*)(GPIOA_BASE_ADD +0X00))
#define GPIOB_MODER       *((volatile u32*)(GPIOB_BASE_ADD +0X00))
#define GPIOC_MODER       *((volatile u32*)(GPIOC_BASE_ADD +0X00))


#define GPIOA_OTYPER      *((volatile u32*)(GPIOA_BASE_ADD +0X04))
#define GPIOB_OTYPER      *((volatile u32*)(GPIOB_BASE_ADD +0X04))
#define GPIOC_OTYPER      *((volatile u32*)(GPIOC_BASE_ADD +0X04))

#define GPIOA_OSPEEDR     *((volatile u32*)(GPIOA_BASE_ADD +0X08))
#define GPIOB_OSPEEDR     *((volatile u32*)(GPIOB_BASE_ADD +0X08))
#define GPIOC_OSPEEDR     *((volatile u32*)(GPIOC_BASE_ADD +0X08))

#define GPIOA_PUPDR       *((volatile u32*)(GPIOA_BASE_ADD +0X0C))
#define GPIOB_PUPDR       *((volatile u32*)(GPIOB_BASE_ADD +0X0C))
#define GPIOC_PUPDR       *((volatile u32*)(GPIOC_BASE_ADD +0X0C))

#define GPIOA_ODR         *((volatile u32*)(GPIOA_BASE_ADD +0X14))
#define GPIOB_ODR         *((volatile u32*)(GPIOB_BASE_ADD +0X14))
#define GPIOC_ODR         *((volatile u32*)(GPIOC_BASE_ADD +0X14))

#define GPIOA_IDR         *((volatile u32*)(GPIOA_BASE_ADD +0X10))
#define GPIOB_IDR         *((volatile u32*)(GPIOB_BASE_ADD +0X10))
#define GPIOC_IDR         *((volatile u32*)(GPIOC_BASE_ADD +0X10))

#define GPIOA_BSRR        *((volatile u32*)(GPIOA_BASE_ADD +0X18))
#define GPIOB_BSRR        *((volatile u32*)(GPIOB_BASE_ADD +0X18))
#define GPIOC_BSRR        *((volatile u32*)(GPIOC_BASE_ADD +0X18))

#define GPIOA_LCKR        *((volatile u32*)(GPIOA_BASE_ADD +0X1c))
#define GPIOB_LCKR        *((volatile u32*)(GPIOB_BASE_ADD +0X1c))
#define GPIOC_LCKR        *((volatile u32*)(GPIOC_BASE_ADD +0X1c))

#define GPIOA_AFRL        *((volatile u32*)(GPIOA_BASE_ADD +0X20))
#define GPIOB_AFRL        *((volatile u32*)(GPIOB_BASE_ADD +0X20))
#define GPIOC_AFRL        *((volatile u32*)(GPIOC_BASE_ADD +0X20))

#define GPIOA_AFRH        *((volatile u32*)(GPIOA_BASE_ADD +0X24))
#define GPIOB_AFRH        *((volatile u32*)(GPIOB_BASE_ADD +0X24))
#define GPIOC_AFRH        *((volatile u32*)(GPIOC_BASE_ADD +0X24))

#endif