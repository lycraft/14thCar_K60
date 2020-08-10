#ifndef __BALANCE_H__
#define __BALANCE_H__
#include "common.h"


#define Zero_Angle  -63.10//-66.8//2.0f	// 蓝色电池
//#define Zero_Angle 22.0f	// 白色电池

extern S_FLOAT_XYZ 
	GYRO_Real,		// 陀螺仪转化后的数据
	ACC_Real,		// 加速度计转化后的数据
	Attitude_Angle,	// 当前角度 
	Last_Angle,		// 上次角度
	Target_Angle;	// 目标角度
	

extern S_INT16_XYZ
	GYRO,			// 陀螺仪原始数据
	GYRO_Offset,	// 陀螺仪温飘
	GYRO_Last,		// 陀螺仪上次数据
	ACC, 			// 加速度计数据
	ACC_Offset,		// 加速度计温飘
	ACC_Last;		// 加速度计上次数据
extern S_INT32_XYZ
	Tar_Ang_Vel,	// 目标角速度
	Tar_Ang_Vel_Last;	// 上次目标角速度

extern int32 
	Speed_Now,		// 当前实际速度
	Speed_Min,		// 左右最小速度
	Speed_Set, 		// 目标设定速度
	Vel_Set,		// 目标转向角速度
	Direct_Parameter,
	Radius;

extern uchar Point;
extern int32 Difference;

extern char Speed_Flag, Angle_Flag, Ang_Velocity_Flag, DMP_Flag;
void motor_control_zhili(void);
int32 range_protect(int32 duty, int32 min, int32 max);
void Balance_Control(void);
void Balance_Init(void);
void get_mpu(void);
#endif
