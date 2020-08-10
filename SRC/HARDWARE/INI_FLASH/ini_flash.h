#ifndef __INI_FLASH_H__
#define __INI_FLASH_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "flash.h"
#include "data_sent.h"

extern uint16_t SD_ALL_WT_Count;
	 
#define  BLOCK_SIZE     (2*1024) //块大小 	 
//为了提高效率，采用双缓存	 
#define INI_BLOCK_NUM1    250  //把计数数据写入的缓存块序号1 1块为2048byte 
#define INI_BLOCK_NUM2    251  //把计数数据写入的缓存块序号2 1块为2048byte 
	 
#define INI_BLOCK_NUM3    252  //把参数数据写入的缓存块序号3 1块为2048byte 

#define OneParLength      8
/*****************************************************************************************
*数据类型别乱填
*UINT    支持   uint8_t   uint16_t       
*IINT    支持   int     int16_t
*FLOAT   支持   float
******************************************************************************************/
/******************************第一个禁止改动，是SD卡计数值，也是场计数值，特殊处理过的***************************************/
#define Par_Num 1

#if(Par_Num)   
#if(Par_Num>=1)
#define    DefaultFlashValue1            SD_ALL_WT_Count
#define    DefaultFlashType1             Typedefault
#endif

#if(Par_Num>=2)
#define    DefaultFlashValue2            Pardefault
#define    DefaultFlashType2             Typedefault
#endif

#if(Par_Num>=3)
#define    DefaultFlashValue3            Pardefault
#define    DefaultFlashType3             Typedefault
#endif

#if(Par_Num>=4)
#define    DefaultFlashValue4            Pardefault
#define    DefaultFlashType4             Typedefault
#endif

#if(Par_Num>=5)
#define    DefaultFlashValue5            Pardefault
#define    DefaultFlashType5             Typedefault
#endif

#if(Par_Num>=6)
#define    DefaultFlashValue6            Pardefault
#define    DefaultFlashType6             Typedefault
#endif

#if(Par_Num>=7)
#define    DefaultFlashValue7            Pardefault
#define    DefaultFlashType7             Typedefault
#endif

#if(Par_Num>=8)
#define    DefaultFlashValue8            Pardefault
#define    DefaultFlashType8             Typedefault
#endif

#if(Par_Num>=9)
#define    DefaultFlashValue9            Pardefault
#define    DefaultFlashType9             Typedefault
#endif

#if(Par_Num>=10)
#define    DefaultFlashValue10            Pardefault
#define    DefaultFlashType10             Typedefault
#endif

#if(Par_Num>=11)
#define    DefaultFlashValue11            Pardefault
#define    DefaultFlashType11             Typedefault
#endif

#if(Par_Num>=12)
#define    DefaultFlashValue12            Pardefault
#define    DefaultFlashType12             Typedefault
#endif

#if(Par_Num>=13)
#define    DefaultFlashValue13            Pardefault
#define    DefaultFlashType13             Typedefault
#endif

#if(Par_Num>=14)
#define    DefaultFlashValue14            Pardefault
#define    DefaultFlashType14             Typedefault
#endif

#if(Par_Num>=15)
#define    DefaultFlashValue15            Pardefault
#define    DefaultFlashType15             Typedefault
#endif

#if(Par_Num>=16)
#define    DefaultFlashValue16            Pardefault
#define    DefaultFlashType16             Typedefault
#endif

#if(Par_Num>=17)
#define    DefaultFlashValue17            Pardefault
#define    DefaultFlashType17             Typedefault
#endif

#if(Par_Num>=18)
#define    DefaultFlashValue18            Pardefault
#define    DefaultFlashType18             Typedefault
#endif

#if(Par_Num>=19)
#define    DefaultFlashValue19            Pardefault
#define    DefaultFlashType19             Typedefault
#endif

#if(Par_Num>=20)
#define    DefaultFlashValue20            Pardefault
#define    DefaultFlashType20             Typedefault
#endif

