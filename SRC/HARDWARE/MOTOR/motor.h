#ifndef __MOTOR_H
#define __MOTOR_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "sys.h"
#include "ftm.h"
	 
	 
typedef struct 
{
  uint16_t kp;     //����ϵ��
  uint16_t kd;     //΢��ϵ��
  uint16_t ki;
	
	float setPoint;//�趨��
  float errNow; //��ǰ�����
  float ctrOut;//�����������
 /*PID�㷨�ڲ���������ֵ�����޸�*/
  float errOld1;
}PID_Speed;
	 

//���Ƶ�ʺ궨��
#define MotorFrequency 10000 //10KHz
//���FTM���ź궨��
#define MotorAZ FTM2_CH0_PA10//FTM1_CH0_PA8 //GPIO_Pin_8	//���A��������
#define MotorAF FTM2_CH1_PA11//FTM0_CH3_PA6 //GPIO_Pin_6	//���A��������
#define MotorBZ FTM1_CH1_PA9//FTM1_CH1_PA9 //GPIO_Pin_9  //���B��������
#define MotorBF FTM1_CH0_PA8//FTM0_CH4_PA7 //GPIO_Pin_7  //���B��������


//������AB�˿ڼ����ź궨��
#define EncoderA    PTB
#define EncoderAI   GPIO_Pin_20	 
#define EncoderB    PTC
#define EncoderBI   GPIO_Pin_6	
//������AB����˿����ź궨��
#define EncoderA_DirPORT      PTB
#define EncoderA_DirPin       GPIO_Pin_21
#define EncoderB_DirPORT      PTB
#define EncoderB_DirPin       GPIO_Pin_22
//������AB��DMA����ѡ�񴥷�Դ�궨��	 
#define EncoderA_DMAREQ PORTB_DMAREQ
#define EncoderB_DMAREQ PORTC_DMAREQ
//������AB��DMA����ͨ���궨��
#define EncoderA_DMA_CH DMA_CH1
#define EncoderB_DMA_CH DMA_CH2
//DMA�����������䳤��
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
