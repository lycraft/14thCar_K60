#include "gpio.h"
#include "ftm.h"
#include "control.h"
#include "data_sent.h"
#include "motor.h"
#include "math.h"
#include "extern.h"
#include "image_processe.h"
#include "shuju.h"
#include "Handle.h"
#include "SEEKFREE_MPU6050.h"
#include "shuju.h"
#include "Balance.h"
#define pi 3.14159
#define SPEEDPERIODFAV  (100)
extern  uint8_t Turn_left_dui ;          //左丢线次数
    extern    uint8_t Turn_right_dui;         //右丢线次数
extern int16 mpu_gyro_x,mpu_gyro_y,mpu_gyro_z;
 extern int16 mpu_acc_x,mpu_acc_y,mpu_acc_z;
extern uint8_t First_yuan_left;
 extern uint8_t podao;
extern uint8_t   camera_flag; 
extern    uint8_t Width[70];
extern uint8_t huanshu;
//设定速度
uint16_t W=16;//车宽
uint16_t L=30;//车长
uint16_t mangqu=39;//盲区
uint16_t stop_chang_yuzhi=4000;
uint16_t jiajian_flag=1;
//uint16_t Speed = 100;
uint16_t Out_Annular_Turn_row=6;
uint16_t LPWM=3000;
uint16_t RPWM=3000;
uint16_t SpeedNumA = 0;
uint16_t SpeedNumB = 0;
uint16_t i=0,j=0;
uint16_t chasu_max =80;
uint16_t chasu_min =170;//内轮最小速度
uint16_t Small_S_kp=0,Small_S_kd=0;
int16_t S_speed=50,N_speed=50,L_speed=50/*长直道*/,Speed_plus=0,brake_i=0,Small_S_speed=50,obstacle_speed=50;
uint16_t Annular_speed=50,Curve_speed=50;//暂时分三档速度 s减速最低速度 n弯道中速度 l直道最大速度
int16_t Short_speed=50/*短直道*/;
int16_t ramp_speed=50;
int32_t Speed_sub=0,speed_out=0;
int16_t Speed_choose=0;
float coefficient=1.5;
float a=0.125,mul=2;
uint16_t quanzhong=4;
uint16_t p_max=500,p_min=160;
extern Data_Type *Sent_Data;
extern PID_Speed PID_LeftSpeed,PID_RightSpeed,Diff_Speed_Control;
char Left_Crazy = 0;	// 电机疯转
char Right_Crazy = 0;	// 电机疯转
int32 RC_Get = 1500;	// 遥控器的通道值
int32 MOTOR_Duty_Left  = 0;
int32 MOTOR_Duty_Right = 0;
int32 MOTOR_Speed_Left = 0;
int32 MOTOR_Speed_Right = 0; 
int32 MOTOR_Speed_Left_Last = 0;
int32 MOTOR_Speed_Right_Last = 0;
int32 MOTOR_Left_Acc = 0;
int32 MOTOR_Right_Acc = 0;
 extern uint8_t  ryh ;
     extern    uint8_t   ryl;
      extern    uint8_t  lyl ;
       extern   uint8_t lyh;
extern int32
	Speed_Now ,	// 当前实际速度
	Speed_Min,	// 左右最小速度
	Speed_Set , 	// 目标设定速度
	Theory_Duty,// 理论直立占空比
	Vel_Set ,	// 目标转向角速度
	Direct_Parameter,// 转向系数
	Direct_Last ,
	Radius ;		// 目标转向半径倒数
float SpeedPWMOut(float NewspeedPWM ,float LastspeedPWM,uint8_t PeriodCount)
{
    float  speedPWMfav ;
    float  SpeedOUT ;
    speedPWMfav = NewspeedPWM - LastspeedPWM ;
    SpeedOUT = speedPWMfav *(PeriodCount)/200 + LastspeedPWM ;
    
    return SpeedOUT ;
}

