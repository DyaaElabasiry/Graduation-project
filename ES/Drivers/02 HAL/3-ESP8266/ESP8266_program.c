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


/***************************************************
 * Name        : ESP_voidInit                      *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : initialization of ESP             *
 **************************************************/
 
void ESP_voidInit(void)
{
#if ESP_USART == ESP_USART1
	USART1_voidInit();
	USART1_voidSendString("AT+CWMODE=" ESP_WIFI_MODE "\r\n");

#elif ESP_USART == ESP_USART2
    USART2_voidInit();
	USART2_voidSendString("AT+CWMODE=" ESP_WIFI_MODE "\r\n");

#elif ESP_USART == ESP_USART6
	USART6_voidInit();
	USART6_voidSendString("AT+CWMODE=" ESP_WIFI_MODE "\r\n");

#endif
	
}

/***************************************************
 * Name        : ESP_u8ConnectToWIFI               *
 * Return type : void                              *
 * Arguments   : Ptr_u8SSID ->u8*                  *
 *               Ptr_u8password ->u8*              *
 * description : Connect ESP To WIFI               *
 **************************************************/
void ESP_voidConnectToWIFI()
{
#if ESP_USART == ESP_USART1
	USART1_voidSendString("AT+CWJAP_CUR=" ESP_WIFI_ID "," ESP_WIFI_PASSWORD "\r\n");
#elif ESP_USART == ESP_USART2
	USART2_voidSendString("AT+CWJAP_CUR=" ESP_WIFI_ID "," ESP_WIFI_PASSWORD "\r\n");
#elif ESP_USART == ESP_USART6
	USART6_voidSendString("AT+CWJAP_CUR=" ESP_WIFI_ID "," ESP_WIFI_PASSWORD "\r\n");

}


