#ifndef __DMACNT_H__
#define __DMACNT_H__


#include "dma.h"
#include "gpio.h"
#endif /* __DMACNT_H__ */

#define DMACNT_MODE_RISING    (uint8_t)(0)    //�����ش���
#define DMACNT_MODE_FALLING   (uint8_t)(1)    //�½��ش���

typedef struct
{
	uint8_t DMA_Chl;              //ͨ����
	GPIO_Type *GPIOx;             //GPIO�˿ں�
	uint8_t GPIO_Pin;             // ���ź�
  uint8_t DMACNT_Mode;	        //����ģʽ
}DMACNT_InitTypeDef;

//������ʵ�ֵĽӿں����б�
void DMACNT_Init(DMACNT_InitTypeDef* DMACNT_InitStruct);
uint16_t DMACNT_GetValue(uint8_t DMA_Chl);




