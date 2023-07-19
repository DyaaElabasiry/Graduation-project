/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: ESP8266       ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef _ESP8266_CONFIG_H_
#define _ESP8266_CONFIG_H_

/*************************************
 * ESP Mode                          *
 * Options:                          *
 * 		1 --> ESP_STATION_MODE       *
 * 		2 --> ESP_SOFTAP_MODE        *
 * 		3 --> ESP_SOFTAP_STATION_MODE*
 ************************************/
#define ESP_WIFI_MODE         ESP_SOFTAP_STATION_MODE

/*****************************************
 *  USART Connected to ESP                *
 * Options:                               *
 * 		1 --> ESP_USART1                  *
 * 		2 --> ESP_USART2                  *
 * 		3 --> ESP_USART6                  *
 ******************************************/
#define ESP_USART         ESP_USART1
#endif