#if(Par_Num>=21)
#define    DefaultFlashValue21            Pardefault
#define    DefaultFlashType21             Typedefault
#endif

#if(Par_Num>=22)
#define    DefaultFlashValue22            Pardefault
#define    DefaultFlashType22             Typedefault
#endif

#if(Par_Num>=23)
#define    DefaultFlashValue23            Pardefault
#define    DefaultFlashType23             Typedefault
#endif

#if(Par_Num>=24)
#define    DefaultFlashValue24            Pardefault
#define    DefaultFlashType24             Typedefault
#endif

#if(Par_Num>=25)
#define    DefaultFlashValue25            Pardefault
#define    DefaultFlashType25             Typedefault
#endif

#if(Par_Num>=26)
#define    DefaultFlashValue26            Pardefault
#define    DefaultFlashType26             Typedefault
#endif

#if(Par_Num>=27)
#define    DefaultFlashValue27            Pardefault
#define    DefaultFlashType27             Typedefault
#endif

#if(Par_Num>=28)
#define    DefaultFlashValue28            Pardefault
#define    DefaultFlashType28             Typedefault
#endif

#if(Par_Num>=29)
#define    DefaultFlashValue29            Pardefault
#define    DefaultFlashType29             Typedefault
#endif

#if(Par_Num>=30)
#define    DefaultFlashValue30            Pardefault
#define    DefaultFlashType30             Typedefault
#endif

#if(Par_Num>=31)
#define    DefaultFlashValue31            Pardefault
#define    DefaultFlashType31             Typedefault
#endif

#if(Par_Num>=32)
#define    DefaultFlashValue32            Pardefault
#define    DefaultFlashType32             Typedefault
#endif

#if(Par_Num>=33)
#define    DefaultFlashValue33            Pardefault
#define    DefaultFlashType33             Typedefault
#endif

#if(Par_Num>=34)
#define    DefaultFlashValue34            Pardefault
#define    DefaultFlashType34             Typedefault
#endif

#if(Par_Num>=35)
#define    DefaultFlashValue35            Pardefault
#define    DefaultFlashType35             Typedefault
#endif

#if(Par_Num>=36)
#define    DefaultFlashValue36            Pardefault
#define    DefaultFlashType36             Typedefault
#endif

#if(Par_Num>=37)
#define    DefaultFlashValue37            Pardefault
#define    DefaultFlashType37             Typedefault
#endif

#if(Par_Num>=38)
#define    DefaultFlashValue38            Pardefault
#define    DefaultFlashType38             Typedefault
#endif

#if(Par_Num>=39)
#define    DefaultFlashValue39            Pardefault
#define    DefaultFlashType39             Typedefault
#endif

#if(Par_Num>=40)
#define    DefaultFlashValue40            Pardefault
#define    DefaultFlashType40             Typedefault
#endif

#if(Par_Num>=41)
#define    DefaultFlashValue41            Pardefault
#define    DefaultFlashType41             Typedefault
#endif

#if(Par_Num>=42)
#define    DefaultFlashValue42            Pardefault
#define    DefaultFlashType42             Typedefault
#endif

#if(Par_Num>=43)
#define    DefaultFlashValue43            Pardefault
#define    DefaultFlashType43             Typedefault
#endif

#if(Par_Num>=44)
#define    DefaultFlashValue44            Pardefault
#define    DefaultFlashType44             Typedefault
#endif

#if(Par_Num>=45)
#define    DefaultFlashValue45            Pardefault
#define    DefaultFlashType45             Typedefault
#endif

#if(Par_Num>=46)
#define    DefaultFlashValue46            Pardefault
#define    DefaultFlashType46             Typedefault
#endif

#if(Par_Num>=47)
#define    DefaultFlashValue47            Pardefault
#define    DefaultFlashType47             Typedefault
#endif

#if(Par_Num>=48)
#define    DefaultFlashValue48            Pardefault
#define    DefaultFlashType48             Typedefault
#endif

#if(Par_Num>=49)
#define    DefaultFlashValue49            Pardefault
#define    DefaultFlashType49             Typedefault
#endif

