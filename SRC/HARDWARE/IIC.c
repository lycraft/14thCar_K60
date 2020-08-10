#include "IIC.h"
#include "gpio.h"
#define ack 1      //主应答
#define no_ack 0   //从应答	 

//-------------------------------------------------------------------------------------------------------------------
//  @brief      模拟IIC延时
//  @return     void						
//  @since      v1.0
//  Sample usage:				如果IIC通讯失败可以尝试增加j的值
//-------------------------------------------------------------------------------------------------------------------
static void simiic_delay(void)
{
	//j=10通讯速率大约为100K （内核频率40M）
    //j=0 通讯速率大约为140K （内核频率40M）
    uint16_t j=10;   
	while(j--);
}

void IIC_GPIOConfig(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  GPIO_InitStruct.GPIOx = IIC_PORT;                             
  GPIO_InitStruct.GPIO_InitState = Bit_SET;         /*  init as 0  */
  GPIO_InitStruct.GPIO_IRQMode = GPIO_IT_DISABLE;   /*  disable it */       
  GPIO_InitStruct.GPIO_Pin = IIC_SDA;              /*  led bit select    */
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OPP;        /*  out put pushpull */        
  GPIO_Init(&GPIO_InitStruct); 
	PORTD->PCR[IIC_SDA]|=0x01 << PORT_PCR_MUX_SHIFT;

  GPIO_InitStruct.GPIOx = IIC_PORT;                             
  GPIO_InitStruct.GPIO_InitState = Bit_SET;         /*  init as 0  */
  GPIO_InitStruct.GPIO_IRQMode = GPIO_IT_DISABLE;   /*  disable it */       
  GPIO_InitStruct.GPIO_Pin = IIC_SCL;              /*  led bit select    */
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OPP;        /*  out put pushpull */        
  GPIO_Init(&GPIO_InitStruct);   
	PORTD->PCR[IIC_SCL]|=0x01 << PORT_PCR_MUX_SHIFT;
}

 void SDA_OUTinit(void)
{
   GPIO_InitTypeDef  GPIO_InitStruct1; 
    
   GPIO_InitStruct1.GPIOx=IIC_PORT;
   GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_OPP; 
   GPIO_InitStruct1.GPIO_Pin=IIC_SDA;  
   GPIO_InitStruct1.GPIO_InitState=Bit_SET;
   GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
   GPIO_Init(&GPIO_InitStruct1); 
	PORTD->PCR[IIC_SDA]|=0x01 << PORT_PCR_MUX_SHIFT;

}


 void SDA_INinit(void)
{
   GPIO_InitTypeDef  GPIO_InitStruct1; 
    
   GPIO_InitStruct1.GPIOx=IIC_PORT;
   GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IN_FLOATING; 
   GPIO_InitStruct1.GPIO_Pin=IIC_SDA;  
   GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
   GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
   GPIO_Init(&GPIO_InitStruct1); 
	PORTD->PCR[IIC_SDA]|=0x01 << PORT_PCR_MUX_SHIFT;
}


//内部使用，用户无需调用
void IIC_start(void)
{
	SDA1();
	SCL1();
	simiic_delay();
	SDA0();
	simiic_delay();
	SCL0();
}

//内部使用，用户无需调用
void IIC_stop(void)
{
	SDA0();
	SCL0();
	simiic_delay();
	SCL1();
	simiic_delay();
	SDA1();
	simiic_delay();
}

//主应答(包含ack:SDA=0和no_ack:SDA=0)
//内部使用，用户无需调用
static void I2C_SendACK(unsigned char ack_dat)
{
    SCL0();
    simiic_delay();
	DIR_OUT();
    if(ack_dat) SDA0();
    else    	    SDA1();

    SCL1();
    simiic_delay();
    SCL0();
    simiic_delay();
}


static int WaitAck(void)
{
    SCL0();
    DIR_IN();
    simiic_delay();
    SCL1();
    simiic_delay();
	
    if(SDA)           //应答为高电平，异常，通信失败
    {
        DIR_OUT();
        SCL0();
        return 0;
    }
    DIR_OUT();
    SCL0();
    simiic_delay();
    return 1;
}