void SpeedCalculate(void)
{

	
	
//	
//	if(LeftSpeedSigma > Car_Left_Speed + 250)           //速度变化率限幅
//		LeftSpeedSigma = Car_Left_Speed + 250;
//	else if(LeftSpeedSigma < Car_Left_Speed - 250)
//		LeftSpeedSigma = Car_Left_Speed -250;
//	if(RightSpeedSigma > Car_Right_Speed + 250)
//		RightSpeedSigma = Car_Right_Speed + 250;
//	else if(RightSpeedSigma < Car_Right_Speed - 250)
//		RightSpeedSigma = Car_Right_Speed - 250;
//	
//	CarSpeed = (LeftSpeedSigma + RightSpeedSigma) *0.5; //当前速度
//	Car_Left_Speed = LeftSpeedSigma;
//	Car_Right_Speed = RightSpeedSigma;                             
//	LeftSpeedSigma = 0;
//	RightSpeedSigma = 0;	
//	if(CarSpeed>30)start=1;
	if(LeftSpeedSigma1 > Car_Left_Speed + 250)           //速度变化率限幅
		LeftSpeedSigma1 = Car_Left_Speed + 250;
	else if(LeftSpeedSigma1 < Car_Left_Speed - 250)
		LeftSpeedSigma1 = Car_Left_Speed -250;
	if(RightSpeedSigma1 > Car_Right_Speed + 250)
		RightSpeedSigma1 = Car_Right_Speed + 250;
	else if(RightSpeedSigma1 < Car_Right_Speed - 250)
		RightSpeedSigma1 = Car_Right_Speed - 250;
	
	CarSpeed = (LeftSpeedSigma1 + RightSpeedSigma1) *0.5; //当前速度
	Car_Left_Speed = LeftSpeedSigma1;
	Car_Right_Speed = RightSpeedSigma1;                             
	LeftSpeedSigma1 = 0;
	RightSpeedSigma1 = 0;	
	SpeedError = Save_speed - CarSpeed; //本次速度偏差刷新
	SpeedLastError = CarSpeed - LastCarSpeed; //上上次速度偏差刷新
	LastCarSpeed = CarSpeed; //上次速度偏差值刷新
/************************位置式pid***************************/
	
	/*************************一次P*******************************/
	if(SpeedError > 0)
	{
    	SpeedP =  (SpeedError * Speed_P * 0.1 );// / 10.0);		
	}
	else
	{
		   	SpeedP =  (SpeedError * Speed_P * 0.1 );// / 10.0);		
	}

	//	if ( SpeedError <= 500)
	  {
		  SpeedI += (SpeedError * Speed_I * 0.01);	
	  }
	if(SpeedI > 3000)
		SpeedI = 3000;
	else if(SpeedI < -3000)
		SpeedI = -3000;

	Last_Speed = Speed;
	Speed = SpeedP + SpeedI;

	
		if(	Speed > Speedmax)
	{
		Speed = Speedmax;
	}
	else if(Speed < -Speedmax)
	{
		Speed = -Speedmax;
	}
	

}


/***********************************************
* 函数名: Kalman_left
* 功  能: 左编码器卡尔曼滤波
* 调用函数: 
* 调用参数: 
* 返回值:  
* 使用方法:
* 编写时间: 2014/12/5
* 修改时间: 2014/12/5
************************************************/
int Kalman_left(int data)
{
  static int p1=6;
  static int c1=5;
  int q=5;
  int r=10;
  float kg,c2,p2;
  
	
  p2=p1+q;
  kg=p2*p2/(p2*p2+r*r);
  c2=c1+kg*(data-c1);
  p1=(1-kg)/p2;
  c1=c2;

  return c1; 
}
/***********************************************
* 函数名: Kalman_right
* 功  能: 右编码器卡尔曼滤波
* 调用函数: 
* 调用参数: 
* 返回值:  
* 使用方法:
* 编写时间: 2014/12/5
* 修改时间: 2014/12/5
************************************************/
int Kalman_right(int data)
{
  static int p1=6;
  static int c1=5;
  int q=5;
  int r=10;
  float kg,c2,p2;
  
	
  p2=p1+q;
  kg=p2*p2/(p2*p2+r*r);
  c2=c1+kg*(data-c1);
  p1=(1-kg)/p2;
  c1=c2;

  return c1; 
}
int Limit_value(int value, int up_value,int down_value)
{
	int temp;
	
	if(value>up_value)
		temp=up_value;
	else if(value<down_value)
		temp=down_value;
	else
		temp=value;
	
	return temp;
}
//*********** 动态P **************
float Dynamic_P(uint16_t err_in)
{
	
	float p;
	p=a*err_in*err_in+p_min;//0.008
	if(p>p_max) 
		p=p_max;
    
	return p;
}

