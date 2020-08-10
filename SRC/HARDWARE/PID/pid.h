#ifndef __PID_H
#define __PID_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "common.h"
#include "sys.h"
#define KP 0
#define KI 1
#define KD 2
#define KT 3
#define KB 4
#define KF 5

typedef struct PID
{
	float SumError;	//误差累计	
	int32 LastError;	//Error[-1]
	int32 PrevError;	//Error[-2]	
	int32 LastData;	//Speed[-1]
} PID;

extern PID MOTOR_PID, Angle_PID, Ang_Vel_PID, Direct_PID, Turn_PID, Distance_PID;	//定义舵机和电机的PID参数结构体
extern float MOTOR[4], Angle[4], Ang_Vel[4], Direct[4], Turn[5][4], Distance[4];

// PID参数初始化
void PID_Parameter_Init(PID *sptr);


// 位置式动态PID控制
int32 PlacePID_Control(PID *sprt, float *PID, int32 NowPiont, int32 SetPoint);

// 位置式PID控制
int32 PID_Realize(PID *sptr, float *PID, int32 NowData, int32 Point);

// 增量式PID控制
int32 PID_Increase(PID *sptr, float *PID, int32 NowData, int32 Point);	 
//电机极限速度	 
#define MotorMaxDutyCycle 10000
#define MotorMinDutyCycle -10000
	 
int16_t PID_MotorA(int16_t MeasuredValue,int16_t Dir,int16_t SetPoint);
int16_t PID_MotorB(int16_t MeasuredValue,int16_t Dir,int16_t SetPoint);
int16_t PD_Engine(int16_t MeasuredValue,int16_t SetPoint);

#ifdef __cplusplus
}
#endif

#endif
