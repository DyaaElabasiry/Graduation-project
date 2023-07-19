/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: ESP8266       ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef _ESP8266_INTERFACE_H_
#define _ESP8266_INTERFACE_H_

typedef struct
{
	u8 ESP8266_ECHO;
	u8 ESP8266_CONNCETION_MODE;
	u8 ESP8266_WIFI_ID;
	u8 ESP8266_WIFI_PASSWORD;

}ESP8266_t;

typedef enum
{
	ESP8266_ERROR,
	ESP8266_OK,
	ESP8266_TimeOut,
	ESP8266_NoError,
	ESP8266_ECHOERROR,
	ESP8266_MODEERROR,
	ESP8266_CONNECTIONERROR,
}ESP8266_Retrun;


/**********************************************************************
 * Function Name        : ESP_ESP8266_RetrunInit                       *
 *                                                                     *
 * Return type          : ESP8266_Retrun "enum"                        *
 * Function arguments   : A_InitStruct     ->  USART_InitType          *
 *                        A_ClockInitStruct->  USART_ClockInitTypeDef  *
 *                        USARTx           ->  USART_t                 *
 * Function Description : set the ESP8266 configuration                *
 ***********************************************************************/

ESP8266_Retrun ESP_ESP8266_RetrunInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx);


/**********************************************************************
 * Function Name        : ESP_ESP8266_RetrunConnectToWIFI              *
 *                                                                     *
 * Return type          : ESP8266_Retrun "enum"                        *
 * Function arguments   : USARTx           ->  USART_t                 *
 * Function Description : connect ESP8266 to WIFI                      *
 ***********************************************************************/
ESP8266_Retrun ESP_ESP8266_RetrunConnectToWIFI(USART_t *USARTx);

#endif