void motor_speed_zhili(int32_t speed1,int32_t speed2,int32 max,int32 min)
{

	
speed1= range_protect( speed1, min, max );
speed2= range_protect( speed2, min, max );	
if(speed1>0)
{
FTM_PWM_ChangeDuty(MotorBZ,0);//正转zuo
			FTM_PWM_ChangeDuty(MotorBF,speed1);
}
else 
{
FTM_PWM_ChangeDuty(MotorBZ,-speed1);//正转zuo
			FTM_PWM_ChangeDuty(MotorBF,0);
}
if(speed2>0)
{
  FTM_PWM_ChangeDuty(MotorAZ,speed2);//正转
		FTM_PWM_ChangeDuty(MotorAF,0);

}
else{
  FTM_PWM_ChangeDuty(MotorAZ,0);//fang转
		FTM_PWM_ChangeDuty(MotorAF,-speed2);		

}
}

void balance_deal(void)
{
    Ang_acc=(float)(atan2(mpu_acc_y,mpu_acc_z ))*180.0/pi;
	  if(Ang_acc>90)  Ang_acc =90;
	  if(Ang_acc<-90)  Ang_acc =-90;
	  mpu_y=(mpu_gyro_x*1.0-mpu_zero)/16.4;
	 
  Gyro_speed=-(float)((mpu_gyro_x*1.0-mpu_zero)*mpu_ratio/16.4);		
	  Ang_gyro=(float)(Ang_gyro+(float)(Gyro_speed));
		
	 Ang_gyro=Ang_gyro+(Ang_acc -Ang_gyro)*0.0901425;

    diviation_ang =Ang_gyro -Ang_zero;
	  up_pwm=up_p*diviation_ang+ mpu_y*up_d;
  // 	motor_speed_zhili(-up_pwm,-up_pwm,950,-950);

	  
	
}





 float tan1(int a)
 {
	 float b=0;
		switch(a)
		{
			case 1 : b=0.017455065;break;  
			case 2 : b=0.034921;break;  
			case 3 : b=0.052407779;break;  
			case 4 : b=0.069926812;break;  
			case 5 : b=0.087488664;break;  
			case 6 : b=0.105104235;break;  
			case 7 : b=0.122784561;break;  
			case 8 : b=0.140540835;break;  
			case 9 : b=0.15838444;break;  
			case 10 : b= 0.176326981;break;  
			case 11 : b= 0.194380309;break;  
			case 12 : b= 0.212556562;break;  
			case 13 : b= 0.230868191;break;  
			case 14 : b= 0.249328003;break;  
			case 15 : b= 0.267949192;break;  
			case 16 : b= 0.286745386;break;  
			case 17 : b= 0.305730681;break;  
			case 18 : b= 0.324919696;break;  
			case 19 : b= 0.344327613;break;  
			case 20 : b= 0.363970234;break;  
			case 21 : b= 0.383864035;break;  
			case 22 : b= 0.404026226;break;  
			case 23 : b= 0.424474816;break;  
			case 24 : b= 0.445228685;break;  
			case 25 : b= 0.466307658;break;  
			case 26 : b= 0.487732589;break;  
			case 27 : b= 0.509525449;break;  
			case 28 : b= 0.531709432;break;  
			case 29 : b= 0.554309051;break;  
			case 30 : b= 0.577350269;break; 
		}
		return b;
 }

 
 

void State_Analyze(void)
{  
    //出赛道保护
    if( left_wdata<50 &&  right_wdata<50&&zhangai==0&&start==1&&bianxing!=1 )
    {
		Huan_Road_flag=0;
		run=0;
		Stop=0;
		BBB(0);
		start=0;
		tingche=0;
		speed_sum=0;
        adc_error = 0;
		bianxing=0;
		juli2=0;
		duanlu=0;
    }
	//偏差  左负右正
	if(zhangai==0||zhangai==11||zhangai==5)
	{ adc_error = (right_wdata - left_wdata)/(left_wdata+right_wdata)*100;//20000
	adc_error=adc_error*(adc_error*adc_error/1250.0+2)/10;}
	tar_speed();
	if(camera_flag==2)
	{

	camera_flag=0;

	}
	
	
	

}




