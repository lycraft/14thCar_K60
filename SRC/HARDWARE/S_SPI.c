/**
  ******************************************************************************
  * @author  泽耀科技 ASHINING
  * @version V3.0
  * @date    2016-10-08
  * @brief   SPI配置C文件
  ******************************************************************************
  * @attention
  *
  * 官网	:	http://www.ashining.com
  * 淘宝	:	https://shop105912646.taobao.com
  * 阿里巴巴:	https://cdzeyao.1688.com
  ******************************************************************************
  */



#include "S_SPI.h"
#include "gpio.h"



/** 软件SPI */


/**
  * @brief :SPI初始化(软件)
  * @param :无
  * @note  :无
  * @retval:无
  */
void drv_spi_init( void )
{
	GPIO_InitTypeDef	SpiGpioInitStructer;
	
	/** SPI引脚配置 */
	//RCC_APB2PeriphClockCmd( SPI_CLK_GPIO_CLK | SPI_MISO_GPIO_CLK | SPI_MOSI_GPIO_CLK | SPI_NSS_GPIO_CLK, ENABLE );	//打开端口时钟
	
	//SCK MOSI NSS配置为推挽输出
//	SpiGpioInitStructer.GPIO_Speed = GPIO_Speed_10MHz;
	
	SpiGpioInitStructer.GPIO_InitState = Bit_RESET;
	SpiGpioInitStructer.GPIO_IRQMode = GPIO_IT_DISABLE;
	SpiGpioInitStructer.GPIO_Mode = GPIO_Mode_OPP;
	SpiGpioInitStructer.GPIO_Pin = SPI_CLK;
	SpiGpioInitStructer.GPIOx = SPI_CLK_GPIO_PORT;
 	GPIO_Init( &SpiGpioInitStructer );		//初始化SCK
	GPIO_ResetBits( SPI_CLK_GPIO_PORT, SPI_CLK_GPIO_PIN);		//初始化状态设置为低
	
	SpiGpioInitStructer.GPIO_InitState = Bit_SET;
	SpiGpioInitStructer.GPIO_IRQMode = GPIO_IT_DISABLE;
	SpiGpioInitStructer.GPIO_Mode = GPIO_Mode_OPP;
	SpiGpioInitStructer.GPIO_Pin = SPI_MOSI;
	SpiGpioInitStructer.GPIOx = SPI_MOSI_GPIO_PORT;
	GPIO_Init(  &SpiGpioInitStructer );		//初始化MOSI
	GPIO_SetBits( SPI_MOSI_GPIO_PORT, SPI_MOSI_GPIO_PIN);		//初始化状态设置为高
	
	SpiGpioInitStructer.GPIO_InitState = Bit_SET;
	SpiGpioInitStructer.GPIO_IRQMode = GPIO_IT_DISABLE;
	SpiGpioInitStructer.GPIO_Mode = GPIO_Mode_OPP;
	SpiGpioInitStructer.GPIO_Pin = SPI_NSS;
	SpiGpioInitStructer.GPIOx = SPI_NSS_GPIO_PORT;
	GPIO_Init(  &SpiGpioInitStructer );		//初始化NSS
	GPIO_SetBits( SPI_NSS_GPIO_PORT, SPI_NSS_GPIO_PIN);			//初始化状态设置为高
	
	//初始化MISO 上拉输入
	SpiGpioInitStructer.GPIO_InitState = Bit_SET;
	SpiGpioInitStructer.GPIO_IRQMode = GPIO_IT_DISABLE;
	SpiGpioInitStructer.GPIO_Mode = GPIO_Mode_IPU;
	SpiGpioInitStructer.GPIO_Pin = SPI_MISO;
	SpiGpioInitStructer.GPIOx = SPI_MISO_GPIO_PORT;
	GPIO_Init(&SpiGpioInitStructer );		
	GPIO_SetBits( SPI_MISO_GPIO_PORT, SPI_MISO_GPIO_PIN);		//初始化状态设置为高
}

/**
  * @brief :SPI收发一个字节
  * @param :
  *			@TxByte: 发送的数据字节
  * @note  :非堵塞式，一旦等待超时，函数会自动退出
  * @retval:接收到的字节
  */
uint8_t drv_spi_read_write_byte( uint8_t TxByte )
{
	uint8_t i = 0, Data = 0;
	
	spi_set_clk_low( );
	
	for( i = 0; i < 8; i++ )			//一个字节8byte需要循环8次
	{
		/** 发送 */
		if( 0x80 == ( TxByte & 0x80 ))
		{
			spi_set_mosi_hight( );		//如果即将要发送的位为 1 则置高IO引脚
		}
		else
		{
			spi_set_mosi_low( );		//如果即将要发送的位为 0 则置低IO引脚
		}
		TxByte <<= 1;					//数据左移一位，先发送的是最高位
		
		spi_set_clk_high( );			//时钟线置高
		__nop( );
		__nop( );
		
		/** 接收 */
		Data <<= 1;						//接收数据左移一位，先接收到的是最高位
		if( 1 == spi_get_miso( ))
		{
			Data |= 0x01;				//如果接收时IO引脚为高则认为接收到 1
		}
		
		spi_set_clk_low( );				//时钟线置低
		__nop( );
		__nop( );
	}
	
	return Data;		//返回接收到的字节
}

/**
  * @brief :SPI收发字符串
  * @param :
  *			@ReadBuffer: 接收数据缓冲区地址
  *			@WriteBuffer:发送字节缓冲区地址
  *			@Length:字节长度
  * @note  :非堵塞式，一旦等待超时，函数会自动退出
  * @retval:无
  */
void drv_spi_read_write_string( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length )
{
	spi_set_nss_low( );			//片选拉低
	
	while( Length-- )
	{
		*ReadBuffer = drv_spi_read_write_byte( *WriteBuffer );		//收发数据
		ReadBuffer++;
		WriteBuffer++;			//读写地址加1
	}
	
	spi_set_nss_high( );		//片选拉高
}


/** 软件SPI */


