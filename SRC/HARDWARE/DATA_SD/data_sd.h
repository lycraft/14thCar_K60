#ifndef __DATA_SD_H__
#define __DATA_SD_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "sd.h"



#define ON 1
#define OFF 0	 

//SD卡控制器引脚类型
#define SD_PortType PORTE
	 
#define  D1   GPIO_Pin_0
#define  D0   GPIO_Pin_1 
#define  CLK  GPIO_Pin_2
#define  CMD  GPIO_Pin_3
#define  D3   GPIO_Pin_4
#define  D2   GPIO_Pin_5

//SD卡块参数
#define SD_WR_BaudRate  5000000 // 设置SD的读写波特率  1千万 最高不超过2.5千万
#define SD_Block_Size     512    //SD卡块大小单位byte
#define SD_WT_BlocksNum ((Data_All_Length+SD_Block_Size-1)/SD_Block_Size)
                          //一次写入数据块的数量 按需要14500个数据来计算

#define Key_Delay_Count      3  //中断按键延时次数 中断按键不稳定
#define Image_SD_Speed       35 //读取SD卡速度 单位 场/每秒
#define CarDataNum 14		//小车要储存的数据个数


	
void Data_SD_WT_Init(void);//写命令初始化
uint8_t Data_SD_Init(void);//SD卡初始化
void Data_SD_WriteMultiBlock(const uint8_t *pbuffer,uint16_t Count);//多块写
void Data_SD_ReadSingleBlock(uint32_t sector, uint8_t *buffer,uint16_t Count);//单块读
void Data_Read_Init(void);//读SD卡初始化
void Data_SD_Save(void);//SD卡存储信息
void Uart_Read_SD(void);//读取SD卡信息
void Data_Read(void);//读取数据到Data数组
void OLED_Read_SD(void);

#ifdef __cplusplus
}
#endif

#endif

