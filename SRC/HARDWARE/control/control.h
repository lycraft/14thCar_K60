#include "sys.h"
#include "extern.h"

void motor_speed_zhili(int32_t speed1,int32_t speed2,int32 max,int32 min);
void Engine_Control(void);
void balance_deal(void);
void Motor_Control(void);
 float tan1(int a);
void Speed_Measure(void);
void SpeedCalculate(void);
float SpeedPWMOut(float NewspeedPWM ,float LastspeedPWM,uint8_t PeriodCount);
void Electronic_diff(void);
void expect_angv(void);	
 void State_Analyze(void);

