/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: DAC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef DAC_CONFIG_H_
#define DAC_CONFIG_H_

/* Options: GPIO_PORTA
			GPIO_PORTB
			GPIO_PORTC
			GPIO_PORTD
*/
#define DAC_DATA_PORT       GPIO_PORTA
#define DAC_START_PIN       GPIO_PIN0


#define TICK_TIME       100

/*write the song array name and its array size*/
#define DAC_ARRAY_SIZE  DAC_Sound_raw_len
#define DAC_SONG_NAME   DAC_Sound_raw



#endif