#if(Par_Num>=50)
#define    DefaultFlashValue50            Pardefault
#define    DefaultFlashType50             Typedefault
#endif

#if(Par_Num>=51)
#define    DefaultFlashValue51            Pardefault
#define    DefaultFlashType51             Typedefault
#endif

#if(Par_Num>=52)
#define    DefaultFlashValue52            Pardefault
#define    DefaultFlashType52             Typedefault
#endif

#if(Par_Num>=53)
#define    DefaultFlashValue53            Pardefault
#define    DefaultFlashType53             Typedefault
#endif

#if(Par_Num>=54)
#define    DefaultFlashValue54            Pardefault
#define    DefaultFlashType54             Typedefault
#endif

#if(Par_Num>=55)
#define    DefaultFlashValue55            Pardefault
#define    DefaultFlashType55             Typedefault
#endif

#if(Par_Num>=56)
#define    DefaultFlashValue56            Pardefault
#define    DefaultFlashType56             Typedefault
#endif

#if(Par_Num>=57)
#define    DefaultFlashValue57            Pardefault
#define    DefaultFlashType57             Typedefault
#endif

#if(Par_Num>=58)
#define    DefaultFlashValue58            Pardefault
#define    DefaultFlashType58             Typedefault
#endif

#if(Par_Num>=59)
#define    DefaultFlashValue59            Pardefault
#define    DefaultFlashType59             Typedefault
#endif

#if(Par_Num>=60)
#define    DefaultFlashValue60            Pardefault
#define    DefaultFlashType60             Typedefault
#endif

#if(Par_Num>=61)
#define    DefaultFlashValue61            Pardefault
#define    DefaultFlashType61             Typedefault
#endif

#if(Par_Num>=62)
#define    DefaultFlashValue62            Pardefault
#define    DefaultFlashType62             Typedefault
#endif

#if(Par_Num>=63)
#define    DefaultFlashValue63            Pardefault
#define    DefaultFlashType63             Typedefault
#endif

#if(Par_Num>=64)
#define    DefaultFlashValue64            Pardefault
#define    DefaultFlashType64             Typedefault
#endif

#if(Par_Num>=65)
#define    DefaultFlashValue65            Pardefault
#define    DefaultFlashType65             Typedefault
#endif

#if(Par_Num>=66)
#define    DefaultFlashValue66            Pardefault
#define    DefaultFlashType66             Typedefault
#endif

#if(Par_Num>=67)
#define    DefaultFlashValue67            Pardefault
#define    DefaultFlashType67             Typedefault
#endif

#if(Par_Num>=68)
#define    DefaultFlashValue68            Pardefault
#define    DefaultFlashType68             Typedefault
#endif

#if(Par_Num>=69)
#define    DefaultFlashValue69            Pardefault
#define    DefaultFlashType69             Typedefault
#endif

#if(Par_Num>=70)
#define    DefaultFlashValue70            Pardefault
#define    DefaultFlashType70             Typedefault
#endif

#if(Par_Num>=71)
#define    DefaultFlashValue71            Pardefault
#define    DefaultFlashType71             Typedefault
#endif

#if(Par_Num>=72)
#define    DefaultFlashValue72            Pardefault
#define    DefaultFlashType72             Typedefault
#endif

#if(Par_Num>=73)
#define    DefaultFlashValue73            Pardefault
#define    DefaultFlashType73             Typedefault
#endif

#if(Par_Num>=74)
#define    DefaultFlashValue74            Pardefault
#define    DefaultFlashType74             Typedefault
#endif

#if(Par_Num>=75)
#define    DefaultFlashValue75            Pardefault
#define    DefaultFlashType75             Typedefault
#endif

#if(Par_Num>=76)
#define    DefaultFlashValue76            Pardefault
#define    DefaultFlashType76             Typedefault
#endif

#if(Par_Num>=77)
#define    DefaultFlashValue77            Pardefault
#define    DefaultFlashType77             Typedefault
#endif

