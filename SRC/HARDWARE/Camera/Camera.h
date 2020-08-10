#include "gpio.h"

#ifdef __cplusplus
 extern "C" {
#endif

//摄像头采集端口设置
#define Field_IT_GPIOx   PTA         //场中断通道类型
#define Field_IT_Pin     GPIO_Pin_26  //场中断端口引脚	
     
#define Pclk_IT_GPIOx    PTA         //PCLK中断通道类型
#define Pclk_IT_Pin      GPIO_Pin_25  //PCLK中断端口引脚	
	  
#define Pixels_GPIOx     PTB         //摄像头图像数通道类型 
#define Pixels_Pin       GPIO_Pin_0  //摄像头图像数据端口引脚
	 
/***********************oled图片数据	******************************/
#define Image_W          160
#define Image_H          70	 
	 
/***********************图片尺寸设置******************************/	 
#define  Image_Width              200
#define  Image_Height             70
#define  DMA_CAMERA_Length        11208   //摄像头一次采集长度 

	 
void Camera_Init(void);

#ifdef __cplusplus
}
#endif

