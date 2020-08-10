#ifndef __OLED_IMAGE_H__
#define __OLED_IMAGE_H__

#ifdef __cplusplus
	extern "C" {
#endif
		
#include "Camera.h"

#define Image_X_Rotate_Mode  ON  //ͼ��X����ת180��
#define Image_Y_Rotate_Mode  ON //ͼ��Y����ת180��
#define Image_XSub           1  //X��������ֵ  �Ǹ������������ı�Ե����
#define Image_YSub           1  //Y��������ֵ  �Ǹ������������ı�Ե����
#define Image_RColor_Mode  WhiteShow  //ԭͼ��ɫ���   
#define Image_FColor_Mode  BlackShow  //��ͼ��ɫ���        
        
#define Shift  1 

typedef enum
{  
  BlackShow=0 ,            //�����װ�
  WhiteShow =1,           //�ڰ�����   
}ColorMode;        
        



        
//-------------------------------------Һ����ʾ����(Ϊ�˼ӿ�Ч��)-------------------------------------------------------
#define OLED_SET_CMD(cmd)       OLED_DC_OL;OLED_D0_OL; k=8;     \
                                 while (k --)                   \
                                {                               \
                                  if (cmd & 0x80)               \
                                  {                             \
                                    OLED_D1_OH;                 \
                                  }                             \
                                  else                          \
                                  {                              \
                                    OLED_D1_OL;                  \
                                  }                              \
                                  OLED_D0_OH;                    \
                                  OLED_D0_OL;                    \
                                  cmd <<= 1;                     \
                                } 	        
        
        
        
        
void  OLED_Real_Image_Dispaly(void);       
void  OLED_Fit_Image_Dispaly(void);//Һ������ʾ��ͼ�� 

void OLED_Image_Dispaly(ColorMode Mode);        
void OLED_Lcr_Display(ColorMode Mode);      
void OLED_Par_Dispaly_Host(int Par_Page);//��ʾ���� ����       
void OLED_Par_Dispaly_Live(int Par_Page);//��ʾ���� ����        
void OLED_Image_Live(void);//Һ����������ʾͼ����ͼ����        
#ifdef __cplusplus
}
#endif

#endif														
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