#if(Par_Num>=78)
#define    DefaultFlashValue78            Pardefault
#define    DefaultFlashType78             Typedefault
#endif

#if(Par_Num>=79)
#define    DefaultFlashValue79            Pardefault
#define    DefaultFlashType79             Typedefault
#endif

#if(Par_Num>=80)
#define    DefaultFlashValue80            Pardefault
#define    DefaultFlashType80             Typedefault
#endif

#if(Par_Num>=81)
#define    DefaultFlashValue81            Pardefault
#define    DefaultFlashType81             Typedefault
#endif

#if(Par_Num>=82)
#define    DefaultFlashValue82            Pardefault
#define    DefaultFlashType82             Typedefault
#endif

#if(Par_Num>=83)
#define    DefaultFlashValue83            Pardefault
#define    DefaultFlashType83             Typedefault
#endif

#if(Par_Num>=84)
#define    DefaultFlashValue84            Pardefault
#define    DefaultFlashType84             Typedefault
#endif

#if(Par_Num>=85)
#define    DefaultFlashValue85            Pardefault
#define    DefaultFlashType85             Typedefault
#endif

#if(Par_Num>=86)
#define    DefaultFlashValue86            Pardefault
#define    DefaultFlashType86             Typedefault
#endif

#if(Par_Num>=87)
#define    DefaultFlashValue87            Pardefault
#define    DefaultFlashType87             Typedefault
#endif

#if(Par_Num>=88)
#define    DefaultFlashValue88            Pardefault
#define    DefaultFlashType88             Typedefault
#endif

#if(Par_Num>=89)
#define    DefaultFlashValue89            Pardefault
#define    DefaultFlashType89             Typedefault
#endif

#if(Par_Num>=90)
#define    DefaultFlashValue90            Pardefault
#define    DefaultFlashType90             Typedefault
#endif

#if(Par_Num>=91)
#define    DefaultFlashValue91            Pardefault
#define    DefaultFlashType91             Typedefault
#endif

#if(Par_Num>=92)
#define    DefaultFlashValue92            Pardefault
#define    DefaultFlashType92             Typedefault
#endif

#if(Par_Num>=93)
#define    DefaultFlashValue93            Pardefault
#define    DefaultFlashType93             Typedefault
#endif

#if(Par_Num>=94)
#define    DefaultFlashValue94            Pardefault
#define    DefaultFlashType94             Typedefault
#endif

#if(Par_Num>=95)
#define    DefaultFlashValue95            Pardefault
#define    DefaultFlashType95             Typedefault
#endif

#if(Par_Num>=96)
#define    DefaultFlashValue96            Pardefault
#define    DefaultFlashType96             Typedefault
#endif

#if(Par_Num>=97)
#define    DefaultFlashValue97            Pardefault
#define    DefaultFlashType97             Typedefault
#endif

#if(Par_Num>=98)
#define    DefaultFlashValue98            Pardefault
#define    DefaultFlashType98             Typedefault
#endif

#if(Par_Num>=99)
#define    DefaultFlashValue99            Pardefault
#define    DefaultFlashType99             Typedefault
#endif

#if(Par_Num>=100)
#define    DefaultFlashValue100            Pardefault
#define    DefaultFlashType100             Typedefault
#endif

#if(Par_Num>=101)
#define    DefaultFlashValue101            Pardefault
#define    DefaultFlashType101             Typedefault
#endif

#if(Par_Num>=102)
#define    DefaultFlashValue102            Pardefault
#define    DefaultFlashType102             Typedefault
#endif

#if(Par_Num>=103)
#define    DefaultFlashValue103            Pardefault
#define    DefaultFlashType103             Typedefault
#endif

#if(Par_Num>=104)
#define    DefaultFlashValue104            Pardefault
#define    DefaultFlashType104             Typedefault
#endif

#if(Par_Num>=105)
#define    DefaultFlashValue105            Pardefault
#define    DefaultFlashType105             Typedefault
#endif

