/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 3.00            ****************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_Manipulation.h"


#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"




void GPIO_SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Mode )
{
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		GPIOA->MODER &= ~(0b11<<(Copy_u8Pin*2));
		GPIOA->MODER |= (Copy_u8Mode<<(Copy_u8Pin*2));

		break;

	case GPIO_PORTB:
		GPIOB->MODER &= ~(0b11<<(Copy_u8Pin*2));
		GPIOB->MODER |= (Copy_u8Mode<<(Copy_u8Pin*2));

		break;

	case GPIO_PORTC:
		GPIOC->MODER &= ~(0b11<<(Copy_u8Pin*2));
		GPIOC->MODER |= (Copy_u8Mode<<(Copy_u8Pin*2));

		break;


	}

}

void GPIO_SetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8OutputType )
{
	if(Copy_u8OutputType == Output_Open_Drain)
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->OTYPER, Copy_u8Pin);
			break;
		}
	}
	else if(Copy_u8OutputType == Output_Push_Pull)
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA:
			CLEAR_BIT(GPIOA->OTYPER, Copy_u8Pin);
			break;
		}
	}
}

void GPIO_SetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8OutputSpeed )
{
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		GPIOA->OSPEEDR &= ~(0b11<<(Copy_u8Pin*2));
		GPIOA->OSPEEDR |= (Copy_u8OutputSpeed<<(Copy_u8Pin*2));

		break;

	case GPIO_PORTB:
		GPIOB->OSPEEDR &= ~(0b11<<(Copy_u8Pin*2));
		GPIOB->OSPEEDR |= (Copy_u8OutputSpeed<<(Copy_u8Pin*2));

		break;

	case GPIO_PORTC:
		GPIOC->OSPEEDR &= ~(0b11<<(Copy_u8Pin*2));
		GPIOC->OSPEEDR |= (Copy_u8OutputSpeed<<(Copy_u8Pin*2));

		break;


	}

}

void GPIO_SetPinInputPull(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8PullType )
{
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		GPIOA->PUPDR &= ~(0b11<<(Copy_u8Pin*2));
		GPIOA->PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2));

		break;

	case GPIO_PORTB:
		GPIOB->PUPDR &= ~(0b11<<(Copy_u8Pin*2));
		GPIOB->PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2));

		break;

	case GPIO_PORTC:
		GPIOC->PUPDR &= ~(0b11<<(Copy_u8Pin*2));
		GPIOC->PUPDR |= (Copy_u8PullType<<(Copy_u8Pin*2));

		break;


	}
}

void GPIO_SetAlternativeFunction(u8 Copy_u8Port, u8 Copy_u8Pin,  u8 Copy_u8AlternateFunction)
{
	if(Copy_u8Pin<8)
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA:
			GPIOA->AFRL &= ~(0b1111<<(Copy_u8Pin*4));
			GPIOA->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));

			break;

		case GPIO_PORTB:
			GPIOB->AFRL &= ~(0b1111<<(Copy_u8Pin*4));
			GPIOB->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));

			break;

		case GPIO_PORTC:
			GPIOC->AFRL &= ~(0b1111<<(Copy_u8Pin*4));
			GPIOC->AFRL |= (Copy_u8AlternateFunction<<(Copy_u8Pin*4));

			break;
    	}
	}
	else if(Copy_u8Pin>=8)
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA:
			GPIOA->AFRH &= ~(0b1111<<((Copy_u8Pin-8)*4));
			GPIOA->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin-8)*4);

			break;

		case GPIO_PORTB:
			GPIOB->AFRH &= ~(0b1111<<(Copy_u8Pin-8)*4);
			GPIOB->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin-8)*4);

			break;

		case GPIO_PORTC:
			GPIOC->AFRH &= ~(0b1111<<(Copy_u8Pin-8)*4);
			GPIOC->AFRH |= (Copy_u8AlternateFunction<<(Copy_u8Pin-8)*4);

			break;
    	}
	}
}

u8   GPIO_GetPinValue(M_GPIO_CONFIG_t* PinConfig )
{
	u8 Local_u8PinValue = 0;
	switch(PinConfig->Port)
	{
	case GPIO_PORTA:
		Local_u8PinValue = GET_BIT(GPIOA->IDR, PinConfig->Pin);
		 break;
	case GPIO_PORTB:
		Local_u8PinValue = GET_BIT(GPIOB->IDR, PinConfig->Pin);
		 break;
	case GPIO_PORTC:
		Local_u8PinValue = GET_BIT(GPIOC->IDR, PinConfig->Pin);
		 break;
	}

	return Local_u8PinValue;
}

void GPIO_SetPinValue(M_GPIO_CONFIG_t* PinConfig,  u8 Copy_u8PinVal)
{
	if(Copy_u8PinVal == GPIO_PIN_HIGH)
	{
		switch(PinConfig->Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->ODR,PinConfig->Pin );
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,PinConfig->Pin );
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,PinConfig->Pin );
			break;
		}
	}
	else if(Copy_u8PinVal == GPIO_PIN_LOW)
	{
		switch(PinConfig->Port)
		{
		case GPIO_PORTA:
			CLEAR_BIT(GPIOA->ODR,PinConfig->Pin);
			break;
		case GPIO_PORTB:
			CLEAR_BIT(GPIOB->ODR,PinConfig->Pin);
			break;
		case GPIO_PORTC:
			CLEAR_BIT(GPIOC->ODR,PinConfig->Pin );
			break;
		}
	}
}

void GPIO_SetPinValue_AtomicAccess(M_GPIO_CONFIG_t* PinConfig,  u8 Copy_u8PinVal)
{
	if(Copy_u8PinVal == GPIO_PIN_HIGH)
	{
		switch(PinConfig->Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->BSRR,PinConfig->Pin );
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->BSRR,PinConfig->Pin );
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->BSRR,PinConfig->Pin );
			break;
		}
	}
	else if(Copy_u8PinVal == GPIO_PIN_LOW)
	{
		switch(PinConfig->Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->BSRR,((PinConfig->Pin)+16) );
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->BSRR,((PinConfig->Pin)+16) );
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->BSRR,((PinConfig->Pin)+16) );
			break;
		}
	}
}


void GPIO_voidInit(M_GPIO_CONFIG_t* PinConfig)
{
	GPIO_SetPinMode(PinConfig->Port, PinConfig->Pin , PinConfig->Mode);
	GPIO_SetPinOutputType(PinConfig->Port, PinConfig->Pin , PinConfig->OutputType);
	GPIO_SetPinOutputSpeed(PinConfig->Port, PinConfig->Pin , PinConfig->OutputSpeed );
    GPIO_SetPinInputPull(PinConfig->Port, PinConfig->Pin , PinConfig->InputPull );
    GPIO_SetAlternativeFunction(PinConfig->Port, PinConfig->Pin , PinConfig->AF);





}

