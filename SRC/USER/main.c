#include "sys.h"
#include "uart.h"
#include "Camera.h"
#include "oled_display.h"
#include "oled.h"
#include "sccb.h"
#include "delay.h"
#include "pit.h"
#include "menu.h"
#include "data_sent.h"
#include "data_sd.h"
#include "key.h"
#include "control.h"
#include "extern.h"
#include "motor.h"
#include "SEEKFREE_MT9V032.h"
#include "SEEKFREE_MPU6050.h"
#include "MK60DN10_cmt.h"
#include "myadc.h"
#include "Handle.h"
#include "Balance.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "MPU6050.h"
#include "common.h"
#include "drv_RF24L01.h"
#include "S_SPI.h"
#include "image_processe.h"
#include "shuju.h"

/*舵机控制系数*/
float Engine_Kp_R=550;//
float Engine_Kd_R=13.0;//
float Engine_Kp_temp;
float Engine_Kd_temp;



//计数变量
int32 EncoderA_Cnt;//编码器A脉冲计数  右轮
int32 EncoderB_Cnt;//编码器B脉冲计数  左轮


//DMA计数传输变量
uint8_t DMA_Temp;

/****************************************/
extern uint8_t g_UartRxBuffer[ 4 ];

/********************上位机**********************************/
extern Data_Type *Sent_Data;
Data_Type DATA_ALL;
uint16_t  h;
uint8_t *P;

/******************** 菜单 **********************************/  
struct ModeStruct Mode;//开关模式    
uint16_t MODE=0; //模式选择 
uint32_t Mode_Temp=0;//模式缓存
uint16_t SD_ALL_WT_Count=0;
int All_Temp_i=0;//全局临时变量


/******************** CCD摄像头 **********************************/  
uint8_t   Pixels[Image_Width*Image_Height];  //用于存储原始图像 
typedef uint8_t (*PP_Pixels)[Image_Width];        //定义一个第二维为Image_Width的二维指针类型
PP_Pixels P_Pixels=(PP_Pixels)Pixels;        //一维数组当二维数组用
uint8_t   data [DMA_CAMERA_Length];          //DMA数据缓存
uint8_t 	threshold=0x80;
uint8_t 	last_threshold=0x80;
uint8_t   camera_flag;        //DMA采图中断标志位 

uint8_t RowNum;
int main(void)
{

		SystemClockSetup(ClockSource_EX50M,CoreClock_180M);
	PID_LeftSpeed_Init(10,0,50,0);//电机PID初始化
	PID_RightSpeed_Init(10,0,50,0);//	
		PID_Parameter_Init(&MOTOR_PID);		// 速度环PID参数初始化	 
		MyKey_Init();           //按键初始化 
		DelayInit();
		camera_init();
		Camera_Init();
		DisableInterrupts();
		OLED_Init();
		Motor_Init();
		myadc_init();
		Encoder_Init();
		LED_Init();
		Data_Uart_Init();       //读图上位机	初始化 
	//	UART_DebugPortInit(UART4_RX_C14_TX_C15,115200); //匿名上位机
	 
		INI_Flash_Init();          //Flash初始化
		 //SPI初始化
		drv_spi_init( );	
		//RF24L01引脚初始化
		NRF24L01_Gpio_Init( );	
		//检测nRF24L01
		NRF24L01_check( );			
		RF24L01_Init( );
		NrfData_UpLoad();         //初始化数据
		IIC_GPIOConfig();
		MPU6050_Init();
		Target_Angle.Y = (Ang_zero+wei);
	
		while (mpu_dmp_init());		// 初始化DMP
		MPU6050_Offset();
		
		
		 MODE=0;//设置默认模式	

		 Menu_Start: //goto标签
		
	 
		 GetMode();//获取模式
		 Menu_Init();//菜单初始化

		 SetMode();//设置Mode值

		if(Mode.Uart_Read_SD || Mode.Write_SD || Mode.OLED_Read_SD ) while(Data_SD_Init() != ESDHC_OK);//等待SD卡初始化成功

	   // if(Mode.INI_Read) {INI_Flash_Par_Read();MODE=0;(*((uint32_t *)&Mode))=0;goto Menu_Start; }//匹配参数读  9

	   // if(Mode.INI_Write) {INI_Flash_Par_Write();MODE=0;(*((uint32_t *)&Mode))=0;goto Menu_Start; }//匹配参数写 8 

		if(Mode.OLED_Image_Live) {IT_Image_Mode_Key();}//中断按键启动 1

		if(Mode.Uart_Read_SD) {Uart_Read_SD();} //读取SD卡信息 3

		if(Mode.OLED_Read_SD) {OLED_Read_SD();}//OLED显示SD卡的信息 4

		if(Mode.Write_SD) {Data_SD_WT_Init();run=1;}//写sd卡指令初始化 (存数据模式) 5
		//********定时停车*************//
		PIT_InitTypeDef PIT_InitStruct;
		PIT_InitStruct.PITx = PIT0;          //PIT0通道
		PIT_InitStruct.PIT_Interval = 1;   //定时周期10MS
		PIT_Init(&PIT_InitStruct);
		PIT_ITConfig(PIT0,PIT_IT_TIF,ENABLE);
		NVIC_EnableIRQ(PIT0_IRQn);
		  
		PIT_InitStruct.PITx = PIT1;          //PIT0通道
		PIT_InitStruct.PIT_Interval = 100;   //定时周期10MS
		PIT_Init(&PIT_InitStruct);
		PIT_ITConfig(PIT1,PIT_IT_TIF,ENABLE);
		NVIC_EnableIRQ(PIT1_IRQn);
		
		EnableInterrupts();//开启总中断

		NVIC_EnableIRQ(PORTA_IRQn);//打开场中断
		NVIC_Init(PORTA_IRQn, NVIC_PriorityGroup_4,1,2);	
		NVIC_Init(PIT0_IRQn, NVIC_PriorityGroup_4,0,2);
		NVIC_Init(DMA0_IRQn, NVIC_PriorityGroup_4,2,2);
	    NVIC_Init(PIT1_IRQn, NVIC_PriorityGroup_4,3,2);


	while(1)
		
	{
		
		if (Mode.OLED_Image_Live){OLED_Image_Live();}//OLED显示   
		if(camera_flag==1)
		{
			
			
		image_processe();
//		if(Huan_Road_flag!=0){BBB(1);}
//		else BBB(0);
		camera_flag=2;
				

       if(Mode.Read_Live) { UART_Send_Con();}//上传在线图像  DMA对时序无影响

      else if(Mode.Write_SD) {SD_ALL_WT_Count++;Data_SD_Save();}//存储SD信息
			
	  
		}

	}
}

void assert_failed(uint8_t* file, uint32_t line)
{
	//断言失败检测
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}