#if(Par_Num>=106)
#define    DefaultFlashValue106            Pardefault
#define    DefaultFlashType106             Typedefault
#endif

#if(Par_Num>=107)
#define    DefaultFlashValue107            Pardefault
#define    DefaultFlashType107             Typedefault
#endif

#if(Par_Num>=108)
#define    DefaultFlashValue108            Pardefault
#define    DefaultFlashType108             Typedefault
#endif

#if(Par_Num>=109)
#define    DefaultFlashValue109            Pardefault
#define    DefaultFlashType109             Typedefault
#endif

#if(Par_Num>=110)
#define    DefaultFlashValue110            Pardefault
#define    DefaultFlashType110             Typedefault
#endif

#if(Par_Num>=111)
#define    DefaultFlashValue111            Pardefault
#define    DefaultFlashType111             Typedefault
#endif

#if(Par_Num>=112)
#define    DefaultFlashValue112            Pardefault
#define    DefaultFlashType112             Typedefault
#endif

#if(Par_Num>=113)
#define    DefaultFlashValue113            Pardefault
#define    DefaultFlashType113             Typedefault
#endif

#if(Par_Num>=114)
#define    DefaultFlashValue114            Pardefault
#define    DefaultFlashType114             Typedefault
#endif

#if(Par_Num>=115)
#define    DefaultFlashValue115            Pardefault
#define    DefaultFlashType115             Typedefault
#endif

#if(Par_Num>=116)
#define    DefaultFlashValue116            Pardefault
#define    DefaultFlashType116             Typedefault
#endif

#if(Par_Num>=117)
#define    DefaultFlashValue117            Pardefault
#define    DefaultFlashType117             Typedefault
#endif

#if(Par_Num>=118)
#define    DefaultFlashValue118            Pardefault
#define    DefaultFlashType118             Typedefault
#endif

#if(Par_Num>=119)
#define    DefaultFlashValue119            Pardefault
#define    DefaultFlashType119             Typedefault
#endif

#if(Par_Num>=120)
#define    DefaultFlashValue120            Pardefault
#define    DefaultFlashType120             Typedefault
#endif

#if(Par_Num>=121)
#define    DefaultFlashValue121            Pardefault
#define    DefaultFlashType121             Typedefault
#endif

#if(Par_Num>=122)
#define    DefaultFlashValue122            Pardefault
#define    DefaultFlashType122             Typedefault
#endif

#if(Par_Num>=123)
#define    DefaultFlashValue123            Pardefault
#define    DefaultFlashType123             Typedefault
#endif

#if(Par_Num>=124)
#define    DefaultFlashValue124            Pardefault
#define    DefaultFlashType124             Typedefault
#endif

#if(Par_Num>=125)
#define    DefaultFlashValue125            Pardefault
#define    DefaultFlashType125             Typedefault
#endif

#if(Par_Num>=126)
#define    DefaultFlashValue126            Pardefault
#define    DefaultFlashType126             Typedefault
#endif

#if(Par_Num>=127)
#define    DefaultFlashValue127            Pardefault
#define    DefaultFlashType127             Typedefault
#endif

#if(Par_Num>=128)
#define    DefaultFlashValue128            Pardefault
#define    DefaultFlashType128             Typedefault
#endif

#if(Par_Num>=129)
#define    DefaultFlashValue129            Pardefault
#define    DefaultFlashType129             Typedefault
#endif

#if(Par_Num>=130)
#define    DefaultFlashValue130            Pardefault
#define    DefaultFlashType130             Typedefault
#endif

#if(Par_Num>=131)
#define    DefaultFlashValue131            Pardefault
#define    DefaultFlashType131             Typedefault
#endif

#if(Par_Num>=132)
#define    DefaultFlashValue132            Pardefault
#define    DefaultFlashType132             Typedefault
#endif

#if(Par_Num>=133)
#define    DefaultFlashValue133            Pardefault
#define    DefaultFlashType133             Typedefault
#endif

