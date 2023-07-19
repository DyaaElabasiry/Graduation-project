/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: DAC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef DAC_PRIVATE_H_
#define DAC_PRIVATE_H_

u8*PTR_TO_FUNC=DAC_SONG_NAME;

/*
 * NAME:DAC_voidSendAudio
 * RETURN TYPE: void
 * ARGUMENTS: void
 * DESCRIPTION: SEND Audio
 */
void DAC_voidSendAudio()
{
	static u16 x = 0;
	GPIO_voidSetGroupChannel(DAC_DATA_PORT, DAC_START_PIN, 8, PTR_TO_FUNC[x++]);

	if(x == DAC_ARRAY_SIZE) x = 0;

}


#endif
