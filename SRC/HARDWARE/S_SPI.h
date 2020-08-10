/**
  ******************************************************************************
  * @author  泽耀科技 ASHINING
  * @version V3.0
  * @date    2016-10-08
  * @brief   SPI配置H文件
  ******************************************************************************
  * @attention
  *
  * 官网	:	http://www.ashining.com
  * 淘宝	:	https://shop105912646.taobao.com
  * 阿里巴巴:	https://cdzeyao.1688.com
  ******************************************************************************
  */


#ifndef __SPI_H__
#define __SPI_H__


//#include "stm32f10x_rcc.h"
#include "gpio.h"
//#include "stm32f10x_spi.h"
//#include "main.h"



//SPI引脚定义
#define SPI_CLK_GPIO_PORT			PTA
//#define SPI_CLK_GPIO_CLK			RCC_APB2Periph_GPIOB
#define SPI_CLK_GPIO_PIN			GPIO_Pin_14
#define SPI_CLK			            (14)

#define SPI_MISO_GPIO_PORT			PTA
//#define SPI_MISO_GPIO_CLK			RCC_APB2Periph_GPIOB
#define SPI_MISO_GPIO_PIN			GPIO_Pin_16
#define SPI_MISO			        (16)

#define SPI_MOSI_GPIO_PORT			PTA
//#define SPI_MOSI_GPIO_CLK			RCC_APB2Periph_GPIOB
#define SPI_MOSI_GPIO_PIN			GPIO_Pin_15
#define SPI_MOSI			        (15)

#define SPI_NSS_GPIO_PORT			PTA
//#define SPI_NSS_GPIO_CLK			RCC_APB2Periph_GPIOG
#define SPI_NSS_GPIO_PIN			GPIO_Pin_13
#define SPI_NSS			            (13)


#define spi_set_nss_high( )			GPIO_SetBits(SPI_NSS_GPIO_PORT,SPI_NSS_GPIO_PIN)							//片选置高
#define spi_set_nss_low( )			GPIO_ResetBits(SPI_NSS_GPIO_PORT,SPI_NSS_GPIO_PIN)	//片选置低



	/** 只有使用软件SPI才需要的封装 */			

#define spi_set_clk_high( )			GPIO_SetBits(SPI_CLK_GPIO_PORT,SPI_CLK_GPIO_PIN)								//时钟置高
#define spi_set_clk_low( )			GPIO_ResetBits(SPI_CLK_GPIO_PORT,SPI_CLK_GPIO_PIN)	//时钟置低

#define spi_set_mosi_hight( )		GPIO_SetBits(SPI_MOSI_GPIO_PORT,SPI_MOSI_GPIO_PIN)						//发送脚置高
#define spi_set_mosi_low( )			GPIO_ResetBits(SPI_MOSI_GPIO_PORT,SPI_MOSI_GPIO_PIN)	//发送脚置低

#define spi_get_miso( )				GPIO_ReadInputDataBit(SPI_MISO_GPIO_PORT,SPI_MISO_GPIO_PIN) // 若相应输入位为低则得到0，相应输入位为高则得到1


void drv_spi_init( void );
uint8_t drv_spi_read_write_byte( uint8_t TxByte );
void drv_spi_read_write_string( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length );





#endif

