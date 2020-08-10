#ifndef __DATA_SD_H__
#define __DATA_SD_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "sd.h"



#define ON 1
#define OFF 0	 

//SD����������������
#define SD_PortType PORTE
	 
#define  D1   GPIO_Pin_0
#define  D0   GPIO_Pin_1 
#define  CLK  GPIO_Pin_2
#define  CMD  GPIO_Pin_3
#define  D3   GPIO_Pin_4
#define  D2   GPIO_Pin_5

//SD�������
#define SD_WR_BaudRate  5000000 // ����SD�Ķ�д������  1ǧ�� ��߲�����2.5ǧ��
#define SD_Block_Size     512    //SD�����С��λbyte
#define SD_WT_BlocksNum ((Data_All_Length+SD_Block_Size-1)/SD_Block_Size)
                          //һ��д�����ݿ������ ����Ҫ14500������������

#define Key_Delay_Count      3  //�жϰ�����ʱ���� �жϰ������ȶ�
#define Image_SD_Speed       35 //��ȡSD���ٶ� ��λ ��/ÿ��
#define CarDataNum 14		//С��Ҫ��������ݸ���


	
void Data_SD_WT_Init(void);//д�����ʼ��
uint8_t Data_SD_Init(void);//SD����ʼ��
void Data_SD_WriteMultiBlock(const uint8_t *pbuffer,uint16_t Count);//���д
void Data_SD_ReadSingleBlock(uint32_t sector, uint8_t *buffer,uint16_t Count);//�����
void Data_Read_Init(void);//��SD����ʼ��
void Data_SD_Save(void);//SD���洢��Ϣ
void Uart_Read_SD(void);//��ȡSD����Ϣ
void Data_Read(void);//��ȡ���ݵ�Data����
void OLED_Read_SD(void);

#ifdef __cplusplus
}
#endif

#endif

