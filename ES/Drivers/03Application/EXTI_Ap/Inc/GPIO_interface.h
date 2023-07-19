/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GPIO           ****************/
/*************       Version: 3.00            ****************/
/*************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*************************************************************************************************/

#define  GPIO_PIN_HIGH    1
#define  GPIO_PIN_LOW     0


#define  GPIO_PORT_HIGH      0XFFFF
#define  GPIO_PORT_LOW        0


#define Input_Mode                             00
#define General_Purpose_Output_Mode            01
#define Alternate_Function_Mode                10
#define Analog_Mode                            11

#define Output_Push_Pull                       0
#define Output_Open_Drain                      1

#define Low_Speed                              00
#define Medium_Speed                           01
#define High_Speed                             10
#define Very_High_Speed                        11


#define No_Pull_Up_or_Down                     00
#define Pull_Up                                01
#define Pull_Down                              10

#define Not_Active_Lock                        0
#define Active_Lock                            1


#define Not_Locked                             0
#define Locked                                 1


/**********************************************************************************************************/

typedef enum{
        GPIO_PORTA ,
	    GPIO_PORTB,
	    GPIO_PORTC,

}Port_t;

/********************************************************************************************************/
/*Note: PORTA doesn't have pin 13,14 and PORTC has only 13,14,15 pins*/
typedef enum{
        GPIO_PIN0 ,
	    GPIO_PIN1 ,
	    GPIO_PIN2 ,
	    GPIO_PIN3 ,
	    GPIO_PIN4 ,
	    GPIO_PIN5 ,
		GPIO_PIN6 ,
	    GPIO_PIN7 ,
	    GPIO_PIN8 ,
		GPIO_PIN9 ,
		GPIO_PIN10,
		GPIO_PIN11,
		GPIO_PIN12,
		GPIO_PIN13,
	    GPIO_PIN14,
        GPIO_PIN15,

}Pins_t;

/**********************************************************************************************************************/
/*
	NOTE --> see to the MC Pin out to know the multiple function of each pin and choose one of them

	alternate functions options:
		1)  AF0            --> system
		2)  AF1            --> TIM1\TIM2
		3)  AF2            --> TIM3..5
		4)  AF3            --> TIM9..11
		5)  AF4            --> I2C1..3
		6)  AF5            --> SPI1..4
		7)  AF6            --> SPI3
		8)  AF7            --> USART1..2
		9)  AF8            --> USART6
		10) AF9            --> I2C2..3
		11) AF10           --> OTG_FS
		12) AF11           -->
		13) AF12           --> SDIO
		14) AF13           -->
		15) AF14           -->
		16) AF15           --> EVENTOUT
*/
typedef enum {
        AF0 ,
	    AF1 ,
	    AF2 ,
	    AF3 ,
	    AF4 ,
	    AF5 ,
		AF6 ,
	    AF7 ,
	    AF8 ,
		AF9 ,
		AF10,
		AF11,
		AF12,
		AF13,
	    AF14,
        AF15,

}AF_t;

/**********************************************************************************************************/
typedef struct M_GPIO_CONFIG  M_GPIO_CONFIG_t;

struct M_GPIO_CONFIG
{
	Port_t Port;
	Pins_t Pin;
	u8     Mode;
	u8     OutputType;
	u8     OutputSpeed;
	u8     InputPull;
	AF_t     AF;

};
/***********************************************************************************************************/
/*
 Function Name:        GPIO_SetPinMode
 Function Arguments:   Copy_u8Port--> u8
                       Copy_u8Pin --> u8
                       Copy_u8Mode-->u8
 Function Return:      void
 Function Description: configure pin mode
*/
void GPIO_SetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);

/*
 Function Name:        GPIO_SetPinOutputType
 Function Arguments:   Copy_u8Port--> u8
                       Copy_u8Pin --> u8
                       Copy_u8OutputType-->u8
 Function Return:      void
 Function Description: configure output type
*/
void GPIO_SetPinOutputType(u8 Copy_u8Port,u8 Copy_u8Pin ,u8 Copy_u8OutputType );

/*
 Function Name:        GPIO_SetPinOutputSpeed
 Function Arguments:   Copy_u8Port--> u8
                       Copy_u8Pin --> u8
                       Copy_u8OutputSpeed-->u8
 Function Return:      void
 Function Description: configure speed of output pin
*/
void GPIO_SetPinOutputSpeed(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutputSpeed );

/*
 Function Name:        GPIO_SetPinInputPull
 Function Arguments:   Copy_u8Port--> u8
                       Copy_u8Pin --> u8
                       Copy_u8PullType-->u8
 Function Return:      void
 Function Description: configure pull type for input pin
*/
void GPIO_SetPinInputPull(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PullType );

/*
 Function Name:        GPIO_SetAlternativeFunction
 Function Arguments:   Copy_u8Port--> u8
                       Copy_u8Pin --> u8
                       Copy_u8AlternateFunction-->u8
 Function Return:      void
 Function Description: configure AF pin
*/
void GPIO_SetAlternativeFunction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8AlternateFunction);

/*
 Function Name:        GPIO_GetPinValue
 Function Arguments:   PinConfig --> M_GPIO_CONFIG_t*
 Function Return:      u8
 Function Description: get value from pin
*/
u8 GPIO_GetPinValue(M_GPIO_CONFIG_t* PinConfig );

/*
 Function Name:        GPIO_SetPinValue
 Function Arguments:   PinConfig     --> M_GPIO_CONFIG_t*
                       Copy_u8PinVal -->u8
 Function Return:      void
 Function Description: set pin value
*/
void GPIO_SetPinValue(M_GPIO_CONFIG_t* PinConfig,  u8 Copy_u8PinVal);

/*
 Function Name:        GPIO_SetPinValue_AtomicAccess
 Function Arguments:   PinConfig     --> M_GPIO_CONFIG_t*
                       Copy_u8PinVal -->u8
 Function Return:      void
 Function Description: set pin value atomic access
*/
void GPIO_SetPinValue_AtomicAccess(M_GPIO_CONFIG_t* PinConfig, u8 Copy_u8PinVal);

/*
 Function Name:        GPIO_voidInit
 Function Arguments:   PinConfig     --> M_GPIO_CONFIG_t*
 Function Return:      void
 Function Description: initialize pin configuration
*/
void GPIO_voidInit(M_GPIO_CONFIG_t* PinConfig);

/*
 Function Name:        GPIO_voidSetGroupChannel
 Function Arguments:   Copy_u8Port     --> u8
                       Copy_u8StartPin -->pins_t
                       Copy_u8ChannelWidth -->u8
                       Copy_u8Value    -->u16
 Function Return:      void
 Function Description: set group of pins
*/
void GPIO_voidSetGroupChannel(u8 Copy_u8Port,Pins_t Copy_u8StartPin,u8 Copy_u8ChannelWidth,u16 Copy_u8Value);

#endif



