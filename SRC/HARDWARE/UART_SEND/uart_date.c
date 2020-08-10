
#include "sys.h"
#include "uart_date.h"
#include "dma.h"
#include "uart.h"

#define  Image_Width              200
#define  Image_Height             70
/**************************** DATE_SNED ***********************************/
extern uint8_t Pixels[Image_Width*Image_Height]; 
extern uint8_t*P;
extern  uint16_t  h;



void UART_DMA_Init(void)
{
	DMA_InitTypeDef DMA_InitStruct1;
	
	UART_DebugPortInit(UART5_RX_E9_TX_E8, 115200);
	UART_ITConfig(UART5,UART_IT_TDRE,ENABLE);
	UART_DMACmd(UART5,UART_DMAReq_Tx,ENABLE);
	
	
	DMA_InitStruct1.Channelx = DMA_CH3;
	DMA_InitStruct1.DMAAutoClose = ENABLE;
	DMA_InitStruct1.EnableState = DISABLE;
	DMA_InitStruct1.MinorLoopLength = sizeof(Pixels);
	DMA_InitStruct1.PeripheralDMAReq = UART5_TRAN_DMAREQ;
	DMA_InitStruct1.TransferBytes = 1;
	
	DMA_InitStruct1.DestBaseAddr = (uint32_t)&(UART5->D);
	DMA_InitStruct1.DestDataSize = DMA_DST_8BIT;
	DMA_InitStruct1.DestMajorInc = 0;
	DMA_InitStruct1.DestMinorInc = 0;
	
	DMA_InitStruct1.SourceBaseAddr = (uint32_t)Pixels;
	DMA_InitStruct1.SourceDataSize = DMA_SRC_8BIT;
	DMA_InitStruct1.SourceMajorInc = 0;
	DMA_InitStruct1.SourceMinorInc = 1;
	
	DMA_Init(&DMA_InitStruct1);
	NVIC_EnableIRQ(DMA3_IRQn); 
	DMA_ITConfig(DMA0, DMA_IT_MAJOR, DMA_CH3,ENABLE);
}

void UART_DMA_Open(void)
{
	DMA_SetEnableReq(DMA_CH3,ENABLE);
}
