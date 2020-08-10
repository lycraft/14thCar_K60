#include "sys.h"
#include "gpio.h"
#include "delay.h"
#include "wdog.h"
#include "pit.h"
#include "dma.h"
#include "ftm.h"
#include "lptm.h"
#include "adc.h"
#include "tsi.h"
#include "spi.h"
#include "i2c.h"
#include "pdb.h"
#include "sd.h"
#include "flash.h"
#include "stdio.h"
#include "uart.h"
#include "oled.h"
#include "camera.h"
#include "motor.h"
#include "engine.h"
#include "pid.h"
#include "data_sent.h"
#include "data_sd.h"
#include "menu.h"
#include "nrf2401.h"
#include "data_sd.h"
#include "led.h"
#include "data_sent.h"
#include "common.h"


/*********************CCD摄像头**************************************/
extern uint8_t date[];//DMA0图像缓存数据

extern uint8_t Left_flag[];
extern uint8_t Right_flag[];
extern uint8_t fixvalue[];

extern uint8_t flage_DMA;



extern uint8_t  Hang;          //有效行计数
extern uint8_t  Chang;         //有效场计数           
extern uint8_t  Hsync;             //行标
   
typedef uint8_t (*PP_Pixels)[Image_Width];        //定义一个第二维为Image_Width的二维指针类型
extern uint8_t Pixels[Image_Width*Image_Height];  //用于存储原始图像 
extern PP_Pixels P_Pixels;   

extern uint8_t fixvalue[70] ;

extern  uint8_t lie,youxiao;
extern  uint16_t i,j;
extern  uint8_t Turn_left_flag;
extern  uint8_t Turn_right_flag;
extern  uint8_t Annular_flag;//?????
extern  uint8_t Annular_flag1;//?????
extern  uint8_t Annular_turn_left_flag;//???????
extern  uint16_t Annular_turn_right_flag;//???????
extern  uint8_t left_miss_flag;//????????
extern  uint8_t right_miss_flag;//????????
extern  uint8_t left_error_flag;//???????
extern  uint8_t right_error_flag;//???????
extern  uint8_t left_error_line;//???????
extern  uint8_t right_error_line;//???????
extern  uint8_t Annular_line;//?????
extern  uint8_t left_Annular_line;//???????
extern  uint8_t right_Annular_line;//???????
extern  uint8_t last_left_Annular_line;//??????????
extern  uint8_t last_right_Annular_line;//??????????
extern  uint8_t left_right_line;//?????
extern  uint8_t right_right_line;//?????
extern  uint8_t left_error_cnt;//????????
extern  uint8_t right_error_cnt;//????????
extern  uint8_t ten_error_cnt;//??????
extern  uint8_t left_line;//???????????
extern  uint8_t right_line;//?????????????
extern  uint8_t left_ten_flag;//?????????
extern  uint8_t right_ten_flag;//?????????
extern  uint8_t left_error_count;//??????
extern  uint8_t right_error_count;//??????
extern  uint8_t left_right_count;//??????
extern  uint8_t right_right_count;//??????
extern  uint8_t right_transmit_cnt;//???????????
extern  uint8_t left_transmit_cnt;//???????????
extern  uint8_t start_line;//???????
extern  uint8_t end_line;//???????
extern  float ratio;//??
extern  float constant;//??
extern  float ratio1;//??
extern  float constant1;//??
extern  uint8_t ten_count;//????????
extern  uint8_t ten_line;//???????
extern  uint8_t not_ten_flag;
extern  uint8_t Annular_line_cnt;//??????
extern  uint8_t Annular_Lline;//???
extern  uint8_t Annular_Rline;//???
extern  uint8_t left_Annular_count;//?????
extern  uint8_t right_Annular_count;//?????
extern  uint8_t Rlose_count;//???????
extern  uint8_t Llose_count;//???????
extern  uint8_t last_left_right_line;
extern  uint8_t last_right_right_line;
extern  uint8_t left_car_line;
extern  uint8_t right_car_line;
extern  uint8_t middle_car_line;
extern  uint8_t last_left_car_line;
extern  uint8_t last_right_car_line;
extern  uint8_t Turn_left_count;
extern  uint8_t Turn_right_count;
extern  uint8_t Turn_left_line;
extern  uint8_t Turn_right_line;
extern  uint8_t Annular_right_cnt;
extern  uint8_t Annular_left_cnt;
extern  uint8_t Annular_count;//?????
extern  uint8_t In_Annular_flag;//?????
extern  uint8_t Out_Annular_line;
extern  uint8_t Out_Annular_cnt;
extern  uint8_t Out_Annular_flag;
extern  uint8_t Out_Annular_count;
extern  uint8_t left_Annular_flag;
extern  uint8_t right_Annular_flag;
extern  uint8_t RowNum;
extern  uint8_t Last_field_LBlack;
extern  uint8_t Last_field_RBlack;
extern  uint8_t Last_field_Center;
extern  uint8_t Edge_flag;
extern  uint8_t ten_right_cnt;
extern  uint8_t ten_left_cnt;
//extern  uint8_t Road_flag;
extern  uint8_t stop_cnt;
extern  uint8_t stop_flag;
extern  uint8_t straight_cnt;
extern  uint8_t black_line;
extern  uint8_t Edge_line_temp;
extern  uint8_t Starting_line_flag;//??????
extern  uint8_t Starting_line_cnt;//??????
extern  uint8_t Small_S_flag; //???S?????
extern  uint8_t last_Small_S_flag;
extern  uint8_t Small_S_center;
extern  uint8_t Small_S_L_cnt;
extern  uint8_t Small_S_R_cnt;
extern  uint8_t Edge_line;
extern  uint8_t Annular_cnt;
extern  uint8_t Annular_cnt1;
extern  uint8_t chang_cnt;
extern  uint8_t last_ten_line;
extern  uint8_t ten_line_flag;
extern  uint8_t Out_Annular_sub;
extern  uint8_t obstacle_cnt;
extern  uint8_t obstacle_flag;
extern  uint8_t obstacle_line;
extern  uint8_t obstacle_chang;
extern  uint8_t Small_s_cnt;
extern  uint8_t In_Annular_flag1;
extern  uint8_t Starting_line;
extern  uint8_t trend_L_cnt;
extern  uint8_t trend_R_cnt;
extern  uint8_t trend_L_flag;//1?2?
extern  uint8_t trend_R_flag;//1?2?
extern  uint8_t ramp_cnt;
extern  uint8_t ramp_flag;
//extern  uint8_t ramp_chang;
extern  uint8_t Starting_line_chang;
extern  uint8_t Starting_line_flag1;
extern  uint8_t Obstacle_location;
extern  unsigned int delay;
extern  uint8_t Starting_line_stop_flag;
extern  uint8_t Starting_line_stop_flag1;