//字节发送程序
//发送c(可以是数据也可是地址)，送完后接收从应答
//不考虑从应答位
//内部使用，用户无需调用
void send_ch(uint8_t c)
{
    uint8_t i = 8;
    while(i--)
    {
        if(c & 0x80)	      SDA1();//SDA 输出数据
        else		      SDA0();
        c <<= 1;
        simiic_delay();
        SCL1();                //SCL 拉高，采集信号
        simiic_delay();
        SCL0();                //SCL 时钟线拉低
    }
	WaitAck();
}

//字节接收程序
//接收器件传来的数据，此程序应配合|主应答函数|IIC_ack_main()使用
//内部使用，用户无需调用
uint8_t read_ch(uint8_t ack_x)
{
    uint8_t i;
    uint8_t c;
    c=0;
    SCL0();
    simiic_delay();
    SDA1();             //置数据线为输入方式
    DIR_IN();
    for(i=0;i<8;i++)
    {
        simiic_delay();
        SCL0();         //置时钟线为低，准备接收数据位
        simiic_delay();
        SCL1();         //置时钟线为高，使数据线上数据有效
        simiic_delay();
        c<<=1;
        if(SDA) c+=1;   //读数据位，将接收的数据存c
    }
    DIR_OUT();
    SCL0();
    simiic_delay();
    I2C_SendACK(ack_x);
	
    return c;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      模拟IIC写数据到设备寄存器函数
//  @param      dev_add			设备地址(低七位地址)
//  @param      reg				寄存器地址
//  @param      dat				写入的数据
//  @return     void						
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------
void simiic_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat)
{
    IIC_start();
    send_ch( (dev_add<<1) | 0x00);   //发送器件地址加写位
    send_ch( reg );   				 //发送从机寄存器地址
    send_ch( dat );   				 //发送需要写入的数据
    IIC_stop();
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      模拟IIC从设备寄存器读取数据
//  @param      dev_add			设备地址(低七位地址)
//  @param      reg				寄存器地址
//  @param      type			选择通信方式是IIC  还是 SCCB
//  @return     uint8_t			返回寄存器的数据			
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------
uint8_t simiic_read_reg(uint8_t dev_add, uint8_t reg)
{
    uint8_t dat;
    IIC_start();
    send_ch( (dev_add<<1) | 0x00);  //发送器件地址加写位
    send_ch( reg );   				//发送从机寄存器地址
	
	IIC_start();
	send_ch( (dev_add<<1) | 0x01);  //发送器件地址加读位
	dat = read_ch(no_ack);   				//发送需要写入的数据
	IIC_stop();
	
	return dat;
}
//  @brief      模拟IIC读取多字节数据
//  @param      dev_add			设备地址(低七位地址)
//  @param      reg				寄存器地址
//  @param      dat_add			数据保存的地址指针
//  @param      num				读取字节数量
//  @param      type			选择通信方式是IIC  还是 SCCB
//  @return     uint8			返回寄存器的数据			
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------
void simiic_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num)
{
	IIC_start();
    send_ch( (dev_add<<1) | 0x00);  //发送器件地址加写位
	send_ch( reg );   				//发送从机寄存器地址
	
	
	IIC_start();
	send_ch( (dev_add<<1) | 0x01);  //发送器件地址加读位
    while(--num)
    {
        *dat_add = read_ch(ack); //读取数据
        dat_add++;
    }
    *dat_add = read_ch(no_ack); //读取数据
	IIC_stop();
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      模拟IIC端口初始化
//  @param      NULL
//  @return     void	
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------

uint8_t simiic_read_len(uint8_t dev_add, uint8_t reg, uint8_t len, uint8_t *dat)
{
	uint8_t i;

	IIC_start();
    send_ch( (dev_add<<1) | 0x00);  //发送器件地址加写位
	send_ch( reg );   				//发送从机寄存器地址
	IIC_start();
	send_ch( (dev_add<<1) | 0x01);  //发送器件地址加读位
	for (i = 0; i < len-1; i++)
	{
		dat[i] = read_ch(1);	//发送需要写入的数据
	}
	dat[i] = read_ch(0);	//发送需要写入的数据
	IIC_stop();
	
	return 0;
}



uint8_t simiic_write_len(uint8_t dev_add, uint8_t reg, uint8_t len,uint8_t  *dat)
{
	uint8_t i;
	
	IIC_start();
    send_ch( (dev_add<<1) | 0x00);   //发送器件地址加写位
	send_ch( reg );   				 //发送从机寄存器地址
	for (i = 0; i < len; i++)
	{
		send_ch(dat[i]);   				 //发送需要写入的数据
	}
	IIC_stop();
	
	return 0;
}

