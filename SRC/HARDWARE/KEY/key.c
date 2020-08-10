#include "key.h"
#include "delay.h"
/***************************************************************
功能：配置每个按键的端口、管脚和它的输入输出模式
形参：GPIOx: PTA/PTB/PTC/PTD/PTE
			GPIO_Pin: 0~31 数字
			Mode: Mode等于1时为上拉输入模式，
						Mode等于0时为下拉输入模式。

****************************************************************/
IRQn_Type get_IRQn(GPIO_InitTypeDef* GPIO_InitStruct);//获取中断号
uint8_t Image_Mode_Key_Flag=0;//用作中断标记

void MyKey_Pin_Init(GPIO_Type *GPIOx,uint16_t GPIO_Pin,int Mode)
{
	GPIO_InitTypeDef GPIO_InitStruct1;

	GPIO_InitStruct1.GPIOx = GPIOx;                           
	GPIO_InitStruct1.GPIO_InitState = Bit_RESET;          //初始设为高电平     
	GPIO_InitStruct1.GPIO_IRQMode = GPIO_IT_DISABLE;      //不时能中断
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin;                  
	if(Mode == 0)
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPU;					//设为上拉输入模式
	else
		GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_IPD;					//设为下拉输入模式

	GPIO_Init(&GPIO_InitStruct1);                       	//执行GPIO初始化	
}

void IT_Image_Mode_Key(void)//模式切换中断按键
{
    GPIO_InitTypeDef GPIO_Key;
  
    //---------中断按键1---------
    GPIO_Key.GPIOx = Key_Real_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//边沿触发
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Real_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//开启中断
    //---------中断按键2---------
    GPIO_Key.GPIOx = Key_Fit_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//边沿触发
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Fit_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//开启中断
    //---------中断按键3---------
    GPIO_Key.GPIOx = Key_Par_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//边沿触发
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Par_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//开启中断
    //---------中断按键4---------
    GPIO_Key.GPIOx = Key_Play_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//边沿触发
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Play_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//开启中断
    //---------中断按键5---------
    GPIO_Key.GPIOx = Key_Up_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//边沿触发
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Up_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//开启中断
    //---------中断按键6---------
    GPIO_Key.GPIOx = Key_Down_Port;
	GPIO_Key.GPIO_InitState = Bit_RESET;
	GPIO_Key.GPIO_IRQMode = Image_Mode_Key_Mode;//边沿触发
	GPIO_Key.GPIO_Mode = GPIO_Mode_IPU;     
	GPIO_Key.GPIO_Pin = Key_Down_Pin;
  	GPIO_Init(&GPIO_Key);
    NVIC_EnableIRQ(get_IRQn(&GPIO_Key));//开启中断
    
    
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

       GPIO_ClearITPendingBit(Key_Real_Port,Key_Real_Pin);     //清除标志位
    }
    else if(GPIO_GetITStates(Key_Fit_Port,Key_Fit_Pin))
    {
       Image_Mode_Key_Flag=2;

       GPIO_ClearITPendingBit(Key_Fit_Port,Key_Fit_Pin);     //清除标志位
    }
    else if(GPIO_GetITStates(Key_Par_Port,Key_Par_Pin))
    {
       Image_Mode_Key_Flag=3;

       GPIO_ClearITPendingBit(Key_Par_Port,Key_Par_Pin);     //清除标志位
    }
    else if(GPIO_GetITStates(Key_Play_Port,Key_Play_Pin))
    {
       Image_Mode_Key_Flag=4;

       GPIO_ClearITPendingBit(Key_Play_Port,Key_Play_Pin);     //清除标志位
    }
    else if(GPIO_GetITStates(Key_Up_Port,Key_Up_Pin))
    {
       Image_Mode_Key_Flag=5;

       GPIO_ClearITPendingBit(Key_Up_Port,Key_Up_Pin);     //清除标志位
    }
    else if(GPIO_GetITStates(Key_Down_Port,Key_Down_Pin))
    {
      Image_Mode_Key_Flag=6;

       GPIO_ClearITPendingBit(Key_Down_Port,Key_Down_Pin);     //清除标志位
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
	
	MyKey_Pin_Init(MyKey1_Port,MyKey1_Pin,GPIO_Key_Mode);			//配置key1键
	MyKey_Pin_Init(MyKey2_Port,MyKey2_Pin,GPIO_Key_Mode);			//配置key2键
	MyKey_Pin_Init(MyKey3_Port,MyKey3_Pin,GPIO_Key_Mode);			//配置key3键
	MyKey_Pin_Init(MyKey4_Port,MyKey4_Pin,GPIO_Key_Mode);			//配置key4键
	MyKey_Pin_Init(MyKey5_Port,MyKey5_Pin,GPIO_Key_Mode);			//配置key5键
	MyKey_Pin_Init(MyKey6_Port,MyKey6_Pin,GPIO_Key_Mode);			//配置key6键
	
	
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
	if(GPIO_ReadInputDataBit(MyKey1_Port,MyKey1_Pin) == GPIO_Key_Mode)		//读key1对应的管脚，看是否有键按下
	{											
		DelayMs(delay_times);																												//消抖
		if(GPIO_ReadInputDataBit(MyKey1_Port,MyKey1_Pin) == GPIO_Key_Mode)	//读key1对应的管脚，看是否有键按下
		{
			return MyKey1;																													//返回1，对应1键被按下
		}
	}
	
		//同上
	if(GPIO_ReadInputDataBit(MyKey2_Port,MyKey2_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey2_Port,MyKey2_Pin) == GPIO_Key_Mode)
		{
			return MyKey2;
		}
	}
	
	//同上
	if(GPIO_ReadInputDataBit(MyKey3_Port,MyKey3_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey3_Port,MyKey3_Pin) == GPIO_Key_Mode)
		{
			return MyKey3;
		}
	}
	
	//同上	
	if(GPIO_ReadInputDataBit(MyKey4_Port,MyKey4_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey4_Port,MyKey4_Pin) == GPIO_Key_Mode)
		{
			return MyKey4;
		}
	}
	
	//同上
	if(GPIO_ReadInputDataBit(MyKey5_Port,MyKey5_Pin) == GPIO_Key_Mode)
	{
		DelayMs(delay_times);
		if(GPIO_ReadInputDataBit(MyKey5_Port,MyKey5_Pin) == GPIO_Key_Mode)
		{
			return MyKey5;
		}
	}
	
	//同上
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




