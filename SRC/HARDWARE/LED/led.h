/**
  ******************************************************************************
  * @file    led.h
  * @author  YANDLD
  * @version V2.4
  * @date    2013.5.23
  * @brief   ����ԭ�Ӻ˺��İ� BSP���� LED����
  ******************************************************************************
  */
#ifndef __LED_H__
#define __LED_H__

#include "gpio.h"

#ifdef __cplusplus
 extern "C" {
#endif

//LEDͷ�ļ�
//IO ��
#define LED1_PORT PTE  //���
//#define LED2_PORT PTD
//#define LED3_PORT PTD  //�ұ�
//#define LED4_PORT PTD
//����
#define LED1_PIN  (12) //���
//#define LED2_PIN  (13)
//#define LED3_PIN  (10) //�ұ�
//#define LED4_PIN  (11)

//��������ʵ�ֵĺ����ӿ��б�
void LED_Init(void);
void BBB(int flag);
#ifdef __cplusplus
}
#endif

#endif