#if(Par_Num>=134)
#define    DefaultFlashValue134            Pardefault
#define    DefaultFlashType134             Typedefault
#endif

#if(Par_Num>=135)
#define    DefaultFlashValue135            Pardefault
#define    DefaultFlashType135             Typedefault
#endif

#if(Par_Num>=136)
#define    DefaultFlashValue136            Pardefault
#define    DefaultFlashType136             Typedefault
#endif

#if(Par_Num>=137)
#define    DefaultFlashValue137            Pardefault
#define    DefaultFlashType137             Typedefault
#endif

#if(Par_Num>=138)
#define    DefaultFlashValue138            Pardefault
#define    DefaultFlashType138             Typedefault
#endif

#if(Par_Num>=139)
#define    DefaultFlashValue139            Pardefault
#define    DefaultFlashType139             Typedefault
#endif

#if(Par_Num>=140)
#define    DefaultFlashValue140            Pardefault
#define    DefaultFlashType140             Typedefault
#endif

#if(Par_Num>=141)
#define    DefaultFlashValue141            Pardefault
#define    DefaultFlashType141             Typedefault
#endif

#if(Par_Num>=142)
#define    DefaultFlashValue142            Pardefault
#define    DefaultFlashType142             Typedefault
#endif

#if(Par_Num>=143)
#define    DefaultFlashValue143            Pardefault
#define    DefaultFlashType143             Typedefault
#endif

#if(Par_Num>=144)
#define    DefaultFlashValue144            Pardefault
#define    DefaultFlashType144             Typedefault
#endif

#if(Par_Num>=145)
#define    DefaultFlashValue145            Pardefault
#define    DefaultFlashType145             Typedefault
#endif

#if(Par_Num>=146)
#define    DefaultFlashValue146            Pardefault
#define    DefaultFlashType146             Typedefault
#endif

#if(Par_Num>=147)
#define    DefaultFlashValue147            Pardefault
#define    DefaultFlashType147             Typedefault
#endif

#if(Par_Num>=148)
#define    DefaultFlashValue148            Pardefault
#define    DefaultFlashType148             Typedefault
#endif

#if(Par_Num>=149)
#define    DefaultFlashValue149            Pardefault
#define    DefaultFlashType149             Typedefault
#endif

#if(Par_Num>=150)
#define    DefaultFlashValue150            Pardefault
#define    DefaultFlashType150             Typedefault
#endif

#if(Par_Num>=151)
#define    DefaultFlashValue151            Pardefault
#define    DefaultFlashType151             Typedefault
#endif

#if(Par_Num>=152)
#define    DefaultFlashValue152            Pardefault
#define    DefaultFlashType152             Typedefault
#endif

#if(Par_Num>=153)
#define    DefaultFlashValue153            Pardefault
#define    DefaultFlashType153             Typedefault
#endif

#if(Par_Num>=154)
#define    DefaultFlashValue154            Pardefault
#define    DefaultFlashType154             Typedefault
#endif

#if(Par_Num>=155)
#define    DefaultFlashValue155            Pardefault
#define    DefaultFlashType155             Typedefault
#endif

#if(Par_Num>=156)
#define    DefaultFlashValue156            Pardefault
#define    DefaultFlashType156             Typedefault
#endif

#if(Par_Num>=157)
#define    DefaultFlashValue157            Pardefault
#define    DefaultFlashType157             Typedefault
#endif

#if(Par_Num>=158)
#define    DefaultFlashValue158            Pardefault
#define    DefaultFlashType158             Typedefault
#endif

#if(Par_Num>=159)
#define    DefaultFlashValue159            Pardefault
#define    DefaultFlashType159             Typedefault
#endif

#if(Par_Num>=160)
#define    DefaultFlashValue160            Pardefault
#define    DefaultFlashType160             Typedefault
#endif

#if(Par_Num>=161)
#define    DefaultFlashValue161            Pardefault
#define    DefaultFlashType161             Typedefault
#endif

#if(Par_Num>=162)
#define    DefaultFlashValue162            Pardefault
#define    DefaultFlashType162             Typedefault
#endif

