#include "motor.h"
#include "gpio.h"
#include "ftm.h"
#include "dma.h"
#include "pit.h"
#include "pid.h"
#include "extern.h"
#include "control.h"
#include "stdlib.h"
#include "extern.h"
#include "math.h"
/*陀螺仪数据*/

PID_Speed PID_MiddleSpeed,PID_LeftSpeed,PID_RightSpeed,Diff_Speed_Control;
float LSpeedP,LSpeedI,LSpeedD;
float RSpeedP,RSpeedI,RSpeedD;
float MSpeedP,MSpeedI,MSpeedD;
extern int16_t S_speed,N_speed,L_speed,Speed_plus;

//uint16_t CarSpeed;
uint16_t Diff_P=16,Diff_P_temp,Diff_D=40,Diff_D_temp;//////////驱动输出pwm是反的 给2000 输出8000
float M_P=80,M_I=7;
int32_t leftout,L_MAX=9700;
int32_t rightout,R_MAX=9700;
int32_t diff_pwm_max=70;
int16_t D_P_F =0;
//电机初始化函数
void Motor_Init(void)
{
	FTM_InitTypeDef FTM_InitStruct1;
	
	FTM_InitStruct1.Frequency = MotorFrequency;
	FTM_InitStruct1.FTMxMAP = MotorAZ;
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 0;
	FTM_Init(&FTM_InitStruct1);

	FTM_InitStruct1.Frequency = MotorFrequency;
	FTM_InitStruct1.FTMxMAP = MotorAF;
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 0;
	FTM_Init(&FTM_InitStruct1);

	FTM_InitStruct1.Frequency = MotorFrequency;
	FTM_InitStruct1.FTMxMAP = MotorBZ;
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 0;
	FTM_Init(&FTM_InitStruct1);

	FTM_InitStruct1.Frequency = MotorFrequency;
	FTM_InitStruct1.FTMxMAP = MotorBF;
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = 0;
	FTM_Init(&FTM_InitStruct1);
}
//编码器计数初始化函数
void Encoder_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct1;
	DMA_InitTypeDef DMA_InitStruct1;
	
	GPIO_InitStruct1.GPIOx = EncoderA;
	GPIO_InitStruct1.GPIO_Pin = EncoderAI;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DMA_RISING;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(&GPIO_InitStruct1);

	GPIO_InitStruct1.GPIOx = EncoderB;
	GPIO_InitStruct1.GPIO_Pin = EncoderBI;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DMA_RISING;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(&GPIO_InitStruct1);

	GPIO_InitStruct1.GPIOx = EncoderA_DirPORT;
	GPIO_InitStruct1.GPIO_Pin = EncoderA_DirPin;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIOx = EncoderB_DirPORT;
	GPIO_InitStruct1.GPIO_Pin = EncoderB_DirPin;
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(&GPIO_InitStruct1);
	
	//编码器A的DMA采集脉冲配置
	DMA_InitStruct1.Channelx = EncoderA_DMA_CH;
	DMA_InitStruct1.DMAAutoClose = DISABLE;//传输完毕自动关闭
	DMA_InitStruct1.EnableState = ENABLE;//初始化直接使能，等待触发
	DMA_InitStruct1.MinorLoopLength = TransferLength;
	DMA_InitStruct1.PeripheralDMAReq = EncoderA_DMAREQ;
	DMA_InitStruct1.TransferBytes = 1;
	
	DMA_InitStruct1.DestBaseAddr = (uint32_t)(&DMA_Temp);
	DMA_InitStruct1.DestDataSize = DMA_DST_8BIT;
	DMA_InitStruct1.DestMajorInc = 0;
	DMA_InitStruct1.DestMinorInc = 0;
	
	DMA_InitStruct1.SourceBaseAddr = (uint32_t)(&DMA_Temp);
	DMA_InitStruct1.SourceDataSize = DMA_SRC_8BIT;
	DMA_InitStruct1.SourceMajorInc = 0;
	DMA_InitStruct1.SourceMinorInc = 0;
	DMA_Init(&DMA_InitStruct1);
	//编码器B的DMA采集脉冲配置
	DMA_InitStruct1.Channelx = EncoderB_DMA_CH;
	DMA_InitStruct1.DMAAutoClose = DISABLE;//传输完毕自动关闭
	DMA_InitStruct1.EnableState = ENABLE;//初始化直接使能，等待触发
	DMA_InitStruct1.MinorLoopLength = TransferLength;
	DMA_InitStruct1.PeripheralDMAReq = EncoderB_DMAREQ;
	DMA_InitStruct1.TransferBytes = 1;
	
	DMA_InitStruct1.DestBaseAddr = (uint32_t)(&DMA_Temp);
	DMA_InitStruct1.DestDataSize = DMA_DST_8BIT;
	DMA_InitStruct1.DestMajorInc = 0;
	DMA_InitStruct1.DestMinorInc = 0;
	
	DMA_InitStruct1.SourceBaseAddr = (uint32_t)(&DMA_Temp);
	DMA_InitStruct1.SourceDataSize = DMA_SRC_8BIT;
	DMA_InitStruct1.SourceMajorInc = 0;
	DMA_InitStruct1.SourceMinorInc = 0;
	DMA_Init(&DMA_InitStruct1);
}
//获取编码器A的脉冲函数，自带重载
uint16_t Get_EncoderA_PulseCount(void)
{
	uint16_t temp;
	
	temp = DMA_GetCurrDataCounter(EncoderA_DMA_CH);
	DMA_SetCurrDataCounter(EncoderA_DMA_CH,TransferLength);
	
	return (TransferLength - temp);
}
//获取编码器B的脉冲函数，自带重载
uint16_t Get_EncoderB_PulseCount(void)
{
	uint16_t temp;
	
	temp = DMA_GetCurrDataCounter(EncoderB_DMA_CH);
	DMA_SetCurrDataCounter(EncoderB_DMA_CH,TransferLength);
	
	return (TransferLength - temp);
}
//获取编码器方向函数
uint16_t Get_EncoderA_Dir(void)
{
	uint16_t temp;
	
	temp = GPIO_ReadInputDataBit(EncoderA_DirPORT,EncoderA_DirPin);
	
	return temp;
}
//获取编码器方向函数
uint16_t Get_EncoderB_Dir(void)
{
	uint16_t temp;
	
	temp = GPIO_ReadInputDataBit(EncoderB_DirPORT,EncoderB_DirPin);
	
	return temp;
}



