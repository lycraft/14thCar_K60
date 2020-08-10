#ifndef __MOTOR_H
#define __MOTOR_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "sys.h"
#include "ftm.h"
	 
	 
typedef struct 
{
  uint16_t kp;     //比例系数
  uint16_t kd;     //微分系数
  uint16_t ki;
	
	float setPoint;//设定量
  float errNow; //当前的误差
  float ctrOut;//控制总量输出
 /*PID算法内部变量，其值不能修改*/
  float errOld1;
}PID_Speed;
	 

//电机频率宏定义
#define MotorFrequency 10000 //10KHz
//电机FTM引脚宏定义
#define MotorAZ FTM2_CH0_PA10//FTM1_CH0_PA8 //GPIO_Pin_8	//电机A驱动正向
#define MotorAF FTM2_CH1_PA11//FTM0_CH3_PA6 //GPIO_Pin_6	//电机A驱动负向
#define MotorBZ FTM1_CH1_PA9//FTM1_CH1_PA9 //GPIO_Pin_9  //电机B驱动正向
#define MotorBF FTM1_CH0_PA8//FTM0_CH4_PA7 //GPIO_Pin_7  //电机B驱动负向


//编码器AB端口及引脚宏定义
#define EncoderA    PTB
#define EncoderAI   GPIO_Pin_20	 
#define EncoderB    PTC
#define EncoderBI   GPIO_Pin_6	
//编码器AB方向端口引脚宏定义
#define EncoderA_DirPORT      PTB
#define EncoderA_DirPin       GPIO_Pin_21
#define EncoderB_DirPORT      PTB
#define EncoderB_DirPin       GPIO_Pin_22
//编码器AB的DMA计数选择触发源宏定义	 
#define EncoderA_DMAREQ PORTB_DMAREQ
#define EncoderB_DMAREQ PORTC_DMAREQ
//编码器AB的DMA计数通道宏定义
#define EncoderA_DMA_CH DMA_CH1
#define EncoderB_DMA_CH DMA_CH2
//DMA脉冲计数最大传输长度
#define TransferLength 30000
	 
void Motor_Init(void);
void Encoder_Init(void);
void Time_Init(void);
uint16_t Get_EncoderA_PulseCount(void);
uint16_t Get_EncoderB_PulseCount(void);
void MotorSpeedChange(uint16_t SetPointA,uint16_t SetPointB);
uint16_t Get_EncoderA_Dir(void);
uint16_t Get_EncoderB_Dir(void);
void PID_LeftSpeed_Init(float P,float I,float D,float setPoint);
void PID_RightSpeed_Init(float P,float I,float D,float setPoint);
void Right_SpeedControl(int32_t Rightin);
void Left_SpeedControl(int32_t leftin);
void Get_MotorSpeed(void);
int32_t Diff_Speed_Duoji(float err);
//int16_t get_diff(int16_t err_in);
int get_diff(float err_in);
void speed_ctrl(int16_t speed_real);
int Kalman_left(int data);
int Kalman_right(int data);
 int dongtai_P(int a);
#ifdef __cplusplus
}
#endif
	 
#endif
