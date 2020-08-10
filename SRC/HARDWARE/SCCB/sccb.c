#include "sccb.h"
#include "gpio.h"
#include "dma.h"
#include "delay.h"



#define  OV7725_EAGLE_W          160
#define  OV7725_EAGLE_H          120

//50֡��
//{COM4         , 0xC1},
//{CLKRC        , 0x02},


//75֡��
//{COM4         , 0x41},
//{CLKRC        , 0x00},


//112֡��
//{COM4         , 0x81},
//{CLKRC        , 0x00},


//150֡��
//{COM4         , 0xC1},
//{CLKRC        , 0x00},

static void SCCB_delay(uint16_t i);



static void SCCB_delay(volatile uint16_t time)
{
  while(time)
  {
    time--;
  }
}


 
void SCCB_GPIOConfig(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  GPIO_InitStruct.GPIOx = SCCB_PORT;                             
  GPIO_InitStruct.GPIO_InitState = Bit_SET;         /*  init as 0  */
  GPIO_InitStruct.GPIO_IRQMode = GPIO_IT_DISABLE;   /*  disable it */       
  GPIO_InitStruct.GPIO_Pin = SCCB_SDA;              /*  led bit select    */
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OPP;        /*  out put pushpull */        
  GPIO_Init(&GPIO_InitStruct); 

  GPIO_InitStruct.GPIOx = SCCB_PORT;                             
  GPIO_InitStruct.GPIO_InitState = Bit_SET;         /*  init as 0  */
  GPIO_InitStruct.GPIO_IRQMode = GPIO_IT_DISABLE;   /*  disable it */       
  GPIO_InitStruct.GPIO_Pin = SCCB_SCL;              /*  led bit select    */
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OPP;        /*  out put pushpull */        
  GPIO_Init(&GPIO_InitStruct);   
}

/*!
 *  @brief      SCCB��ʼ�ź�
 *  @since      v5.0
 */
static uint8_t SCCB_Start(void)
{
  SDA_H();      
  SCL_H();
  SCCB_DELAY();

   SDA_DDR_IN();     /* output to input  */
  if(!SDA_IN())     /* read bit */
  {
    SDA_DDR_OUT();  /* input to output  */
    return 0;       /* SDA��Ϊ�͵�ƽ������æ,�˳� */
  }
  SDA_DDR_OUT();    /* input to output  */
  SDA_L();

  SCCB_DELAY();
  SCL_L();

  if(SDA_IN())      /* read bit */
  {
      SDA_DDR_OUT();/* input to output  */
      return 0;   /* SDA��Ϊ�ߵ�ƽ�����߳���,�˳� */
  }
  //SDA_DDR_OUT();
  //SDA_L();
  //SCCB_delay();
  return 1;
}

/*!
*  @brief      SCCBֹͣ�ź�
*  @since      v5.0
*/
static void SCCB_Stop(void)
{
  SCL_L();
  //SCCB_DELAY();
  SDA_L();
  SCCB_DELAY();
  SCL_H();
  SCCB_DELAY();
  SDA_H();
  SCCB_DELAY();
}

/*!
 *  @brief      SCCBӦ���ź�
 *  @since      v5.0
 */
static void SCCB_Ack(void)
{
    SCL_L();
    SCCB_DELAY();
    SDA_L();
    SCCB_DELAY();
    SCL_H();
    SCCB_DELAY();
    SCL_L();
    SCCB_DELAY();
}

/*!
 *  @brief      SCCB��Ӧ���ź�
 *  @since      v5.0
 */
static void SCCB_NoAck(void)
{
    SCL_L();
    SCCB_DELAY();
    SDA_H();
    SCCB_DELAY();
    SCL_H();
    SCCB_DELAY();
    SCL_L();
    SCCB_DELAY();
}

/*!
 *  @brief      SCCB �ȴ�Ӧ��
 *  @return     Ӧ������0��ʾ��Ӧ��1��ʾ��Ӧ��
 *  @since      v5.0
 */
static int SCCB_WaitAck(void)
{
    SCL_L();
    //SDA_H();
    SDA_DDR_IN();

    SCCB_DELAY();
    SCL_H();

    SCCB_DELAY();

    if(SDA_IN())           //Ӧ��Ϊ�ߵ�ƽ���쳣��ͨ��ʧ��
    {
        SDA_DDR_OUT();
        SCL_L();
        return 0;
    }
    SDA_DDR_OUT();
    SCL_L();
    return 1;
}

/*!
 *  @brief      SCCB ���͵�����
 *  @param      SendByte    ��Ҫ���͵�����
 *  @since      v5.0
 */
static void SCCB_SendByte(uint8_t SendByte)
{
    uint8_t i = 8;
    while(i--)
    {

        if(SendByte & 0x80)     //SDA �������
        {
            SDA_H();
        }
        else
        {
            SDA_L();
        }
        SendByte <<= 1;
        SCCB_DELAY();
        SCL_H();                //SCL ���ߣ��ɼ��ź�
        SCCB_DELAY();
        SCL_L();                //SCL ʱ��������
        //SCCB_DELAY();
    }
    //SCL_L();
}

