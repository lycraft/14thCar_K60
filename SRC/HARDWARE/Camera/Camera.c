#include "sys.h"
#include "dma.h"
#include "Camera.h"


extern uint8_t   data [DMA_CAMERA_Length];

void Camera_Init(void)
{
	  DMA_InitTypeDef DMA_InitStruct1;
	  GPIO_InitTypeDef GPIO_InitStruct1;
	
	  GPIO_InitStruct1.GPIOx = Field_IT_GPIOx;         
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_FALLING;  
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = Field_IT_Pin;
    GPIO_Init(&GPIO_InitStruct1);
	

    		
	  GPIO_InitStruct1.GPIOx = Pclk_IT_GPIOx;           
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DMA_FALLING;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = Pclk_IT_Pin;
		GPIO_Init(&GPIO_InitStruct1);
		
		GPIO_InitStruct1.GPIOx = Pixels_GPIOx;           
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = Pixels_Pin;
		GPIO_Init(&GPIO_InitStruct1);
		
		GPIO_InitStruct1.GPIOx = Pixels_GPIOx;            //像素
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_0;
		GPIO_Init(&GPIO_InitStruct1);
			
    GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_1;
		GPIO_Init(&GPIO_InitStruct1);

		GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_2;
		GPIO_Init(&GPIO_InitStruct1);
               
    GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_3;
		GPIO_Init(&GPIO_InitStruct1);
             
    GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_4;
		GPIO_Init(&GPIO_InitStruct1);
                
    GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_5;
		GPIO_Init(&GPIO_InitStruct1);
               
    GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_6;
		GPIO_Init(&GPIO_InitStruct1);
                
    GPIO_InitStruct1.GPIOx = Pixels_GPIOx;
		GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
		GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;										
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;     
		GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_7;
		GPIO_Init(&GPIO_InitStruct1); 
		
		DMA_InitStruct1.Channelx = DMA_CH0;                         //使用DMA0通道  (0-15)
	DMA_InitStruct1.DMAAutoClose = ENABLE;                      //传输完毕后自动关闭
	DMA_InitStruct1.EnableState = ENABLE;                       //初始化后立即开始传输
	DMA_InitStruct1.MinorLoopLength =DMA_CAMERA_Length ;   //传输次数
	DMA_InitStruct1.PeripheralDMAReq  = PORTA_DMAREQ ;      
	DMA_InitStruct1.TransferBytes = 1;                          //每次传输一个字节
	//配置目的地址传输参数
	DMA_InitStruct1.DestBaseAddr = (uint32_t)&data;       //指向目的地址
	DMA_InitStruct1.DestDataSize = DMA_DST_8BIT;                //数组为1Byte
	DMA_InitStruct1.DestMajorInc = 0;                           //执行一次大循环后 地址不增加
	DMA_InitStruct1.DestMinorInc = 1;                           //每次传输完地址增加1
 
	//配置源地址传输参数
	DMA_InitStruct1.SourceBaseAddr = (uint32_t)&PTB->PDIR;
	DMA_InitStruct1.SourceDataSize = DMA_SRC_8BIT;
	DMA_InitStruct1.SourceMajorInc = 0;
	DMA_InitStruct1.SourceMinorInc = 0;
	DMA_Init(&DMA_InitStruct1);
	
	
	DMA_ITConfig(DMA0, DMA_IT_MAJOR, DMA_CH0,ENABLE); //开启传输完成中断
	NVIC_EnableIRQ(DMA0_IRQn);
	

}


