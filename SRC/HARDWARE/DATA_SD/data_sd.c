#include "data_sd.h"
#include "sd.h"
#include "data_sent.h"
#include "delay.h"
#include "key.h"
#include "oled_display.h"

extern Data_Type *Sent_Data;
uint8_t Data_SD_CardType = SD_CARD_TYPE_NONE;
uint32_t Data_SD_RCA = 0;
uint64_t Data_Count=NULL;//���ݿ鳤��

uint16_t Blocks_Num=0;//������ǵ�ַ

uint8_t Data_SD_Init(void)
{
	uint32_t delay_cnt = 0;
	uint8_t result;  //�洢�������ؽ��
	uint8_t i=0;
	uint8_t hc=0;     //�Ƿ�ΪSDHC��־
	//SD������ṹ�嶨��
	SD_CommandTypeDef SD_CommandStruct1;
	//SD���������ýṹ�嶨��
	SD_InitTypeDef SD_InitStruct;
	
	SD_InitStruct.SD_BaudRate=SD_WR_BaudRate;//���ò�����
	
	//����GPIOʱ��
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	//����SDHCʱ��
	SIM->SCGC3 |= SIM_SCGC3_SDHC_MASK;
	//��λSDHC ���ó�ʱʱ��
	SDHC->SYSCTL = SDHC_SYSCTL_RSTA_MASK | SDHC_SYSCTL_SDCLKFS(0x80); //��ʱʱ������Ϊ2^13  //2��Ƶ
	//�ȴ���λ���
	while(SDHC->SYSCTL & SDHC_SYSCTL_RSTA_MASK){};
	//��ʼ��SDHC��ؼĴ���	
	SDHC->VENDOR = 0;
	SDHC->BLKATTR = SDHC_BLKATTR_BLKCNT(1) | SDHC_BLKATTR_BLKSIZE(512); //Ĭ�ϴ���1��Block ÿ��Block 512�ֽ�
	SDHC->PROCTL = SDHC_PROCTL_EMODE(2)| SDHC_PROCTL_D3CD_MASK;        //LSB��ʽ   ʹ��DATA3 ��⿨�����Ƴ�
	SDHC->WML = SDHC_WML_RDWML(1) | SDHC_WML_WRWML(1);                 //���ö�д���߻���������Ϊ1word
	//����SDHCģ���ͨ������
	SD_SetBaudRate(SD_InitStruct.SD_BaudRate); //����SD��ͨ������Ϊ25MHZ
	while (SDHC->PRSSTAT & (SDHC_PRSSTAT_CIHB_MASK | SDHC_PRSSTAT_CDIHB_MASK)) ;
	//��ʼ��GPIO

	SD_PortType->PCR[D1] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D1  */
	SD_PortType->PCR[D0] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D0  */
	SD_PortType->PCR[CLK] = (PORT_PCR_MUX(4) | PORT_PCR_DSE_MASK);                                          /* ESDHC.CLK */
	SD_PortType->PCR[CMD] = (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.CMD */
	SD_PortType->PCR[D3] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D3  */
	SD_PortType->PCR[D2] =  (PORT_PCR_MUX(4) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK);    /* ESDHC.D2  */		


	SDHC->IRQSTAT = 0xFFFF;
	//ʹ���ж�λ
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
 //��ʱ									 
	for(delay_cnt=0;delay_cnt<10000;delay_cnt++);
	//80��ʱ�����ڵĳ�ʼ��
	SDHC->SYSCTL |= SDHC_SYSCTL_INITA_MASK; //ȷ����ʼ����80��sd��ʱ����������� �������ڴ��ڼ������������������Ҫ�ȴ�SD������������
	while (SDHC->SYSCTL & SDHC_SYSCTL_INITA_MASK){}; //�ȴ���ʼ�����
	//--------------���¿�ʼSD����ʼ�� �����Э��---------------------------
	//��ʼSD����ʼ������ --------------------------------
	//˵�� �CCMD0 -> CMD8 -> while(CMD55+ACMD41) ->CMD2 -> CMD3 ->CMD9
	//            -> CMD7(ѡ�п�)-> CMD16(���ÿ��С)->(CMD55+ACMD6)����λ4��λ��
	//---------------------------��ʽ��ʼ------------------------------  now Let's begin !
	//CMD0  ʹ���п�����IDLE
	SD_CommandStruct1.COMMAND = ESDHC_CMD0;
	SD_CommandStruct1.ARGUMENT = 0;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;      //�����򷵻�
		
	//CMD8  �ж���V1.0����V2.0�Ŀ�
	SD_CommandStruct1.COMMAND = ESDHC_CMD8;
	SD_CommandStruct1.ARGUMENT =0x000001AA;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if (result > 0)  //CMD8����Ӧ  ���������ͨ��
	{
		result = ESDHC_ERROR_INIT_FAILED;
	}
	if (result == 0) //SDHC ��
	{
		hc = TRUE;  					
	}
	//��������55+ACDM41 ֱ����׼����
	do 
	{
		//��ʱ									 
		for(delay_cnt=0;delay_cnt<10000;delay_cnt++);
		i++;   
		SD_CommandStruct1.COMMAND = ESDHC_CMD55;
		SD_CommandStruct1.ARGUMENT =0;
  	SD_CommandStruct1.BLOCKS = 0;
	  result = SD_SendCommand(&SD_CommandStruct1);
		
		SD_CommandStruct1.COMMAND = ESDHC_ACMD41;
		if(hc)
		{
			SD_CommandStruct1.ARGUMENT = 0x40300000;  //���Ǵ�����SD��   //0~2G        SDSC    ��׼����SD��
		}                                                              //2~32G       SDHC    ������SDCH���濨
		else                                                           //32~2T       SDXC    �������󻯵İ�ȫ���濨
		{
			SD_CommandStruct1.ARGUMENT = 0x00300000;
		}
		result = SD_SendCommand(&SD_CommandStruct1);
	}while ((0 == (SD_CommandStruct1.RESPONSE[0] & 0x80000000)) && (i < 30));	
	//CMD2 ȡCID
	SD_CommandStruct1.COMMAND = ESDHC_CMD2;
	SD_CommandStruct1.ARGUMENT = 0;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	
	
	
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;    
	SD_InitStruct.CID[0] = SD_CommandStruct1.RESPONSE[0];
	SD_InitStruct.CID[1] = SD_CommandStruct1.RESPONSE[1];
	SD_InitStruct.CID[2] = SD_CommandStruct1.RESPONSE[2];
	SD_InitStruct.CID[3] = SD_CommandStruct1.RESPONSE[3];
	
	//CMD3 ȡRCA
	SD_CommandStruct1.COMMAND = ESDHC_CMD3;
	SD_CommandStruct1.ARGUMENT = 0;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;    
	SD_InitStruct.RCA = SD_CommandStruct1.RESPONSE[0]>>16;
	Data_SD_RCA = SD_CommandStruct1.RESPONSE[0];
	//CMD9 ȡCSD
	SD_CommandStruct1.COMMAND = ESDHC_CMD9;
	SD_CommandStruct1.ARGUMENT = SD_InitStruct.RCA<<16;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	SD_InitStruct.CSD[0] = SD_CommandStruct1.RESPONSE[0];
	SD_InitStruct.CSD[1] = SD_CommandStruct1.RESPONSE[1];
	SD_InitStruct.CSD[2] = SD_CommandStruct1.RESPONSE[2];
	SD_InitStruct.CSD[3] = SD_CommandStruct1.RESPONSE[3];
	
	//CMD7 ѡ�п�
	SD_CommandStruct1.COMMAND = ESDHC_CMD7;
	SD_CommandStruct1.ARGUMENT = SD_InitStruct.RCA<<16;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	//CMD16 ���ÿ��С
	SD_CommandStruct1.COMMAND = ESDHC_CMD16;
	SD_CommandStruct1.ARGUMENT = 512;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	
	//CMD55 ʹ��ACMD����
	SD_CommandStruct1.COMMAND = ESDHC_CMD55;
	SD_CommandStruct1.ARGUMENT = SD_InitStruct.RCA<<16;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	//ACMD6 �޸�SD��ͨѶλ��
	SD_CommandStruct1.COMMAND = ESDHC_ACMD6;
	SD_CommandStruct1.ARGUMENT = 2;
	SD_CommandStruct1.BLOCKS = 0;
	result = SD_SendCommand(&SD_CommandStruct1);//�޸�SD��λ4λͨѶλ��	
	if(result != ESDHC_OK) return ESDHC_ERROR_INIT_FAILED;  
	 //���� Kinetis�� SDIOģ��λ4��ģʽ
	SDHC->PROCTL &= (~SDHC_PROCTL_DTW_MASK);
	SDHC->PROCTL |=  SDHC_PROCTL_DTW(ESDHC_PROCTL_DTW_4BIT);
	//�жϿ�����
	if((SD_InitStruct.CSD[3]>>22)&0x03)
	{
		Data_SD_CardType = SD_CARD_TYPE_SDHC;
	}
	else
	{
		Data_SD_CardType = SD_CARD_TYPE_SD;
	}
	
		//˳����ʼ������
	SD_InitStruct.SD_Size = SD_GetCapacity(&SD_InitStruct);
	
	Data_Count=(SD_InitStruct.SD_Size*1024*1024/512);//���㳤�� Ϊ�˱���sd�ܹ����ٴ洢
	
	return ESDHC_OK;	
}





//���дָ���ʼ��
void Data_SD_WT_Init(void)
{
	SD_CommandTypeDef SD_CommandStruct1;

	SD_CommandStruct1.COMMAND = ESDHC_CMD25;
	SD_CommandStruct1.BLOCKS =Data_Count;
	SD_CommandStruct1.BLOCKSIZE = 512;
	SD_CommandStruct1.ARGUMENT = 0;//sd����ʼ��ַ
	SD_SendCommand(&SD_CommandStruct1);
	
}


//���дָ��
void Data_SD_WriteMultiBlock(const uint8_t *pbuffer,uint16_t Count)
{
	uint32_t j;
	uint8_t* ptr=(uint8_t *) pbuffer;
	 
	for (j=0 ;j<(SD_WT_BlocksNum*((SD_Block_Size+3)>>2));j++)
	{
        while (0 == (SDHC->PRSSTAT & SDHC_PRSSTAT_BWEN_MASK)){}; //�ȴ�����׼����

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






//��SD����һ��block
													  
void Data_SD_ReadSingleBlock(uint32_t sector, uint8_t *buffer,uint16_t Count)
{
	uint32_t	j;
  volatile uint32_t  temp=0xFFFFFFFF;//��������һ��ʣ��Ŀ�
    uint8_t	*ptr = (uint8_t*)buffer;
	SD_CommandTypeDef SD_CommandStruct1;
	if(Data_SD_CardType == SD_CARD_TYPE_SD) //�������ͨSD�� �ѿ��ַת�����ֽڵ�ַ
	{
		sector = sector<<9;
	}
	 while (SDHC->PRSSTAT & SDHC_PRSSTAT_DLA_MASK){};//�ȴ�DATA�߿���

	 SD_CommandStruct1.COMMAND = ESDHC_CMD17;
	 SD_CommandStruct1.ARGUMENT = sector;
	 SD_CommandStruct1.BLOCKS = 1;
	 SD_CommandStruct1.BLOCKSIZE = SD_Block_Size;
   SD_SendCommand(&SD_CommandStruct1);
	
	
        for (j =0 ;j<(SD_Block_Size+3)>>2;j++)
        {
					 
						//�ȴ�����׼����	
            while (0 == (SDHC->PRSSTAT & SDHC_PRSSTAT_BREN_MASK)) {};
            if((j<<2)<Count)
            {
						   *(uint32_t *)ptr = (uint32_t)SDHC->DATPORT;	  
						   ptr+=4;	//����ȡ�� *ptr++=SDHC->DATPORT;	 ��Ϊ�����BUG
            }
            else
            {
               temp=SDHC->DATPORT;
            }
						
        }

}


void Data_Read_Init(void)//��SD����ʼ��
{
    Blocks_Num=0; 
}

void Data_SD_Save(void)//SD���洢��Ϣ
{
   Set_DataToCon();

   SetFlashDataToCon();

   Compressed_Data();//ѹ������

   Data_SD_WriteMultiBlock((uint8_t *)Sent_Data,Data_All_Length);/*��ȡ����*/

   if(SD_ALL_WT_Count%50==0) INI_Flash_Count_Save();/*100��ˢ�¼���һ��*/
}



void Uart_Read_SD(void)//��ȡSD����Ϣ Uart����
{
    int i,j;
    INI_Flash_Count_Read(); //��ȡ����	
    OLED_Clear();//����
    Data_Read_Init();//SD��ͼ��ʼ��
    OLED_Write_String(3,1,(uint8_t*)"ALL:");
    OLED_Write_Num4(7,1,SD_ALL_WT_Count);
    OLED_Write_String(3,3,(uint8_t*)"NUM:");
    for(i=0;i<=SD_ALL_WT_Count;i++)//�ϴ���һ�������Զ��ر�   SD_ALL_WT_Count
    {			
       Data_Read();//��SD��
       OLED_Write_Num4(7,3,i);
       Data_UpLoad();//������ 
       for(j=0;j<500000;j++){;} 
       Blocks_Num+=SD_WT_BlocksNum;
    }	
    OLED_Write_String(1,5,(uint8_t*)"READ SD IS OK.");
    while(1);
}


void OLED_Read_SD(void)//��ȡSD����Ϣ OLED��ʾ
{
    uint8_t Key_temp;
    int i,Par_Page;
    uint8_t Mode=0,Display_Flag=0;
    INI_Flash_Count_Read(); //��ȡ����		
    IT_Image_Mode_Key();//�����жϰ���
    EnableInterrupts();//�������ж�
    OLED_Clear();//����
    Data_Read_Init();//SD��ͼ��ʼ��
    for(i=0;i<=SD_ALL_WT_Count;)//�ϴ���һ�������Զ��ر�   SD_ALL_WT_Count
    {			
        Key_temp=get_Image_Mode_Key();//��ȡ�жϰ���
    //    for(j=0;j<Key_Delay_Count;j++) {DelayMs(15); get_Image_Mode_Key();}//��ʱ�жϰ�����������

        
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
                Unpack_Data(); //��ѹ����
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
                OLED_Par_Dispaly_Host(Par_Page);//��ʾ���� ����
            }
            i++;
            Blocks_Num+=SD_WT_BlocksNum;
            DelayUs(100000/Image_SD_Speed);//�����ٶ�
        }    
        else
        {
            if(Mode==1)
            {
                Data_Read();
                Unpack_Data(); //��ѹ����
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
                OLED_Par_Dispaly_Host(Par_Page);//��ʾ���� ����
            }
            //DelayUs(100000/Image_SD_Speed);//�����ٶ�            
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


void Data_Read(void)//��ȡ���ݵ�Data����
{ 
    uint8_t i=0;
    uint16_t Data_Count =Data_All_Length;//��¼����
	 
    for(i=0;i<((Data_All_Length+SD_Block_Size-1)>>9);i++)//��һ����������ݿ���
    {
        Data_SD_ReadSingleBlock(Blocks_Num+i,(uint8_t *)Sent_Data+(i<<9),Data_Count>=SD_Block_Size?SD_Block_Size:Data_Count );
        Data_Count-=SD_Block_Size;
	}
}





