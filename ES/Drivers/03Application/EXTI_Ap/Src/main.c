#include <stdint.h>



#include"STD_TYPES.h"
#include"BIT_Manipulation.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"

void LED_voidToggle(void);
M_GPIO_CONFIG_t LED={GPIO_PORTA,
			             GPIO_PIN1,
						 General_Purpose_Output_Mode,
						 Output_Push_Pull,
						 Medium_Speed,
						 No_Pull_Up_or_Down,
    					 AF11,};


int main(void)
{

	RCC_voidSystemClockInit();
	RCC_voidPeripheralClockEnable(RCC_AHB1,GPIOA);

	/*Selection line of MUX*/
	RCC_voidPeripheralClockEnable(RCC_APB2,SYSCFG);


	M_GPIO_CONFIG_t EXTI_PIN={GPIO_PORTA,
				             GPIO_PIN0,
							 Input_Mode,
							 Output_Push_Pull,
							 Medium_Speed,
							 Pull_Up,
	    					 AF11,};

	GPIO_voidInit(&LED);
	GPIO_voidInit(&EXTI_PIN);

	EXTI_LINEx  EXTI_L0={EXTI_Line0,
		               EXTI_RISING_EDGE};

	EXTI_voidInit(&EXTI_L0);

	NVIC_voidEnableInterrupt(EXTI0);

	EXTI_voidSetCallBack(&EXTI_L0,LED_voidToggle);
	//EXTI_voidSoftwareTrigger(&EXTI_L0);


    while(1);
}

void LED_voidToggle(void)
{
	static u8 x;
	x=1-x;
	GPIO_SetPinValue(&LED,x);
}