extern  int Left_sub;//????????
extern  int Right_sub;
extern  uint8_t Wait_flag;//??????
 


extern  uint8_t last_Road_flag;
extern  uint8_t brake_flag;
extern  uint8_t brake_cnt;
extern  uint8_t brake_cnt1;
        
extern  uint8_t car_fixvalue[65];

extern  uint8_t Left_flag[70];
extern  uint8_t Right_flag[70];

/**************************** DATE_SNED ***********************************/
extern Data_Type *Sent_Data;
extern uint8_t Pixels[]; 
extern uint8_t*P;
extern  uint16_t  h;







extern uint8_t DMA_Temp;
extern int32 EncoderA_Cnt;
extern int32 EncoderB_Cnt;


extern struct ModeStruct Mode;//开关模式    
extern uint16_t MODE; //模式选择 
extern uint32_t Mode_Temp;
extern uint16_t SD_ALL_WT_Count;
extern int All_Temp_i;


extern float Engine_Kp_R;//舵机的P系数//图像行数缩了之后比例要调小
extern float Engine_Kd_R;//舵机的D系数
extern float Engine_Kp_temp;
extern float Engine_Kd_temp;

//电机PID的三个系数
////A
//extern uint16_t MotorA_PID_Kp;
//extern uint16_t MotorA_PID_Ki;
//extern uint16_t MotorA_PID_Kd;
////B
//extern uint16_t MotorB_PID_Kp;
//extern uint16_t MotorB_PID_Ki;
//extern uint16_t MotorB_PID_Kd;
//设定速度
extern uint16_t SpeedNumA;
extern uint16_t SpeedNumB;
//extern uint16_t Speed;
extern uint16_t RPWM;
extern uint16_t LPWM;
extern uint16_t Diff_P;
extern uint16_t Out_Annular_Turn_row;
extern uint16_t Small_S_kp,Small_S_kd;
extern int16_t L_speed;
extern int32_t Speed_sub;
extern int32_t leftout;
extern int32_t rightout;
extern int32_t speed_out;
extern int16_t steer_sub;
//电机PID参数结构体
extern PID_Speed PID_MiddleSpeed,PID_LeftSpeed,PID_RightSpeed,Diff_Speed_Control;

extern uint16_t chasu_max;
extern uint8_t tingche_flag;
extern int brake;
extern  uint16_t mangqu;
extern uint16_t jiajian_flag;
extern uint16_t stop_chang_yuzhi;
extern uint16_t ramp_chang_yuzhi;
extern uint16_t obstacle_chang_yuzhi;
extern uint16_t Annular_speed;