/*!
 *  @brief      ����SCCB���ߵ�����
 *  @return     ���յ�������
 *  @since      v5.0
 */
static int SCCB_ReceiveByte(void)
{
    uint8_t i = 8;
    uint8_t ReceiveByte = 0;

    //SDA_H();
    //SCCB_DELAY();
    SDA_DDR_IN();

    while(i--)
    {
        ReceiveByte <<= 1;
        SCL_L();
        SCCB_DELAY();
        SCL_H();
        SCCB_DELAY();

        if(SDA_IN())
        {
            ReceiveByte |= 0x01;
        }


    }
    SDA_DDR_OUT();
    SCL_L();
    return ReceiveByte;
}

/*****************************************************************************************
* ��������SCCB_WriteByte
* ����  ��дһ�ֽ�����
* ����  ��- WriteAddress: ��д���ַ    - SendByte: ��д������  - DeviceAddress: ��������
* ���  ������Ϊ:=1�ɹ�д��,=0ʧ��
* ע��  ����
*****************************************************************************************/
static int SCCB_WriteByte_one( uint16_t WriteAddress , uint8_t SendByte );


int SCCB_WriteByte( uint16_t WriteAddress , uint8_t SendByte )            //���ǵ���sccb�Ĺܽ�ģ�⣬�Ƚ�����ʧ�ܣ���˶��Լ���
{
    uint8_t i = 0;
    while( 0 == SCCB_WriteByte_one ( WriteAddress, SendByte ) )
    {
        i++;
        if(i == 20)
        {
            return 0 ;
        }
    }
    return 1;
}

int SCCB_WriteByte_one( uint16_t WriteAddress , uint8_t SendByte )
{
    if(!SCCB_Start())
    {
        return 0;
    }
    SCCB_SendByte( DEV_ADR );                    /* ������ַ */
    if( !SCCB_WaitAck() )
    {
        SCCB_Stop();
        return 0;
    }
    SCCB_SendByte((uint8_t)(WriteAddress & 0x00FF));   /* ���õ���ʼ��ַ */
    SCCB_WaitAck();
    SCCB_SendByte(SendByte);
    SCCB_WaitAck();
    SCCB_Stop();
    return 1;
}





static int SCCB_ReadByte_one(uint8_t *pBuffer,   uint16_t length,   uint8_t ReadAddress);

int SCCB_ReadByte(uint8_t *pBuffer,   uint16_t length,   uint8_t ReadAddress)
{
    uint8_t i = 0;
    while( 0 == SCCB_ReadByte_one(pBuffer, length, ReadAddress) )
    {
        i++;
        if(i == 30)
        {
            return 0 ;
        }
    }
    return 1;
}

int SCCB_ReadByte_one(uint8_t *pBuffer,   uint16_t length,   uint8_t ReadAddress)
{
    if(!SCCB_Start())
    {
        return 0;
    }
    SCCB_SendByte( DEV_ADR );         /* ������ַ */
    if( !SCCB_WaitAck() )
    {
        SCCB_Stop();
        return 0;
    }
    SCCB_SendByte( ReadAddress );           /* ���õ���ʼ��ַ */
    SCCB_WaitAck();
    SCCB_Stop();

    if(!SCCB_Start())
    {
        return 0;
    }
    SCCB_SendByte( DEV_ADR + 1 );               /* ������ַ */

    if(!SCCB_WaitAck())
    {
        SCCB_Stop();
        return 0;
    }
    while(length)
    {
        *pBuffer = SCCB_ReceiveByte();
        if(length == 1)
        {
            SCCB_NoAck();
        }
        else
        {
            SCCB_Ack();
        }
        pBuffer++;
        length--;
    }
    SCCB_Stop();
    return 1;
}

 void SDA_OUT_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStruct1; 
    
   GPIO_InitStruct1.GPIOx=SCCB_PORT;
   GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_OPP; 
   GPIO_InitStruct1.GPIO_Pin=SCCB_SDA;  
   GPIO_InitStruct1.GPIO_InitState=Bit_SET;
   GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
   GPIO_Init(&GPIO_InitStruct1); 
	

}


 void SDA_IN_Init(void)
{
   GPIO_InitTypeDef  GPIO_InitStruct1; 
    
   GPIO_InitStruct1.GPIOx=SCCB_PORT;
   GPIO_InitStruct1.GPIO_Mode=GPIO_Mode_IN_FLOATING; 
   GPIO_InitStruct1.GPIO_Pin=SCCB_SDA;  
   GPIO_InitStruct1.GPIO_InitState=Bit_RESET;
   GPIO_InitStruct1.GPIO_IRQMode=GPIO_IT_DISABLE;
   GPIO_Init(&GPIO_InitStruct1); 
}





