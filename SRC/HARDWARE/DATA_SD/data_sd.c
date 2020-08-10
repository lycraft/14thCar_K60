#include "data_sd.h"
#include "sd.h"
#include "data_sent.h"
#include "delay.h"
#include "key.h"
#include "oled_display.h"

extern Data_Type *Sent_Data;
uint8_t Data_SD_CardType = SD_CARD_TYPE_NONE;
uint32_t Data_SD_RCA = 0;
uint64_t Data_Count=NULL;//数据块长度

uint16_t Blocks_Num=0;//扇区标记地址

uint8_t Data_SD_Init(void)
{
	uint32_t delay_cnt = 0;
	uint8_t result;  //存储函数返回结果
	uint8_t i=0;
	uint8_t hc=0;     //是否为SDHC标志
	//SD卡命令结构体定义
	SD_CommandTypeDef SD_CommandStruct1;
	//SD卡参数设置结构体定义
	SD_InitTypeDef SD_InitStruct;
	
	SD_InitStruct.SD_BaudRate=SD_WR_BaudRate;//设置波特率
	
	//开启GPIO时钟
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	//开启SDHC时钟
	SIM->SCGC3 |= SIM_SCGC3_SDHC_MASK;
	//复位SDHC 设置超时时间
	SDHC->SYSCTL = SDHC_SYSCTL_RSTA_MASK | SDHC_SYSCTL_SDCLKFS(0x80); //超时时间设置为2^13  //2分频
	//等待复位完成
	while(SDHC->SYSCTL & SDHC_SYSCTL_RSTA_MASK){};
	//初始化SDHC相关寄存器	
	SDHC->VENDOR = 0;
	SDHC->BLKATTR = SDHC_BLKATTR_BLKCNT(1) | SDHC_BLKATTR_BLKSIZE(512); //默认传输1个Block 每个Block 512字节
	SDHC->PROCTL = SDHC_PROCTL_EMODE(2)| SDHC_PROCTL_D3CD_MASK;        //LSB格式   使用DATA3 检测卡插入移除
	SDHC->WML = SDHC_WML_RDWML(1) | SDHC_WML_WRWML(1);                 //设置读写总线缓冲区容量为1word
	//设置SDHC模块的通信速率
	SD_SetBaudRate(SD_InitStruct.SD_BaudRate); //设置SD卡通信速率为25MHZ
	while (SDHC->PRSSTAT & (SDHC_PRSSTAT_CIHB_MASK | SDHC_PRSSTAT_CDIHB_MASK)) ;
	//初始化GPIO

	SD_PortType->PCR[D1] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D1  */
	SD_PortType->PCR[D0] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D0  */
	SD_PortType->PCR[CLK] = (PORT_PCR_MUX(4) | PORT_PCR_DSE_MASK);                                          /* ESDHC.CLK */
	SD_PortType->PCR[CMD] = (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.CMD */
	SD_PortType->PCR[D3] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D3  */
	SD_PortType->PCR[D2] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D2  */		


	SDHC->IRQSTAT = 0xFFFF;
	//使能中断位
	SDHC->IRQSTATEN = SDHC_IRQSTATEN_DEBESEN_MASK 
                   | SDHC_IRQSTATEN_DCESEN_MASK 
                   | SDHC_IRQSTATEN_DTOESEN_MASK 
                   | SDHC_IRQSTATEN_CIESEN_MASK 
                   | SDHC_IRQSTATEN_CEBESEN_MASK 
                   | SDHC_IRQSTATEN_CCESEN_MASK 
                   | SDHC_IRQSTATEN_CTOESEN_MASK 
                   | SDHC_IRQSTATEN_BRRSEN_MASK 
                   | SDHC_IRQSTATEN_BWRSEN_MASK 
                   | SDHC_IRQSTATEN_CRMSEN_MASK
                   | SDHC_IRQSTATEN_TCSEN_MASK 
                   | SDHC_IRQSTATEN_CCSEN_MASK; 	
 //延时									 
	for(delay_cnt=0;delay_cnt<10000;delay_cnt++);
	//80个时钟周期的初始化
	SDHC->SYSCTL |= SDHC_SYSCTL_INITA_MASK; //确保初始化在80个sd卡时钟周期内完成 ，并且在此期间总线允许发布命令，不需要等待SD卡自我清除完毕
	while (SDHC->SYSCTL & SDHC_SYSCTL_INITA_MASK){}; //等待初始化完成
	//--------------以下开始SD卡初始化 物理层协议---------------------------
	//开始SD卡初始化进程 --------------------------------
	//说明 CMD0 -> CMD8 -> while(CMD55+ACMD41) ->CMD2 -> CMD3 ->CMD9
	//            -> CMD7(选中卡)-> CMD16(设置块大小)->(CMD55+ACMD6)设置位4线位宽
	//---------------------------正式开始------------------------------  now Let's begin !
	//CMD0  使所有卡进入IDLE
	SD_CommandStruct1.COMMAND = ESDHC_CMD0;
	SD_CommandStruct1.ARGUMENT = 0;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;      //错误则返回
		
	//CMD8  判断是V1.0还是V2.0的卡
	SD_CommandStruct1.COMMAND = ESDHC_CMD8;
	SD_CommandStruct1.ARGUMENT =0x000001AA;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if (result > 0)  //CMD8无响应  错误或者普通卡
	{
		result = ESDHC_ERROR_INIT_FAILED;
	}
	if (result == 0) //SDHC 卡
	{
		hc = TRUE;  					
	}
	//反复发送55+ACDM41 直到卡准备好
	do 
	{
		//延时									 
		for(delay_cnt=0;delay_cnt<10000;delay_cnt++);
		i++;   
		SD_CommandStruct1.COMMAND = ESDHC_CMD55;
		SD_CommandStruct1.ARGUMENT =0;
  	SD_CommandStruct1.BLOCKS = 0;
	  result = SD_SendCommand(&SD_CommandStruct1);
		
		SD_CommandStruct1.COMMAND = ESDHC_ACMD41;
		if(hc)
		{
			SD_CommandStruct1.ARGUMENT = 0x40300000;  //若是大容量SD卡   //0~2G        SDSC    标准容量SD卡
		}                                                              //2~32G       SDHC    大容量SDCH储存卡
		else                                                           //32~2T       SDXC    容量扩大化的安全储存卡
		{
			SD_CommandStruct1.ARGUMENT = 0x00300000;
		}
		result = SD_SendCommand(&SD_CommandStruct1);
	}while ((0 == (SD_CommandStruct1.RESPONSE[0] & 0x80000000)) && (i < 30));	
	//CMD2 取CID
	SD_CommandStruct1.COMMAND = ESDHC_CMD2;
	SD_CommandStruct1.ARGUMENT = 0;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	
	
	
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;    
	SD_InitStruct.CID[0] = SD_CommandStruct1.RESPONSE[0];
	SD_InitStruct.CID[1] = SD_CommandStruct1.RESPONSE[1];
	SD_InitStruct.CID[2] = SD_CommandStruct1.RESPONSE[2];
	SD_InitStruct.CID[3] = SD_CommandStruct1.RESPONSE[3];
	
	//CMD3 取RCA
	SD_CommandStruct1.COMMAND = ESDHC_CMD3;
	SD_CommandStruct1.ARGUMENT = 0;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;    
	SD_InitStruct.RCA = SD_CommandStruct1.RESPONSE[0]>>16;
	Data_SD_RCA = SD_CommandStruct1.RESPONSE[0];
	//CMD9 取CSD
	SD_CommandStruct1.COMMAND = ESDHC_CMD9;
	SD_CommandStruct1.ARGUMENT = SD_InitStruct.RCA<<16;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	SD_InitStruct.CSD[0] = SD_CommandStruct1.RESPONSE[0];
	SD_InitStruct.CSD[1] = SD_CommandStruct1.RESPONSE[1];
	SD_InitStruct.CSD[2] = SD_CommandStruct1.RESPONSE[2];
	SD_InitStruct.CSD[3] = SD_CommandStruct1.RESPONSE[3];
	
	//CMD7 选中卡
	SD_CommandStruct1.COMMAND = ESDHC_CMD7;
	SD_CommandStruct1.ARGUMENT = SD_InitStruct.RCA<<16;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	//CMD16 设置块大小
	SD_CommandStruct1.COMMAND = ESDHC_CMD16;
	SD_CommandStruct1.ARGUMENT = 512;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	
	//CMD55 使用ACMD命令
	SD_CommandStruct1.COMMAND = ESDHC_CMD55;
	SD_CommandStruct1.ARGUMENT = SD_InitStruct.RCA<<16;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	//ACMD6 修改SD卡通讯位宽
	SD_CommandStruct1.COMMAND = ESDHC_ACMD6;
	SD_CommandStruct1.ARGUMENT = 2;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);//修改SD卡位4位通讯位宽	
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	 //设置 Kinetis的 SDIO模块位4线模式
	SDHC->PROCTL &= (~SDHC_PROCTL_DTW_MASK);
	SDHC->PROCTL |=  SDHC_PROCTL_DTW(ESDHC_PROCTL_DTW_4BIT);
	//判断卡类型
	if((SD_InitStruct.CSD[3]>>22)&0x03)
	{
		Data_SD_CardType = SD_CARD_TYPE_SDHC;
	}
	else
	{
		Data_SD_CardType = SD_CARD_TYPE_SD;
	}
	
		//顺利初始化操作
	SD_InitStruct.SD_Size = SD_GetCapacity(&SD_InitStruct);
	
	Data_Count=(SD_InitStruct.SD_Size*1024*1024/512);//计算长度 为了保持sd能够高速存储
	
	return ESDHC_OK;	
}





