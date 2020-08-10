/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2016,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		MK60DN10_cmt.c
* @brief      		CMT_PWM������
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		Go For It(1325536866)
 * @version    		v1.0
 * @Software 		IAR 7.7 or MDK 5.17
 * @Target core		MK60DN512VLL10
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2016-02-25
 ********************************************************************************************************************/




#include "MK60DN10_cmt.h"
#include "gpio.h" 
vuint16 cmt_period;
     

//-------------------------------------------------------------------------------------------------------------------
//  @brief      CMT_PWM��ʼ��
//  @param      freq         ����PWM��Ƶ��
//  @param      duty         ����PWM��ռ�ձ�
//  @return     void
//  @since      v1.0
//  Sample usage:               cmt_pwm_init(50,50);    // Ƶ��50HZ��ռ�ձ�Ϊ�ٷ�֮��50/CMT_PRECISON *100��;
//------------------------------------------------------------------------------------------------------------------- 

void cmt_pwm_init(uint16 freq, uint16 duty)
{
    uint32 temp_clk;
    uint32 temp_high_num, temp_low_num;
    uint32 temp_div;
    //ʹ��ʱ��
    SIM->SCGC4 |= SIM_SCGC4_CMT_MASK;
    //���ø��ù���ΪCMT����
//	SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
//	PORTD->PCR[GPIO_Pin_7] &= ~PORT_PCR_MUX_MASK;
//	PORTD->PCR[GPIO_Pin_7]|=0x02 << PORT_PCR_MUX_SHIFT;
//	PORTD->PCR[GPIO_Pin_7]|=0x03 << PORT_PCR_PS_SHIFT;
	SIM->SCGC5 |= (SIM_SCGC5_PORTA_MASK << 3);
    
    //����жϱ�־λ
    PORTD->ISFR = (uint32)1<<7;
    
    //���ø��ù���ΪGPIO�����ö˿ڹ���
    PORTD->PCR[7] = (0x02 << PORT_PCR_MUX_SHIFT)|(0x03 << PORT_PCR_PS_SHIFT);
    
    //���ö˿�Ϊ����
    PTD->PDDR &= ~(uint32)(1<<7);
    //ʹ�����
    CMT->OC |= CMT_OC_IROPEN_MASK;
    
    //����CMTģ���̶��˷�Ƶ�����������㣬���ں���ʹ��
    temp_clk = CPUInfo.BusClock/8;
    
    //������ѷ�Ƶ
    temp_div = temp_clk/freq;
    temp_div = temp_div>>16;
    if(temp_div>0x0f)   temp_div = 0x0f;
    
    //���÷�Ƶ
    CMT->PPS = CMT_PPS_PPSDIV(temp_div);
    
    //����һ��������Ҫ�����Ĵ���
    cmt_period = temp_clk/(temp_div+1)/freq;

    //����ߵ͵�ƽ�ļ�������
    temp_low_num = (cmt_period*(CMT_PRECISON-duty)/CMT_PRECISON);
    temp_high_num = (cmt_period*(duty)/CMT_PRECISON);
    
    //���õ͵�ƽʱ��
    temp_low_num--;
    CMT->CMD1 = temp_low_num >> 8;
    CMT->CMD2 = (uint8)temp_low_num;
    
    //���øߵ�ƽʱ��
    CMT->CMD3 = temp_high_num >> 8;
    CMT->CMD4 = (uint8)temp_high_num;
    
    //����ģʽ��ʹ��CMTģ��    
    CMT->MSC = CMT_MSC_BASE_MASK | CMT_MSC_MCGEN_MASK;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      CMT_PWMռ�ձ�����
//  @param      duty         ����PWM��ռ�ձ�
//  @return     void
//  @since      v1.0
//  Sample usage:               cmt_pwm_duty(50);    //ռ�ձ�Ϊ�ٷ�֮��50/CMT_PRECISON *100��;
//-------------------------------------------------------------------------------------------------------------------
void cmt_pwm_duty(uint16 duty)
{
    
    uint32 temp_high_num, temp_low_num;

    //����ߵ͵�ƽ�ļ�������
    temp_low_num = (cmt_period*(CMT_PRECISON-duty)/CMT_PRECISON);
    temp_high_num = (cmt_period*(duty)/CMT_PRECISON);
    
    //���õ͵�ƽʱ��
    temp_low_num--;
    CMT->CMD1 = temp_low_num >> 8;
    CMT->CMD2 = (uint8)temp_low_num;
    
    //���øߵ�ƽʱ��
    CMT->CMD3 = temp_high_num >> 8;
    CMT->CMD4 = (uint8)temp_high_num;

}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      CMT_PWMƵ������
//  @param      freq         ����PWM��Ƶ��
//  @param      duty         ����PWM��ռ�ձ�
//  @return     void
//  @since      v1.0
//  Sample usage:               cmt_pwm_init(50,50);    // Ƶ��50HZ��ռ�ձ�Ϊ�ٷ�֮��50/CMT_PRECISON *100��;
//-------------------------------------------------------------------------------------------------------------------
void cmt_pwm_freq(uint16 freq, uint16 duty)
{
    uint32 temp_clk;
    uint32 temp_high_num, temp_low_num;
    uint32 temp_div;

    
    //����CMTģ���̶��˷�Ƶ�����������㣬���ں���ʹ��
    temp_clk = CPUInfo.BusClock*1000*1000/8;
    
    //������ѷ�Ƶ
    temp_div = temp_clk/freq;
    temp_div = temp_div>>16;
    if(temp_div>0x0f)   temp_div = 0x0f;
    
    //���÷�Ƶ
    CMT->PPS = CMT_PPS_PPSDIV(temp_div);

    
    //����һ��������Ҫ�����Ĵ���
    cmt_period = temp_clk/(temp_div+1)/freq;
    
    //����ߵ͵�ƽ�ļ�������
    temp_low_num = (cmt_period*(CMT_PRECISON-duty)/CMT_PRECISON);
    temp_high_num = (cmt_period*(duty)/CMT_PRECISON);
    
    //���õ͵�ƽʱ��
    temp_low_num--;
    CMT->CMD1 = temp_low_num >> 8;
    CMT->CMD2 = (uint8)temp_low_num;
    
    //���øߵ�ƽʱ��
    CMT->CMD3 = temp_high_num >> 8;
    CMT->CMD4 = (uint8)temp_high_num;
}















