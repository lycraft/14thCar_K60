/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2016,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		MK60DN10_cmt.h
* @brief      		CMT_PWM������
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		Go For It(1325536866)
 * @version    		v1.0
 * @Software 		IAR 7.7 or MDK 5.17
 * @Target core		MK60DN512VLL10
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2016-02-25
 ********************************************************************************************************************/




#ifndef _MK60DN10_cmt_h
#define _MK60DN10_cmt_h


#include "common.h"





#define CMT_PRECISON 10000u     //����ռ�ձȾ��ȣ���˼��ʹ��һ�����ڷֳɶ��ٷ֣��ֶ�Խ����������Խ�ߣ�����ռ�ձȵ�ʱ��duty�ķ�Χ����0-FTM0_PRECISON  ���ֻ������Ϊ65535


void cmt_pwm_init(uint16 period, uint16 duty);
void cmt_pwm_duty(uint16 duty);
void cmt_pwm_freq(uint16 freq, uint16 duty);

#endif
