#include "key.h"
#include "delay.h"
/***************************************************************
���ܣ�����ÿ�������Ķ˿ڡ��ܽź������������ģʽ
�βΣ�GPIOx: PTA/PTB/PTC/PTD/PTE
			GPIO_Pin: 0~31 ����
			Mode: Mode����1ʱΪ��������ģʽ��
						Mode����0ʱΪ��������ģʽ��

****************************************************************/
IRQn_Type get_IRQn(GPIO_InitTypeDef* GPIO_InitStruct);//��ȡ�жϺ�
uint8_t Image_Mode_Key_Flag=0;//�����жϱ��

void MyKey_Pin_Init(GPIO_Type *GPIOx,uint16_t GPIO_Pin,int Mode)
{
	GPIO_InitTypeDef GPIO_InitStruct1;

	GPIO_InitStruct1.GPIOx = GPIOx;                           
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;          //��ʼ��Ϊ�ߵ�ƽ     
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;      //��ʱ���ж�
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin;                  
	if(Mode == 0)
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;					//��Ϊ��������ģʽ
	else
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;					//��Ϊ��������ģʽ

	GPIO_Init(&GPIO_InitStruct1);                       	//ִ��GPIO��ʼ��	
}

void IT_Image_Mode_Key(void)//ģʽ�л��жϰ���
{
    GPIO_InitTypeDef GPIO_Key;
  
    //---------�жϰ���1---------
    GPIO_Key.GPIOx = Key_Real_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//���ش���
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Real_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//�����ж�
    //---------�жϰ���2---------
    GPIO_Key.GPIOx = Key_Fit_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//���ش���
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Fit_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//�����ж�
    //---------�жϰ���3---------
    GPIO_Key.GPIOx = Key_Par_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//���ش���
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Par_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//�����ж�
    //---------�жϰ���4---------
    GPIO_Key.GPIOx = Key_Play_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//���ش���
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Play_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//�����ж�
    //---------�жϰ���5---------
    GPIO_Key.GPIOx = Key_Up_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//���ش���
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Up_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//�����ж�
    //---------�жϰ���6---------
    GPIO_Key.GPIOx = Key_Down_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//���ش���
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Down_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//�����ж�
    
    
}

uint8_t get_Image_Mode_Key(void)
{
    uint8_t Key_Value=Image_Mode_Key_Flag;

    if(Key_Value)
    {
       Image_Mode_Key_Flag=0;   

       return Key_Value;
    }   
 
    return 0;
}

void IT_KeyScan(void)
{

    if(GPIO_GetITStates(Key_Real_Port,Key_Real_Pin))
    {
       Image_Mode_Key_Flag=1;

       GPIO_ClearITPendingBit(Key_Real_Port,Key_Real_Pin);     //�����־λ
    }
    else if(GPIO_GetITStates(Key_Fit_Port,Key_Fit_Pin))
    {
       Image_Mode_Key_Flag=2;

       GPIO_ClearITPendingBit(Key_Fit_Port,Key_Fit_Pin);     //�����־λ
    }
    else if(GPIO_GetITStates(Key_Par_Port,Key_Par_Pin))
    {
       Image_Mode_Key_Flag=3;

       GPIO_ClearITPendingBit(Key_Par_Port,Key_Par_Pin);     //�����־λ
    }
    else if(GPIO_GetITStates(Key_Play_Port,Key_Play_Pin))
    {
       Image_Mode_Key_Flag=4;

       GPIO_ClearITPendingBit(Key_Play_Port,Key_Play_Pin);     //�����־λ
    }
    else if(GPIO_GetITStates(Key_Up_Port,Key_Up_Pin))
    {
       Image_Mode_Key_Flag=5;

       GPIO_ClearITPendingBit(Key_Up_Port,Key_Up_Pin);     //�����־λ
    }
    else if(GPIO_GetITStates(Key_Down_Port,Key_Down_Pin))
    {
      Image_Mode_Key_Flag=6;

       GPIO_ClearITPendingBit(Key_Down_Port,Key_Down_Pin);     //�����־λ
    }

}