//多块写指令初始化
void Data_SD_WT_Init(void)
{
	SD_CommandTypeDef SD_CommandStruct1;

	SD_CommandStruct1.COMMAND = ESDHC_CMD25;
	SD_CommandStruct1.BLOCKS =Data_Count;
	SD_CommandStruct1.BLOCKSIZE = 512;
	SD_CommandStruct1.ARGUMENT = 0;//sd卡初始地址
	SD_SendCommand(&SD_CommandStruct1);
	
}


//多块写指令
void Data_SD_WriteMultiBlock(const uint8_t *pbuffer,uint16_t Count)
{
	uint32_t j;
	uint8_t* ptr=(uint8_t *) pbuffer;
	 
	for (j=0 ;j<(SD_WT_BlocksNum*((SD_Block_Size+3)>>2));j++)
	{
        while (0 == (SDHC->PRSSTAT & SDHC_PRSSTAT_BWEN_MASK)){}; //等待数据准备好

        if((j<<2)<Count)
        {
                   SDHC->DATPORT =  *(uint32_t *)ptr;
                   ptr+=4;
        }
        else
        {
           SDHC->DATPORT = 0xFFFFFFFF;
        }
    }
}






//读SD卡的一个block
													  
void Data_SD_ReadSingleBlock(uint32_t sector, uint8_t *buffer,uint16_t Count)
{
	uint32_t	j;
  volatile uint32_t  temp=0xFFFFFFFF;//用来消耗一下剩余的块
    uint8_t	*ptr = (uint8_t*)buffer;
	SD_CommandTypeDef SD_CommandStruct1;
	if(Data_SD_CardType == SD_CARD_TYPE_SD) //如果是普通SD卡 把块地址转换成字节地址
	{
		sector = sector<<9;
	}
	 while (SDHC->PRSSTAT & SDHC_PRSSTAT_DLA_MASK){};//等待DATA线空闲

	 SD_CommandStruct1.COMMAND = ESDHC_CMD17;
	 SD_CommandStruct1.ARGUMENT = sector;
	 SD_CommandStruct1.BLOCKS = 1;
	 SD_CommandStruct1.BLOCKSIZE = SD_Block_Size;
   SD_SendCommand(&SD_CommandStruct1);
	
	
        for (j =0 ;j<(SD_Block_Size+3)>>2;j++)
        {
					 
						//等待数据准备好	
            while (0 == (SDHC->PRSSTAT & SDHC_PRSSTAT_BREN_MASK)) {};
            if((j<<2)<Count)
            {
						   *(uint32_t *)ptr = (uint32_t)SDHC->DATPORT;	  
						   ptr+=4;	//这里取代 *ptr++=SDHC->DATPORT;	 因为这句有BUG
            }
            else
            {
               temp=SDHC->DATPORT;
            }
						
        }

}


