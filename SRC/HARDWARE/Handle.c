#include "Handle.h"
#include "shuju.h"
#include "image_processe.h"
#include "extern.h"
#include "motor.h"
#include "math.h"
#include "MK60DN10_cmt.h"
//extern uint8 P_Pixels[Image_H][Image_W];
extern uint8_t data[];
		double center_RealData_P = 0;
        double center_RealData = 100;
        double center_NowData_P = 1;
        double center_Kg;
//		int i,j;
//		int RowNum = 0;
//		int LcrlenBool = 0;//图像截断标志
uint8 colour[2] = {255, 0},black=1,white=0; //0 和 1 分别对应的颜色
//注：山外的摄像头 0 表示 白色，1表示 黑色
extern uint8_t 	threshold;
uint8_t stop_line;

		uint8_t Huan=0;
        uint8_t Last_field_T_center = 100;
        uint8_t Last_field_Center = 100;//上场0行中线值
        uint8_t Last_field_LBlack = 170;
        uint8_t Last_field_RBlack = 35;
        uint8_t Search_sub = 10;//左右线搜索范围区
        uint8_t Right_blank;
        uint8_t Left_blank;
        uint8_t Right_miss;
        uint8_t Left_miss;


        int Left_sub;//左线相隔两行差值
        int Right_sub;//右线相隔两行差值
        float Sub_d;//拟线微分


        uint8_t Turn_left_flag_last = 0;
        uint8_t Turn_right_flag_last = 0;
        uint8_t Turn_line;//拐弯行

        float Turn_K1;//斜率一
        float Turn_K2;//斜率二
        uint8_t Wait_flag = 0;//等待拟线标志


        float Obstacle_slope;


        uint8_t Singlet_right = 0;

        uint8_t Huan_flag_lr [4]=
        {
            1,1,0,0,
        };

        uint8_t First_K = 0;
        int K_average = 0; //两边无线时补线的斜率
        uint8_t Ten_cnt = 0;

        uint8_t Ten_first = 0;
        uint8_t Ten_two_void = 0;
        uint8_t No_black_count = 0;

        uint8_t Out_track_cnt = 0;

        uint8_t Edge_flag = 0;//中线边缘检测标志
        uint8_t Edge_line = 0;

        uint8_t Ramp_flag = 0;
        uint8_t Ramp_in_count = 0;
        uint8_t Ramp_out_count = 50;

        uint8_t Field_count = 0;

        uint8_t BLACK_DISTANCE = 15;
        uint8_t ANGLE_TURN_DISTANCE = 50;

     

        uint8_t fixvalue[70]=
        {
        101,100,99,98,97,96,94,94,92,91,
        90,89,88,86,86,84,83,82,81,80,
        78,77,76,74,73,71,71,70,68,68,
        66,66,64,63,62,61,60,58,58,56,
        55,54,52,51,50,49,47,47,45,43,
        43,41,41,39,38,37,35,35,33,31,
        31,29,27,27,25,23,23,21,20,18,
        };

        uint8_t Search_field [70]=
        {
            28,28,28,27,27,27,26,26,26,25,
            25,25,24,24,24,23,23,23,22,22,
            22,21,21,21,20,20,20,19,19,19,
            18,18,18,17,17,17,16,16,16,15,
            15,15,14,14,14,13,13,13,13,12,
            12,12,11,11,11,10,10,10,9,9,9,
            8,8,8,7,7,7,6,6,6
        };



        uint8_t Centerline_kalman(uint8_t data_now, uint8_t data_last)//中线卡尔曼滤波
        {
            uint8_t center_Q = 2;
            uint8_t center_R = 5;

            center_NowData_P = center_RealData_P + center_Q;
            center_Kg = center_NowData_P * center_NowData_P / (center_NowData_P * center_NowData_P + center_R * center_R);
            center_RealData = ((1 - center_Kg) * data_now + center_Kg * data_last);
            center_RealData_P = (1 - center_Kg) * center_NowData_P;
            return (uint8_t)center_RealData;
        }
        double value_k(double x1, double y1, double x2, double y2)//斜率计算K（x1,y1,x2,y2)
        {
            double k = 0;
            k = (y2 - y1) / (x2 - x1);
            return k;
        }
        uint8_t Pro_value_byte(int value)   //数值越界保护函数 (byte型)
        {
            if (value >= 158)
                value = 158;
            else if (value <= 2)
                value = 2;
            return (uint8_t)value;
        }



        void Centerline_kalman_deal()//中线卡尔曼滤波
        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            //------------------------中线卡尔曼滤波------------------------------------------------
            for (RowNum = 0; RowNum < 60; RowNum++)
            {
                if (RowNum > 0)
                {
                    if (Lcr[RowNum].Center != 255)
                    {
                        Lcr[RowNum].Center = Centerline_kalman(Lcr[RowNum].Center, Lcr[RowNum - 1].Center);
                    }
                }
            }
            // -------------------------------------------------------------------------------------------
        }
        float Xielv(int First_Center, int End_Center, int cha)
        {
            return ((float)(End_Center - First_Center) / cha);

        }
        uint8_t Pro_value_byte_1(int value)   //数值越界保护函数 (byte型)
        {
            if (value >= 70)
                value = 70;
            return (uint8_t)value;
        }
  uint8_t  ryh = 0;
         uint8_t   ryl =0;
          uint8_t  lyl = 0;
          uint8_t lyh = 0;
		     uint8_t  stright_judge = 0;//直道标志位
         uint8_t stright_Left_flag = 0;
         uint8_t stright_Right_flag = 0;
				uint8_t	stright_flag = 0;//计数
		   uint8_t poshu=0;
		uint8_t huanshu=0;
        uint8_t podao = 0;//行扫描
        uint8_t lie;                         //行扫描
      
        uint8_t first_start = 80;            //第一行扫线起点
		  uint8_t First_find_left = 0;         //控制记录第一次左拐弯行//第一次没扫到的线
        uint8_t First_find_right = 0;         //控制记录第一次左拐弯行//第一次没扫到的线
        uint8_t First_turn_left = 0;         //控制记录第一次左拐弯行//第一次没扫到的线
        uint8_t First_yuan_left = 0;         //控制记录第一次左拐弯行//第一次没扫到的线
        uint8_t First_yuan_right = 0;         //控制记录第一次左拐弯行//第一次没扫到的线
        uint8_t First_turn_right = 0;        //控制记录第一次右拐弯行
        uint8_t Turn_left_flag = 0;          //左丢线次数
        uint8_t Turn_right_flag = 0;         //右丢线次数
        uint8_t Turn_left_dui = 0;          //左丢线次数
        uint8_t Turn_right_dui = 0;         //右丢线次数
        uint8_t Left_flag [70];      //有没有扫到 0没有 1有
        uint8_t Right_flag [70];
        uint8_t Width[70];
        uint8_t leftless = 160;
        uint8_t leftmax = 0;
        uint8_t lefthang = 0;
        uint8_t rightless = 0;
        uint8_t rightmax = 160;
        uint8_t righthang = 0;
        uint8_t leftmaxhang = 0;       
        uint8_t rightmaxhang = 0;
      

        /*********************************停车变量****************************************/
        uint8_t Stop = 0;
		uint8_t Stop_found=0;
        uint8_t First_left_start = 0;
        uint8_t First_right_start = 0;


        uint8_t Fabs(int data)
        {
            if (data >= 0)
                return (uint8_t)data;
            else
                return (uint8_t)(-data);

        }
        float Center_variance(uint8_t line) //每行中点偏差的方差
        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            float average;
            float f_sum = 0;
            int sum = 0;
            uint8_t num;

            for (num = 1; num <= line; num++)
            {
                sum = sum + Lcr[num].Center - Lcr[num - 1].Center;
            }
            average = (float)sum / (line - 1);
            for (num = 1; num <= line; num++)
            {
                f_sum = f_sum + (Lcr[num].Center - Lcr[num - 1].Center - average) * (Lcr[num].Center - Lcr[num - 1].Center - average) / (line - 1);
            }
            // setText用户自定义("路径方差" + f_sum);

            return f_sum;
        }
       
        void Image_Init()//把每场图像处理里数据里需要初始化的变量初始化 
        {
			//duanlu=0;
			/*直道参数*/
            stright_flag = 0;
            stright_judge = 0;
            stright_Left_flag = 0;
            stright_Right_flag = 0;
			
            ryh = 0;
            ryl =0;
            lyl = 0;
            lyh = 0;
		
			Stop_found=0;
			leftmaxhang = 0;
            rightmaxhang = 0;
            lefthang = 0;
            leftless = 160;
            leftmax = 0;
            righthang = 0;
            rightless = 0;
            rightmax = 160;
			
      
          
           
           
            Turn_left_flag = 0;
            Turn_right_flag = 0;
            Turn_left_dui = 0;
            Turn_right_dui = 0;
			
			
       
            First_turn_left = 70;
            First_turn_right = 70;
            First_yuan_left = 70;
            First_yuan_right = 70;
			First_find_left = 70;
            First_find_right = 70;
         
      
			
       
        
            for (i = 0; i < 70; i++)
            {
                Left_flag[i] = 0;
                Right_flag[i] = 0;
            }
        
        }
        void ImageProcess()//图像行处理
        {
			
			LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            /******************第一行扫线*******************/
           // #region
			ting[RowNum]=0;
			for (j = 158; j > 0; j--)
                {
					if(P_Pixels[RowNum][ j]==0)
						ting[RowNum]++;
				}
				wu[RowNum]=0;
		
             if (RowNum == 0)
            {
                Lcr[RowNum].LStart = first_start;
                Lcr[RowNum].RStart = first_start;
                Lcr[RowNum].REnd = 2;
                Lcr[RowNum].LEnd = 158;
                
                for (lie = Lcr[RowNum].LStart; lie <= Lcr[RowNum].LEnd; lie++)//左
                {
                    if (P_Pixels[RowNum][lie] == 0 && P_Pixels[RowNum][lie+1] == 0)//黑为0
                    {
                        Left_flag[RowNum] = 1;
                        Lcr[RowNum].LBlack = lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].LEnd + 1)
                {
                    Left_flag[RowNum] = 0;
                    Lcr[RowNum].LBlack = 158;
                    if (Turn_left_flag == 0)
                    {
                       First_turn_left = RowNum;//左丢线首行
                    }
                    Turn_left_flag++;//左丢线次数
                }
                for (lie = Lcr[RowNum].RStart; lie >= Lcr[RowNum].REnd; lie--)//右
                {
                    if (P_Pixels[RowNum][ lie] == 0 && P_Pixels[RowNum][ lie-1] == 0)
                    {
                        Right_flag[RowNum] = 1;
                        Lcr[RowNum].RBlack = lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].REnd - 1)
                {
                    Right_flag[RowNum] = 0;
                    Lcr[RowNum].RBlack = 2;
                    if (Turn_right_flag == 0)
                    {
                       First_turn_right = RowNum;//右丢线首行
                    }
                    Turn_right_flag++;
                }
                Lcr[RowNum].Center = ((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);
                first_start = Lcr[RowNum].Center;
                
            }
       //     #endregion

            /******************其余几行扫线****************/
          //  #region       
            else
            {
                Lcr[RowNum].LStart = Pro_value_byte(Lcr[RowNum - 1].LBlack - 13);
                Lcr[RowNum].RStart = Pro_value_byte(Lcr[RowNum - 1].RBlack + 13);
                Lcr[RowNum].LEnd = Pro_value_byte(Lcr[RowNum - 1].LBlack + 20);
                Lcr[RowNum].REnd = Pro_value_byte(Lcr[RowNum - 1].RBlack - 20);
		
			 if(Huan_Road_flag!=3&&Huan_Road_flag!=33&&Huan_Road_flag!=5&&Huan_Road_flag!=55)
			 {if (Lcr[RowNum-1].RBlack==2)
                    Lcr[RowNum].RStart = Pro_value_byte(Lcr[RowNum - 1].LBlack-30);
                if (Lcr[RowNum - 1].LBlack == 158)
                    Lcr[RowNum].LStart = Pro_value_byte(Lcr[RowNum - 1].RBlack + 30);}
				if(Huan_Road_flag==3||Huan_Road_flag==5)
				{
		
                Lcr[RowNum].LStart = Pro_value_byte(Lcr[RowNum - 1].RBlack + 10);
           
				}
					if(Huan_Road_flag==33||Huan_Road_flag==55)
				{
				  Lcr[RowNum].RStart = Pro_value_byte(Lcr[RowNum - 1].LBlack-10);
      
				
				
				}
                //扫线
               // #region
                for (lie = Lcr[RowNum].LStart; lie <= Lcr[RowNum].LEnd; lie++)
                {
                    if (P_Pixels[RowNum][ lie] == 0 && P_Pixels[RowNum][lie+1] == 0)//左
                    {
                        Left_flag[RowNum] = 1;
                        if (First_find_left == 70)
                            First_find_left = RowNum;//左首次找到线
                        Lcr[RowNum].LBlack = lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].LEnd + 1)
                {
                    Left_flag[RowNum] = 0;
                    Lcr[RowNum].LBlack = 158;
                    if (RowNum > 5 && Turn_left_dui == 0)
                        First_yuan_left = RowNum;//左大于5行后的首次丢线
                    if (RowNum > 5)
                        Turn_left_dui++;
                    if (Turn_left_flag == 0)
                    {
                        First_turn_left = RowNum;
                        
                    }
					if(RowNum<45)
                    Turn_left_flag++;
                   
                }

                for (lie = Lcr[RowNum].RStart; lie >= Lcr[RowNum].REnd; lie--)
                {
                    if (P_Pixels[RowNum][ lie] == 0 && P_Pixels[RowNum][ lie-1] == 0)//右
                    {
                        Right_flag[RowNum] = 1;
                        if (First_find_right == 70)
                            First_find_right = RowNum;//右首次发现行
                        Lcr[RowNum].RBlack = lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].REnd - 1)
                {
                    Right_flag[RowNum] = 0;
                    Lcr[RowNum].RBlack = 2;
                    if (RowNum > 5 && Turn_right_dui == 0)
                        First_yuan_right = RowNum;//右大于5的首次丢线
                    if (RowNum > 5)
                        Turn_right_dui++;
                    if (Turn_right_flag == 0)
                    {
                        First_turn_right = RowNum;
                        
                    }
					if(RowNum<45)
                    Turn_right_flag++;
                    
                }
				
               // #endregion
                Lcr[RowNum].Center = ((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);
                Width[RowNum] = (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack);	//计算本行赛道宽度
				
				
					for (j = Lcr[RowNum-1].LBlack; j > Lcr[RowNum-1].RBlack; j--)
                {
					if(P_Pixels[RowNum][ j]==0)
						wu[RowNum]++;
				}
               if( Width[RowNum]<= Width[RowNum-1]&&Right_flag[RowNum] == 1&& Left_flag[RowNum] == 1)  stright_flag++;
               if (RowNum > 20 && RowNum < 60 )
                {
                    if (leftless >= Lcr[RowNum].LBlack)
                    {
                        leftless = Lcr[RowNum].LBlack;
                        lefthang = RowNum;
                    }
                }
                if (RowNum > 20 && RowNum < 60 )
                {
                    if (rightless <= Lcr[RowNum].RBlack)
                    {
                        rightless = Lcr[RowNum].RBlack;
                        righthang = RowNum;
                    }
                }
              /*  if (RowNum > 40 && RowNum < 70)
                {
                    if (leftmax <= Lcr[RowNum].LBlack)
                    {
                        leftmax = Lcr[RowNum].LBlack;
                        leftmaxhang = RowNum;
                    }
                    if (rightmax >= Lcr[RowNum].RBlack)
                    {
                        rightmax = Lcr[RowNum].RBlack;
                        rightmaxhang = RowNum;
                    }
                }*/
            }
         //   #endregion

           
        }
        void FieldProcess() //图像场处理函数内联
        {
			 float xl;
			LCR  *Lcr=(LCR *)Sent_Data->Lcr;
			/*断路*/
			if((zhangai==0||zhangai==11)&&start==1)
			{
				if(start==1&&DuanLu1==1&&DuanLu2==1&&duanlu==0)duanlu=3;	
				for(RowNum = 15; RowNum < 30; RowNum++)
					if(ting[RowNum]>115&&ting[RowNum-1]>115&&ting[RowNum-2]>115&&ting[4]>115&&ting[5]>115&&duanlu==3 )	{duanlu=1;	}
					if(duanlu==1)			
					{
						for(RowNum = 5; RowNum < 20; RowNum++)
					if(duanlu==1&&DuanLu1==0&&DuanLu1==0&&bianxing==2 )	duanlu=2;	
					}
					if(duanlu==2||duanlu==3)duanlu_shu++;
					if(duanlu_shu>5&&duanlu==3)duanlu=0;
					if(duanlu_shu>30)duanlu=0;
					if(duanlu==0)
						duanlu_shu=0;
			}
			
			/*障碍*/
            for(RowNum = 20; RowNum < 55; RowNum++)
//                 if (zhang==1&&Huan_Road_flag==0&& start==1&&zhidao == 0&&ting[RowNum]>120&&zhangai==0&&Width[RowNum - 3] > 40&&Width[RowNum - 3] <140 &&Lcr[RowNum-3].Center>65&&Lcr[RowNum-3].Center<95&&Lcr[RowNum].LBlack<Lcr[RowNum].RBlack 
//					 &&Lcr[RowNum-3].LBlack>80&&Lcr[RowNum-3].LBlack<150&&Lcr[RowNum-3].RBlack<80&&Lcr[RowNum-3].RBlack>10&&Turn_right_flag<20&&Turn_left_flag<20&&right_wdata<800&&left_wdata<800)
//				
			if (zhang==1&&Huan_Road_flag==0&& start==1&&zhidao == 0&&zhangai==0&&data[RowNum*160+80]<30&&ting[RowNum]>140&&Width[RowNum - 1] > 80 && Lcr[RowNum].RBlack > Lcr[RowNum].LBlack&&right_wdata>200&&left_wdata>200&&right_wdata<700&&left_wdata<700&&Lcr[RowNum-1].Center>65&&Lcr[RowNum-1].Center<95 )
     
 { zhangai = 11;zhangai_hang=RowNum;}
			if(zhangai==11)
				{
					OLED_Write_Num5(10,0,data[(RowNum+5)*160+80]);
					
	
				}
				gray=data[(RowNum+5)*160+80];
			if(zhangai!=0)tushu++;
			if(zhangai==5)chuzhangai++;
			if(zhangai==2)zhangai_shu++;
				if(tushu>5&&zhangai==11)
				{zhangai=0;
				tushu=0;}
			if(tushu==50)
			{
				zhangai=0;
				tushu=0;
			}
		
	
			 /*直道判断*/
            if (stright_flag >= 55)
            {
                stright_judge = 1;
            }
            else
            {
                stright_judge = 0;
            }
            //检验是否为直道
            if (stright_judge == 1)
            {
                for (RowNum = 0; RowNum < 69; RowNum++)
                {
                    if (RowNum % 5 == 0 && RowNum / 5 != 0)
                    {
                        if (value_k(Lcr[RowNum - 5].LBlack, 0, Lcr[RowNum].LBlack, 5) < 0)
                        {
                            stright_Left_flag++;
                        }
                        if (value_k(Lcr[RowNum - 5].RBlack, 0, Lcr[RowNum].RBlack, 5) > 0)
                        {
                            stright_Right_flag++;
                        }
                    }
                }
                if (stright_Left_flag < 9 || stright_Right_flag < 9)
                {
                    stright_judge = 0;
                }
            }
			
			

			 /*圆环*/
			
			
			if(right_wdata>750&&left_wdata>750)
				dahuan++;
			if(dahuan>0||Huan_Road_flag==44||Huan_Road_flag==4||Huan_Road_flag==2||Huan_Road_flag==22)
			{ 
				for (RowNum = 3; RowNum < 65; RowNum++)
				{
				  
				  
						if (Lcr[RowNum-1].RBlack - 20 > Lcr[RowNum - 3].RBlack&&Lcr[RowNum].RBlack - 20 > Lcr[RowNum - 2].RBlack && RowNum > 10 && ryh==0&&Lcr[RowNum-2].LBlack-Lcr[RowNum-4].LBlack<=0&& lyh==0)
						{
							ryh = RowNum;
							ryl = Lcr[RowNum].RBlack;
						}
						if (Lcr[RowNum-1].LBlack + 20 < Lcr[RowNum - 3].LBlack &&Lcr[RowNum].LBlack + 20 < Lcr[RowNum - 2].LBlack && RowNum > 10 && lyh == 0&&Lcr[RowNum-2].RBlack-Lcr[RowNum-4].RBlack>=0&& ryh==0)
						{
							lyh = RowNum;
							lyl = Lcr[RowNum].LBlack;
						}
						
					
						if (Huan_Road_flag==2&&Lcr[RowNum].RBlack - 5 > Lcr[RowNum - 2].RBlack&& ryh==0 )
						{
							ryh = RowNum;
							ryl = Lcr[RowNum].RBlack;
						}
						if (Huan_Road_flag==22&&Lcr[RowNum].LBlack + 5 < Lcr[RowNum - 2].LBlack&& lyh==0 )
						{
							lyh = RowNum;
							lyl = Lcr[RowNum].LBlack;
						}
					
					
					}
				
            }
			
			if(dahuan>0)
				{
					if(ryh!=0)you++;
					if(lyh!=0)zuo++;
				
				}		
			if(dahuan>0)
			{	
			if(right_wdata<600||left_wdata<600)	
			bushi++;
			}
			if(bushi>15)
			{dahuan=0;bushi=0;}
			if(Huan_Road_flag==1||Huan_Road_flag==11)
			{
				
		//	dahuan=0;
			bushi=0;
			}
			
			if(dahuan==1)
			{
				if(lefthang<59&&righthang>lefthang)
				{
					if(Width[lefthang]<80)
						panhuan=1;
					else panhuan=2;
				}
				if(righthang<59&&righthang<lefthang)
				{
					if(Width[righthang]<80)
						panhuan=1;
					else panhuan=2;
				}
				
			}
			 /*右环*/
//			if(you>2&&you>zuo&&dahuan>2&&(Huan_Road_flag==0)&&Turn_right_flag>10&&huan==1)
//				Huan_Road_flag=1;
			
			if(Huan_Road_flag==1&&(right_wdata<800||left_wdata<800)&&Turn_left_flag>15)
				Huan_Road_flag=2;
			
			if(Huan_Road_flag==2&&(Turn_right_flag-Turn_left_flag)>20)
				Huan_Road_flag=3;
			if(turn_angle<-15&&(Huan_Road_flag==2||Huan_Road_flag==1)&&panhuan==1)
				Huan_Road_flag=3;
			if(turn_angle<-20&&(Huan_Road_flag==2||Huan_Road_flag==1)&&panhuan==2)
				Huan_Road_flag=3;
			
			
			if(Huan_Road_flag==3){cishu++;dahuan=0;BBB(0);}
			if(Huan_Road_flag==3&&cishu>5 )
			{	
				for(RowNum=20;RowNum<50;RowNum++)
				if((Lcr[RowNum].LBlack-Lcr[RowNum-3].LBlack>20)&&(Lcr[RowNum-1].LBlack-Lcr[RowNum-4].LBlack>20))
					chuhuankou=1;
			}
			if(Huan_Road_flag==3&&Turn_left_flag>20&&Turn_right_flag>20&&cishu>10)
				Huan_Road_flag=5;
			if(Huan_Road_flag==3&&Turn_left_flag>15&&chuhuankou==1&&cishu>10)
				Huan_Road_flag=5;
			
			if(Huan_Road_flag==5&&Turn_left_flag<2)
				Huan_Road_flag=4;
			
			if(Huan_Road_flag==4)
				chuhuan++;
			
			if(Huan_Road_flag==4&&chuhuan==15)
				{
					Huan_Road_flag=0;
					huanshu=0;
				}
			
			if(Huan_Road_flag==4&&right_wdata<700&&left_wdata<700&&Turn_right_flag<15&&chuhuan>2)	
				{
					Huan_Road_flag=0;
					huanshu=0;
				}
			/*左环*/
//			if(zuo>2&&you<zuo&&dahuan>2&&(Huan_Road_flag==0)&&Turn_left_flag>10&&huan==1)
//				Huan_Road_flag=11;
			
			if(Huan_Road_flag==11&&(right_wdata<800||left_wdata<800)&&Turn_right_flag>15)
				Huan_Road_flag=22;
			
			if(turn_angle>15&&(Huan_Road_flag==22||Huan_Road_flag==11)&&panhuan==1)
				Huan_Road_flag=33;
			if(turn_angle>20&&(Huan_Road_flag==22||Huan_Road_flag==11)&&panhuan==2)
				Huan_Road_flag=33;
			if(Huan_Road_flag==22&&(Turn_left_flag-Turn_right_flag)>20)
				Huan_Road_flag=33;
			
			
			if(Huan_Road_flag==33){cishu++;dahuan=0;BBB(0);}
			if(Huan_Road_flag==33&&cishu>5 )
			{	
				for(RowNum=20;RowNum<50;RowNum++)
				if((Lcr[RowNum].RBlack-Lcr[RowNum-3].RBlack<-20)&&(Lcr[RowNum-1].RBlack-Lcr[RowNum-4].RBlack<-20))
					chuhuankou=1;
			}
			if(Huan_Road_flag==33&&Turn_left_flag>20&&Turn_right_flag>20&&cishu>10)
				Huan_Road_flag=55;
			if(Huan_Road_flag==33&&chuhuankou==1&&Turn_right_flag>15&&cishu>10)
				Huan_Road_flag=55;	
			
			if(Huan_Road_flag==55&&Turn_right_flag<2)
				Huan_Road_flag=44;
			
			if(Huan_Road_flag==44)
				chuhuan++;
			
			if(Huan_Road_flag==44&&right_wdata<700&&left_wdata<700&&Turn_left_flag<15&&chuhuan>2)
				{
					Huan_Road_flag=0;
					huanshu=0;
				}
			
			if(Huan_Road_flag==44&&chuhuan==15)
				{
					Huan_Road_flag=0;
					huanshu=0;
				}
			
			
			if(Huan_Road_flag==0){chuhuan=0;	changshu=0;}
			if(Huan_Road_flag==3||Huan_Road_flag==4||Huan_Road_flag==33||Huan_Road_flag==44||Huan_Road_flag==5||Huan_Road_flag==55)
				huanshu++;
			if (huanshu == 150)
				{ 
					huanshu = 0; 	
					Huan_Road_flag=0;
					panhuan=0;
					turn_angle=0;
				}     
			if(Huan_Road_flag==4||Huan_Road_flag==44||Huan_Road_flag==5||Huan_Road_flag==55)chuhuankou=0;
               



				
			if(Huan_Road_flag==1||Huan_Road_flag==2||Huan_Road_flag==4)lyh=0;
			if(Huan_Road_flag==11||Huan_Road_flag==22||Huan_Road_flag==44)ryh=0;

			
			
			
		
				
			
			
	
	
	
	
	
	
	

	
	

	
	
	



		
	
			/*入环补线*/
			if(Huan_Road_flag!=44&&Huan_Road_flag!=4)
			{  
				if (ryh != 0)
				{ 
					xl = Xielv(Lcr[0].LBlack,ryl, ryh);
					for(RowNum = 0; RowNum < 50; RowNum++)
					{
						Lcr[RowNum].LBlack = Pro_value_byte(xl * (RowNum) + Lcr[0].LBlack);
						Lcr[RowNum].RBlack = 2;
						Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].LBlack + Lcr[RowNum].RBlack) / 2-3);
					}
				
				}
				 if (lyh != 0)
				{ 
					xl = Xielv(Lcr[0].RBlack,lyl, lyh);
					for(RowNum = 0; RowNum < 50; RowNum++)
					{
						Lcr[RowNum].RBlack = Pro_value_byte(xl * (RowNum) + Lcr[0].RBlack);
							Lcr[RowNum].LBlack = 158;
						Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].LBlack + Lcr[RowNum].RBlack) / 2+3);
					}
					
				}
			}
			/*出环补线*/
			if(Huan_Road_flag==44||Huan_Road_flag==4)
				{ 
					if (ryh != 0)
					{ 
						xl = Xielv(Lcr[0].RBlack,ryl, ryh);
						for(RowNum = 0; RowNum < ryh; RowNum++)
						{
							Lcr[RowNum].RBlack = Pro_value_byte(xl * (RowNum) + Lcr[0].RBlack);
							Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].LBlack + Lcr[RowNum].RBlack) / 2);
						}
					
					}
					 if (lyh != 0)
					{ 
						xl = Xielv(Lcr[0].LBlack,lyl, lyh);
						for(RowNum = 0; RowNum < lyh; RowNum++)
						{
							Lcr[RowNum].LBlack = Pro_value_byte(xl * (RowNum) + Lcr[0].LBlack);
							Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].LBlack + Lcr[RowNum].RBlack) / 2);
						}
					
					}
				}
			
				if(Huan_Road_flag==5)
					{
						xl = Xielv(Lcr[1].Center,leftless, lefthang);
						for(RowNum = 0; RowNum < 50; RowNum++)
						{
                 
							Lcr[RowNum].Center = Pro_value_byte(xl * (RowNum) + Lcr[0].Center);
                
						}
					}
				if(Huan_Road_flag==55)
					{
						xl = Xielv(Lcr[1].Center,rightless, righthang);
						for(RowNum = 0; RowNum < 50; RowNum++)
						{
						   
							Lcr[RowNum].Center = Pro_value_byte(xl * (RowNum) + Lcr[0].Center);
						}
					}
    
             
