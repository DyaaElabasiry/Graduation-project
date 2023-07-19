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
 * 		1 --> STATION_MODE           *
 * 		2 --> SOFTAP_MODE            *
 * 		3 --> BOTH_MODES             *
 ************************************/
#define ESP_WIFI_MODE         STATION_MODE

/*****************************************
 *  USART Connected to ESP                *
 * Options:                               *
 * 		1 --> USART1                      *
 * 		2 --> USART2                      *
 * 		3 --> USART6                      *
 ******************************************/
#define ESP_USART            USART1

/**************************************
  Write the Router ID and Password
 **************************************/
#define ESP_WIFI_ID           "Faida"
#define ESP_WIFI_PASSWORD     "h8a2b2e0b0a0"

/**************************************
  Write the Server IP
 **************************************/
#define ESP_SERVER_IP           "172.107.162.12"


/************************************
 * Choose Connection Type           *
 * Options:                         *
 * 		1 --> "TCP"                 *
 * 		2 --> "UDP"                 *
 ************************************/
#define ESP_CONNECTION_TYPE        "TCP"

/***************************************
 * write server port
 * note :all http servers has the same port number 80
 * ************************************/
#define ESP_PORT_NUMBER            80

/*************************************************************
 * Write the data length and the HTTP Command   *
 *************************************************************/
#define ESP_Data_Length        48
#define ESP_HTTP_COMMAND      "GET http://habebahamada.freevar.com/status.txt\r\n"



#endif
