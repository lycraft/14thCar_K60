//****************************************//
//	模拟IIC
//****************************************//
#ifndef __IIC_H_
#define __IIC_H_

#include "sys.h"  

//#define SEEKFREE_SCL    D12                           //定义SCL引脚  可任意更改为其他IO
//#define SEEKFREE_SDA    D13                           //定义SDA引脚  可任意更改为其他IO
#define IIC_PORT       PTD
#define IIC_SCL        GPIO_Pin_9
#define IIC_SDA        GPIO_Pin_8

#define SDA             GPIO_ReadInputDataBit(IIC_PORT,IIC_SDA)
#define SDA0()          GPIO_ResetBits(IIC_PORT,IIC_SDA)		//IO口输出低电平
#define SDA1()          GPIO_SetBits(IIC_PORT,IIC_SDA)		//IO口输出高电平  
#define SCL0()          GPIO_ResetBits(IIC_PORT,IIC_SCL)
#define SCL1()          GPIO_SetBits(IIC_PORT,IIC_SCL)
#define DIR_OUT()       SDA_OUTinit();    //输出方向
#define DIR_IN()        SDA_INinit();    //输入方向

void SDA_OUTinit(void);
 void SDA_INinit(void);
void IIC_GPIOConfig(void);
void IIC_start(void);
void IIC_stop(void);
void send_ch(uint8_t c);
uint8_t read_ch(uint8_t ack_x);
void  simiic_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat);
uint8_t simiic_read_reg(uint8_t dev_add, uint8_t reg);
void simiic_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num);
uint8_t simiic_read_len(uint8_t dev_add, uint8_t reg, uint8_t len, uint8_t *dat);
uint8_t simiic_write_len(uint8_t dev_add, uint8_t reg, uint8_t len, uint8_t *dat);
#endif