void Left_SpeedControl(int32_t leftin)
{
	 int32_t leftout;
   PID_LeftSpeed.errNow =PID_LeftSpeed.setPoint - (float)(leftin);//偏差
//	/*---------------------*/
//		if(abs(PID_LeftSpeed.errNow) > (L_speed - N_speed - 10))//与目标速度偏差过大 加大P
//			PID_LeftSpeed.kp = 20;
//		else
//			PID_LeftSpeed.kp = 10;
//	/*-----------------------*/
	PID_LeftSpeed.kp=6;
	PID_LeftSpeed.kd=56;
	 LSpeedP= PID_LeftSpeed.kp * PID_LeftSpeed.errNow;//P
	
	 LSpeedD= PID_LeftSpeed.kd * (PID_LeftSpeed.errNow-PID_LeftSpeed.errOld1);//D
	
//	if((LSpeedP + LSpeedD)>=2000)PID_LeftSpeed.ctrOut +=2000;
//	else if((LSpeedP + LSpeedD)<=-2000)PID_LeftSpeed.ctrOut -=2000;
//	else
		PID_LeftSpeed.ctrOut += (LSpeedP + LSpeedD);

		PID_LeftSpeed.errOld1 =PID_LeftSpeed.errNow;//刷新上一次误差
		
		if(PID_LeftSpeed.ctrOut>5000){PID_LeftSpeed.ctrOut=5000;}//设置上限
		if(PID_LeftSpeed.ctrOut<-5000){PID_LeftSpeed.ctrOut=-5000;}
		
		leftout=(int32_t)(PID_LeftSpeed.ctrOut);
		
//		if(Brake_Stop==0 && start_flag==0 && stop_flag==1)//反刹停车
//			leftout=0;
		
//		if(leftout<0)
//		{
//			OLED_Write_String(0,4,"-");
//			OLED_Write_Num5(1,4,-leftout);
//		}
//		else
//		{
//			OLED_Write_Num5(1,4,leftout);
//		}
			
		if(leftout>=0)
		{
			FTM_PWM_ChangeDuty(MotorBZ,0);//正转
			FTM_PWM_ChangeDuty(MotorBF,leftout);
		}
		else if(leftout<0)
		{
			leftout=-leftout;
			FTM_PWM_ChangeDuty(MotorBF,0);//反转
			FTM_PWM_ChangeDuty(MotorBZ,leftout);
		}
		//OLED_Write_Num5(1,4,leftout);
}

