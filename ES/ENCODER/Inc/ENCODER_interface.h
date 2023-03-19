/*******************************************/
/*     Author:    Habeba Hamada            */
/*     LAYER:     HAL                      */
/*     Component: ENCODER                  */
/*     Version:   2.00                     */
/******************************************/
#ifndef ENCODER_INTERFACE_H_
#define ENCODER_INTERFACE_H_

typedef struct
{

	s64 EncoderCounter;
	u16 EncoderResolution;

	u8  Encoder_A_Port , Encoder_A_Pin;
	u8  Encoder_B_Port , Encoder_B_Pin;

	s32 RPM;

	s64 LastEncoderCounter;
	u32  CurrentTime, LastTime;
	f32 delta_time;
	void (*ptr_forward) (void);
	void (*ptr_backward) (void);
	EXTI_LINE_t Encoder_A_IRQn;
	EXTI_LINE_t Encoder_B_IRQn;

}Encoder_variables;


/*
 Function Name:        Encoder_init
 Function Arguments:   copy_Encoder-->Encoder_variables *
 Function Return:      void
 Function Description: init Encoder parameters
*/
void Encoder_init			(Encoder_variables *copy_Encoder);


/*
 Function Name:        Encoder_init
 Function Arguments:   copy_Encoder-->Encoder_variables *
 Function Return:      void
 Function Description: init Encoder forward function
*/
void Encoder_Forward	(Encoder_variables *copy_Encoder);


/*
 Function Name:        Encoder_init
 Function Arguments:   copy_Encoder-->Encoder_variables *
 Function Return:      void
 Function Description: init Encoder backward function
*/
void Encoder_Backward	(Encoder_variables *copy_Encoder);



/*
 Function Name:        Encoder_init
 Function Arguments:   copy_Encoder-->Encoder_variables *
 Function Return:      void
 Function Description: Calculate RPM form encoder counter
*/

void RPM_Calculate		(Encoder_variables *copy_Encoder);



#endif /* ENCODER_INTERFACE_H_ */
