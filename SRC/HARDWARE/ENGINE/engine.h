#ifndef __ENGINE_H
#define __ENGINE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "sys.h"

//#define Engine_Output FTM2_CH0_PB18 //�������˿�
//#define Engine_Frequency 100 //100Hz
//#define Engine_InitialDutyCycle 1690 //�����ʼռ�ձ�(���������)
//#define Engine_MaxDeviationDutyCycle 150//������ƫ��ռ�ձ�

#define Engine_Output FTM0_CH7_PD7 //�������˿�
#define Engine_Frequency 100 //100Hz
#define Engine_InitialDutyCycle 660 //�����ʼռ�ձ�(�������)1180
#define Engine_MaxDeviationDutyCycle 80//������ƫ��ռ�ձ�
	 
void Engine_Init(void);
void Engine_RightDeflection(uint8_t DeflectionValue);
void Engine_LeftDeflection(uint8_t DeflectionValue);
void Engine_CenterDeflection(void);
void Engine_Deflection(int16_t deflection);

	 
#ifdef __cplusplus
}
#endif

#endif