void PID_LeftSpeed_Init(float P,float I,float D,float setPoint)//初始化
{
		PID_LeftSpeed.kp=P;
		PID_LeftSpeed.ki=I;
		PID_LeftSpeed.kd=D;
	  PID_LeftSpeed.setPoint=setPoint;

		PID_LeftSpeed.ctrOut=0;
		PID_LeftSpeed.errNow=0;
		PID_LeftSpeed.errOld1=0;
}
/////////////////////////////////////////////////////////////左轮


/////////////////////////////////////////////////////////////右轮
void Right_SpeedControl(int32_t Rightin)
{
	 int32_t Rightout;
   PID_RightSpeed.errNow =PID_RightSpeed.setPoint -(float)(Rightin);//偏差
	
//	/*---------------------*/
//	if(abs(PID_RightSpeed.errNow) > (L_speed - N_speed - 10))//与目标速度偏差过大 加大P
//		PID_RightSpeed.kp = 20;
//	else
//		PID_RightSpeed.kp = 10;
//	/*-----------------------*/
	

//	 if(PID_RightSpeed.errNow<=20)
//		{
//			PID_RightSpeed.kp=M_I*fabs(PID_RightSpeed.errNow)/(20);
//		}
//		else
	PID_RightSpeed.kp=6;
	PID_RightSpeed.kd=56;
	 RSpeedP= PID_RightSpeed.kp * PID_RightSpeed.errNow;
 
	 RSpeedD= PID_RightSpeed.kd * (PID_RightSpeed.errNow-PID_RightSpeed.errOld1);
	 
//	if((LSpeedP + LSpeedD)>=2000)PID_RightSpeed.ctrOut +=2000;
//	else if((LSpeedP + LSpeedD)<=-2000)PID_RightSpeed.ctrOut -=2000;
//	else
	 PID_RightSpeed.ctrOut += (RSpeedP + RSpeedD);
	 PID_RightSpeed.errOld1 =PID_RightSpeed.errNow;//刷新上一次误差

	if(PID_RightSpeed.ctrOut>5000){PID_RightSpeed.ctrOut=5000;}//设置上限
	if(PID_RightSpeed.ctrOut<-5000){PID_RightSpeed.ctrOut=-5000;}
	
	Rightout=(int32_t)(PID_RightSpeed.ctrOut);
	
//	if(Brake_Stop==0 && start_flag==0 && stop_flag==1)//反刹停车
//		Rightout=0;
	
//	if(Rightout<0)
//	{
//		OLED_Write_String(0,6,"-");
//		OLED_Write_Num5(1,6,-Rightout);
//	}
//	else
//	{
//		OLED_Write_Num5(1,6,Rightout);
//	}
	if(Rightout>=0)
	{
		FTM_PWM_ChangeDuty(MotorAZ,Rightout);//正转
		FTM_PWM_ChangeDuty(MotorAF,0);
	}
	else
	{
		Rightout=-Rightout;
		FTM_PWM_ChangeDuty(MotorAF,Rightout);//反转
		FTM_PWM_ChangeDuty(MotorAZ,0);
	}
	//OLED_Write_Num5(1,6,Rightout);
}