void Data_Read_Init(void)//读SD卡初始化
{
    Blocks_Num=0; 
}

void Data_SD_Save(void)//SD卡存储信息
{
   Set_DataToCon();

   SetFlashDataToCon();

   Compressed_Data();//压缩数据

   Data_SD_WriteMultiBlock((uint8_t *)Sent_Data,Data_All_Length);/*存取数据*/

   if(SD_ALL_WT_Count%50==0) INI_Flash_Count_Save();/*100场刷新计数一次*/
}



void Uart_Read_SD(void)//读取SD卡信息 Uart发送
{
    int i,j;
    INI_Flash_Count_Read(); //读取场数	
    OLED_Clear();//清屏
    Data_Read_Init();//SD传图初始化
    OLED_Write_String(3,1,(uint8_t*)"ALL:");
    OLED_Write_Num4(7,1,SD_ALL_WT_Count);
    OLED_Write_String(3,3,(uint8_t*)"NUM:");
    for(i=0;i<=SD_ALL_WT_Count;i++)//上传到一定数量自动关闭   SD_ALL_WT_Count
    {			
       Data_Read();//读SD卡
       OLED_Write_Num4(7,3,i);
       Data_UpLoad();//传数据 
       for(j=0;j<500000;j++){;} 
       Blocks_Num+=SD_WT_BlocksNum;
    }	
    OLED_Write_String(1,5,(uint8_t*)"READ SD IS OK.");
    while(1);
}


