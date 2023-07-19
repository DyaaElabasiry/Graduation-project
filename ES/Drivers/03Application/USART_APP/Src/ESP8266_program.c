/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: ESP8266       ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/


#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "GPIO_interface.h"
#include "USART_interface.h"

#include "ESP8266_interface.h"
#include "ESP8266_private.h"
#include "ESP8266_config.h"


extern u8 ESP8266_AT_COMMAND[5];
extern u8 ESP8266_ECHO_OFF[7];
extern u8 ESP8266_STATION_MODE[13];
extern u8 ESP8266_AT_COMMAND[5];
extern u8 ESP8266_CONNECT_WIFI[40];



ESP8266_Retrun ESP_ESP8266_RetrunInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,USART_t *USARTx)
{

	u8 Local_u8ValidationResult = ESP8266_ERROR;
	u8 Local_u8Timeout = 0;


	/* Enable Used USART */
	USART_voidInit(A_InitStruct, A_ClockInitStruct, USARTx);

    USART_voidSendString(USARTx,ESP8266_AT_COMMAND);

    for(int i=0; i<10000; i++)
    {
        __asm("NOP");
    }

    /* Echo off command */
    while(Local_u8ValidationResult == ESP8266_ERROR && Local_u8Timeout < ESP8266_TIMEOUT)
    {
    	/* send Echo off command */
    	//ESP8266_ECHO_OFF[3]=(char)ESPx->ESP8266_ECHO+'0';
    	USART_voidSendString(USARTx, ESP8266_ECHO_OFF);

    	/* check the OK response */
    	Local_u8ValidationResult = ESP8266_u8OkValidation(USARTx);

    	Local_u8Timeout++;

    	if(Local_u8ValidationResult == ESP8266_ERROR)
    	{
    		Local_u8ValidationResult=ESP8266_ECHOERROR;
    	}

    	else
    	{
    		Local_u8ValidationResult=ESP8266_NoError;
    	}
    }

	/* check timeout */
	if(Local_u8Timeout == ESP8266_TIMEOUT)
	{
		return ESP8266_TimeOut;
	}



    /********Connection Mode*********/
	/*
	 * Return Local_u8Timeout and Local_u8ValidationResult to their initial value
	 */
	Local_u8Timeout = 0;
	Local_u8ValidationResult = ESP8266_ERROR;


	/*set WIFI station mode */
	while(Local_u8ValidationResult == ESP8266_ERROR && Local_u8Timeout < ESP8266_TIMEOUT)
	{
		/* station mode command */
		USART_voidSendString(USARTx, ESP8266_STATION_MODE);

		/* check the OK response */
		Local_u8ValidationResult = ESP8266_u8OkValidation(USARTx);

		Local_u8Timeout++;

		/*check the type of Error*/
		if(Local_u8ValidationResult == ESP8266_ERROR)
		{
			Local_u8ValidationResult=ESP8266_MODEERROR;
		}
		else
		{
			Local_u8ValidationResult=ESP8266_NoError;
		}
	}


	/* check timeout */
	if(Local_u8Timeout == ESP8266_TIMEOUT)
	{
		return ESP8266_TimeOut;
	}

	return ESP8266_NoError;
}


ESP8266_Retrun ESP8266_u8OkValidation(USART_t* USARTx)
{
	u8 Local_u8Result = ESP8266_ERROR;
	u8 Local_u8Data = 0;


	u8 arr[2] = "NO"; /*Debugging*/


	/* loop until there is no data to receive */
	while(1)
	{
		/* receive response of the WIFI module */
		USART_voidReceiveByteSynchBlocking(USARTx, &Local_u8Data);

		/* check for OK response */
		if(Local_u8Data == 'O')
		{
			arr[0] = Local_u8Data;

			USART_voidReceiveByteSynchBlocking(USARTx, &Local_u8Data);

			if(Local_u8Data == 'K')
			{
				arr[1] = Local_u8Data;

				Local_u8Result = ESP8266_OK;
				break;
			}
		}
	}

	return Local_u8Result;
}

ESP8266_Retrun ESP_ESP8266_RetrunConnectToWIFI(USART_t *USARTx)
{
	u8 Local_u8ValidationResult = ESP8266_ERROR;

	/* sending connect to WIFI command command */
	while(Local_u8ValidationResult == ESP8266_ERROR)
	{

		USART_voidSendString(USARTx,  ESP8266_CONNECT_WIFI);

		/* check the OK response */
		Local_u8ValidationResult = ESP8266_u8OkValidation(USARTx);

		if(Local_u8ValidationResult == ESP8266_ERROR)
		{
			Local_u8ValidationResult=ESP8266_CONNECTIONERROR;
		}

		else
		{
			Local_u8ValidationResult=ESP8266_NoError;
		}
	}




}

