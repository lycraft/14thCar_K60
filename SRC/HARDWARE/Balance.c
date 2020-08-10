#include "Balance.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "MPU6050.h"
#include "motor.h"
#include "PID.h"
#include "control.h"
#include "shuju.h"
#define pi 3.14159
extern uint8_t   camera_flag;        //DMA采图中断标志位 

S_FLOAT_XYZ 
	GYRO_Real,		// 陀螺仪转化后的数据
	ACC_Real,		// 加速度计转化后的数据
	Attitude_Angle,	// 当前角度
	Last_Angle,		// 上次角度
	Target_Angle;	// 目标角度
	

S_INT16_XYZ
	GYRO,			// 陀螺仪原始数据
	GYRO_Offset,	// 陀螺仪温飘
	GYRO_Last,		// 陀螺仪上次数据
	ACC, 			// 加速度计数据
	ACC_Offset,		// 加速度计温飘
	ACC_Last;		// 加速度计上次数据
S_INT32_XYZ
	Tar_Ang_Vel,	// 目标角速度
	Tar_Ang_Vel_Last;	// 上次目标角速度

int32
	Speed_Now = 0,	// 当前实际速度
	Speed_Min = 0,	// 左右最小速度
	Speed_Set = 0, 	// 目标设定速度
	Theory_Duty = 0,// 理论直立占空比
	Vel_Set = 0,	// 目标转向角速度
	Direct_Parameter = 0,// 转向系数
	Direct_Last = 0,
	Radius = 0;		// 目标转向半径倒数

//uchar Point = 80;
int32 Difference = 0;
	  
	  			/* 各种标志位，放定时器中进行时序控制 */
char Speed_Flag, Angle_Flag, Ang_Velocity_Flag, DMP_Flag;
/********************************************************/

void get_mpu(void)
{
MPU6050_GetData(&GYRO, &ACC);	// 读取陀螺仪数据
		
		Data_Filter();
}
// 频率控制在定时器中设置
void Balance_Control(void)
{
	
	if (Ang_Velocity_Flag)	// 直立角速度环	2ms
	{
		Ang_Velocity_Flag = 0;
		MPU6050_GetData(&GYRO, &ACC);	// 读取陀螺仪数据
		Data_Filter();					// 对原始数据滑动滤波	
		Ang_acc=-(float)(atan2(ACC_Real.X,-ACC_Real.Z ))*180.0/pi;
		if(Ang_acc>90)  Ang_acc =90;
		if(Ang_acc<-90)  Ang_acc =-90;
		if(Ang_acc>(Ang_gyro+7-Ang_gyro/88))  Ang_acc =Ang_gyro+7-Ang_gyro/88;
		if(Ang_acc<(Ang_gyro-7-Ang_gyro/88))  Ang_acc =Ang_gyro-7-Ang_gyro/88;
		mpu_y=(-GYRO_Real.Y*1.0-mpu_zero)*mpu_ratio/16.4;
	 
		Gyro_speed=(float)(mpu_y);		
		Ang_gyro=(float)(Ang_gyro+(float)(Gyro_speed));
		
		
		Ang_gyro=Ang_gyro+(Ang_acc -Ang_gyro)*0.055425;

		diviation_ang =Ang_gyro -Target_Angle.Y-tiaozheng;
		up_pwm=up_p*diviation_ang+ mpu_y*up_d;
		
	}
		if (Speed_Flag)		// 速度环	100ms
	{
		Speed_Flag = 0;
////												/* 速度环加到角度环上串级控制 */
		Target_Angle.Y = -PID_Realize(&MOTOR_PID, MOTOR, CarSpeed, Save_speed);	// 结果为放大100倍的目标角度
		Target_Angle.Y += (Ang_zero+wei)*100;	// 目标角度叠加在零点上(Ang_zero+wei)
		Target_Angle.Y = range_protect((int32)Target_Angle.Y, 2000, 4000+wei*100);	// -44 22
		Target_Angle.Y=Target_Angle.Y*0.01;

	}
	

}


