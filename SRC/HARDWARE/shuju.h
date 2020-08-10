#ifndef __SHUJU_H
#define __SHUJU_H
#include "common.h"
#include "image_processe.h"
#include "extern.h"
#include "motor.h"
#include "math.h"
extern uint8 huan;
extern uint8 zhang;

extern uint8 DMA_Temp;
extern uint8 DuanLu1;
extern uint8 DuanLu2;
extern double left_wdata;
extern double left_ldata;
extern double ADC_ceju;
extern double right_wdata;
extern double right_ldata;
extern int Left_Line[63], Right_Line[63];
extern uchar Mid_Line[63];	//�����ұ߽���
extern uint8 point;
extern int32 speed; 
extern uint8 run;
extern int8_t tiaozheng;
extern float turn;
extern float turn1;
extern uint8 dahuan;
extern uint8 chuhuan;
extern uint8 panhuan;
extern uint8 chuhuankou;
extern float  turn_angle;
extern float  turn_angle1;
extern uint8 bianxing;
extern uint8 bushi;
  extern  uint8_t zhangai;
   extern  uint8_t duanlu;
      extern  uint8_t duanyu;
 extern uint8_t zhangai_shu;
extern int32_t speed_dir_left;
extern int32_t speed_dir_right;
 extern uint8_t gray;
 extern uint8 zhidao;
extern int16_t juli ;
extern int16_t juli2 ;

extern int chao,ni;
extern uint8 zuo;
extern uint8 you;
extern uint8 tushu;
extern int ting[70];
extern int wu[70];
extern uint8 line;
extern uint8 line1;
extern int16_t LeftSpeedSigma2 ;                       //�����ٶ�
extern int16_t RightSpeedSigma2;                      //�����ٶ�
extern int16_t CarSpeed2;                                //��ǰ����
extern int16_t Car_Left_Speed2;
extern int16_t Car_Right_Speed2;
extern uint8 changshu;
typedef struct SERVO_PID_MESSAGE              //���PID����
{
	float error_now;
	float error_last;
        float error_deviation;
        float fuzzy_kp_gain;
        float fuzzy_kd_gain;
	float kp;
        float kd; 
	float output;
} SERVO_PID_MESSAGE;

extern SERVO_PID_MESSAGE Servo_pid;
extern uint8 duanlu_shu;
extern uint16_t Huan_Road_flag;                          //���α�־λ
extern uint8_t First_yuan_right;
extern int16  mpu_zero;
extern float Ang_acc;
/*ֱ�����pwm*/
extern float   up_pwm;
/*ֱ����pd*/
extern float up_p ;
extern float up_d;
extern float  mpu_y;
extern float  Ang_gyro;
extern uint8_t chuzhangai;
 extern uint8_t start;
/*ƫ��Ƕ�*/
extern float   diviation_ang;
extern float  Gyro_speed;
extern uint8 tingche;
/*�����ǻ���*/
extern float mpu_ratio;//0.002029386
extern float  Ang_zero;
extern float shuduz;
	extern float shuduy;
extern int16_t speed_sum;
extern int16_t juli3; 
extern float wei;
extern int16_t LeftSpeedSigma ;                       //�����ٶ�
extern int16_t RightSpeedSigma;                      //�����ٶ�
extern int16_t LeftSpeedSigma1 ;                       //�����ٶ�
extern int16_t RightSpeedSigma1;                      //�����ٶ�
extern int16_t CarSpeed;                                //��ǰ����
extern int16_t Car_Left_Speed;
extern int16_t Car_Right_Speed;
extern int16_t   LastCarSpeed;                           //�ϴγ���              
extern int16_t   SpeedError;                             //����ٶ���Ŀ���ٶ����
extern int16_t   SpeedLastError;                         //�ϴ��ٶ�ƫ��ˢ��
extern int16_t   Speedmax;     // 16000                    
extern uint8_t  SpeedOutPeriod;  
extern uint8_t  SpeedCount;                          //�ٶȻ�����ʱ��
extern float  PWM_Speed;                                 //������ٶȻ�pwm
extern uint8 cishu;
extern float  Last_Speed;                                //�ϴμ�������pwm  
extern float SpeedP;
extern float SpeedI;
extern float Speed_P ; // 240
extern int16_t Speed_I ;
extern float Speed;
extern int16_t  Save_speed;                         //Ŀ���ٶ�
extern double adc_error;
extern double adc_errorlast;

extern int16  mpu6050_gz; //z����ٶ�
extern int32_t dv;
#endif