void PID_RightSpeed_Init(float P,float I,float D,float setPoint)//初始化
{
		PID_RightSpeed.kp=P;
		PID_RightSpeed.ki=I;
		PID_RightSpeed.kd=D;
	  PID_RightSpeed.setPoint=setPoint;

		PID_RightSpeed.ctrOut=0;
		PID_RightSpeed.errNow=0;
		PID_RightSpeed.errOld1=0;
}
/////////////////////////////////////////////////////////////右轮

//编码器读取车身速度
void Get_MotorSpeed(void)
{
	EncoderA_Cnt=Get_EncoderA_PulseCount();//读取编码器计数值  
	EncoderB_Cnt=Get_EncoderB_PulseCount();
	if(Get_EncoderA_Dir()==0)
		EncoderA_Cnt=-EncoderA_Cnt;
	if(Get_EncoderB_Dir()==1)
		EncoderB_Cnt=-EncoderB_Cnt;
		
	CarSpeed=(EncoderA_Cnt+EncoderB_Cnt)>>1;//车身速度
}
////*********** 速度控制 **********************
//void speed_ctrl(int16_t speed_real)
//{
//    LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//     int16_t diff_pwm=0,D_P,PWM_Give;
//		static int16_t PWM_GiveL=0,PWM_GiveR=0,serr_now=0,serr_last=0,serr_pre=0;
////	   s_p = get_motorP(speed_set,speed_real);
////     s_d = 2*s_p;
//	
//     serr_now = PID_LeftSpeed.setPoint - speed_real;					//计算偏差
//	 
//      D_P = PID_LeftSpeed.ki*serr_now + PID_LeftSpeed.kp*(serr_now-serr_last) + PID_LeftSpeed.kd*(serr_now-2*serr_last+serr_pre); //带入PID中计算增量

//      //D_P = s_p*(serr_now-serr_last) + s_d*(serr_now - 2*serr_last + serr_pre);
//      //D_P = s_p*serr_now + s_d*(serr_now-serr_last); 
//    if(D_P>=2500)   //为增量限幅
//    {
//        D_P = 2500;
//    }
//    else if(D_P<-2500)
//    {
//        D_P = -2500;
//    }
//		
//    PWM_Give = (PWM_GiveL+PWM_GiveR) >> 1 ;  //计算上次两个电机的平均输出
//    PWM_Give += D_P;                                            //计算本次两个电机的基本输出
//    
//    //diff_pwm = get_diff(Duo_PWM-DuoJi_MID);
//    
//  if((Road_flag!=11||Road_flag!=12)&&fabs(Lcr[Turn_row_temp].Center-80)>=8)  //直道情况下与障碍情况下不加主动差速
//	{
//		diff_pwm = get_diff(steer_sub);   //根据中值偏差计算两个电机的输出偏差
//		if(diff_pwm>=diff_pwm_max)
//			diff_pwm=diff_pwm_max;
//		if(diff_pwm<=-diff_pwm_max)
//			diff_pwm=-diff_pwm_max;
//	} 
//    PWM_GiveL = PWM_Give + diff_pwm;  //计算左轮输出
//    PWM_GiveR = PWM_Give - diff_pwm; 			//计算右轮输出
//    
//    
//  if(PWM_GiveL > L_MAX) //左电机输出限幅
//  {
//    PWM_GiveL = L_MAX;
//  }
//  else if(PWM_GiveL < -L_MAX)
//  {
//    PWM_GiveL =  -L_MAX;
//  }
//  
//  
//   if(PWM_GiveL<0)//小于0  //左电机输出
//  {
//      
//   //***************** 电机1 ********************  //左反
//   FTM_PWM_ChangeDuty(MotorAF,- PWM_GiveL); //
//   FTM_PWM_ChangeDuty(MotorAZ, 0);    
//      
//  }
//  else //大于0
//  {
//     
//     //*************** 电机1 *******************  //左
//     FTM_PWM_ChangeDuty(MotorAF,0); 
//     FTM_PWM_ChangeDuty(MotorAZ,PWM_GiveL);      
//      
//  }
//  
//  
//  if(PWM_GiveR>R_MAX) //右电机输出限幅
//  {
//    PWM_GiveR= R_MAX;
//  }
//  else if(PWM_GiveR < -R_MAX)
//  {
//    PWM_GiveR =  -R_MAX;
//  } 
//  
// if(PWM_GiveR<0)//小于0	右电机输出
//  {
//      
//    //*************** 电机2 *********************  //右反
//    FTM_PWM_ChangeDuty(MotorBF, - PWM_GiveR); //-
//    FTM_PWM_ChangeDuty(MotorBZ,  0);    
//    
//  }
//  else //大于0
//  {
//     //*************** 电机2 *******************   //右
//     FTM_PWM_ChangeDuty(MotorBF,  0); 
//     FTM_PWM_ChangeDuty(MotorBZ, PWM_GiveR);    
//             
//  } 
//  
//  serr_pre = serr_last;//对前一次误差赋值
//  serr_last = serr_now ;//对上一次误差赋值
//  
//}



