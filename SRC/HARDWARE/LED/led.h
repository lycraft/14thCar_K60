/**
  ******************************************************************************
  * @file    led.h
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   超核原子核核心板 BSP构件 LED驱动
  ******************************************************************************
  */
#ifndef __LED_H__
#define __LED_H__

#include "gpio.h"

#ifdef __cplusplus
 extern "C" {
#endif

//LED头文件
//IO 口
#define LED1_PORT PTE  //左边
//#define LED2_PORT PTD
//#define LED3_PORT PTD  //右边
//#define LED4_PORT PTD
//引脚
#define LED1_PIN  (12) //左边
//#define LED2_PIN  (13)
//#define LED3_PIN  (10) //右边
//#define LED4_PIN  (11)

//本构件所实现的函数接口列表
void LED_Init(void);
void BBB(int flag);
#ifdef __cplusplus
}
#endif

#endif
