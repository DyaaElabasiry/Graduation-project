/*************************************************************/
/************ Author  : Habeba Hamada             ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SPI                       ************/
/*************************************************************/


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPI1_BASE_ADDRESS       (u32)0x40013000
#define SPI2_BASE_ADDRESS       (u32)0x40003800
#define SPI3_BASE_ADDRESS       (u32)0x40003C00


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;


#define SPI1                    ((volatile SPI_t*)(SPI1_BASE_ADDRESS))
#define SPI2                    ((volatile SPI_t*)(SPI2_BASE_ADDRESS))
#define SPI3                    ((volatile SPI_t*)(SPI3_BASE_ADDRESS))

typedef enum
{
	CHPA,
	CPOL,
	MSTR,
	BR,
	SPE = 6,
	LSBFIRST,
	SSI,
	SSM,
	RXONLY,
	DFF,
	CRCNEXT,
	CRCEN,
	BIDIOE,
	BIDIMODE,
}SPI_CR1_t;


typedef enum
{
	RXDMAEN,
	TXDMAEN,
	SSOE,
	FRF = 4,
	ERRIE,
	RXNEIE,
	TXEIE,
}SPI_CR2_t;


typedef enum
{
	RXNE,
	TXE,
	CHSIDE,
	UDR,
	CRCERR,
	MODF,
	OVR,
	BSY,
	FRE,
}SPI_SR_t;

typedef enum
{
	CHLEN,
	DATLEN,
	CKPOL = 3,
	I2SSTD,
	PCMSYNC = 7,
	I2SCFG,
	I2SE = 10,
	I2SMOD,
}SPI_I2SCFGR_t;


typedef enum
{
	I2SDIV,
	ODD = 8,
	MCKOE,
}SPI_I2SPR_t;



#endif