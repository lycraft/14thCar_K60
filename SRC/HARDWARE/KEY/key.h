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


#define MyKey1_Pin (GPIO_Pin_8)//启动
#define MyKey2_Pin (GPIO_Pin_9)//翻页
#define MyKey3_Pin (GPIO_Pin_11)//下一行
#define MyKey4_Pin (GPIO_Pin_10)//增值
#define MyKey5_Pin (GPIO_Pin_12)//减值
#define MyKey6_Pin (GPIO_Pin_13)//上一行


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


#define GPIO_Key_Mode (0)//0为上拉，1为下拉
#define delay_times 20//延时时间

//---------------------------中断按键设计--------------------------
#define Image_Mode_Key_Mode  GPIO_IT_RISING    //设置触发方式

#define Key_Real_Port   MyKey1_Port  //原图模式
#define Key_Fit_Port    MyKey2_Port  //拟图模式
#define Key_Par_Port    MyKey3_Port  //参数模式
#define Key_Play_Port   MyKey4_Port  //播放/暂停
#define Key_Up_Port     MyKey5_Port  //向上翻
#define Key_Down_Port   MyKey6_Port  //向下翻

#define Key_Real_Pin    MyKey1_Pin   //原图模式
#define Key_Fit_Pin     MyKey2_Pin   //拟图模式
#define Key_Par_Pin     MyKey3_Pin   //参数模式
#define Key_Play_Pin    MyKey4_Pin   //播放/暂停
#define Key_Up_Pin      MyKey5_Pin   //向上翻
#define Key_Down_Pin    MyKey6_Pin   //向下翻

#define ON   1 //开关打开
#define OFF  0 //开关关闭





void MyKey_Init(void);
char KeyScan(void);
void IT_Image_Mode_Key(void);//模式切换中断按键
void KeyItScan(void);//中断检测按键
uint8_t get_Image_Mode_Key(void);//获取按键是否按下
void IT_KeyScan(void);




#endif

