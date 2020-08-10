#include "ini_flash.h" 
#include "data_sent.h" 

extern Data_Type *Sent_Data;

uint16_t P_Value[1];//鬼知道什么东西，之前摄像头的灰度，

uint8_t INI_BLOCK_NUM_CS=0;//缓存片选
uint8_t INI_Count=1;//存储配置参数的计数

uint32_t* P_INI[Par_Num+Buff_Sub];//用于作为存储的
uint16_t  P_TYPE[Par_Num+Buff_Sub];//用于存储符号
union
{
    uint32_t  word;
    uint8_t   byte[4];
}dest;


void INI_Flash_Count_Save(void)//普通保存参数 用于存储配置信息，双缓存存储
{		
	 
		if(INI_Count==1 || INI_Count==3)
		{
	     INI_Flash_Erssce();
		}
		else if(INI_Count==2 || INI_Count==4)
		{
            INI_Flash_Count_Write();
		}
		
		INI_Count++;
		if(INI_Count>=5) 
		{
			 INI_Count=1;

		}
		
	
	//	UART_printf("%d\r\n",INI_Count);
		
}



void INI_Flash_Erssce(void)//块檫除函数
{
		if(INI_BLOCK_NUM_CS==0)//对块1擦除
		{
				dest.word = (uint32_t)(INI_BLOCK_NUM1*BLOCK_SIZE);
			  FTFL->FCCOB0 = ERSSCR; // 擦除扇区命令
				// 设置目标地址
				FTFL->FCCOB1 = dest.byte[2];
				FTFL->FCCOB2 = dest.byte[1];
				FTFL->FCCOB3 = dest.byte[0];
	 
		}
		else if(INI_BLOCK_NUM_CS==1)//对块2擦除
		{
				dest.word = (uint32_t)(INI_BLOCK_NUM2*BLOCK_SIZE);
				FTFL->FCCOB0 = ERSSCR; // 擦除扇区命令
				// 设置目标地址
				FTFL->FCCOB1 = dest.byte[2];
				FTFL->FCCOB2 = dest.byte[1];
				FTFL->FCCOB3 = dest.byte[0];
		}
		
		// 清除访问错误标志位和非法访问标志位 
		FTFL->FSTAT |=(FTFL_FSTAT_ACCERR_MASK|FTFL_FSTAT_FPVIOL_MASK|FTFL_FSTAT_RDCOLERR_MASK);
		// 启动命令
		FTFL->FSTAT |= FTFL_FSTAT_CCIF_MASK;
		// 等待命令结束
		//while((FTFL->FSTAT &FTFL_FSTAT_CCIF_MASK)==0);
		
	
}

void INI_Flash_Count_Write(void)// 包含图像数量
{
    	
	uint32_t* P_FTFL_FCCOB7=(uint32_t*)&(FTFL->FCCOB7);//数据指针1


	if(INI_BLOCK_NUM_CS==0)
	{
	  dest.word = (uint32_t)(INI_BLOCK_NUM1*BLOCK_SIZE);
		INI_BLOCK_NUM_CS=1;
	}
	else if(INI_BLOCK_NUM_CS==1)
	{
    dest.word = (uint32_t)(INI_BLOCK_NUM2*BLOCK_SIZE);
		INI_BLOCK_NUM_CS=0;
    }
	 
		// 设置写入命令
	  FTFL->FCCOB0 = PGM4;

		// 设置存储地址
		FTFL->FCCOB1 = dest.byte[2];
		FTFL->FCCOB2 = dest.byte[1];
		FTFL->FCCOB3 = dest.byte[0];
		// 拷贝数据	（此数据排列按照从低位到高位存储）
				
        *(uint32_t *)P_FTFL_FCCOB7=(*(uint32_t *)P_INI[0]);

		// 清除访问错误标志位和非法访问标志位 
		FTFL->FSTAT |=(FTFL_FSTAT_ACCERR_MASK|FTFL_FSTAT_FPVIOL_MASK|FTFL_FSTAT_RDCOLERR_MASK);
		// 启动命令
		FTFL->FSTAT |= FTFL_FSTAT_CCIF_MASK;
		// 等待命令结束
		//while((FTFL->FSTAT &FTFL_FSTAT_CCIF_MASK)==0);

		//OLED_Write_Num4(0,4,(*(uint32_t *)P_INI[0]));
}


void INI_Flash_Par_Write(void)//写入参数 包含图像数量
{
#if((Par_Num>>1))  
     uint16_t i;
     uint16_t* P_FTFL_FCCOB7=(uint16_t*)&(FTFL->FCCOB7);//数据指针1
	
     dest.word = (uint32_t)(INI_BLOCK_NUM3*BLOCK_SIZE);
	
	
		FTFL->FCCOB0 = ERSSCR; // 擦除扇区命令
		// 设置目标地址
		FTFL->FCCOB1 = dest.byte[2];
		FTFL->FCCOB2 = dest.byte[1];
		FTFL->FCCOB3 = dest.byte[0];
	
    // 清除访问错误标志位和非法访问标志位 
		FTFL->FSTAT |=(FTFL_FSTAT_ACCERR_MASK|FTFL_FSTAT_FPVIOL_MASK|FTFL_FSTAT_RDCOLERR_MASK);
		// 启动命令
		FTFL->FSTAT |= FTFL_FSTAT_CCIF_MASK;
		// 等待命令结束
		while((FTFL->FSTAT &FTFL_FSTAT_CCIF_MASK)==0); 
	
		 //  DelayMs(1000);
			 
		// 设置写入命令
	    FTFL->FCCOB0 = PGM4;
	// 四字节对齐
	for(i=1;i<(Par_Num);i++)
	{
		// 设置存储地址
		FTFL->FCCOB1 = dest.byte[2];
		FTFL->FCCOB2 = dest.byte[1];
		FTFL->FCCOB3 = dest.byte[0];
		// 拷贝数据	（此数据排列按照从低位到高位存储）
        if(P_TYPE[i]==FLOAT)
        {
		 *(float *)P_FTFL_FCCOB7=(*(float *)P_INI[i]);

        }
        else if(P_TYPE[i]==IINT)
        {
            *(int *)P_FTFL_FCCOB7=(*(int *)P_INI[i]);

        }
        else if(P_TYPE[i]==UINT)
        {
            *(uint32_t *)P_FTFL_FCCOB7=(*(uint32_t *)P_INI[i]);
        }
		dest.word+=4; 

		// 清除访问错误标志位和非法访问标志位 
		FTFL->FSTAT |=(FTFL_FSTAT_ACCERR_MASK|FTFL_FSTAT_FPVIOL_MASK|FTFL_FSTAT_RDCOLERR_MASK);
		// 启动命令
		FTFL->FSTAT |= FTFL_FSTAT_CCIF_MASK;
		// 等待命令结束
		while((FTFL->FSTAT &FTFL_FSTAT_CCIF_MASK)==0);
	}
#endif
}


void INI_Flash_Count_Read(void)
{
	
	uint16_t temp1=0,temp2=0;//保存计数，用于比较
	uint32_t FlashStartAdd=0;//地址
	
	temp1=*(uint32_t *)((INI_BLOCK_NUM1<<11));//块1 计数的值
	
	temp2=*(uint32_t *)((INI_BLOCK_NUM2<<11));//块2 计数的值
	
	if(temp1==0xFFFF || (temp1!=0xFFFF && temp2!=0xFFFF && temp1<=temp2))
	{
     FlashStartAdd=(INI_BLOCK_NUM2<<11);
    }
	else if(temp2==0xFFFF  || (temp1!=0xFFFF && temp2!=0xFFFF && temp1>=temp2))
	{
     FlashStartAdd=(INI_BLOCK_NUM1<<11);
    }
	else
	{
     FlashStartAdd=(INI_BLOCK_NUM1<<11);
    }
	

    switch(P_TYPE[0])
    {
        case UINT:
            *P_INI[0] = *(uint32_t *)(FlashStartAdd); 
            break;
        case IINT:
            *P_INI[0] = *(int *)(FlashStartAdd);		//读取指定地址的数据
            break;
        case FLOAT:
            *(float *)P_INI[0] = *(float *)(FlashStartAdd);		//读取指定地址的数据
            break;
        default:break;

    }
   	
}



