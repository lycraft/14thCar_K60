#ifndef __DATA_SENT_H__
#define __DATA_SENT_H__

#ifdef __cplusplus
 extern "C" {
#endif
    
#include "uart.h" 
#include "OLED.h"        
#include "dma.h"
#include "sys.h"
#include "gpio.h"
#include "mk60dz10.h"
#include "Camera.h"  
#include "ini_flash.h"  

#define Par_Num 1	 
	 
#define DMA_UART_TX_DB       ((uint8_t*)&(UART4->D))
#define DMA_UART_TX_SB       Sent_Data //设置DMA原地址
     
#define  DMA_UART_CHx                DMA_CH4 //选取DMA通道     
#define  UARTx_TRAN_DMAREQ           UART4_TRAN_DMAREQ //选取DMA中断源     

#define UINT          0x00
#define IINT          0x01 
#define FLOAT         0x02 

#define Pardefault    0
#define Typedefault   UINT   
#define Namedefault   "Val"  
     
#define Bit8          0x08
#define Bit16         0x10
         

#define ParMODE       0x01 //参数模式
#define PicBazMODE    0x03 //二值图像模式  
     
#define Send_Mode         PicBazMODE      //设置发送模式
#define DMAUART_BANDRATE  640000
#define Data_UARTx_Map    UART4_RX_C14_TX_C15//UART5_RX_D8_TX_D9//UART5_RX_E8_TX_E9
#define Data_UARTx        UART4

#define Image_FitDataLen    (Image_Height*7)//490 //拟图数据长度

/*****************************前4个暂时还是别去动他了，是建模需要的一些数据*******************************/
#define DataNum           35//上传数据的个数

//能在上位机显示波形的参数；
extern uint8_t threshold;
extern double left_wdata;
extern double left_ldata;
extern double right_wdata;
extern double right_ldata;
extern uint8_t Stop;

extern double ADC_ceju;
extern uint8 dahuan;
extern uint8 bushi;
extern uint8 panhuan;
extern uint8 zhangai;
extern uint8 zhangai_hang;
extern float  turn_angle;
extern int32_t dv;
extern double adc_error;
extern uint8 chuhuan;
extern uint8 chuhuankou;
extern uint8 cishu;
extern int16_t juli ;
extern int16_t juli1 ;
extern  uint8_t  ryh;
extern         uint8_t   ryl ;
 extern         uint8_t  lyl ;
 extern         uint8_t lyh;
extern uint8 zuo;
extern uint8 you;
   extern  uint8_t duanlu;
 extern uint8_t gray;
  extern uint8_t  stright_judge; 
   extern uint8 zhidao;
   extern float Ang_acc;
   extern float  Ang_gyro;
  extern int16_t CarSpeed; 
 extern uint8_t righthang ;
 extern uint8_t  rightless;
  extern uint8_t lefthang ;
 extern uint8_t  leftless;
  extern uint8_t start;
  extern S_FLOAT_XYZ Target_Angle;
  extern int16_t speed_sum;
  extern int16_t juli3; 
#if(DataNum)   
#if(DataNum>=1)
#define    DefaultParValue1            panhuan
#define    DefaultParName1             "threshold"
#endif
#if(DataNum>=2)
#define    DefaultParValue2            Huan_Road_flag
#define    DefaultParName2            "Huan_Road_flag"
#endif
#if(DataNum>=3)
#define    DefaultParValue3           adc_error
#define    DefaultParName3           "adc_error" //((Namedefault<<2)|0x03)
#endif
#if(DataNum>=4)
#define    DefaultParValue4            dahuan
#define    DefaultParName4             "dahuan"//((Namedefault<<2)|0x04)
#endif
#if(DataNum>=5)
#define    DefaultParValue5            bushi
#define    DefaultParName5             "bushi"//((Namedefault<<2)|0x05)
#endif
#if(DataNum>=6)
#define    DefaultParValue6            turn_angle
#define    DefaultParName6            "turn_angle"//((Namedefault<<2)|0x06)
#endif
#if(DataNum>=7)
#define    DefaultParValue7            dv
#define    DefaultParName7             "dv"//((Namedefault<<2)|0x07)
#endif


#if(DataNum>=8)
#define    DefaultParValue8            chuhuankou
#define    DefaultParName8             "chuhuankou"//((Namedefault<<2)|0x08)
#endif
#if(DataNum>=9)
#define    DefaultParValue9            left_wdata
#define    DefaultParName9             "left_wdata"//((Namedefault<<2)|0x09)
#endif
#if(DataNum>=10)
#define    DefaultParValue10            right_wdata
#define    DefaultParName10             "right_wdata"//((Namedefault<<2)|0x0A)
#endif
#if(DataNum>=11)
#define    DefaultParValue11            ryh
#define    DefaultParName11             "ryh"//((Namedefault<<2)|0x0B)
#endif
#if(DataNum>=12)
#define    DefaultParValue12            lyh
#define    DefaultParName12             "lyh"//((Namedefault<<2)|0x0C)
#endif
#if(DataNum>=13)
#define    DefaultParValue13            zuo
#define    DefaultParName13             "zuo"//((Namedefault<<2)|0x0D)
#endif
#if(DataNum>=14)
#define    DefaultParValue14            you
#define    DefaultParName14            "you"//((Namedefault<<2)|0x0E)
#endif
#if(DataNum>=15)
#define    DefaultParValue15            threshold
#define    DefaultParName15             "threshold"//((Namedefault<<2)|0x0F)
#endif
#if(DataNum>=16)
#define    DefaultParValue16            chuhuan
#define    DefaultParName16             "chuhuan"//((Namedefault<<2)|0x10)
#endif
#if(DataNum>=17)
#define    DefaultParValue17            duanlu
#define    DefaultParName17             "duanlu"//((Namedefault<<2)|0x11)
#endif
#if(DataNum>=18)
#define    DefaultParValue18            zhangai
#define    DefaultParName18            "zhangai"// ((Namedefault<<2)|0x12)
#endif
#if(DataNum>=19)
#define    DefaultParValue19            gray
#define    DefaultParName19             "gray"//((Namedefault<<2)|0x13)
#endif
#if(DataNum>=20)
#define    DefaultParValue20            ADC_ceju
#define    DefaultParName20            "ADC_ceju"//((Namedefault<<2)|0x14)
#endif
#if(DataNum>=21)
#define    DefaultParValue21            stright_judge
#define    DefaultParName21            "stright_judge"//((Namedefault<<2)|0x15)
#endif
#if(DataNum>=22)
#define    DefaultParValue22            zhidao
#define    DefaultParName22            "zhidao"// ((Namedefault<<2)|0x16)
#endif
#if(DataNum>=23)
#define    DefaultParValue23            Ang_gyro
#define    DefaultParName23             "Ang_gyro"//((Namedefault<<2)|0x17)
#endif
#if(DataNum>=24)
#define    DefaultParValue24            CarSpeed
#define    DefaultParName24             "CarSpeed"//((Namedefault<<2)|0x18)
#endif
#if(DataNum>=25)
#define    DefaultParValue25            zhangai_hang
#define    DefaultParName25             "zhangai_hang"//((Namedefault<<2)|0x19)
#endif
#if(DataNum>=26)
#define    DefaultParValue26            cishu
#define    DefaultParName26             "cishu"//((Namedefault<<2)|0x1A)
#endif
#if(DataNum>=27)
#define    DefaultParValue27            righthang
#define    DefaultParName27              "righthang"//((Namedefault<<2)|0x1B)
#endif
#if(DataNum>=28)
#define    DefaultParValue28            rightless
#define    DefaultParName28              "rightless"//((Namedefault<<2)|0x1C)
#endif
#if(DataNum>=29)
#define    DefaultParValue29            lefthang
#define    DefaultParName29             "lefthang"// ((Namedefault<<2)|0x1D)
#endif
#if(DataNum>=30)
#define    DefaultParValue30            leftless
#define    DefaultParName30              "leftless"//((Namedefault<<2)|0x1E)
#endif
#if(DataNum>=31)
#define    DefaultParValue31            start
#define    DefaultParName31             "start"//((Namedefault<<2)|0x1F)
#endif
#if(DataNum>=32)
#define    DefaultParValue32            Stop
#define    DefaultParName32             "Stop"//((Namedefault<<2)|0x20)
#endif
#if(DataNum>=33)
#define    DefaultParValue33            Target_Angle.Y
#define    DefaultParName33             "Target_Angle.Y"//((Namedefault<<2)|0x21)
#endif
#if(DataNum>=34)
#define    DefaultParValue34            speed_sum
#define    DefaultParName34             "speed_sum"//((Namedefault<<2)|0x22)
#endif
#if(DataNum>=35)
#define    DefaultParValue35            juli3
#define    DefaultParName35             "juli3"//((Namedefault<<2)|0x23)
#endif
#if(DataNum>=36)
#define    DefaultParValue36            Pardefault
#define    DefaultParName36             ((Namedefault<<2)|0x24)
#endif
#if(DataNum>=37)
#define    DefaultParValue37            Pardefault
#define    DefaultParName37             ((Namedefault<<2)|0x25)
#endif
#if(DataNum>=38)
#define    DefaultParValue38            Pardefault
#define    DefaultParName38             ((Namedefault<<2)|0x26)
#endif
#if(DataNum>=39)
#define    DefaultParValue39            Pardefault
#define    DefaultParName39             ((Namedefault<<2)|0x27)
#endif
#if(DataNum>=40)
#define    DefaultParValue40            Pardefault
#define    DefaultParName40             ((Namedefault<<2)|0x28)
#endif
#if(DataNum>=41)
#define    DefaultParValue41            Pardefault
#define    DefaultParName41             ((Namedefault<<2)|0x29)
#endif
#if(DataNum>=42)
#define    DefaultParValue42            Pardefault
#define    DefaultParName42             ((Namedefault<<2)|0x2A)
#endif
#if(DataNum>=43)
#define    DefaultParValue43            Pardefault
#define    DefaultParName43             ((Namedefault<<2)|0x2B)
#endif
#if(DataNum>=44)
#define    DefaultParValue44            Pardefault
#define    DefaultParName44             ((Namedefault<<2)|0x2C)
#endif
#if(DataNum>=45)
#define    DefaultParValue45            Pardefault
#define    DefaultParName45             ((Namedefault<<2)|0x2D)
#endif
#if(DataNum>=46)
#define    DefaultParValue46            Pardefault
#define    DefaultParName46             ((Namedefault<<2)|0x2E)
#endif
#if(DataNum>=47)
#define    DefaultParValue47            Pardefault
#define    DefaultParName47             ((Namedefault<<2)|0x2F)
#endif
#if(DataNum>=48)
#define    DefaultParValue48            Pardefault
#define    DefaultParName48             ((Namedefault<<2)|0x30)
#endif
#if(DataNum>=49)
#define    DefaultParValue49            Pardefault
#define    DefaultParName49             ((Namedefault<<2)|0x31)
#endif
#if(DataNum>=50)
#define    DefaultParValue50            Pardefault
#define    DefaultParName50             ((Namedefault<<2)|0x32)
#endif
#if(DataNum>=51)
#define    DefaultParValue51            Pardefault
#define    DefaultParName51             ((Namedefault<<2)|0x33)
#endif
#if(DataNum>=52)
#define    DefaultParValue52            Pardefault
#define    DefaultParName52             ((Namedefault<<2)|0x34)
#endif
#if(DataNum>=53)
#define    DefaultParValue53            Pardefault
#define    DefaultParName53             ((Namedefault<<2)|0x35)
#endif
#if(DataNum>=54)
#define    DefaultParValue54            Pardefault
#define    DefaultParName54             ((Namedefault<<2)|0x36)
#endif
#if(DataNum>=55)
#define    DefaultParValue55            Pardefault
#define    DefaultParName55             ((Namedefault<<2)|0x37)
#endif
#if(DataNum>=56)
#define    DefaultParValue56            Pardefault
#define    DefaultParName56             ((Namedefault<<2)|0x38)
#endif
#if(DataNum>=57)
#define    DefaultParValue57            Pardefault
#define    DefaultParName57             ((Namedefault<<2)|0x39)
#endif
#if(DataNum>=58)
#define    DefaultParValue58            Pardefault
#define    DefaultParName58             ((Namedefault<<2)|0x3A)
#endif
#if(DataNum>=59)
#define    DefaultParValue59            Pardefault
#define    DefaultParName59             ((Namedefault<<2)|0x3B)
#endif
#if(DataNum>=60)
#define    DefaultParValue60            Pardefault
#define    DefaultParName60             ((Namedefault<<2)|0x3C)
#endif
#if(DataNum>=61)
#define    DefaultParValue61            Pardefault
#define    DefaultParName61             ((Namedefault<<2)|0x3D)
#endif
#if(DataNum>=62)
#define    DefaultParValue62            Pardefault
#define    DefaultParName62             ((Namedefault<<2)|0x3E)
#endif
#if(DataNum>=63)
#define    DefaultParValue63            Pardefault
#define    DefaultParName63             ((Namedefault<<2)|0x3F)
#endif
#if(DataNum>=64)
#define    DefaultParValue64            Pardefault
#define    DefaultParName64             ((Namedefault<<2)|0x40)
#endif
#if(DataNum>=65)
#define    DefaultParValue65            Pardefault
#define    DefaultParName65             ((Namedefault<<2)|0x41)
#endif
#if(DataNum>=66)
#define    DefaultParValue66            Pardefault
#define    DefaultParName66             ((Namedefault<<2)|0x42)
#endif
#if(DataNum>=67)
#define    DefaultParValue67            Pardefault
#define    DefaultParName67             ((Namedefault<<2)|0x43)
#endif
#if(DataNum>=68)
#define    DefaultParValue68            Pardefault
#define    DefaultParName68             ((Namedefault<<2)|0x44)
#endif
#if(DataNum>=69)
#define    DefaultParValue69            Pardefault
#define    DefaultParName69             ((Namedefault<<2)|0x45)
#endif
#if(DataNum>=70)
#define    DefaultParValue70            Pardefault
#define    DefaultParName70             ((Namedefault<<2)|0x46)
#endif
#if(DataNum>=71)
#define    DefaultParValue71            Pardefault
#define    DefaultParName71             ((Namedefault<<2)|0x47)
#endif
#if(DataNum>=72)
#define    DefaultParValue72            Pardefault
#define    DefaultParName72             ((Namedefault<<2)|0x48)
#endif
#if(DataNum>=73)
#define    DefaultParValue73            Pardefault
#define    DefaultParName73             ((Namedefault<<2)|0x49)
#endif
#if(DataNum>=74)
#define    DefaultParValue74            Pardefault
#define    DefaultParName74             ((Namedefault<<2)|0x4A)
#endif
#if(DataNum>=75)
#define    DefaultParValue75            Pardefault
#define    DefaultParName75             ((Namedefault<<2)|0x4B)
#endif
#if(DataNum>=76)
#define    DefaultParValue76            Pardefault
#define    DefaultParName76             ((Namedefault<<2)|0x4C)
#endif
#if(DataNum>=77)
#define    DefaultParValue77            Pardefault
#define    DefaultParName77             ((Namedefault<<2)|0x4D)
#endif
#if(DataNum>=78)
#define    DefaultParValue78            Pardefault
#define    DefaultParName78             ((Namedefault<<2)|0x4E)
#endif
#if(DataNum>=79)
#define    DefaultParValue79            Pardefault
#define    DefaultParName79             ((Namedefault<<2)|0x4F)
#endif
#if(DataNum>=80)
#define    DefaultParValue80            Pardefault
#define    DefaultParName80             ((Namedefault<<2)|0x50)
#endif
#if(DataNum>=81)
#define    DefaultParValue81            Pardefault
#define    DefaultParName81             ((Namedefault<<2)|0x51)
#endif
#if(DataNum>=82)
#define    DefaultParValue82            Pardefault
#define    DefaultParName82             ((Namedefault<<2)|0x52)
#endif
#if(DataNum>=83)
#define    DefaultParValue83            Pardefault
#define    DefaultParName83             ((Namedefault<<2)|0x53)
#endif
#if(DataNum>=84)
#define    DefaultParValue84            Pardefault
#define    DefaultParName84             ((Namedefault<<2)|0x54)
#endif
#if(DataNum>=85)
#define    DefaultParValue85            Pardefault
#define    DefaultParName85             ((Namedefault<<2)|0x55)
#endif
#if(DataNum>=86)
#define    DefaultParValue86            Pardefault
#define    DefaultParName86             ((Namedefault<<2)|0x56)
#endif
#if(DataNum>=87)
#define    DefaultParValue87            Pardefault
#define    DefaultParName87             ((Namedefault<<2)|0x57)
#endif
#if(DataNum>=88)
#define    DefaultParValue88            Pardefault
#define    DefaultParName88             ((Namedefault<<2)|0x58)
#endif
#if(DataNum>=89)
#define    DefaultParValue89            Pardefault
#define    DefaultParName89             ((Namedefault<<2)|0x59)
#endif
#if(DataNum>=90)
#define    DefaultParValue90            Pardefault
#define    DefaultParName90             ((Namedefault<<2)|0x5A)
#endif
#if(DataNum>=91)
#define    DefaultParValue91            Pardefault
#define    DefaultParName91             ((Namedefault<<2)|0x5B)
#endif
#if(DataNum>=92)
#define    DefaultParValue92            Pardefault
#define    DefaultParName92             ((Namedefault<<2)|0x5C)
#endif
#if(DataNum>=93)
#define    DefaultParValue93            Pardefault
#define    DefaultParName93             ((Namedefault<<2)|0x5D)
#endif
#if(DataNum>=94)
#define    DefaultParValue94            Pardefault
#define    DefaultParName94             ((Namedefault<<2)|0x5E)
#endif
#if(DataNum>=95)
#define    DefaultParValue95            Pardefault
#define    DefaultParName95             ((Namedefault<<2)|0x5F)
#endif
#if(DataNum>=96)
#define    DefaultParValue96            Pardefault
#define    DefaultParName96             ((Namedefault<<2)|0x60)
#endif
#if(DataNum>=97)
#define    DefaultParValue97            Pardefault
#define    DefaultParName97             ((Namedefault<<2)|0x61)
#endif
#if(DataNum>=98)
#define    DefaultParValue98            Pardefault
#define    DefaultParName98             ((Namedefault<<2)|0x62)
#endif
#if(DataNum>=99)
#define    DefaultParValue99            Pardefault
#define    DefaultParName99             ((Namedefault<<2)|0x63)
#endif
#if(DataNum>=100)
#define    DefaultParValue100            Pardefault
#define    DefaultParName100             ((Namedefault<<2)|0x64)
#endif
#if(DataNum>=101)
#define    DefaultParValue101            Pardefault
#define    DefaultParName101             ((Namedefault<<2)|0x65)
#endif
#if(DataNum>=102)
#define    DefaultParValue102            Pardefault
#define    DefaultParName102             ((Namedefault<<2)|0x66)
#endif
#if(DataNum>=103)
#define    DefaultParValue103            Pardefault
#define    DefaultParName103             ((Namedefault<<2)|0x67)
#endif
#if(DataNum>=104)
#define    DefaultParValue104            Pardefault
#define    DefaultParName104             ((Namedefault<<2)|0x68)
#endif
#if(DataNum>=105)
#define    DefaultParValue105            Pardefault
#define    DefaultParName105             ((Namedefault<<2)|0x69)
#endif
#if(DataNum>=106)
#define    DefaultParValue106            Pardefault
#define    DefaultParName106             ((Namedefault<<2)|0x6A)
#endif
#if(DataNum>=107)
#define    DefaultParValue107            Pardefault
#define    DefaultParName107             ((Namedefault<<2)|0x6B)
#endif
#if(DataNum>=108)
#define    DefaultParValue108            Pardefault
#define    DefaultParName108             ((Namedefault<<2)|0x6C)
#endif
#if(DataNum>=109)
#define    DefaultParValue109            Pardefault
#define    DefaultParName109             ((Namedefault<<2)|0x6D)
#endif
#if(DataNum>=110)
#define    DefaultParValue110            Pardefault
#define    DefaultParName110             ((Namedefault<<2)|0x6E)
#endif
#if(DataNum>=111)
#define    DefaultParValue111            Pardefault
#define    DefaultParName111             ((Namedefault<<2)|0x6F)
#endif
#if(DataNum>=112)
#define    DefaultParValue112            Pardefault
#define    DefaultParName112             ((Namedefault<<2)|0x70)
#endif
#if(DataNum>=113)
#define    DefaultParValue113            Pardefault
#define    DefaultParName113             ((Namedefault<<2)|0x71)
#endif
#if(DataNum>=114)
#define    DefaultParValue114            Pardefault
#define    DefaultParName114             ((Namedefault<<2)|0x72)
#endif
#if(DataNum>=115)
#define    DefaultParValue115            Pardefault
#define    DefaultParName115             ((Namedefault<<2)|0x73)
#endif
#if(DataNum>=116)
#define    DefaultParValue116            Pardefault
#define    DefaultParName116             ((Namedefault<<2)|0x74)
#endif
#if(DataNum>=117)
#define    DefaultParValue117            Pardefault
#define    DefaultParName117             ((Namedefault<<2)|0x75)
#endif
#if(DataNum>=118)
#define    DefaultParValue118            Pardefault
#define    DefaultParName118             ((Namedefault<<2)|0x76)
#endif
#if(DataNum>=119)
#define    DefaultParValue119            Pardefault
#define    DefaultParName119             ((Namedefault<<2)|0x77)
#endif
#if(DataNum>=120)
#define    DefaultParValue120            Pardefault
#define    DefaultParName120             ((Namedefault<<2)|0x78)
#endif
#if(DataNum>=121)
#define    DefaultParValue121            Pardefault
#define    DefaultParName121             ((Namedefault<<2)|0x79)
#endif
#if(DataNum>=122)
#define    DefaultParValue122            Pardefault
#define    DefaultParName122             ((Namedefault<<2)|0x7A)
#endif
#if(DataNum>=123)
#define    DefaultParValue123            Pardefault
#define    DefaultParName123             ((Namedefault<<2)|0x7B)
#endif
#if(DataNum>=124)
#define    DefaultParValue124            Pardefault
#define    DefaultParName124             ((Namedefault<<2)|0x7C)
#endif
#if(DataNum>=125)
#define    DefaultParValue125            Pardefault
#define    DefaultParName125             ((Namedefault<<2)|0x7D)
#endif
#if(DataNum>=126)
#define    DefaultParValue126            Pardefault
#define    DefaultParName126             ((Namedefault<<2)|0x7E)
#endif
#if(DataNum>=127)
#define    DefaultParValue127            Pardefault
#define    DefaultParName127             ((Namedefault<<2)|0x7F)
#endif
#if(DataNum>=128)
#define    DefaultParValue128            Pardefault
#define    DefaultParName128             ((Namedefault<<2)|0x80)
#endif
#if(DataNum>=129)
#define    DefaultParValue129            Pardefault
#define    DefaultParName129             ((Namedefault<<2)|0x81)
#endif
#if(DataNum>=130)
#define    DefaultParValue130            Pardefault
#define    DefaultParName130             ((Namedefault<<2)|0x82)
#endif
#if(DataNum>=131)
#define    DefaultParValue131            Pardefault
#define    DefaultParName131             ((Namedefault<<2)|0x83)
#endif
#if(DataNum>=132)
#define    DefaultParValue132            Pardefault
#define    DefaultParName132             ((Namedefault<<2)|0x84)
#endif
#if(DataNum>=133)
#define    DefaultParValue133            Pardefault
#define    DefaultParName133             ((Namedefault<<2)|0x85)
#endif
#if(DataNum>=134)
#define    DefaultParValue134            Pardefault
#define    DefaultParName134             ((Namedefault<<2)|0x86)
#endif
#if(DataNum>=135)
#define    DefaultParValue135            Pardefault
#define    DefaultParName135             ((Namedefault<<2)|0x87)
#endif
#if(DataNum>=136)
#define    DefaultParValue136            Pardefault
#define    DefaultParName136             ((Namedefault<<2)|0x88)
#endif
#if(DataNum>=137)
#define    DefaultParValue137            Pardefault
#define    DefaultParName137             ((Namedefault<<2)|0x89)
#endif
#if(DataNum>=138)
#define    DefaultParValue138            Pardefault
#define    DefaultParName138             ((Namedefault<<2)|0x8A)
#endif
#if(DataNum>=139)
#define    DefaultParValue139            Pardefault
#define    DefaultParName139             ((Namedefault<<2)|0x8B)
#endif
#if(DataNum>=140)
#define    DefaultParValue140            Pardefault
#define    DefaultParName140             ((Namedefault<<2)|0x8C)
#endif
#if(DataNum>=141)
#define    DefaultParValue141            Pardefault
#define    DefaultParName141             ((Namedefault<<2)|0x8D)
#endif
#if(DataNum>=142)
#define    DefaultParValue142            Pardefault
#define    DefaultParName142             ((Namedefault<<2)|0x8E)
#endif
#if(DataNum>=143)
#define    DefaultParValue143            Pardefault
#define    DefaultParName143             ((Namedefault<<2)|0x8F)
#endif
#if(DataNum>=144)
#define    DefaultParValue144            Pardefault
#define    DefaultParName144             ((Namedefault<<2)|0x90)
#endif
#if(DataNum>=145)
#define    DefaultParValue145            Pardefault
#define    DefaultParName145             ((Namedefault<<2)|0x91)
#endif
#if(DataNum>=146)
#define    DefaultParValue146            Pardefault
#define    DefaultParName146             ((Namedefault<<2)|0x92)
#endif
#if(DataNum>=147)
#define    DefaultParValue147            Pardefault
#define    DefaultParName147             ((Namedefault<<2)|0x93)
#endif
#if(DataNum>=148)
#define    DefaultParValue148            Pardefault
#define    DefaultParName148             ((Namedefault<<2)|0x94)
#endif
#if(DataNum>=149)
#define    DefaultParValue149            Pardefault
#define    DefaultParName149             ((Namedefault<<2)|0x95)
#endif
#if(DataNum>=150)
#define    DefaultParValue150            Pardefault
#define    DefaultParName150             ((Namedefault<<2)|0x96)
#endif
#if(DataNum>=151)
#define    DefaultParValue151            Pardefault
#define    DefaultParName151             ((Namedefault<<2)|0x97)
#endif
#if(DataNum>=152)
#define    DefaultParValue152            Pardefault
#define    DefaultParName152             ((Namedefault<<2)|0x98)
#endif
#if(DataNum>=153)
#define    DefaultParValue153            Pardefault
#define    DefaultParName153             ((Namedefault<<2)|0x99)
#endif
#if(DataNum>=154)
#define    DefaultParValue154            Pardefault
#define    DefaultParName154             ((Namedefault<<2)|0x9A)
#endif
#if(DataNum>=155)
#define    DefaultParValue155            Pardefault
#define    DefaultParName155             ((Namedefault<<2)|0x9B)
#endif
#if(DataNum>=156)
#define    DefaultParValue156            Pardefault
#define    DefaultParName156             ((Namedefault<<2)|0x9C)
#endif
#if(DataNum>=157)
#define    DefaultParValue157            Pardefault
#define    DefaultParName157             ((Namedefault<<2)|0x9D)
#endif
#if(DataNum>=158)
#define    DefaultParValue158            Pardefault
#define    DefaultParName158             ((Namedefault<<2)|0x9E)
#endif
#if(DataNum>=159)
#define    DefaultParValue159            Pardefault
#define    DefaultParName159             ((Namedefault<<2)|0x9F)
#endif
#if(DataNum>=160)
#define    DefaultParValue160            Pardefault
#define    DefaultParName160             ((Namedefault<<2)|0xA0)
#endif
#if(DataNum>=161)
#define    DefaultParValue161            Pardefault
#define    DefaultParName161             ((Namedefault<<2)|0xA1)
#endif
#if(DataNum>=162)
#define    DefaultParValue162            Pardefault
#define    DefaultParName162             ((Namedefault<<2)|0xA2)
#endif
#if(DataNum>=163)
#define    DefaultParValue163            Pardefault
#define    DefaultParName163             ((Namedefault<<2)|0xA3)
#endif
#if(DataNum>=164)
#define    DefaultParValue164            Pardefault
#define    DefaultParName164             ((Namedefault<<2)|0xA4)
#endif
#if(DataNum>=165)
#define    DefaultParValue165            Pardefault
#define    DefaultParName165             ((Namedefault<<2)|0xA5)
#endif
#if(Par_Num>=166)
#define    DefaultParValue166            Pardefault
#define    DefaultParName166             ((Namedefault<<2)|0xA6)
#endif
#if(DataNum>=167)
#define    DefaultParValue167            Pardefault
#define    DefaultParName167             ((Namedefault<<2)|0xA7)
#endif
#if(DataNum>=168)
#define    DefaultParValue168            Pardefault
#define    DefaultParName168             ((Namedefault<<2)|0xA8)
#endif
#if(DataNum>=169)
#define    DefaultParValue169            Pardefault
#define    DefaultParName169             ((Namedefault<<2)|0xA9)
#endif
#if(DataNum>=170)
#define    DefaultParValue170            Pardefault
#define    DefaultParName170             ((Namedefault<<2)|0xAA)
#endif
#if(DataNum>=171)
#define    DefaultParValue171            Pardefault
#define    DefaultParName171             ((Namedefault<<2)|0xAB)
#endif
#if(DataNum>=172)
#define    DefaultParValue172            Pardefault
#define    DefaultParName172             ((Namedefault<<2)|0xAC)
#endif
#if(DataNum>=173)
#define    DefaultParValue173            Pardefault
#define    DefaultParName173             ((Namedefault<<2)|0xAD)
#endif
#if(DataNum>=174)
#define    DefaultParValue174            Pardefault
#define    DefaultParName174             ((Namedefault<<2)|0xAE)
#endif
#if(DataNum>=175)
#define    DefaultParValue175            Pardefault
#define    DefaultParName175             ((Namedefault<<2)|0xAF)
#endif
#if(DataNum>=176)
#define    DefaultParValue176            Pardefault
#define    DefaultParName176             ((Namedefault<<2)|0xB0)
#endif
#if(DataNum>=177)
#define    DefaultParValue177            Pardefault
#define    DefaultParName177             ((Namedefault<<2)|0xB1)
#endif
#if(DataNum>=178)
#define    DefaultParValue178            Pardefault
#define    DefaultParName178             ((Namedefault<<2)|0xB2)
#endif
#if(DataNum>=179)
#define    DefaultParValue179            Pardefault
#define    DefaultParName179             ((Namedefault<<2)|0xB3)
#endif
#if(DataNum>=180)
#define    DefaultParValue180            Pardefault
#define    DefaultParName180             ((Namedefault<<2)|0xB4)
#endif
#if(DataNum>=181)
#define    DefaultParValue181            Pardefault
#define    DefaultParName181             ((Namedefault<<2)|0xB5)
#endif
#if(DataNum>=182)
#define    DefaultParValue182            Pardefault
#define    DefaultParName182             ((Namedefault<<2)|0xB6)
#endif
#if(DataNum>=183)
#define    DefaultParValue183            Pardefault
#define    DefaultParName183             ((Namedefault<<2)|0xB7)
#endif
#if(DataNum>=184)
#define    DefaultParValue184            Pardefault
#define    DefaultParName184             ((Namedefault<<2)|0xB8)
#endif
#if(DataNum>=185)
#define    DefaultParValue185            Pardefault
#define    DefaultParName185             ((Namedefault<<2)|0xB9)
#endif
#if(DataNum>=186)
#define    DefaultParValue186            Pardefault
#define    DefaultParName186             ((Namedefault<<2)|0xBA)
#endif
#if(DataNum>=187)
#define    DefaultParValue187            Pardefault
#define    DefaultParName187             ((Namedefault<<2)|0xBB)
#endif
#if(DataNum>=188)
#define    DefaultParValue188            Pardefault
#define    DefaultParName188             ((Namedefault<<2)|0xBC)
#endif
#if(DataNum>=189)
#define    DefaultParValue189            Pardefault
#define    DefaultParName189             ((Namedefault<<2)|0xBD)
#endif
#if(DataNum>=190)
#define    DefaultParValue190            Pardefault
#define    DefaultParName190             ((Namedefault<<2)|0xBE)
#endif
#if(DataNum>=191)
#define    DefaultParValue191            Pardefault
#define    DefaultParName191             ((Namedefault<<2)|0xBF)
#endif
#if(DataNum>=192)
#define    DefaultParValue192            Pardefault
#define    DefaultParName192             ((Namedefault<<2)|0xC0)
#endif
#if(DataNum>=193)
#define    DefaultParValue193            Pardefault
#define    DefaultParName193             ((Namedefault<<2)|0xC1)
#endif
#if(DataNum>=194)
#define    DefaultParValue194            Pardefault
#define    DefaultParName194             ((Namedefault<<2)|0xC2)
#endif
#if(DataNum>=195)
#define    DefaultParValue195            Pardefault
#define    DefaultParName195             ((Namedefault<<2)|0xC3)
#endif
#if(DataNum>=196)
#define    DefaultParValue196            Pardefault
#define    DefaultParName196             ((Namedefault<<2)|0xC4)
#endif
#if(DataNum>=197)
#define    DefaultParValue197            Pardefault
#define    DefaultParName197             ((Namedefault<<2)|0xC5)
#endif
#if(DataNum>=198)
#define    DefaultParValue198            Pardefault
#define    DefaultParName198             ((Namedefault<<2)|0xC6)
#endif
#if(DataNum>=199)
#define    DefaultParValue199            Pardefault
#define    DefaultParName199             ((Namedefault<<2)|0xC7)
#endif
#if(DataNum>=200)
#define    DefaultParValue200            Pardefault
#define    DefaultParName200             ((Namedefault<<2)|0xC8)
#endif
#if(DataNum>=201)
#define    DefaultParValue201            Pardefault
#define    DefaultParName201             ((Namedefault<<2)|0xC9)
#endif
#if(DataNum>=202)
#define    DefaultParValue202            Pardefault
#define    DefaultParName202             ((Namedefault<<2)|0xCA)
#endif
#if(DataNum>=203)
#define    DefaultParValue203            Pardefault
#define    DefaultParName203             ((Namedefault<<2)|0xCB)
#endif
#if(DataNum>=204)
#define    DefaultParValue204            Pardefault
#define    DefaultParName204             ((Namedefault<<2)|0xCC)
#endif
#if(DataNum>=205)
#define    DefaultParValue205            Pardefault
#define    DefaultParName205             ((Namedefault<<2)|0xCD)
#endif
#if(DataNum>=206)
#define    DefaultParValue206            Pardefault
#define    DefaultParName206             ((Namedefault<<2)|0xCE)
#endif
#if(DataNum>=207)
#define    DefaultParValue207            Pardefault
#define    DefaultParName207             ((Namedefault<<2)|0xCF)
#endif
#if(DataNum>=208)
#define    DefaultParValue208            Pardefault
#define    DefaultParName208             ((Namedefault<<2)|0xD0)
#endif
#if(DataNum>=209)
#define    DefaultParValue209            Pardefault
#define    DefaultParName209             ((Namedefault<<2)|0xD1)
#endif
#if(DataNum>=210)
#define    DefaultParValue210            Pardefault
#define    DefaultParName210             ((Namedefault<<2)|0xD2)
#endif
#if(DataNum>=211)
#define    DefaultParValue211            Pardefault
#define    DefaultParName211             ((Namedefault<<2)|0xD3)
#endif
#if(DataNum>=212)
#define    DefaultParValue212            Pardefault
#define    DefaultParName212             ((Namedefault<<2)|0xD4)
#endif
#if(DataNum>=213)
#define    DefaultParValue213            Pardefault
#define    DefaultParName213             ((Namedefault<<2)|0xD5)
#endif
#if(DataNum>=214)
#define    DefaultParValue214            Pardefault
#define    DefaultParName214             ((Namedefault<<2)|0xD6)
#endif
#if(DataNum>=215)
#define    DefaultParValue215            Pardefault
#define    DefaultParName215             ((Namedefault<<2)|0xD7)
#endif
#if(DataNum>=216)
#define    DefaultParValue216            Pardefault
#define    DefaultParName216             ((Namedefault<<2)|0xD8)
#endif
#if(DataNum>=217)
#define    DefaultParValue217            Pardefault
#define    DefaultParName217             ((Namedefault<<2)|0xD9)
#endif
#if(DataNum>=218)
#define    DefaultParValue218            Pardefault
#define    DefaultParName218             ((Namedefault<<2)|0xDA)
#endif
#if(DataNum>=219)
#define    DefaultParValue219            Pardefault
#define    DefaultParName219             ((Namedefault<<2)|0xDB)
#endif
#if(DataNum>=220)
#define    DefaultParValue220            Pardefault
#define    DefaultParName220             ((Namedefault<<2)|0xDC)
#endif
#if(DataNum>=221)
#define    DefaultParValue221            Pardefault
#define    DefaultParName221             ((Namedefault<<2)|0xDD)
#endif
#if(DataNum>=222)
#define    DefaultParValue222            Pardefault
#define    DefaultParName222             ((Namedefault<<2)|0xDE)
#endif
#if(DataNum>=223)
#define    DefaultParValue223            Pardefault
#define    DefaultParName223             ((Namedefault<<2)|0xDF)
#endif
#if(DataNum>=224)
#define    DefaultParValue224            Pardefault
#define    DefaultParName224             ((Namedefault<<2)|0xE0)
#endif
#if(DataNum>=225)
#define    DefaultParValue225            Pardefault
#define    DefaultParName225             ((Namedefault<<2)|0xE1)
#endif
#if(DataNum>=226)
#define    DefaultParValue226            Pardefault
#define    DefaultParName226             ((Namedefault<<2)|0xE2)
#endif
#if(DataNum>=227)
#define    DefaultParValue227            Pardefault
#define    DefaultParName227             ((Namedefault<<2)|0xE3)
#endif
#if(DataNum>=228)
#define    DefaultParValue228            Pardefault
#define    DefaultParName228             ((Namedefault<<2)|0xE4)
#endif
#if(DataNum>=229)
#define    DefaultParValue229            Pardefault
#define    DefaultParName229             ((Namedefault<<2)|0xE5)
#endif
#if(DataNum>=230)
#define    DefaultParValue230            Pardefault
#define    DefaultParName230             ((Namedefault<<2)|0xE6)
#endif
#if(DataNum>=231)
#define    DefaultParValue231            Pardefault
#define    DefaultParName231             ((Namedefault<<2)|0xE7)
#endif
#if(DataNum>=232)
#define    DefaultParValue232            Pardefault
#define    DefaultParName232             ((Namedefault<<2)|0xE8)
#endif
#if(DataNum>=233)
#define    DefaultParValue233            Pardefault
#define    DefaultParName233             ((Namedefault<<2)|0xE9)
#endif
#if(DataNum>=234)
#define    DefaultParValue234            Pardefault
#define    DefaultParName234             ((Namedefault<<2)|0xEA)
#endif
#if(DataNum>=235)
#define    DefaultParValue235            Pardefault
#define    DefaultParName235             ((Namedefault<<2)|0xEB)
#endif
#if(DataNum>=236)
#define    DefaultParValue236            Pardefault
#define    DefaultParName236             ((Namedefault<<2)|0xEC)
#endif
#if(DataNum>=237)
#define    DefaultParValue237            Pardefault
#define    DefaultParName237             ((Namedefault<<2)|0xED)
#endif
#if(DataNum>=238)
#define    DefaultParValue238            Pardefault
#define    DefaultParName238             ((Namedefault<<2)|0xEE)
#endif
#if(DataNum>=239)
#define    DefaultParValue239            Pardefault
#define    DefaultParName239             ((Namedefault<<2)|0xEF)
#endif
#if(DataNum>=240)
#define    DefaultParValue240            Pardefault
#define    DefaultParName240             ((Namedefault<<2)|0xF0)
#endif
#if(DataNum>=241)
#define    DefaultParValue241            Pardefault
#define    DefaultParName241             ((Namedefault<<2)|0xF1)
#endif
#if(DataNum>=242)
#define    DefaultParValue242            Pardefault
#define    DefaultParName242             ((Namedefault<<2)|0xF2)
#endif
#if(DataNum>=243)
#define    DefaultParValue243            Pardefault
#define    DefaultParName243             ((Namedefault<<2)|0xF3)
#endif
#if(DataNum>=244)
#define    DefaultParValue244            Pardefault
#define    DefaultParName244             ((Namedefault<<2)|0xF4)
#endif
#if(DataNum>=245)
#define    DefaultParValue245            Pardefault
#define    DefaultParName245             ((Namedefault<<2)|0xF5)
#endif
#if(DataNum>=246)
#define    DefaultParValue246            Pardefault
#define    DefaultParName246             ((Namedefault<<2)|0xF6)
#endif
#if(DataNum>=247)
#define    DefaultParValue247            Pardefault
#define    DefaultParName247             ((Namedefault<<2)|0xF7)
#endif
#if(DataNum>=248)
#define    DefaultParValue248            Pardefault
#define    DefaultParName248             ((Namedefault<<2)|0xF8)
#endif
#if(DataNum>=249)
#define    DefaultParValue249            Pardefault
#define    DefaultParName249             ((Namedefault<<2)|0xF9)
#endif
#if(DataNum>=250)
#define    DefaultParValue250            Pardefault
#define    DefaultParName250             ((Namedefault<<2)|0xFA)
#endif
#if(DataNum>=251)
#define    DefaultParValue251            Pardefault
#define    DefaultParName251             ((Namedefault<<2)|0xFB)
#endif
#if(DataNum>=252)
#define    DefaultParValue252            Pardefault
#define    DefaultParName252             ((Namedefault<<2)|0xFC)
#endif
#if(DataNum>=253)
#define    DefaultParValue253            Pardefault
#define    DefaultParName253             ((Namedefault<<2)|0xFD)
#endif
#if(DataNum>=254)
#define    DefaultParValue254            Pardefault
#define    DefaultParName254             ((Namedefault<<2)|0xFE)
#endif
#if(DataNum>=255)
#define    DefaultParValue255            Pardefault
#define    DefaultParName255             ((Namedefault<<2)|0xFF)
#endif
#if(DataNum>=256)
#define    DefaultParValue256            Pardefault
#define    DefaultParName256             ((Namedefault<<2)|0x100)
#endif


#endif


//自动计算出数据长度
#define  Buff_Sub                        4  //补偿 防止DMA或者单片机不稳定所导致的数组溢出问题
#define  Ver_Sub                         7  //验证及各种信息
#define  ParValue_Length     ((DataNum<<3)+ (Par_Num<<3))//参数长度
  

#if(Send_Mode==PicBazMODE)
#define  Pixels_Length       ((Image_Width*Image_Height)>>3)//存储图像大小，为了减少计算,编译器优化
#define  Data_Length         (Pixels_Length+Image_FitDataLen) //数据长度计算,编译器优化 Image_FitDataLen拟图数据长度
#define  Data_All_Length     (Data_Length+ParValue_Length+Ver_Sub +Buff_Sub) //数据和参数信息总长度,编译器优化 
#endif
#if(Send_Mode==ParMODE)
#define  Pixels_Length       (Image_Width*Image_Height)//存储图像大小，为了减少计算,编译器优化
#define  Data_Length         (Pixels_Length+Image_FitDataLen) //数据长度计算,编译器优化 Image_FitDataLen拟图数据长度
#define  Data_All_Length     (ParValue_Length + Ver_Sub +Buff_Sub) //数据和参数信息总长度,编译器优化 
#endif




typedef struct 
{
    uint8_t LEnd;
    uint8_t REnd;
    uint8_t LStart;
    uint8_t RStart;
    uint8_t LBlack;
    uint8_t RBlack;
    uint8_t Center;
}LCR;


typedef struct 
{
    uint8_t Verific[5];
    uint8_t Pixels_width;
    uint8_t Pixels_height;
    uint8_t Coefficient_Num;
    uint8_t Parameter_Num;  
    uint8_t Data_Con[DataNum*8];
    uint8_t Par_Con[Par_Num*8];    
    LCR Lcr[Image_Height];
    uint8_t Pixels[Pixels_Length];  


}Data_Type;


struct Byte8_Struct
{
 uint8_t bit1:1;
 uint8_t bit2:1;
 uint8_t bit3:1;
 uint8_t bit4:1;
 uint8_t bit5:1;
 uint8_t bit6:1;
 uint8_t bit7:1;
 uint8_t bit8:1;
};





void Set_DataToCon(void);
void UART_Send_Con(void);
void Data_Uart_Init(void);     
void  DMA_Uart_ClearITPendingBit(void);//清除UART DMA中断标记
void Set_Uart_DMA_Enable(FunctionalState DMA_ON_OFF);//开启或关闭uartDMA   
void Set_Uart_DMA_DAddr(uint32_t DMA_Addr);//修改DMA目的地址
void Compressed_Data(void);//8位数据压缩成一位数据
void Data_UpLoad(void);
void Unpack_Data(void); //数据解压
void DataInit(void);    
void NrfData_UpLoad(void);
#ifdef __cplusplus
}
#endif

#endif


