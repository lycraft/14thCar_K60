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

/*�������ϵ��*/
float Engine_Kp_R=550;//
float Engine_Kd_R=13.0;//
float Engine_Kp_temp;
float Engine_Kd_temp;



//��������
int32 EncoderA_Cnt;//������A�������  ����
int32 EncoderB_Cnt;//������B�������  ����


//DMA�����������
uint8_t DMA_Temp;

/****************************************/
extern uint8_t g_UartRxBuffer[ 4 ];

/********************��λ��**********************************/
extern Data_Type *Sent_Data;
Data_Type DATA_ALL;
uint16_t  h;
uint8_t *P;

/******************** �˵� **********************************/  
struct ModeStruct Mode;//����ģʽ    
uint16_t MODE=0; //ģʽѡ�� 
uint32_t Mode_Temp=0;//ģʽ����
uint16_t SD_ALL_WT_Count=0;
int All_Temp_i=0;//ȫ����ʱ����


/******************** CCD����ͷ **********************************/  
uint8_t   Pixels[Image_Width*Image_Height];  //���ڴ洢ԭʼͼ�� 
typedef uint8_t (*PP_Pixels)[Image_Width];        //����һ���ڶ�άΪImage_Width�Ķ�άָ������
PP_Pixels P_Pixels=(PP_Pixels)Pixels;        //һά���鵱��ά������
uint8_t   data [DMA_CAMERA_Length];          //DMA���ݻ���
uint8_t 	threshold=0x80;
uint8_t 	last_threshold=0x80;
uint8_t   camera_flag;        //DMA��ͼ�жϱ�־λ 

uint8_t RowNum;
int main(void)
{

		SystemClockSetup(ClockSource_EX50M,CoreClock_180M);
	PID_LeftSpeed_Init(10,0,50,0);//���PID��ʼ��
	PID_RightSpeed_Init(10,0,50,0);//	
		PID_Parameter_Init(&MOTOR_PID);		// �ٶȻ�PID������ʼ��	 
		MyKey_Init();           //������ʼ�� 
		DelayInit();
		camera_init();
		Camera_Init();
		DisableInterrupts();
		OLED_Init();
		Motor_Init();
		myadc_init();
		Encoder_Init();
		LED_Init();
		Data_Uart_Init();       //��ͼ��λ��	��ʼ�� 
	//	UART_DebugPortInit(UART4_RX_C14_TX_C15,115200); //������λ��
	 
		INI_Flash_Init();          //Flash��ʼ��
		 //SPI��ʼ��
		drv_spi_init( );	
		//RF24L01���ų�ʼ��
		NRF24L01_Gpio_Init( );	
		//���nRF24L01
		NRF24L01_check( );			
		RF24L01_Init( );
		NrfData_UpLoad();         //��ʼ������
		IIC_GPIOConfig();
		MPU6050_Init();
		Target_Angle.Y = (Ang_zero+wei);
	
		while (mpu_dmp_init());		// ��ʼ��DMP
		MPU6050_Offset();
		
		
		 MODE=0;//����Ĭ��ģʽ	

		 Menu_Start: //goto��ǩ
		
	 
		 GetMode();//��ȡģʽ
		 Menu_Init();//�˵���ʼ��

		 SetMode();//����Modeֵ

		if(Mode.Uart_Read_SD || Mode.Write_SD || Mode.OLED_Read_SD ) while(Data_SD_Init() != ESDHC_OK);//�ȴ�SD����ʼ���ɹ�

	   // if(Mode.INI_Read) {INI_Flash_Par_Read();MODE=0;(*((uint32_t *)&Mode))=0;goto Menu_Start; }//ƥ�������  9

	   // if(Mode.INI_Write) {INI_Flash_Par_Write();MODE=0;(*((uint32_t *)&Mode))=0;goto Menu_Start; }//ƥ�����д 8 

		if(Mode.OLED_Image_Live) {IT_Image_Mode_Key();}//�жϰ������� 1

		if(Mode.Uart_Read_SD) {Uart_Read_SD();} //��ȡSD����Ϣ 3

		if(Mode.OLED_Read_SD) {OLED_Read_SD();}//OLED��ʾSD������Ϣ 4

		if(Mode.Write_SD) {Data_SD_WT_Init();run=1;}//дsd��ָ���ʼ�� (������ģʽ) 5
		//********��ʱͣ��*************//
		PIT_InitTypeDef PIT_InitStruct;
		PIT_InitStruct.PITx = PIT0;          //PIT0ͨ��
		PIT_InitStruct.PIT_Interval = 1;   //��ʱ����10MS
		PIT_Init(&PIT_InitStruct);
		PIT_ITConfig(PIT0,PIT_IT_TIF,ENABLE);
		NVIC_EnableIRQ(PIT0_IRQn);
		  
		PIT_InitStruct.PITx = PIT1;          //PIT0ͨ��
		PIT_InitStruct.PIT_Interval = 100;   //��ʱ����10MS
		PIT_Init(&PIT_InitStruct);
		PIT_ITConfig(PIT1,PIT_IT_TIF,ENABLE);
		NVIC_EnableIRQ(PIT1_IRQn);
		
		EnableInterrupts();//�������ж�

		NVIC_EnableIRQ(PORTA_IRQn);//�򿪳��ж�
		NVIC_Init(PORTA_IRQn, NVIC_PriorityGroup_4,1,2);	
		NVIC_Init(PIT0_IRQn, NVIC_PriorityGroup_4,0,2);
		NVIC_Init(DMA0_IRQn, NVIC_PriorityGroup_4,2,2);
	    NVIC_Init(PIT1_IRQn, NVIC_PriorityGroup_4,3,2);


	while(1)
		
	{
		
		if (Mode.OLED_Image_Live){OLED_Image_Live();}//OLED��ʾ   
		if(camera_flag==1)
		{
			
			
		image_processe();
//		if(Huan_Road_flag!=0){BBB(1);}
//		else BBB(0);
		camera_flag=2;
				

       if(Mode.Read_Live) { UART_Send_Con();}//�ϴ�����ͼ��  DMA��ʱ����Ӱ��

      else if(Mode.Write_SD) {SD_ALL_WT_Count++;Data_SD_Save();}//�洢SD��Ϣ
			
	  
		}

	}
}

void assert_failed(uint8_t* file, uint32_t line)
{
	//����ʧ�ܼ��
	UART_printf("assert_failed:line:%d %s\r\n",line,file);
	while(1);
}


