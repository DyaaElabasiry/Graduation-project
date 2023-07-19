/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     HAL                      */
/*     Component: DCM                      */
/*     Version:   1.00                     */
/******************************************/

#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

typedef struct
{
	u8 PORT:1;
	u8 Direction_Pin:4; //output pin
	u8 PWM_Pin:4;
	u8 ENCA:4;         //input (EXTI pin)
	u8 ENCB:4;        //input*/
	/*u8 PINA:1;  //output
	u8 PINB:1;  //output*/
}DCM_t;

/*
 Function Name:        DCM_voidInit
 Function Arguments:   DCM->DCM_t*
 Function Return:      void
 Function Description: initialize Initial parameters for DC motor
 
*/
void DCM_voidInit(DCM_t* DCM);

/*
 Function Name:        DCM_voidRotateCW
 Function Arguments:   DCM->DCM_t*
 Function Return:      void
 Function Description: rotate DC motor in clock wise direction

*/
void DCM_voidRotateCW(DCM_t* DCM);

/*
 Function Name:        DCM_voidRotateCW
 Function Arguments:   DCM->DCM_t*
 Function Return:      void
 Function Description: rotate DC motor in counter clock wise direction

*/
void DCM_voidRotateCCW(DCM_t* DCM);


/*
 Function Name:        DCM_voidSTOP
 Function Arguments:   DCM->DCM_t*
 Function Return:      void
 Function Description: make DC motor stop

*/
void DCM_voidSTOP(DCM_t* DCM);

u8 DCM_u8DetectDirection_ENCA();
u8 DCM_u8DetectDirection_ENCB();

void DCM_voidENCAISR(void);
void DCM_voidENCBISR(void);
#endif
