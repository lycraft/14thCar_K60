#include "menu.h"
#include "ftm.h"
#include "oled.h"
#include "key.h"
#include "string.h"
#include "extern.h"
#include "shuju.h"
uint8_t hang = 1;
uint16_t  Default=0;

struct Menu_Select Allnum[All_Count];

void Menu_Init(void)
{

#if(All_Count >= 1)
   strcpy(Allnum[0].name, name0);  //把name0传给结构体中的name数组
   Allnum[0].va = (uint16_t*)&(name0_value);	//把name0_value的地址传给结构体中的va	
   Allnum[0].sub = name0_sub;      //把name0_sub传给结构体中的sub
   Allnum[0].type = name0_type;   //把name0_sub传给结构体中的type
#endif


#if(All_Count >= 2)
   strcpy(Allnum[1].name, name1);
   Allnum[1].va = (uint16_t*)&(name1_value);			
   Allnum[1].sub = name1_sub;
   Allnum[1].type = name1_type;
#endif


#if(All_Count >= 3)
   strcpy(Allnum[2].name, name2);
   Allnum[2].va = (uint16_t*)&(name2_value);			
   Allnum[2].sub = name2_sub;
   Allnum[2].type = name2_type;
#endif


#if(All_Count >= 4)
   strcpy(Allnum[3].name, name3);
   Allnum[3].va = (uint16_t*)&(name3_value);			
   Allnum[3].sub = name3_sub;
   Allnum[3].type = name3_type;
#endif


#if(All_Count >= 5)
   strcpy(Allnum[4].name, name4);
   Allnum[4].va = (uint16_t*)&(name4_value);			
   Allnum[4].sub = name4_sub;
   Allnum[4].type = name4_type;
#endif


#if(All_Count >= 6)
   strcpy(Allnum[5].name, name5);
   Allnum[5].va = (uint16_t*)&(name5_value);			
   Allnum[5].sub = name5_sub;
   Allnum[5].type = name5_type;
#endif


#if(All_Count >= 7)
   strcpy(Allnum[6].name, name6);
   Allnum[6].va = (uint16_t*)&(name6_value);			
   Allnum[6].sub = name6_sub;
   Allnum[6].type = name6_type;
#endif


#if(All_Count >= 8)
   strcpy(Allnum[7].name, name7);
   Allnum[7].va = (uint16_t*)&(name7_value);			
   Allnum[7].sub = name7_sub;
   Allnum[7].type = name7_type;
#endif


#if(All_Count >= 9)
   strcpy(Allnum[8].name, name8);
   Allnum[8].va = (uint16_t*)&(name8_value);			
   Allnum[8].sub = name8_sub;
   Allnum[8].type = name8_type;
#endif


#if(All_Count >= 10)
   strcpy(Allnum[9].name, name9);
   Allnum[9].va = (uint16_t*)&(name9_value);			
   Allnum[9].sub = name9_sub;
   Allnum[9].type = name9_type;
#endif


#if(All_Count >= 11)
   strcpy(Allnum[10].name, name10);
   Allnum[10].va = (uint16_t*)&(name10_value);			
   Allnum[10].sub = name10_sub;
   Allnum[10].type = name10_type;
#endif


#if(All_Count >= 12)
   strcpy(Allnum[11].name, name11);
   Allnum[11].va = (uint16_t*)&(name11_value);			
   Allnum[11].sub = name11_sub;
   Allnum[11].type = name11_type;
#endif


#if(All_Count >= 13)
   strcpy(Allnum[12].name, name12);
   Allnum[12].va = (uint16_t*)&(name12_value);			
   Allnum[12].sub = name12_sub;
   Allnum[12].type = name12_type;
#endif


#if(All_Count >= 14)
   strcpy(Allnum[13].name, name13);
   Allnum[13].va = (uint16_t*)&(name13_value);			
   Allnum[13].sub = name13_sub;
   Allnum[13].type = name13_type;
#endif


#if(All_Count >= 15)
   strcpy(Allnum[14].name, name14);
   Allnum[14].va = (uint16_t*)&(name14_value);			
   Allnum[14].sub = name14_sub;
   Allnum[14].type = name14_type;
#endif


#if(All_Count >= 16)
   strcpy(Allnum[15].name, name15);
   Allnum[15].va = (uint16_t*)&(name15_value);			
   Allnum[15].sub = name15_sub;
   Allnum[15].type = name15_type;
#endif


#if(All_Count >= 17)
   strcpy(Allnum[16].name, name16);
   Allnum[16].va = (uint16_t*)&(name16_value);			
   Allnum[16].sub = name16_sub;
   Allnum[16].type = name16_type;
#endif


#if(All_Count >= 18)
   strcpy(Allnum[17].name, name17);
   Allnum[17].va = (uint16_t*)&(name17_value);			
   Allnum[17].sub = name17_sub;
   Allnum[17].type = name17_type;
#endif


#if(All_Count >= 19)
   strcpy(Allnum[18].name, name18);
   Allnum[18].va = (uint16_t*)&(name18_value);			
   Allnum[18].sub = name18_sub;
   Allnum[18].type = name18_type;
#endif


#if(All_Count >= 20)
   strcpy(Allnum[19].name, name19);
   Allnum[19].va = (uint16_t*)&(name19_value);			
   Allnum[19].sub = name19_sub;
   Allnum[19].type = name19_type;
#endif


#if(All_Count >= 21)
   strcpy(Allnum[20].name, name20);
   Allnum[20].va = (uint16_t*)&(name20_value);			
   Allnum[20].sub = name20_sub;
   Allnum[20].type = name20_type;
#endif


#if(All_Count >= 22)
   strcpy(Allnum[21].name, name21);
   Allnum[21].va = (uint16_t*)&(name21_value);			
   Allnum[21].sub = name21_sub;
   Allnum[21].type = name21_type;
#endif


#if(All_Count >= 23)
   strcpy(Allnum[22].name, name22);
   Allnum[22].va = (uint16_t*)&(name22_value);			
   Allnum[22].sub = name22_sub;
   Allnum[22].type = name22_type;
#endif


#if(All_Count >= 24)
   strcpy(Allnum[23].name, name23);
   Allnum[23].va = (uint16_t*)&(name23_value);			
   Allnum[23].sub = name23_sub;
   Allnum[23].type = name23_type;
#endif


#if(All_Count >= 25)
   strcpy(Allnum[24].name, name24);
   Allnum[24].va = (uint16_t*)&(name24_value);			
   Allnum[24].sub = name24_sub;
   Allnum[24].type = name24_type;
#endif


#if(All_Count >= 26)
   strcpy(Allnum[25].name, name25);
   Allnum[25].va = (uint16_t*)&(name25_value);			
   Allnum[25].sub = name25_sub;
   Allnum[25].type = name25_type;
#endif


#if(All_Count >= 27)
   strcpy(Allnum[26].name, name26);
   Allnum[26].va = (uint16_t*)&(name26_value);			
   Allnum[26].sub = name26_sub;
   Allnum[26].type = name26_type;
#endif


#if(All_Count >= 28)
   strcpy(Allnum[27].name, name27);
   Allnum[27].va = (uint16_t*)&(name27_value);			
   Allnum[27].sub = name27_sub;
   Allnum[27].type = name27_type;
#endif


#if(All_Count >= 29)
   strcpy(Allnum[28].name, name28);
   Allnum[28].va = (uint16_t*)&(name28_value);			
   Allnum[28].sub = name28_sub;
   Allnum[28].type = name28_type;
#endif


#if(All_Count >= 30)
   strcpy(Allnum[29].name, name29);
   Allnum[29].va = (uint16_t*)&(name29_value);			
   Allnum[29].sub = name29_sub;
   Allnum[29].type = name29_type;
#endif


#if(All_Count >= 31)
   strcpy(Allnum[30].name, name30);
   Allnum[30].va = (uint16_t*)&(name30_value);			
   Allnum[30].sub = name30_sub;
   Allnum[30].type = name30_type;
#endif


#if(All_Count >= 32)
   strcpy(Allnum[31].name, name31);
   Allnum[31].va = (uint16_t*)&(name31_value);			
   Allnum[31].sub = name31_sub;
   Allnum[31].type = name31_type;
#endif


#if(All_Count >= 33)
   strcpy(Allnum[32].name, name32);
   Allnum[32].va = (uint16_t*)&(name32_value);			
   Allnum[32].sub = name32_sub;
   Allnum[32].type = name32_type;
#endif


#if(All_Count >= 34)
   strcpy(Allnum[33].name, name33);
   Allnum[33].va = (uint16_t*)&(name33_value);			
   Allnum[33].sub = name33_sub;
   Allnum[33].type = name33_type;
#endif


#if(All_Count >= 35)
   strcpy(Allnum[34].name, name34);
   Allnum[34].va = (uint16_t*)&(name34_value);			
   Allnum[34].sub = name34_sub;
   Allnum[34].type = name34_type;
#endif


#if(All_Count >= 36)
   strcpy(Allnum[35].name, name35);
   Allnum[35].va = (uint16_t*)&(name35_value);			
   Allnum[35].sub = name35_sub;
   Allnum[35].type = name35_type;
#endif


#if(All_Count >= 37)
   strcpy(Allnum[36].name, name36);
   Allnum[36].va = (uint16_t*)&(name36_value);			
   Allnum[36].sub = name36_sub;
   Allnum[36].type = name36_type;
#endif


#if(All_Count >= 38)
   strcpy(Allnum[37].name, name37);
   Allnum[37].va = (uint16_t*)&(name37_value);			
   Allnum[37].sub = name37_sub;
   Allnum[37].type = name37_type;
#endif


#if(All_Count >= 39)
   strcpy(Allnum[38].name, name38);
   Allnum[38].va = (uint16_t*)&(name38_value);			
   Allnum[38].sub = name38_sub;
   Allnum[38].type = name38_type;
#endif


#if(All_Count >= 40)
   strcpy(Allnum[39].name, name39);
   Allnum[39].va = (uint16_t*)&(name39_value);			
   Allnum[39].sub = name39_sub;
   Allnum[39].type = name39_type;
#endif


#if(All_Count >= 41)
   strcpy(Allnum[40].name, name40);
   Allnum[40].va = (uint16_t*)&(name40_value);			
   Allnum[40].sub = name40_sub;
   Allnum[40].type = name40_type;
#endif


#if(All_Count >= 42)
   strcpy(Allnum[41].name, name41);
   Allnum[41].va = (uint16_t*)&(name41_value);			
   Allnum[41].sub = name41_sub;
   Allnum[41].type = name41_type;
#endif


#if(All_Count >= 43)
   strcpy(Allnum[42].name, name42);
   Allnum[42].va = (uint16_t*)&(name42_value);			
   Allnum[42].sub = name42_sub;
   Allnum[42].type = name42_type;
#endif


#if(All_Count >= 44)
   strcpy(Allnum[43].name, name43);
   Allnum[43].va = (uint16_t*)&(name43_value);			
   Allnum[43].sub = name43_sub;
   Allnum[43].type = name43_type;
#endif


#if(All_Count >= 45)
   strcpy(Allnum[44].name, name44);
   Allnum[44].va = (uint16_t*)&(name44_value);			
   Allnum[44].sub = name44_sub;
   Allnum[44].type = name44_type;
#endif


#if(All_Count >= 46)
   strcpy(Allnum[45].name, name45);
   Allnum[45].va = (uint16_t*)&(name45_value);			
   Allnum[45].sub = name45_sub;
   Allnum[45].type = name45_type;
#endif


#if(All_Count >= 47)
   strcpy(Allnum[46].name, name46);
   Allnum[46].va = (uint16_t*)&(name46_value);			
   Allnum[46].sub = name46_sub;
   Allnum[46].type = name46_type;
#endif


#if(All_Count >= 48)
   strcpy(Allnum[47].name, name47);
   Allnum[47].va = (uint16_t*)&(name47_value);			
   Allnum[47].sub = name47_sub;
   Allnum[47].type = name47_type;
#endif


#if(All_Count >= 49)
   strcpy(Allnum[48].name, name48);
   Allnum[48].va = (uint16_t*)&(name48_value);			
   Allnum[48].sub = name48_sub;
   Allnum[48].type = name48_type;
#endif


#if(All_Count >= 50)
   strcpy(Allnum[49].name, name49);
   Allnum[49].va = (uint16_t*)&(name49_value);			
   Allnum[49].sub = name49_sub;
   Allnum[49].type = name49_type;
#endif


#if(All_Count >= 51)
   strcpy(Allnum[50].name, name50);
   Allnum[50].va = (uint16_t*)&(name50_value);			
   Allnum[50].sub = name50_sub;
   Allnum[50].type = name50_type;
#endif


#if(All_Count >= 52)
   strcpy(Allnum[51].name, name51);
   Allnum[51].va = (uint16_t*)&(name51_value);			
   Allnum[51].sub = name51_sub;
   Allnum[51].type = name51_type;
#endif


#if(All_Count >= 53)
   strcpy(Allnum[52].name, name52);
   Allnum[52].va = (uint16_t*)&(name52_value);			
   Allnum[52].sub = name52_sub;
   Allnum[52].type = name52_type;
#endif


#if(All_Count >= 54)
   strcpy(Allnum[53].name, name53);
   Allnum[53].va = (uint16_t*)&(name53_value);			
   Allnum[53].sub = name53_sub;
   Allnum[53].type = name53_type;
#endif


#if(All_Count >= 55)
   strcpy(Allnum[54].name, name54);
   Allnum[54].va = (uint16_t*)&(name54_value);			
   Allnum[54].sub = name54_sub;
   Allnum[54].type = name54_type;
#endif


#if(All_Count >= 56)
   strcpy(Allnum[55].name, name55);
   Allnum[55].va = (uint16_t*)&(name55_value);			
   Allnum[55].sub = name55_sub;
   Allnum[55].type = name55_type;
#endif


#if(All_Count >= 57)
   strcpy(Allnum[56].name, name56);
   Allnum[56].va = (uint16_t*)&(name56_value);			
   Allnum[56].sub = name56_sub;
   Allnum[56].type = name56_type;
#endif


#if(All_Count >= 58)
   strcpy(Allnum[57].name, name57);
   Allnum[57].va = (uint16_t*)&(name57_value);			
   Allnum[57].sub = name57_sub;
   Allnum[57].type = name57_type;
#endif


#if(All_Count >= 59)
   strcpy(Allnum[58].name, name58);
   Allnum[58].va = (uint16_t*)&(name58_value);			
   Allnum[58].sub = name58_sub;
   Allnum[58].type = name58_type;
#endif


#if(All_Count >= 60)
   strcpy(Allnum[59].name, name59);
   Allnum[59].va = (uint16_t*)&(name59_value);			
   Allnum[59].sub = name59_sub;
   Allnum[59].type = name59_type;
#endif


#if(All_Count >= 61)
   strcpy(Allnum[60].name, name60);
   Allnum[60].va = (uint16_t*)&(name60_value);			
   Allnum[60].sub = name60_sub;
   Allnum[60].type = name60_type;
#endif


#if(All_Count >= 62)
   strcpy(Allnum[61].name, name61);
   Allnum[61].va = (uint16_t*)&(name61_value);			
   Allnum[61].sub = name61_sub;
   Allnum[61].type = name61_type;
#endif


#if(All_Count >= 63)
   strcpy(Allnum[62].name, name62);
   Allnum[62].va = (uint16_t*)&(name62_value);			
   Allnum[62].sub = name62_sub;
   Allnum[62].type = name62_type;
#endif


#if(All_Count >= 64)
   strcpy(Allnum[63].name, name63);
   Allnum[63].va = (uint16_t*)&(name63_value);			
   Allnum[63].sub = name63_sub;
   Allnum[63].type = name63_type;
#endif


#if(All_Count >= 65)
   strcpy(Allnum[64].name, name64);
   Allnum[64].va = (uint16_t*)&(name64_value);			
   Allnum[64].sub = name64_sub;
   Allnum[64].type = name64_type;
#endif


#if(All_Count >= 66)
   strcpy(Allnum[65].name, name65);
   Allnum[65].va = (uint16_t*)&(name65_value);			
   Allnum[65].sub = name65_sub;
   Allnum[65].type = name65_type;
#endif


#if(All_Count >= 67)
   strcpy(Allnum[66].name, name66);
   Allnum[66].va = (uint16_t*)&(name66_value);			
   Allnum[66].sub = name66_sub;
   Allnum[66].type = name66_type;
#endif


#if(All_Count >= 68)
   strcpy(Allnum[67].name, name67);
   Allnum[67].va = (uint16_t*)&(name67_value);			
   Allnum[67].sub = name67_sub;
   Allnum[67].type = name67_type;
#endif


#if(All_Count >= 69)
   strcpy(Allnum[68].name, name68);
   Allnum[68].va = (uint16_t*)&(name68_value);			
   Allnum[68].sub = name68_sub;
   Allnum[68].type = name68_type;
#endif


#if(All_Count >= 70)
   strcpy(Allnum[69].name, name69);
   Allnum[69].va = (uint16_t*)&(name69_value);			
   Allnum[69].sub = name69_sub;
   Allnum[69].type = name69_type;
#endif


#if(All_Count >= 71)
   strcpy(Allnum[70].name, name70);
   Allnum[70].va = (uint16_t*)&(name70_value);			
   Allnum[70].sub = name70_sub;
   Allnum[70].type = name70_type;
#endif


#if(All_Count >= 72)
   strcpy(Allnum[71].name, name71);
   Allnum[71].va = (uint16_t*)&(name71_value);			
   Allnum[71].sub = name71_sub;
   Allnum[71].type = name71_type;
#endif


#if(All_Count >= 73)
   strcpy(Allnum[72].name, name72);
   Allnum[72].va = (uint16_t*)&(name72_value);			
   Allnum[72].sub = name72_sub;
   Allnum[72].type = name72_type;
#endif


#if(All_Count >= 74)
   strcpy(Allnum[73].name, name73);
   Allnum[73].va = (uint16_t*)&(name73_value);			
   Allnum[73].sub = name73_sub;
   Allnum[73].type = name73_type;
#endif


#if(All_Count >= 75)
   strcpy(Allnum[74].name, name74);
   Allnum[74].va = (uint16_t*)&(name74_value);			
   Allnum[74].sub = name74_sub;
   Allnum[74].type = name74_type;
#endif


#if(All_Count >= 76)
   strcpy(Allnum[75].name, name75);
   Allnum[75].va = (uint16_t*)&(name75_value);			
   Allnum[75].sub = name75_sub;
   Allnum[75].type = name75_type;
#endif


#if(All_Count >= 77)
   strcpy(Allnum[76].name, name76);
   Allnum[76].va = (uint16_t*)&(name76_value);			
   Allnum[76].sub = name76_sub;
   Allnum[76].type = name76_type;
#endif


#if(All_Count >= 78)
   strcpy(Allnum[77].name, name77);
   Allnum[77].va = (uint16_t*)&(name77_value);			
   Allnum[77].sub = name77_sub;
   Allnum[77].type = name77_type;
#endif


#if(All_Count >= 79)
   strcpy(Allnum[78].name, name78);
   Allnum[78].va = (uint16_t*)&(name78_value);			
   Allnum[78].sub = name78_sub;
   Allnum[78].type = name78_type;
#endif


#if(All_Count >= 80)
   strcpy(Allnum[79].name, name79);
   Allnum[79].va = (uint16_t*)&(name79_value);			
   Allnum[79].sub = name79_sub;
   Allnum[79].type = name79_type;
#endif


#if(All_Count >= 81)
   strcpy(Allnum[80].name, name80);
   Allnum[80].va = (uint16_t*)&(name80_value);			
   Allnum[80].sub = name80_sub;
   Allnum[80].type = name80_type;
#endif


#if(All_Count >= 82)
   strcpy(Allnum[81].name, name81);
   Allnum[81].va = (uint16_t*)&(name81_value);			
   Allnum[81].sub = name81_sub;
   Allnum[81].type = name81_type;
#endif


#if(All_Count >= 83)
   strcpy(Allnum[82].name, name82);
   Allnum[82].va = (uint16_t*)&(name82_value);			
   Allnum[82].sub = name82_sub;
   Allnum[82].type = name82_type;
#endif


#if(All_Count >= 84)
   strcpy(Allnum[83].name, name83);
   Allnum[83].va = (uint16_t*)&(name83_value);			
   Allnum[83].sub = name83_sub;
   Allnum[83].type = name83_type;
#endif


#if(All_Count >= 85)
   strcpy(Allnum[84].name, name84);
   Allnum[84].va = (uint16_t*)&(name84_value);			
   Allnum[84].sub = name84_sub;
   Allnum[84].type = name84_type;
#endif


#if(All_Count >= 86)
   strcpy(Allnum[85].name, name85);
   Allnum[85].va = (uint16_t*)&(name85_value);			
   Allnum[85].sub = name85_sub;
   Allnum[85].type = name85_type;
#endif


#if(All_Count >= 87)
   strcpy(Allnum[86].name, name86);
   Allnum[86].va = (uint16_t*)&(name86_value);			
   Allnum[86].sub = name86_sub;
   Allnum[86].type = name86_type;
#endif


#if(All_Count >= 88)
   strcpy(Allnum[87].name, name87);
   Allnum[87].va = (uint16_t*)&(name87_value);			
   Allnum[87].sub = name87_sub;
   Allnum[87].type = name87_type;
#endif


#if(All_Count >= 89)
   strcpy(Allnum[88].name, name88);
   Allnum[88].va = (uint16_t*)&(name88_value);			
   Allnum[88].sub = name88_sub;
   Allnum[88].type = name88_type;
#endif


#if(All_Count >= 90)
   strcpy(Allnum[89].name, name89);
   Allnum[89].va = (uint16_t*)&(name89_value);			
   Allnum[89].sub = name89_sub;
   Allnum[89].type = name89_type;
#endif


#if(All_Count >= 91)
   strcpy(Allnum[90].name, name90);
   Allnum[90].va = (uint16_t*)&(name90_value);			
   Allnum[90].sub = name90_sub;
   Allnum[90].type = name90_type;
#endif


#if(All_Count >= 92)
   strcpy(Allnum[91].name, name91);
   Allnum[91].va = (uint16_t*)&(name91_value);			
   Allnum[91].sub = name91_sub;
   Allnum[91].type = name91_type;
#endif


#if(All_Count >= 93)
   strcpy(Allnum[92].name, name92);
   Allnum[92].va = (uint16_t*)&(name92_value);			
   Allnum[92].sub = name92_sub;
   Allnum[92].type = name92_type;
#endif


#if(All_Count >= 94)
   strcpy(Allnum[93].name, name93);
   Allnum[93].va = (uint16_t*)&(name93_value);			
   Allnum[93].sub = name93_sub;
   Allnum[93].type = name93_type;
#endif


#if(All_Count >= 95)
   strcpy(Allnum[94].name, name94);
   Allnum[94].va = (uint16_t*)&(name94_value);			
   Allnum[94].sub = name94_sub;
   Allnum[94].type = name94_type;
#endif


#if(All_Count >= 96)
   strcpy(Allnum[95].name, name95);
   Allnum[95].va = (uint16_t*)&(name95_value);			
   Allnum[95].sub = name95_sub;
   Allnum[95].type = name95_type;
#endif


#if(All_Count >= 97)
   strcpy(Allnum[96].name, name96);
   Allnum[96].va = (uint16_t*)&(name96_value);			
   Allnum[96].sub = name96_sub;
   Allnum[96].type = name96_type;
#endif


#if(All_Count >= 98)
   strcpy(Allnum[97].name, name97);
   Allnum[97].va = (uint16_t*)&(name97_value);			
   Allnum[97].sub = name97_sub;
   Allnum[97].type = name97_type;
#endif


#if(All_Count >= 99)
   strcpy(Allnum[98].name, name98);
   Allnum[98].va = (uint16_t*)&(name98_value);			
   Allnum[98].sub = name98_sub;
   Allnum[98].type = name98_type;
#endif


#if(All_Count >= 100)
   strcpy(Allnum[99].name, name99);
   Allnum[99].va = (uint16_t*)&(name99_value);			
   Allnum[99].sub = name99_sub;
   Allnum[99].type = name99_type;
#endif


#if(All_Count >= 101)
   strcpy(Allnum[100].name, name100);
   Allnum[100].va = (uint16_t*)&(name100_value);			
   Allnum[100].sub = name100_sub;
   Allnum[100].type = name100_type;
#endif


#if(All_Count >= 102)
   strcpy(Allnum[101].name, name101);
   Allnum[101].va = (uint16_t*)&(name101_value);			
   Allnum[101].sub = name101_sub;
   Allnum[101].type = name101_type;
#endif


#if(All_Count >= 103)
   strcpy(Allnum[102].name, name102);
   Allnum[102].va = (uint16_t*)&(name102_value);			
   Allnum[102].sub = name102_sub;
   Allnum[102].type = name102_type;
#endif


#if(All_Count >= 104)
   strcpy(Allnum[103].name, name103);
   Allnum[103].va = (uint16_t*)&(name103_value);			
   Allnum[103].sub = name103_sub;
   Allnum[103].type = name103_type;
#endif


#if(All_Count >= 105)
   strcpy(Allnum[104].name, name104);
   Allnum[104].va = (uint16_t*)&(name104_value);			
   Allnum[104].sub = name104_sub;
   Allnum[104].type = name104_type;
#endif


#if(All_Count >= 106)
   strcpy(Allnum[105].name, name105);
   Allnum[105].va = (uint16_t*)&(name105_value);			
   Allnum[105].sub = name105_sub;
   Allnum[105].type = name105_type;
#endif


#if(All_Count >= 107)
   strcpy(Allnum[106].name, name106);
   Allnum[106].va = (uint16_t*)&(name106_value);			
   Allnum[106].sub = name106_sub;
   Allnum[106].type = name106_type;
#endif


#if(All_Count >= 108)
   strcpy(Allnum[107].name, name107);
   Allnum[107].va = (uint16_t*)&(name107_value);			
   Allnum[107].sub = name107_sub;
   Allnum[107].type = name107_type;
#endif


#if(All_Count >= 109)
   strcpy(Allnum[108].name, name108);
   Allnum[108].va = (uint16_t*)&(name108_value);			
   Allnum[108].sub = name108_sub;
   Allnum[108].type = name108_type;
#endif


#if(All_Count >= 110)
   strcpy(Allnum[109].name, name109);
   Allnum[109].va = (uint16_t*)&(name109_value);			
   Allnum[109].sub = name109_sub;
   Allnum[109].type = name109_type;
#endif


#if(All_Count >= 111)
   strcpy(Allnum[110].name, name110);
   Allnum[110].va = (uint16_t*)&(name110_value);			
   Allnum[110].sub = name110_sub;
   Allnum[110].type = name110_type;
#endif


#if(All_Count >= 112)
   strcpy(Allnum[111].name, name111);
   Allnum[111].va = (uint16_t*)&(name111_value);			
   Allnum[111].sub = name111_sub;
   Allnum[111].type = name111_type;
#endif


#if(All_Count >= 113)
   strcpy(Allnum[112].name, name112);
   Allnum[112].va = (uint16_t*)&(name112_value);			
   Allnum[112].sub = name112_sub;
   Allnum[112].type = name112_type;
#endif


#if(All_Count >= 114)
   strcpy(Allnum[113].name, name113);
   Allnum[113].va = (uint16_t*)&(name113_value);			
   Allnum[113].sub = name113_sub;
   Allnum[113].type = name113_type;
#endif


#if(All_Count >= 115)
   strcpy(Allnum[114].name, name114);
   Allnum[114].va = (uint16_t*)&(name114_value);			
   Allnum[114].sub = name114_sub;
   Allnum[114].type = name114_type;
#endif


#if(All_Count >= 116)
   strcpy(Allnum[115].name, name115);
   Allnum[115].va = (uint16_t*)&(name115_value);			
   Allnum[115].sub = name115_sub;
   Allnum[115].type = name115_type;
#endif


#if(All_Count >= 117)
   strcpy(Allnum[116].name, name116);
   Allnum[116].va = (uint16_t*)&(name116_value);			
   Allnum[116].sub = name116_sub;
   Allnum[116].type = name116_type;
#endif


#if(All_Count >= 118)
   strcpy(Allnum[117].name, name117);
   Allnum[117].va = (uint16_t*)&(name117_value);			
   Allnum[117].sub = name117_sub;
   Allnum[117].type = name117_type;
#endif


#if(All_Count >= 119)
   strcpy(Allnum[118].name, name118);
   Allnum[118].va = (uint16_t*)&(name118_value);			
   Allnum[118].sub = name118_sub;
   Allnum[118].type = name118_type;
#endif


#if(All_Count >= 120)
   strcpy(Allnum[119].name, name119);
   Allnum[119].va = (uint16_t*)&(name119_value);			
   Allnum[119].sub = name119_sub;
   Allnum[119].type = name119_type;
#endif


#if(All_Count >= 121)
   strcpy(Allnum[120].name, name120);
   Allnum[120].va = (uint16_t*)&(name120_value);			
   Allnum[120].sub = name120_sub;
   Allnum[120].type = name120_type;
#endif


#if(All_Count >= 122)
   strcpy(Allnum[121].name, name121);
   Allnum[121].va = (uint16_t*)&(name121_value);			
   Allnum[121].sub = name121_sub;
   Allnum[121].type = name121_type;
#endif


#if(All_Count >= 123)
   strcpy(Allnum[122].name, name122);
   Allnum[122].va = (uint16_t*)&(name122_value);			
   Allnum[122].sub = name122_sub;
   Allnum[122].type = name122_type;
#endif


#if(All_Count >= 124)
   strcpy(Allnum[123].name, name123);
   Allnum[123].va = (uint16_t*)&(name123_value);			
   Allnum[123].sub = name123_sub;
   Allnum[123].type = name123_type;
#endif


#if(All_Count >= 125)
   strcpy(Allnum[124].name, name124);
   Allnum[124].va = (uint16_t*)&(name124_value);			
   Allnum[124].sub = name124_sub;
   Allnum[124].type = name124_type;
#endif


#if(All_Count >= 126)
   strcpy(Allnum[125].name, name125);
   Allnum[125].va = (uint16_t*)&(name125_value);			
   Allnum[125].sub = name125_sub;
   Allnum[125].type = name125_type;
#endif


#if(All_Count >= 127)
   strcpy(Allnum[126].name, name126);
   Allnum[126].va = (uint16_t*)&(name126_value);			
   Allnum[126].sub = name126_sub;
   Allnum[126].type = name126_type;
#endif


#if(All_Count >= 128)
   strcpy(Allnum[127].name, name127);
   Allnum[127].va = (uint16_t*)&(name127_value);			
   Allnum[127].sub = name127_sub;
   Allnum[127].type = name127_type;
#endif


#if(All_Count >= 129)
   strcpy(Allnum[128].name, name128);
   Allnum[128].va = (uint16_t*)&(name128_value);			
   Allnum[128].sub = name128_sub;
   Allnum[128].type = name128_type;
#endif


#if(All_Count >= 130)
   strcpy(Allnum[129].name, name129);
   Allnum[129].va = (uint16_t*)&(name129_value);			
   Allnum[129].sub = name129_sub;
   Allnum[129].type = name129_type;
#endif


#if(All_Count >= 131)
   strcpy(Allnum[130].name, name130);
   Allnum[130].va = (uint16_t*)&(name130_value);			
   Allnum[130].sub = name130_sub;
   Allnum[130].type = name130_type;
#endif


#if(All_Count >= 132)
   strcpy(Allnum[131].name, name131);
   Allnum[131].va = (uint16_t*)&(name131_value);			
   Allnum[131].sub = name131_sub;
   Allnum[131].type = name131_type;
#endif


#if(All_Count >= 133)
   strcpy(Allnum[132].name, name132);
   Allnum[132].va = (uint16_t*)&(name132_value);			
   Allnum[132].sub = name132_sub;
   Allnum[132].type = name132_type;
#endif


#if(All_Count >= 134)
   strcpy(Allnum[133].name, name133);
   Allnum[133].va = (uint16_t*)&(name133_value);			
   Allnum[133].sub = name133_sub;
   Allnum[133].type = name133_type;
#endif


#if(All_Count >= 135)
   strcpy(Allnum[134].name, name134);
   Allnum[134].va = (uint16_t*)&(name134_value);			
   Allnum[134].sub = name134_sub;
   Allnum[134].type = name134_type;
#endif


#if(All_Count >= 136)
   strcpy(Allnum[135].name, name135);
   Allnum[135].va = (uint16_t*)&(name135_value);			
   Allnum[135].sub = name135_sub;
   Allnum[135].type = name135_type;
#endif


#if(All_Count >= 137)
   strcpy(Allnum[136].name, name136);
   Allnum[136].va = (uint16_t*)&(name136_value);			
   Allnum[136].sub = name136_sub;
   Allnum[136].type = name136_type;
#endif


#if(All_Count >= 138)
   strcpy(Allnum[137].name, name137);
   Allnum[137].va = (uint16_t*)&(name137_value);			
   Allnum[137].sub = name137_sub;
   Allnum[137].type = name137_type;
#endif


#if(All_Count >= 139)
   strcpy(Allnum[138].name, name138);
   Allnum[138].va = (uint16_t*)&(name138_value);			
   Allnum[138].sub = name138_sub;
   Allnum[138].type = name138_type;
#endif


#if(All_Count >= 140)
   strcpy(Allnum[139].name, name139);
   Allnum[139].va = (uint16_t*)&(name139_value);			
   Allnum[139].sub = name139_sub;
   Allnum[139].type = name139_type;
#endif


#if(All_Count >= 141)
   strcpy(Allnum[140].name, name140);
   Allnum[140].va = (uint16_t*)&(name140_value);			
   Allnum[140].sub = name140_sub;
   Allnum[140].type = name140_type;
#endif


#if(All_Count >= 142)
   strcpy(Allnum[141].name, name141);
   Allnum[141].va = (uint16_t*)&(name141_value);			
   Allnum[141].sub = name141_sub;
   Allnum[141].type = name141_type;
#endif


#if(All_Count >= 143)
   strcpy(Allnum[142].name, name142);
   Allnum[142].va = (uint16_t*)&(name142_value);			
   Allnum[142].sub = name142_sub;
   Allnum[142].type = name142_type;
#endif


#if(All_Count >= 144)
   strcpy(Allnum[143].name, name143);
   Allnum[143].va = (uint16_t*)&(name143_value);			
   Allnum[143].sub = name143_sub;
   Allnum[143].type = name143_type;
#endif


#if(All_Count >= 145)
   strcpy(Allnum[144].name, name144);
   Allnum[144].va = (uint16_t*)&(name144_value);			
   Allnum[144].sub = name144_sub;
   Allnum[144].type = name144_type;
#endif


#if(All_Count >= 146)
   strcpy(Allnum[145].name, name145);
   Allnum[145].va = (uint16_t*)&(name145_value);			
   Allnum[145].sub = name145_sub;
   Allnum[145].type = name145_type;
#endif


#if(All_Count >= 147)
   strcpy(Allnum[146].name, name146);
   Allnum[146].va = (uint16_t*)&(name146_value);			
   Allnum[146].sub = name146_sub;
   Allnum[146].type = name146_type;
#endif


#if(All_Count >= 148)
   strcpy(Allnum[147].name, name147);
   Allnum[147].va = (uint16_t*)&(name147_value);			
   Allnum[147].sub = name147_sub;
   Allnum[147].type = name147_type;
#endif


#if(All_Count >= 149)
   strcpy(Allnum[148].name, name148);
   Allnum[148].va = (uint16_t*)&(name148_value);			
   Allnum[148].sub = name148_sub;
   Allnum[148].type = name148_type;
#endif


#if(All_Count >= 150)
   strcpy(Allnum[149].name, name149);
   Allnum[149].va = (uint16_t*)&(name149_value);			
   Allnum[149].sub = name149_sub;
   Allnum[149].type = name149_type;
#endif


#if(All_Count >= 151)
   strcpy(Allnum[150].name, name150);
   Allnum[150].va = (uint16_t*)&(name150_value);			
   Allnum[150].sub = name150_sub;
   Allnum[150].type = name150_type;
#endif


#if(All_Count >= 152)
   strcpy(Allnum[151].name, name151);
   Allnum[151].va = (uint16_t*)&(name151_value);			
   Allnum[151].sub = name151_sub;
   Allnum[151].type = name151_type;
#endif


#if(All_Count >= 153)
   strcpy(Allnum[152].name, name152);
   Allnum[152].va = (uint16_t*)&(name152_value);			
   Allnum[152].sub = name152_sub;
   Allnum[152].type = name152_type;
#endif


#if(All_Count >= 154)
   strcpy(Allnum[153].name, name153);
   Allnum[153].va = (uint16_t*)&(name153_value);			
   Allnum[153].sub = name153_sub;
   Allnum[153].type = name153_type;
#endif


#if(All_Count >= 155)
   strcpy(Allnum[154].name, name154);
   Allnum[154].va = (uint16_t*)&(name154_value);			
   Allnum[154].sub = name154_sub;
   Allnum[154].type = name154_type;
#endif


#if(All_Count >= 156)
   strcpy(Allnum[155].name, name155);
   Allnum[155].va = (uint16_t*)&(name155_value);			
   Allnum[155].sub = name155_sub;
   Allnum[155].type = name155_type;
#endif


#if(All_Count >= 157)
   strcpy(Allnum[156].name, name156);
   Allnum[156].va = (uint16_t*)&(name156_value);			
   Allnum[156].sub = name156_sub;
   Allnum[156].type = name156_type;
#endif


#if(All_Count >= 158)
   strcpy(Allnum[157].name, name157);
   Allnum[157].va = (uint16_t*)&(name157_value);			
   Allnum[157].sub = name157_sub;
   Allnum[157].type = name157_type;
#endif


#if(All_Count >= 159)
   strcpy(Allnum[158].name, name158);
   Allnum[158].va = (uint16_t*)&(name158_value);			
   Allnum[158].sub = name158_sub;
   Allnum[158].type = name158_type;
#endif


#if(All_Count >= 160)
   strcpy(Allnum[159].name, name159);
   Allnum[159].va = (uint16_t*)&(name159_value);			
   Allnum[159].sub = name159_sub;
   Allnum[159].type = name159_type;
#endif


#if(All_Count >= 161)
   strcpy(Allnum[160].name, name160);
   Allnum[160].va = (uint16_t*)&(name160_value);			
   Allnum[160].sub = name160_sub;
   Allnum[160].type = name160_type;
#endif


#if(All_Count >= 162)
   strcpy(Allnum[161].name, name161);
   Allnum[161].va = (uint16_t*)&(name161_value);			
   Allnum[161].sub = name161_sub;
   Allnum[161].type = name161_type;
#endif


#if(All_Count >= 163)
   strcpy(Allnum[162].name, name162);
   Allnum[162].va = (uint16_t*)&(name162_value);			
   Allnum[162].sub = name162_sub;
   Allnum[162].type = name162_type;
#endif


#if(All_Count >= 164)
   strcpy(Allnum[163].name, name163);
   Allnum[163].va = (uint16_t*)&(name163_value);			
   Allnum[163].sub = name163_sub;
   Allnum[163].type = name163_type;
#endif


#if(All_Count >= 165)
   strcpy(Allnum[164].name, name164);
   Allnum[164].va = (uint16_t*)&(name164_value);			
   Allnum[164].sub = name164_sub;
   Allnum[164].type = name164_type;
#endif


#if(All_Count >= 166)
   strcpy(Allnum[165].name, name165);
   Allnum[165].va = (uint16_t*)&(name165_value);			
   Allnum[165].sub = name165_sub;
   Allnum[165].type = name165_type;
#endif


#if(All_Count >= 167)
   strcpy(Allnum[166].name, name166);
   Allnum[166].va = (uint16_t*)&(name166_value);			
   Allnum[166].sub = name166_sub;
   Allnum[166].type = name166_type;
#endif


#if(All_Count >= 168)
   strcpy(Allnum[167].name, name167);
   Allnum[167].va = (uint16_t*)&(name167_value);			
   Allnum[167].sub = name167_sub;
   Allnum[167].type = name167_type;
#endif


#if(All_Count >= 169)
   strcpy(Allnum[168].name, name168);
   Allnum[168].va = (uint16_t*)&(name168_value);			
   Allnum[168].sub = name168_sub;
   Allnum[168].type = name168_type;
#endif


#if(All_Count >= 170)
   strcpy(Allnum[169].name, name169);
   Allnum[169].va = (uint16_t*)&(name169_value);			
   Allnum[169].sub = name169_sub;
   Allnum[169].type = name169_type;
#endif


#if(All_Count >= 171)
   strcpy(Allnum[170].name, name170);
   Allnum[170].va = (uint16_t*)&(name170_value);			
   Allnum[170].sub = name170_sub;
   Allnum[170].type = name170_type;
#endif


#if(All_Count >= 172)
   strcpy(Allnum[171].name, name171);
   Allnum[171].va = (uint16_t*)&(name171_value);			
   Allnum[171].sub = name171_sub;
   Allnum[171].type = name171_type;
#endif


#if(All_Count >= 173)
   strcpy(Allnum[172].name, name172);
   Allnum[172].va = (uint16_t*)&(name172_value);			
   Allnum[172].sub = name172_sub;
   Allnum[172].type = name172_type;
#endif


#if(All_Count >= 174)
   strcpy(Allnum[173].name, name173);
   Allnum[173].va = (uint16_t*)&(name173_value);			
   Allnum[173].sub = name173_sub;
   Allnum[173].type = name173_type;
#endif


#if(All_Count >= 175)
   strcpy(Allnum[174].name, name174);
   Allnum[174].va = (uint16_t*)&(name174_value);			
   Allnum[174].sub = name174_sub;
   Allnum[174].type = name174_type;
#endif


#if(All_Count >= 176)
   strcpy(Allnum[175].name, name175);
   Allnum[175].va = (uint16_t*)&(name175_value);			
   Allnum[175].sub = name175_sub;
   Allnum[175].type = name175_type;
#endif


#if(All_Count >= 177)
   strcpy(Allnum[176].name, name176);
   Allnum[176].va = (uint16_t*)&(name176_value);			
   Allnum[176].sub = name176_sub;
   Allnum[176].type = name176_type;
#endif


#if(All_Count >= 178)
   strcpy(Allnum[177].name, name177);
   Allnum[177].va = (uint16_t*)&(name177_value);			
   Allnum[177].sub = name177_sub;
   Allnum[177].type = name177_type;
#endif


#if(All_Count >= 179)
   strcpy(Allnum[178].name, name178);
   Allnum[178].va = (uint16_t*)&(name178_value);			
   Allnum[178].sub = name178_sub;
   Allnum[178].type = name178_type;
#endif


#if(All_Count >= 180)
   strcpy(Allnum[179].name, name179);
   Allnum[179].va = (uint16_t*)&(name179_value);			
   Allnum[179].sub = name179_sub;
   Allnum[179].type = name179_type;
#endif


#if(All_Count >= 181)
   strcpy(Allnum[180].name, name180);
   Allnum[180].va = (uint16_t*)&(name180_value);			
   Allnum[180].sub = name180_sub;
   Allnum[180].type = name180_type;
#endif


#if(All_Count >= 182)
   strcpy(Allnum[181].name, name181);
   Allnum[181].va = (uint16_t*)&(name181_value);			
   Allnum[181].sub = name181_sub;
   Allnum[181].type = name181_type;
#endif


#if(All_Count >= 183)
   strcpy(Allnum[182].name, name182);
   Allnum[182].va = (uint16_t*)&(name182_value);			
   Allnum[182].sub = name182_sub;
   Allnum[182].type = name182_type;
#endif


#if(All_Count >= 184)
   strcpy(Allnum[183].name, name183);
   Allnum[183].va = (uint16_t*)&(name183_value);			
   Allnum[183].sub = name183_sub;
   Allnum[183].type = name183_type;
#endif


#if(All_Count >= 185)
   strcpy(Allnum[184].name, name184);
   Allnum[184].va = (uint16_t*)&(name184_value);			
   Allnum[184].sub = name184_sub;
   Allnum[184].type = name184_type;
#endif


#if(All_Count >= 186)
   strcpy(Allnum[185].name, name185);
   Allnum[185].va = (uint16_t*)&(name185_value);			
   Allnum[185].sub = name185_sub;
   Allnum[185].type = name185_type;
#endif


#if(All_Count >= 187)
   strcpy(Allnum[186].name, name186);
   Allnum[186].va = (uint16_t*)&(name186_value);			
   Allnum[186].sub = name186_sub;
   Allnum[186].type = name186_type;
#endif


#if(All_Count >= 188)
   strcpy(Allnum[187].name, name187);
   Allnum[187].va = (uint16_t*)&(name187_value);			
   Allnum[187].sub = name187_sub;
   Allnum[187].type = name187_type;
#endif


#if(All_Count >= 189)
   strcpy(Allnum[188].name, name188);
   Allnum[188].va = (uint16_t*)&(name188_value);			
   Allnum[188].sub = name188_sub;
   Allnum[188].type = name188_type;
#endif


#if(All_Count >= 190)
   strcpy(Allnum[189].name, name189);
   Allnum[189].va = (uint16_t*)&(name189_value);			
   Allnum[189].sub = name189_sub;
   Allnum[189].type = name189_type;
#endif


#if(All_Count >= 191)
   strcpy(Allnum[190].name, name190);
   Allnum[190].va = (uint16_t*)&(name190_value);			
   Allnum[190].sub = name190_sub;
   Allnum[190].type = name190_type;
#endif


#if(All_Count >= 192)
   strcpy(Allnum[191].name, name191);
   Allnum[191].va = (uint16_t*)&(name191_value);			
   Allnum[191].sub = name191_sub;
   Allnum[191].type = name191_type;
#endif


#if(All_Count >= 193)
   strcpy(Allnum[192].name, name192);
   Allnum[192].va = (uint16_t*)&(name192_value);			
   Allnum[192].sub = name192_sub;
   Allnum[192].type = name192_type;
#endif


#if(All_Count >= 194)
   strcpy(Allnum[193].name, name193);
   Allnum[193].va = (uint16_t*)&(name193_value);			
   Allnum[193].sub = name193_sub;
   Allnum[193].type = name193_type;
#endif


#if(All_Count >= 195)
   strcpy(Allnum[194].name, name194);
   Allnum[194].va = (uint16_t*)&(name194_value);			
   Allnum[194].sub = name194_sub;
   Allnum[194].type = name194_type;
#endif


#if(All_Count >= 196)
   strcpy(Allnum[195].name, name195);
   Allnum[195].va = (uint16_t*)&(name195_value);			
   Allnum[195].sub = name195_sub;
   Allnum[195].type = name195_type;
#endif


#if(All_Count >= 197)
   strcpy(Allnum[196].name, name196);
   Allnum[196].va = (uint16_t*)&(name196_value);			
   Allnum[196].sub = name196_sub;
   Allnum[196].type = name196_type;
#endif


#if(All_Count >= 198)
   strcpy(Allnum[197].name, name197);
   Allnum[197].va = (uint16_t*)&(name197_value);			
   Allnum[197].sub = name197_sub;
   Allnum[197].type = name197_type;
#endif


#if(All_Count >= 199)
   strcpy(Allnum[198].name, name198);
   Allnum[198].va = (uint16_t*)&(name198_value);			
   Allnum[198].sub = name198_sub;
   Allnum[198].type = name198_type;
#endif


#if(All_Count >= 200)
   strcpy(Allnum[199].name, name199);
   Allnum[199].va = (uint16_t*)&(name199_value);			
   Allnum[199].sub = name199_sub;
   Allnum[199].type = name199_type;
#endif


#if(All_Count >= 201)
   strcpy(Allnum[200].name, name200);
   Allnum[200].va = (uint16_t*)&(name200_value);			
   Allnum[200].sub = name200_sub;
   Allnum[200].type = name200_type;
#endif


#if(All_Count >= 202)
   strcpy(Allnum[201].name, name201);
   Allnum[201].va = (uint16_t*)&(name201_value);			
   Allnum[201].sub = name201_sub;
   Allnum[201].type = name201_type;
#endif


#if(All_Count >= 203)
   strcpy(Allnum[202].name, name202);
   Allnum[202].va = (uint16_t*)&(name202_value);			
   Allnum[202].sub = name202_sub;
   Allnum[202].type = name202_type;
#endif


#if(All_Count >= 204)
   strcpy(Allnum[203].name, name203);
   Allnum[203].va = (uint16_t*)&(name203_value);			
   Allnum[203].sub = name203_sub;
   Allnum[203].type = name203_type;
#endif


#if(All_Count >= 205)
   strcpy(Allnum[204].name, name204);
   Allnum[204].va = (uint16_t*)&(name204_value);			
   Allnum[204].sub = name204_sub;
   Allnum[204].type = name204_type;
#endif


#if(All_Count >= 206)
   strcpy(Allnum[205].name, name205);
   Allnum[205].va = (uint16_t*)&(name205_value);			
   Allnum[205].sub = name205_sub;
   Allnum[205].type = name205_type;
#endif


#if(All_Count >= 207)
   strcpy(Allnum[206].name, name206);
   Allnum[206].va = (uint16_t*)&(name206_value);			
   Allnum[206].sub = name206_sub;
   Allnum[206].type = name206_type;
#endif


#if(All_Count >= 208)
   strcpy(Allnum[207].name, name207);
   Allnum[207].va = (uint16_t*)&(name207_value);			
   Allnum[207].sub = name207_sub;
   Allnum[207].type = name207_type;
#endif


#if(All_Count >= 209)
   strcpy(Allnum[208].name, name208);
   Allnum[208].va = (uint16_t*)&(name208_value);			
   Allnum[208].sub = name208_sub;
   Allnum[208].type = name208_type;
#endif


#if(All_Count >= 210)
   strcpy(Allnum[209].name, name209);
   Allnum[209].va = (uint16_t*)&(name209_value);			
   Allnum[209].sub = name209_sub;
   Allnum[209].type = name209_type;
#endif


#if(All_Count >= 211)
   strcpy(Allnum[210].name, name210);
   Allnum[210].va = (uint16_t*)&(name210_value);			
   Allnum[210].sub = name210_sub;
   Allnum[210].type = name210_type;
#endif


#if(All_Count >= 212)
   strcpy(Allnum[211].name, name211);
   Allnum[211].va = (uint16_t*)&(name211_value);			
   Allnum[211].sub = name211_sub;
   Allnum[211].type = name211_type;
#endif


#if(All_Count >= 213)
   strcpy(Allnum[212].name, name212);
   Allnum[212].va = (uint16_t*)&(name212_value);			
   Allnum[212].sub = name212_sub;
   Allnum[212].type = name212_type;
#endif


#if(All_Count >= 214)
   strcpy(Allnum[213].name, name213);
   Allnum[213].va = (uint16_t*)&(name213_value);			
   Allnum[213].sub = name213_sub;
   Allnum[213].type = name213_type;
#endif


#if(All_Count >= 215)
   strcpy(Allnum[214].name, name214);
   Allnum[214].va = (uint16_t*)&(name214_value);			
   Allnum[214].sub = name214_sub;
   Allnum[214].type = name214_type;
#endif


#if(All_Count >= 216)
   strcpy(Allnum[215].name, name215);
   Allnum[215].va = (uint16_t*)&(name215_value);			
   Allnum[215].sub = name215_sub;
   Allnum[215].type = name215_type;
#endif


#if(All_Count >= 217)
   strcpy(Allnum[216].name, name216);
   Allnum[216].va = (uint16_t*)&(name216_value);			
   Allnum[216].sub = name216_sub;
   Allnum[216].type = name216_type;
#endif


#if(All_Count >= 218)
   strcpy(Allnum[217].name, name217);
   Allnum[217].va = (uint16_t*)&(name217_value);			
   Allnum[217].sub = name217_sub;
   Allnum[217].type = name217_type;
#endif


#if(All_Count >= 219)
   strcpy(Allnum[218].name, name218);
   Allnum[218].va = (uint16_t*)&(name218_value);			
   Allnum[218].sub = name218_sub;
   Allnum[218].type = name218_type;
#endif


#if(All_Count >= 220)
   strcpy(Allnum[219].name, name219);
   Allnum[219].va = (uint16_t*)&(name219_value);			
   Allnum[219].sub = name219_sub;
   Allnum[219].type = name219_type;
#endif


#if(All_Count >= 221)
   strcpy(Allnum[220].name, name220);
   Allnum[220].va = (uint16_t*)&(name220_value);			
   Allnum[220].sub = name220_sub;
   Allnum[220].type = name220_type;
#endif


#if(All_Count >= 222)
   strcpy(Allnum[221].name, name221);
   Allnum[221].va = (uint16_t*)&(name221_value);			
   Allnum[221].sub = name221_sub;
   Allnum[221].type = name221_type;
#endif


#if(All_Count >= 223)
   strcpy(Allnum[222].name, name222);
   Allnum[222].va = (uint16_t*)&(name222_value);			
   Allnum[222].sub = name222_sub;
   Allnum[222].type = name222_type;
#endif


#if(All_Count >= 224)
   strcpy(Allnum[223].name, name223);
   Allnum[223].va = (uint16_t*)&(name223_value);			
   Allnum[223].sub = name223_sub;
   Allnum[223].type = name223_type;
#endif


#if(All_Count >= 225)
   strcpy(Allnum[224].name, name224);
   Allnum[224].va = (uint16_t*)&(name224_value);			
   Allnum[224].sub = name224_sub;
   Allnum[224].type = name224_type;
#endif


#if(All_Count >= 226)
   strcpy(Allnum[225].name, name225);
   Allnum[225].va = (uint16_t*)&(name225_value);			
   Allnum[225].sub = name225_sub;
   Allnum[225].type = name225_type;
#endif


#if(All_Count >= 227)
   strcpy(Allnum[226].name, name226);
   Allnum[226].va = (uint16_t*)&(name226_value);			
   Allnum[226].sub = name226_sub;
   Allnum[226].type = name226_type;
#endif


#if(All_Count >= 228)
   strcpy(Allnum[227].name, name227);
   Allnum[227].va = (uint16_t*)&(name227_value);			
   Allnum[227].sub = name227_sub;
   Allnum[227].type = name227_type;
#endif


#if(All_Count >= 229)
   strcpy(Allnum[228].name, name228);
   Allnum[228].va = (uint16_t*)&(name228_value);			
   Allnum[228].sub = name228_sub;
   Allnum[228].type = name228_type;
#endif


#if(All_Count >= 230)
   strcpy(Allnum[229].name, name229);
   Allnum[229].va = (uint16_t*)&(name229_value);			
   Allnum[229].sub = name229_sub;
   Allnum[229].type = name229_type;
#endif


#if(All_Count >= 231)
   strcpy(Allnum[230].name, name230);
   Allnum[230].va = (uint16_t*)&(name230_value);			
   Allnum[230].sub = name230_sub;
   Allnum[230].type = name230_type;
#endif


#if(All_Count >= 232)
   strcpy(Allnum[231].name, name231);
   Allnum[231].va = (uint16_t*)&(name231_value);			
   Allnum[231].sub = name231_sub;
   Allnum[231].type = name231_type;
#endif


#if(All_Count >= 233)
   strcpy(Allnum[232].name, name232);
   Allnum[232].va = (uint16_t*)&(name232_value);			
   Allnum[232].sub = name232_sub;
   Allnum[232].type = name232_type;
#endif


#if(All_Count >= 234)
   strcpy(Allnum[233].name, name233);
   Allnum[233].va = (uint16_t*)&(name233_value);			
   Allnum[233].sub = name233_sub;
   Allnum[233].type = name233_type;
#endif


#if(All_Count >= 235)
   strcpy(Allnum[234].name, name234);
   Allnum[234].va = (uint16_t*)&(name234_value);			
   Allnum[234].sub = name234_sub;
   Allnum[234].type = name234_type;
#endif


#if(All_Count >= 236)
   strcpy(Allnum[235].name, name235);
   Allnum[235].va = (uint16_t*)&(name235_value);			
   Allnum[235].sub = name235_sub;
   Allnum[235].type = name235_type;
#endif


#if(All_Count >= 237)
   strcpy(Allnum[236].name, name236);
   Allnum[236].va = (uint16_t*)&(name236_value);			
   Allnum[236].sub = name236_sub;
   Allnum[236].type = name236_type;
#endif


#if(All_Count >= 238)
   strcpy(Allnum[237].name, name237);
   Allnum[237].va = (uint16_t*)&(name237_value);			
   Allnum[237].sub = name237_sub;
   Allnum[237].type = name237_type;
#endif


#if(All_Count >= 239)
   strcpy(Allnum[238].name, name238);
   Allnum[238].va = (uint16_t*)&(name238_value);			
   Allnum[238].sub = name238_sub;
   Allnum[238].type = name238_type;
#endif


#if(All_Count >= 240)
   strcpy(Allnum[239].name, name239);
   Allnum[239].va = (uint16_t*)&(name239_value);			
   Allnum[239].sub = name239_sub;
   Allnum[239].type = name239_type;
#endif


#if(All_Count >= 241)
   strcpy(Allnum[240].name, name240);
   Allnum[240].va = (uint16_t*)&(name240_value);			
   Allnum[240].sub = name240_sub;
   Allnum[240].type = name240_type;
#endif


#if(All_Count >= 242)
   strcpy(Allnum[241].name, name241);
   Allnum[241].va = (uint16_t*)&(name241_value);			
   Allnum[241].sub = name241_sub;
   Allnum[241].type = name241_type;
#endif


#if(All_Count >= 243)
   strcpy(Allnum[242].name, name242);
   Allnum[242].va = (uint16_t*)&(name242_value);			
   Allnum[242].sub = name242_sub;
   Allnum[242].type = name242_type;
#endif


#if(All_Count >= 244)
   strcpy(Allnum[243].name, name243);
   Allnum[243].va = (uint16_t*)&(name243_value);			
   Allnum[243].sub = name243_sub;
   Allnum[243].type = name243_type;
#endif


#if(All_Count >= 245)
   strcpy(Allnum[244].name, name244);
   Allnum[244].va = (uint16_t*)&(name244_value);			
   Allnum[244].sub = name244_sub;
   Allnum[244].type = name244_type;
#endif


#if(All_Count >= 246)
   strcpy(Allnum[245].name, name245);
   Allnum[245].va = (uint16_t*)&(name245_value);			
   Allnum[245].sub = name245_sub;
   Allnum[245].type = name245_type;
#endif


#if(All_Count >= 247)
   strcpy(Allnum[246].name, name246);
   Allnum[246].va = (uint16_t*)&(name246_value);			
   Allnum[246].sub = name246_sub;
   Allnum[246].type = name246_type;
#endif


#if(All_Count >= 248)
   strcpy(Allnum[247].name, name247);
   Allnum[247].va = (uint16_t*)&(name247_value);			
   Allnum[247].sub = name247_sub;
   Allnum[247].type = name247_type;
#endif


#if(All_Count >= 249)
   strcpy(Allnum[248].name, name248);
   Allnum[248].va = (uint16_t*)&(name248_value);			
   Allnum[248].sub = name248_sub;
   Allnum[248].type = name248_type;
#endif


#if(All_Count >= 250)
   strcpy(Allnum[249].name, name249);
   Allnum[249].va = (uint16_t*)&(name249_value);			
   Allnum[249].sub = name249_sub;
   Allnum[249].type = name249_type;
#endif


#if(All_Count >= 251)
   strcpy(Allnum[250].name, name250);
   Allnum[250].va = (uint16_t*)&(name250_value);			
   Allnum[250].sub = name250_sub;
   Allnum[250].type = name250_type;
#endif


#if(All_Count >= 252)
   strcpy(Allnum[251].name, name251);
   Allnum[251].va = (uint16_t*)&(name251_value);			
   Allnum[251].sub = name251_sub;
   Allnum[251].type = name251_type;
#endif


#if(All_Count >= 253)
   strcpy(Allnum[252].name, name252);
   Allnum[252].va = (uint16_t*)&(name252_value);			
   Allnum[252].sub = name252_sub;
   Allnum[252].type = name252_type;
#endif


#if(All_Count >= 254)
   strcpy(Allnum[253].name, name253);
   Allnum[253].va = (uint16_t*)&(name253_value);			
   Allnum[253].sub = name253_sub;
   Allnum[253].type = name253_type;
#endif


#if(All_Count >= 255)
   strcpy(Allnum[254].name, name254);
   Allnum[254].va = (uint16_t*)&(name254_value);			
   Allnum[254].sub = name254_sub;
   Allnum[254].type = name254_type;
#endif


#if(All_Count >= 256)
   strcpy(Allnum[255].name, name255);
   Allnum[255].va = (uint16_t*)&(name255_value);			
   Allnum[255].sub = name255_sub;
   Allnum[255].type = name255_type;
#endif


#if(All_Count >= 257)
   strcpy(Allnum[256].name, name256);
   Allnum[256].va = (uint16_t*)&(name256_value);			
   Allnum[256].sub = name256_sub;
   Allnum[256].type = name256_type;
#endif


#if(All_Count >= 258)
   strcpy(Allnum[257].name, name257);
   Allnum[257].va = (uint16_t*)&(name257_value);			
   Allnum[257].sub = name257_sub;
   Allnum[257].type = name257_type;
#endif


#if(All_Count >= 259)
   strcpy(Allnum[258].name, name258);
   Allnum[258].va = (uint16_t*)&(name258_value);			
   Allnum[258].sub = name258_sub;
   Allnum[258].type = name258_type;
#endif


#if(All_Count >= 260)
   strcpy(Allnum[259].name, name259);
   Allnum[259].va = (uint16_t*)&(name259_value);			
   Allnum[259].sub = name259_sub;
   Allnum[259].type = name259_type;
#endif


#if(All_Count >= 261)
   strcpy(Allnum[260].name, name260);
   Allnum[260].va = (uint16_t*)&(name260_value);			
   Allnum[260].sub = name260_sub;
   Allnum[260].type = name260_type;
#endif


#if(All_Count >= 262)
   strcpy(Allnum[261].name, name261);
   Allnum[261].va = (uint16_t*)&(name261_value);			
   Allnum[261].sub = name261_sub;
   Allnum[261].type = name261_type;
#endif


#if(All_Count >= 263)
   strcpy(Allnum[262].name, name262);
   Allnum[262].va = (uint16_t*)&(name262_value);			
   Allnum[262].sub = name262_sub;
   Allnum[262].type = name262_type;
#endif


#if(All_Count >= 264)
   strcpy(Allnum[263].name, name263);
   Allnum[263].va = (uint16_t*)&(name263_value);			
   Allnum[263].sub = name263_sub;
   Allnum[263].type = name263_type;
#endif


#if(All_Count >= 265)
   strcpy(Allnum[264].name, name264);
   Allnum[264].va = (uint16_t*)&(name264_value);			
   Allnum[264].sub = name264_sub;
   Allnum[264].type = name264_type;
#endif


#if(All_Count >= 266)
   strcpy(Allnum[265].name, name265);
   Allnum[265].va = (uint16_t*)&(name265_value);			
   Allnum[265].sub = name265_sub;
   Allnum[265].type = name265_type;
#endif


#if(All_Count >= 267)
   strcpy(Allnum[266].name, name266);
   Allnum[266].va = (uint16_t*)&(name266_value);			
   Allnum[266].sub = name266_sub;
   Allnum[266].type = name266_type;
#endif


#if(All_Count >= 268)
   strcpy(Allnum[267].name, name267);
   Allnum[267].va = (uint16_t*)&(name267_value);			
   Allnum[267].sub = name267_sub;
   Allnum[267].type = name267_type;
#endif


#if(All_Count >= 269)
   strcpy(Allnum[268].name, name268);
   Allnum[268].va = (uint16_t*)&(name268_value);			
   Allnum[268].sub = name268_sub;
   Allnum[268].type = name268_type;
#endif


#if(All_Count >= 270)
   strcpy(Allnum[269].name, name269);
   Allnum[269].va = (uint16_t*)&(name269_value);			
   Allnum[269].sub = name269_sub;
   Allnum[269].type = name269_type;
#endif


#if(All_Count >= 271)
   strcpy(Allnum[270].name, name270);
   Allnum[270].va = (uint16_t*)&(name270_value);			
   Allnum[270].sub = name270_sub;
   Allnum[270].type = name270_type;
#endif


#if(All_Count >= 272)
   strcpy(Allnum[271].name, name271);
   Allnum[271].va = (uint16_t*)&(name271_value);			
   Allnum[271].sub = name271_sub;
   Allnum[271].type = name271_type;
#endif


#if(All_Count >= 273)
   strcpy(Allnum[272].name, name272);
   Allnum[272].va = (uint16_t*)&(name272_value);			
   Allnum[272].sub = name272_sub;
   Allnum[272].type = name272_type;
#endif


#if(All_Count >= 274)
   strcpy(Allnum[273].name, name273);
   Allnum[273].va = (uint16_t*)&(name273_value);			
   Allnum[273].sub = name273_sub;
   Allnum[273].type = name273_type;
#endif


#if(All_Count >= 275)
   strcpy(Allnum[274].name, name274);
   Allnum[274].va = (uint16_t*)&(name274_value);			
   Allnum[274].sub = name274_sub;
   Allnum[274].type = name274_type;
#endif


#if(All_Count >= 276)
   strcpy(Allnum[275].name, name275);
   Allnum[275].va = (uint16_t*)&(name275_value);			
   Allnum[275].sub = name275_sub;
   Allnum[275].type = name275_type;
#endif


#if(All_Count >= 277)
   strcpy(Allnum[276].name, name276);
   Allnum[276].va = (uint16_t*)&(name276_value);			
   Allnum[276].sub = name276_sub;
   Allnum[276].type = name276_type;
#endif


#if(All_Count >= 278)
   strcpy(Allnum[277].name, name277);
   Allnum[277].va = (uint16_t*)&(name277_value);			
   Allnum[277].sub = name277_sub;
   Allnum[277].type = name277_type;
#endif


#if(All_Count >= 279)
   strcpy(Allnum[278].name, name278);
   Allnum[278].va = (uint16_t*)&(name278_value);			
   Allnum[278].sub = name278_sub;
   Allnum[278].type = name278_type;
#endif


#if(All_Count >= 280)
   strcpy(Allnum[279].name, name279);
   Allnum[279].va = (uint16_t*)&(name279_value);			
   Allnum[279].sub = name279_sub;
   Allnum[279].type = name279_type;
#endif


#if(All_Count >= 281)
   strcpy(Allnum[280].name, name280);
   Allnum[280].va = (uint16_t*)&(name280_value);			
   Allnum[280].sub = name280_sub;
   Allnum[280].type = name280_type;
#endif


#if(All_Count >= 282)
   strcpy(Allnum[281].name, name281);
   Allnum[281].va = (uint16_t*)&(name281_value);			
   Allnum[281].sub = name281_sub;
   Allnum[281].type = name281_type;
#endif


#if(All_Count >= 283)
   strcpy(Allnum[282].name, name282);
   Allnum[282].va = (uint16_t*)&(name282_value);			
   Allnum[282].sub = name282_sub;
   Allnum[282].type = name282_type;
#endif


#if(All_Count >= 284)
   strcpy(Allnum[283].name, name283);
   Allnum[283].va = (uint16_t*)&(name283_value);			
   Allnum[283].sub = name283_sub;
   Allnum[283].type = name283_type;
#endif


#if(All_Count >= 285)
   strcpy(Allnum[284].name, name284);
   Allnum[284].va = (uint16_t*)&(name284_value);			
   Allnum[284].sub = name284_sub;
   Allnum[284].type = name284_type;
#endif


#if(All_Count >= 286)
   strcpy(Allnum[285].name, name285);
   Allnum[285].va = (uint16_t*)&(name285_value);			
   Allnum[285].sub = name285_sub;
   Allnum[285].type = name285_type;
#endif


#if(All_Count >= 287)
   strcpy(Allnum[286].name, name286);
   Allnum[286].va = (uint16_t*)&(name286_value);			
   Allnum[286].sub = name286_sub;
   Allnum[286].type = name286_type;
#endif


#if(All_Count >= 288)
   strcpy(Allnum[287].name, name287);
   Allnum[287].va = (uint16_t*)&(name287_value);			
   Allnum[287].sub = name287_sub;
   Allnum[287].type = name287_type;
#endif


#if(All_Count >= 289)
   strcpy(Allnum[288].name, name288);
   Allnum[288].va = (uint16_t*)&(name288_value);			
   Allnum[288].sub = name288_sub;
   Allnum[288].type = name288_type;
#endif


#if(All_Count >= 290)
   strcpy(Allnum[289].name, name289);
   Allnum[289].va = (uint16_t*)&(name289_value);			
   Allnum[289].sub = name289_sub;
   Allnum[289].type = name289_type;
#endif


#if(All_Count >= 291)
   strcpy(Allnum[290].name, name290);
   Allnum[290].va = (uint16_t*)&(name290_value);			
   Allnum[290].sub = name290_sub;
   Allnum[290].type = name290_type;
#endif


#if(All_Count >= 292)
   strcpy(Allnum[291].name, name291);
   Allnum[291].va = (uint16_t*)&(name291_value);			
   Allnum[291].sub = name291_sub;
   Allnum[291].type = name291_type;
#endif


#if(All_Count >= 293)
   strcpy(Allnum[292].name, name292);
   Allnum[292].va = (uint16_t*)&(name292_value);			
   Allnum[292].sub = name292_sub;
   Allnum[292].type = name292_type;
#endif


#if(All_Count >= 294)
   strcpy(Allnum[293].name, name293);
   Allnum[293].va = (uint16_t*)&(name293_value);			
   Allnum[293].sub = name293_sub;
   Allnum[293].type = name293_type;
#endif


#if(All_Count >= 295)
   strcpy(Allnum[294].name, name294);
   Allnum[294].va = (uint16_t*)&(name294_value);			
   Allnum[294].sub = name294_sub;
   Allnum[294].type = name294_type;
#endif


#if(All_Count >= 296)
   strcpy(Allnum[295].name, name295);
   Allnum[295].va = (uint16_t*)&(name295_value);			
   Allnum[295].sub = name295_sub;
   Allnum[295].type = name295_type;
#endif


#if(All_Count >= 297)
   strcpy(Allnum[296].name, name296);
   Allnum[296].va = (uint16_t*)&(name296_value);			
   Allnum[296].sub = name296_sub;
   Allnum[296].type = name296_type;
#endif


#if(All_Count >= 298)
   strcpy(Allnum[297].name, name297);
   Allnum[297].va = (uint16_t*)&(name297_value);			
   Allnum[297].sub = name297_sub;
   Allnum[297].type = name297_type;
#endif


#if(All_Count >= 299)
   strcpy(Allnum[298].name, name298);
   Allnum[298].va = (uint16_t*)&(name298_value);			
   Allnum[298].sub = name298_sub;
   Allnum[298].type = name298_type;
#endif


#if(All_Count >= 300)
   strcpy(Allnum[299].name, name299);
   Allnum[299].va = (uint16_t*)&(name299_value);			
   Allnum[299].sub = name299_sub;
   Allnum[299].type = name299_type;
#endif


#if(All_Count >= 301)
   strcpy(Allnum[300].name, name300);
   Allnum[300].va = (uint16_t*)&(name300_value);			
   Allnum[300].sub = name300_sub;
   Allnum[300].type = name300_type;
#endif


#if(All_Count >= 302)
   strcpy(Allnum[301].name, name301);
   Allnum[301].va = (uint16_t*)&(name301_value);			
   Allnum[301].sub = name301_sub;
   Allnum[301].type = name301_type;
#endif


#if(All_Count >= 303)
   strcpy(Allnum[302].name, name302);
   Allnum[302].va = (uint16_t*)&(name302_value);			
   Allnum[302].sub = name302_sub;
   Allnum[302].type = name302_type;
#endif


#if(All_Count >= 304)
   strcpy(Allnum[303].name, name303);
   Allnum[303].va = (uint16_t*)&(name303_value);			
   Allnum[303].sub = name303_sub;
   Allnum[303].type = name303_type;
#endif


#if(All_Count >= 305)
   strcpy(Allnum[304].name, name304);
   Allnum[304].va = (uint16_t*)&(name304_value);			
   Allnum[304].sub = name304_sub;
   Allnum[304].type = name304_type;
#endif


#if(All_Count >= 306)
   strcpy(Allnum[305].name, name305);
   Allnum[305].va = (uint16_t*)&(name305_value);			
   Allnum[305].sub = name305_sub;
   Allnum[305].type = name305_type;
#endif


#if(All_Count >= 307)
   strcpy(Allnum[306].name, name306);
   Allnum[306].va = (uint16_t*)&(name306_value);			
   Allnum[306].sub = name306_sub;
   Allnum[306].type = name306_type;
#endif


#if(All_Count >= 308)
   strcpy(Allnum[307].name, name307);
   Allnum[307].va = (uint16_t*)&(name307_value);			
   Allnum[307].sub = name307_sub;
   Allnum[307].type = name307_type;
#endif


#if(All_Count >= 309)
   strcpy(Allnum[308].name, name308);
   Allnum[308].va = (uint16_t*)&(name308_value);			
   Allnum[308].sub = name308_sub;
   Allnum[308].type = name308_type;
#endif


#if(All_Count >= 310)
   strcpy(Allnum[309].name, name309);
   Allnum[309].va = (uint16_t*)&(name309_value);			
   Allnum[309].sub = name309_sub;
   Allnum[309].type = name309_type;
#endif


#if(All_Count >= 311)
   strcpy(Allnum[310].name, name310);
   Allnum[310].va = (uint16_t*)&(name310_value);			
   Allnum[310].sub = name310_sub;
   Allnum[310].type = name310_type;
#endif


#if(All_Count >= 312)
   strcpy(Allnum[311].name, name311);
   Allnum[311].va = (uint16_t*)&(name311_value);			
   Allnum[311].sub = name311_sub;
   Allnum[311].type = name311_type;
#endif


#if(All_Count >= 313)
   strcpy(Allnum[312].name, name312);
   Allnum[312].va = (uint16_t*)&(name312_value);			
   Allnum[312].sub = name312_sub;
   Allnum[312].type = name312_type;
#endif


#if(All_Count >= 314)
   strcpy(Allnum[313].name, name313);
   Allnum[313].va = (uint16_t*)&(name313_value);			
   Allnum[313].sub = name313_sub;
   Allnum[313].type = name313_type;
#endif


#if(All_Count >= 315)
   strcpy(Allnum[314].name, name314);
   Allnum[314].va = (uint16_t*)&(name314_value);			
   Allnum[314].sub = name314_sub;
   Allnum[314].type = name314_type;
#endif


#if(All_Count >= 316)
   strcpy(Allnum[315].name, name315);
   Allnum[315].va = (uint16_t*)&(name315_value);			
   Allnum[315].sub = name315_sub;
   Allnum[315].type = name315_type;
#endif


#if(All_Count >= 317)
   strcpy(Allnum[316].name, name316);
   Allnum[316].va = (uint16_t*)&(name316_value);			
   Allnum[316].sub = name316_sub;
   Allnum[316].type = name316_type;
#endif


#if(All_Count >= 318)
   strcpy(Allnum[317].name, name317);
   Allnum[317].va = (uint16_t*)&(name317_value);			
   Allnum[317].sub = name317_sub;
   Allnum[317].type = name317_type;
#endif


#if(All_Count >= 319)
   strcpy(Allnum[318].name, name318);
   Allnum[318].va = (uint16_t*)&(name318_value);			
   Allnum[318].sub = name318_sub;
   Allnum[318].type = name318_type;
#endif


#if(All_Count >= 320)
   strcpy(Allnum[319].name, name319);
   Allnum[319].va = (uint16_t*)&(name319_value);			
   Allnum[319].sub = name319_sub;
   Allnum[319].type = name319_type;
#endif


#if(All_Count >= 321)
   strcpy(Allnum[320].name, name320);
   Allnum[320].va = (uint16_t*)&(name320_value);			
   Allnum[320].sub = name320_sub;
   Allnum[320].type = name320_type;
#endif


#if(All_Count >= 322)
   strcpy(Allnum[321].name, name321);
   Allnum[321].va = (uint16_t*)&(name321_value);			
   Allnum[321].sub = name321_sub;
   Allnum[321].type = name321_type;
#endif


#if(All_Count >= 323)
   strcpy(Allnum[322].name, name322);
   Allnum[322].va = (uint16_t*)&(name322_value);			
   Allnum[322].sub = name322_sub;
   Allnum[322].type = name322_type;
#endif


#if(All_Count >= 324)
   strcpy(Allnum[323].name, name323);
   Allnum[323].va = (uint16_t*)&(name323_value);			
   Allnum[323].sub = name323_sub;
   Allnum[323].type = name323_type;
#endif


#if(All_Count >= 325)
   strcpy(Allnum[324].name, name324);
   Allnum[324].va = (uint16_t*)&(name324_value);			
   Allnum[324].sub = name324_sub;
   Allnum[324].type = name324_type;
#endif


#if(All_Count >= 326)
   strcpy(Allnum[325].name, name325);
   Allnum[325].va = (uint16_t*)&(name325_value);			
   Allnum[325].sub = name325_sub;
   Allnum[325].type = name325_type;
#endif


#if(All_Count >= 327)
   strcpy(Allnum[326].name, name326);
   Allnum[326].va = (uint16_t*)&(name326_value);			
   Allnum[326].sub = name326_sub;
   Allnum[326].type = name326_type;
#endif


#if(All_Count >= 328)
   strcpy(Allnum[327].name, name327);
   Allnum[327].va = (uint16_t*)&(name327_value);			
   Allnum[327].sub = name327_sub;
   Allnum[327].type = name327_type;
#endif


#if(All_Count >= 329)
   strcpy(Allnum[328].name, name328);
   Allnum[328].va = (uint16_t*)&(name328_value);			
   Allnum[328].sub = name328_sub;
   Allnum[328].type = name328_type;
#endif


#if(All_Count >= 330)
   strcpy(Allnum[329].name, name329);
   Allnum[329].va = (uint16_t*)&(name329_value);			
   Allnum[329].sub = name329_sub;
   Allnum[329].type = name329_type;
#endif


#if(All_Count >= 331)
   strcpy(Allnum[330].name, name330);
   Allnum[330].va = (uint16_t*)&(name330_value);			
   Allnum[330].sub = name330_sub;
   Allnum[330].type = name330_type;
#endif


#if(All_Count >= 332)
   strcpy(Allnum[331].name, name331);
   Allnum[331].va = (uint16_t*)&(name331_value);			
   Allnum[331].sub = name331_sub;
   Allnum[331].type = name331_type;
#endif


#if(All_Count >= 333)
   strcpy(Allnum[332].name, name332);
   Allnum[332].va = (uint16_t*)&(name332_value);			
   Allnum[332].sub = name332_sub;
   Allnum[332].type = name332_type;
#endif


#if(All_Count >= 334)
   strcpy(Allnum[333].name, name333);
   Allnum[333].va = (uint16_t*)&(name333_value);			
   Allnum[333].sub = name333_sub;
   Allnum[333].type = name333_type;
#endif


#if(All_Count >= 335)
   strcpy(Allnum[334].name, name334);
   Allnum[334].va = (uint16_t*)&(name334_value);			
   Allnum[334].sub = name334_sub;
   Allnum[334].type = name334_type;
#endif


#if(All_Count >= 336)
   strcpy(Allnum[335].name, name335);
   Allnum[335].va = (uint16_t*)&(name335_value);			
   Allnum[335].sub = name335_sub;
   Allnum[335].type = name335_type;
#endif


#if(All_Count >= 337)
   strcpy(Allnum[336].name, name336);
   Allnum[336].va = (uint16_t*)&(name336_value);			
   Allnum[336].sub = name336_sub;
   Allnum[336].type = name336_type;
#endif


#if(All_Count >= 338)
   strcpy(Allnum[337].name, name337);
   Allnum[337].va = (uint16_t*)&(name337_value);			
   Allnum[337].sub = name337_sub;
   Allnum[337].type = name337_type;
#endif


#if(All_Count >= 339)
   strcpy(Allnum[338].name, name338);
   Allnum[338].va = (uint16_t*)&(name338_value);			
   Allnum[338].sub = name338_sub;
   Allnum[338].type = name338_type;
#endif


#if(All_Count >= 340)
   strcpy(Allnum[339].name, name339);
   Allnum[339].va = (uint16_t*)&(name339_value);			
   Allnum[339].sub = name339_sub;
   Allnum[339].type = name339_type;
#endif


#if(All_Count >= 341)
   strcpy(Allnum[340].name, name340);
   Allnum[340].va = (uint16_t*)&(name340_value);			
   Allnum[340].sub = name340_sub;
   Allnum[340].type = name340_type;
#endif


#if(All_Count >= 342)
   strcpy(Allnum[341].name, name341);
   Allnum[341].va = (uint16_t*)&(name341_value);			
   Allnum[341].sub = name341_sub;
   Allnum[341].type = name341_type;
#endif


#if(All_Count >= 343)
   strcpy(Allnum[342].name, name342);
   Allnum[342].va = (uint16_t*)&(name342_value);			
   Allnum[342].sub = name342_sub;
   Allnum[342].type = name342_type;
#endif


#if(All_Count >= 344)
   strcpy(Allnum[343].name, name343);
   Allnum[343].va = (uint16_t*)&(name343_value);			
   Allnum[343].sub = name343_sub;
   Allnum[343].type = name343_type;
#endif


#if(All_Count >= 345)
   strcpy(Allnum[344].name, name344);
   Allnum[344].va = (uint16_t*)&(name344_value);			
   Allnum[344].sub = name344_sub;
   Allnum[344].type = name344_type;
#endif


#if(All_Count >= 346)
   strcpy(Allnum[345].name, name345);
   Allnum[345].va = (uint16_t*)&(name345_value);			
   Allnum[345].sub = name345_sub;
   Allnum[345].type = name345_type;
#endif


#if(All_Count >= 347)
   strcpy(Allnum[346].name, name346);
   Allnum[346].va = (uint16_t*)&(name346_value);			
   Allnum[346].sub = name346_sub;
   Allnum[346].type = name346_type;
#endif


#if(All_Count >= 348)
   strcpy(Allnum[347].name, name347);
   Allnum[347].va = (uint16_t*)&(name347_value);			
   Allnum[347].sub = name347_sub;
   Allnum[347].type = name347_type;
#endif


#if(All_Count >= 349)
   strcpy(Allnum[348].name, name348);
   Allnum[348].va = (uint16_t*)&(name348_value);			
   Allnum[348].sub = name348_sub;
   Allnum[348].type = name348_type;
#endif


#if(All_Count >= 350)
   strcpy(Allnum[349].name, name349);
   Allnum[349].va = (uint16_t*)&(name349_value);			
   Allnum[349].sub = name349_sub;
   Allnum[349].type = name349_type;
#endif


#if(All_Count >= 351)
   strcpy(Allnum[350].name, name350);
   Allnum[350].va = (uint16_t*)&(name350_value);			
   Allnum[350].sub = name350_sub;
   Allnum[350].type = name350_type;
#endif


#if(All_Count >= 352)
   strcpy(Allnum[351].name, name351);
   Allnum[351].va = (uint16_t*)&(name351_value);			
   Allnum[351].sub = name351_sub;
   Allnum[351].type = name351_type;
#endif


#if(All_Count >= 353)
   strcpy(Allnum[352].name, name352);
   Allnum[352].va = (uint16_t*)&(name352_value);			
   Allnum[352].sub = name352_sub;
   Allnum[352].type = name352_type;
#endif


#if(All_Count >= 354)
   strcpy(Allnum[353].name, name353);
   Allnum[353].va = (uint16_t*)&(name353_value);			
   Allnum[353].sub = name353_sub;
   Allnum[353].type = name353_type;
#endif


#if(All_Count >= 355)
   strcpy(Allnum[354].name, name354);
   Allnum[354].va = (uint16_t*)&(name354_value);			
   Allnum[354].sub = name354_sub;
   Allnum[354].type = name354_type;
#endif


#if(All_Count >= 356)
   strcpy(Allnum[355].name, name355);
   Allnum[355].va = (uint16_t*)&(name355_value);			
   Allnum[355].sub = name355_sub;
   Allnum[355].type = name355_type;
#endif


#if(All_Count >= 357)
   strcpy(Allnum[356].name, name356);
   Allnum[356].va = (uint16_t*)&(name356_value);			
   Allnum[356].sub = name356_sub;
   Allnum[356].type = name356_type;
#endif


#if(All_Count >= 358)
   strcpy(Allnum[357].name, name357);
   Allnum[357].va = (uint16_t*)&(name357_value);			
   Allnum[357].sub = name357_sub;
   Allnum[357].type = name357_type;
#endif


#if(All_Count >= 359)
   strcpy(Allnum[358].name, name358);
   Allnum[358].va = (uint16_t*)&(name358_value);			
   Allnum[358].sub = name358_sub;
   Allnum[358].type = name358_type;
#endif


#if(All_Count >= 360)
   strcpy(Allnum[359].name, name359);
   Allnum[359].va = (uint16_t*)&(name359_value);			
   Allnum[359].sub = name359_sub;
   Allnum[359].type = name359_type;
#endif


#if(All_Count >= 361)
   strcpy(Allnum[360].name, name360);
   Allnum[360].va = (uint16_t*)&(name360_value);			
   Allnum[360].sub = name360_sub;
   Allnum[360].type = name360_type;
#endif


#if(All_Count >= 362)
   strcpy(Allnum[361].name, name361);
   Allnum[361].va = (uint16_t*)&(name361_value);			
   Allnum[361].sub = name361_sub;
   Allnum[361].type = name361_type;
#endif


#if(All_Count >= 363)
   strcpy(Allnum[362].name, name362);
   Allnum[362].va = (uint16_t*)&(name362_value);			
   Allnum[362].sub = name362_sub;
   Allnum[362].type = name362_type;
#endif


#if(All_Count >= 364)
   strcpy(Allnum[363].name, name363);
   Allnum[363].va = (uint16_t*)&(name363_value);			
   Allnum[363].sub = name363_sub;
   Allnum[363].type = name363_type;
#endif


#if(All_Count >= 365)
   strcpy(Allnum[364].name, name364);
   Allnum[364].va = (uint16_t*)&(name364_value);			
   Allnum[364].sub = name364_sub;
   Allnum[364].type = name364_type;
#endif


#if(All_Count >= 366)
   strcpy(Allnum[365].name, name365);
   Allnum[365].va = (uint16_t*)&(name365_value);			
   Allnum[365].sub = name365_sub;
   Allnum[365].type = name365_type;
#endif


#if(All_Count >= 367)
   strcpy(Allnum[366].name, name366);
   Allnum[366].va = (uint16_t*)&(name366_value);			
   Allnum[366].sub = name366_sub;
   Allnum[366].type = name366_type;
#endif


#if(All_Count >= 368)
   strcpy(Allnum[367].name, name367);
   Allnum[367].va = (uint16_t*)&(name367_value);			
   Allnum[367].sub = name367_sub;
   Allnum[367].type = name367_type;
#endif


#if(All_Count >= 369)
   strcpy(Allnum[368].name, name368);
   Allnum[368].va = (uint16_t*)&(name368_value);			
   Allnum[368].sub = name368_sub;
   Allnum[368].type = name368_type;
#endif


#if(All_Count >= 370)
   strcpy(Allnum[369].name, name369);
   Allnum[369].va = (uint16_t*)&(name369_value);			
   Allnum[369].sub = name369_sub;
   Allnum[369].type = name369_type;
#endif


#if(All_Count >= 371)
   strcpy(Allnum[370].name, name370);
   Allnum[370].va = (uint16_t*)&(name370_value);			
   Allnum[370].sub = name370_sub;
   Allnum[370].type = name370_type;
#endif


#if(All_Count >= 372)
   strcpy(Allnum[371].name, name371);
   Allnum[371].va = (uint16_t*)&(name371_value);			
   Allnum[371].sub = name371_sub;
   Allnum[371].type = name371_type;
#endif


#if(All_Count >= 373)
   strcpy(Allnum[372].name, name372);
   Allnum[372].va = (uint16_t*)&(name372_value);			
   Allnum[372].sub = name372_sub;
   Allnum[372].type = name372_type;
#endif


#if(All_Count >= 374)
   strcpy(Allnum[373].name, name373);
   Allnum[373].va = (uint16_t*)&(name373_value);			
   Allnum[373].sub = name373_sub;
   Allnum[373].type = name373_type;
#endif


#if(All_Count >= 375)
   strcpy(Allnum[374].name, name374);
   Allnum[374].va = (uint16_t*)&(name374_value);			
   Allnum[374].sub = name374_sub;
   Allnum[374].type = name374_type;
#endif


#if(All_Count >= 376)
   strcpy(Allnum[375].name, name375);
   Allnum[375].va = (uint16_t*)&(name375_value);			
   Allnum[375].sub = name375_sub;
   Allnum[375].type = name375_type;
#endif


#if(All_Count >= 377)
   strcpy(Allnum[376].name, name376);
   Allnum[376].va = (uint16_t*)&(name376_value);			
   Allnum[376].sub = name376_sub;
   Allnum[376].type = name376_type;
#endif


#if(All_Count >= 378)
   strcpy(Allnum[377].name, name377);
   Allnum[377].va = (uint16_t*)&(name377_value);			
   Allnum[377].sub = name377_sub;
   Allnum[377].type = name377_type;
#endif


#if(All_Count >= 379)
   strcpy(Allnum[378].name, name378);
   Allnum[378].va = (uint16_t*)&(name378_value);			
   Allnum[378].sub = name378_sub;
   Allnum[378].type = name378_type;
#endif


#if(All_Count >= 380)
   strcpy(Allnum[379].name, name379);
   Allnum[379].va = (uint16_t*)&(name379_value);			
   Allnum[379].sub = name379_sub;
   Allnum[379].type = name379_type;
#endif


#if(All_Count >= 381)
   strcpy(Allnum[380].name, name380);
   Allnum[380].va = (uint16_t*)&(name380_value);			
   Allnum[380].sub = name380_sub;
   Allnum[380].type = name380_type;
#endif


#if(All_Count >= 382)
   strcpy(Allnum[381].name, name381);
   Allnum[381].va = (uint16_t*)&(name381_value);			
   Allnum[381].sub = name381_sub;
   Allnum[381].type = name381_type;
#endif


#if(All_Count >= 383)
   strcpy(Allnum[382].name, name382);
   Allnum[382].va = (uint16_t*)&(name382_value);			
   Allnum[382].sub = name382_sub;
   Allnum[382].type = name382_type;
#endif


#if(All_Count >= 384)
   strcpy(Allnum[383].name, name383);
   Allnum[383].va = (uint16_t*)&(name383_value);			
   Allnum[383].sub = name383_sub;
   Allnum[383].type = name383_type;
#endif


#if(All_Count >= 385)
   strcpy(Allnum[384].name, name384);
   Allnum[384].va = (uint16_t*)&(name384_value);			
   Allnum[384].sub = name384_sub;
   Allnum[384].type = name384_type;
#endif


#if(All_Count >= 386)
   strcpy(Allnum[385].name, name385);
   Allnum[385].va = (uint16_t*)&(name385_value);			
   Allnum[385].sub = name385_sub;
   Allnum[385].type = name385_type;
#endif


#if(All_Count >= 387)
   strcpy(Allnum[386].name, name386);
   Allnum[386].va = (uint16_t*)&(name386_value);			
   Allnum[386].sub = name386_sub;
   Allnum[386].type = name386_type;
#endif


#if(All_Count >= 388)
   strcpy(Allnum[387].name, name387);
   Allnum[387].va = (uint16_t*)&(name387_value);			
   Allnum[387].sub = name387_sub;
   Allnum[387].type = name387_type;
#endif


#if(All_Count >= 389)
   strcpy(Allnum[388].name, name388);
   Allnum[388].va = (uint16_t*)&(name388_value);			
   Allnum[388].sub = name388_sub;
   Allnum[388].type = name388_type;
#endif


#if(All_Count >= 390)
   strcpy(Allnum[389].name, name389);
   Allnum[389].va = (uint16_t*)&(name389_value);			
   Allnum[389].sub = name389_sub;
   Allnum[389].type = name389_type;
#endif


#if(All_Count >= 391)
   strcpy(Allnum[390].name, name390);
   Allnum[390].va = (uint16_t*)&(name390_value);			
   Allnum[390].sub = name390_sub;
   Allnum[390].type = name390_type;
#endif


#if(All_Count >= 392)
   strcpy(Allnum[391].name, name391);
   Allnum[391].va = (uint16_t*)&(name391_value);			
   Allnum[391].sub = name391_sub;
   Allnum[391].type = name391_type;
#endif


#if(All_Count >= 393)
   strcpy(Allnum[392].name, name392);
   Allnum[392].va = (uint16_t*)&(name392_value);			
   Allnum[392].sub = name392_sub;
   Allnum[392].type = name392_type;
#endif


#if(All_Count >= 394)
   strcpy(Allnum[393].name, name393);
   Allnum[393].va = (uint16_t*)&(name393_value);			
   Allnum[393].sub = name393_sub;
   Allnum[393].type = name393_type;
#endif


#if(All_Count >= 395)
   strcpy(Allnum[394].name, name394);
   Allnum[394].va = (uint16_t*)&(name394_value);			
   Allnum[394].sub = name394_sub;
   Allnum[394].type = name394_type;
#endif


#if(All_Count >= 396)
   strcpy(Allnum[395].name, name395);
   Allnum[395].va = (uint16_t*)&(name395_value);			
   Allnum[395].sub = name395_sub;
   Allnum[395].type = name395_type;
#endif


#if(All_Count >= 397)
   strcpy(Allnum[396].name, name396);
   Allnum[396].va = (uint16_t*)&(name396_value);			
   Allnum[396].sub = name396_sub;
   Allnum[396].type = name396_type;
#endif


#if(All_Count >= 398)
   strcpy(Allnum[397].name, name397);
   Allnum[397].va = (uint16_t*)&(name397_value);			
   Allnum[397].sub = name397_sub;
   Allnum[397].type = name397_type;
#endif


#if(All_Count >= 399)
   strcpy(Allnum[398].name, name398);
   Allnum[398].va = (uint16_t*)&(name398_value);			
   Allnum[398].sub = name398_sub;
   Allnum[398].type = name398_type;
#endif


#if(All_Count >= 400)
   strcpy(Allnum[399].name, name399);
   Allnum[399].va = (uint16_t*)&(name399_value);			
   Allnum[399].sub = name399_sub;
   Allnum[399].type = name399_type;
#endif


#if(All_Count >= 401)
   strcpy(Allnum[400].name, name400);
   Allnum[400].va = (uint16_t*)&(name400_value);			
   Allnum[400].sub = name400_sub;
   Allnum[400].type = name400_type;
#endif


#if(All_Count >= 402)
   strcpy(Allnum[401].name, name401);
   Allnum[401].va = (uint16_t*)&(name401_value);			
   Allnum[401].sub = name401_sub;
   Allnum[401].type = name401_type;
#endif


#if(All_Count >= 403)
   strcpy(Allnum[402].name, name402);
   Allnum[402].va = (uint16_t*)&(name402_value);			
   Allnum[402].sub = name402_sub;
   Allnum[402].type = name402_type;
#endif


#if(All_Count >= 404)
   strcpy(Allnum[403].name, name403);
   Allnum[403].va = (uint16_t*)&(name403_value);			
   Allnum[403].sub = name403_sub;
   Allnum[403].type = name403_type;
#endif


#if(All_Count >= 405)
   strcpy(Allnum[404].name, name404);
   Allnum[404].va = (uint16_t*)&(name404_value);			
   Allnum[404].sub = name404_sub;
   Allnum[404].type = name404_type;
#endif


#if(All_Count >= 406)
   strcpy(Allnum[405].name, name405);
   Allnum[405].va = (uint16_t*)&(name405_value);			
   Allnum[405].sub = name405_sub;
   Allnum[405].type = name405_type;
#endif


#if(All_Count >= 407)
   strcpy(Allnum[406].name, name406);
   Allnum[406].va = (uint16_t*)&(name406_value);			
   Allnum[406].sub = name406_sub;
   Allnum[406].type = name406_type;
#endif


#if(All_Count >= 408)
   strcpy(Allnum[407].name, name407);
   Allnum[407].va = (uint16_t*)&(name407_value);			
   Allnum[407].sub = name407_sub;
   Allnum[407].type = name407_type;
#endif


#if(All_Count >= 409)
   strcpy(Allnum[408].name, name408);
   Allnum[408].va = (uint16_t*)&(name408_value);			
   Allnum[408].sub = name408_sub;
   Allnum[408].type = name408_type;
#endif


#if(All_Count >= 410)
   strcpy(Allnum[409].name, name409);
   Allnum[409].va = (uint16_t*)&(name409_value);			
   Allnum[409].sub = name409_sub;
   Allnum[409].type = name409_type;
#endif


#if(All_Count >= 411)
   strcpy(Allnum[410].name, name410);
   Allnum[410].va = (uint16_t*)&(name410_value);			
   Allnum[410].sub = name410_sub;
   Allnum[410].type = name410_type;
#endif


#if(All_Count >= 412)
   strcpy(Allnum[411].name, name411);
   Allnum[411].va = (uint16_t*)&(name411_value);			
   Allnum[411].sub = name411_sub;
   Allnum[411].type = name411_type;
#endif


#if(All_Count >= 413)
   strcpy(Allnum[412].name, name412);
   Allnum[412].va = (uint16_t*)&(name412_value);			
   Allnum[412].sub = name412_sub;
   Allnum[412].type = name412_type;
#endif


#if(All_Count >= 414)
   strcpy(Allnum[413].name, name413);
   Allnum[413].va = (uint16_t*)&(name413_value);			
   Allnum[413].sub = name413_sub;
   Allnum[413].type = name413_type;
#endif


#if(All_Count >= 415)
   strcpy(Allnum[414].name, name414);
   Allnum[414].va = (uint16_t*)&(name414_value);			
   Allnum[414].sub = name414_sub;
   Allnum[414].type = name414_type;
#endif


#if(All_Count >= 416)
   strcpy(Allnum[415].name, name415);
   Allnum[415].va = (uint16_t*)&(name415_value);			
   Allnum[415].sub = name415_sub;
   Allnum[415].type = name415_type;
#endif


#if(All_Count >= 417)
   strcpy(Allnum[416].name, name416);
   Allnum[416].va = (uint16_t*)&(name416_value);			
   Allnum[416].sub = name416_sub;
   Allnum[416].type = name416_type;
#endif


#if(All_Count >= 418)
   strcpy(Allnum[417].name, name417);
   Allnum[417].va = (uint16_t*)&(name417_value);			
   Allnum[417].sub = name417_sub;
   Allnum[417].type = name417_type;
#endif


#if(All_Count >= 419)
   strcpy(Allnum[418].name, name418);
   Allnum[418].va = (uint16_t*)&(name418_value);			
   Allnum[418].sub = name418_sub;
   Allnum[418].type = name418_type;
#endif


#if(All_Count >= 420)
   strcpy(Allnum[419].name, name419);
   Allnum[419].va = (uint16_t*)&(name419_value);			
   Allnum[419].sub = name419_sub;
   Allnum[419].type = name419_type;
#endif


#if(All_Count >= 421)
   strcpy(Allnum[420].name, name420);
   Allnum[420].va = (uint16_t*)&(name420_value);			
   Allnum[420].sub = name420_sub;
   Allnum[420].type = name420_type;
#endif


#if(All_Count >= 422)
   strcpy(Allnum[421].name, name421);
   Allnum[421].va = (uint16_t*)&(name421_value);			
   Allnum[421].sub = name421_sub;
   Allnum[421].type = name421_type;
#endif


#if(All_Count >= 423)
   strcpy(Allnum[422].name, name422);
   Allnum[422].va = (uint16_t*)&(name422_value);			
   Allnum[422].sub = name422_sub;
   Allnum[422].type = name422_type;
#endif


#if(All_Count >= 424)
   strcpy(Allnum[423].name, name423);
   Allnum[423].va = (uint16_t*)&(name423_value);			
   Allnum[423].sub = name423_sub;
   Allnum[423].type = name423_type;
#endif


#if(All_Count >= 425)
   strcpy(Allnum[424].name, name424);
   Allnum[424].va = (uint16_t*)&(name424_value);			
   Allnum[424].sub = name424_sub;
   Allnum[424].type = name424_type;
#endif


#if(All_Count >= 426)
   strcpy(Allnum[425].name, name425);
   Allnum[425].va = (uint16_t*)&(name425_value);			
   Allnum[425].sub = name425_sub;
   Allnum[425].type = name425_type;
#endif


#if(All_Count >= 427)
   strcpy(Allnum[426].name, name426);
   Allnum[426].va = (uint16_t*)&(name426_value);			
   Allnum[426].sub = name426_sub;
   Allnum[426].type = name426_type;
#endif


#if(All_Count >= 428)
   strcpy(Allnum[427].name, name427);
   Allnum[427].va = (uint16_t*)&(name427_value);			
   Allnum[427].sub = name427_sub;
   Allnum[427].type = name427_type;
#endif


#if(All_Count >= 429)
   strcpy(Allnum[428].name, name428);
   Allnum[428].va = (uint16_t*)&(name428_value);			
   Allnum[428].sub = name428_sub;
   Allnum[428].type = name428_type;
#endif


#if(All_Count >= 430)
   strcpy(Allnum[429].name, name429);
   Allnum[429].va = (uint16_t*)&(name429_value);			
   Allnum[429].sub = name429_sub;
   Allnum[429].type = name429_type;
#endif


#if(All_Count >= 431)
   strcpy(Allnum[430].name, name430);
   Allnum[430].va = (uint16_t*)&(name430_value);			
   Allnum[430].sub = name430_sub;
   Allnum[430].type = name430_type;
#endif


#if(All_Count >= 432)
   strcpy(Allnum[431].name, name431);
   Allnum[431].va = (uint16_t*)&(name431_value);			
   Allnum[431].sub = name431_sub;
   Allnum[431].type = name431_type;
#endif


#if(All_Count >= 433)
   strcpy(Allnum[432].name, name432);
   Allnum[432].va = (uint16_t*)&(name432_value);			
   Allnum[432].sub = name432_sub;
   Allnum[432].type = name432_type;
#endif


#if(All_Count >= 434)
   strcpy(Allnum[433].name, name433);
   Allnum[433].va = (uint16_t*)&(name433_value);			
   Allnum[433].sub = name433_sub;
   Allnum[433].type = name433_type;
#endif


#if(All_Count >= 435)
   strcpy(Allnum[434].name, name434);
   Allnum[434].va = (uint16_t*)&(name434_value);			
   Allnum[434].sub = name434_sub;
   Allnum[434].type = name434_type;
#endif


#if(All_Count >= 436)
   strcpy(Allnum[435].name, name435);
   Allnum[435].va = (uint16_t*)&(name435_value);			
   Allnum[435].sub = name435_sub;
   Allnum[435].type = name435_type;
#endif


#if(All_Count >= 437)
   strcpy(Allnum[436].name, name436);
   Allnum[436].va = (uint16_t*)&(name436_value);			
   Allnum[436].sub = name436_sub;
   Allnum[436].type = name436_type;
#endif


#if(All_Count >= 438)
   strcpy(Allnum[437].name, name437);
   Allnum[437].va = (uint16_t*)&(name437_value);			
   Allnum[437].sub = name437_sub;
   Allnum[437].type = name437_type;
#endif


#if(All_Count >= 439)
   strcpy(Allnum[438].name, name438);
   Allnum[438].va = (uint16_t*)&(name438_value);			
   Allnum[438].sub = name438_sub;
   Allnum[438].type = name438_type;
#endif


#if(All_Count >= 440)
   strcpy(Allnum[439].name, name439);
   Allnum[439].va = (uint16_t*)&(name439_value);			
   Allnum[439].sub = name439_sub;
   Allnum[439].type = name439_type;
#endif


#if(All_Count >= 441)
   strcpy(Allnum[440].name, name440);
   Allnum[440].va = (uint16_t*)&(name440_value);			
   Allnum[440].sub = name440_sub;
   Allnum[440].type = name440_type;
#endif


#if(All_Count >= 442)
   strcpy(Allnum[441].name, name441);
   Allnum[441].va = (uint16_t*)&(name441_value);			
   Allnum[441].sub = name441_sub;
   Allnum[441].type = name441_type;
#endif


#if(All_Count >= 443)
   strcpy(Allnum[442].name, name442);
   Allnum[442].va = (uint16_t*)&(name442_value);			
   Allnum[442].sub = name442_sub;
   Allnum[442].type = name442_type;
#endif


#if(All_Count >= 444)
   strcpy(Allnum[443].name, name443);
   Allnum[443].va = (uint16_t*)&(name443_value);			
   Allnum[443].sub = name443_sub;
   Allnum[443].type = name443_type;
#endif


#if(All_Count >= 445)
   strcpy(Allnum[444].name, name444);
   Allnum[444].va = (uint16_t*)&(name444_value);			
   Allnum[444].sub = name444_sub;
   Allnum[444].type = name444_type;
#endif


#if(All_Count >= 446)
   strcpy(Allnum[445].name, name445);
   Allnum[445].va = (uint16_t*)&(name445_value);			
   Allnum[445].sub = name445_sub;
   Allnum[445].type = name445_type;
#endif


#if(All_Count >= 447)
   strcpy(Allnum[446].name, name446);
   Allnum[446].va = (uint16_t*)&(name446_value);			
   Allnum[446].sub = name446_sub;
   Allnum[446].type = name446_type;
#endif


#if(All_Count >= 448)
   strcpy(Allnum[447].name, name447);
   Allnum[447].va = (uint16_t*)&(name447_value);			
   Allnum[447].sub = name447_sub;
   Allnum[447].type = name447_type;
#endif


#if(All_Count >= 449)
   strcpy(Allnum[448].name, name448);
   Allnum[448].va = (uint16_t*)&(name448_value);			
   Allnum[448].sub = name448_sub;
   Allnum[448].type = name448_type;
#endif


#if(All_Count >= 450)
   strcpy(Allnum[449].name, name449);
   Allnum[449].va = (uint16_t*)&(name449_value);			
   Allnum[449].sub = name449_sub;
   Allnum[449].type = name449_type;
#endif


#if(All_Count >= 451)
   strcpy(Allnum[450].name, name450);
   Allnum[450].va = (uint16_t*)&(name450_value);			
   Allnum[450].sub = name450_sub;
   Allnum[450].type = name450_type;
#endif


#if(All_Count >= 452)
   strcpy(Allnum[451].name, name451);
   Allnum[451].va = (uint16_t*)&(name451_value);			
   Allnum[451].sub = name451_sub;
   Allnum[451].type = name451_type;
#endif


#if(All_Count >= 453)
   strcpy(Allnum[452].name, name452);
   Allnum[452].va = (uint16_t*)&(name452_value);			
   Allnum[452].sub = name452_sub;
   Allnum[452].type = name452_type;
#endif


#if(All_Count >= 454)
   strcpy(Allnum[453].name, name453);
   Allnum[453].va = (uint16_t*)&(name453_value);			
   Allnum[453].sub = name453_sub;
   Allnum[453].type = name453_type;
#endif


#if(All_Count >= 455)
   strcpy(Allnum[454].name, name454);
   Allnum[454].va = (uint16_t*)&(name454_value);			
   Allnum[454].sub = name454_sub;
   Allnum[454].type = name454_type;
#endif


#if(All_Count >= 456)
   strcpy(Allnum[455].name, name455);
   Allnum[455].va = (uint16_t*)&(name455_value);			
   Allnum[455].sub = name455_sub;
   Allnum[455].type = name455_type;
#endif


#if(All_Count >= 457)
   strcpy(Allnum[456].name, name456);
   Allnum[456].va = (uint16_t*)&(name456_value);			
   Allnum[456].sub = name456_sub;
   Allnum[456].type = name456_type;
#endif


#if(All_Count >= 458)
   strcpy(Allnum[457].name, name457);
   Allnum[457].va = (uint16_t*)&(name457_value);			
   Allnum[457].sub = name457_sub;
   Allnum[457].type = name457_type;
#endif


#if(All_Count >= 459)
   strcpy(Allnum[458].name, name458);
   Allnum[458].va = (uint16_t*)&(name458_value);			
   Allnum[458].sub = name458_sub;
   Allnum[458].type = name458_type;
#endif


#if(All_Count >= 460)
   strcpy(Allnum[459].name, name459);
   Allnum[459].va = (uint16_t*)&(name459_value);			
   Allnum[459].sub = name459_sub;
   Allnum[459].type = name459_type;
#endif


#if(All_Count >= 461)
   strcpy(Allnum[460].name, name460);
   Allnum[460].va = (uint16_t*)&(name460_value);			
   Allnum[460].sub = name460_sub;
   Allnum[460].type = name460_type;
#endif


#if(All_Count >= 462)
   strcpy(Allnum[461].name, name461);
   Allnum[461].va = (uint16_t*)&(name461_value);			
   Allnum[461].sub = name461_sub;
   Allnum[461].type = name461_type;
#endif


#if(All_Count >= 463)
   strcpy(Allnum[462].name, name462);
   Allnum[462].va = (uint16_t*)&(name462_value);			
   Allnum[462].sub = name462_sub;
   Allnum[462].type = name462_type;
#endif


#if(All_Count >= 464)
   strcpy(Allnum[463].name, name463);
   Allnum[463].va = (uint16_t*)&(name463_value);			
   Allnum[463].sub = name463_sub;
   Allnum[463].type = name463_type;
#endif


#if(All_Count >= 465)
   strcpy(Allnum[464].name, name464);
   Allnum[464].va = (uint16_t*)&(name464_value);			
   Allnum[464].sub = name464_sub;
   Allnum[464].type = name464_type;
#endif


#if(All_Count >= 466)
   strcpy(Allnum[465].name, name465);
   Allnum[465].va = (uint16_t*)&(name465_value);			
   Allnum[465].sub = name465_sub;
   Allnum[465].type = name465_type;
#endif


#if(All_Count >= 467)
   strcpy(Allnum[466].name, name466);
   Allnum[466].va = (uint16_t*)&(name466_value);			
   Allnum[466].sub = name466_sub;
   Allnum[466].type = name466_type;
#endif


#if(All_Count >= 468)
   strcpy(Allnum[467].name, name467);
   Allnum[467].va = (uint16_t*)&(name467_value);			
   Allnum[467].sub = name467_sub;
   Allnum[467].type = name467_type;
#endif


#if(All_Count >= 469)
   strcpy(Allnum[468].name, name468);
   Allnum[468].va = (uint16_t*)&(name468_value);			
   Allnum[468].sub = name468_sub;
   Allnum[468].type = name468_type;
#endif


#if(All_Count >= 470)
   strcpy(Allnum[469].name, name469);
   Allnum[469].va = (uint16_t*)&(name469_value);			
   Allnum[469].sub = name469_sub;
   Allnum[469].type = name469_type;
#endif


#if(All_Count >= 471)
   strcpy(Allnum[470].name, name470);
   Allnum[470].va = (uint16_t*)&(name470_value);			
   Allnum[470].sub = name470_sub;
   Allnum[470].type = name470_type;
#endif


#if(All_Count >= 472)
   strcpy(Allnum[471].name, name471);
   Allnum[471].va = (uint16_t*)&(name471_value);			
   Allnum[471].sub = name471_sub;
   Allnum[471].type = name471_type;
#endif


#if(All_Count >= 473)
   strcpy(Allnum[472].name, name472);
   Allnum[472].va = (uint16_t*)&(name472_value);			
   Allnum[472].sub = name472_sub;
   Allnum[472].type = name472_type;
#endif


#if(All_Count >= 474)
   strcpy(Allnum[473].name, name473);
   Allnum[473].va = (uint16_t*)&(name473_value);			
   Allnum[473].sub = name473_sub;
   Allnum[473].type = name473_type;
#endif


#if(All_Count >= 475)
   strcpy(Allnum[474].name, name474);
   Allnum[474].va = (uint16_t*)&(name474_value);			
   Allnum[474].sub = name474_sub;
   Allnum[474].type = name474_type;
#endif


#if(All_Count >= 476)
   strcpy(Allnum[475].name, name475);
   Allnum[475].va = (uint16_t*)&(name475_value);			
   Allnum[475].sub = name475_sub;
   Allnum[475].type = name475_type;
#endif


#if(All_Count >= 477)
   strcpy(Allnum[476].name, name476);
   Allnum[476].va = (uint16_t*)&(name476_value);			
   Allnum[476].sub = name476_sub;
   Allnum[476].type = name476_type;
#endif


#if(All_Count >= 478)
   strcpy(Allnum[477].name, name477);
   Allnum[477].va = (uint16_t*)&(name477_value);			
   Allnum[477].sub = name477_sub;
   Allnum[477].type = name477_type;
#endif


#if(All_Count >= 479)
   strcpy(Allnum[478].name, name478);
   Allnum[478].va = (uint16_t*)&(name478_value);			
   Allnum[478].sub = name478_sub;
   Allnum[478].type = name478_type;
#endif


#if(All_Count >= 480)
   strcpy(Allnum[479].name, name479);
   Allnum[479].va = (uint16_t*)&(name479_value);			
   Allnum[479].sub = name479_sub;
   Allnum[479].type = name479_type;
#endif


#if(All_Count >= 481)
   strcpy(Allnum[480].name, name480);
   Allnum[480].va = (uint16_t*)&(name480_value);			
   Allnum[480].sub = name480_sub;
   Allnum[480].type = name480_type;
#endif


#if(All_Count >= 482)
   strcpy(Allnum[481].name, name481);
   Allnum[481].va = (uint16_t*)&(name481_value);			
   Allnum[481].sub = name481_sub;
   Allnum[481].type = name481_type;
#endif


#if(All_Count >= 483)
   strcpy(Allnum[482].name, name482);
   Allnum[482].va = (uint16_t*)&(name482_value);			
   Allnum[482].sub = name482_sub;
   Allnum[482].type = name482_type;
#endif


#if(All_Count >= 484)
   strcpy(Allnum[483].name, name483);
   Allnum[483].va = (uint16_t*)&(name483_value);			
   Allnum[483].sub = name483_sub;
   Allnum[483].type = name483_type;
#endif


#if(All_Count >= 485)
   strcpy(Allnum[484].name, name484);
   Allnum[484].va = (uint16_t*)&(name484_value);			
   Allnum[484].sub = name484_sub;
   Allnum[484].type = name484_type;
#endif


#if(All_Count >= 486)
   strcpy(Allnum[485].name, name485);
   Allnum[485].va = (uint16_t*)&(name485_value);			
   Allnum[485].sub = name485_sub;
   Allnum[485].type = name485_type;
#endif


#if(All_Count >= 487)
   strcpy(Allnum[486].name, name486);
   Allnum[486].va = (uint16_t*)&(name486_value);			
   Allnum[486].sub = name486_sub;
   Allnum[486].type = name486_type;
#endif


#if(All_Count >= 488)
   strcpy(Allnum[487].name, name487);
   Allnum[487].va = (uint16_t*)&(name487_value);			
   Allnum[487].sub = name487_sub;
   Allnum[487].type = name487_type;
#endif


#if(All_Count >= 489)
   strcpy(Allnum[488].name, name488);
   Allnum[488].va = (uint16_t*)&(name488_value);			
   Allnum[488].sub = name488_sub;
   Allnum[488].type = name488_type;
#endif


#if(All_Count >= 490)
   strcpy(Allnum[489].name, name489);
   Allnum[489].va = (uint16_t*)&(name489_value);			
   Allnum[489].sub = name489_sub;
   Allnum[489].type = name489_type;
#endif


#if(All_Count >= 491)
   strcpy(Allnum[490].name, name490);
   Allnum[490].va = (uint16_t*)&(name490_value);			
   Allnum[490].sub = name490_sub;
   Allnum[490].type = name490_type;
#endif


#if(All_Count >= 492)
   strcpy(Allnum[491].name, name491);
   Allnum[491].va = (uint16_t*)&(name491_value);			
   Allnum[491].sub = name491_sub;
   Allnum[491].type = name491_type;
#endif


#if(All_Count >= 493)
   strcpy(Allnum[492].name, name492);
   Allnum[492].va = (uint16_t*)&(name492_value);			
   Allnum[492].sub = name492_sub;
   Allnum[492].type = name492_type;
#endif


#if(All_Count >= 494)
   strcpy(Allnum[493].name, name493);
   Allnum[493].va = (uint16_t*)&(name493_value);			
   Allnum[493].sub = name493_sub;
   Allnum[493].type = name493_type;
#endif


#if(All_Count >= 495)
   strcpy(Allnum[494].name, name494);
   Allnum[494].va = (uint16_t*)&(name494_value);			
   Allnum[494].sub = name494_sub;
   Allnum[494].type = name494_type;
#endif


#if(All_Count >= 496)
   strcpy(Allnum[495].name, name495);
   Allnum[495].va = (uint16_t*)&(name495_value);			
   Allnum[495].sub = name495_sub;
   Allnum[495].type = name495_type;
#endif


#if(All_Count >= 497)
   strcpy(Allnum[496].name, name496);
   Allnum[496].va = (uint16_t*)&(name496_value);			
   Allnum[496].sub = name496_sub;
   Allnum[496].type = name496_type;
#endif


#if(All_Count >= 498)
   strcpy(Allnum[497].name, name497);
   Allnum[497].va = (uint16_t*)&(name497_value);			
   Allnum[497].sub = name497_sub;
   Allnum[497].type = name497_type;
#endif


#if(All_Count >= 499)
   strcpy(Allnum[498].name, name498);
   Allnum[498].va = (uint16_t*)&(name498_value);			
   Allnum[498].sub = name498_sub;
   Allnum[498].type = name498_type;
#endif


#if(All_Count >= 500)
   strcpy(Allnum[499].name, name499);
   Allnum[499].va = (uint16_t*)&(name499_value);			
   Allnum[499].sub = name499_sub;
   Allnum[499].type = name499_type;
#endif


#if(All_Count >= 501)
   strcpy(Allnum[500].name, name500);
   Allnum[500].va = (uint16_t*)&(name500_value);			
   Allnum[500].sub = name500_sub;
   Allnum[500].type = name500_type;
#endif


#if(All_Count >= 502)
   strcpy(Allnum[501].name, name501);
   Allnum[501].va = (uint16_t*)&(name501_value);			
   Allnum[501].sub = name501_sub;
   Allnum[501].type = name501_type;
#endif


#if(All_Count >= 503)
   strcpy(Allnum[502].name, name502);
   Allnum[502].va = (uint16_t*)&(name502_value);			
   Allnum[502].sub = name502_sub;
   Allnum[502].type = name502_type;
#endif


#if(All_Count >= 504)
   strcpy(Allnum[503].name, name503);
   Allnum[503].va = (uint16_t*)&(name503_value);			
   Allnum[503].sub = name503_sub;
   Allnum[503].type = name503_type;
#endif


#if(All_Count >= 505)
   strcpy(Allnum[504].name, name504);
   Allnum[504].va = (uint16_t*)&(name504_value);			
   Allnum[504].sub = name504_sub;
   Allnum[504].type = name504_type;
#endif


#if(All_Count >= 506)
   strcpy(Allnum[505].name, name505);
   Allnum[505].va = (uint16_t*)&(name505_value);			
   Allnum[505].sub = name505_sub;
   Allnum[505].type = name505_type;
#endif


#if(All_Count >= 507)
   strcpy(Allnum[506].name, name506);
   Allnum[506].va = (uint16_t*)&(name506_value);			
   Allnum[506].sub = name506_sub;
   Allnum[506].type = name506_type;
#endif


#if(All_Count >= 508)
   strcpy(Allnum[507].name, name507);
   Allnum[507].va = (uint16_t*)&(name507_value);			
   Allnum[507].sub = name507_sub;
   Allnum[507].type = name507_type;
#endif


#if(All_Count >= 509)
   strcpy(Allnum[508].name, name508);
   Allnum[508].va = (uint16_t*)&(name508_value);			
   Allnum[508].sub = name508_sub;
   Allnum[508].type = name508_type;
#endif


#if(All_Count >= 510)
   strcpy(Allnum[509].name, name509);
   Allnum[509].va = (uint16_t*)&(name509_value);			
   Allnum[509].sub = name509_sub;
   Allnum[509].type = name509_type;
#endif


#if(All_Count >= 511)
   strcpy(Allnum[510].name, name510);
   Allnum[510].va = (uint16_t*)&(name510_value);			
   Allnum[510].sub = name510_sub;
   Allnum[510].type = name510_type;
#endif


#if(All_Count >= 512)
   strcpy(Allnum[511].name, name511);
   Allnum[511].va = (uint16_t*)&(name511_value);			
   Allnum[511].sub = name511_sub;
   Allnum[511].type = name511_type;
#endif


#if(All_Count >= 513)
   strcpy(Allnum[512].name, name512);
   Allnum[512].va = (uint16_t*)&(name512_value);			
   Allnum[512].sub = name512_sub;
   Allnum[512].type = name512_type;
#endif


#if(All_Count >= 514)
   strcpy(Allnum[513].name, name513);
   Allnum[513].va = (uint16_t*)&(name513_value);			
   Allnum[513].sub = name513_sub;
   Allnum[513].type = name513_type;
#endif


#if(All_Count >= 515)
   strcpy(Allnum[514].name, name514);
   Allnum[514].va = (uint16_t*)&(name514_value);			
   Allnum[514].sub = name514_sub;
   Allnum[514].type = name514_type;
#endif


#if(All_Count >= 516)
   strcpy(Allnum[515].name, name515);
   Allnum[515].va = (uint16_t*)&(name515_value);			
   Allnum[515].sub = name515_sub;
   Allnum[515].type = name515_type;
#endif


#if(All_Count >= 517)
   strcpy(Allnum[516].name, name516);
   Allnum[516].va = (uint16_t*)&(name516_value);			
   Allnum[516].sub = name516_sub;
   Allnum[516].type = name516_type;
#endif


#if(All_Count >= 518)
   strcpy(Allnum[517].name, name517);
   Allnum[517].va = (uint16_t*)&(name517_value);			
   Allnum[517].sub = name517_sub;
   Allnum[517].type = name517_type;
#endif


#if(All_Count >= 519)
   strcpy(Allnum[518].name, name518);
   Allnum[518].va = (uint16_t*)&(name518_value);			
   Allnum[518].sub = name518_sub;
   Allnum[518].type = name518_type;
#endif


#if(All_Count >= 520)
   strcpy(Allnum[519].name, name519);
   Allnum[519].va = (uint16_t*)&(name519_value);			
   Allnum[519].sub = name519_sub;
   Allnum[519].type = name519_type;
#endif


#if(All_Count >= 521)
   strcpy(Allnum[520].name, name520);
   Allnum[520].va = (uint16_t*)&(name520_value);			
   Allnum[520].sub = name520_sub;
   Allnum[520].type = name520_type;
#endif


#if(All_Count >= 522)
   strcpy(Allnum[521].name, name521);
   Allnum[521].va = (uint16_t*)&(name521_value);			
   Allnum[521].sub = name521_sub;
   Allnum[521].type = name521_type;
#endif


#if(All_Count >= 523)
   strcpy(Allnum[522].name, name522);
   Allnum[522].va = (uint16_t*)&(name522_value);			
   Allnum[522].sub = name522_sub;
   Allnum[522].type = name522_type;
#endif


#if(All_Count >= 524)
   strcpy(Allnum[523].name, name523);
   Allnum[523].va = (uint16_t*)&(name523_value);			
   Allnum[523].sub = name523_sub;
   Allnum[523].type = name523_type;
#endif


#if(All_Count >= 525)
   strcpy(Allnum[524].name, name524);
   Allnum[524].va = (uint16_t*)&(name524_value);			
   Allnum[524].sub = name524_sub;
   Allnum[524].type = name524_type;
#endif


#if(All_Count >= 526)
   strcpy(Allnum[525].name, name525);
   Allnum[525].va = (uint16_t*)&(name525_value);			
   Allnum[525].sub = name525_sub;
   Allnum[525].type = name525_type;
#endif


#if(All_Count >= 527)
   strcpy(Allnum[526].name, name526);
   Allnum[526].va = (uint16_t*)&(name526_value);			
   Allnum[526].sub = name526_sub;
   Allnum[526].type = name526_type;
#endif


#if(All_Count >= 528)
   strcpy(Allnum[527].name, name527);
   Allnum[527].va = (uint16_t*)&(name527_value);			
   Allnum[527].sub = name527_sub;
   Allnum[527].type = name527_type;
#endif


#if(All_Count >= 529)
   strcpy(Allnum[528].name, name528);
   Allnum[528].va = (uint16_t*)&(name528_value);			
   Allnum[528].sub = name528_sub;
   Allnum[528].type = name528_type;
#endif


#if(All_Count >= 530)
   strcpy(Allnum[529].name, name529);
   Allnum[529].va = (uint16_t*)&(name529_value);			
   Allnum[529].sub = name529_sub;
   Allnum[529].type = name529_type;
#endif


#if(All_Count >= 531)
   strcpy(Allnum[530].name, name530);
   Allnum[530].va = (uint16_t*)&(name530_value);			
   Allnum[530].sub = name530_sub;
   Allnum[530].type = name530_type;
#endif


#if(All_Count >= 532)
   strcpy(Allnum[531].name, name531);
   Allnum[531].va = (uint16_t*)&(name531_value);			
   Allnum[531].sub = name531_sub;
   Allnum[531].type = name531_type;
#endif


#if(All_Count >= 533)
   strcpy(Allnum[532].name, name532);
   Allnum[532].va = (uint16_t*)&(name532_value);			
   Allnum[532].sub = name532_sub;
   Allnum[532].type = name532_type;
#endif


#if(All_Count >= 534)
   strcpy(Allnum[533].name, name533);
   Allnum[533].va = (uint16_t*)&(name533_value);			
   Allnum[533].sub = name533_sub;
   Allnum[533].type = name533_type;
#endif


#if(All_Count >= 535)
   strcpy(Allnum[534].name, name534);
   Allnum[534].va = (uint16_t*)&(name534_value);			
   Allnum[534].sub = name534_sub;
   Allnum[534].type = name534_type;
#endif


#if(All_Count >= 536)
   strcpy(Allnum[535].name, name535);
   Allnum[535].va = (uint16_t*)&(name535_value);			
   Allnum[535].sub = name535_sub;
   Allnum[535].type = name535_type;
#endif


#if(All_Count >= 537)
   strcpy(Allnum[536].name, name536);
   Allnum[536].va = (uint16_t*)&(name536_value);			
   Allnum[536].sub = name536_sub;
   Allnum[536].type = name536_type;
#endif


#if(All_Count >= 538)
   strcpy(Allnum[537].name, name537);
   Allnum[537].va = (uint16_t*)&(name537_value);			
   Allnum[537].sub = name537_sub;
   Allnum[537].type = name537_type;
#endif


#if(All_Count >= 539)
   strcpy(Allnum[538].name, name538);
   Allnum[538].va = (uint16_t*)&(name538_value);			
   Allnum[538].sub = name538_sub;
   Allnum[538].type = name538_type;
#endif


#if(All_Count >= 540)
   strcpy(Allnum[539].name, name539);
   Allnum[539].va = (uint16_t*)&(name539_value);			
   Allnum[539].sub = name539_sub;
   Allnum[539].type = name539_type;
#endif


#if(All_Count >= 541)
   strcpy(Allnum[540].name, name540);
   Allnum[540].va = (uint16_t*)&(name540_value);			
   Allnum[540].sub = name540_sub;
   Allnum[540].type = name540_type;
#endif


#if(All_Count >= 542)
   strcpy(Allnum[541].name, name541);
   Allnum[541].va = (uint16_t*)&(name541_value);			
   Allnum[541].sub = name541_sub;
   Allnum[541].type = name541_type;
#endif


#if(All_Count >= 543)
   strcpy(Allnum[542].name, name542);
   Allnum[542].va = (uint16_t*)&(name542_value);			
   Allnum[542].sub = name542_sub;
   Allnum[542].type = name542_type;
#endif


#if(All_Count >= 544)
   strcpy(Allnum[543].name, name543);
   Allnum[543].va = (uint16_t*)&(name543_value);			
   Allnum[543].sub = name543_sub;
   Allnum[543].type = name543_type;
#endif


#if(All_Count >= 545)
   strcpy(Allnum[544].name, name544);
   Allnum[544].va = (uint16_t*)&(name544_value);			
   Allnum[544].sub = name544_sub;
   Allnum[544].type = name544_type;
#endif


#if(All_Count >= 546)
   strcpy(Allnum[545].name, name545);
   Allnum[545].va = (uint16_t*)&(name545_value);			
   Allnum[545].sub = name545_sub;
   Allnum[545].type = name545_type;
#endif


#if(All_Count >= 547)
   strcpy(Allnum[546].name, name546);
   Allnum[546].va = (uint16_t*)&(name546_value);			
   Allnum[546].sub = name546_sub;
   Allnum[546].type = name546_type;
#endif


#if(All_Count >= 548)
   strcpy(Allnum[547].name, name547);
   Allnum[547].va = (uint16_t*)&(name547_value);			
   Allnum[547].sub = name547_sub;
   Allnum[547].type = name547_type;
#endif


#if(All_Count >= 549)
   strcpy(Allnum[548].name, name548);
   Allnum[548].va = (uint16_t*)&(name548_value);			
   Allnum[548].sub = name548_sub;
   Allnum[548].type = name548_type;
#endif


#if(All_Count >= 550)
   strcpy(Allnum[549].name, name549);
   Allnum[549].va = (uint16_t*)&(name549_value);			
   Allnum[549].sub = name549_sub;
   Allnum[549].type = name549_type;
#endif


#if(All_Count >= 551)
   strcpy(Allnum[550].name, name550);
   Allnum[550].va = (uint16_t*)&(name550_value);			
   Allnum[550].sub = name550_sub;
   Allnum[550].type = name550_type;
#endif


#if(All_Count >= 552)
   strcpy(Allnum[551].name, name551);
   Allnum[551].va = (uint16_t*)&(name551_value);			
   Allnum[551].sub = name551_sub;
   Allnum[551].type = name551_type;
#endif


#if(All_Count >= 553)
   strcpy(Allnum[552].name, name552);
   Allnum[552].va = (uint16_t*)&(name552_value);			
   Allnum[552].sub = name552_sub;
   Allnum[552].type = name552_type;
#endif


#if(All_Count >= 554)
   strcpy(Allnum[553].name, name553);
   Allnum[553].va = (uint16_t*)&(name553_value);			
   Allnum[553].sub = name553_sub;
   Allnum[553].type = name553_type;
#endif


#if(All_Count >= 555)
   strcpy(Allnum[554].name, name554);
   Allnum[554].va = (uint16_t*)&(name554_value);			
   Allnum[554].sub = name554_sub;
   Allnum[554].type = name554_type;
#endif


#if(All_Count >= 556)
   strcpy(Allnum[555].name, name555);
   Allnum[555].va = (uint16_t*)&(name555_value);			
   Allnum[555].sub = name555_sub;
   Allnum[555].type = name555_type;
#endif


#if(All_Count >= 557)
   strcpy(Allnum[556].name, name556);
   Allnum[556].va = (uint16_t*)&(name556_value);			
   Allnum[556].sub = name556_sub;
   Allnum[556].type = name556_type;
#endif


#if(All_Count >= 558)
   strcpy(Allnum[557].name, name557);
   Allnum[557].va = (uint16_t*)&(name557_value);			
   Allnum[557].sub = name557_sub;
   Allnum[557].type = name557_type;
#endif


#if(All_Count >= 559)
   strcpy(Allnum[558].name, name558);
   Allnum[558].va = (uint16_t*)&(name558_value);			
   Allnum[558].sub = name558_sub;
   Allnum[558].type = name558_type;
#endif


#if(All_Count >= 560)
   strcpy(Allnum[559].name, name559);
   Allnum[559].va = (uint16_t*)&(name559_value);			
   Allnum[559].sub = name559_sub;
   Allnum[559].type = name559_type;
#endif


#if(All_Count >= 561)
   strcpy(Allnum[560].name, name560);
   Allnum[560].va = (uint16_t*)&(name560_value);			
   Allnum[560].sub = name560_sub;
   Allnum[560].type = name560_type;
#endif


#if(All_Count >= 562)
   strcpy(Allnum[561].name, name561);
   Allnum[561].va = (uint16_t*)&(name561_value);			
   Allnum[561].sub = name561_sub;
   Allnum[561].type = name561_type;
#endif


#if(All_Count >= 563)
   strcpy(Allnum[562].name, name562);
   Allnum[562].va = (uint16_t*)&(name562_value);			
   Allnum[562].sub = name562_sub;
   Allnum[562].type = name562_type;
#endif


#if(All_Count >= 564)
   strcpy(Allnum[563].name, name563);
   Allnum[563].va = (uint16_t*)&(name563_value);			
   Allnum[563].sub = name563_sub;
   Allnum[563].type = name563_type;
#endif


#if(All_Count >= 565)
   strcpy(Allnum[564].name, name564);
   Allnum[564].va = (uint16_t*)&(name564_value);			
   Allnum[564].sub = name564_sub;
   Allnum[564].type = name564_type;
#endif


#if(All_Count >= 566)
   strcpy(Allnum[565].name, name565);
   Allnum[565].va = (uint16_t*)&(name565_value);			
   Allnum[565].sub = name565_sub;
   Allnum[565].type = name565_type;
#endif


#if(All_Count >= 567)
   strcpy(Allnum[566].name, name566);
   Allnum[566].va = (uint16_t*)&(name566_value);			
   Allnum[566].sub = name566_sub;
   Allnum[566].type = name566_type;
#endif


#if(All_Count >= 568)
   strcpy(Allnum[567].name, name567);
   Allnum[567].va = (uint16_t*)&(name567_value);			
   Allnum[567].sub = name567_sub;
   Allnum[567].type = name567_type;
#endif


#if(All_Count >= 569)
   strcpy(Allnum[568].name, name568);
   Allnum[568].va = (uint16_t*)&(name568_value);			
   Allnum[568].sub = name568_sub;
   Allnum[568].type = name568_type;
#endif


#if(All_Count >= 570)
   strcpy(Allnum[569].name, name569);
   Allnum[569].va = (uint16_t*)&(name569_value);			
   Allnum[569].sub = name569_sub;
   Allnum[569].type = name569_type;
#endif


#if(All_Count >= 571)
   strcpy(Allnum[570].name, name570);
   Allnum[570].va = (uint16_t*)&(name570_value);			
   Allnum[570].sub = name570_sub;
   Allnum[570].type = name570_type;
#endif


#if(All_Count >= 572)
   strcpy(Allnum[571].name, name571);
   Allnum[571].va = (uint16_t*)&(name571_value);			
   Allnum[571].sub = name571_sub;
   Allnum[571].type = name571_type;
#endif


#if(All_Count >= 573)
   strcpy(Allnum[572].name, name572);
   Allnum[572].va = (uint16_t*)&(name572_value);			
   Allnum[572].sub = name572_sub;
   Allnum[572].type = name572_type;
#endif


#if(All_Count >= 574)
   strcpy(Allnum[573].name, name573);
   Allnum[573].va = (uint16_t*)&(name573_value);			
   Allnum[573].sub = name573_sub;
   Allnum[573].type = name573_type;
#endif


#if(All_Count >= 575)
   strcpy(Allnum[574].name, name574);
   Allnum[574].va = (uint16_t*)&(name574_value);			
   Allnum[574].sub = name574_sub;
   Allnum[574].type = name574_type;
#endif


#if(All_Count >= 576)
   strcpy(Allnum[575].name, name575);
   Allnum[575].va = (uint16_t*)&(name575_value);			
   Allnum[575].sub = name575_sub;
   Allnum[575].type = name575_type;
#endif


#if(All_Count >= 577)
   strcpy(Allnum[576].name, name576);
   Allnum[576].va = (uint16_t*)&(name576_value);			
   Allnum[576].sub = name576_sub;
   Allnum[576].type = name576_type;
#endif


#if(All_Count >= 578)
   strcpy(Allnum[577].name, name577);
   Allnum[577].va = (uint16_t*)&(name577_value);			
   Allnum[577].sub = name577_sub;
   Allnum[577].type = name577_type;
#endif


#if(All_Count >= 579)
   strcpy(Allnum[578].name, name578);
   Allnum[578].va = (uint16_t*)&(name578_value);			
   Allnum[578].sub = name578_sub;
   Allnum[578].type = name578_type;
#endif


#if(All_Count >= 580)
   strcpy(Allnum[579].name, name579);
   Allnum[579].va = (uint16_t*)&(name579_value);			
   Allnum[579].sub = name579_sub;
   Allnum[579].type = name579_type;
#endif


#if(All_Count >= 581)
   strcpy(Allnum[580].name, name580);
   Allnum[580].va = (uint16_t*)&(name580_value);			
   Allnum[580].sub = name580_sub;
   Allnum[580].type = name580_type;
#endif


#if(All_Count >= 582)
   strcpy(Allnum[581].name, name581);
   Allnum[581].va = (uint16_t*)&(name581_value);			
   Allnum[581].sub = name581_sub;
   Allnum[581].type = name581_type;
#endif


#if(All_Count >= 583)
   strcpy(Allnum[582].name, name582);
   Allnum[582].va = (uint16_t*)&(name582_value);			
   Allnum[582].sub = name582_sub;
   Allnum[582].type = name582_type;
#endif


#if(All_Count >= 584)
   strcpy(Allnum[583].name, name583);
   Allnum[583].va = (uint16_t*)&(name583_value);			
   Allnum[583].sub = name583_sub;
   Allnum[583].type = name583_type;
#endif


#if(All_Count >= 585)
   strcpy(Allnum[584].name, name584);
   Allnum[584].va = (uint16_t*)&(name584_value);			
   Allnum[584].sub = name584_sub;
   Allnum[584].type = name584_type;
#endif


#if(All_Count >= 586)
   strcpy(Allnum[585].name, name585);
   Allnum[585].va = (uint16_t*)&(name585_value);			
   Allnum[585].sub = name585_sub;
   Allnum[585].type = name585_type;
#endif


#if(All_Count >= 587)
   strcpy(Allnum[586].name, name586);
   Allnum[586].va = (uint16_t*)&(name586_value);			
   Allnum[586].sub = name586_sub;
   Allnum[586].type = name586_type;
#endif


#if(All_Count >= 588)
   strcpy(Allnum[587].name, name587);
   Allnum[587].va = (uint16_t*)&(name587_value);			
   Allnum[587].sub = name587_sub;
   Allnum[587].type = name587_type;
#endif


#if(All_Count >= 589)
   strcpy(Allnum[588].name, name588);
   Allnum[588].va = (uint16_t*)&(name588_value);			
   Allnum[588].sub = name588_sub;
   Allnum[588].type = name588_type;
#endif


#if(All_Count >= 590)
   strcpy(Allnum[589].name, name589);
   Allnum[589].va = (uint16_t*)&(name589_value);			
   Allnum[589].sub = name589_sub;
   Allnum[589].type = name589_type;
#endif


#if(All_Count >= 591)
   strcpy(Allnum[590].name, name590);
   Allnum[590].va = (uint16_t*)&(name590_value);			
   Allnum[590].sub = name590_sub;
   Allnum[590].type = name590_type;
#endif


#if(All_Count >= 592)
   strcpy(Allnum[591].name, name591);
   Allnum[591].va = (uint16_t*)&(name591_value);			
   Allnum[591].sub = name591_sub;
   Allnum[591].type = name591_type;
#endif


#if(All_Count >= 593)
   strcpy(Allnum[592].name, name592);
   Allnum[592].va = (uint16_t*)&(name592_value);			
   Allnum[592].sub = name592_sub;
   Allnum[592].type = name592_type;
#endif


#if(All_Count >= 594)
   strcpy(Allnum[593].name, name593);
   Allnum[593].va = (uint16_t*)&(name593_value);			
   Allnum[593].sub = name593_sub;
   Allnum[593].type = name593_type;
#endif


#if(All_Count >= 595)
   strcpy(Allnum[594].name, name594);
   Allnum[594].va = (uint16_t*)&(name594_value);			
   Allnum[594].sub = name594_sub;
   Allnum[594].type = name594_type;
#endif


#if(All_Count >= 596)
   strcpy(Allnum[595].name, name595);
   Allnum[595].va = (uint16_t*)&(name595_value);			
   Allnum[595].sub = name595_sub;
   Allnum[595].type = name595_type;
#endif


#if(All_Count >= 597)
   strcpy(Allnum[596].name, name596);
   Allnum[596].va = (uint16_t*)&(name596_value);			
   Allnum[596].sub = name596_sub;
   Allnum[596].type = name596_type;
#endif


#if(All_Count >= 598)
   strcpy(Allnum[597].name, name597);
   Allnum[597].va = (uint16_t*)&(name597_value);			
   Allnum[597].sub = name597_sub;
   Allnum[597].type = name597_type;
#endif


#if(All_Count >= 599)
   strcpy(Allnum[598].name, name598);
   Allnum[598].va = (uint16_t*)&(name598_value);			
   Allnum[598].sub = name598_sub;
   Allnum[598].type = name598_type;
#endif


#if(All_Count >= 600)
   strcpy(Allnum[599].name, name599);
   Allnum[599].va = (uint16_t*)&(name599_value);			
   Allnum[599].sub = name599_sub;
   Allnum[599].type = name599_type;
#endif


#if(All_Count >= 601)
   strcpy(Allnum[600].name, name600);
   Allnum[600].va = (uint16_t*)&(name600_value);			
   Allnum[600].sub = name600_sub;
   Allnum[600].type = name600_type;
#endif


#if(All_Count >= 602)
   strcpy(Allnum[601].name, name601);
   Allnum[601].va = (uint16_t*)&(name601_value);			
   Allnum[601].sub = name601_sub;
   Allnum[601].type = name601_type;
#endif


#if(All_Count >= 603)
   strcpy(Allnum[602].name, name602);
   Allnum[602].va = (uint16_t*)&(name602_value);			
   Allnum[602].sub = name602_sub;
   Allnum[602].type = name602_type;
#endif


#if(All_Count >= 604)
   strcpy(Allnum[603].name, name603);
   Allnum[603].va = (uint16_t*)&(name603_value);			
   Allnum[603].sub = name603_sub;
   Allnum[603].type = name603_type;
#endif


#if(All_Count >= 605)
   strcpy(Allnum[604].name, name604);
   Allnum[604].va = (uint16_t*)&(name604_value);			
   Allnum[604].sub = name604_sub;
   Allnum[604].type = name604_type;
#endif


#if(All_Count >= 606)
   strcpy(Allnum[605].name, name605);
   Allnum[605].va = (uint16_t*)&(name605_value);			
   Allnum[605].sub = name605_sub;
   Allnum[605].type = name605_type;
#endif


#if(All_Count >= 607)
   strcpy(Allnum[606].name, name606);
   Allnum[606].va = (uint16_t*)&(name606_value);			
   Allnum[606].sub = name606_sub;
   Allnum[606].type = name606_type;
#endif


#if(All_Count >= 608)
   strcpy(Allnum[607].name, name607);
   Allnum[607].va = (uint16_t*)&(name607_value);			
   Allnum[607].sub = name607_sub;
   Allnum[607].type = name607_type;
#endif


#if(All_Count >= 609)
   strcpy(Allnum[608].name, name608);
   Allnum[608].va = (uint16_t*)&(name608_value);			
   Allnum[608].sub = name608_sub;
   Allnum[608].type = name608_type;
#endif


#if(All_Count >= 610)
   strcpy(Allnum[609].name, name609);
   Allnum[609].va = (uint16_t*)&(name609_value);			
   Allnum[609].sub = name609_sub;
   Allnum[609].type = name609_type;
#endif


#if(All_Count >= 611)
   strcpy(Allnum[610].name, name610);
   Allnum[610].va = (uint16_t*)&(name610_value);			
   Allnum[610].sub = name610_sub;
   Allnum[610].type = name610_type;
#endif


#if(All_Count >= 612)
   strcpy(Allnum[611].name, name611);
   Allnum[611].va = (uint16_t*)&(name611_value);			
   Allnum[611].sub = name611_sub;
   Allnum[611].type = name611_type;
#endif


#if(All_Count >= 613)
   strcpy(Allnum[612].name, name612);
   Allnum[612].va = (uint16_t*)&(name612_value);			
   Allnum[612].sub = name612_sub;
   Allnum[612].type = name612_type;
#endif


#if(All_Count >= 614)
   strcpy(Allnum[613].name, name613);
   Allnum[613].va = (uint16_t*)&(name613_value);			
   Allnum[613].sub = name613_sub;
   Allnum[613].type = name613_type;
#endif


#if(All_Count >= 615)
   strcpy(Allnum[614].name, name614);
   Allnum[614].va = (uint16_t*)&(name614_value);			
   Allnum[614].sub = name614_sub;
   Allnum[614].type = name614_type;
#endif


#if(All_Count >= 616)
   strcpy(Allnum[615].name, name615);
   Allnum[615].va = (uint16_t*)&(name615_value);			
   Allnum[615].sub = name615_sub;
   Allnum[615].type = name615_type;
#endif


#if(All_Count >= 617)
   strcpy(Allnum[616].name, name616);
   Allnum[616].va = (uint16_t*)&(name616_value);			
   Allnum[616].sub = name616_sub;
   Allnum[616].type = name616_type;
#endif


#if(All_Count >= 618)
   strcpy(Allnum[617].name, name617);
   Allnum[617].va = (uint16_t*)&(name617_value);			
   Allnum[617].sub = name617_sub;
   Allnum[617].type = name617_type;
#endif


#if(All_Count >= 619)
   strcpy(Allnum[618].name, name618);
   Allnum[618].va = (uint16_t*)&(name618_value);			
   Allnum[618].sub = name618_sub;
   Allnum[618].type = name618_type;
#endif


#if(All_Count >= 620)
   strcpy(Allnum[619].name, name619);
   Allnum[619].va = (uint16_t*)&(name619_value);			
   Allnum[619].sub = name619_sub;
   Allnum[619].type = name619_type;
#endif


#if(All_Count >= 621)
   strcpy(Allnum[620].name, name620);
   Allnum[620].va = (uint16_t*)&(name620_value);			
   Allnum[620].sub = name620_sub;
   Allnum[620].type = name620_type;
#endif


#if(All_Count >= 622)
   strcpy(Allnum[621].name, name621);
   Allnum[621].va = (uint16_t*)&(name621_value);			
   Allnum[621].sub = name621_sub;
   Allnum[621].type = name621_type;
#endif


#if(All_Count >= 623)
   strcpy(Allnum[622].name, name622);
   Allnum[622].va = (uint16_t*)&(name622_value);			
   Allnum[622].sub = name622_sub;
   Allnum[622].type = name622_type;
#endif


#if(All_Count >= 624)
   strcpy(Allnum[623].name, name623);
   Allnum[623].va = (uint16_t*)&(name623_value);			
   Allnum[623].sub = name623_sub;
   Allnum[623].type = name623_type;
#endif


#if(All_Count >= 625)
   strcpy(Allnum[624].name, name624);
   Allnum[624].va = (uint16_t*)&(name624_value);			
   Allnum[624].sub = name624_sub;
   Allnum[624].type = name624_type;
#endif


#if(All_Count >= 626)
   strcpy(Allnum[625].name, name625);
   Allnum[625].va = (uint16_t*)&(name625_value);			
   Allnum[625].sub = name625_sub;
   Allnum[625].type = name625_type;
#endif


#if(All_Count >= 627)
   strcpy(Allnum[626].name, name626);
   Allnum[626].va = (uint16_t*)&(name626_value);			
   Allnum[626].sub = name626_sub;
   Allnum[626].type = name626_type;
#endif


#if(All_Count >= 628)
   strcpy(Allnum[627].name, name627);
   Allnum[627].va = (uint16_t*)&(name627_value);			
   Allnum[627].sub = name627_sub;
   Allnum[627].type = name627_type;
#endif


#if(All_Count >= 629)
   strcpy(Allnum[628].name, name628);
   Allnum[628].va = (uint16_t*)&(name628_value);			
   Allnum[628].sub = name628_sub;
   Allnum[628].type = name628_type;
#endif


#if(All_Count >= 630)
   strcpy(Allnum[629].name, name629);
   Allnum[629].va = (uint16_t*)&(name629_value);			
   Allnum[629].sub = name629_sub;
   Allnum[629].type = name629_type;
#endif


#if(All_Count >= 631)
   strcpy(Allnum[630].name, name630);
   Allnum[630].va = (uint16_t*)&(name630_value);			
   Allnum[630].sub = name630_sub;
   Allnum[630].type = name630_type;
#endif


#if(All_Count >= 632)
   strcpy(Allnum[631].name, name631);
   Allnum[631].va = (uint16_t*)&(name631_value);			
   Allnum[631].sub = name631_sub;
   Allnum[631].type = name631_type;
#endif


#if(All_Count >= 633)
   strcpy(Allnum[632].name, name632);
   Allnum[632].va = (uint16_t*)&(name632_value);			
   Allnum[632].sub = name632_sub;
   Allnum[632].type = name632_type;
#endif


#if(All_Count >= 634)
   strcpy(Allnum[633].name, name633);
   Allnum[633].va = (uint16_t*)&(name633_value);			
   Allnum[633].sub = name633_sub;
   Allnum[633].type = name633_type;
#endif


#if(All_Count >= 635)
   strcpy(Allnum[634].name, name634);
   Allnum[634].va = (uint16_t*)&(name634_value);			
   Allnum[634].sub = name634_sub;
   Allnum[634].type = name634_type;
#endif


#if(All_Count >= 636)
   strcpy(Allnum[635].name, name635);
   Allnum[635].va = (uint16_t*)&(name635_value);			
   Allnum[635].sub = name635_sub;
   Allnum[635].type = name635_type;
#endif


#if(All_Count >= 637)
   strcpy(Allnum[636].name, name636);
   Allnum[636].va = (uint16_t*)&(name636_value);			
   Allnum[636].sub = name636_sub;
   Allnum[636].type = name636_type;
#endif


#if(All_Count >= 638)
   strcpy(Allnum[637].name, name637);
   Allnum[637].va = (uint16_t*)&(name637_value);			
   Allnum[637].sub = name637_sub;
   Allnum[637].type = name637_type;
#endif


#if(All_Count >= 639)
   strcpy(Allnum[638].name, name638);
   Allnum[638].va = (uint16_t*)&(name638_value);			
   Allnum[638].sub = name638_sub;
   Allnum[638].type = name638_type;
#endif


#if(All_Count >= 640)
   strcpy(Allnum[639].name, name639);
   Allnum[639].va = (uint16_t*)&(name639_value);			
   Allnum[639].sub = name639_sub;
   Allnum[639].type = name639_type;
#endif


#if(All_Count >= 641)
   strcpy(Allnum[640].name, name640);
   Allnum[640].va = (uint16_t*)&(name640_value);			
   Allnum[640].sub = name640_sub;
   Allnum[640].type = name640_type;
#endif


#if(All_Count >= 642)
   strcpy(Allnum[641].name, name641);
   Allnum[641].va = (uint16_t*)&(name641_value);			
   Allnum[641].sub = name641_sub;
   Allnum[641].type = name641_type;
#endif


#if(All_Count >= 643)
   strcpy(Allnum[642].name, name642);
   Allnum[642].va = (uint16_t*)&(name642_value);			
   Allnum[642].sub = name642_sub;
   Allnum[642].type = name642_type;
#endif


#if(All_Count >= 644)
   strcpy(Allnum[643].name, name643);
   Allnum[643].va = (uint16_t*)&(name643_value);			
   Allnum[643].sub = name643_sub;
   Allnum[643].type = name643_type;
#endif


#if(All_Count >= 645)
   strcpy(Allnum[644].name, name644);
   Allnum[644].va = (uint16_t*)&(name644_value);			
   Allnum[644].sub = name644_sub;
   Allnum[644].type = name644_type;
#endif


#if(All_Count >= 646)
   strcpy(Allnum[645].name, name645);
   Allnum[645].va = (uint16_t*)&(name645_value);			
   Allnum[645].sub = name645_sub;
   Allnum[645].type = name645_type;
#endif


#if(All_Count >= 647)
   strcpy(Allnum[646].name, name646);
   Allnum[646].va = (uint16_t*)&(name646_value);			
   Allnum[646].sub = name646_sub;
   Allnum[646].type = name646_type;
#endif


#if(All_Count >= 648)
   strcpy(Allnum[647].name, name647);
   Allnum[647].va = (uint16_t*)&(name647_value);			
   Allnum[647].sub = name647_sub;
   Allnum[647].type = name647_type;
#endif


#if(All_Count >= 649)
   strcpy(Allnum[648].name, name648);
   Allnum[648].va = (uint16_t*)&(name648_value);			
   Allnum[648].sub = name648_sub;
   Allnum[648].type = name648_type;
#endif


#if(All_Count >= 650)
   strcpy(Allnum[649].name, name649);
   Allnum[649].va = (uint16_t*)&(name649_value);			
   Allnum[649].sub = name649_sub;
   Allnum[649].type = name649_type;
#endif


#if(All_Count >= 651)
   strcpy(Allnum[650].name, name650);
   Allnum[650].va = (uint16_t*)&(name650_value);			
   Allnum[650].sub = name650_sub;
   Allnum[650].type = name650_type;
#endif


#if(All_Count >= 652)
   strcpy(Allnum[651].name, name651);
   Allnum[651].va = (uint16_t*)&(name651_value);			
   Allnum[651].sub = name651_sub;
   Allnum[651].type = name651_type;
#endif


#if(All_Count >= 653)
   strcpy(Allnum[652].name, name652);
   Allnum[652].va = (uint16_t*)&(name652_value);			
   Allnum[652].sub = name652_sub;
   Allnum[652].type = name652_type;
#endif


#if(All_Count >= 654)
   strcpy(Allnum[653].name, name653);
   Allnum[653].va = (uint16_t*)&(name653_value);			
   Allnum[653].sub = name653_sub;
   Allnum[653].type = name653_type;
#endif


#if(All_Count >= 655)
   strcpy(Allnum[654].name, name654);
   Allnum[654].va = (uint16_t*)&(name654_value);			
   Allnum[654].sub = name654_sub;
   Allnum[654].type = name654_type;
#endif


#if(All_Count >= 656)
   strcpy(Allnum[655].name, name655);
   Allnum[655].va = (uint16_t*)&(name655_value);			
   Allnum[655].sub = name655_sub;
   Allnum[655].type = name655_type;
#endif


#if(All_Count >= 657)
   strcpy(Allnum[656].name, name656);
   Allnum[656].va = (uint16_t*)&(name656_value);			
   Allnum[656].sub = name656_sub;
   Allnum[656].type = name656_type;
#endif


#if(All_Count >= 658)
   strcpy(Allnum[657].name, name657);
   Allnum[657].va = (uint16_t*)&(name657_value);			
   Allnum[657].sub = name657_sub;
   Allnum[657].type = name657_type;
#endif


#if(All_Count >= 659)
   strcpy(Allnum[658].name, name658);
   Allnum[658].va = (uint16_t*)&(name658_value);			
   Allnum[658].sub = name658_sub;
   Allnum[658].type = name658_type;
#endif


#if(All_Count >= 660)
   strcpy(Allnum[659].name, name659);
   Allnum[659].va = (uint16_t*)&(name659_value);			
   Allnum[659].sub = name659_sub;
   Allnum[659].type = name659_type;
#endif


#if(All_Count >= 661)
   strcpy(Allnum[660].name, name660);
   Allnum[660].va = (uint16_t*)&(name660_value);			
   Allnum[660].sub = name660_sub;
   Allnum[660].type = name660_type;
#endif


#if(All_Count >= 662)
   strcpy(Allnum[661].name, name661);
   Allnum[661].va = (uint16_t*)&(name661_value);			
   Allnum[661].sub = name661_sub;
   Allnum[661].type = name661_type;
#endif


#if(All_Count >= 663)
   strcpy(Allnum[662].name, name662);
   Allnum[662].va = (uint16_t*)&(name662_value);			
   Allnum[662].sub = name662_sub;
   Allnum[662].type = name662_type;
#endif


#if(All_Count >= 664)
   strcpy(Allnum[663].name, name663);
   Allnum[663].va = (uint16_t*)&(name663_value);			
   Allnum[663].sub = name663_sub;
   Allnum[663].type = name663_type;
#endif


#if(All_Count >= 665)
   strcpy(Allnum[664].name, name664);
   Allnum[664].va = (uint16_t*)&(name664_value);			
   Allnum[664].sub = name664_sub;
   Allnum[664].type = name664_type;
#endif


#if(All_Count >= 666)
   strcpy(Allnum[665].name, name665);
   Allnum[665].va = (uint16_t*)&(name665_value);			
   Allnum[665].sub = name665_sub;
   Allnum[665].type = name665_type;
#endif


#if(All_Count >= 667)
   strcpy(Allnum[666].name, name666);
   Allnum[666].va = (uint16_t*)&(name666_value);			
   Allnum[666].sub = name666_sub;
   Allnum[666].type = name666_type;
#endif


#if(All_Count >= 668)
   strcpy(Allnum[667].name, name667);
   Allnum[667].va = (uint16_t*)&(name667_value);			
   Allnum[667].sub = name667_sub;
   Allnum[667].type = name667_type;
#endif


#if(All_Count >= 669)
   strcpy(Allnum[668].name, name668);
   Allnum[668].va = (uint16_t*)&(name668_value);			
   Allnum[668].sub = name668_sub;
   Allnum[668].type = name668_type;
#endif


#if(All_Count >= 670)
   strcpy(Allnum[669].name, name669);
   Allnum[669].va = (uint16_t*)&(name669_value);			
   Allnum[669].sub = name669_sub;
   Allnum[669].type = name669_type;
#endif


#if(All_Count >= 671)
   strcpy(Allnum[670].name, name670);
   Allnum[670].va = (uint16_t*)&(name670_value);			
   Allnum[670].sub = name670_sub;
   Allnum[670].type = name670_type;
#endif


#if(All_Count >= 672)
   strcpy(Allnum[671].name, name671);
   Allnum[671].va = (uint16_t*)&(name671_value);			
   Allnum[671].sub = name671_sub;
   Allnum[671].type = name671_type;
#endif


#if(All_Count >= 673)
   strcpy(Allnum[672].name, name672);
   Allnum[672].va = (uint16_t*)&(name672_value);			
   Allnum[672].sub = name672_sub;
   Allnum[672].type = name672_type;
#endif


#if(All_Count >= 674)
   strcpy(Allnum[673].name, name673);
   Allnum[673].va = (uint16_t*)&(name673_value);			
   Allnum[673].sub = name673_sub;
   Allnum[673].type = name673_type;
#endif


#if(All_Count >= 675)
   strcpy(Allnum[674].name, name674);
   Allnum[674].va = (uint16_t*)&(name674_value);			
   Allnum[674].sub = name674_sub;
   Allnum[674].type = name674_type;
#endif


#if(All_Count >= 676)
   strcpy(Allnum[675].name, name675);
   Allnum[675].va = (uint16_t*)&(name675_value);			
   Allnum[675].sub = name675_sub;
   Allnum[675].type = name675_type;
#endif


#if(All_Count >= 677)
   strcpy(Allnum[676].name, name676);
   Allnum[676].va = (uint16_t*)&(name676_value);			
   Allnum[676].sub = name676_sub;
   Allnum[676].type = name676_type;
#endif


#if(All_Count >= 678)
   strcpy(Allnum[677].name, name677);
   Allnum[677].va = (uint16_t*)&(name677_value);			
   Allnum[677].sub = name677_sub;
   Allnum[677].type = name677_type;
#endif


#if(All_Count >= 679)
   strcpy(Allnum[678].name, name678);
   Allnum[678].va = (uint16_t*)&(name678_value);			
   Allnum[678].sub = name678_sub;
   Allnum[678].type = name678_type;
#endif


#if(All_Count >= 680)
   strcpy(Allnum[679].name, name679);
   Allnum[679].va = (uint16_t*)&(name679_value);			
   Allnum[679].sub = name679_sub;
   Allnum[679].type = name679_type;
#endif


#if(All_Count >= 681)
   strcpy(Allnum[680].name, name680);
   Allnum[680].va = (uint16_t*)&(name680_value);			
   Allnum[680].sub = name680_sub;
   Allnum[680].type = name680_type;
#endif


#if(All_Count >= 682)
   strcpy(Allnum[681].name, name681);
   Allnum[681].va = (uint16_t*)&(name681_value);			
   Allnum[681].sub = name681_sub;
   Allnum[681].type = name681_type;
#endif


#if(All_Count >= 683)
   strcpy(Allnum[682].name, name682);
   Allnum[682].va = (uint16_t*)&(name682_value);			
   Allnum[682].sub = name682_sub;
   Allnum[682].type = name682_type;
#endif


#if(All_Count >= 684)
   strcpy(Allnum[683].name, name683);
   Allnum[683].va = (uint16_t*)&(name683_value);			
   Allnum[683].sub = name683_sub;
   Allnum[683].type = name683_type;
#endif


#if(All_Count >= 685)
   strcpy(Allnum[684].name, name684);
   Allnum[684].va = (uint16_t*)&(name684_value);			
   Allnum[684].sub = name684_sub;
   Allnum[684].type = name684_type;
#endif


#if(All_Count >= 686)
   strcpy(Allnum[685].name, name685);
   Allnum[685].va = (uint16_t*)&(name685_value);			
   Allnum[685].sub = name685_sub;
   Allnum[685].type = name685_type;
#endif


#if(All_Count >= 687)
   strcpy(Allnum[686].name, name686);
   Allnum[686].va = (uint16_t*)&(name686_value);			
   Allnum[686].sub = name686_sub;
   Allnum[686].type = name686_type;
#endif


#if(All_Count >= 688)
   strcpy(Allnum[687].name, name687);
   Allnum[687].va = (uint16_t*)&(name687_value);			
   Allnum[687].sub = name687_sub;
   Allnum[687].type = name687_type;
#endif


#if(All_Count >= 689)
   strcpy(Allnum[688].name, name688);
   Allnum[688].va = (uint16_t*)&(name688_value);			
   Allnum[688].sub = name688_sub;
   Allnum[688].type = name688_type;
#endif


#if(All_Count >= 690)
   strcpy(Allnum[689].name, name689);
   Allnum[689].va = (uint16_t*)&(name689_value);			
   Allnum[689].sub = name689_sub;
   Allnum[689].type = name689_type;
#endif


#if(All_Count >= 691)
   strcpy(Allnum[690].name, name690);
   Allnum[690].va = (uint16_t*)&(name690_value);			
   Allnum[690].sub = name690_sub;
   Allnum[690].type = name690_type;
#endif


#if(All_Count >= 692)
   strcpy(Allnum[691].name, name691);
   Allnum[691].va = (uint16_t*)&(name691_value);			
   Allnum[691].sub = name691_sub;
   Allnum[691].type = name691_type;
#endif


#if(All_Count >= 693)
   strcpy(Allnum[692].name, name692);
   Allnum[692].va = (uint16_t*)&(name692_value);			
   Allnum[692].sub = name692_sub;
   Allnum[692].type = name692_type;
#endif


#if(All_Count >= 694)
   strcpy(Allnum[693].name, name693);
   Allnum[693].va = (uint16_t*)&(name693_value);			
   Allnum[693].sub = name693_sub;
   Allnum[693].type = name693_type;
#endif


#if(All_Count >= 695)
   strcpy(Allnum[694].name, name694);
   Allnum[694].va = (uint16_t*)&(name694_value);			
   Allnum[694].sub = name694_sub;
   Allnum[694].type = name694_type;
#endif


#if(All_Count >= 696)
   strcpy(Allnum[695].name, name695);
   Allnum[695].va = (uint16_t*)&(name695_value);			
   Allnum[695].sub = name695_sub;
   Allnum[695].type = name695_type;
#endif


#if(All_Count >= 697)
   strcpy(Allnum[696].name, name696);
   Allnum[696].va = (uint16_t*)&(name696_value);			
   Allnum[696].sub = name696_sub;
   Allnum[696].type = name696_type;
#endif


#if(All_Count >= 698)
   strcpy(Allnum[697].name, name697);
   Allnum[697].va = (uint16_t*)&(name697_value);			
   Allnum[697].sub = name697_sub;
   Allnum[697].type = name697_type;
#endif


#if(All_Count >= 699)
   strcpy(Allnum[698].name, name698);
   Allnum[698].va = (uint16_t*)&(name698_value);			
   Allnum[698].sub = name698_sub;
   Allnum[698].type = name698_type;
#endif


#if(All_Count >= 700)
   strcpy(Allnum[699].name, name699);
   Allnum[699].va = (uint16_t*)&(name699_value);			
   Allnum[699].sub = name699_sub;
   Allnum[699].type = name699_type;
#endif


#if(All_Count >= 701)
   strcpy(Allnum[700].name, name700);
   Allnum[700].va = (uint16_t*)&(name700_value);			
   Allnum[700].sub = name700_sub;
   Allnum[700].type = name700_type;
#endif


#if(All_Count >= 702)
   strcpy(Allnum[701].name, name701);
   Allnum[701].va = (uint16_t*)&(name701_value);			
   Allnum[701].sub = name701_sub;
   Allnum[701].type = name701_type;
#endif


#if(All_Count >= 703)
   strcpy(Allnum[702].name, name702);
   Allnum[702].va = (uint16_t*)&(name702_value);			
   Allnum[702].sub = name702_sub;
   Allnum[702].type = name702_type;
#endif


#if(All_Count >= 704)
   strcpy(Allnum[703].name, name703);
   Allnum[703].va = (uint16_t*)&(name703_value);			
   Allnum[703].sub = name703_sub;
   Allnum[703].type = name703_type;
#endif


#if(All_Count >= 705)
   strcpy(Allnum[704].name, name704);
   Allnum[704].va = (uint16_t*)&(name704_value);			
   Allnum[704].sub = name704_sub;
   Allnum[704].type = name704_type;
#endif


#if(All_Count >= 706)
   strcpy(Allnum[705].name, name705);
   Allnum[705].va = (uint16_t*)&(name705_value);			
   Allnum[705].sub = name705_sub;
   Allnum[705].type = name705_type;
#endif


#if(All_Count >= 707)
   strcpy(Allnum[706].name, name706);
   Allnum[706].va = (uint16_t*)&(name706_value);			
   Allnum[706].sub = name706_sub;
   Allnum[706].type = name706_type;
#endif


#if(All_Count >= 708)
   strcpy(Allnum[707].name, name707);
   Allnum[707].va = (uint16_t*)&(name707_value);			
   Allnum[707].sub = name707_sub;
   Allnum[707].type = name707_type;
#endif


#if(All_Count >= 709)
   strcpy(Allnum[708].name, name708);
   Allnum[708].va = (uint16_t*)&(name708_value);			
   Allnum[708].sub = name708_sub;
   Allnum[708].type = name708_type;
#endif


#if(All_Count >= 710)
   strcpy(Allnum[709].name, name709);
   Allnum[709].va = (uint16_t*)&(name709_value);			
   Allnum[709].sub = name709_sub;
   Allnum[709].type = name709_type;
#endif


#if(All_Count >= 711)
   strcpy(Allnum[710].name, name710);
   Allnum[710].va = (uint16_t*)&(name710_value);			
   Allnum[710].sub = name710_sub;
   Allnum[710].type = name710_type;
#endif


#if(All_Count >= 712)
   strcpy(Allnum[711].name, name711);
   Allnum[711].va = (uint16_t*)&(name711_value);			
   Allnum[711].sub = name711_sub;
   Allnum[711].type = name711_type;
#endif


#if(All_Count >= 713)
   strcpy(Allnum[712].name, name712);
   Allnum[712].va = (uint16_t*)&(name712_value);			
   Allnum[712].sub = name712_sub;
   Allnum[712].type = name712_type;
#endif


#if(All_Count >= 714)
   strcpy(Allnum[713].name, name713);
   Allnum[713].va = (uint16_t*)&(name713_value);			
   Allnum[713].sub = name713_sub;
   Allnum[713].type = name713_type;
#endif


#if(All_Count >= 715)
   strcpy(Allnum[714].name, name714);
   Allnum[714].va = (uint16_t*)&(name714_value);			
   Allnum[714].sub = name714_sub;
   Allnum[714].type = name714_type;
#endif


#if(All_Count >= 716)
   strcpy(Allnum[715].name, name715);
   Allnum[715].va = (uint16_t*)&(name715_value);			
   Allnum[715].sub = name715_sub;
   Allnum[715].type = name715_type;
#endif


#if(All_Count >= 717)
   strcpy(Allnum[716].name, name716);
   Allnum[716].va = (uint16_t*)&(name716_value);			
   Allnum[716].sub = name716_sub;
   Allnum[716].type = name716_type;
#endif


#if(All_Count >= 718)
   strcpy(Allnum[717].name, name717);
   Allnum[717].va = (uint16_t*)&(name717_value);			
   Allnum[717].sub = name717_sub;
   Allnum[717].type = name717_type;
#endif


#if(All_Count >= 719)
   strcpy(Allnum[718].name, name718);
   Allnum[718].va = (uint16_t*)&(name718_value);			
   Allnum[718].sub = name718_sub;
   Allnum[718].type = name718_type;
#endif


#if(All_Count >= 720)
   strcpy(Allnum[719].name, name719);
   Allnum[719].va = (uint16_t*)&(name719_value);			
   Allnum[719].sub = name719_sub;
   Allnum[719].type = name719_type;
#endif


#if(All_Count >= 721)
   strcpy(Allnum[720].name, name720);
   Allnum[720].va = (uint16_t*)&(name720_value);			
   Allnum[720].sub = name720_sub;
   Allnum[720].type = name720_type;
#endif


#if(All_Count >= 722)
   strcpy(Allnum[721].name, name721);
   Allnum[721].va = (uint16_t*)&(name721_value);			
   Allnum[721].sub = name721_sub;
   Allnum[721].type = name721_type;
#endif


#if(All_Count >= 723)
   strcpy(Allnum[722].name, name722);
   Allnum[722].va = (uint16_t*)&(name722_value);			
   Allnum[722].sub = name722_sub;
   Allnum[722].type = name722_type;
#endif


#if(All_Count >= 724)
   strcpy(Allnum[723].name, name723);
   Allnum[723].va = (uint16_t*)&(name723_value);			
   Allnum[723].sub = name723_sub;
   Allnum[723].type = name723_type;
#endif


#if(All_Count >= 725)
   strcpy(Allnum[724].name, name724);
   Allnum[724].va = (uint16_t*)&(name724_value);			
   Allnum[724].sub = name724_sub;
   Allnum[724].type = name724_type;
#endif


#if(All_Count >= 726)
   strcpy(Allnum[725].name, name725);
   Allnum[725].va = (uint16_t*)&(name725_value);			
   Allnum[725].sub = name725_sub;
   Allnum[725].type = name725_type;
#endif


#if(All_Count >= 727)
   strcpy(Allnum[726].name, name726);
   Allnum[726].va = (uint16_t*)&(name726_value);			
   Allnum[726].sub = name726_sub;
   Allnum[726].type = name726_type;
#endif


#if(All_Count >= 728)
   strcpy(Allnum[727].name, name727);
   Allnum[727].va = (uint16_t*)&(name727_value);			
   Allnum[727].sub = name727_sub;
   Allnum[727].type = name727_type;
#endif


#if(All_Count >= 729)
   strcpy(Allnum[728].name, name728);
   Allnum[728].va = (uint16_t*)&(name728_value);			
   Allnum[728].sub = name728_sub;
   Allnum[728].type = name728_type;
#endif


#if(All_Count >= 730)
   strcpy(Allnum[729].name, name729);
   Allnum[729].va = (uint16_t*)&(name729_value);			
   Allnum[729].sub = name729_sub;
   Allnum[729].type = name729_type;
#endif


#if(All_Count >= 731)
   strcpy(Allnum[730].name, name730);
   Allnum[730].va = (uint16_t*)&(name730_value);			
   Allnum[730].sub = name730_sub;
   Allnum[730].type = name730_type;
#endif


#if(All_Count >= 732)
   strcpy(Allnum[731].name, name731);
   Allnum[731].va = (uint16_t*)&(name731_value);			
   Allnum[731].sub = name731_sub;
   Allnum[731].type = name731_type;
#endif


#if(All_Count >= 733)
   strcpy(Allnum[732].name, name732);
   Allnum[732].va = (uint16_t*)&(name732_value);			
   Allnum[732].sub = name732_sub;
   Allnum[732].type = name732_type;
#endif


#if(All_Count >= 734)
   strcpy(Allnum[733].name, name733);
   Allnum[733].va = (uint16_t*)&(name733_value);			
   Allnum[733].sub = name733_sub;
   Allnum[733].type = name733_type;
#endif


#if(All_Count >= 735)
   strcpy(Allnum[734].name, name734);
   Allnum[734].va = (uint16_t*)&(name734_value);			
   Allnum[734].sub = name734_sub;
   Allnum[734].type = name734_type;
#endif


#if(All_Count >= 736)
   strcpy(Allnum[735].name, name735);
   Allnum[735].va = (uint16_t*)&(name735_value);			
   Allnum[735].sub = name735_sub;
   Allnum[735].type = name735_type;
#endif


#if(All_Count >= 737)
   strcpy(Allnum[736].name, name736);
   Allnum[736].va = (uint16_t*)&(name736_value);			
   Allnum[736].sub = name736_sub;
   Allnum[736].type = name736_type;
#endif


#if(All_Count >= 738)
   strcpy(Allnum[737].name, name737);
   Allnum[737].va = (uint16_t*)&(name737_value);			
   Allnum[737].sub = name737_sub;
   Allnum[737].type = name737_type;
#endif


#if(All_Count >= 739)
   strcpy(Allnum[738].name, name738);
   Allnum[738].va = (uint16_t*)&(name738_value);			
   Allnum[738].sub = name738_sub;
   Allnum[738].type = name738_type;
#endif


#if(All_Count >= 740)
   strcpy(Allnum[739].name, name739);
   Allnum[739].va = (uint16_t*)&(name739_value);			
   Allnum[739].sub = name739_sub;
   Allnum[739].type = name739_type;
#endif


#if(All_Count >= 741)
   strcpy(Allnum[740].name, name740);
   Allnum[740].va = (uint16_t*)&(name740_value);			
   Allnum[740].sub = name740_sub;
   Allnum[740].type = name740_type;
#endif


#if(All_Count >= 742)
   strcpy(Allnum[741].name, name741);
   Allnum[741].va = (uint16_t*)&(name741_value);			
   Allnum[741].sub = name741_sub;
   Allnum[741].type = name741_type;
#endif


#if(All_Count >= 743)
   strcpy(Allnum[742].name, name742);
   Allnum[742].va = (uint16_t*)&(name742_value);			
   Allnum[742].sub = name742_sub;
   Allnum[742].type = name742_type;
#endif


#if(All_Count >= 744)
   strcpy(Allnum[743].name, name743);
   Allnum[743].va = (uint16_t*)&(name743_value);			
   Allnum[743].sub = name743_sub;
   Allnum[743].type = name743_type;
#endif


#if(All_Count >= 745)
   strcpy(Allnum[744].name, name744);
   Allnum[744].va = (uint16_t*)&(name744_value);			
   Allnum[744].sub = name744_sub;
   Allnum[744].type = name744_type;
#endif


#if(All_Count >= 746)
   strcpy(Allnum[745].name, name745);
   Allnum[745].va = (uint16_t*)&(name745_value);			
   Allnum[745].sub = name745_sub;
   Allnum[745].type = name745_type;
#endif


#if(All_Count >= 747)
   strcpy(Allnum[746].name, name746);
   Allnum[746].va = (uint16_t*)&(name746_value);			
   Allnum[746].sub = name746_sub;
   Allnum[746].type = name746_type;
#endif


#if(All_Count >= 748)
   strcpy(Allnum[747].name, name747);
   Allnum[747].va = (uint16_t*)&(name747_value);			
   Allnum[747].sub = name747_sub;
   Allnum[747].type = name747_type;
#endif


#if(All_Count >= 749)
   strcpy(Allnum[748].name, name748);
   Allnum[748].va = (uint16_t*)&(name748_value);			
   Allnum[748].sub = name748_sub;
   Allnum[748].type = name748_type;
#endif


#if(All_Count >= 750)
   strcpy(Allnum[749].name, name749);
   Allnum[749].va = (uint16_t*)&(name749_value);			
   Allnum[749].sub = name749_sub;
   Allnum[749].type = name749_type;
#endif


#if(All_Count >= 751)
   strcpy(Allnum[750].name, name750);
   Allnum[750].va = (uint16_t*)&(name750_value);			
   Allnum[750].sub = name750_sub;
   Allnum[750].type = name750_type;
#endif


#if(All_Count >= 752)
   strcpy(Allnum[751].name, name751);
   Allnum[751].va = (uint16_t*)&(name751_value);			
   Allnum[751].sub = name751_sub;
   Allnum[751].type = name751_type;
#endif


#if(All_Count >= 753)
   strcpy(Allnum[752].name, name752);
   Allnum[752].va = (uint16_t*)&(name752_value);			
   Allnum[752].sub = name752_sub;
   Allnum[752].type = name752_type;
#endif


#if(All_Count >= 754)
   strcpy(Allnum[753].name, name753);
   Allnum[753].va = (uint16_t*)&(name753_value);			
   Allnum[753].sub = name753_sub;
   Allnum[753].type = name753_type;
#endif


#if(All_Count >= 755)
   strcpy(Allnum[754].name, name754);
   Allnum[754].va = (uint16_t*)&(name754_value);			
   Allnum[754].sub = name754_sub;
   Allnum[754].type = name754_type;
#endif


#if(All_Count >= 756)
   strcpy(Allnum[755].name, name755);
   Allnum[755].va = (uint16_t*)&(name755_value);			
   Allnum[755].sub = name755_sub;
   Allnum[755].type = name755_type;
#endif


#if(All_Count >= 757)
   strcpy(Allnum[756].name, name756);
   Allnum[756].va = (uint16_t*)&(name756_value);			
   Allnum[756].sub = name756_sub;
   Allnum[756].type = name756_type;
#endif


#if(All_Count >= 758)
   strcpy(Allnum[757].name, name757);
   Allnum[757].va = (uint16_t*)&(name757_value);			
   Allnum[757].sub = name757_sub;
   Allnum[757].type = name757_type;
#endif


#if(All_Count >= 759)
   strcpy(Allnum[758].name, name758);
   Allnum[758].va = (uint16_t*)&(name758_value);			
   Allnum[758].sub = name758_sub;
   Allnum[758].type = name758_type;
#endif


#if(All_Count >= 760)
   strcpy(Allnum[759].name, name759);
   Allnum[759].va = (uint16_t*)&(name759_value);			
   Allnum[759].sub = name759_sub;
   Allnum[759].type = name759_type;
#endif


#if(All_Count >= 761)
   strcpy(Allnum[760].name, name760);
   Allnum[760].va = (uint16_t*)&(name760_value);			
   Allnum[760].sub = name760_sub;
   Allnum[760].type = name760_type;
#endif


#if(All_Count >= 762)
   strcpy(Allnum[761].name, name761);
   Allnum[761].va = (uint16_t*)&(name761_value);			
   Allnum[761].sub = name761_sub;
   Allnum[761].type = name761_type;
#endif


#if(All_Count >= 763)
   strcpy(Allnum[762].name, name762);
   Allnum[762].va = (uint16_t*)&(name762_value);			
   Allnum[762].sub = name762_sub;
   Allnum[762].type = name762_type;
#endif


#if(All_Count >= 764)
   strcpy(Allnum[763].name, name763);
   Allnum[763].va = (uint16_t*)&(name763_value);			
   Allnum[763].sub = name763_sub;
   Allnum[763].type = name763_type;
#endif


#if(All_Count >= 765)
   strcpy(Allnum[764].name, name764);
   Allnum[764].va = (uint16_t*)&(name764_value);			
   Allnum[764].sub = name764_sub;
   Allnum[764].type = name764_type;
#endif


#if(All_Count >= 766)
   strcpy(Allnum[765].name, name765);
   Allnum[765].va = (uint16_t*)&(name765_value);			
   Allnum[765].sub = name765_sub;
   Allnum[765].type = name765_type;
#endif


#if(All_Count >= 767)
   strcpy(Allnum[766].name, name766);
   Allnum[766].va = (uint16_t*)&(name766_value);			
   Allnum[766].sub = name766_sub;
   Allnum[766].type = name766_type;
#endif


#if(All_Count >= 768)
   strcpy(Allnum[767].name, name767);
   Allnum[767].va = (uint16_t*)&(name767_value);			
   Allnum[767].sub = name767_sub;
   Allnum[767].type = name767_type;
#endif


#if(All_Count >= 769)
   strcpy(Allnum[768].name, name768);
   Allnum[768].va = (uint16_t*)&(name768_value);			
   Allnum[768].sub = name768_sub;
   Allnum[768].type = name768_type;
#endif


#if(All_Count >= 770)
   strcpy(Allnum[769].name, name769);
   Allnum[769].va = (uint16_t*)&(name769_value);			
   Allnum[769].sub = name769_sub;
   Allnum[769].type = name769_type;
#endif


#if(All_Count >= 771)
   strcpy(Allnum[770].name, name770);
   Allnum[770].va = (uint16_t*)&(name770_value);			
   Allnum[770].sub = name770_sub;
   Allnum[770].type = name770_type;
#endif


#if(All_Count >= 772)
   strcpy(Allnum[771].name, name771);
   Allnum[771].va = (uint16_t*)&(name771_value);			
   Allnum[771].sub = name771_sub;
   Allnum[771].type = name771_type;
#endif


#if(All_Count >= 773)
   strcpy(Allnum[772].name, name772);
   Allnum[772].va = (uint16_t*)&(name772_value);			
   Allnum[772].sub = name772_sub;
   Allnum[772].type = name772_type;
#endif


#if(All_Count >= 774)
   strcpy(Allnum[773].name, name773);
   Allnum[773].va = (uint16_t*)&(name773_value);			
   Allnum[773].sub = name773_sub;
   Allnum[773].type = name773_type;
#endif


#if(All_Count >= 775)
   strcpy(Allnum[774].name, name774);
   Allnum[774].va = (uint16_t*)&(name774_value);			
   Allnum[774].sub = name774_sub;
   Allnum[774].type = name774_type;
#endif


#if(All_Count >= 776)
   strcpy(Allnum[775].name, name775);
   Allnum[775].va = (uint16_t*)&(name775_value);			
   Allnum[775].sub = name775_sub;
   Allnum[775].type = name775_type;
#endif


#if(All_Count >= 777)
   strcpy(Allnum[776].name, name776);
   Allnum[776].va = (uint16_t*)&(name776_value);			
   Allnum[776].sub = name776_sub;
   Allnum[776].type = name776_type;
#endif


#if(All_Count >= 778)
   strcpy(Allnum[777].name, name777);
   Allnum[777].va = (uint16_t*)&(name777_value);			
   Allnum[777].sub = name777_sub;
   Allnum[777].type = name777_type;
#endif


#if(All_Count >= 779)
   strcpy(Allnum[778].name, name778);
   Allnum[778].va = (uint16_t*)&(name778_value);			
   Allnum[778].sub = name778_sub;
   Allnum[778].type = name778_type;
#endif


#if(All_Count >= 780)
   strcpy(Allnum[779].name, name779);
   Allnum[779].va = (uint16_t*)&(name779_value);			
   Allnum[779].sub = name779_sub;
   Allnum[779].type = name779_type;
#endif


#if(All_Count >= 781)
   strcpy(Allnum[780].name, name780);
   Allnum[780].va = (uint16_t*)&(name780_value);			
   Allnum[780].sub = name780_sub;
   Allnum[780].type = name780_type;
#endif


#if(All_Count >= 782)
   strcpy(Allnum[781].name, name781);
   Allnum[781].va = (uint16_t*)&(name781_value);			
   Allnum[781].sub = name781_sub;
   Allnum[781].type = name781_type;
#endif


#if(All_Count >= 783)
   strcpy(Allnum[782].name, name782);
   Allnum[782].va = (uint16_t*)&(name782_value);			
   Allnum[782].sub = name782_sub;
   Allnum[782].type = name782_type;
#endif


#if(All_Count >= 784)
   strcpy(Allnum[783].name, name783);
   Allnum[783].va = (uint16_t*)&(name783_value);			
   Allnum[783].sub = name783_sub;
   Allnum[783].type = name783_type;
#endif


#if(All_Count >= 785)
   strcpy(Allnum[784].name, name784);
   Allnum[784].va = (uint16_t*)&(name784_value);			
   Allnum[784].sub = name784_sub;
   Allnum[784].type = name784_type;
#endif


#if(All_Count >= 786)
   strcpy(Allnum[785].name, name785);
   Allnum[785].va = (uint16_t*)&(name785_value);			
   Allnum[785].sub = name785_sub;
   Allnum[785].type = name785_type;
#endif


#if(All_Count >= 787)
   strcpy(Allnum[786].name, name786);
   Allnum[786].va = (uint16_t*)&(name786_value);			
   Allnum[786].sub = name786_sub;
   Allnum[786].type = name786_type;
#endif


#if(All_Count >= 788)
   strcpy(Allnum[787].name, name787);
   Allnum[787].va = (uint16_t*)&(name787_value);			
   Allnum[787].sub = name787_sub;
   Allnum[787].type = name787_type;
#endif


#if(All_Count >= 789)
   strcpy(Allnum[788].name, name788);
   Allnum[788].va = (uint16_t*)&(name788_value);			
   Allnum[788].sub = name788_sub;
   Allnum[788].type = name788_type;
#endif


#if(All_Count >= 790)
   strcpy(Allnum[789].name, name789);
   Allnum[789].va = (uint16_t*)&(name789_value);			
   Allnum[789].sub = name789_sub;
   Allnum[789].type = name789_type;
#endif


#if(All_Count >= 791)
   strcpy(Allnum[790].name, name790);
   Allnum[790].va = (uint16_t*)&(name790_value);			
   Allnum[790].sub = name790_sub;
   Allnum[790].type = name790_type;
#endif


#if(All_Count >= 792)
   strcpy(Allnum[791].name, name791);
   Allnum[791].va = (uint16_t*)&(name791_value);			
   Allnum[791].sub = name791_sub;
   Allnum[791].type = name791_type;
#endif


#if(All_Count >= 793)
   strcpy(Allnum[792].name, name792);
   Allnum[792].va = (uint16_t*)&(name792_value);			
   Allnum[792].sub = name792_sub;
   Allnum[792].type = name792_type;
#endif


#if(All_Count >= 794)
   strcpy(Allnum[793].name, name793);
   Allnum[793].va = (uint16_t*)&(name793_value);			
   Allnum[793].sub = name793_sub;
   Allnum[793].type = name793_type;
#endif


#if(All_Count >= 795)
   strcpy(Allnum[794].name, name794);
   Allnum[794].va = (uint16_t*)&(name794_value);			
   Allnum[794].sub = name794_sub;
   Allnum[794].type = name794_type;
#endif


#if(All_Count >= 796)
   strcpy(Allnum[795].name, name795);
   Allnum[795].va = (uint16_t*)&(name795_value);			
   Allnum[795].sub = name795_sub;
   Allnum[795].type = name795_type;
#endif


#if(All_Count >= 797)
   strcpy(Allnum[796].name, name796);
   Allnum[796].va = (uint16_t*)&(name796_value);			
   Allnum[796].sub = name796_sub;
   Allnum[796].type = name796_type;
#endif


#if(All_Count >= 798)
   strcpy(Allnum[797].name, name797);
   Allnum[797].va = (uint16_t*)&(name797_value);			
   Allnum[797].sub = name797_sub;
   Allnum[797].type = name797_type;
#endif


#if(All_Count >= 799)
   strcpy(Allnum[798].name, name798);
   Allnum[798].va = (uint16_t*)&(name798_value);			
   Allnum[798].sub = name798_sub;
   Allnum[798].type = name798_type;
#endif


#if(All_Count >= 800)
   strcpy(Allnum[799].name, name799);
   Allnum[799].va = (uint16_t*)&(name799_value);			
   Allnum[799].sub = name799_sub;
   Allnum[799].type = name799_type;
#endif


#if(All_Count >= 801)
   strcpy(Allnum[800].name, name800);
   Allnum[800].va = (uint16_t*)&(name800_value);			
   Allnum[800].sub = name800_sub;
   Allnum[800].type = name800_type;
#endif


#if(All_Count >= 802)
   strcpy(Allnum[801].name, name801);
   Allnum[801].va = (uint16_t*)&(name801_value);			
   Allnum[801].sub = name801_sub;
   Allnum[801].type = name801_type;
#endif


#if(All_Count >= 803)
   strcpy(Allnum[802].name, name802);
   Allnum[802].va = (uint16_t*)&(name802_value);			
   Allnum[802].sub = name802_sub;
   Allnum[802].type = name802_type;
#endif


#if(All_Count >= 804)
   strcpy(Allnum[803].name, name803);
   Allnum[803].va = (uint16_t*)&(name803_value);			
   Allnum[803].sub = name803_sub;
   Allnum[803].type = name803_type;
#endif


#if(All_Count >= 805)
   strcpy(Allnum[804].name, name804);
   Allnum[804].va = (uint16_t*)&(name804_value);			
   Allnum[804].sub = name804_sub;
   Allnum[804].type = name804_type;
#endif


#if(All_Count >= 806)
   strcpy(Allnum[805].name, name805);
   Allnum[805].va = (uint16_t*)&(name805_value);			
   Allnum[805].sub = name805_sub;
   Allnum[805].type = name805_type;
#endif


#if(All_Count >= 807)
   strcpy(Allnum[806].name, name806);
   Allnum[806].va = (uint16_t*)&(name806_value);			
   Allnum[806].sub = name806_sub;
   Allnum[806].type = name806_type;
#endif


#if(All_Count >= 808)
   strcpy(Allnum[807].name, name807);
   Allnum[807].va = (uint16_t*)&(name807_value);			
   Allnum[807].sub = name807_sub;
   Allnum[807].type = name807_type;
#endif


#if(All_Count >= 809)
   strcpy(Allnum[808].name, name808);
   Allnum[808].va = (uint16_t*)&(name808_value);			
   Allnum[808].sub = name808_sub;
   Allnum[808].type = name808_type;
#endif


#if(All_Count >= 810)
   strcpy(Allnum[809].name, name809);
   Allnum[809].va = (uint16_t*)&(name809_value);			
   Allnum[809].sub = name809_sub;
   Allnum[809].type = name809_type;
#endif


#if(All_Count >= 811)
   strcpy(Allnum[810].name, name810);
   Allnum[810].va = (uint16_t*)&(name810_value);			
   Allnum[810].sub = name810_sub;
   Allnum[810].type = name810_type;
#endif


#if(All_Count >= 812)
   strcpy(Allnum[811].name, name811);
   Allnum[811].va = (uint16_t*)&(name811_value);			
   Allnum[811].sub = name811_sub;
   Allnum[811].type = name811_type;
#endif


#if(All_Count >= 813)
   strcpy(Allnum[812].name, name812);
   Allnum[812].va = (uint16_t*)&(name812_value);			
   Allnum[812].sub = name812_sub;
   Allnum[812].type = name812_type;
#endif


#if(All_Count >= 814)
   strcpy(Allnum[813].name, name813);
   Allnum[813].va = (uint16_t*)&(name813_value);			
   Allnum[813].sub = name813_sub;
   Allnum[813].type = name813_type;
#endif


#if(All_Count >= 815)
   strcpy(Allnum[814].name, name814);
   Allnum[814].va = (uint16_t*)&(name814_value);			
   Allnum[814].sub = name814_sub;
   Allnum[814].type = name814_type;
#endif


#if(All_Count >= 816)
   strcpy(Allnum[815].name, name815);
   Allnum[815].va = (uint16_t*)&(name815_value);			
   Allnum[815].sub = name815_sub;
   Allnum[815].type = name815_type;
#endif


#if(All_Count >= 817)
   strcpy(Allnum[816].name, name816);
   Allnum[816].va = (uint16_t*)&(name816_value);			
   Allnum[816].sub = name816_sub;
   Allnum[816].type = name816_type;
#endif


#if(All_Count >= 818)
   strcpy(Allnum[817].name, name817);
   Allnum[817].va = (uint16_t*)&(name817_value);			
   Allnum[817].sub = name817_sub;
   Allnum[817].type = name817_type;
#endif


#if(All_Count >= 819)
   strcpy(Allnum[818].name, name818);
   Allnum[818].va = (uint16_t*)&(name818_value);			
   Allnum[818].sub = name818_sub;
   Allnum[818].type = name818_type;
#endif


#if(All_Count >= 820)
   strcpy(Allnum[819].name, name819);
   Allnum[819].va = (uint16_t*)&(name819_value);			
   Allnum[819].sub = name819_sub;
   Allnum[819].type = name819_type;
#endif


#if(All_Count >= 821)
   strcpy(Allnum[820].name, name820);
   Allnum[820].va = (uint16_t*)&(name820_value);			
   Allnum[820].sub = name820_sub;
   Allnum[820].type = name820_type;
#endif


#if(All_Count >= 822)
   strcpy(Allnum[821].name, name821);
   Allnum[821].va = (uint16_t*)&(name821_value);			
   Allnum[821].sub = name821_sub;
   Allnum[821].type = name821_type;
#endif


#if(All_Count >= 823)
   strcpy(Allnum[822].name, name822);
   Allnum[822].va = (uint16_t*)&(name822_value);			
   Allnum[822].sub = name822_sub;
   Allnum[822].type = name822_type;
#endif


#if(All_Count >= 824)
   strcpy(Allnum[823].name, name823);
   Allnum[823].va = (uint16_t*)&(name823_value);			
   Allnum[823].sub = name823_sub;
   Allnum[823].type = name823_type;
#endif


#if(All_Count >= 825)
   strcpy(Allnum[824].name, name824);
   Allnum[824].va = (uint16_t*)&(name824_value);			
   Allnum[824].sub = name824_sub;
   Allnum[824].type = name824_type;
#endif


#if(All_Count >= 826)
   strcpy(Allnum[825].name, name825);
   Allnum[825].va = (uint16_t*)&(name825_value);			
   Allnum[825].sub = name825_sub;
   Allnum[825].type = name825_type;
#endif


#if(All_Count >= 827)
   strcpy(Allnum[826].name, name826);
   Allnum[826].va = (uint16_t*)&(name826_value);			
   Allnum[826].sub = name826_sub;
   Allnum[826].type = name826_type;
#endif


#if(All_Count >= 828)
   strcpy(Allnum[827].name, name827);
   Allnum[827].va = (uint16_t*)&(name827_value);			
   Allnum[827].sub = name827_sub;
   Allnum[827].type = name827_type;
#endif


#if(All_Count >= 829)
   strcpy(Allnum[828].name, name828);
   Allnum[828].va = (uint16_t*)&(name828_value);			
   Allnum[828].sub = name828_sub;
   Allnum[828].type = name828_type;
#endif


#if(All_Count >= 830)
   strcpy(Allnum[829].name, name829);
   Allnum[829].va = (uint16_t*)&(name829_value);			
   Allnum[829].sub = name829_sub;
   Allnum[829].type = name829_type;
#endif


#if(All_Count >= 831)
   strcpy(Allnum[830].name, name830);
   Allnum[830].va = (uint16_t*)&(name830_value);			
   Allnum[830].sub = name830_sub;
   Allnum[830].type = name830_type;
#endif


#if(All_Count >= 832)
   strcpy(Allnum[831].name, name831);
   Allnum[831].va = (uint16_t*)&(name831_value);			
   Allnum[831].sub = name831_sub;
   Allnum[831].type = name831_type;
#endif


#if(All_Count >= 833)
   strcpy(Allnum[832].name, name832);
   Allnum[832].va = (uint16_t*)&(name832_value);			
   Allnum[832].sub = name832_sub;
   Allnum[832].type = name832_type;
#endif


#if(All_Count >= 834)
   strcpy(Allnum[833].name, name833);
   Allnum[833].va = (uint16_t*)&(name833_value);			
   Allnum[833].sub = name833_sub;
   Allnum[833].type = name833_type;
#endif


#if(All_Count >= 835)
   strcpy(Allnum[834].name, name834);
   Allnum[834].va = (uint16_t*)&(name834_value);			
   Allnum[834].sub = name834_sub;
   Allnum[834].type = name834_type;
#endif


#if(All_Count >= 836)
   strcpy(Allnum[835].name, name835);
   Allnum[835].va = (uint16_t*)&(name835_value);			
   Allnum[835].sub = name835_sub;
   Allnum[835].type = name835_type;
#endif


#if(All_Count >= 837)
   strcpy(Allnum[836].name, name836);
   Allnum[836].va = (uint16_t*)&(name836_value);			
   Allnum[836].sub = name836_sub;
   Allnum[836].type = name836_type;
#endif


#if(All_Count >= 838)
   strcpy(Allnum[837].name, name837);
   Allnum[837].va = (uint16_t*)&(name837_value);			
   Allnum[837].sub = name837_sub;
   Allnum[837].type = name837_type;
#endif


#if(All_Count >= 839)
   strcpy(Allnum[838].name, name838);
   Allnum[838].va = (uint16_t*)&(name838_value);			
   Allnum[838].sub = name838_sub;
   Allnum[838].type = name838_type;
#endif


#if(All_Count >= 840)
   strcpy(Allnum[839].name, name839);
   Allnum[839].va = (uint16_t*)&(name839_value);			
   Allnum[839].sub = name839_sub;
   Allnum[839].type = name839_type;
#endif


#if(All_Count >= 841)
   strcpy(Allnum[840].name, name840);
   Allnum[840].va = (uint16_t*)&(name840_value);			
   Allnum[840].sub = name840_sub;
   Allnum[840].type = name840_type;
#endif


#if(All_Count >= 842)
   strcpy(Allnum[841].name, name841);
   Allnum[841].va = (uint16_t*)&(name841_value);			
   Allnum[841].sub = name841_sub;
   Allnum[841].type = name841_type;
#endif


#if(All_Count >= 843)
   strcpy(Allnum[842].name, name842);
   Allnum[842].va = (uint16_t*)&(name842_value);			
   Allnum[842].sub = name842_sub;
   Allnum[842].type = name842_type;
#endif


#if(All_Count >= 844)
   strcpy(Allnum[843].name, name843);
   Allnum[843].va = (uint16_t*)&(name843_value);			
   Allnum[843].sub = name843_sub;
   Allnum[843].type = name843_type;
#endif


#if(All_Count >= 845)
   strcpy(Allnum[844].name, name844);
   Allnum[844].va = (uint16_t*)&(name844_value);			
   Allnum[844].sub = name844_sub;
   Allnum[844].type = name844_type;
#endif


#if(All_Count >= 846)
   strcpy(Allnum[845].name, name845);
   Allnum[845].va = (uint16_t*)&(name845_value);			
   Allnum[845].sub = name845_sub;
   Allnum[845].type = name845_type;
#endif


#if(All_Count >= 847)
   strcpy(Allnum[846].name, name846);
   Allnum[846].va = (uint16_t*)&(name846_value);			
   Allnum[846].sub = name846_sub;
   Allnum[846].type = name846_type;
#endif


#if(All_Count >= 848)
   strcpy(Allnum[847].name, name847);
   Allnum[847].va = (uint16_t*)&(name847_value);			
   Allnum[847].sub = name847_sub;
   Allnum[847].type = name847_type;
#endif


#if(All_Count >= 849)
   strcpy(Allnum[848].name, name848);
   Allnum[848].va = (uint16_t*)&(name848_value);			
   Allnum[848].sub = name848_sub;
   Allnum[848].type = name848_type;
#endif


#if(All_Count >= 850)
   strcpy(Allnum[849].name, name849);
   Allnum[849].va = (uint16_t*)&(name849_value);			
   Allnum[849].sub = name849_sub;
   Allnum[849].type = name849_type;
#endif


#if(All_Count >= 851)
   strcpy(Allnum[850].name, name850);
   Allnum[850].va = (uint16_t*)&(name850_value);			
   Allnum[850].sub = name850_sub;
   Allnum[850].type = name850_type;
#endif


#if(All_Count >= 852)
   strcpy(Allnum[851].name, name851);
   Allnum[851].va = (uint16_t*)&(name851_value);			
   Allnum[851].sub = name851_sub;
   Allnum[851].type = name851_type;
#endif


#if(All_Count >= 853)
   strcpy(Allnum[852].name, name852);
   Allnum[852].va = (uint16_t*)&(name852_value);			
   Allnum[852].sub = name852_sub;
   Allnum[852].type = name852_type;
#endif


#if(All_Count >= 854)
   strcpy(Allnum[853].name, name853);
   Allnum[853].va = (uint16_t*)&(name853_value);			
   Allnum[853].sub = name853_sub;
   Allnum[853].type = name853_type;
#endif


#if(All_Count >= 855)
   strcpy(Allnum[854].name, name854);
   Allnum[854].va = (uint16_t*)&(name854_value);			
   Allnum[854].sub = name854_sub;
   Allnum[854].type = name854_type;
#endif


#if(All_Count >= 856)
   strcpy(Allnum[855].name, name855);
   Allnum[855].va = (uint16_t*)&(name855_value);			
   Allnum[855].sub = name855_sub;
   Allnum[855].type = name855_type;
#endif


#if(All_Count >= 857)
   strcpy(Allnum[856].name, name856);
   Allnum[856].va = (uint16_t*)&(name856_value);			
   Allnum[856].sub = name856_sub;
   Allnum[856].type = name856_type;
#endif


#if(All_Count >= 858)
   strcpy(Allnum[857].name, name857);
   Allnum[857].va = (uint16_t*)&(name857_value);			
   Allnum[857].sub = name857_sub;
   Allnum[857].type = name857_type;
#endif


#if(All_Count >= 859)
   strcpy(Allnum[858].name, name858);
   Allnum[858].va = (uint16_t*)&(name858_value);			
   Allnum[858].sub = name858_sub;
   Allnum[858].type = name858_type;
#endif


#if(All_Count >= 860)
   strcpy(Allnum[859].name, name859);
   Allnum[859].va = (uint16_t*)&(name859_value);			
   Allnum[859].sub = name859_sub;
   Allnum[859].type = name859_type;
#endif


#if(All_Count >= 861)
   strcpy(Allnum[860].name, name860);
   Allnum[860].va = (uint16_t*)&(name860_value);			
   Allnum[860].sub = name860_sub;
   Allnum[860].type = name860_type;
#endif


#if(All_Count >= 862)
   strcpy(Allnum[861].name, name861);
   Allnum[861].va = (uint16_t*)&(name861_value);			
   Allnum[861].sub = name861_sub;
   Allnum[861].type = name861_type;
#endif


#if(All_Count >= 863)
   strcpy(Allnum[862].name, name862);
   Allnum[862].va = (uint16_t*)&(name862_value);			
   Allnum[862].sub = name862_sub;
   Allnum[862].type = name862_type;
#endif


#if(All_Count >= 864)
   strcpy(Allnum[863].name, name863);
   Allnum[863].va = (uint16_t*)&(name863_value);			
   Allnum[863].sub = name863_sub;
   Allnum[863].type = name863_type;
#endif


#if(All_Count >= 865)
   strcpy(Allnum[864].name, name864);
   Allnum[864].va = (uint16_t*)&(name864_value);			
   Allnum[864].sub = name864_sub;
   Allnum[864].type = name864_type;
#endif


#if(All_Count >= 866)
   strcpy(Allnum[865].name, name865);
   Allnum[865].va = (uint16_t*)&(name865_value);			
   Allnum[865].sub = name865_sub;
   Allnum[865].type = name865_type;
#endif


#if(All_Count >= 867)
   strcpy(Allnum[866].name, name866);
   Allnum[866].va = (uint16_t*)&(name866_value);			
   Allnum[866].sub = name866_sub;
   Allnum[866].type = name866_type;
#endif


#if(All_Count >= 868)
   strcpy(Allnum[867].name, name867);
   Allnum[867].va = (uint16_t*)&(name867_value);			
   Allnum[867].sub = name867_sub;
   Allnum[867].type = name867_type;
#endif


#if(All_Count >= 869)
   strcpy(Allnum[868].name, name868);
   Allnum[868].va = (uint16_t*)&(name868_value);			
   Allnum[868].sub = name868_sub;
   Allnum[868].type = name868_type;
#endif


#if(All_Count >= 870)
   strcpy(Allnum[869].name, name869);
   Allnum[869].va = (uint16_t*)&(name869_value);			
   Allnum[869].sub = name869_sub;
   Allnum[869].type = name869_type;
#endif


#if(All_Count >= 871)
   strcpy(Allnum[870].name, name870);
   Allnum[870].va = (uint16_t*)&(name870_value);			
   Allnum[870].sub = name870_sub;
   Allnum[870].type = name870_type;
#endif


#if(All_Count >= 872)
   strcpy(Allnum[871].name, name871);
   Allnum[871].va = (uint16_t*)&(name871_value);			
   Allnum[871].sub = name871_sub;
   Allnum[871].type = name871_type;
#endif


#if(All_Count >= 873)
   strcpy(Allnum[872].name, name872);
   Allnum[872].va = (uint16_t*)&(name872_value);			
   Allnum[872].sub = name872_sub;
   Allnum[872].type = name872_type;
#endif


#if(All_Count >= 874)
   strcpy(Allnum[873].name, name873);
   Allnum[873].va = (uint16_t*)&(name873_value);			
   Allnum[873].sub = name873_sub;
   Allnum[873].type = name873_type;
#endif


#if(All_Count >= 875)
   strcpy(Allnum[874].name, name874);
   Allnum[874].va = (uint16_t*)&(name874_value);			
   Allnum[874].sub = name874_sub;
   Allnum[874].type = name874_type;
#endif


#if(All_Count >= 876)
   strcpy(Allnum[875].name, name875);
   Allnum[875].va = (uint16_t*)&(name875_value);			
   Allnum[875].sub = name875_sub;
   Allnum[875].type = name875_type;
#endif


#if(All_Count >= 877)
   strcpy(Allnum[876].name, name876);
   Allnum[876].va = (uint16_t*)&(name876_value);			
   Allnum[876].sub = name876_sub;
   Allnum[876].type = name876_type;
#endif


#if(All_Count >= 878)
   strcpy(Allnum[877].name, name877);
   Allnum[877].va = (uint16_t*)&(name877_value);			
   Allnum[877].sub = name877_sub;
   Allnum[877].type = name877_type;
#endif


#if(All_Count >= 879)
   strcpy(Allnum[878].name, name878);
   Allnum[878].va = (uint16_t*)&(name878_value);			
   Allnum[878].sub = name878_sub;
   Allnum[878].type = name878_type;
#endif


#if(All_Count >= 880)
   strcpy(Allnum[879].name, name879);
   Allnum[879].va = (uint16_t*)&(name879_value);			
   Allnum[879].sub = name879_sub;
   Allnum[879].type = name879_type;
#endif


#if(All_Count >= 881)
   strcpy(Allnum[880].name, name880);
   Allnum[880].va = (uint16_t*)&(name880_value);			
   Allnum[880].sub = name880_sub;
   Allnum[880].type = name880_type;
#endif


#if(All_Count >= 882)
   strcpy(Allnum[881].name, name881);
   Allnum[881].va = (uint16_t*)&(name881_value);			
   Allnum[881].sub = name881_sub;
   Allnum[881].type = name881_type;
#endif


#if(All_Count >= 883)
   strcpy(Allnum[882].name, name882);
   Allnum[882].va = (uint16_t*)&(name882_value);			
   Allnum[882].sub = name882_sub;
   Allnum[882].type = name882_type;
#endif


#if(All_Count >= 884)
   strcpy(Allnum[883].name, name883);
   Allnum[883].va = (uint16_t*)&(name883_value);			
   Allnum[883].sub = name883_sub;
   Allnum[883].type = name883_type;
#endif


#if(All_Count >= 885)
   strcpy(Allnum[884].name, name884);
   Allnum[884].va = (uint16_t*)&(name884_value);			
   Allnum[884].sub = name884_sub;
   Allnum[884].type = name884_type;
#endif


#if(All_Count >= 886)
   strcpy(Allnum[885].name, name885);
   Allnum[885].va = (uint16_t*)&(name885_value);			
   Allnum[885].sub = name885_sub;
   Allnum[885].type = name885_type;
#endif


#if(All_Count >= 887)
   strcpy(Allnum[886].name, name886);
   Allnum[886].va = (uint16_t*)&(name886_value);			
   Allnum[886].sub = name886_sub;
   Allnum[886].type = name886_type;
#endif


#if(All_Count >= 888)
   strcpy(Allnum[887].name, name887);
   Allnum[887].va = (uint16_t*)&(name887_value);			
   Allnum[887].sub = name887_sub;
   Allnum[887].type = name887_type;
#endif


#if(All_Count >= 889)
   strcpy(Allnum[888].name, name888);
   Allnum[888].va = (uint16_t*)&(name888_value);			
   Allnum[888].sub = name888_sub;
   Allnum[888].type = name888_type;
#endif


#if(All_Count >= 890)
   strcpy(Allnum[889].name, name889);
   Allnum[889].va = (uint16_t*)&(name889_value);			
   Allnum[889].sub = name889_sub;
   Allnum[889].type = name889_type;
#endif


#if(All_Count >= 891)
   strcpy(Allnum[890].name, name890);
   Allnum[890].va = (uint16_t*)&(name890_value);			
   Allnum[890].sub = name890_sub;
   Allnum[890].type = name890_type;
#endif


#if(All_Count >= 892)
   strcpy(Allnum[891].name, name891);
   Allnum[891].va = (uint16_t*)&(name891_value);			
   Allnum[891].sub = name891_sub;
   Allnum[891].type = name891_type;
#endif


#if(All_Count >= 893)
   strcpy(Allnum[892].name, name892);
   Allnum[892].va = (uint16_t*)&(name892_value);			
   Allnum[892].sub = name892_sub;
   Allnum[892].type = name892_type;
#endif


#if(All_Count >= 894)
   strcpy(Allnum[893].name, name893);
   Allnum[893].va = (uint16_t*)&(name893_value);			
   Allnum[893].sub = name893_sub;
   Allnum[893].type = name893_type;
#endif


#if(All_Count >= 895)
   strcpy(Allnum[894].name, name894);
   Allnum[894].va = (uint16_t*)&(name894_value);			
   Allnum[894].sub = name894_sub;
   Allnum[894].type = name894_type;
#endif


#if(All_Count >= 896)
   strcpy(Allnum[895].name, name895);
   Allnum[895].va = (uint16_t*)&(name895_value);			
   Allnum[895].sub = name895_sub;
   Allnum[895].type = name895_type;
#endif


#if(All_Count >= 897)
   strcpy(Allnum[896].name, name896);
   Allnum[896].va = (uint16_t*)&(name896_value);			
   Allnum[896].sub = name896_sub;
   Allnum[896].type = name896_type;
#endif


#if(All_Count >= 898)
   strcpy(Allnum[897].name, name897);
   Allnum[897].va = (uint16_t*)&(name897_value);			
   Allnum[897].sub = name897_sub;
   Allnum[897].type = name897_type;
#endif


#if(All_Count >= 899)
   strcpy(Allnum[898].name, name898);
   Allnum[898].va = (uint16_t*)&(name898_value);			
   Allnum[898].sub = name898_sub;
   Allnum[898].type = name898_type;
#endif


#if(All_Count >= 900)
   strcpy(Allnum[899].name, name899);
   Allnum[899].va = (uint16_t*)&(name899_value);			
   Allnum[899].sub = name899_sub;
   Allnum[899].type = name899_type;
#endif


#if(All_Count >= 901)
   strcpy(Allnum[900].name, name900);
   Allnum[900].va = (uint16_t*)&(name900_value);			
   Allnum[900].sub = name900_sub;
   Allnum[900].type = name900_type;
#endif


#if(All_Count >= 902)
   strcpy(Allnum[901].name, name901);
   Allnum[901].va = (uint16_t*)&(name901_value);			
   Allnum[901].sub = name901_sub;
   Allnum[901].type = name901_type;
#endif


#if(All_Count >= 903)
   strcpy(Allnum[902].name, name902);
   Allnum[902].va = (uint16_t*)&(name902_value);			
   Allnum[902].sub = name902_sub;
   Allnum[902].type = name902_type;
#endif


#if(All_Count >= 904)
   strcpy(Allnum[903].name, name903);
   Allnum[903].va = (uint16_t*)&(name903_value);			
   Allnum[903].sub = name903_sub;
   Allnum[903].type = name903_type;
#endif


#if(All_Count >= 905)
   strcpy(Allnum[904].name, name904);
   Allnum[904].va = (uint16_t*)&(name904_value);			
   Allnum[904].sub = name904_sub;
   Allnum[904].type = name904_type;
#endif


#if(All_Count >= 906)
   strcpy(Allnum[905].name, name905);
   Allnum[905].va = (uint16_t*)&(name905_value);			
   Allnum[905].sub = name905_sub;
   Allnum[905].type = name905_type;
#endif


#if(All_Count >= 907)
   strcpy(Allnum[906].name, name906);
   Allnum[906].va = (uint16_t*)&(name906_value);			
   Allnum[906].sub = name906_sub;
   Allnum[906].type = name906_type;
#endif


#if(All_Count >= 908)
   strcpy(Allnum[907].name, name907);
   Allnum[907].va = (uint16_t*)&(name907_value);			
   Allnum[907].sub = name907_sub;
   Allnum[907].type = name907_type;
#endif


#if(All_Count >= 909)
   strcpy(Allnum[908].name, name908);
   Allnum[908].va = (uint16_t*)&(name908_value);			
   Allnum[908].sub = name908_sub;
   Allnum[908].type = name908_type;
#endif


#if(All_Count >= 910)
   strcpy(Allnum[909].name, name909);
   Allnum[909].va = (uint16_t*)&(name909_value);			
   Allnum[909].sub = name909_sub;
   Allnum[909].type = name909_type;
#endif


#if(All_Count >= 911)
   strcpy(Allnum[910].name, name910);
   Allnum[910].va = (uint16_t*)&(name910_value);			
   Allnum[910].sub = name910_sub;
   Allnum[910].type = name910_type;
#endif


#if(All_Count >= 912)
   strcpy(Allnum[911].name, name911);
   Allnum[911].va = (uint16_t*)&(name911_value);			
   Allnum[911].sub = name911_sub;
   Allnum[911].type = name911_type;
#endif


#if(All_Count >= 913)
   strcpy(Allnum[912].name, name912);
   Allnum[912].va = (uint16_t*)&(name912_value);			
   Allnum[912].sub = name912_sub;
   Allnum[912].type = name912_type;
#endif


#if(All_Count >= 914)
   strcpy(Allnum[913].name, name913);
   Allnum[913].va = (uint16_t*)&(name913_value);			
   Allnum[913].sub = name913_sub;
   Allnum[913].type = name913_type;
#endif


#if(All_Count >= 915)
   strcpy(Allnum[914].name, name914);
   Allnum[914].va = (uint16_t*)&(name914_value);			
   Allnum[914].sub = name914_sub;
   Allnum[914].type = name914_type;
#endif


#if(All_Count >= 916)
   strcpy(Allnum[915].name, name915);
   Allnum[915].va = (uint16_t*)&(name915_value);			
   Allnum[915].sub = name915_sub;
   Allnum[915].type = name915_type;
#endif


#if(All_Count >= 917)
   strcpy(Allnum[916].name, name916);
   Allnum[916].va = (uint16_t*)&(name916_value);			
   Allnum[916].sub = name916_sub;
   Allnum[916].type = name916_type;
#endif


#if(All_Count >= 918)
   strcpy(Allnum[917].name, name917);
   Allnum[917].va = (uint16_t*)&(name917_value);			
   Allnum[917].sub = name917_sub;
   Allnum[917].type = name917_type;
#endif


#if(All_Count >= 919)
   strcpy(Allnum[918].name, name918);
   Allnum[918].va = (uint16_t*)&(name918_value);			
   Allnum[918].sub = name918_sub;
   Allnum[918].type = name918_type;
#endif


#if(All_Count >= 920)
   strcpy(Allnum[919].name, name919);
   Allnum[919].va = (uint16_t*)&(name919_value);			
   Allnum[919].sub = name919_sub;
   Allnum[919].type = name919_type;
#endif


#if(All_Count >= 921)
   strcpy(Allnum[920].name, name920);
   Allnum[920].va = (uint16_t*)&(name920_value);			
   Allnum[920].sub = name920_sub;
   Allnum[920].type = name920_type;
#endif


#if(All_Count >= 922)
   strcpy(Allnum[921].name, name921);
   Allnum[921].va = (uint16_t*)&(name921_value);			
   Allnum[921].sub = name921_sub;
   Allnum[921].type = name921_type;
#endif


#if(All_Count >= 923)
   strcpy(Allnum[922].name, name922);
   Allnum[922].va = (uint16_t*)&(name922_value);			
   Allnum[922].sub = name922_sub;
   Allnum[922].type = name922_type;
#endif


#if(All_Count >= 924)
   strcpy(Allnum[923].name, name923);
   Allnum[923].va = (uint16_t*)&(name923_value);			
   Allnum[923].sub = name923_sub;
   Allnum[923].type = name923_type;
#endif


#if(All_Count >= 925)
   strcpy(Allnum[924].name, name924);
   Allnum[924].va = (uint16_t*)&(name924_value);			
   Allnum[924].sub = name924_sub;
   Allnum[924].type = name924_type;
#endif


#if(All_Count >= 926)
   strcpy(Allnum[925].name, name925);
   Allnum[925].va = (uint16_t*)&(name925_value);			
   Allnum[925].sub = name925_sub;
   Allnum[925].type = name925_type;
#endif


#if(All_Count >= 927)
   strcpy(Allnum[926].name, name926);
   Allnum[926].va = (uint16_t*)&(name926_value);			
   Allnum[926].sub = name926_sub;
   Allnum[926].type = name926_type;
#endif


#if(All_Count >= 928)
   strcpy(Allnum[927].name, name927);
   Allnum[927].va = (uint16_t*)&(name927_value);			
   Allnum[927].sub = name927_sub;
   Allnum[927].type = name927_type;
#endif


#if(All_Count >= 929)
   strcpy(Allnum[928].name, name928);
   Allnum[928].va = (uint16_t*)&(name928_value);			
   Allnum[928].sub = name928_sub;
   Allnum[928].type = name928_type;
#endif


#if(All_Count >= 930)
   strcpy(Allnum[929].name, name929);
   Allnum[929].va = (uint16_t*)&(name929_value);			
   Allnum[929].sub = name929_sub;
   Allnum[929].type = name929_type;
#endif


#if(All_Count >= 931)
   strcpy(Allnum[930].name, name930);
   Allnum[930].va = (uint16_t*)&(name930_value);			
   Allnum[930].sub = name930_sub;
   Allnum[930].type = name930_type;
#endif


#if(All_Count >= 932)
   strcpy(Allnum[931].name, name931);
   Allnum[931].va = (uint16_t*)&(name931_value);			
   Allnum[931].sub = name931_sub;
   Allnum[931].type = name931_type;
#endif


#if(All_Count >= 933)
   strcpy(Allnum[932].name, name932);
   Allnum[932].va = (uint16_t*)&(name932_value);			
   Allnum[932].sub = name932_sub;
   Allnum[932].type = name932_type;
#endif


#if(All_Count >= 934)
   strcpy(Allnum[933].name, name933);
   Allnum[933].va = (uint16_t*)&(name933_value);			
   Allnum[933].sub = name933_sub;
   Allnum[933].type = name933_type;
#endif


#if(All_Count >= 935)
   strcpy(Allnum[934].name, name934);
   Allnum[934].va = (uint16_t*)&(name934_value);			
   Allnum[934].sub = name934_sub;
   Allnum[934].type = name934_type;
#endif


#if(All_Count >= 936)
   strcpy(Allnum[935].name, name935);
   Allnum[935].va = (uint16_t*)&(name935_value);			
   Allnum[935].sub = name935_sub;
   Allnum[935].type = name935_type;
#endif


#if(All_Count >= 937)
   strcpy(Allnum[936].name, name936);
   Allnum[936].va = (uint16_t*)&(name936_value);			
   Allnum[936].sub = name936_sub;
   Allnum[936].type = name936_type;
#endif


#if(All_Count >= 938)
   strcpy(Allnum[937].name, name937);
   Allnum[937].va = (uint16_t*)&(name937_value);			
   Allnum[937].sub = name937_sub;
   Allnum[937].type = name937_type;
#endif


#if(All_Count >= 939)
   strcpy(Allnum[938].name, name938);
   Allnum[938].va = (uint16_t*)&(name938_value);			
   Allnum[938].sub = name938_sub;
   Allnum[938].type = name938_type;
#endif


#if(All_Count >= 940)
   strcpy(Allnum[939].name, name939);
   Allnum[939].va = (uint16_t*)&(name939_value);			
   Allnum[939].sub = name939_sub;
   Allnum[939].type = name939_type;
#endif


#if(All_Count >= 941)
   strcpy(Allnum[940].name, name940);
   Allnum[940].va = (uint16_t*)&(name940_value);			
   Allnum[940].sub = name940_sub;
   Allnum[940].type = name940_type;
#endif


#if(All_Count >= 942)
   strcpy(Allnum[941].name, name941);
   Allnum[941].va = (uint16_t*)&(name941_value);			
   Allnum[941].sub = name941_sub;
   Allnum[941].type = name941_type;
#endif


#if(All_Count >= 943)
   strcpy(Allnum[942].name, name942);
   Allnum[942].va = (uint16_t*)&(name942_value);			
   Allnum[942].sub = name942_sub;
   Allnum[942].type = name942_type;
#endif


#if(All_Count >= 944)
   strcpy(Allnum[943].name, name943);
   Allnum[943].va = (uint16_t*)&(name943_value);			
   Allnum[943].sub = name943_sub;
   Allnum[943].type = name943_type;
#endif


#if(All_Count >= 945)
   strcpy(Allnum[944].name, name944);
   Allnum[944].va = (uint16_t*)&(name944_value);			
   Allnum[944].sub = name944_sub;
   Allnum[944].type = name944_type;
#endif


#if(All_Count >= 946)
   strcpy(Allnum[945].name, name945);
   Allnum[945].va = (uint16_t*)&(name945_value);			
   Allnum[945].sub = name945_sub;
   Allnum[945].type = name945_type;
#endif


#if(All_Count >= 947)
   strcpy(Allnum[946].name, name946);
   Allnum[946].va = (uint16_t*)&(name946_value);			
   Allnum[946].sub = name946_sub;
   Allnum[946].type = name946_type;
#endif


#if(All_Count >= 948)
   strcpy(Allnum[947].name, name947);
   Allnum[947].va = (uint16_t*)&(name947_value);			
   Allnum[947].sub = name947_sub;
   Allnum[947].type = name947_type;
#endif


#if(All_Count >= 949)
   strcpy(Allnum[948].name, name948);
   Allnum[948].va = (uint16_t*)&(name948_value);			
   Allnum[948].sub = name948_sub;
   Allnum[948].type = name948_type;
#endif


#if(All_Count >= 950)
   strcpy(Allnum[949].name, name949);
   Allnum[949].va = (uint16_t*)&(name949_value);			
   Allnum[949].sub = name949_sub;
   Allnum[949].type = name949_type;
#endif


#if(All_Count >= 951)
   strcpy(Allnum[950].name, name950);
   Allnum[950].va = (uint16_t*)&(name950_value);			
   Allnum[950].sub = name950_sub;
   Allnum[950].type = name950_type;
#endif


#if(All_Count >= 952)
   strcpy(Allnum[951].name, name951);
   Allnum[951].va = (uint16_t*)&(name951_value);			
   Allnum[951].sub = name951_sub;
   Allnum[951].type = name951_type;
#endif


#if(All_Count >= 953)
   strcpy(Allnum[952].name, name952);
   Allnum[952].va = (uint16_t*)&(name952_value);			
   Allnum[952].sub = name952_sub;
   Allnum[952].type = name952_type;
#endif


#if(All_Count >= 954)
   strcpy(Allnum[953].name, name953);
   Allnum[953].va = (uint16_t*)&(name953_value);			
   Allnum[953].sub = name953_sub;
   Allnum[953].type = name953_type;
#endif


#if(All_Count >= 955)
   strcpy(Allnum[954].name, name954);
   Allnum[954].va = (uint16_t*)&(name954_value);			
   Allnum[954].sub = name954_sub;
   Allnum[954].type = name954_type;
#endif


#if(All_Count >= 956)
   strcpy(Allnum[955].name, name955);
   Allnum[955].va = (uint16_t*)&(name955_value);			
   Allnum[955].sub = name955_sub;
   Allnum[955].type = name955_type;
#endif


#if(All_Count >= 957)
   strcpy(Allnum[956].name, name956);
   Allnum[956].va = (uint16_t*)&(name956_value);			
   Allnum[956].sub = name956_sub;
   Allnum[956].type = name956_type;
#endif


#if(All_Count >= 958)
   strcpy(Allnum[957].name, name957);
   Allnum[957].va = (uint16_t*)&(name957_value);			
   Allnum[957].sub = name957_sub;
   Allnum[957].type = name957_type;
#endif


#if(All_Count >= 959)
   strcpy(Allnum[958].name, name958);
   Allnum[958].va = (uint16_t*)&(name958_value);			
   Allnum[958].sub = name958_sub;
   Allnum[958].type = name958_type;
#endif


#if(All_Count >= 960)
   strcpy(Allnum[959].name, name959);
   Allnum[959].va = (uint16_t*)&(name959_value);			
   Allnum[959].sub = name959_sub;
   Allnum[959].type = name959_type;
#endif


#if(All_Count >= 961)
   strcpy(Allnum[960].name, name960);
   Allnum[960].va = (uint16_t*)&(name960_value);			
   Allnum[960].sub = name960_sub;
   Allnum[960].type = name960_type;
#endif


#if(All_Count >= 962)
   strcpy(Allnum[961].name, name961);
   Allnum[961].va = (uint16_t*)&(name961_value);			
   Allnum[961].sub = name961_sub;
   Allnum[961].type = name961_type;
#endif


#if(All_Count >= 963)
   strcpy(Allnum[962].name, name962);
   Allnum[962].va = (uint16_t*)&(name962_value);			
   Allnum[962].sub = name962_sub;
   Allnum[962].type = name962_type;
#endif


#if(All_Count >= 964)
   strcpy(Allnum[963].name, name963);
   Allnum[963].va = (uint16_t*)&(name963_value);			
   Allnum[963].sub = name963_sub;
   Allnum[963].type = name963_type;
#endif


#if(All_Count >= 965)
   strcpy(Allnum[964].name, name964);
   Allnum[964].va = (uint16_t*)&(name964_value);			
   Allnum[964].sub = name964_sub;
   Allnum[964].type = name964_type;
#endif


#if(All_Count >= 966)
   strcpy(Allnum[965].name, name965);
   Allnum[965].va = (uint16_t*)&(name965_value);			
   Allnum[965].sub = name965_sub;
   Allnum[965].type = name965_type;
#endif


#if(All_Count >= 967)
   strcpy(Allnum[966].name, name966);
   Allnum[966].va = (uint16_t*)&(name966_value);			
   Allnum[966].sub = name966_sub;
   Allnum[966].type = name966_type;
#endif


#if(All_Count >= 968)
   strcpy(Allnum[967].name, name967);
   Allnum[967].va = (uint16_t*)&(name967_value);			
   Allnum[967].sub = name967_sub;
   Allnum[967].type = name967_type;
#endif


#if(All_Count >= 969)
   strcpy(Allnum[968].name, name968);
   Allnum[968].va = (uint16_t*)&(name968_value);			
   Allnum[968].sub = name968_sub;
   Allnum[968].type = name968_type;
#endif


#if(All_Count >= 970)
   strcpy(Allnum[969].name, name969);
   Allnum[969].va = (uint16_t*)&(name969_value);			
   Allnum[969].sub = name969_sub;
   Allnum[969].type = name969_type;
#endif


#if(All_Count >= 971)
   strcpy(Allnum[970].name, name970);
   Allnum[970].va = (uint16_t*)&(name970_value);			
   Allnum[970].sub = name970_sub;
   Allnum[970].type = name970_type;
#endif


#if(All_Count >= 972)
   strcpy(Allnum[971].name, name971);
   Allnum[971].va = (uint16_t*)&(name971_value);			
   Allnum[971].sub = name971_sub;
   Allnum[971].type = name971_type;
#endif


#if(All_Count >= 973)
   strcpy(Allnum[972].name, name972);
   Allnum[972].va = (uint16_t*)&(name972_value);			
   Allnum[972].sub = name972_sub;
   Allnum[972].type = name972_type;
#endif


#if(All_Count >= 974)
   strcpy(Allnum[973].name, name973);
   Allnum[973].va = (uint16_t*)&(name973_value);			
   Allnum[973].sub = name973_sub;
   Allnum[973].type = name973_type;
#endif


#if(All_Count >= 975)
   strcpy(Allnum[974].name, name974);
   Allnum[974].va = (uint16_t*)&(name974_value);			
   Allnum[974].sub = name974_sub;
   Allnum[974].type = name974_type;
#endif


#if(All_Count >= 976)
   strcpy(Allnum[975].name, name975);
   Allnum[975].va = (uint16_t*)&(name975_value);			
   Allnum[975].sub = name975_sub;
   Allnum[975].type = name975_type;
#endif


#if(All_Count >= 977)
   strcpy(Allnum[976].name, name976);
   Allnum[976].va = (uint16_t*)&(name976_value);			
   Allnum[976].sub = name976_sub;
   Allnum[976].type = name976_type;
#endif


#if(All_Count >= 978)
   strcpy(Allnum[977].name, name977);
   Allnum[977].va = (uint16_t*)&(name977_value);			
   Allnum[977].sub = name977_sub;
   Allnum[977].type = name977_type;
#endif


#if(All_Count >= 979)
   strcpy(Allnum[978].name, name978);
   Allnum[978].va = (uint16_t*)&(name978_value);			
   Allnum[978].sub = name978_sub;
   Allnum[978].type = name978_type;
#endif


#if(All_Count >= 980)
   strcpy(Allnum[979].name, name979);
   Allnum[979].va = (uint16_t*)&(name979_value);			
   Allnum[979].sub = name979_sub;
   Allnum[979].type = name979_type;
#endif


#if(All_Count >= 981)
   strcpy(Allnum[980].name, name980);
   Allnum[980].va = (uint16_t*)&(name980_value);			
   Allnum[980].sub = name980_sub;
   Allnum[980].type = name980_type;
#endif


#if(All_Count >= 982)
   strcpy(Allnum[981].name, name981);
   Allnum[981].va = (uint16_t*)&(name981_value);			
   Allnum[981].sub = name981_sub;
   Allnum[981].type = name981_type;
#endif


#if(All_Count >= 983)
   strcpy(Allnum[982].name, name982);
   Allnum[982].va = (uint16_t*)&(name982_value);			
   Allnum[982].sub = name982_sub;
   Allnum[982].type = name982_type;
#endif


#if(All_Count >= 984)
   strcpy(Allnum[983].name, name983);
   Allnum[983].va = (uint16_t*)&(name983_value);			
   Allnum[983].sub = name983_sub;
   Allnum[983].type = name983_type;
#endif


#if(All_Count >= 985)
   strcpy(Allnum[984].name, name984);
   Allnum[984].va = (uint16_t*)&(name984_value);			
   Allnum[984].sub = name984_sub;
   Allnum[984].type = name984_type;
#endif


#if(All_Count >= 986)
   strcpy(Allnum[985].name, name985);
   Allnum[985].va = (uint16_t*)&(name985_value);			
   Allnum[985].sub = name985_sub;
   Allnum[985].type = name985_type;
#endif


#if(All_Count >= 987)
   strcpy(Allnum[986].name, name986);
   Allnum[986].va = (uint16_t*)&(name986_value);			
   Allnum[986].sub = name986_sub;
   Allnum[986].type = name986_type;
#endif


#if(All_Count >= 988)
   strcpy(Allnum[987].name, name987);
   Allnum[987].va = (uint16_t*)&(name987_value);			
   Allnum[987].sub = name987_sub;
   Allnum[987].type = name987_type;
#endif


#if(All_Count >= 989)
   strcpy(Allnum[988].name, name988);
   Allnum[988].va = (uint16_t*)&(name988_value);			
   Allnum[988].sub = name988_sub;
   Allnum[988].type = name988_type;
#endif


#if(All_Count >= 990)
   strcpy(Allnum[989].name, name989);
   Allnum[989].va = (uint16_t*)&(name989_value);			
   Allnum[989].sub = name989_sub;
   Allnum[989].type = name989_type;
#endif


#if(All_Count >= 991)
   strcpy(Allnum[990].name, name990);
   Allnum[990].va = (uint16_t*)&(name990_value);			
   Allnum[990].sub = name990_sub;
   Allnum[990].type = name990_type;
#endif


#if(All_Count >= 992)
   strcpy(Allnum[991].name, name991);
   Allnum[991].va = (uint16_t*)&(name991_value);			
   Allnum[991].sub = name991_sub;
   Allnum[991].type = name991_type;
#endif


#if(All_Count >= 993)
   strcpy(Allnum[992].name, name992);
   Allnum[992].va = (uint16_t*)&(name992_value);			
   Allnum[992].sub = name992_sub;
   Allnum[992].type = name992_type;
#endif


#if(All_Count >= 994)
   strcpy(Allnum[993].name, name993);
   Allnum[993].va = (uint16_t*)&(name993_value);			
   Allnum[993].sub = name993_sub;
   Allnum[993].type = name993_type;
#endif


#if(All_Count >= 995)
   strcpy(Allnum[994].name, name994);
   Allnum[994].va = (uint16_t*)&(name994_value);			
   Allnum[994].sub = name994_sub;
   Allnum[994].type = name994_type;
#endif


#if(All_Count >= 996)
   strcpy(Allnum[995].name, name995);
   Allnum[995].va = (uint16_t*)&(name995_value);			
   Allnum[995].sub = name995_sub;
   Allnum[995].type = name995_type;
#endif


#if(All_Count >= 997)
   strcpy(Allnum[996].name, name996);
   Allnum[996].va = (uint16_t*)&(name996_value);			
   Allnum[996].sub = name996_sub;
   Allnum[996].type = name996_type;
#endif


#if(All_Count >= 998)
   strcpy(Allnum[997].name, name997);
   Allnum[997].va = (uint16_t*)&(name997_value);			
   Allnum[997].sub = name997_sub;
   Allnum[997].type = name997_type;
#endif


#if(All_Count >= 999)
   strcpy(Allnum[998].name, name998);
   Allnum[998].va = (uint16_t*)&(name998_value);			
   Allnum[998].sub = name998_sub;
   Allnum[998].type = name998_type;
#endif


#if(All_Count >= 1000)
   strcpy(Allnum[999].name, name999);
   Allnum[999].va = (uint16_t*)&(name999_value);			
   Allnum[999].sub = name999_sub;
   Allnum[999].type = name999_type;
#endif

#if(All_Count) 
    Display_All();
#endif
}