if(Huan_Road_flag!=0&&Huan_Road_flag!=1&&Huan_Road_flag!=11&&Huan_Road_flag!=22&&Huan_Road_flag!=2)dahuan=0;

				if(Huan_Road_flag!=0)
					{
				//	dahuan=0;
					
					zuo=0;
					you=0;
					}
//					else
//						BBB(0);
	
			if(Huan_Road_flag==4||Huan_Road_flag==44||Huan_Road_flag==5||Huan_Road_flag==55){panhuan=0;cishu=0;}
			if((Huan_Road_flag==1||Huan_Road_flag==11||Huan_Road_flag==2||Huan_Road_flag==22)&&panhuan==0)panhuan=2;
//			if(Stop==0&&Width[20]>80&&start==1&&(duanlu==0||duanlu==2)&&zhangai==0&&Huan_Road_flag==0&&zhidao==0&&Turn_right_flag<2&&Turn_left_flag<2)
//			{
//			for(RowNum=20;RowNum<40;RowNum++)
//				
//			{
//				if(Lcr[RowNum].LBlack<Lcr[RowNum].RBlack)
////				for (lie = 50; lie < 120; lie++)
////                {
////                    if (P_Pixels[RowNum][ lie] == 0 && P_Pixels[RowNum][ lie+1] != 0)
////                    {
////                        Stop_found++;
////                    }
////                }
//				//if(Stop_found<=5)Stop_found=0;
//				
//				//else 
//					Stop++;
//			}
//		}
//			
//			 if(Stop >2&&start==1&&(duanlu==0||duanlu==2)&&zhangai==0&&Huan_Road_flag==0&&zhidao==0&&Width[20]>80&&Turn_right_flag<2&&Turn_left_flag<2)
//                {
//                   
//                 //   Stop = 1;
//					BBB(1);
//                 
//                }
//				else{ BBB(0);Stop=0;}
				
        }






         void SignalProcess()//信息处理.left
        {
			LCR  *Lcr=(LCR *)Sent_Data->Lcr;
			int x;
		
			
            Image_Init();//变量初始化 
			
            for (RowNum = 0; RowNum < 70; RowNum++) //循环叠加
            {
                ImageProcess(); //图像行处理 内联函数
                //---------------------------------------------------------------------------------------------------------------
            }

            FieldProcess();//图像场处理函数内联
            Last_field_Center = Lcr[0].Center; //记录上场0行中线
            Last_field_LBlack = Lcr[0].LBlack;
            Last_field_RBlack = Lcr[0].RBlack;
	x =  CarSpeed/10 ;
//	if(Huan_Road_flag==1||Huan_Road_flag==11||Huan_Road_flag==2||Huan_Road_flag==22)
//	{
//  	switch(x)
//	{
//		case 0:  line = 0;/* P = turn_p * 0.1; D_G = turn_d_gyro * 0.1;*/break;
//		case 1:  line = 5;/* P = turn_p * 0.2; D_G = turn_d_gyro * 0.2;*/break;
//		case 2:  line = 10;/* P = turn_p * 0.4; D_G = turn_d_gyro * 0.4;*/break; 
//		case 3:  line = 16;/* P = turn_p * 0.5; D_G = turn_d_gyro * 0.5;*/break;
//		case 4:  line = 17;/* P = turn_p * 0.8; D_G = turn_d_gyro * 0.8;*/break;
//		case 5:  line = 19;break;
//		case 6:  line = 21; break;
//		case 7:  line = 22;break;
//		case 8:  line = 25; break;                                        //17
//		case 9:  line = 29; break;     //31  
//		case 10: line = 32; break;     //33
//		case 11: line = 34; break;     //33
//		case 12: line = 35; break;   //35
//		case 13: line = 35; break;
//		case 14: line = 35; break;
//		case 15: line = 36; break;
//		case 16: line = 37; break;
//		case 17: line = 40; break;
//		case 18: line = 41; break;
//		case 19: line = 42; break;
//		case 20: line = 43; break;
//		case 21: line = 44; break;
//		case 22: line = 45; break;
//		case 23: line = 46; break;

//	 }
 //}
	
if(Huan_Road_flag==5||Huan_Road_flag==55)
	{
line1=25;
	 
	} 
 else if(Huan_Road_flag==4||Huan_Road_flag==44)
	{
  BBB(0);
line1=20;
	 
	}
	else line1=line;
			point=Lcr[line1].Center;	
        }

		int32 range_protect(int32 duty, int32 min, int32 max)//限幅保护
{
	if (duty >= max)
	{
		return max;
	}
	if (duty <= min)
	{
		return min;
	}
	else
	{
		return duty;
	}
}

