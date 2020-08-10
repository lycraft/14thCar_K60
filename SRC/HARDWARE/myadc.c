	#include "adc.h"
	#include "pdb.h"
	#include "dma.h"
	#include "MK60DZ10.h"
	#include "shuju.h"
	#include "myadc.h"
	uint32_t Result[4];
	
	
	void myadc_init(void)
	{
		ADC_InitTypeDef ADC_InitStruct;//申请结构体变量
		ADC_InitStruct . ADCxMap = ADC0_SE14_PC0;//使用引脚配置
		ADC_InitStruct . ADC_Precision = ADC_PRECISION_10BIT;//16 位转换精度
		ADC_InitStruct . ADC_TriggerSelect = ADC_TRIGGER_SW;//选择软件触发
		ADC_Init(&ADC_InitStruct);//调用初始化函数
	
		ADC_InitStruct . ADCxMap = ADC0_SE15_PC1;//使用引脚配置
		ADC_InitStruct . ADC_Precision = ADC_PRECISION_10BIT;//16 位转换精度
		ADC_InitStruct . ADC_TriggerSelect = ADC_TRIGGER_SW;//选择软件触发
		ADC_Init(&ADC_InitStruct);//调用初始化函数
		
		ADC_InitStruct . ADCxMap = ADC0_SE17_E24;//使用引脚配置
		ADC_InitStruct . ADC_Precision = ADC_PRECISION_10BIT;//16 位转换精度
		ADC_InitStruct . ADC_TriggerSelect = ADC_TRIGGER_SW;//选择软件触发
		ADC_Init(&ADC_InitStruct);//调用初始化函数
		
			ADC_InitStruct . ADCxMap = ADC0_SE4B_PC2;//使用引脚配置
		ADC_InitStruct . ADC_Precision = ADC_PRECISION_10BIT;//16 位转换精度
		ADC_InitStruct . ADC_TriggerSelect = ADC_TRIGGER_SW;//选择软件触发
		ADC_Init(&ADC_InitStruct);//调用初始化函数
		
			ADC_InitStruct . ADCxMap = ADC0_SE5B_PD1;//使用引脚配置
		ADC_InitStruct . ADC_Precision = ADC_PRECISION_10BIT;//16 位转换精度
		ADC_InitStruct . ADC_TriggerSelect = ADC_TRIGGER_SW;//选择软件触发
		ADC_Init(&ADC_InitStruct);//调用初始化函数
	
		

	}
	void adc_read(void)
{     
	    uint16_t sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,ave1=0,ave2=0,ave3=0,ave4=0,ave5=0;
	    uint8_t   time;
	    for(time = 0;time < 10;time++)
	{
	    sum1 += ADC_GetConversionValue(ADC0_SE14_PC0); 
	    sum2 += ADC_GetConversionValue(ADC0_SE15_PC1);
		sum3 += ADC_GetConversionValue(ADC0_SE4B_PC2);
		sum4 += ADC_GetConversionValue(ADC0_SE5B_PD1);
		sum5 += ADC_GetConversionValue(ADC0_SE17_E24);
	}
	    ave1 = sum1/10;
			ave2 = sum2/10;  
			ave3 = sum3/10; 
			ave4 = sum4/10;  
			ave5 = sum5/10;  	
		left_wdata = ave1;
		left_ldata = ave3;
		right_ldata= ave4;
		right_wdata = ave2;
		ADC_ceju=ave5;
	
}

