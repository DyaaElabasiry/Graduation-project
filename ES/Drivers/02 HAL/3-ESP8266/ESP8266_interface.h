/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: ESP8266       ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/



#ifndef _ESP8266_INTERFACE_H_
#define _ESP8266_INTERFACE_H_





void ESP_voidInit(void);
void ESP_voidConnectToWIFI();
void ESP_u8ConnectToSite(u8* Ptr_u8Data);
void ESP_u8Send(u8* Ptr_u8IP, u8* Ptr_u8Data);




#endif
