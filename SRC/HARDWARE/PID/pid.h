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
	float SumError;	//����ۼ�	
	int32 LastError;	//Error[-1]
	int32 PrevError;	//Error[-2]	
	int32 LastData;	//Speed[-1]
} PID;

extern PID MOTOR_PID, Angle_PID, Ang_Vel_PID, Direct_PID, Turn_PID, Distance_PID;	//�������͵����PID�����ṹ��
extern float MOTOR[4], Angle[4], Ang_Vel[4], Direct[4], Turn[5][4], Distance[4];

// PID������ʼ��
void PID_Parameter_Init(PID *sptr);


// λ��ʽ��̬PID����
int32 PlacePID_Control(PID *sprt, float *PID, int32 NowPiont, int32 SetPoint);

// λ��ʽPID����
int32 PID_Realize(PID *sptr, float *PID, int32 NowData, int32 Point);

// ����ʽPID����
int32 PID_Increase(PID *sptr, float *PID, int32 NowData, int32 Point);	 
//��������ٶ�	 
#define MotorMaxDutyCycle 10000
#define MotorMinDutyCycle -10000
	 
int16_t PID_MotorA(int16_t MeasuredValue,int16_t Dir,int16_t SetPoint);
int16_t PID_MotorB(int16_t MeasuredValue,int16_t Dir,int16_t SetPoint);
int16_t PD_Engine(int16_t MeasuredValue,int16_t SetPoint);

#ifdef __cplusplus
}
#endif

#endif
