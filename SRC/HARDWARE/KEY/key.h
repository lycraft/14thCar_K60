#ifndef _KEY_H_
#define _KEY_H_

#include "gpio.h"

#define LEFT_LIGHT_PORT PTD
#define LEFT_LIGHT_PIN  13

#define RIGHT_LIGHT_PORT PTD
#define RIGHT_LIGHT_PIN  14


#define MyKey1_Port PTC
#define MyKey2_Port PTC
#define MyKey3_Port PTC
#define MyKey4_Port PTC
#define MyKey5_Port PTC
#define MyKey6_Port PTC


#define MyKey1_Pin (GPIO_Pin_8)//����
#define MyKey2_Pin (GPIO_Pin_9)//��ҳ
#define MyKey3_Pin (GPIO_Pin_11)//��һ��
#define MyKey4_Pin (GPIO_Pin_10)//��ֵ
#define MyKey5_Pin (GPIO_Pin_12)//��ֵ
#define MyKey6_Pin (GPIO_Pin_13)//��һ��


#define MyKey1 (1)
#define MyKey2 (2)
#define MyKey3 (3)
#define MyKey4 (4)
#define MyKey5 (5)
#define MyKey6 (6)

#define		up			6
#define		DOWN		3
#define		LEFT		4
#define		RIGHT		5
#define		K1			2
#define		K2			1


#define GPIO_Key_Mode (0)//0Ϊ������1Ϊ����
#define delay_times 20//��ʱʱ��

//---------------------------�жϰ������--------------------------
#define Image_Mode_Key_Mode  GPIO_IT_RISING    //���ô�����ʽ

#define Key_Real_Port   MyKey1_Port  //ԭͼģʽ
#define Key_Fit_Port    MyKey2_Port  //��ͼģʽ
#define Key_Par_Port    MyKey3_Port  //����ģʽ
#define Key_Play_Port   MyKey4_Port  //����/��ͣ
#define Key_Up_Port     MyKey5_Port  //���Ϸ�
#define Key_Down_Port   MyKey6_Port  //���·�

#define Key_Real_Pin    MyKey1_Pin   //ԭͼģʽ
#define Key_Fit_Pin     MyKey2_Pin   //��ͼģʽ
#define Key_Par_Pin     MyKey3_Pin   //����ģʽ
#define Key_Play_Pin    MyKey4_Pin   //����/��ͣ
#define Key_Up_Pin      MyKey5_Pin   //���Ϸ�
#define Key_Down_Pin    MyKey6_Pin   //���·�

#define ON   1 //���ش�
#define OFF  0 //���عر�





void MyKey_Init(void);
char KeyScan(void);
void IT_Image_Mode_Key(void);//ģʽ�л��жϰ���
void KeyItScan(void);//�жϼ�ⰴ��
uint8_t get_Image_Mode_Key(void);//��ȡ�����Ƿ���
void IT_KeyScan(void);




#endif

