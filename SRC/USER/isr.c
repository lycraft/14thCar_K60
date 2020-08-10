#include "isr.h"
#include "dma.h"  
#include "Camera.h"
#include "pit.h"
#include "oled.h"
#include "key.h"
#include "extern.h"
#include "SEEKFREE_MT9V032.h"
#include "Handle.h"
#include "Balance.h"
#include "inv_mpu.h"
#include "myadc.h"
#include "drv_RF24L01.h"
extern uint8_t camera_flag;
extern uint8_t data[DMA_CAMERA_Length];
typedef uint8_t (*PP_Pixels)[Image_Width];        //定义一个第二维为Image_Width的二维指针类型
extern uint8_t Pixels[Image_Width*Image_Height];  //用于存储原始图像 
extern PP_Pixels P_Pixels;
extern uint8_t data[];          //DMA数据缓存
extern uint8_t threshold;
extern uint8_t podao;
extern uint8_t g_UartRxBuffer[ 4 ];
extern uint8_t 	last_threshold;
void PIT1_IRQHandler(void)
{
static uchar Time_400ms = 0;
	Time_400ms++;
	if (Time_400ms == 2)//50
	{
		Time_400ms = 0;
		RF24L01_Set_Mode( MODE_TX );		//发送模式
				g_UartRxBuffer[0]=run+10;
				g_UartRxBuffer[2]=duanlu;
				NRF24L01_TxPacket( g_UartRxBuffer, 4);		
	
	}
PIT_ClearITPendingBit(PIT1,PIT_IT_TIF);
}
void PIT0_IRQHandler(void)
{

	Save_speed=speed;	
	

	static uchar Time_10ms = 0;
	static uchar Time_100ms = 0;
	static uchar Time_200ms = 0;
	
	Time_10ms++;
	Time_100ms++;
	Time_200ms++;


	SpeedOutPeriod++; 
//	if(start==0 )
//	{Ang_zero=30;
//	BBB(1);}
//	else
//	{BBB(0);
//		Ang_zero=34;}
	if (Time_10ms == 1)
	{
		Ang_Velocity_Flag = 1;	// 角速度1ms获取一次
		Balance_Control();
	}
	if (Time_10ms == 2)
	{
		adc_read();
		DuanLu1=GPIO_ReadInputDataBit(PTD,12);
		DuanLu2=GPIO_ReadInputDataBit(PTD,13);
		tingche=GPIO_ReadInputDataBit(PTD,5);
		if(tingche==0&&start==1)
		{run=0;
			
		}
		
	//	if(run==2&&Ang_gyro<5)run=0;
	//	 SpeedCount ++ ; 
	
//		LeftSpeedSigma+=LeftSpeedSigma1;
//		RightSpeedSigma+=RightSpeedSigma1;
//		if(SpeedCount == 50)                                       //100ms速度控制计算
//			{	
//				SpeedCount=0;                                            //速度控制周期时间清零
//				SpeedOutPeriod=0;                                        //速度pwm拆分时间清零
//				SpeedCalculate();                                        //速度pwm计算		
//			}
	 SpeedCount ++ ; 
	 LeftSpeedSigma1 = (Get_EncoderB_PulseCount());                          //左轮速度采集
		  RightSpeedSigma1 = (Get_EncoderA_PulseCount());                        //右轮速度采集	//速度pwm拆分时间
		if(Get_EncoderA_Dir()==0)
		RightSpeedSigma1=-RightSpeedSigma1;
	if(Get_EncoderB_Dir()==1)
		LeftSpeedSigma1=-LeftSpeedSigma1;
//		LeftSpeedSigma+=LeftSpeedSigma1;
//		RightSpeedSigma+=RightSpeedSigma1;
		if(SpeedCount == 100)                                       //100ms速度控制计算
			{	
				SpeedCount=0;                                            //速度控制周期时间清零
				SpeedOutPeriod=0;                                        //速度pwm拆分时间清零
				SpeedCalculate();                                        //速度pwm计算		
			}
	
	}
	
	if (Time_200ms == 10)//50
	{
		Time_200ms = 0;
		 LeftSpeedSigma2 = (Get_EncoderA_PulseCount());                          //左轮速度采集
		  RightSpeedSigma2 = (Get_EncoderB_PulseCount());                        //右轮速度采集	//速度pwm拆分时间
		if(Get_EncoderA_Dir()==0)
		LeftSpeedSigma2=-LeftSpeedSigma2;
	if(Get_EncoderB_Dir()==1)
		RightSpeedSigma2=-RightSpeedSigma2;
		if(LeftSpeedSigma2 > Car_Left_Speed + 100)           //速度变化率限幅
		LeftSpeedSigma2 = Car_Left_Speed + 100;
	else if(LeftSpeedSigma2 < Car_Left_Speed - 100)
		LeftSpeedSigma2 = Car_Left_Speed -100;
	if(RightSpeedSigma2 > Car_Right_Speed + 100)
		RightSpeedSigma2 = Car_Right_Speed + 100;
	else if(RightSpeedSigma2 < Car_Right_Speed - 100)
		RightSpeedSigma2 = Car_Right_Speed - 100;
	
	CarSpeed2 = (LeftSpeedSigma2 + RightSpeedSigma2) *0.5; //当前速度
	Car_Left_Speed2 = LeftSpeedSigma2;
	Car_Right_Speed2 = RightSpeedSigma2;                             
	LeftSpeedSigma2 = 0;
	RightSpeedSigma2 = 0;	
//				 SpeedCount ++ ; 

//		if(SpeedCount == 10)                                       //100ms速度控制计算
//			{	
//				SpeedCount=0;                                            //速度控制周期时间清零
//				SpeedOutPeriod=0;                                        //速度pwm拆分时间清零
//				SpeedCalculate();                                        //速度pwm计算		
//			}
	}
//	if (Time_100ms == 100)//50
//	{
//		Time_100ms = 0;
//			
//		Speed_Flag = 1;	// 速度100ms控制一次
//	}
	if (Time_10ms == 4)
	{
		
		if(run==1)
		State_Analyze();
		Electronic_diff();
	}
	
	if (Time_10ms == 5)Time_10ms=0;
	
	PWM_Speed = SpeedPWMOut(Speed,Last_Speed,SpeedOutPeriod);      //速度pwm拆分
	//up_pwm=0;
	//PWM_Speed=0;
	if(bianxing==1)
	{
		up_pwm=0;
	PWM_Speed=0;
		}
	shuduz=up_pwm+PWM_Speed*0.6+speed_dir_left;
	shuduy=up_pwm+PWM_Speed*0.6+speed_dir_right;		
		
	if(run==1)	
	{	
	 motor_speed_zhili(-shuduz,-shuduy,9000,-9000);
	}
	if(run==0)
	{
		FTM_PWM_ChangeDuty(MotorAZ,0);
		FTM_PWM_ChangeDuty(MotorAF,0);
		FTM_PWM_ChangeDuty(MotorBZ,0);
		FTM_PWM_ChangeDuty(MotorBF,0);}
		//bluetooth_sent();
		if(run==2)
		{
	PID_LeftSpeed.setPoint = 0;
		PID_RightSpeed.setPoint = 0;
		Left_SpeedControl(Car_Left_Speed2);
		Right_SpeedControl(Car_Right_Speed2);
		}
	PIT_ClearITPendingBit(PIT0,PIT_IT_TIF);
}
void DMA0_IRQHandler(void)
{	
		uint8_t i,j;
		uint8_t dots[2]={1,0};

//	if(camera_flag==0)
	{
 	threshold=otsuThreshold( 160,  70);
		//threshold=60;
	//	if(duanlu==1&&duanyu==0)duanyu=threshold;
		if(threshold>(10+last_threshold))
			threshold=(10+last_threshold);
		if(threshold<(last_threshold-10))
			threshold=(last_threshold-10);
		if(duanlu==1||duanlu==3)threshold=150;
		
		//threshold=80;
		for(i=0;i<70;i++)
			{

//		for(j=0;j<20;j++)  
//				{
//					P_Pixels[i][j*8] = dots[(data[i*160+j*8]) >threshold?0:1];
//					P_Pixels[i][j*8+1] = dots[(data[i*160+j*8+1]) >threshold?0:1];
//					P_Pixels[i][j*8+2] = dots[(data[i*160+j*8+2]) >threshold?0:1];
//					P_Pixels[i][j*8+3] = dots[(data[i*160+j*8+3]) >threshold?0:1];
//					P_Pixels[i][j*8+4] = dots[(data[i*160+j*8+4]) >threshold?0:1];
//					P_Pixels[i][j*8+5] = dots[(data[i*160+j*8+5]) >threshold?0:1];
//					P_Pixels[i][j*8+6] = dots[(data[i*160+j*8+6]) >threshold?0:1];
//					P_Pixels[i][j*8+7] = dots[(data[i*160+j*8+7]) >threshold?0:1];
//					
//				
//				}
				    for(j=0;j<160;j++)    
                 {
                    

					  P_Pixels[i][j] = dots[(data[i*160+j]) >threshold?0:1];
                 }

			} 
			last_threshold=threshold;
				camera_flag=1;
		}
			 DMA_ClearITPendingBit(DMA0,DMA_IT_MAJOR,DMA_CH0);
}


