#include "engine.h"
#include "ftm.h"
#include "extern.h"
#include "MK60DN10_cmt.h"
int16_t steer_sub=0;
void Engine_Init(void)
{
	FTM_InitTypeDef FTM_InitStruct1;
	
	FTM_InitStruct1.Frequency = Engine_Frequency;
	FTM_InitStruct1.FTMxMAP = Engine_Output;
	FTM_InitStruct1.FTM_Mode = FTM_Mode_EdgeAligned;
	FTM_InitStruct1.InitalDuty = Engine_InitialDutyCycle;
	FTM_Init(&FTM_InitStruct1);
}

void Engine_RightDeflection(uint8_t DeflectionValue)
{
	if(DeflectionValue >= Engine_MaxDeviationDutyCycle)
	{
		DeflectionValue = Engine_MaxDeviationDutyCycle;
	}
	FTM_PWM_ChangeDuty(Engine_Output,Engine_InitialDutyCycle - DeflectionValue);
}

void Engine_LeftDeflection(uint8_t DeflectionValue)
{
	if(DeflectionValue >= Engine_MaxDeviationDutyCycle)
	{
		DeflectionValue = Engine_MaxDeviationDutyCycle;
	}
	FTM_PWM_ChangeDuty(Engine_Output,Engine_InitialDutyCycle + DeflectionValue);
}

void Engine_CenterDeflection(void)
{
	FTM_PWM_ChangeDuty(Engine_Output,Engine_InitialDutyCycle);
}

void Engine_Deflection(int16_t deflection)//ÓÒ×ª¼õ×ó×ª¼Ó
{
	if(deflection >= 0)
	{
		if(deflection >= Engine_MaxDeviationDutyCycle)
		{
			deflection = Engine_MaxDeviationDutyCycle;
		}
	}
	else if(deflection < 0)
	{
		deflection = -deflection;
		if(deflection >= Engine_MaxDeviationDutyCycle)
		{
			deflection = Engine_MaxDeviationDutyCycle;
		}
		deflection = -deflection;
	}
	FTM_PWM_ChangeDuty(Engine_Output,Engine_InitialDutyCycle + deflection);
}