IRQn_Type get_IRQn(GPIO_InitTypeDef* GPIO_InitStruct)
{
  GPIO_Type *GPIOx = NULL; 
  GPIOx = GPIO_InitStruct->GPIOx;
	switch((uint32_t)GPIOx)
	{
		case PTA_BASE:return PORTA_IRQn;
	    case PTB_BASE:return PORTB_IRQn;
	    case PTC_BASE:return PORTC_IRQn;
	    case PTD_BASE:return PORTD_IRQn;
	    case PTE_BASE:return PORTE_IRQn;
	    default :return PORTA_IRQn;
    }
}



void MyKey_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct1;
	
	MyKey_Pin_Init(MyKey1_Port,MyKey1_Pin,GPIO_Key_Mode);			//����key1��
	MyKey_Pin_Init(MyKey2_Port,MyKey2_Pin,GPIO_Key_Mode);			//����key2��
	MyKey_Pin_Init(MyKey3_Port,MyKey3_Pin,GPIO_Key_Mode);			//����key3��
	MyKey_Pin_Init(MyKey4_Port,MyKey4_Pin,GPIO_Key_Mode);			//����key4��
	MyKey_Pin_Init(MyKey5_Port,MyKey5_Pin,GPIO_Key_Mode);			//����key5��
	MyKey_Pin_Init(MyKey6_Port,MyKey6_Pin,GPIO_Key_Mode);			//����key6��
	
	
	GPIO_InitStruct1.GPIOx = LEFT_LIGHT_PORT ;
	GPIO_InitStruct1.GPIO_Pin =LEFT_LIGHT_PIN ;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(&GPIO_InitStruct1);
	
	GPIO_InitStruct1.GPIOx = RIGHT_LIGHT_PORT ;
	GPIO_InitStruct1.GPIO_Pin =RIGHT_LIGHT_PIN ;
	GPIO_InitStruct1.GPIO_InitState = Bit_SET;
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(&GPIO_InitStruct1);
}


char KeyScan(void)
{
	if(GPIO_ReadInputDataBit(MyKey1_Port,MyKey1_Pin) == GPIO_Key_Mode)		//��key1��Ӧ�Ĺܽţ����Ƿ��м�����
	{											
		DelayMs(delay_times);																												//����
		if(GPIO_ReadInputDataBit(MyKey1_Port,MyKey1_Pin) == GPIO_Key_Mode)	//��key1��Ӧ�Ĺܽţ����Ƿ��м�����
		{
			return MyKey1;																													//����1����Ӧ1��������
		}
	}
	
		//ͬ��
	if(GPIO_ReadInputDataBit(MyKey2_Port,MyKey2_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey2_Port,MyKey2_Pin) == GPIO_Key_Mode)
		{
			return MyKey2;
		}
	}
	
	//ͬ��
	if(GPIO_ReadInputDataBit(MyKey3_Port,MyKey3_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey3_Port,MyKey3_Pin) == GPIO_Key_Mode)
		{
			return MyKey3;
		}
	}
	
	//ͬ��	
	if(GPIO_ReadInputDataBit(MyKey4_Port,MyKey4_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey4_Port,MyKey4_Pin) == GPIO_Key_Mode)
		{
			return MyKey4;
		}
	}
	
	//ͬ��
	if(GPIO_ReadInputDataBit(MyKey5_Port,MyKey5_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey5_Port,MyKey5_Pin) == GPIO_Key_Mode)
		{
			return MyKey5;
		}
	}
	
	//ͬ��
	if(GPIO_ReadInputDataBit(MyKey6_Port,MyKey6_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey6_Port,MyKey6_Pin) == GPIO_Key_Mode)
		{
			return MyKey6;
		}
	}
	

	return 0;
	
}