void INI_Flash_Par_Read(void)//读取配置参数
{
	uint16_t i = 0;
	
	uint32_t FlashStartAdd=0;//地址

    FlashStartAdd=(INI_BLOCK_NUM3<<11);
  	
	for(i=1;i<Par_Num;i++)
	{

        switch(P_TYPE[i])
        {
            case UINT:
                *P_INI[i] = *(uint16_t *)(FlashStartAdd+((i-1)<<2));
                break;
            case IINT:
                *P_INI[i] = *(int *)(FlashStartAdd+((i-1)<<2));		//读取指定地址的数据
                break;
            case FLOAT:
                *(float *)P_INI[i] = *(float *)(FlashStartAdd+((i-1)<<2));		//读取指定地址的数据
                break;
            default:break;

        }
	}
}

void INI_Flash_Init(void)
{
	//清除FMC缓冲区
	FMC->PFB0CR |= FMC_PFB0CR_S_B_INV_MASK;
	FMC->PFB1CR |= FMC_PFB0CR_S_B_INV_MASK;
	// 禁止看门狗
	WDOG->UNLOCK = 0xC520;
	WDOG->UNLOCK = 0xD928;
	WDOG->STCTRLH = 0;    // 禁止看门狗
	//检查Flash访问错误
  if(FTFL->FSTAT & FTFL_FSTAT_ACCERR_MASK)
  {
    FTFL->FSTAT |= FTFL_FSTAT_ACCERR_MASK;       //清除错误标志
  }
  //检查保护错误
  else if (FTFL->FSTAT & FTFL_FSTAT_FPVIOL_MASK)
  {
    FTFL->FSTAT |= FTFL_FSTAT_FPVIOL_MASK;
  }
  //检查读冲突错误
  else if (FTFL->FSTAT & FTFL_FSTAT_RDCOLERR_MASK)
  {
    FTFL->FSTAT |= FTFL_FSTAT_RDCOLERR_MASK;
  }
  //禁用Flash模块的数据缓存
  FMC->PFB0CR &= ~FMC_PFB0CR_B0DCE_MASK;
  FMC->PFB1CR &= ~FMC_PFB1CR_B1DCE_MASK;
//参数赋值表  





#if(Par_Num)   
    #if(Par_Num>=1)
    {
       P_INI[0]=(uint32_t *)&DefaultFlashValue1;
       P_TYPE[0]=DefaultFlashType1;
    }
    #endif
    #if(Par_Num>=2)
    {
       P_INI[1]=(uint32_t *)&DefaultFlashValue2;
       P_TYPE[1]=DefaultFlashType2;
    }
    #endif
    #if(Par_Num>=3)
    {
       P_INI[2]=(uint32_t *)&DefaultFlashValue3;
       P_TYPE[2]=DefaultFlashType3;
    }
    #endif
    #if(Par_Num>=4)
    {
       P_INI[3]=(uint32_t *)&DefaultFlashValue4;
       P_TYPE[3]=DefaultFlashType4;
    }
    #endif
    #if(Par_Num>=5)
    {
       P_INI[4]=(uint32_t *)&DefaultFlashValue5;
       P_TYPE[4]=DefaultFlashType5;
    }
    #endif
    #if(Par_Num>=6)
    {
       P_INI[5]=(uint32_t *)&DefaultFlashValue6;
       P_TYPE[5]=DefaultFlashType6;
    }
    #endif
    #if(Par_Num>=7)
    {
       P_INI[6]=(uint32_t *)&DefaultFlashValue7;
       P_TYPE[6]=DefaultFlashType7;
    }
    #endif
    #if(Par_Num>=8)
    {
       P_INI[7]=(uint32_t *)&DefaultFlashValue8;
       P_TYPE[7]=DefaultFlashType8;
    }
    #endif
    #if(Par_Num>=9)
    {
       P_INI[8]=(uint32_t *)&DefaultFlashValue9;
       P_TYPE[8]=DefaultFlashType9;
    }
    #endif
    #if(Par_Num>=10)
    {
       P_INI[9]=(uint32_t *)&DefaultFlashValue10;
       P_TYPE[9]=DefaultFlashType10;
    }
    #endif
    #if(Par_Num>=11)
    {
       P_INI[10]=(uint32_t *)&DefaultFlashValue11;
       P_TYPE[10]=DefaultFlashType11;
    }
    #endif
    #if(Par_Num>=12)
    {
       P_INI[81]=(uint32_t *)&DefaultFlashValue12;
       P_TYPE[81]=DefaultFlashType12;
    }
    #endif
    #if(Par_Num>=13)
    {
       P_INI[82]=(uint32_t *)&DefaultFlashValue13;
       P_TYPE[82]=DefaultFlashType13;
    }
    #endif
    #if(Par_Num>=14)
    {
       P_INI[83]=(uint32_t *)&DefaultFlashValue14;
       P_TYPE[83]=DefaultFlashType14;
    }
    #endif
    #if(Par_Num>=15)
    {
       P_INI[84]=(uint32_t *)&DefaultFlashValue15;
       P_TYPE[84]=DefaultFlashType15;
    }
    #endif
    #if(Par_Num>=16)
    {
       P_INI[85]=(uint32_t *)&DefaultFlashValue16;
       P_TYPE[85]=DefaultFlashType16;
    }
    #endif
    #if(Par_Num>=17)
    {
       P_INI[86]=(uint32_t *)&DefaultFlashValue17;
       P_TYPE[86]=DefaultFlashType17;
    }
    #endif
    #if(Par_Num>=18)
    {
       P_INI[87]=(uint32_t *)&DefaultFlashValue18;
       P_TYPE[87]=DefaultFlashType18;
    }
    #endif
    #if(Par_Num>=19)
    {
       P_INI[88]=(uint32_t *)&DefaultFlashValue19;
       P_TYPE[88]=DefaultFlashType19;
    }
    #endif
    #if(Par_Num>=20)
    {
       P_INI[89]=(uint32_t *)&DefaultFlashValue20;
       P_TYPE[89]=DefaultFlashType20;
    }
    #endif
    #if(Par_Num>=21)
    {
       P_INI[90]=(uint32_t *)&DefaultFlashValue21;
       P_TYPE[90]=DefaultFlashType21;
    }
    #endif
    #if(Par_Num>=22)
    {
       P_INI[91]=(uint32_t *)&DefaultFlashValue22;
       P_TYPE[91]=DefaultFlashType22;
    }
    #endif
    #if(Par_Num>=23)
    {
       P_INI[92]=(uint32_t *)&DefaultFlashValue23;
       P_TYPE[92]=DefaultFlashType23;
    }
    #endif
    #if(Par_Num>=24)
    {
       P_INI[93]=(uint32_t *)&DefaultFlashValue24;
       P_TYPE[93]=DefaultFlashType24;
    }
    #endif
    #if(Par_Num>=25)
    {
       P_INI[94]=(uint32_t *)&DefaultFlashValue25;
       P_TYPE[94]=DefaultFlashType25;
    }
    #endif
    #if(Par_Num>=26)
    {
       P_INI[95]=(uint32_t *)&DefaultFlashValue26;
       P_TYPE[95]=DefaultFlashType26;
    }
    #endif
    #if(Par_Num>=27)
    {
       P_INI[96]=(uint32_t *)&DefaultFlashValue27;
       P_TYPE[96]=DefaultFlashType27;
    }
    #endif
    #if(Par_Num>=28)
    {
       P_INI[97]=(uint32_t *)&DefaultFlashValue28;
       P_TYPE[97]=DefaultFlashType28;
    }
    #endif
    #if(Par_Num>=29)
    {
       P_INI[98]=(uint32_t *)&DefaultFlashValue29;
       P_TYPE[98]=DefaultFlashType29;
    }
    #endif
    #if(Par_Num>=30)
    {
       P_INI[99]=(uint32_t *)&DefaultFlashValue30;
       P_TYPE[99]=DefaultFlashType30;
    }
    #endif
    #if(Par_Num>=31)
    {
       P_INI[100]=(uint32_t *)&DefaultFlashValue31;
       P_TYPE[100]=DefaultFlashType31;
    }
    #endif
    #if(Par_Num>=32)
    {
       P_INI[101]=(uint32_t *)&DefaultFlashValue32;
       P_TYPE[101]=DefaultFlashType32;
    }
    #endif
    #if(Par_Num>=33)
    {
       P_INI[102]=(uint32_t *)&DefaultFlashValue33;
       P_TYPE[102]=DefaultFlashType33;
    }
    #endif
    #if(Par_Num>=34)
    {
       P_INI[103]=(uint32_t *)&DefaultFlashValue34;
       P_TYPE[103]=DefaultFlashType34;
    }
    #endif
    #if(Par_Num>=35)
    {
       P_INI[104]=(uint32_t *)&DefaultFlashValue35;
       P_TYPE[104]=DefaultFlashType35;
    }
    #endif
    #if(Par_Num>=36)
    {
       P_INI[105]=(uint32_t *)&DefaultFlashValue36;
       P_TYPE[105]=DefaultFlashType36;
    }
    #endif
    #if(Par_Num>=37)
    {
       P_INI[106]=(uint32_t *)&DefaultFlashValue37;
       P_TYPE[106]=DefaultFlashType37;
    }
    #endif
    #if(Par_Num>=38)
    {
       P_INI[107]=(uint32_t *)&DefaultFlashValue38;
       P_TYPE[107]=DefaultFlashType38;
    }
    #endif
    #if(Par_Num>=39)
    {
       P_INI[108]=(uint32_t *)&DefaultFlashValue39;
       P_TYPE[108]=DefaultFlashType39;
    }
    #endif
    #if(Par_Num>=40)
    {
       P_INI[109]=(uint32_t *)&DefaultFlashValue40;
       P_TYPE[109]=DefaultFlashType40;
    }
    #endif
    #if(Par_Num>=41)
    {
       P_INI[110]=(uint32_t *)&DefaultFlashValue41;
       P_TYPE[110]=DefaultFlashType41;
    }
    #endif
    #if(Par_Num>=42)
    {
       P_INI[111]=(uint32_t *)&DefaultFlashValue42;
       P_TYPE[111]=DefaultFlashType42;
    }
    #endif
    #if(Par_Num>=43)
    {
       P_INI[112]=(uint32_t *)&DefaultFlashValue43;
       P_TYPE[112]=DefaultFlashType43;
    }
    #endif
    #if(Par_Num>=44)
    {
       P_INI[113]=(uint32_t *)&DefaultFlashValue44;
       P_TYPE[113]=DefaultFlashType44;
    }
    #endif
    #if(Par_Num>=45)
    {
       P_INI[114]=(uint32_t *)&DefaultFlashValue45;
       P_TYPE[114]=DefaultFlashType45;
    }
    #endif
    #if(Par_Num>=46)
    {
       P_INI[115]=(uint32_t *)&DefaultFlashValue46;
       P_TYPE[115]=DefaultFlashType46;
    }
    #endif
    #if(Par_Num>=47)
    {
       P_INI[116]=(uint32_t *)&DefaultFlashValue47;
       P_TYPE[116]=DefaultFlashType47;
    }
    #endif
    #if(Par_Num>=48)
    {
       P_INI[117]=(uint32_t *)&DefaultFlashValue48;
       P_TYPE[117]=DefaultFlashType48;
    }
    #endif
    #if(Par_Num>=49)
    {
       P_INI[118]=(uint32_t *)&DefaultFlashValue49;
       P_TYPE[118]=DefaultFlashType49;
    }
    #endif
    #if(Par_Num>=50)
    {
       P_INI[119]=(uint32_t *)&DefaultFlashValue50;
       P_TYPE[119]=DefaultFlashType50;
    }
    #endif
    #if(Par_Num>=51)
    {
       P_INI[120]=(uint32_t *)&DefaultFlashValue51;
       P_TYPE[120]=DefaultFlashType51;
    }
    #endif
    #if(Par_Num>=52)
    {
       P_INI[121]=(uint32_t *)&DefaultFlashValue52;
       P_TYPE[121]=DefaultFlashType52;
    }
    #endif
    #if(Par_Num>=53)
    {
       P_INI[122]=(uint32_t *)&DefaultFlashValue53;
       P_TYPE[122]=DefaultFlashType53;
    }
    #endif
    #if(Par_Num>=54)
    {
       P_INI[123]=(uint32_t *)&DefaultFlashValue54;
       P_TYPE[123]=DefaultFlashType54;
    }
    #endif
    #if(Par_Num>=55)
    {
       P_INI[124]=(uint32_t *)&DefaultFlashValue55;
       P_TYPE[124]=DefaultFlashType55;
    }
    #endif
    #if(Par_Num>=56)
    {
       P_INI[125]=(uint32_t *)&DefaultFlashValue56;
       P_TYPE[125]=DefaultFlashType56;
    }
    #endif
    #if(Par_Num>=57)
    {
       P_INI[126]=(uint32_t *)&DefaultFlashValue57;
       P_TYPE[126]=DefaultFlashType57;
    }
    #endif
    #if(Par_Num>=58)
    {
       P_INI[127]=(uint32_t *)&DefaultFlashValue58;
       P_TYPE[127]=DefaultFlashType58;
    }
    #endif
    #if(Par_Num>=59)
    {
       P_INI[128]=(uint32_t *)&DefaultFlashValue59;
       P_TYPE[128]=DefaultFlashType59;
    }
    #endif
    #if(Par_Num>=60)
    {
       P_INI[129]=(uint32_t *)&DefaultFlashValue60;
       P_TYPE[129]=DefaultFlashType60;
    }
    #endif
    #if(Par_Num>=61)
    {
       P_INI[130]=(uint32_t *)&DefaultFlashValue61;
       P_TYPE[130]=DefaultFlashType61;
    }
    #endif
    #if(Par_Num>=62)
    {
       P_INI[131]=(uint32_t *)&DefaultFlashValue62;
       P_TYPE[131]=DefaultFlashType62;
    }
    #endif
    #if(Par_Num>=63)
    {
       P_INI[132]=(uint32_t *)&DefaultFlashValue63;
       P_TYPE[132]=DefaultFlashType63;
    }
    #endif
    #if(Par_Num>=64)
    {
       P_INI[133]=(uint32_t *)&DefaultFlashValue64;
       P_TYPE[133]=DefaultFlashType64;
    }
    #endif
    #if(Par_Num>=65)
    {
       P_INI[134]=(uint32_t *)&DefaultFlashValue65;
       P_TYPE[134]=DefaultFlashType65;
    }
    #endif
    #if(Par_Num>=66)
    {
       P_INI[135]=(uint32_t *)&DefaultFlashValue66;
       P_TYPE[135]=DefaultFlashType66;
    }
    #endif
    #if(Par_Num>=67)
    {
       P_INI[136]=(uint32_t *)&DefaultFlashValue67;
       P_TYPE[136]=DefaultFlashType67;
    }
    #endif
    #if(Par_Num>=68)
    {
       P_INI[137]=(uint32_t *)&DefaultFlashValue68;
       P_TYPE[137]=DefaultFlashType68;
    }
    #endif
    #if(Par_Num>=69)
    {
       P_INI[138]=(uint32_t *)&DefaultFlashValue69;
       P_TYPE[138]=DefaultFlashType69;
    }
    #endif
    #if(Par_Num>=70)
    {
       P_INI[139]=(uint32_t *)&DefaultFlashValue70;
       P_TYPE[139]=DefaultFlashType70;
    }
    #endif
    #if(Par_Num>=71)
    {
       P_INI[140]=(uint32_t *)&DefaultFlashValue71;
       P_TYPE[140]=DefaultFlashType71;
    }
    #endif
    #if(Par_Num>=72)
    {
       P_INI[141]=(uint32_t *)&DefaultFlashValue72;
       P_TYPE[141]=DefaultFlashType72;
    }
    #endif
    #if(Par_Num>=73)
    {
       P_INI[142]=(uint32_t *)&DefaultFlashValue73;
       P_TYPE[142]=DefaultFlashType73;
    }
    #endif
    #if(Par_Num>=74)
    {
       P_INI[143]=(uint32_t *)&DefaultFlashValue74;
       P_TYPE[143]=DefaultFlashType74;
    }
    #endif
    #if(Par_Num>=75)
    {
       P_INI[144]=(uint32_t *)&DefaultFlashValue75;
       P_TYPE[144]=DefaultFlashType75;
    }
    #endif
    #if(Par_Num>=76)
    {
       P_INI[145]=(uint32_t *)&DefaultFlashValue76;
       P_TYPE[145]=DefaultFlashType76;
    }
    #endif
    #if(Par_Num>=77)
    {
       P_INI[146]=(uint32_t *)&DefaultFlashValue77;
       P_TYPE[146]=DefaultFlashType77;
    }
    #endif
    #if(Par_Num>=78)
    {
       P_INI[147]=(uint32_t *)&DefaultFlashValue78;
       P_TYPE[147]=DefaultFlashType78;
    }
    #endif
    #if(Par_Num>=79)
    {
       P_INI[148]=(uint32_t *)&DefaultFlashValue79;
       P_TYPE[148]=DefaultFlashType79;
    }
    #endif
    #if(Par_Num>=80)
    {
       P_INI[149]=(uint32_t *)&DefaultFlashValue80;
       P_TYPE[149]=DefaultFlashType80;
    }
    #endif
    #if(Par_Num>=81)
    {
       P_INI[150]=(uint32_t *)&DefaultFlashValue81;
       P_TYPE[150]=DefaultFlashType81;
    }
    #endif
    #if(Par_Num>=82)
    {
       P_INI[151]=(uint32_t *)&DefaultFlashValue82;
       P_TYPE[151]=DefaultFlashType82;
    }
    #endif
    #if(Par_Num>=83)
    {
       P_INI[152]=(uint32_t *)&DefaultFlashValue83;
       P_TYPE[152]=DefaultFlashType83;
    }
    #endif
    #if(Par_Num>=84)
    {
       P_INI[153]=(uint32_t *)&DefaultFlashValue84;
       P_TYPE[153]=DefaultFlashType84;
    }
    #endif
    #if(Par_Num>=85)
    {
       P_INI[154]=(uint32_t *)&DefaultFlashValue85;
       P_TYPE[154]=DefaultFlashType85;
    }
    #endif
    #if(Par_Num>=86)
    {
       P_INI[155]=(uint32_t *)&DefaultFlashValue86;
       P_TYPE[155]=DefaultFlashType86;
    }
    #endif
    #if(Par_Num>=87)
    {
       P_INI[156]=(uint32_t *)&DefaultFlashValue87;
       P_TYPE[156]=DefaultFlashType87;
    }
    #endif
    #if(Par_Num>=88)
    {
       P_INI[157]=(uint32_t *)&DefaultFlashValue88;
       P_TYPE[157]=DefaultFlashType88;
    }
    #endif
    #if(Par_Num>=89)
    {
       P_INI[158]=(uint32_t *)&DefaultFlashValue89;
       P_TYPE[158]=DefaultFlashType89;
    }
    #endif
    #if(Par_Num>=90)
    {
       P_INI[159]=(uint32_t *)&DefaultFlashValue90;
       P_TYPE[159]=DefaultFlashType90;
    }
    #endif
    #if(Par_Num>=91)
    {
       P_INI[160]=(uint32_t *)&DefaultFlashValue91;
       P_TYPE[160]=DefaultFlashType91;
    }
    #endif
    #if(Par_Num>=92)
    {
       P_INI[161]=(uint32_t *)&DefaultFlashValue92;
       P_TYPE[161]=DefaultFlashType92;
    }
    #endif
    #if(Par_Num>=93)
    {
       P_INI[162]=(uint32_t *)&DefaultFlashValue93;
       P_TYPE[162]=DefaultFlashType93;
    }
    #endif
    #if(Par_Num>=94)
    {
       P_INI[163]=(uint32_t *)&DefaultFlashValue94;
       P_TYPE[163]=DefaultFlashType94;
    }
    #endif
    #if(Par_Num>=95)
    {
       P_INI[164]=(uint32_t *)&DefaultFlashValue95;
       P_TYPE[164]=DefaultFlashType95;
    }
    #endif
    #if(Par_Num>=96)
    {
       P_INI[165]=(uint32_t *)&DefaultFlashValue96;
       P_TYPE[165]=DefaultFlashType96;
    }
    #endif
    #if(Par_Num>=97)
    {
       P_INI[166]=(uint32_t *)&DefaultFlashValue97;
       P_TYPE[166]=DefaultFlashType97;
    }
    #endif
    #if(Par_Num>=98)
    {
       P_INI[167]=(uint32_t *)&DefaultFlashValue98;
       P_TYPE[167]=DefaultFlashType98;
    }
    #endif
    #if(Par_Num>=99)
    {
       P_INI[168]=(uint32_t *)&DefaultFlashValue99;
       P_TYPE[168]=DefaultFlashType99;
    }
    #endif
    #if(Par_Num>=100)
    {
       P_INI[169]=(uint32_t *)&DefaultFlashValue100;
       P_TYPE[169]=DefaultFlashType100;
    }
    #endif
    #if(Par_Num>=101)
    {
       P_INI[170]=(uint32_t *)&DefaultFlashValue101;
       P_TYPE[170]=DefaultFlashType101;
    }
    #endif
    #if(Par_Num>=102)
    {
       P_INI[171]=(uint32_t *)&DefaultFlashValue102;
       P_TYPE[171]=DefaultFlashType102;
    }
    #endif
    #if(Par_Num>=103)
    {
       P_INI[172]=(uint32_t *)&DefaultFlashValue103;
       P_TYPE[172]=DefaultFlashType103;
    }
    #endif
    #if(Par_Num>=104)
    {
       P_INI[173]=(uint32_t *)&DefaultFlashValue104;
       P_TYPE[173]=DefaultFlashType104;
    }
    #endif
    #if(Par_Num>=105)
    {
       P_INI[174]=(uint32_t *)&DefaultFlashValue105;
       P_TYPE[174]=DefaultFlashType105;
    }
    #endif
    #if(Par_Num>=106)
    {
       P_INI[175]=(uint32_t *)&DefaultFlashValue106;
       P_TYPE[175]=DefaultFlashType106;
    }
    #endif
    #if(Par_Num>=107)
    {
       P_INI[176]=(uint32_t *)&DefaultFlashValue107;
       P_TYPE[176]=DefaultFlashType107;
    }
    #endif
    #if(Par_Num>=108)
    {
       P_INI[177]=(uint32_t *)&DefaultFlashValue108;
       P_TYPE[177]=DefaultFlashType108;
    }
    #endif
    #if(Par_Num>=109)
    {
       P_INI[178]=(uint32_t *)&DefaultFlashValue109;
       P_TYPE[178]=DefaultFlashType109;
    }
    #endif
    #if(Par_Num>=110)
    {
       P_INI[179]=(uint32_t *)&DefaultFlashValue110;
       P_TYPE[179]=DefaultFlashType110;
    }
    #endif
    #if(Par_Num>=111)
    {
       P_INI[180]=(uint32_t *)&DefaultFlashValue111;
       P_TYPE[180]=DefaultFlashType111;
    }
    #endif
    #if(Par_Num>=112)
    {
       P_INI[181]=(uint32_t *)&DefaultFlashValue112;
       P_TYPE[181]=DefaultFlashType112;
    }
    #endif
    #if(Par_Num>=113)
    {
       P_INI[182]=(uint32_t *)&DefaultFlashValue113;
       P_TYPE[182]=DefaultFlashType113;
    }
    #endif
    #if(Par_Num>=114)
    {
       P_INI[183]=(uint32_t *)&DefaultFlashValue114;
       P_TYPE[183]=DefaultFlashType114;
    }
    #endif
    #if(Par_Num>=115)
    {
       P_INI[184]=(uint32_t *)&DefaultFlashValue115;
       P_TYPE[184]=DefaultFlashType115;
    }
    #endif
    #if(Par_Num>=116)
    {
       P_INI[185]=(uint32_t *)&DefaultFlashValue116;
       P_TYPE[185]=DefaultFlashType116;
    }
    #endif
    #if(Par_Num>=117)
    {
       P_INI[186]=(uint32_t *)&DefaultFlashValue117;
       P_TYPE[186]=DefaultFlashType117;
    }
    #endif
    #if(Par_Num>=118)
    {
       P_INI[187]=(uint32_t *)&DefaultFlashValue118;
       P_TYPE[187]=DefaultFlashType118;
    }
    #endif
    #if(Par_Num>=119)
    {
       P_INI[188]=(uint32_t *)&DefaultFlashValue119;
       P_TYPE[188]=DefaultFlashType119;
    }
    #endif
    #if(Par_Num>=120)
    {
       P_INI[189]=(uint32_t *)&DefaultFlashValue120;
       P_TYPE[189]=DefaultFlashType120;
    }
    #endif
    #if(Par_Num>=121)
    {
       P_INI[190]=(uint32_t *)&DefaultFlashValue121;
       P_TYPE[190]=DefaultFlashType121;
    }
    #endif
    #if(Par_Num>=122)
    {
       P_INI[191]=(uint32_t *)&DefaultFlashValue122;
       P_TYPE[191]=DefaultFlashType122;
    }
    #endif
    #if(Par_Num>=123)
    {
       P_INI[192]=(uint32_t *)&DefaultFlashValue123;
       P_TYPE[192]=DefaultFlashType123;
    }
    #endif
    #if(Par_Num>=124)
    {
       P_INI[193]=(uint32_t *)&DefaultFlashValue124;
       P_TYPE[193]=DefaultFlashType124;
    }
    #endif
    #if(Par_Num>=125)
    {
       P_INI[194]=(uint32_t *)&DefaultFlashValue125;
       P_TYPE[194]=DefaultFlashType125;
    }
    #endif
    #if(Par_Num>=126)
    {
       P_INI[195]=(uint32_t *)&DefaultFlashValue126;
       P_TYPE[195]=DefaultFlashType126;
    }
    #endif
    #if(Par_Num>=127)
    {
       P_INI[196]=(uint32_t *)&DefaultFlashValue127;
       P_TYPE[196]=DefaultFlashType127;
    }
    #endif
    #if(Par_Num>=128)
    {
       P_INI[197]=(uint32_t *)&DefaultFlashValue128;
       P_TYPE[197]=DefaultFlashType128;
    }
    #endif
    #if(Par_Num>=129)
    {
       P_INI[198]=(uint32_t *)&DefaultFlashValue120;
       P_TYPE[198]=DefaultFlashType120;
    }
    #endif
    #if(Par_Num>=130)
    {
       P_INI[199]=(uint32_t *)&DefaultFlashValue130;
       P_TYPE[199]=DefaultFlashType130;
    }
    #endif
    #if(Par_Num>=131)
    {
       P_INI[200]=(uint32_t *)&DefaultFlashValue131;
       P_TYPE[200]=DefaultFlashType131;
    }
    #endif
    #if(Par_Num>=132)
    {
       P_INI[201]=(uint32_t *)&DefaultFlashValue132;
       P_TYPE[201]=DefaultFlashType132;
    }
    #endif
    #if(Par_Num>=133)
    {
       P_INI[202]=(uint32_t *)&DefaultFlashValue133;
       P_TYPE[202]=DefaultFlashType133;
    }
    #endif
    #if(Par_Num>=134)
    {
       P_INI[203]=(uint32_t *)&DefaultFlashValue134;
       P_TYPE[203]=DefaultFlashType134;
    }
    #endif
    #if(Par_Num>=135)
    {
       P_INI[204]=(uint32_t *)&DefaultFlashValue135;
       P_TYPE[204]=DefaultFlashType135;
    }
    #endif
    #if(Par_Num>=136)
    {
       P_INI[205]=(uint32_t *)&DefaultFlashValue136;
       P_TYPE[205]=DefaultFlashType136;
    }
    #endif
    #if(Par_Num>=137)
    {
       P_INI[206]=(uint32_t *)&DefaultFlashValue137;
       P_TYPE[206]=DefaultFlashType137;
    }
    #endif
    #if(Par_Num>=138)
    {
       P_INI[207]=(uint32_t *)&DefaultFlashValue138;
       P_TYPE[207]=DefaultFlashType138;
    }
    #endif
    #if(Par_Num>=139)
    {
       P_INI[208]=(uint32_t *)&DefaultFlashValue139;
       P_TYPE[208]=DefaultFlashType139;
    }
    #endif
    #if(Par_Num>=140)
    {
       P_INI[209]=(uint32_t *)&DefaultFlashValue140;
       P_TYPE[209]=DefaultFlashType140;
    }
    #endif
    #if(Par_Num>=141)
    {
       P_INI[210]=(uint32_t *)&DefaultFlashValue141;
       P_TYPE[210]=DefaultFlashType141;
    }
    #endif
    #if(Par_Num>=142)
    {
       P_INI[211]=(uint32_t *)&DefaultFlashValue142;
       P_TYPE[211]=DefaultFlashType142;
    }
    #endif
    #if(Par_Num>=143)
    {
       P_INI[212]=(uint32_t *)&DefaultFlashValue143;
       P_TYPE[212]=DefaultFlashType143;
    }
    #endif
    #if(Par_Num>=144)
    {
       P_INI[213]=(uint32_t *)&DefaultFlashValue144;
       P_TYPE[213]=DefaultFlashType144;
    }
    #endif
    #if(Par_Num>=145)
    {
       P_INI[214]=(uint32_t *)&DefaultFlashValue145;
       P_TYPE[214]=DefaultFlashType145;
    }
    #endif
    #if(Par_Num>=146)
    {
       P_INI[215]=(uint32_t *)&DefaultFlashValue146;
       P_TYPE[215]=DefaultFlashType146;
    }
    #endif
    #if(Par_Num>=147)
    {
       P_INI[216]=(uint32_t *)&DefaultFlashValue147;
       P_TYPE[216]=DefaultFlashType147;
    }
    #endif
    #if(Par_Num>=148)
    {
       P_INI[217]=(uint32_t *)&DefaultFlashValue148;
       P_TYPE[217]=DefaultFlashType148;
    }
    #endif
    #if(Par_Num>=149)
    {
       P_INI[218]=(uint32_t *)&DefaultFlashValue149;
       P_TYPE[218]=DefaultFlashType149;
    }
    #endif
    #if(Par_Num>=150)
    {
       P_INI[219]=(uint32_t *)&DefaultFlashValue150;
       P_TYPE[219]=DefaultFlashType150;
    }
    #endif
    #if(Par_Num>=151)
    {
       P_INI[220]=(uint32_t *)&DefaultFlashValue151;
       P_TYPE[220]=DefaultFlashType151;
    }
    #endif
    #if(Par_Num>=152)
    {
       P_INI[221]=(uint32_t *)&DefaultFlashValue152;
       P_TYPE[221]=DefaultFlashType152;
    }
    #endif
    #if(Par_Num>=153)
    {
       P_INI[222]=(uint32_t *)&DefaultFlashValue153;
       P_TYPE[222]=DefaultFlashType153;
    }
    #endif
    #if(Par_Num>=154)
    {
       P_INI[223]=(uint32_t *)&DefaultFlashValue154;
       P_TYPE[223]=DefaultFlashType154;
    }
    #endif
    #if(Par_Num>=155)
    {
       P_INI[224]=(uint32_t *)&DefaultFlashValue155;
       P_TYPE[224]=DefaultFlashType155;
    }
    #endif
    #if(Par_Num>=156)
    {
       P_INI[225]=(uint32_t *)&DefaultFlashValue156;
       P_TYPE[225]=DefaultFlashType156;
    }
    #endif
    #if(Par_Num>=157)
    {
       P_INI[226]=(uint32_t *)&DefaultFlashValue157;
       P_TYPE[226]=DefaultFlashType157;
    }
    #endif
    #if(Par_Num>=158)
    {
       P_INI[227]=(uint32_t *)&DefaultFlashValue158;
       P_TYPE[227]=DefaultFlashType158;
    }
    #endif
    #if(Par_Num>=159)
    {
       P_INI[228]=(uint32_t *)&DefaultFlashValue159;
       P_TYPE[228]=DefaultFlashType159;
    }
    #endif
    #if(Par_Num>=160)
    {
       P_INI[229]=(uint32_t *)&DefaultFlashValue160;
       P_TYPE[229]=DefaultFlashType160;
    }
    #endif
    #if(Par_Num>=161)
    {
       P_INI[230]=(uint32_t *)&DefaultFlashValue161;
       P_TYPE[230]=DefaultFlashType161;
    }
    #endif
    #if(Par_Num>=162)
    {
       P_INI[231]=(uint32_t *)&DefaultFlashValue162;
       P_TYPE[231]=DefaultFlashType162;
    }
    #endif
    #if(Par_Num>=163)
    {
       P_INI[232]=(uint32_t *)&DefaultFlashValue163;
       P_TYPE[232]=DefaultFlashType163;
    }
    #endif
    #if(Par_Num>=164)
    {
       P_INI[233]=(uint32_t *)&DefaultFlashValue416;
       P_TYPE[233]=DefaultFlashType164;
    }
    #endif
    #if(Par_Num>=165)
    {
       P_INI[234]=(uint32_t *)&DefaultFlashValue165;
       P_TYPE[234]=DefaultFlashType165;
    }
    #endif
    #if(Par_Num>=166)
    {
       P_INI[235]=(uint32_t *)&DefaultFlashValue166;
       P_TYPE[235]=DefaultFlashType166;
    }
    #endif
    #if(Par_Num>=167)
    {
       P_INI[236]=(uint32_t *)&DefaultFlashValue167;
       P_TYPE[236]=DefaultFlashType167;
    }
    #endif
    #if(Par_Num>=168)
    {
       P_INI[237]=(uint32_t *)&DefaultFlashValue168;
       P_TYPE[237]=DefaultFlashType168;
    }
    #endif
    #if(Par_Num>=169)
    {
       P_INI[238]=(uint32_t *)&DefaultFlashValue169;
       P_TYPE[238]=DefaultFlashType169;
    }
    #endif
    #if(Par_Num>=170)
    {
       P_INI[239]=(uint32_t *)&DefaultFlashValue170;
       P_TYPE[239]=DefaultFlashType170;
    }
    #endif
    #if(Par_Num>=171)
    {
       P_INI[240]=(uint32_t *)&DefaultFlashValue171;
       P_TYPE[240]=DefaultFlashType171;
    }
    #endif
    #if(Par_Num>=172)
    {
       P_INI[241]=(uint32_t *)&DefaultFlashValue172;
       P_TYPE[241]=DefaultFlashType172;
    }
    #endif
    #if(Par_Num>=173)
    {
       P_INI[242]=(uint32_t *)&DefaultFlashValue173;
       P_TYPE[242]=DefaultFlashType173;
    }
    #endif
    #if(Par_Num>=174)
    {
       P_INI[243]=(uint32_t *)&DefaultFlashValue174;
       P_TYPE[243]=DefaultFlashType174;
    }
    #endif
    #if(Par_Num>=175)
    {
       P_INI[244]=(uint32_t *)&DefaultFlashValue175;
       P_TYPE[244]=DefaultFlashType175;
    }
    #endif
    #if(Par_Num>=176)
    {
       P_INI[245]=(uint32_t *)&DefaultFlashValue176;
       P_TYPE[245]=DefaultFlashType176;
    }
    #endif
    #if(Par_Num>=177)
    {
       P_INI[246]=(uint32_t *)&DefaultFlashValue177;
       P_TYPE[246]=DefaultFlashType177;
    }
    #endif
    #if(Par_Num>=178)
    {
       P_INI[247]=(uint32_t *)&DefaultFlashValue178;
       P_TYPE[247]=DefaultFlashType178;
    }
    #endif
    #if(Par_Num>=179)
    {
       P_INI[248]=(uint32_t *)&DefaultFlashValue179;
       P_TYPE[248]=DefaultFlashType179;
    }
    #endif
    #if(Par_Num>=180)
    {
       P_INI[249]=(uint32_t *)&DefaultFlashValue180;
       P_TYPE[249]=DefaultFlashType180;
    }
    #endif
    #if(Par_Num>=181)
    {
       P_INI[250]=(uint32_t *)&DefaultFlashValue181;
       P_TYPE[250]=DefaultFlashType181;
    }
    #endif
    #if(Par_Num>=182)
    {
       P_INI[251]=(uint32_t *)&DefaultFlashValue182;
       P_TYPE[251]=DefaultFlashType182;
    }
    #endif
    #if(Par_Num>=183)
    {
       P_INI[252]=(uint32_t *)&DefaultFlashValue183;
       P_TYPE[252]=DefaultFlashType183;
    }
    #endif
    #if(Par_Num>=184)
    {
       P_INI[253]=(uint32_t *)&DefaultFlashValue184;
       P_TYPE[253]=DefaultFlashType184;
    }
    #endif
    #if(Par_Num>=185)
    {
       P_INI[254]=(uint32_t *)&DefaultFlashValue185;
       P_TYPE[254]=DefaultFlashType185;
    }
    #endif
    #if(Par_Num>=186)
    {
       P_INI[255]=(uint32_t *)&DefaultFlashValue186;
       P_TYPE[255]=DefaultFlashType186;
    }
    #endif
#endif
}