#if(Par_Num>=163)
#define    DefaultFlashValue163            Pardefault
#define    DefaultFlashType163             Typedefault
#endif

#if(Par_Num>=164)
#define    DefaultFlashValue164            Pardefault
#define    DefaultFlashType164             Typedefault
#endif

#if(Par_Num>=165)
#define    DefaultFlashValue165            Pardefault
#define    DefaultFlashType165             Typedefault
#endif

#if(Par_Num>=166)
#define    DefaultFlashValue166            Pardefault
#define    DefaultFlashType166             Typedefault
#endif

#if(Par_Num>=167)
#define    DefaultFlashValue167            Pardefault
#define    DefaultFlashType167             Typedefault
#endif

#if(Par_Num>=168)
#define    DefaultFlashValue168            Pardefault
#define    DefaultFlashType168             Typedefault
#endif

#if(Par_Num>=169)
#define    DefaultFlashValue169            Pardefault
#define    DefaultFlashType169             Typedefault
#endif

#if(Par_Num>=170)
#define    DefaultFlashValue170            Pardefault
#define    DefaultFlashType170             Typedefault
#endif

#if(Par_Num>=171)
#define    DefaultFlashValue171            Pardefault
#define    DefaultFlashType171             Typedefault
#endif

#if(Par_Num>=172)
#define    DefaultFlashValue172            Pardefault
#define    DefaultFlashType172             Typedefault
#endif

#if(Par_Num>=173)
#define    DefaultFlashValue173            Pardefault
#define    DefaultFlashType173             Typedefault
#endif

#if(Par_Num>=174)
#define    DefaultFlashValue174            Pardefault
#define    DefaultFlashType174             Typedefault
#endif

#if(Par_Num>=175)
#define    DefaultFlashValue175            Pardefault
#define    DefaultFlashType175             Typedefault
#endif

#if(Par_Num>=176)
#define    DefaultFlashValue176            Pardefault
#define    DefaultFlashType176             Typedefault
#endif

#if(Par_Num>=177)
#define    DefaultFlashValue177            Pardefault
#define    DefaultFlashType177             Typedefault
#endif

#if(Par_Num>=178)
#define    DefaultFlashValue178            Pardefault
#define    DefaultFlashType178             Typedefault
#endif

#if(Par_Num>=179)
#define    DefaultFlashValue179            Pardefault
#define    DefaultFlashType179             Typedefault
#endif

#if(Par_Num>=180)
#define    DefaultFlashValue180            Pardefault
#define    DefaultFlashType180             Typedefault
#endif

#if(Par_Num>=181)
#define    DefaultFlashValue181            Pardefault
#define    DefaultFlashType181             Typedefault
#endif

#if(Par_Num>=182)
#define    DefaultFlashValue182            Pardefault
#define    DefaultFlashType182             Typedefault
#endif

#if(Par_Num>=183)
#define    DefaultFlashValue183            Pardefault
#define    DefaultFlashType183             Typedefault
#endif

#if(Par_Num>=184)
#define    DefaultFlashValue184            Pardefault
#define    DefaultFlashType184             Typedefault
#endif

#if(Par_Num>=185)
#define    DefaultFlashValue185            Pardefault
#define    DefaultFlashType185             Typedefault
#endif

#if(Par_Num>=186)
#define    DefaultFlashValue186            Pardefault
#define    DefaultFlashType186             Typedefault
#endif
#endif


void SetFlashDataToCon(void);
void INI_Flash_Count_Save(void);//普通保存参数 用于存储配置信息，双缓存存储
void INI_Flash_Erssce(void);//块檫除函数
void INI_Flash_Count_Write(void);// 包含图像数量
void INI_Flash_Par_Write(void);//写入参数 包含图像数量
void INI_Flash_Count_Read(void);
void INI_Flash_Par_Read(void);//读取配置参数
void INI_Flash_Init(void);
#ifdef __cplusplus
}
#endif

#endif