void image_processe(void)
{
if(run!=0)
{
	SignalProcess();
	
}

}

uint8_t otsuThreshold( uint16 col, uint16 row)
{
    #define GrayScale 256
    uint16 width = col;
    uint16 height = row;




	
    int i, j, pixelSum = width * height;

    uint8 xx = 0;   

	int sum=0;
 
    //统计灰度级中每个像素在整幅图像中的个数  
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {

					sum+=(int)data[i * width + j];
        }
    }
xx=sum/pixelSum;
  

    return xx;
}
	
void tar_speed(void)
{
   
    
    static int16_t error_sum[3];
    
    //直道弯道判断
    //最大车速  0-直道  1-弯道  2-颠簸  3-圆环

    speed_sum += CarSpeed2;
	adc_errorlast=adc_error;
	if(adc_errorlast<0)adc_errorlast=-adc_errorlast;
    if(speed_sum > 3000)
    {
		start=1;
        speed_sum = 0;
        error_sum[2] = error_sum[1];
        error_sum[1] = error_sum[0];
        error_sum[0] = adc_errorlast;
        if((error_sum[0]+error_sum[1]+error_sum[2])<40 && zhidao == 1)       //直道
        {   
            zhidao = 0;
        }
        else if((error_sum[0]+error_sum[1]+error_sum[2])>40 && zhidao == 0)  //弯道
        {   
            zhidao = 1;
        }
    }
    

   
}


