/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: DMA           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA1_BASE_ADD                (u32)(0x40026000)
#define DMA2_BASE_ADD                (u32)(0x40026400)


typedef struct
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_Stream_t;

typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	DMA_Stream_t Stream[8];
}DMA_t


#define DMA1                        ((volatile DMA_t*)(DMA1_BASE_ADD))
#define DMA2                        ((volatile DMA_t*)(DMA2_BASE_ADD))

typedef enum
{   EN,
	DMEIE,
	TEIE,
	HTIE,
	TCIE,
	PFCTRL,
	DIR,
	CIRC = 8,
	PINC,
	MINC,
	PSIZE,
	MSIZE = 13,
	PINCOS = 15,
	PL,
	DBM = 18,
	CT,
	PBURST = 21,
	MBUSRT = 23,
	CHSEL = 25,
}DMA_CR_t;


typedef enum
{
	FTH,
	DMDIS = 2,
	FS,
	FEIE = 7,
}DMA_FCR_t;


#define DMA_LISR_FEIF0                  0
#define DMA_LISR_FEIF1                  6
#define DMA_LISR_FEIF2                  16
#define DMA_LISR_FEIF3                  22
#define DMA_LISR_DMEIF0                 2
#define DMA_LISR_DMEIF1                 8
#define DMA_LISR_DMEIF2                 18
#define DMA_LISR_DMEIF3                 24
#define DMA_LISR_TEIF0                  3
#define DMA_LISR_TEIF1                  9
#define DMA_LISR_TEIF2                  19
#define DMA_LISR_TEIF3                  25
#define DMA_LISR_HTIF0                  4
#define DMA_LISR_HTIF1                  10
#define DMA_LISR_HTIF2                  20
#define DMA_LISR_HTIF3                  26
#define DMA_LISR_TCIF0                  5
#define DMA_LISR_TCIF1                  11
#define DMA_LISR_TCIF2                  21
#define DMA_LISR_TCIF3                  27

#define DMA_HISR_FEIF4                  0
#define DMA_HISR_FEIF5                  6
#define DMA_HISR_FEIF6                  16
#define DMA_HISR_FEIF7                  22
#define DMA_HISR_DMEIF4                 2
#define DMA_HISR_DMEIF5                 8
#define DMA_HISR_DMEIF6                 18
#define DMA_HISR_DMEIF7                 24
#define DMA_HISR_TEIF4                  3
#define DMA_HISR_TEIF5                  9
#define DMA_HISR_TEIF6                  19
#define DMA_HISR_TEIF7                  25
#define DMA_HISR_HTIF4                  4
#define DMA_HISR_HTIF5                  10
#define DMA_HISR_HTIF6                  20
#define DMA_HISR_HTIF7                  26
#define DMA_HISR_TCIF4                  5
#define DMA_HISR_TCIF5                  11
#define DMA_HISR_TCIF6                  21
#define DMA_HISR_TCIF7                  27


#define DMA_LISR_CFEIF0                  0
#define DMA_LISR_CFEIF1                  6
#define DMA_LISR_CFEIF2                  16
#define DMA_LISR_CFEIF3                  22
#define DMA_LISR_CDMEIF0                 2
#define DMA_LISR_CDMEIF1                 8
#define DMA_LISR_CDMEIF2                 18
#define DMA_LISR_CDMEIF3                 24
#define DMA_LISR_CTEIF0                  3
#define DMA_LISR_CTEIF1                  9
#define DMA_LISR_CTEIF2                  19
#define DMA_LISR_CTEIF3                  25
#define DMA_LISR_CHTIF0                  4
#define DMA_LISR_CHTIF1                  10
#define DMA_LISR_CHTIF2                  20
#define DMA_LISR_CHTIF3                  26
#define DMA_LISR_CTCIF0                  5
#define DMA_LISR_CTCIF1                  11
#define DMA_LISR_CTCIF2                  21
#define DMA_LISR_CTCIF3                  27

#define DMA_HISR_CFEIF4                  0
#define DMA_HISR_CFEIF5                  6
#define DMA_HISR_CFEIF6                  16
#define DMA_HISR_CFEIF7                  22
#define DMA_HISR_CDMEIF4                 2
#define DMA_HISR_CDMEIF5                 8
#define DMA_HISR_CDMEIF6                 18
#define DMA_HISR_CDMEIF7                 24
#define DMA_HISR_CTEIF4                  3
#define DMA_HISR_CTEIF5                  9
#define DMA_HISR_CTEIF6                  19
#define DMA_HISR_CTEIF7                  25
#define DMA_HISR_CHTIF4                  4
#define DMA_HISR_CHTIF5                  10
#define DMA_HISR_CHTIF6                  20
#define DMA_HISR_CHTIF7                  26
#define DMA_HISR_CTCIF4                  5
#define DMA_HISR_CTCIF5                  11
#define DMA_HISR_CTCIF6                  21
#define DMA_HISR_CTCIF7                  27





/********************************************************************************************/

#define STREAM_Disable         0
#define STREAM_Enable          1

#define INTERRUPT_Disable         0
#define INTERRUPT_Enable          1

#define DMA_FLOW_CONTROLLER               0
#define PERIPHERAL_FLOW_CONTROLLER        1

#define PERIPHERAL_TO_MEMORY         0b00
#define MEMORY_TO_PERIPHERAL         0b01
#define MEMORY_TO_MEMORY             0b10

#define CIRCULAR_MODE_DISABLED       0
#define CIRCULAR_MODE_ENABLED        1

#endif



