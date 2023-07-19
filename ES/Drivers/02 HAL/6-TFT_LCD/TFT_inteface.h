/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: TFT           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_


typedef struct
{
	u8 TFT_u8ResetPin;
	u8 TFT_u8A0Pin;
}TFT_t;



/************************************************
 * Name        : TFT_voidInit                   *
 * Return type : void                           *
 * Arguments   : void                           *
 * description : initialization of TFT          *
 ************************************************/
void TFT_voidInit(void);


/************************************************
 * Name        : TFT_voidReset                  *
 * Return type : void                           *
 * Arguments   : void                           *
 * description : Reset sequence of TFT          *
 ************************************************/
void TFT_voidReset(void);


/************************************************
 * Name        : TFT_voidSendData               *
 * Return type : void                           *
 * Arguments   : copy_u8Data -> u8              *
 * description : sending Data to TFT            *
 ************************************************/
void TFT_voidSendData(u8 copy_u8Data);


/************************************************
 * Name        : TFT_voidSendCommand            *
 * Return type : void                           *
 * Arguments   : copy_u8Command -> u8           *
 * description : sending Command to TFT         *
 ************************************************/
void TFT_voidSendCommand(u8 copy_u8Command);

#endif