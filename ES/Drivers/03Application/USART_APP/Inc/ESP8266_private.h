/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: ESP8266       ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef _ESP8266_PRIVATE_H_
#define _ESP8266_PRIVATE_H_

#define ESP826_ECHO_OFF   0
#define ESP8266_ECHO_ON    1

#define ESP8266_TIMEOUT    10000

#define ESP_STATION_MODE              1
#define ESP8266_SOFTAP_MODE           2
#define ESP8266_BOTH_MODES            3

/****************************************************************************
 * Name        : ESP8266_u8OkValidation                                     *
 *                                                                          *
 * Return type : ESP8266_Retrun                                             *
 *                                                                          *
 * Arguments   : ptr_USARTx -> ( USART1, USART2, USART6 )                   *
 * 	                                                                        *
 * Type        : Synchronous                                                *
 *                                                                          *
 * description : Check for the Response of the WIFI Module                  *
 ****************************************************************************/
ESP8266_Retrun ESP8266_u8OkValidation(USART_t* ptr_USARTx);

#endif