void SetFlashDataToCon(void)
{
    uint8_t *FlashData_Con=Sent_Data->Par_Con; 

    #if(Par_Num>=1)
    {
        *(float *)FlashData_Con=DefaultFlashValue1;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=2)
    {
        *(float *)FlashData_Con=DefaultFlashValue2;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=3)
    {
        *(float *)FlashData_Con=DefaultFlashValue3;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=4)
    {
        *(float *)FlashData_Con=DefaultFlashValue4;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=5)
    {
        *(float *)FlashData_Con=DefaultFlashValue5;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=6)
    {
        *(float *)FlashData_Con=DefaultFlashValue6;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=7)
    {
        *(float *)FlashData_Con=DefaultFlashValue7;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=8)
    {
        *(float *)FlashData_Con=DefaultFlashValue8;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=9)
    {
        *(float *)FlashData_Con=DefaultFlashValue9;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=10)
    {
        *(float *)FlashData_Con=DefaultFlashValue10;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=11)
    {
        *(float *)FlashData_Con=DefaultFlashValue11;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=12)
    {
        *(float *)FlashData_Con=DefaultFlashValue12;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=13)
    {
        *(float *)FlashData_Con=DefaultFlashValue13;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=14)
    {
        *(float *)FlashData_Con=DefaultFlashValue14;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=15)
    {
        *(float *)FlashData_Con=DefaultFlashValue15;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=16)
    {
        *(float *)FlashData_Con=DefaultFlashValue16;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=17)
    {
        *(float *)FlashData_Con=DefaultFlashValue17;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=18)
    {
        *(float *)FlashData_Con=DefaultFlashValue18;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=19)
    {
        *(float *)FlashData_Con=DefaultFlashValue19;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=20)
    {
        *(float *)FlashData_Con=DefaultFlashValue20;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=21)
    {
        *(float *)FlashData_Con=DefaultFlashValue21;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=22)
    {
        *(float *)FlashData_Con=DefaultFlashValue22;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=23)
    {
        *(float *)FlashData_Con=DefaultFlashValue23;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=24)
    {
        *(float *)FlashData_Con=DefaultFlashValue24;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=25)
    {
        *(float *)FlashData_Con=DefaultFlashValue25;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=26)
    {
        *(float *)FlashData_Con=DefaultFlashValue26;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=27)
    {
        *(float *)FlashData_Con=DefaultFlashValue27;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=28)
    {
        *(float *)FlashData_Con=DefaultFlashValue28;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=29)
    {
        *(float *)FlashData_Con=DefaultFlashValue29;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=30)
    {
        *(float *)FlashData_Con=DefaultFlashValue30;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=31)
    {
        *(float *)FlashData_Con=DefaultFlashValue31;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=32)
    {
        *(float *)FlashData_Con=DefaultFlashValue32;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=33)
    {
        *(float *)FlashData_Con=DefaultFlashValue33;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=34)
    {
        *(float *)FlashData_Con=DefaultFlashValue34;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=35)
    {
        *(float *)FlashData_Con=DefaultFlashValue35;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=36)
    {
        *(float *)FlashData_Con=DefaultFlashValue36;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=37)
    {
        *(float *)FlashData_Con=DefaultFlashValue37;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=38)
    {
        *(float *)FlashData_Con=DefaultFlashValue38;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=39)
    {
        *(float *)FlashData_Con=DefaultFlashValue39;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=40)
    {
        *(float *)FlashData_Con=DefaultFlashValue40;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=41)
    {
        *(float *)FlashData_Con=DefaultFlashValue41;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=42)
    {
        *(float *)FlashData_Con=DefaultFlashValue42;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=43)
    {
        *(float *)FlashData_Con=DefaultFlashValue43;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=44)
    {
        *(float *)FlashData_Con=DefaultFlashValue44;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=45)
    {
        *(float *)FlashData_Con=DefaultFlashValue45;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=46)
    {
        *(float *)FlashData_Con=DefaultFlashValue46;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=47)
    {
        *(float *)FlashData_Con=DefaultFlashValue47;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=48)
    {
        *(float *)FlashData_Con=DefaultFlashValue48;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=49)
    {
        *(float *)FlashData_Con=DefaultFlashValue49;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=50)
    {
        *(float *)FlashData_Con=DefaultFlashValue50;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=51)
    {
        *(float *)FlashData_Con=DefaultFlashValue51;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=52)
    {
        *(float *)FlashData_Con=DefaultFlashValue52;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=53)
    {
        *(float *)FlashData_Con=DefaultFlashValue53;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=54)
    {
        *(float *)FlashData_Con=DefaultFlashValue54;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=55)
    {
        *(float *)FlashData_Con=DefaultFlashValue55;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=56)
    {
        *(float *)FlashData_Con=DefaultFlashValue56;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=57)
    {
        *(float *)FlashData_Con=DefaultFlashValue57;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=58)
    {
        *(float *)FlashData_Con=DefaultFlashValue58;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=59)
    {
        *(float *)FlashData_Con=DefaultFlashValue59;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=60)
    {
        *(float *)FlashData_Con=DefaultFlashValue60;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=61)
    {
        *(float *)FlashData_Con=DefaultFlashValue61;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=62)
    {
        *(float *)FlashData_Con=DefaultFlashValue62;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=63)
    {
        *(float *)FlashData_Con=DefaultFlashValue63;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=64)
    {
        *(float *)FlashData_Con=DefaultFlashValue64;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=65)
    {
        *(float *)FlashData_Con=DefaultFlashValue65;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=66)
    {
        *(float *)FlashData_Con=DefaultFlashValue66;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=67)
    {
        *(float *)FlashData_Con=DefaultFlashValue67;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=68)
    {
        *(float *)FlashData_Con=DefaultFlashValue68;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=69)
    {
        *(float *)FlashData_Con=DefaultFlashValue69;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=70)
    {
        *(float *)FlashData_Con=DefaultFlashValue70;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=71)
    {
        *(float *)FlashData_Con=DefaultFlashValue71;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=72)
    {
        *(float *)FlashData_Con=DefaultFlashValue72;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=73)
    {
        *(float *)FlashData_Con=DefaultFlashValue73;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=74)
    {
        *(float *)FlashData_Con=DefaultFlashValue74;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=75)
    {
        *(float *)FlashData_Con=DefaultFlashValue75;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=76)
    {
        *(float *)FlashData_Con=DefaultFlashValue76;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=77)
    {
        *(float *)FlashData_Con=DefaultFlashValue77;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=78)
    {
        *(float *)FlashData_Con=DefaultFlashValue78;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=79)
    {
        *(float *)FlashData_Con=DefaultFlashValue79;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=80)
    {
        *(float *)FlashData_Con=DefaultFlashValue80;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=81)
    {
        *(float *)FlashData_Con=DefaultFlashValue81;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=82)
    {
        *(float *)FlashData_Con=DefaultFlashValue82;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=83)
    {
        *(float *)FlashData_Con=DefaultFlashValue83;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=84)
    {
        *(float *)FlashData_Con=DefaultFlashValue84;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=85)
    {
        *(float *)FlashData_Con=DefaultFlashValue85;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=86)
    {
        *(float *)FlashData_Con=DefaultFlashValue86;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=87)
    {
        *(float *)FlashData_Con=DefaultFlashValue87;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=88)
    {
        *(float *)FlashData_Con=DefaultFlashValue88;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=89)
    {
        *(float *)FlashData_Con=DefaultFlashValue89;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=90)
    {
        *(float *)FlashData_Con=DefaultFlashValue90;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=91)
    {
        *(float *)FlashData_Con=DefaultFlashValue91;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=92)
    {
        *(float *)FlashData_Con=DefaultFlashValue92;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=93)
    {
        *(float *)FlashData_Con=DefaultFlashValue93;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=94)
    {
        *(float *)FlashData_Con=DefaultFlashValue94;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=95)
    {
        *(float *)FlashData_Con=DefaultFlashValue95;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=96)
    {
        *(float *)FlashData_Con=DefaultFlashValue96;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=97)
    {
        *(float *)FlashData_Con=DefaultFlashValue97;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=98)
    {
        *(float *)FlashData_Con=DefaultFlashValue98;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=99)
    {
        *(float *)FlashData_Con=DefaultFlashValue99;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=100)
    {
        *(float *)FlashData_Con=DefaultFlashValue100;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=101)
    {
        *(float *)FlashData_Con=DefaultFlashValue101;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=102)
    {
        *(float *)FlashData_Con=DefaultFlashValue102;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=103)
    {
        *(float *)FlashData_Con=DefaultFlashValue103;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=104)
    {
        *(float *)FlashData_Con=DefaultFlashValue104;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=105)
    {
        *(float *)FlashData_Con=DefaultFlashValue105;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=106)
    {
        *(float *)FlashData_Con=DefaultFlashValue106;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=107)
    {
        *(float *)FlashData_Con=DefaultFlashValue107;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=108)
    {
        *(float *)FlashData_Con=DefaultFlashValue108;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=109)
    {
        *(float *)FlashData_Con=DefaultFlashValue109;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=110)
    {
        *(float *)FlashData_Con=DefaultFlashValue110;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=111)
    {
        *(float *)FlashData_Con=DefaultFlashValue111;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=112)
    {
        *(float *)FlashData_Con=DefaultFlashValue112;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=113)
    {
        *(float *)FlashData_Con=DefaultFlashValue113;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=114)
    {
        *(float *)FlashData_Con=DefaultFlashValue114;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=115)
    {
        *(float *)FlashData_Con=DefaultFlashValue115;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=116)
    {
        *(float *)FlashData_Con=DefaultFlashValue116;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=117)
    {
        *(float *)FlashData_Con=DefaultFlashValue117;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=118)
    {
        *(float *)FlashData_Con=DefaultFlashValue118;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=119)
    {
        *(float *)FlashData_Con=DefaultFlashValue119;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=120)
    {
        *(float *)FlashData_Con=DefaultFlashValue120;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=121)
    {
        *(float *)FlashData_Con=DefaultFlashValue121;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=122)
    {
        *(float *)FlashData_Con=DefaultFlashValue122;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=123)
    {
        *(float *)FlashData_Con=DefaultFlashValue123;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=124)
    {
        *(float *)FlashData_Con=DefaultFlashValue124;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=125)
    {
        *(float *)FlashData_Con=DefaultFlashValue125;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=126)
    {
        *(float *)FlashData_Con=DefaultFlashValue126;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=127)
    {
        *(float *)FlashData_Con=DefaultFlashValue127;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=128)
    {
        *(float *)FlashData_Con=DefaultFlashValue128;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=129)
    {
        *(float *)FlashData_Con=DefaultFlashValue129;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=130)
    {
        *(float *)FlashData_Con=DefaultFlashValue130;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=131)
    {
        *(float *)FlashData_Con=DefaultFlashValue131;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=132)
    {
        *(float *)FlashData_Con=DefaultFlashValue132;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=133)
    {
        *(float *)FlashData_Con=DefaultFlashValue133;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=134)
    {
        *(float *)FlashData_Con=DefaultFlashValue134;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=135)
    {
        *(float *)FlashData_Con=DefaultFlashValue135;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=136)
    {
        *(float *)FlashData_Con=DefaultFlashValue136;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=137)
    {
        *(float *)FlashData_Con=DefaultFlashValue137;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=138)
    {
        *(float *)FlashData_Con=DefaultFlashValue138;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=139)
    {
        *(float *)FlashData_Con=DefaultFlashValue139;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=140)
    {
        *(float *)FlashData_Con=DefaultFlashValue140;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=141)
    {
        *(float *)FlashData_Con=DefaultFlashValue141;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=142)
    {
        *(float *)FlashData_Con=DefaultFlashValue142;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=143)
    {
        *(float *)FlashData_Con=DefaultFlashValue143;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=144)
    {
        *(float *)FlashData_Con=DefaultFlashValue144;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=145)
    {
        *(float *)FlashData_Con=DefaultFlashValue145;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=146)
    {
        *(float *)FlashData_Con=DefaultFlashValue146;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=147)
    {
        *(float *)FlashData_Con=DefaultFlashValue147;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=148)
    {
        *(float *)FlashData_Con=DefaultFlashValue148;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=149)
    {
        *(float *)FlashData_Con=DefaultFlashValue149;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=150)
    {
        *(float *)FlashData_Con=DefaultFlashValue150;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=151)
    {
        *(float *)FlashData_Con=DefaultFlashValue151;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=152)
    {
        *(float *)FlashData_Con=DefaultFlashValue152;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=153)
    {
        *(float *)FlashData_Con=DefaultFlashValue153;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=154)
    {
        *(float *)FlashData_Con=DefaultFlashValue154;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=155)
    {
        *(float *)FlashData_Con=DefaultFlashValue155;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=156)
    {
        *(float *)FlashData_Con=DefaultFlashValue156;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=157)
    {
        *(float *)FlashData_Con=DefaultFlashValue157;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=158)
    {
        *(float *)FlashData_Con=DefaultFlashValue158;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=159)
    {
        *(float *)FlashData_Con=DefaultFlashValue159;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=160)
    {
        *(float *)FlashData_Con=DefaultFlashValue160;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=161)
    {
        *(float *)FlashData_Con=DefaultFlashValue161;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=162)
    {
        *(float *)FlashData_Con=DefaultFlashValue162;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=163)
    {
        *(float *)FlashData_Con=DefaultFlashValue163;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=164)
    {
        *(float *)FlashData_Con=DefaultFlashValue164;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=165)
    {
        *(float *)FlashData_Con=DefaultFlashValue165;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=166)
    {
        *(float *)FlashData_Con=DefaultFlashValue166;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=167)
    {
        *(float *)FlashData_Con=DefaultFlashValue167;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=168)
    {
        *(float *)FlashData_Con=DefaultFlashValue168;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=169)
    {
        *(float *)FlashData_Con=DefaultFlashValue169;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=170)
    {
        *(float *)FlashData_Con=DefaultFlashValue170;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=171)
    {
        *(float *)FlashData_Con=DefaultFlashValue171;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=172)
    {
        *(float *)FlashData_Con=DefaultFlashValue172;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=173)
    {
        *(float *)FlashData_Con=DefaultFlashValue173;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=174)
    {
        *(float *)FlashData_Con=DefaultFlashValue174;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=175)
    {
        *(float *)FlashData_Con=DefaultFlashValue175;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=176)
    {
        *(float *)FlashData_Con=DefaultFlashValue176;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=177)
    {
        *(float *)FlashData_Con=DefaultFlashValue177;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=178)
    {
        *(float *)FlashData_Con=DefaultFlashValue178;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=179)
    {
        *(float *)FlashData_Con=DefaultFlashValue179;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=180)
    {
        *(float *)FlashData_Con=DefaultFlashValue180;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=181)
    {
        *(float *)FlashData_Con=DefaultFlashValue181;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=182)
    {
        *(float *)FlashData_Con=DefaultFlashValue182;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=183)
    {
        *(float *)FlashData_Con=DefaultFlashValue183;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=184)
    {
        *(float *)FlashData_Con=DefaultFlashValue184;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=185)
    {
        *(float *)FlashData_Con=DefaultFlashValue185;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
    #if(Par_Num>=186)
    {
        *(float *)FlashData_Con=DefaultFlashValue186;
        *(uint32_t *)(FlashData_Con + 4) = ~*(uint32_t *)FlashData_Con;
        FlashData_Con+=8;
    }
    #endif
}




