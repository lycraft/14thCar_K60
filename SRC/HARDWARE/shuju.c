
#include "common.h"
#include "image_processe.h"
#include "extern.h"
#include "motor.h"
#include "math.h"
uint8 huan=0;



double left_wdata;
double left_ldata;
double right_wdata;
double ADC_ceju;
double right_ldata;
double adc_error;
double adc_errorlast;

uint8 zhang=0;

int Left_Line[63], Right_Line[63]; 
uchar	Mid_Line[63];	//�����ұ߽���
uint8 point;
uint8 dahuan=0;
uint8 chuhuan=0;
uint8 bushi=0;
uint8 panhuan=0;
uint8 changshu=0;
uint8 zhidao=0;
uint8 chuhuankou=0;
uint8 tushu=0;
uint8 duanlu_shu=0;
int ting[70];
int wu[70];
uint8 zuo=0;
uint8 you=0;
uint16_t Huan_Road_flag = 0;                          //���α�־λ
uint8_t zhangai = 0;
uint8_t zhangai_hang = 0;
uint8_t chuzhangai = 0;
uint8_t start = 0;
uint8_t duanlu = 0;
uint8_t duanyu = 0;
uint8_t gray=0;
uint8_t zhangai_shu = 0;
uint8 cishu=0;	
	

uint8 DuanLu1=0;
float wei=0;
int32 speed=80;
uint8 run=0;
uint8 line=16;
uint8 line1=0;
float shuduz=0;
float shuduy=0;
int16_t juli ; 
int16_t juli1 ; 
int16_t juli2=0 ; 
int16_t juli3=0; 
uint8 DuanLu2=0;
uint8 tingche=0;
uint8 bianxing=0;
float turn=0;
float  turn_angle=0;
float turn1=0;
float  turn_angle1=0;

int8_t tiaozheng=0;
int16  mpu_zero=0;
float Ang_acc=0;
/*ֱ�����pwm*/
float   up_pwm=0;
/*ֱ����pd*/
float up_p =700;//700.5;//700
float up_d =6000;//6000
float  mpu_y=0;
float  Ang_gyro=0.0;

/*ƫ��Ƕ�*/
float   diviation_ang=0;
/*���ڻ��ֵ���2�����ٶ�*/
float  Gyro_speed=0.0;
/*�����ǻ���*/
float mpu_ratio= 0.145505;//0.002029386
float  Ang_zero = 39;


int16_t LeftSpeedSigma ;                       //�����ٶ�
int16_t RightSpeedSigma;                      //�����ٶ�
int16_t LeftSpeedSigma1 ;                       //�����ٶ�
int16_t RightSpeedSigma1;                      //�����ٶ�
int16_t LeftSpeedSigma2 ;                       //�����ٶ�
int16_t RightSpeedSigma2;                      //�����ٶ�
int16_t CarSpeed2;                                //��ǰ����
int16_t Car_Left_Speed2;
int16_t Car_Right_Speed2;
int16_t CarSpeed;                                //��ǰ����
int16_t Car_Left_Speed;
int16_t Car_Right_Speed;
int16_t   LastCarSpeed;                           //�ϴγ���              
int16_t   SpeedError;                             //����ٶ���Ŀ���ٶ����
int16_t   SpeedLastError;                         //�ϴ��ٶ�ƫ��ˢ��
int16_t   Speedmax=8000;     // 16000                    
uint8_t  SpeedOutPeriod = 0;
int16_t speed_sum=0; 
uint8_t  SpeedCount = 0;                          //�ٶȻ�����ʱ��
float  PWM_Speed;                                 //������ٶȻ�pwm
float Speed;
float  Last_Speed;                                //�ϴμ�������pwm  
float SpeedP;
float SpeedI;

float Speed_P =800;// 4000;//0.001; // 240/300
int16_t Speed_I =10;//30000;
int16_t  Save_speed = 0;                         //Ŀ���ٶ�



int16  mpu6050_gz; //z����ٶ�

int32_t dv;
int32_t speed_dir_left=0;
int32_t speed_dir_right=0;


