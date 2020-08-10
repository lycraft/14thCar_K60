#ifndef __OLED_IMAGE_H__
#define __OLED_IMAGE_H__

#ifdef __cplusplus
	extern "C" {
#endif
		
#include "Camera.h"

#define Image_X_Rotate_Mode  ON  //图像X轴旋转180度
#define Image_Y_Rotate_Mode  ON //图像Y轴旋转180度
#define Image_XSub           1  //X比例补偿值  非浮点数所带来的边缘问题
#define Image_YSub           1  //Y比例补偿值  非浮点数所带来的边缘问题
#define Image_RColor_Mode  WhiteShow  //原图颜色配比   
#define Image_FColor_Mode  BlackShow  //拟图颜色配比        
        
#define Shift  1 

typedef enum
{  
  BlackShow=0 ,            //黑亮白暗
  WhiteShow =1,           //黑暗白亮   
}ColorMode;        
        



        
//-------------------------------------液晶显示赛道(为了加快效率)-------------------------------------------------------
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
void  OLED_Fit_Image_Dispaly(void);//液晶屏显示拟图像 

void OLED_Image_Dispaly(ColorMode Mode);        
void OLED_Lcr_Display(ColorMode Mode);      
void OLED_Par_Dispaly_Host(int Par_Page);//显示参数 本地       
void OLED_Par_Dispaly_Live(int Par_Page);//显示参数 在线        
void OLED_Image_Live(void);//液晶屏在线显示图像拟图数据        
#ifdef __cplusplus
}
#endif

#endif														
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