void Display_All(void)
{
	uint8_t final_hang=0,page=0,i=0;
	
	OLED_Clear();             //清一下屏
	
	while(1)
	{ 
		 
		if(KeyScan() == 6)  
		{
			hang --;								//向上移一行
			if(hang == 0) hang = All_Count;
			OLED_Clear();
		}
		
		if(KeyScan() == 3)
		{
			hang ++;								//向下移一行
			if(hang == (All_Count + 1)) hang = 1;
			OLED_Clear();
		}
		
		if(KeyScan() == 5)
		{
      if(Allnum[hang - 1].type==UINT)
      {
        if(*(Allnum[hang - 1].va) + Allnum[hang - 1].sub <=((1<<16)-1))
        {
		  	   (*(Allnum[hang - 1].va)) = (*(Allnum[hang - 1].va)) + Allnum[hang - 1].sub;//运用差值实行自加
        }
        else
        {
           (*(Allnum[hang - 1].va)) = ((1<<16)-1);//运用差值实行自加
        }
      }
      else
      {
        if(*((int*)Allnum[hang - 1].va) + Allnum[hang - 1].sub<=((1<<15)-1))
        {
		  	   (*(int*)(Allnum[hang - 1].va)) = *((int*)Allnum[hang - 1].va) + Allnum[hang - 1].sub;//运用差值实行自加
        }
        else
        {
           (*(int*)(Allnum[hang - 1].va)) = ((1<<15)-1);//运用差值实行自加
        }
      }
		}
		
		if(KeyScan() == 4)
		{
      if(Allnum[hang - 1].type==UINT)
      {
        if(*(Allnum[hang - 1].va)- Allnum[hang - 1].sub>=0)
        {
			    (*(Allnum[hang - 1].va)) = (*(Allnum[hang - 1].va)) - Allnum[hang - 1].sub;//运用差值实行自减
        }
        else
        {
          (*(Allnum[hang - 1].va)) =0;
        }
      }
      else
      {
        if(*(int*)(Allnum[hang - 1].va)- Allnum[hang - 1].sub>=(-(1<<15)))
        {
          (*(int*)Allnum[hang - 1].va) = (*(int*)Allnum[hang - 1].va) - Allnum[hang - 1].sub;//运用差值实行自减
        }
        else
        {
          (*((int*)Allnum[hang - 1].va)) = (-(1<<15));
        }
      
      }
			//if((*(Allnum[hang - 1].va))>0xF000) (*(Allnum[hang - 1].va))=0;//为了防止变成负数
		}
		
		
		if(KeyScan() == 2)//翻页
		{
			page ++;		//页加一页
			if(page > (All_Count - 1) / 4) page = 0;
			hang = page * 4 + 1;	//页加一后，行指向该页的第一行
			OLED_Clear();
		}
		
		if(KeyScan() == 1)//启动 
		{
			OLED_Clear();
			
			//run=1;
			//OLED_Write_String(1,3,"I want to fly");
			return;
		}
			
		OLED_Write_Char(1,(hang-1)%4*2,43);   //显示箭头


		
		if((All_Count - 1 )/ 4 > (hang - 1)/ 4) //成立说明现在所在的不为最后一页
		{
			page = (hang - 1)/4;
			final_hang = 4;                   //记录该页的行数
		}
		else
		{
			page = (All_Count - 1) / 4;
			final_hang = All_Count%4;
			if(final_hang == 0) final_hang =4;
		}
		
		for(i = 1;i <= final_hang;i++)  //显示该页
		{
			OLED_Write_String(3,(i - 1)*2,(uint8_t*)Allnum[i - 1 + 4 * page].name);
			OLED_Write_String(7,(i - 1)*2,":");
			OLED_Write_Value(8,(i - 1)*2,*(Allnum[i - 1 + 4 * page].va),Allnum[i - 1 + 4 * page].type);
		}

	}

	
}


