#ifndef __HANDLE_H__
#define __HANDLE_H__
#include "stdint.h"
#include "control.h"
#include "extern.h"

#include "common.h"
//�ⲿ��������
extern uint8 screen_mid;
extern uchar Foresight;


extern uchar Mid_Count;
extern uchar Point_Mid;
extern uchar Turn_Left, Turn_Right;
extern uchar Foresight_Left, Foresight_Right;				//ǰհ���ұ߽缫ֵ
extern uchar Starting_Line_Flag;							//�����߱�־λ

//��������
uint8_t otsuThreshold(uint16 col, uint16 row);
void tar_speed(void);
 double value_k(double x1, double y1, double x2, double y2);//б�ʼ���K��x1,y1,x2,y2)
uint8_t Pro_value_byte(int value);   //��ֵԽ�籣������ (byte��)
void Least_Square_Method(uint8_t BasedLine, uint8_t FinalLine); //��С���˷�
 uint8_t Centerline_kalman(uint8_t data_now, uint8_t data_last);//���߿������˲�
 void Centerline_kalman_deal(void);//���߿������˲�
uint8_t Fabs(int data);
float Center_variance(uint8_t line); //ÿ���е�ƫ��ķ���
void Small_S_road_deal(void); //СS�䴦��
void Image_Init(void);//��ÿ��ͼ��������������Ҫ��ʼ���ı�����ʼ�� 
 float position_filter(void);
uchar Image_GetLine(uchar *data);	//��ȡ�����ұ߽���
void First_Line_Add(uchar *data);	//���ڴ����һ���Ҳ�������������
uchar Point_Handle(void);			//����·���ֻʹ�ü򵥼�Ȩ�㷨��֤�ȶ�����
uchar Point_Weight(void);			//ʹ�ü�Ȩƽ����ȡĿ�������
void Point_Scan(void);				//ѡȡĿ���
char Error_Transform(uchar Data, uchar Set);
int32 Curvature_Transform(uchar Now, uchar Point);	//����ת��������Ŵ�1000��
int32 Angle_Transform(uchar *data);	//����Ŀ��Ƕ�
void Mid_Filtering(uchar *data);	//�����˲�
uint32 Wave_Filtering(uint32 data, uchar Deep);//�˲�����
double Slope_Display(uchar *data);	//б������ʾ
void Mid_Line_Repair(uchar count, uchar *data);		 //�����޸�
void Left_Line_Repair(uchar y, uchar x, uchar *data);//��߽粹������
void Right_Line_Repair(uchar y, uchar x, uchar *data);//�ұ߽粹������
uchar Traversal_Left(uchar *data);	//������߽�, �������ұ߽�ľ���
uchar Traversal_Right(uchar *data); //�ұ����߽�, �������ұ߽�ľ���
void Traversal_Mid_Line(uchar i, uchar *data);								//���м�������ɨ��߽磬��¼���ұ߽�
void Traversal_Left_Side(uchar i, uchar *data);								//��ǰһ����߽翪ʼɨ����߽�
void Traversal_Right_Side(uchar i, uchar *data);							//��ǰһ���ұ߽翪ʼɨ���ұ߽�
void Traversal_Side_Line(uchar i, uchar *data);								//���������м�Ѱ�ұ߽磬���ڳ��ָ��ŵ������ʹ��
void Traversal_Left_Line(uchar i, uchar *data, uchar *Left_Line, uchar *Right_Line);//������߽�, ��¼���ұ߽�
void Traversal_Right_Line(uchar i, uchar *data, uchar *Left_Line, uchar *Right_Line);//�ұ����߽�, ��¼���ұ߽�
void image_processe(void);
void img_extract(uint8 *dst, uint8 *src, uint32 srclen);        //��ѹ �̡̡�
void img_recontract(uint8 *dst, uint8 *src, uint32 srclen);     //ѹ���̡̡�
					//ͼ����Դ  //����Ŀ���ַ  //ͼ����
void img_getline(uint8 *dst, uint8 *src, uint32 srclen);        //��ȡ�߽��ߡ̡̡�
int32 range_protect(int32 duty, int32 min, int32 max);//�޷�����
void SignalProcess(void);
 void ImageProcess(void);
  void FieldProcess(void);
#endif



