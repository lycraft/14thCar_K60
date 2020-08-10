/**
  ******************************************************************************
  * @file    led.c
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   超核原子核核心板 BSP构件 LED驱动
  ******************************************************************************
  */
#include "led.h"

/***********************************************************************************************
 功能：LED初始化
 形参：0
 返回：0
 详解：初始化板子上的LED 调用GPIO构件
************************************************************************************************/
void LED_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStruct1;
	
	GPIO_InitStruct1.GPIO_Pin = LED1_PIN;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_OPP;
	GPIO_InitStruct1.GPIOx = LED1_PORT;
	GPIO_Init(&GPIO_InitStruct1);
	PORTE->PCR[GPIO_Pin_12]|=0x01 << PORT_PCR_MUX_SHIFT;
	
	
	GPIO_InitStruct1.GPIO_Pin = 12;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct1.GPIOx = PTD;
	GPIO_Init(&GPIO_InitStruct1);
//	PORTD->PCR[GPIO_Pin_12]|=0x01 << PORT_PCR_MUX_SHIFT;
	
	
	
	GPIO_InitStruct1.GPIO_Pin = 13;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct1.GPIOx = PTD;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIO_Pin = 5;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct1.GPIOx = PTD;
	GPIO_Init(&GPIO_InitStruct1);
//	PORTD->PCR[GPIO_Pin_13]|=0x01 << PORT_PCR_MUX_SHIFT;
//	GPIO_InitStruct1.GPIO_Pin = LED2_PIN;
//	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
//	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
//	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
//	GPIO_InitStruct1.GPIOx = LED2_PORT;
//	GPIO_Init(&GPIO_InitStruct1);
//	
//	GPIO_InitStruct1.GPIO_Pin = LED3_PIN;
//	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
//	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
//	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
//	GPIO_InitStruct1.GPIOx = LED3_PORT;
//	GPIO_Init(&GPIO_InitStruct1);
//	
//	GPIO_InitStruct1.GPIO_Pin = LED4_PIN;
//	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
//	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
//	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;
//	GPIO_InitStruct1.GPIOx = LED4_PORT;
//	GPIO_Init(&GPIO_InitStruct1);
}
void BBB(int flag) //1B 0不B
{
	if(flag)
	{
		GPIO_SetBits(LED1_PORT, LED1_PIN);
	}
	else
	{
		GPIO_ResetBits(LED1_PORT, LED1_PIN);
	}
}