void PORTA_IRQHandler(void) 
{ 	 

  if(GPIO_GetITStates ( PTA, GPIO_Pin_26 )==1)
	{
	    GPIO_ClearITPendingBit(PTA,GPIO_Pin_26);		
		 DMA0->TCD[DMA_CH0].CITER_ELINKNO = DMA_CITER_ELINKNO_CITER(DMA_CAMERA_Length);  //当前主循环次数 当前循环次数耗尽后再次加载起始主循环次数
    DMA0->TCD[DMA_CH0].BITER_ELINKNO = DMA_BITER_ELINKNO_BITER(DMA_CAMERA_Length);  //起始主循环次数

    DMA0->TCD[DMA_CH0].SADDR = (uint32_t)&PTB->PDIR;                           // 设置  源地址
	    DMA_SetEnableReq(DMA_CH0,ENABLE); 
			
			DMA0->TCD[DMA_CH0].DADDR = (uint32_t)data;   	    
  }
}
/********************按键中断函数（C）***********************/	
void PORTC_IRQHandler(void)    //
{
    IT_KeyScan();//中断按键检测
}		


		   
void UART3_RX_TX_IRQHandler(void)
{
    if(UART3->S1 & UART_S1_RDRF_MASK)                                     //接收数据寄存器满
    {
        //用户需要处理接收数据
		
        mt9v032_cof_uart_interrupt();
    }
    if(UART3->S1 & UART_S1_TDRE_MASK )                                    //发送数据寄存器空
    {
        //用户需要处理发送数据

    }
}

