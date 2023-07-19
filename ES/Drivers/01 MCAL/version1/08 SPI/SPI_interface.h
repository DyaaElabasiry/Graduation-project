/*************************************************************/
/************ Author  : Habeba Hamada             ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SPI                       ************/
/*************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



/* Clock Phase Options */
#define SPI_CLKPH_LEADING_EDGE          0
#define SPI_CLKPH_TRAILING_EDGE         1


/* Clock Polarity Options */
#define SPI_CLKPOL_IDLE_LOW             0
#define SPI_CLKPOL_IDLE_HIGH            1


/* Clock Rate Options */
typedef enum
{
	SPI_Clock_Rate_Div2,
	SPI_Clock_Rate_Div4,
	SPI_Clock_Rate_Div8,
	SPI_Clock_Rate_Div16,
	SPI_Clock_Rate_Div32,
	SPI_Clock_Rate_Div64,
	SPI_Clock_Rate_Div128,
	SPI_Clock_Rate_Div256,
}SPI_Baud_Rate;


/* Data Order Options */
#define SPI_MSB_FIRST                   0
#define SPI_LSB_FIRST                   1

/*typedef struct
{

	SPI_t*           SPI_NUM;
	u8              SPI_Mode;
	u8              ClkPolarity;
	u8              ClkPhase;
	u8              DataOrder;
	SPI_Baud_Rate    ClockRate;

}SPI_str;
*/
/************************************************
 * Name        : SPI1_voidMasterInit            *
 * Return type : void                           *
 * Arguments   : Copy_u8DataOrder --> u8        *
 *               Copy_u8ClockPolatrity --> u8   *
 *               Copy_u8ClockPhase --> u8       *
 *               Copy_u8ClockRate --> u8        *
 * description : initialization of MC as master *
 ************************************************/
void SPI1_voidMasterInit(u8 Copy_u8DataOrder, u8 Copy_u8ClockPolatrity, u8 Copy_u8ClockPhase, u8 Copy_u8ClockRate);


/***********************************************
 * Name        : SPI1_voidSlaveInit            *
 * Return type : void                          *
 * Arguments   : Copy_u8DataOrder --> u8       *
 *               Copy_u8ClockPolatrity --> u8  *
 *               Copy_u8ClockPhase --> u8      *
 * description : initialization of MC as slave *
 ***********************************************/
void SPI1_voidSlaveInit(u8 Copy_u8DataOrder, u8 Copy_u8ClockPolatrity, u8 Copy_u8ClockPhase);


/********************************************
 * Name        : SPI1_u8SynchTransceive     *
 * Return type : u8                         *
 * Arguments   : Copy_u8Data --> u8         *
 * description : sends and receives data    *
 *******************************************/
u8 SPI1_u8SynchTransceive(u8 Copy_u8Data);

/************************************************
 * Name        : SPI2_voidMasterInit            *
 * Return type : void                           *
 * Arguments   : Copy_u8DataOrder --> u8        *
 *               Copy_u8ClockPolatrity --> u8   *
 *               Copy_u8ClockPhase --> u8       *
 *               Copy_u8ClockRate --> u8        *
 * description : initialization of MC as master *
 ************************************************/
void SPI2_voidMasterInit(u8 Copy_u8DataOrder, u8 Copy_u8ClockPolatrity, u8 Copy_u8ClockPhase, u8 Copy_u8ClockRate);


/********************************************
 * Name        : SPI2_u8SynchTransceive     *
 * Return type : u8                         *
 * Arguments   : Copy_u8Data --> u8         *
 * description : sends and receives data    *
 *******************************************/
u8 SPI2_u8SynchTransceive(u8 Copy_u8Data);


#endif 
