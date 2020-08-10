#include "Balance.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "MPU6050.h"
#include "motor.h"
#include "PID.h"
#include "control.h"
#include "shuju.h"
#define pi 3.14159
extern uint8_t   camera_flag;        //DMA��ͼ�жϱ�־λ 

S_FLOAT_XYZ 
	GYRO_Real,		// ������ת���������
	ACC_Real,		// ���ٶȼ�ת���������
	Attitude_Angle,	// ��ǰ�Ƕ�
	Last_Angle,		// �ϴνǶ�
	Target_Angle;	// Ŀ��Ƕ�
	

S_INT16_XYZ
	GYRO,			// ������ԭʼ����
	GYRO_Offset,	// ��������Ʈ
	GYRO_Last,		// �������ϴ�����
	ACC, 			// ���ٶȼ�����
	ACC_Offset,		// ���ٶȼ���Ʈ
	ACC_Last;		// ���ٶȼ��ϴ�����
S_INT32_XYZ
	Tar_Ang_Vel,	// Ŀ����ٶ�
	Tar_Ang_Vel_Last;	// �ϴ�Ŀ����ٶ�

int32
	Speed_Now = 0,	// ��ǰʵ���ٶ�
	Speed_Min = 0,	// ������С�ٶ�
	Speed_Set = 0, 	// Ŀ���趨�ٶ�
	Theory_Duty = 0,// ����ֱ��ռ�ձ�
	Vel_Set = 0,	// Ŀ��ת����ٶ�
	Direct_Parameter = 0,// ת��ϵ��
	Direct_Last = 0,
	Radius = 0;		// Ŀ��ת��뾶����

//uchar Point = 80;
int32 Difference = 0;
	  
	  			/* ���ֱ�־λ���Ŷ�ʱ���н���ʱ����� */
char Speed_Flag, Angle_Flag, Ang_Velocity_Flag, DMP_Flag;
/********************************************************/

void get_mpu(void)
{
MPU6050_GetData(&GYRO, &ACC);	// ��ȡ����������
		
		Data_Filter();
}
// Ƶ�ʿ����ڶ�ʱ��������
void Balance_Control(void)
{
	
	if (Ang_Velocity_Flag)	// ֱ�����ٶȻ�	2ms
	{
		Ang_Velocity_Flag = 0;
		MPU6050_GetData(&GYRO, &ACC);	// ��ȡ����������
		Data_Filter();					// ��ԭʼ���ݻ����˲�	
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
		if (Speed_Flag)		// �ٶȻ�	100ms
	{
		Speed_Flag = 0;
////												/* �ٶȻ��ӵ��ǶȻ��ϴ������� */
		Target_Angle.Y = -PID_Realize(&MOTOR_PID, MOTOR, CarSpeed, Save_speed);	// ���Ϊ�Ŵ�100����Ŀ��Ƕ�
		Target_Angle.Y += (Ang_zero+wei)*100;	// Ŀ��Ƕȵ����������(Ang_zero+wei)
		Target_Angle.Y = range_protect((int32)Target_Angle.Y, 2000, 4000+wei*100);	// -44 22
		Target_Angle.Y=Target_Angle.Y*0.01;

	}
	

}


