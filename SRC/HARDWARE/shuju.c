
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
uchar	Mid_Line[63];	//左中右边界线
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
uint16_t Huan_Road_flag = 0;                          //环形标志位
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
/*直立输出pwm*/
float   up_pwm=0;
/*直立环pd*/
float up_p =700;//700.5;//700
float up_d =6000;//6000
float  mpu_y=0;
float  Ang_gyro=0.0;

/*偏差角度*/
float   diviation_ang=0;
/*用于积分的陀2螺仪速度*/
float  Gyro_speed=0.0;
/*陀螺仪积分*/
float mpu_ratio= 0.145505;//0.002029386
float  Ang_zero = 39;


int16_t LeftSpeedSigma ;                       //左轮速度
int16_t RightSpeedSigma;                      //右轮速度
int16_t LeftSpeedSigma1 ;                       //左轮速度
int16_t RightSpeedSigma1;                      //右轮速度
int16_t LeftSpeedSigma2 ;                       //左轮速度
int16_t RightSpeedSigma2;                      //右轮速度
int16_t CarSpeed2;                                //当前车速
int16_t Car_Left_Speed2;
int16_t Car_Right_Speed2;
int16_t CarSpeed;                                //当前车速
int16_t Car_Left_Speed;
int16_t Car_Right_Speed;
int16_t   LastCarSpeed;                           //上次车速              
int16_t   SpeedError;                             //这次速度与目标速度误差
int16_t   SpeedLastError;                         //上次速度偏差刷新
int16_t   Speedmax=8000;     // 16000                    
uint8_t  SpeedOutPeriod = 0;
int16_t speed_sum=0; 
uint8_t  SpeedCount = 0;                          //速度环控制时间
float  PWM_Speed;                                 //输出的速度环pwm
float Speed;
float  Last_Speed;                                //上次计算所得pwm  
float SpeedP;
float SpeedI;

float Speed_P =800;// 4000;//0.001; // 240/300
int16_t Speed_I =10;//30000;
int16_t  Save_speed = 0;                         //目标速度



int16  mpu6050_gz; //z轴角速度

int32_t dv;
int32_t speed_dir_left=0;
int32_t speed_dir_right=0;


