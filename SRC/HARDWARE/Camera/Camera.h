#include "gpio.h"

#ifdef __cplusplus
 extern "C" {
#endif

//����ͷ�ɼ��˿�����
#define Field_IT_GPIOx   PTA         //���ж�ͨ������
#define Field_IT_Pin     GPIO_Pin_26  //���ж϶˿�����	
     
#define Pclk_IT_GPIOx    PTA         //PCLK�ж�ͨ������
#define Pclk_IT_Pin      GPIO_Pin_25  //PCLK�ж϶˿�����	
	  
#define Pixels_GPIOx     PTB         //����ͷͼ����ͨ������ 
#define Pixels_Pin       GPIO_Pin_0  //����ͷͼ�����ݶ˿�����
	 
/***********************oledͼƬ����	******************************/
#define Image_W          160
#define Image_H          70	 
	 
/***********************ͼƬ�ߴ�����******************************/	 
#define  Image_Width              200
#define  Image_Height             70
#define  DMA_CAMERA_Length        11208   //����ͷһ�βɼ����� 

	 
void Camera_Init(void);

#ifdef __cplusplus
}
#endif