//int16_t get_diff(int16_t err_in)
//{
//    int16_t diff_PWM=0;
//    
//    int16_t diff_err=0;
//	  static int16_t diff_lasterr=0;
//    
////  diff_err = duo_PWM - DuoJi_MID;
//    //P_C = 9*Duo_P;
//	Diff_P_temp=Diff_P;
////	if(Road_flag==3)Diff_P_temp=Diff_P+3;
//    diff_err = err_in;
//    diff_PWM = Diff_P_temp *  diff_err + Diff_D * ( diff_err - diff_lasterr);
//    
////    if(diff_PWM>4000)
////    {
////       diff_PWM = 4000;
////    }
////    
////    if(diff_PWM < -4000)
////    {
////       diff_PWM = -4000 ;
////    }
//    diff_lasterr = diff_err;
//    return diff_PWM;   
//}
//int get_diff(float err_in)
//{
//	LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//    int diff_PWM=0;
//    
//    int diff_err=0;
//	  static int diff_lasterr=0;
//    
//	if(Lcr[Turn_row_temp].Center!=255)
//	{
//	 if((Road_flag!=11||Road_flag!=12)&&fabs(err_in)>=8)  //直道情况下与障碍情况下不加主动差速
//	{
//		diff_PWM = Diff_Speed_Duoji(err_in);   //根据中值偏差计算两个电机的输出偏差
//		if(diff_PWM>=diff_pwm_max)
//			diff_PWM=diff_pwm_max;
//		if(diff_PWM<=-diff_pwm_max)
//			diff_PWM=-diff_pwm_max;
//	} 
//}
//	else
//	{
//		diff_PWM=diff_lasterr;
//	}
//		diff_lasterr=diff_PWM;
//    return diff_PWM;   
//}
 int dongtai_P(int a)
 {
	 int b=0;
		switch(a%5)
		{ 
			case 0 : b= 0;break;
			case 1 : b= 0;break;  
			case 2 : b= Diff_P-15;break;  
			case 3 : b= Diff_P-11;break;  
			case 4 : b= Diff_P-8;break;  
			case 5 : b= Diff_P-4;break;  
			case 6 : b= Diff_P;break;  
			case 7 : b= Diff_P;break;  
			case 8 : b= Diff_P;break;
//			deflat:b= Diff_P;
		}
		return b;
 }
 


 