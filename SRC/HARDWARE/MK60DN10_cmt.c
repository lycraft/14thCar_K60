/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2016,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		MK60DN10_cmt.c
* @brief      		CMT_PWM函数库
 * @company	   		成都逐飞科技有限公司
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
//  @brief      CMT_PWM初始化
//  @param      freq         设置PWM的频率
//  @param      duty         设置PWM的占空比
//  @return     void
//  @since      v1.0
//  Sample usage:               cmt_pwm_init(50,50);    // 频率50HZ，占空比为百分之（50/CMT_PRECISON *100）;
//------------------------------------------------------------------------------------------------------------------- 

void cmt_pwm_init(uint16 freq, uint16 duty)
{
    uint32 temp_clk;
    uint32 temp_high_num, temp_low_num;
    uint32 temp_div;
    //使能时钟
    SIM->SCGC4 |= SIM_SCGC4_CMT_MASK;
    //设置复用功能为CMT功能
//	SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
//	PORTD->PCR[GPIO_Pin_7] &= ~PORT_PCR_MUX_MASK;
//	PORTD->PCR[GPIO_Pin_7]|=0x02 << PORT_PCR_MUX_SHIFT;
//	PORTD->PCR[GPIO_Pin_7]|=0x03 << PORT_PCR_PS_SHIFT;
	SIM->SCGC5 |= (SIM_SCGC5_PORTA_MASK << 3);
    
    //清除中断标志位
    PORTD->ISFR = (uint32)1<<7;
    
    //设置复用功能为GPIO与配置端口功能
    PORTD->PCR[7] = (0x02 << PORT_PCR_MUX_SHIFT)|(0x03 << PORT_PCR_PS_SHIFT);
    
    //设置端口为输入
    PTD->PDDR &= ~(uint32)(1<<7);
    //使能输出
    CMT->OC |= CMT_OC_IROPEN_MASK;
    
    //由于CMT模块会固定八分频，因此这里计算，便于后面使用
    temp_clk = CPUInfo.BusClock/8;
    
    //计算最佳分频
    temp_div = temp_clk/freq;
    temp_div = temp_div>>16;
    if(temp_div>0x0f)   temp_div = 0x0f;
    
    //设置分频
    CMT->PPS = CMT_PPS_PPSDIV(temp_div);
    
    //计算一个周期需要计数的次数
    cmt_period = temp_clk/(temp_div+1)/freq;

    //计算高低电平的计数次数
    temp_low_num = (cmt_period*(CMT_PRECISON-duty)/CMT_PRECISON);
    temp_high_num = (cmt_period*(duty)/CMT_PRECISON);
    
    //设置低电平时间
    temp_low_num--;
    CMT->CMD1 = temp_low_num >> 8;
    CMT->CMD2 = (uint8)temp_low_num;
    
    //设置高电平时间
    CMT->CMD3 = temp_high_num >> 8;
    CMT->CMD4 = (uint8)temp_high_num;
    
    //设置模式且使能CMT模块    
    CMT->MSC = CMT_MSC_BASE_MASK | CMT_MSC_MCGEN_MASK;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      CMT_PWM占空比设置
//  @param      duty         设置PWM的占空比
//  @return     void
//  @since      v1.0
//  Sample usage:               cmt_pwm_duty(50);    //占空比为百分之（50/CMT_PRECISON *100）;
//-------------------------------------------------------------------------------------------------------------------
void cmt_pwm_duty(uint16 duty)
{
    
    uint32 temp_high_num, temp_low_num;

    //计算高低电平的计数次数
    temp_low_num = (cmt_period*(CMT_PRECISON-duty)/CMT_PRECISON);
    temp_high_num = (cmt_period*(duty)/CMT_PRECISON);
    
    //设置低电平时间
    temp_low_num--;
    CMT->CMD1 = temp_low_num >> 8;
    CMT->CMD2 = (uint8)temp_low_num;
    
    //设置高电平时间
    CMT->CMD3 = temp_high_num >> 8;
    CMT->CMD4 = (uint8)temp_high_num;

}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      CMT_PWM频率设置
//  @param      freq         设置PWM的频率
//  @param      duty         设置PWM的占空比
//  @return     void
//  @since      v1.0
//  Sample usage:               cmt_pwm_init(50,50);    // 频率50HZ，占空比为百分之（50/CMT_PRECISON *100）;
//-------------------------------------------------------------------------------------------------------------------
void cmt_pwm_freq(uint16 freq, uint16 duty)
{
    uint32 temp_clk;
    uint32 temp_high_num, temp_low_num;
    uint32 temp_div;

    
    //由于CMT模块会固定八分频，因此这里计算，便于后面使用
    temp_clk = CPUInfo.BusClock*1000*1000/8;
    
    //计算最佳分频
    temp_div = temp_clk/freq;
    temp_div = temp_div>>16;
    if(temp_div>0x0f)   temp_div = 0x0f;
    
    //设置分频
    CMT->PPS = CMT_PPS_PPSDIV(temp_div);

    
    //计算一个周期需要计数的次数
    cmt_period = temp_clk/(temp_div+1)/freq;
    
    //计算高低电平的计数次数
    temp_low_num = (cmt_period*(CMT_PRECISON-duty)/CMT_PRECISON);
    temp_high_num = (cmt_period*(duty)/CMT_PRECISON);
    
    //设置低电平时间
    temp_low_num--;
    CMT->CMD1 = temp_low_num >> 8;
    CMT->CMD2 = (uint8)temp_low_num;
    
    //设置高电平时间
    CMT->CMD3 = temp_high_num >> 8;
    CMT->CMD4 = (uint8)temp_high_num;
}