void Electronic_diff(void)
{  
	 LCR  *Lcr=(LCR *)Sent_Data->Lcr;
    //角速度读取
     
    static int16_t mpu6050_gz_last;	  
	mpu6050_gz =   GYRO_Real.Z*GYRO_Real.Z/4000000+5.0;
	mpu6050_gz=0.7*mpu6050_gz+0.3*mpu6050_gz_last;
	if(Huan_Road_flag==1||Huan_Road_flag==2||Huan_Road_flag==11||Huan_Road_flag==22||zhangai==1||zhangai==3||Huan_Road_flag==5||Huan_Road_flag==55)
		{
		turn=(float)(-GYRO_Real.Z*1.0)*mpu_ratio/16.4;	
		  turn_angle=(float)(turn_angle+(float)(turn));
		}
		if(duanlu==1&&bianxing==0)
		{bianxing=3;}
		if(bianxing==3)juli2+=CarSpeed2;
		if(juli2>10&&bianxing==3)bianxing=1;
		if(bianxing==1)
		{turn1=(float)(-GYRO_Real.Z*1.0)*mpu_ratio/16.4;	
		  turn_angle1=(float)(turn_angle1+(float)(turn1));
			adc_error=30;
			BBB(1);
		}
		if(turn_angle1<-150&&bianxing==1&&(right_wdata>50||left_wdata>50))
		{bianxing=2;turn_angle1=0;BBB(0);juli2=0;}
		
	

	if(left_wdata>850 && right_wdata>850)
		juli3+=CarSpeed2;
	else juli3=0;
	if(zuo>2&&you<zuo&&dahuan>2&&(Huan_Road_flag==0)&&Turn_left_flag>10&&huan==1&&juli3>850)
				Huan_Road_flag=11;
			if(you>2&&you>zuo&&dahuan>2&&(Huan_Road_flag==0)&&Turn_right_flag>10&&huan==1&&juli3>850)
				Huan_Road_flag=1;
	if(Huan_Road_flag==1||Huan_Road_flag==2)
	{adc_error=(80-point);BBB(1);
//	if(panhuan==1&&point>80)
//	adc_error=30;
//		if(panhuan==2&&(point>80||point<40))
//	adc_error=60;
	
	}

	
		
	if(Huan_Road_flag==11||Huan_Road_flag==22)
	{adc_error=(80-point);BBB(1);
//		if(panhuan==1&&point<80)
//	adc_error=-30;
//		if(panhuan==2&&(point<80||point>120))
//	adc_error=-60;
	}
	
//	if(Huan_Road_flag==4||Huan_Road_flag==5)
//{
//	if(left_wdata>800 || right_wdata>800)
//	{adc_error+=13;BBB(1);changshu=1;}
//	if(changshu==1&&left_wdata<800&& right_wdata<800)
//	{
//		BBB(0);
//		if(adc_error<-15)adc_error=-15;
//		if(adc_error>5)adc_error=2;
//	}
//}
//if(Huan_Road_flag==44||Huan_Road_flag==55)
//{
//	if(left_wdata>800 ||  right_wdata>800)
//	{adc_error-=13;BBB(1);changshu=1;}
//	if(changshu==1&&left_wdata<800&& right_wdata<800)
//	{
//		BBB(0);
//		if(adc_error>15)adc_error=15;
//		if(adc_error<-5)adc_error=-2;
//	}
//}
//	if(Huan_Road_flag==55&&Lcr[20].RBlack>70&&Turn_right_flag<2&&Width[2]<95)
//	{
//	//if(adc_error>-50)
//		adc_error-=(80);
//	adc_error=adc_error*10;
//	}
//	if(Huan_Road_flag==5&&Lcr[20].LBlack<90&&Turn_left_flag<2&&Width[2]<95)
//	{
////	if(adc_error<50)
//		adc_error+=(80);
//		adc_error=adc_error*10;
//	}
	
//	if(Huan_Road_flag==55&&Turn_right_flag<2)
//	{
//	//adc_error=(70-point)*(1.8);
//	if(adc_error>-50)adc_error-=(20);
////	
//	}
//	if(Huan_Road_flag==5&&Turn_left_flag<2)
//	{
////	adc_error=(70-point)*(1.8);
//	if(adc_error<50)adc_error+=(20);
//	
//	}
//	
//	
//	if(Huan_Road_flag==44)
//	{
//	if(adc_error<-5)adc_error=2;
//		if(adc_error>15)adc_error=15;
//	
//	}
//	
//	
//	
//	if(Huan_Road_flag==4)
//	{
//	if(adc_error<-15)adc_error=-15;
//		if(adc_error>5)adc_error=2;
//	
//	}
	if(Huan_Road_flag==4||Huan_Road_flag==44)
	{
	{adc_error=(80-point)*0.8;}
	
	}
	if(Huan_Road_flag==5)
	{
	if((left_wdata>800 ||  right_wdata>800)&&left_wdata>300 &&  right_wdata>300&&Turn_left_flag<4)
	{adc_error=(60-point);BBB(1);}
	else BBB(0);
	}
	if(Huan_Road_flag==55)
	{
	if((left_wdata>800 ||  right_wdata>800)&&left_wdata>300 &&  right_wdata>300&&Turn_right_flag<4)
		{adc_error=(100-point);BBB(1);}
		else BBB(0);
	}

	Engine_Kp_temp=Engine_Kp_R;
	Engine_Kd_temp=Engine_Kd_R;
	
		if(Huan_Road_flag==33||Huan_Road_flag==3||Huan_Road_flag==44||Huan_Road_flag==4)
	{
		Engine_Kp_temp=160;
	Engine_Kd_temp=8.5;
	}
	
	if(zhangai!=0)
	{
		Engine_Kp_temp=150;
		Engine_Kd_temp=8.5;
	}
	if(Huan_Road_flag==5||Huan_Road_flag==55||Huan_Road_flag==1||Huan_Road_flag==11||Huan_Road_flag==2||Huan_Road_flag==22)
	{
		Engine_Kp_temp=200;
		Engine_Kd_temp=6.5;
	}	
	
	//障碍
		if(zhangai==11&&ADC_ceju>400&&Ang_acc>20&&start==1)
			zhangai=1;
			if(zhangai==1)
				adc_error=-80;
			if(turn_angle>30&&zhangai==1)
			{zhangai=2;turn_angle=0;}
			if(zhangai==2)
			{adc_error=0;
//				juli1=(Get_EncoderB_PulseCount());
//				if(Get_EncoderB_Dir()==1)
//					juli1=-juli1;
//				
//			juli+=juli1;
				juli+=CarSpeed2;
			}
//			if(zhangai==2&&zhangai_shu>10&&right_wdata<10&&left_wdata<10)
//				zhangai=3;
			if(zhangai==2&&juli>800&&right_wdata<10&&left_wdata<10)
				zhangai=3;
			if(zhangai==3)
			{adc_error=50;juli=0;}
			if(turn_angle<-80&&zhangai==3)
			{zhangai=4;turn_angle=0;}
			if(zhangai==4)
			{adc_error=0;zhangai_shu=0;}
			if((right_wdata>5||left_wdata>5)&&zhangai ==4)
			{zhangai=5;}
			if(zhangai==5&&chuzhangai==10)
			{zhangai=0;tushu=0;chuzhangai=0;}
	
	
	dv = Engine_Kp_temp*(CarSpeed*CarSpeed/(18000*18000)+1)*adc_error- Engine_Kd_temp*mpu6050_gz*GYRO_Real.Z;

  mpu6050_gz_last=mpu6050_gz;
    if(dv > 4000)           //限幅
        dv = 4000;
    else if(dv < -4000)
        dv = -4000;
//	dv=0;
	if(Huan_Road_flag==3||Huan_Road_flag==33||Huan_Road_flag==4||Huan_Road_flag==44)turn_angle=0;

    if(dv>0)
    {           
        speed_dir_left = -0.8*dv;       //减速
        speed_dir_right = dv;       //加速
    }        
    else
    {   
        speed_dir_left = -dv;       //加速
        speed_dir_right = 0.8*dv;       //减速
    }
}