void OLED_Read_SD(void)//读取SD卡信息 OLED显示
{
    uint8_t Key_temp;
    int i,Par_Page;
    uint8_t Mode=0,Display_Flag=0;
    INI_Flash_Count_Read(); //读取场数		
    IT_Image_Mode_Key();//开启中断按键
    EnableInterrupts();//开启总中断
    OLED_Clear();//清屏
    Data_Read_Init();//SD传图初始化
    for(i=0;i<=SD_ALL_WT_Count;)//上传到一定数量自动关闭   SD_ALL_WT_Count
    {			
        Key_temp=get_Image_Mode_Key();//获取中断按键
    //    for(j=0;j<Key_Delay_Count;j++) {DelayMs(15); get_Image_Mode_Key();}//延时中断按键过于灵敏

        
        switch(Key_temp)
        {
            case 1:Display_Flag=~Display_Flag;Key_temp=0;OLED_Clear();break;
            case 6:if(i>0&&i<=SD_ALL_WT_Count){Blocks_Num+=SD_WT_BlocksNum;i++;}Key_temp=0;OLED_Clear();break;
            case 3:if(i>0&&i<=SD_ALL_WT_Count){Blocks_Num-=SD_WT_BlocksNum;i--;}Key_temp=0;OLED_Clear();break;
            case 2:Mode++;OLED_Clear();Key_temp=0;break;
            case 4:if(Par_Page<(DataNum+3)/4-1){Par_Page++;}else{Par_Page=0;}OLED_Clear();Key_temp=0;break;
            case 5:if(Par_Page==0){Par_Page=((DataNum+3)/4-1);}else{Par_Page--;}OLED_Clear();Key_temp=0;break;
            default:break;
        }
        
        if(Mode>3)
        {
            Mode=Mode%3;
        }
        if(Display_Flag)
        {
            if(Mode==1)
            {
                Data_Read();
                Unpack_Data(); //解压数据
                OLED_Real_Image_Dispaly();
            }
            if(Mode==2)
            {
                Data_Read();
                OLED_Fit_Image_Dispaly(); 
            }
            if(Mode==3)
            {
                Data_Read();
                OLED_Par_Dispaly_Host(Par_Page);//显示参数 本地
            }
            i++;
            Blocks_Num+=SD_WT_BlocksNum;
            DelayUs(100000/Image_SD_Speed);//调节速度
        }    
        else
        {
            if(Mode==1)
            {
                Data_Read();
                Unpack_Data(); //解压数据
                OLED_Real_Image_Dispaly();
            }
            if(Mode==2)
            {
                Data_Read();
                OLED_Fit_Image_Dispaly(); 
            }
            if(Mode==3)
            {
                Data_Read();
                OLED_Par_Dispaly_Host(Par_Page);//显示参数 本地
            }
            //DelayUs(100000/Image_SD_Speed);//调节速度            
        }



    }	
    OLED_Clear();
    OLED_Write_String(3,1,(uint8_t*)"ALL:");
    OLED_Write_Num4(7,1,SD_ALL_WT_Count);
    OLED_Write_String(3,3,(uint8_t*)"NUM:");
    OLED_Write_Num4(7,3,i-1);
    OLED_Write_String(1,5,(uint8_t*)"READ SD IS OK.");
    while(1);
}


void Data_Read(void)//读取数据到Data数组
{ 
    uint8_t i=0;
    uint16_t Data_Count =Data_All_Length;//记录长度
	 
    for(i=0;i<((Data_All_Length+SD_Block_Size-1)>>9);i++)//读一次所需的数据块数
    {
        Data_SD_ReadSingleBlock(Blocks_Num+i,(uint8_t *)Sent_Data+(i<<9),Data_Count>=SD_Block_Size?SD_Block_Size:Data_Count );
        Data_Count-=SD_Block_Size;
	}
}