/*OV7725��ʼ�����ñ�*/  
reg_s ov7725_eagle_reg[] =  
{  
    //�Ĵ������Ĵ���ֵ��  
    {OV7725_COM4         , 0x81},  
    {OV7725_CLKRC        , 0x00},  
    {OV7725_COM2         , 0x03},  
    {OV7725_COM3         , 0xD0},  
    {OV7725_COM7         , 0x40},    
    {OV7725_HSTART       , 0x3F},  
    {OV7725_HSIZE        , 0x50},  
    {OV7725_VSTRT        , 0x03},  
    {OV7725_VSIZE        , 0x78},  
    {OV7725_HREF         , 0x00},  
    {OV7725_SCAL0        , 0x0A},  
    {OV7725_AWB_Ctrl0    , 0xE0},  
    {OV7725_DSPAuto      , 0xff},  
    {OV7725_DSP_Ctrl2    , 0x0C},  
    {OV7725_DSP_Ctrl3    , 0x00},  
    {OV7725_DSP_Ctrl4    , 0x00},  
  
#if (OV7725_EAGLE_W == 80)  
    {OV7725_HOutSize     , 0x14},  
#elif (OV7725_EAGLE_W == 160)  
    {OV7725_HOutSize     , 0x28},  
#elif (OV7725_EAGLE_W == 240)  
    {OV7725_HOutSize     , 0x3c},  
#elif (OV7725_EAGLE_W == 320)  
    {OV7725_HOutSize     , 0x50},  
#else  
  
#endif  
  
#if (OV7725_EAGLE_H == 60 )  
	{OV7725_VOutSize     , 0x1E},  
#elif (OV7725_EAGLE_H == 120 )  
    {OV7725_VOutSize     , 0x3c},  
#elif (OV7725_EAGLE_H == 180 )  
    {OV7725_VOutSize     , 0x5a},  
#elif (OV7725_EAGLE_H == 240 )  
    {OV7725_VOutSize     , 0x78},  
#else  
  
#endif  
  
    {OV7725_EXHCH        , 0x00},  
    {OV7725_GAM1         , 0x0c},  
    {OV7725_GAM2         , 0x16},  
    {OV7725_GAM3         , 0x2a},  
    {OV7725_GAM4         , 0x4e},  
    {OV7725_GAM5         , 0x61},  
    {OV7725_GAM6         , 0x6f},  
    {OV7725_GAM7         , 0x7b},  
    {OV7725_GAM8         , 0x86},  
    {OV7725_GAM9         , 0x8e},  
    {OV7725_GAM10        , 0x97},  
    {OV7725_GAM11        , 0xa4},  
    {OV7725_GAM12        , 0xaf},  
    {OV7725_GAM13        , 0xc5},  
    {OV7725_GAM14        , 0xd7},  
    {OV7725_GAM15        , 0xe8},  
    {OV7725_SLOP         , 0x20},  
    {OV7725_LC_RADI      , 0x00},  
    {OV7725_LC_COEF      , 0x13},  
    {OV7725_LC_XC        , 0x08},  
    {OV7725_LC_COEFB     , 0x14},  
    {OV7725_LC_COEFR     , 0x17},  
    {OV7725_LC_CTR       , 0x05},  
    {OV7725_BDBase       , 0x99},  
    {OV7725_BDMStep      , 0x03},  
    {OV7725_SDE          , 0x04},  
    {OV7725_BRIGHT       , 0x00},  
    {OV7725_CNST         , 0x33},  //��ֵ
    {OV7725_SIGN         , 0x06},  
    {OV7725_UVADJ0       , 0x11},  
    {OV7725_UVADJ1       , 0x02},  
  
};
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( ((a)[0]) ) ) 
uint8_t ov7725_eagle_cfgnum = ARR_SIZE( ov7725_eagle_reg ) ; /*�ṹ�������Ա��Ŀ*/
uint8_t ov7725_eagle_reg_init(void)  
{  
    uint16_t i = 0;  
    uint8_t Sensor_IDCode = 0;  
    SCCB_GPIOConfig();  
  
    if( 0 == SCCB_WriteByte ( OV7725_COM7, 0x80 ) ) 
    {   
        return 0 ;  
    }  
  
       DelayMs(50);  
  
    if( 0 == SCCB_ReadByte( &Sensor_IDCode, 1, OV7725_VER ) )   
    {   
        return 0;  
    }  
    if(Sensor_IDCode == OV7725_ID)  
    {  
        for( i = 0 ; i < ov7725_eagle_cfgnum ; i++ )  
        {  
            if( 0 == SCCB_WriteByte(ov7725_eagle_reg[i].addr, ov7725_eagle_reg[i].val) )  
            {    
                return 0;  
            }  
        }  
    }  
    else  
    {  
        return 0;  
    }   
    return 1;  
} 
  
  

  

  

  
  
  
  

