#include "image_processe.h"
#include "extern.h"
#include "motor.h"
#include "math.h"

//int flag=0,flag_chang=0,flag_chang1=0,brake=0;
//uint8_t tingche_flag=1;
//uint16_t ramp_chang_yuzhi=4000;
//uint16_t start_chang=0;
//uint16_t start_chang_yuzhi=1500;
//uint16_t obstacle_chang_yuzhi=35;
//static int ramp_chang=0;
//unsigned int delay_chag=300,delay=250;
//    
//        uint8_t Pro_value_byte(int value)   //???????? (uint8_t?)
//        {
//            if (value >= 158)
//                value = 158;
//            else if (value <= 2)
//                value = 2;
//            return (uint8_t)value;
//        }
//        uint8_t Row_Pro_value_byte(int value)   //???????? (uint8_t?)
//        {
//            if (value >= 69)
//                value = 69;
//            else if (value <= 0)
//                value = 0;
//            return (uint8_t)value;
//        }


//        /***************************************?????****************************************/

//        void Image_Init()//?????????????????????? 
//        {

//            LcrlenBool = 0;//????     
//						Edge_flag = 0;
//            youxiao = 0;
//            //Annular_flag = 0;//?????
//            Annular_flag1 = 0;//?????
//            Turn_left_count = 0;
//            Turn_right_count = 0;
//            Wait_flag = 0;
//            Turn_left_line = 0;
//            Turn_right_line = 0;
//            Turn_left_flag = 0;
//            Turn_right_flag = 0;
//            left_miss_flag = 0;//????????
//            right_miss_flag = 0;//????????
//            left_error_flag = 0;//???????
//            right_error_flag = 0;//???????
//            left_error_line = 0;//?????
//            right_error_line = 0;//?????
//            left_right_line = 0;//?????
//            right_right_line = 0;//?????
//            left_error_cnt = 0;//????????
//            right_transmit_cnt = 0;//???????????
//            left_transmit_cnt = 0;//???????????
//            right_error_cnt = 0;//????????
//            ten_error_cnt = 0;//??????
//            left_line = 0;//???????????
//            right_line = 0;//?????????????
//            left_ten_flag = 0;//?????????
//            right_ten_flag = 0;//?????????
//            left_error_count = 0;//??????
//            right_error_count = 0;//??????
//            start_line = 0;//???????
//            end_line = 0;//???????
//            ratio = 0;//??
//            constant = 0;//??
//            left_right_count = 0;//??????
//            right_right_count = 0;//??????
//            ten_count = 0;//????????
//            ten_line = 0;//???????
//            
//            left_Annular_line = 0;//???????
//            right_Annular_line = 0;//???????
//            Annular_line_cnt = 0;//??????
//            Annular_Lline = 0;//???
//            Annular_Rline = 0;//???
//            left_Annular_count = 0;//?????
//            right_Annular_count = 0;//?????
//            Llose_count = 0;//???????
//            Rlose_count = 0;//???????
//            left_car_line = 0;
//            right_car_line = 0;
//            middle_car_line = 0;
//            Annular_line = 0;//?????
//            Annular_right_cnt = 0;
//            Annular_left_cnt = 0;
//            Out_Annular_line = 0;
//            Out_Annular_cnt = 0;
//            left_Annular_flag = 0;
//            right_Annular_flag = 0;
//            ten_right_cnt = 0;
//            ten_left_cnt = 0;
//						//stop_flag = 0;
//						straight_cnt = 0;
//            Small_S_flag = 0;
//            Small_S_L_cnt = 0;
//            Small_S_R_cnt = 0;
//            black_line = 0;
//            Edge_line_temp = 0;
//						ten_line_flag = 0;
//						obstacle_cnt = 0;
//            obstacle_flag = 0;
//            obstacle_line = 0;
//						Small_s_cnt=0;
//						trend_L_cnt = 0;
//            trend_R_cnt = 0;
//            trend_L_flag = 0;//1?2?
//            trend_R_flag = 0;//1?2?
//						ramp_cnt = 0;
////            ramp_flag = 0;
//						
//            //for (i = 0; i < 70; i++)
//            //{
//            //    Left_flag[i] = 0;
//            //    Right_flag[i] = 0;
//            //    //Lcr[i].LBlack = Lcr[i].RBlack = Lcr[i].Center = 0xFF;
//            //}
//        }
//        float ratio_Calculation(uint8_t start_Row, uint8_t end_Row, uint8_t flag)
//        {
//					LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//            float rat = 0;
//            if (flag == 1)
//            {
//                rat = (float)(Lcr[end_Row].LBlack - Lcr[start_Row].LBlack) / (end_Row - start_Row);//??
//            }
//            if (flag == 2)
//            {
//                rat = (float)(Lcr[start_Row].RBlack - Lcr[end_Row].RBlack) / (start_Row - end_Row);//??
//            }
//            return rat;
//        }
//        int Difference(int a, int b)
//        {
//            int c = 0;
//            if (a >= b)
//            {
//                c = a - b;
//            }
//            if (a < b)
//            {
//                c = b - a;
//            }
//            return c;
//        }
//				float Center_variance(uint8_t line) //?????????
//        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;

//            float average;
//            float f_sum = 0;
//            int sum = 0;
//            uint8_t num;

//            for (num = 1; num <= line; num++)
//            {
//                sum = sum + Lcr[num].Center - Lcr[num - 1].Center;
//            }
//            average = (float)sum / (line - 1);
//            for (num = 1; num <= line; num++)
//            {
//                f_sum = f_sum + (Lcr[num].Center - Lcr[num - 1].Center - average) * (Lcr[num].Center - Lcr[num - 1].Center - average) / (line - 1);
//            }
//            // setText?????("????" + f_sum);

//            return f_sum;
//        }
//        int Fabs(int a)
//        {
//            if (a < 0)
//            {
//                a = -a;
//            }
//            return a;
//        }
//        void Obstacle_deal()//????
//        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//            uint8_t num;
//            uint8_t temp = 0;
//            uint8_t count = 0;//????
//            uint8_t last_line = 0;
//            uint8_t effect = 0;

//            for (num = 1; num <= 60; num++)
//            {
//                if (Right_flag[num] == 1 && Left_flag[num] == 1 && Fabs(Lcr[num].Center - Lcr[num - 1].Center) <= 1)
//                    effect++;
//            }

//            //       setText?????("effect" + effect);

//            if (effect >= 50)
//            {
//                for (num = 1; num < 60; num++)
//                {
//                    if (Lcr[num].LBlack - Lcr[num].RBlack <= (fixvalue[num]) * 0.8
//                        && Lcr[num].LBlack - Lcr[num].RBlack >= (fixvalue[num]) * 0.4
//                        && Left_flag[num] == 1 && Right_flag[num] == 1)
//                    {
//                        count++;

//                        for (num = (uint8_t)(num + 1); num < 60; num++)
//                        {
//                            if (Lcr[num].LBlack - Lcr[num].RBlack <= (fixvalue[num]) * 0.8
//                                && Lcr[num].LBlack - Lcr[num].RBlack >= (fixvalue[num]) * 0.4
//                                && Left_flag[num] == 1 && Right_flag[num] == 1)
//                            {
//                                count++;
//                                last_line = num;
//                            }
//                            if (count >= 7)
//                                break;
//                        }

//                        break;
//                    }
//                }
//            }
//            //setText?????("count" + count);
//            if (count >= 7)
//            {
//                if (last_line != 0)
//                {
//                    temp = (uint8_t)(Lcr[last_line].Center);
//                }
//            }
//            else if (Obstacle_location == 1)
//            {
//                if (Lcr[1].LBlack - Lcr[1].RBlack <= (fixvalue[1]) * 0.8
//                    && Lcr[1].LBlack - Lcr[1].RBlack >= (fixvalue[1]) * 0.4
//                    && Left_flag[1] == 1 && Right_flag[1] == 1)
//                {
//                    temp = (uint8_t)(Lcr[1].Center);
//                }
//            }
//            if (count >= 7 && temp >= 40 && temp <= 120)
//            {
//                Obstacle_location = 1;
//                //setText?????("??" + last_line);
//                if (last_line < 36)
//                {
//                    last_line = 36;
//                }

//                for (num = (uint8_t)(last_line - 1); num > 0; num--)
//                {
//                    if (temp < Lcr[num].LBlack && temp > Lcr[num].RBlack)
//                        Lcr[num].Center = temp;
//                }
//                if (temp < Lcr[0].LBlack && temp > Lcr[0].RBlack && Fabs(Lcr[0].Center - temp) <= 30)
//                    Lcr[0].Center = temp;
//            }
//            else
//            {
//                Obstacle_location = 0;
//            }

//        }
//        void Small_S_road_deal() //?S???
//       
//        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//            uint8_t left_min_value = 0, left_max_value = 0, right_max_value = 0, right_min_value = 0;//???????
//            uint8_t num;
//            uint8_t effect_line = 0;
//            uint8_t center_end_line = 0;
//            float variance;


//            for (num = 10; num < 60; num++)
//            {
//                if (Left_flag[num] == 1 && Right_flag[num] == 1)
//                {
//                    effect_line++;
//                }
//            }

//            for (num = 0; num < 10; num++)
//            {
//                if (Left_flag[num] == 1 && Right_flag[num] == 1)
//                {
//                    center_end_line++;
//                }
//            }
//            variance = Center_variance(45);
//            //setText?????("variance" + variance);

//            if (effect_line >= 50 && variance <= 5 && center_end_line >= 8)
//            {

//                //#region
//                for (num = 6; num < 62; num++)
//                {
//                    if (num <= 15 || num >= 55)
//                    {
//                        if (
//                            Lcr[num].LBlack > Lcr[num - 6].LBlack + 1 &&
//                            Lcr[num].LBlack > Lcr[num + 6].LBlack + 1 &&
//                            Lcr[num + 6].LBlack != 0xFF &&
//                            Lcr[num - 6].LBlack != 0xFF
//                          )
//                        {
//                            //setText?????("???" + num);
//                            left_max_value = num;
//                            break;
//                        }
//                    }
//                    else
//                    {
//                        if (
//                            Lcr[num].LBlack > Lcr[num - 10].LBlack + 1 &&
//                            Lcr[num].LBlack > Lcr[num + 10].LBlack + 1 &&
//                            Lcr[num + 10].LBlack != 0xFF &&
//                            Lcr[num - 10].LBlack != 0xFF
//                            )
//                        {
//                            //setText?????("???" + num);
//                            left_max_value = num;
//                            break;
//                        }
//                    }
//                }
//                for (num = 6; num < 62; num++)
//                {
//                    if (num <= 15 || num >= 55)
//                    {
//                        if (
//                            Lcr[num].LBlack < Lcr[num - 6].LBlack - 1 &&
//                            Lcr[num].LBlack < Lcr[num + 6].LBlack - 1 &&
//                            Lcr[num + 6].LBlack != 0xFF &&
//                            Lcr[num - 6].LBlack != 0xFF
//                          )
//                        {
//                            //setText?????("???" + num);
//                            left_min_value = num;
//                            break;
//                        }
//                    }
//                    else
//                    {
//                        if (
//                            Lcr[num].LBlack < Lcr[num - 10].LBlack - 1 &&
//                            Lcr[num].LBlack < Lcr[num + 10].LBlack - 1 &&
//                            Lcr[num + 10].LBlack != 0xFF &&
//                            Lcr[num - 10].LBlack != 0xFF
//                            )
//                        {

//                            //setText?????("???" + num);
//                            left_min_value = num;
//                            break;
//                        }
//                    }
//                }
//                for (num = 6; num < 62; num++)
//                {
//                    if (num <= 15 || num >= 55)
//                    {
//                        if (
//                             Lcr[num].RBlack > Lcr[num - 6].RBlack + 1 &&
//                             Lcr[num].RBlack > Lcr[num + 6].RBlack + 1 &&
//                             Lcr[num + 6].LBlack != 0xFF &&
//                             Lcr[num - 6].LBlack != 0xFF
//                          )
//                        {
//                            //setText?????("???" + num);
//                            right_max_value = num;
//                            break;
//                        }
//                    }
//                    else
//                    {
//                        if (
//                            Lcr[num].RBlack > Lcr[num - 10].RBlack + 1 &&
//                            Lcr[num].RBlack > Lcr[num + 10].RBlack + 1 &&
//                            Lcr[num + 10].LBlack != 0xFF &&
//                            Lcr[num - 10].LBlack != 0xFF
//                            )
//                        {
//                            //setText?????("???" + num);
//                            right_max_value = num;
//                            break;
//                        }
//                    }
//                }
//                for (num = 6; num < 62; num++)
//                {
//                    if (num <= 15 || num >= 55)
//                    {
//                        if (
//                             Lcr[num].RBlack < Lcr[num - 6].RBlack - 1 &&
//                             Lcr[num].RBlack < Lcr[num + 6].RBlack - 1 &&
//                             Lcr[num + 6].LBlack != 0xFF &&
//                             Lcr[num - 6].LBlack != 0xFF
//                          )
//                        {
//                            //setText?????("???" + num);
//                            right_min_value = num;
//                            break;
//                        }
//                    }
//                    else
//                    {
//                        if (
//                           Lcr[num].RBlack < Lcr[num - 10].RBlack - 1 &&
//                           Lcr[num].RBlack < Lcr[num + 10].RBlack - 1 &&
//                           Lcr[num + 10].LBlack != 0xFF &&
//                           Lcr[num - 10].LBlack != 0xFF
//                        )
//                        {
//                            //setText?????("???" + num);
//                            right_min_value = num;
//                            break;
//                        }
//                    }
//                }
//                //#endregion

//                //setText?????("?" + (Lcr[left_min_value].LBlack - Lcr[right_max_value].RBlack) + "?" + (Lcr[left_max_value].LBlack - Lcr[right_min_value].RBlack));
//                //  setText?????();
//                if (left_min_value != 0 && right_max_value != 0 && Lcr[left_min_value].LBlack - Lcr[right_max_value].RBlack >= 20)
//                {

//                    //-------------???----------------------
//                    Small_S_center = (uint8_t)((Lcr[left_min_value].LBlack + Lcr[right_max_value].RBlack) / 2);

//                    if (Fabs(Small_S_center - Lcr[30].Center) <= 25)
//                    {
//                        Small_S_flag = 1;
//                        //setText?????("?S?" + Small_S_center);
//                    }
//                    else if (Fabs(Small_S_center - Lcr[30].Center) > 25 && Fabs(Small_S_center - Lcr[30].Center) <= 45)
//                    {

//                        Small_S_flag = 2;
//                        Small_S_center = (uint8_t)((Small_S_center + Lcr[30].Center) / 2);
//                       // setText?????("?S?" + Small_S_center);
//                    }
//                }
//                else if (left_max_value != 0 && right_min_value != 0 && Lcr[left_max_value].LBlack - Lcr[right_min_value].RBlack >= 20)
//                {

//                    //-------------???----------------------
//                    Small_S_center = (uint8_t)((Lcr[left_max_value].LBlack + Lcr[right_min_value].RBlack) / 2);

//                    if (Fabs(Small_S_center - Lcr[30].Center) <= 25)
//                    {
//                        Small_S_flag = 1;
//                        //setText?????("?S?" + Small_S_center);
//                    }
//                    else if (Fabs(Small_S_center - Lcr[30].Center) > 25 && Fabs(Small_S_center - Lcr[30].Center) <= 45)
//                    {

//                        Small_S_flag = 2;
//                        Small_S_center = (uint8_t)((Small_S_center + Lcr[30].Center) / 2);
//                        //setText?????("?S?" + Small_S_center);
//                    }
//                }
//                else
//                {
//                    Small_S_flag = 0;
//                }

//            }
//            else
//            {
//                Small_S_flag = 0;
//            }
//        }
//         void ImageProcess()//?????
//        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//            Left_flag[RowNum] = 0;
//            Right_flag[RowNum] = 0;

//            /***************************************?????****************************************/
//            //#region 
//            if (RowNum == 0)
//            {
//                if (Last_field_Center != 160 &&Last_field_Center != 0 && Last_field_LBlack- Last_field_RBlack >=30 && delay_chag<=delay)
////									&& Last_field_Center >= 15 && Last_field_Center <= 145)
//                {
//                    Lcr[RowNum].LStart = Pro_value_byte(Last_field_Center - 15);
//                    Lcr[RowNum].LEnd = 158;
//                    Lcr[RowNum].RStart = Pro_value_byte(Last_field_Center + 15);
//                    Lcr[RowNum].REnd = 2;
//                }
//                else
//                {
//                    Lcr[RowNum].LStart = Pro_value_byte(80);
//                    Lcr[RowNum].LEnd = 158;
//                    Lcr[RowNum].RStart = Pro_value_byte(80);//-15);
//                    Lcr[RowNum].REnd = 2;
//                }
//                for (lie = Lcr[RowNum].RStart; lie > Lcr[RowNum].REnd; lie--)
//                {
//                    if (P[Pro_value_byte(lie)] == 0 && P[Pro_value_byte(lie - 1)] == 0)//&& P[Pro_value_byte(lie - 2)] == 0)
//                    {
//                        Lcr[RowNum].RBlack = lie;
//                        Right_flag[RowNum] = 1;
//                        break;
//                    }
//                    if (Right_flag[RowNum] != 1)
//                    {
//                        Lcr[RowNum].RBlack = 0;
//                    }
//                }
//                for (lie = Lcr[RowNum].LStart; lie < Lcr[RowNum].LEnd; lie++)
//                {
//                    if (P[Pro_value_byte(lie)] == 0 && P[Pro_value_byte(lie + 1)] == 0)//&& P[Pro_value_byte(lie + 2)] == 0)
//                    {
//                        Lcr[RowNum].LBlack = lie;
//                        Left_flag[RowNum] = 1;
//                        break;
//                    }
//                    if (Left_flag[RowNum] != 1)
//                    {
//                        Lcr[RowNum].LBlack = 160;
//                    }
//                }

//            }
//            //#endregion
//            /***************************************???????****************************************/
//            if (RowNum != 0)
//            {
//                /***************************************??????****************************************/
//                //??????
//                //#region
//							if(last_Road_flag==11||last_Road_flag==12||obstacle_flag==1)
//							{
//												Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 20));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 20));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 20));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 20));
//							}
//                if (Ten_Road_flag != 0 && Annular_flag == 0 && left_Annular_flag == 0 && right_Annular_flag == 0)//??????
//                {

//                    if (left_ten_flag != 0 && Ten_Road_flag != 1 && not_ten_flag == 2 && left_error_line != 0)
//                    {
//                        Lcr[RowNum].LStart = Pro_value_byte(Lcr[left_error_line - 1].Center);
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = Pro_value_byte(Lcr[left_error_line - 1].Center);
//                        Lcr[RowNum].REnd = 2;

//                        start_line = left_error_line;
//                    }
//                    else if (right_ten_flag != 0 && Ten_Road_flag != 1 && not_ten_flag == 3 && right_error_line != 0)
//                    {
//                        Lcr[RowNum].LStart = Pro_value_byte(Lcr[right_error_line - 1].Center);
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = Pro_value_byte(Lcr[right_error_line - 1].Center);
//                        Lcr[RowNum].REnd = 2;

//                        start_line = right_error_line;
//                    }
//                    else if (left_ten_flag == 0 && right_ten_flag == 0)
//                    {

//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                    }
//                    if (Ten_Road_flag == 1)
//                    {
//                        if ((right_error_line == 0 && left_error_line == 0 && Left_flag[0] == 1 && Right_flag[0] == 1) && (Left_flag[RowNum - 1] != 0 && Right_flag[RowNum - 1] != 0))
//                        {
//                            Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                            Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                            Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                            Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                        }
//                        else if (left_error_line != 0)
//                        {
//                            Lcr[RowNum].LStart = Pro_value_byte(Lcr[left_error_line - 1].Center);
//                            Lcr[RowNum].LEnd = 158;
//                            Lcr[RowNum].RStart = Pro_value_byte(Lcr[left_error_line - 1].Center);
//                            Lcr[RowNum].REnd = 2;
//                        }
//                        else if (right_error_line != 0)
//                        {
//                            Lcr[RowNum].LStart = Pro_value_byte(Lcr[right_error_line - 1].Center);
//                            Lcr[RowNum].LEnd = 158;
//                            Lcr[RowNum].RStart = Pro_value_byte(Lcr[right_error_line - 1].Center);
//                            Lcr[RowNum].REnd = 2;
//                        }
//                        else if(ten_error_cnt >= 5)
//                        {
//                            Lcr[RowNum].LStart = Pro_value_byte(Lcr[0].Center);
//                            Lcr[RowNum].LEnd = 158;
//                            Lcr[RowNum].RStart = Pro_value_byte(Lcr[0].Center);
//                            Lcr[RowNum].REnd = 2;
//                        }

//                    }
//                    if (Ten_Road_flag == 3 && not_ten_flag != 3 && last_right_right_line != 0 && right_error_line != 0)
//                    {
//                        Lcr[RowNum].LStart = Pro_value_byte(Lcr[last_right_right_line].Center);
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = Pro_value_byte(Lcr[last_right_right_line].Center);
//                        Lcr[RowNum].REnd = 2;
//                    }
//                    if (Ten_Road_flag == 2 && not_ten_flag != 2 && last_left_right_line != 0 && left_error_line != 0)
//                    {
//                        Lcr[RowNum].LStart = Pro_value_byte(Lcr[last_left_right_line].Center);
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = Pro_value_byte(Lcr[last_left_right_line].Center);
//                        Lcr[RowNum].REnd = 2;
//                    }
//                    if (right_right_line != 0 || left_right_line != 0 || ten_line != 0)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                    }
//                }
//                //#endregion
//                //??????
//                //#region
//                else if (Annular_flag == 1 || left_Annular_flag != 0|| right_Annular_flag != 0)//??????
//                {

//                    if (Annular_turn_left_flag == 1 && ((last_left_car_line <= 55 && last_left_car_line != 0 && last_left_Annular_line <= 10) || last_left_Annular_line <= 10 || Lcr[0].LBlack - Lcr[0].RBlack > fixvalue[0] + 10))
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - fixvalue[RowNum] / 2));
//                        Lcr[RowNum].REnd = 2;
//                        Annular_flag1 = 1;
//                        ////setText?????("????1" + last_left_Annular_line);

//                    }
//                    else if (Annular_turn_right_flag == 1 && ((last_right_car_line <= 55 && last_right_car_line != 0 && last_right_Annular_line <= 10) || last_right_Annular_line <= 10 || Lcr[0].LBlack - Lcr[0].RBlack > fixvalue[0] + 10))
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + fixvalue[RowNum] / 2));
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                        Annular_flag1 = 1;
//                        ////setText?????("????1" + last_right_Annular_line);
//                    }
//                    else if (Annular_turn_left_flag == 1 && left_Annular_line != 0)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - fixvalue[RowNum] / 2)); ;
//                        Lcr[RowNum].REnd = 2;
//                        ////setText?????("????2" + left_Annular_line);

//                    }
//                    else if (Annular_turn_right_flag == 1 && right_Annular_line != 0)
//                    {
//                        Lcr[RowNum].LStart = Pro_value_byte(Lcr[RowNum - 1].RBlack + fixvalue[RowNum] / 2);
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                        ////setText?????("????2" + right_Annular_line);
//                    }
//                    else if (Annular_turn_right_flag == 1 && right_Annular_flag != 0)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + fixvalue[RowNum] / 2));
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                    }
//                    else if (Annular_turn_left_flag == 1 && left_Annular_flag != 0)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - fixvalue[RowNum] / 2)); ;
//                        Lcr[RowNum].REnd = 2;
//                    }
//                    else if (Annular_turn_right_flag == 1 && left_Annular_flag != 0)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + fixvalue[RowNum] / 2));
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                    }
//                    else if (Annular_turn_left_flag == 1 && right_Annular_flag != 0)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - fixvalue[RowNum] / 2)); ;
//                        Lcr[RowNum].REnd = 2;
//                    }
//                    else
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                    }
//                }
//                else if (In_Annular_flag == 2)
//                {
//                    if (Annular_turn_left_flag == 1)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                        Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - fixvalue[RowNum] / 2));
//                        Lcr[RowNum].REnd = 2;

//                    }
//                    else if (Annular_turn_right_flag == 1)
//                    {
//                        Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + fixvalue[RowNum] / 2));
//                        Lcr[RowNum].LEnd = 158;
//                        Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                        Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));
//                    }
//                }
//                else
//                {
//                    Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 10));
//                    Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 10));
//                    Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 10));
//                    Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 10));

//                }
//                //#endregion
//                //??????
//                //#region 
////                if (obstacle_flag==1)//||Starting_line_flag != 0)
////                {
////                    Lcr[RowNum].LStart = Pro_value_byte(80);
////                    Lcr[RowNum].LEnd = 158;
////                    Lcr[RowNum].RStart = Pro_value_byte(80);//-15);
////                    Lcr[RowNum].REnd = 2;
////                }
//                //#endregion
//                //????
//                //#region
//								//??????
//               // #region 
//                if (Obstacle_location == 1)
//                {
//                    Lcr[RowNum].LStart = Pro_value_byte((Last_field_Center - 6));
//                    Lcr[RowNum].LEnd = 158;
//                    Lcr[RowNum].RStart = Pro_value_byte((Last_field_Center + 6));
//                    Lcr[RowNum].REnd = 1;
//                }
//                ////if (obstacle_flag==1)//||Starting_line_flag != 0)
//                ////{
//                ////    Lcr[RowNum].LStart = Pro_value_byte(80);
//                ////    Lcr[RowNum].LEnd = 158;
//                ////    Lcr[RowNum].RStart = Pro_value_byte(80);//-15);
//                ////    Lcr[RowNum].REnd = 2;
//                ////}
//                //if (last_Road_flag == 11 || last_Road_flag == 12 || obstacle_flag == 1)
//                //{
//                //    Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 20));
//                //    Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 20));
//                //    Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 20));
//                //    Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 20));
//                //}
//                //#endregion
//                //??????
//                //#region 
//                if (ramp_flag == 1)
//                {
//                    Lcr[RowNum].LStart = Pro_value_byte((Last_field_Center - 6));
//                    Lcr[RowNum].LEnd = 158;
//                    Lcr[RowNum].RStart = Pro_value_byte((Last_field_Center + 6));
//                    Lcr[RowNum].REnd = 1;
//                }
//                //#endregion
////								if (Starting_line_stop_flag == 0&& (last_Road_flag==11|| last_Road_flag==12))
////                {
////                    Lcr[RowNum].LStart = (Pro_value_byte(Lcr[RowNum - 1].LBlack - 3));
////                    Lcr[RowNum].LEnd = (Pro_value_byte(Lcr[RowNum - 1].LBlack + 3));
////                    Lcr[RowNum].RStart = (Pro_value_byte(Lcr[RowNum - 1].RBlack + 3));
////                    Lcr[RowNum].REnd = (Pro_value_byte(Lcr[RowNum - 1].RBlack - 3));
////                }
//                for (lie = Lcr[RowNum].LStart; lie <= Lcr[RowNum].LEnd; lie++)
//                {
//                    if (P[Pro_value_byte(lie)] == 0 && P[Pro_value_byte(lie - 1)] == 0 )//&& P[Pro_value_byte(lie - 2)] == 0)
//                    {
//                        Lcr[RowNum].LBlack = lie;
//                        Left_flag[RowNum] = 1;
//                        break;
//                    }
//                    if (Left_flag[RowNum] != 1)
//                    {
//                        Lcr[RowNum].LBlack = 160;
//                    }

//                }
//                for (lie = Lcr[RowNum].RStart; lie >= Lcr[RowNum].REnd; lie--)
//                {
//                    if (P[Pro_value_byte(lie)] == 0 && P[Pro_value_byte(lie - 1)] == 0 )//&& P[Pro_value_byte(lie - 2)] == 0)
//                    {
//                        Lcr[RowNum].RBlack = lie;
//                        Right_flag[RowNum] = 1;
//                        break;
//                    }
//                    if (Right_flag[RowNum] != 1)
//                    {
//                        Lcr[RowNum].RBlack = 0;
//                    }
//                }


//            }
//            //#endregion
//            
//            /***************************************?????****************************************/

//            /***************************************?????****************************************/
//            //????????
//            //#region
//            if (RowNum != 0)
//            {
//                if (Left_flag[RowNum] == 0 && Right_flag[RowNum] == 1 && Left_flag[RowNum] == 0 && Right_flag[RowNum-1] == 1 && Left_flag[RowNum-1] == 0 && Turn_right_flag != 1)//????
//                {
//                    Turn_left_count++;
//                    if (Turn_left_count == 1)
//                    {
//                        Turn_left_line = RowNum;
//                    }
//                    if (Turn_left_count >= 8)
//                    {
//                        Turn_left_flag = 1;
//                        //Turn_left_count = 0;
//                        //Wait_flag = 1;
//                    }
//                }
//                if (Right_flag[RowNum] == 0 && Left_flag[RowNum] == 1 && Right_flag[RowNum-1] == 0 && Left_flag[RowNum-1] == 1 && Turn_left_flag != 1)//????
//                {
//                    Turn_right_count++;
//                    if (Turn_right_count == 1)
//                    {
//                        Turn_right_line = RowNum;
//                    }
//                    if (Turn_right_count >= 8)
//                    {
//                        Turn_right_flag = 1;
//                        //Turn_right_count = 0;
//                        //Wait_flag = 1;
//                    }
//                }
//                if (RowNum - Turn_left_line > 9 && Turn_left_count < 8)
//                {
//                    Turn_left_count = 0;
//                }
//                if (RowNum - Turn_right_line > 9 && Turn_right_count < 8)
//                {
//                    Turn_right_count = 0;
//                }
//            }
//            //#endregion
//            /***************************************?????****************************************/
//            //#region
//            if (RowNum > 1 && RowNum <65 && Annular_flag == 0&& In_Annular_flag== 0 && right_Annular_flag == 0 && left_Annular_flag == 0)
//            {
//                Left_sub = Lcr[RowNum].LBlack - Lcr[RowNum - 1].LBlack;
//                Right_sub = Lcr[RowNum - 1].RBlack - Lcr[RowNum].RBlack;
//                if (Lcr[Row_Pro_value_byte(RowNum - 1)].RBlack - Lcr[Row_Pro_value_byte(RowNum)].RBlack <= 0)
//                {
//                    ten_right_cnt++;
//                }
//                if (Lcr[Row_Pro_value_byte(RowNum - 1)].LBlack - Lcr[Row_Pro_value_byte(RowNum)].LBlack >= 0)
//                {
//                    ten_left_cnt++;
//                }
//                if ((Ten_Road_flag == 2 && left_ten_flag != 1) || left_ten_flag != 1)
//                {
//                    if (Left_sub > 1&& ten_left_cnt>2)
//                    {
//                        left_error_flag = 1;//???????
//                        left_error_count++;//??????
//                                           ////setText?????("???"+ RowNum);
//                        if (left_error_count == 1)
//                        {
//                            left_line = RowNum;//???????????
//                        }
//                    }
//                    
//                    if (left_error_count >= 5 || Left_sub >= 20)
//                    {
//                            left_error_line = left_line;//?????
//                            left_ten_flag = 1;//?????????
//                            //setText?????("?????" + left_error_line);//ratio_Calculation(left_error_line, (uint8_t)(left_error_line + 5), 1));
//                        
//                    }
//                    if (RowNum - left_line > 6 && Turn_left_count < 5)
//                    {
//                        left_error_count = 0;
//                    }
//                }
//                if (right_ten_flag != 1 || (Ten_Road_flag == 3 && right_ten_flag != 1))
//                {
//                    if (Right_sub > 1 && ten_right_cnt > 2)
//                    {
//                        right_error_flag = 1;//???????
//                        right_error_count++;//??????
//                                            ////setText?????("???"+ RowNum);
//                        if (right_error_count == 1)
//                        {
//                            right_line = RowNum;//???????????
//                        }
//                    }
//                    
//                    if (right_error_count >= 5|| Right_sub>=20)
//                    {
//                            right_error_line = right_line;//?????
//                            right_ten_flag = 1;//?????????
//                            //setText?????("?????" + right_error_line);//ratio_Calculation(right_error_line, (uint8_t)(right_error_line + 5), 2));
//                    }
//                    if (RowNum - right_line > 6 && right_error_count < 5)
//                    {
//                        right_error_count = 0;
//                    }
//                }
//                if (Left_flag[RowNum] == 0 && Right_flag[RowNum] == 0)
//                {
//                    ten_error_cnt ++;//??????
//                }
//                if (right_error_line == 0 && Left_flag[RowNum] == 0)
//                {
//                    left_transmit_cnt++;//???????????
//                }
//                if (left_error_line == 0 && Right_flag[RowNum] == 0)
//                {
//                    right_transmit_cnt++;//???????????
//                }
//                if (((right_error_line <= 62 && right_error_line <= 62 && right_error_line >= 25 && right_error_line >= 25 && Difference(left_error_line, right_error_line) <= 6) || ((left_ten_flag == 1 || right_ten_flag == 1) && ten_error_cnt >= 5))
//                    || (ten_error_cnt >= 3) || (Right_flag[0] == 0 && Left_flag[0] == 0 && Right_flag[1] == 0 && Left_flag[1] == 0 && Right_flag[2] == 0 && Left_flag[2] == 0))
//                {
//                    Ten_Road_flag = 1;
//                }
//                if (Ten_Road_flag != 0 && (Left_sub <= -15|| Right_sub <= -15))
//                {
//                    ten_line_flag = 1;
//                }
//                if (Ten_Road_flag != 0&&ten_line==0&& (ten_error_cnt>=1|| ten_line_flag==1))
//                {
//                    if (Right_flag[RowNum-1] == 1 && Left_flag[RowNum-1] == 1 && Right_flag[RowNum] == 1 && Left_flag[RowNum] == 1&& Left_sub>=-2&& Left_sub<=0 && Right_sub >= -2 && Right_sub <= 0)
//                    {
//                        ten_count ++;//????????
//                    }
//                    if (ten_count >= 2)
//                    {
//                        ten_line = RowNum;//???????
//                    }
//                }
//                if (Ten_Road_flag == 3&& right_ten_flag==1&& right_right_line==0&& Lcr[RowNum].LBlack - Lcr[RowNum].RBlack<=fixvalue[RowNum]+5)
//                {
//                    if (Right_flag[RowNum - 1] == 1 && Right_flag[RowNum] == 1 && Right_sub >= -2 && Right_sub <= 0)
//                    {
//                        right_right_line = RowNum;
//                    }
//                }
//                if (Ten_Road_flag == 2&& left_ten_flag==1 && left_right_line == 0 && Lcr[RowNum].LBlack - Lcr[RowNum].RBlack <= fixvalue[RowNum] + 5)
//                {
//                    if (Left_flag[RowNum - 1] == 1 && Left_flag[RowNum] == 1 && Left_sub >= -2 && Left_sub <= 0)
//                    {
//                        left_right_line = RowNum;
//                    }
//                }
//                if (Ten_Road_flag == 3&& Left_flag[RowNum] == 1)
//                {
//                    left_right_count ++;//??????
//                }
//                if (Ten_Road_flag == 2 && Right_flag[RowNum] == 1)
//                {
//                    right_right_count ++;//??????
//                }
//            }
//            //#endregion
//            

//            /***************************************?????****************************************/
//            //???
//            //#region
//            if (RowNum > 5 && RowNum <= 60)// && RowNum >= 10)
//            {
//                if (Lcr[Row_Pro_value_byte(RowNum - 1)].RBlack - Lcr[Row_Pro_value_byte(RowNum)].RBlack <= 0)
//                {
//                    Annular_right_cnt++;
//                }
//                if (Lcr[Row_Pro_value_byte(RowNum - 1)].LBlack - Lcr[Row_Pro_value_byte(RowNum)].LBlack >= 0)
//                {
//                    Annular_left_cnt++;
//                }
//                if (Annular_Rline == 0&& Annular_right_cnt>=2)
//                {
//                    Right_sub = Lcr[RowNum - 1].RBlack - Lcr[RowNum].RBlack;
//                    if (Right_sub >= Out_Annular_sub)
//                    {
//                        right_Annular_count++;//?????
//                        if (right_Annular_count == 1)
//                        {
//                            right_Annular_line = RowNum;//???????????
//                        }
//                    }

//                    if (right_Annular_count >= 5 || Right_sub >= 15)
//                    {
//                        Annular_Rline = right_Annular_line;
//                        //setText?????("??????" + Annular_Rline);//ratio_Calculation(right_error_line, (uint8_t)(right_error_line + 5), 2));
//                    }
//                    if ((RowNum - right_Annular_line > 6 && right_Annular_count < 5))
//                    {
//                        right_Annular_count = 0;
//                    }
//                    
//                }
//                if (Annular_Lline == 0&& Annular_left_cnt>=2)
//                {
//                    Left_sub = Lcr[RowNum].LBlack - Lcr[RowNum - 1].LBlack;
//                    if (Left_sub >= Out_Annular_sub)
//                    {
//                        left_Annular_count++;//?????
//                        if (left_Annular_count == 1)
//                        {
//                            left_Annular_line = RowNum;//???????????
//                        }
//                    }

//                    if (left_Annular_count >= 5 || Left_sub >= 15)
//                    {
//                        Annular_Lline = left_Annular_line;
//                        //setText?????("??????" + Annular_Lline);//ratio_Calculation(right_error_line, (uint8_t)(right_error_line + 5), 2));
//                    }
//                    if ((RowNum - left_Annular_line > 6 && left_Annular_count < 5))
//                    {
//                        left_Annular_count = 0;
//                    }
//                    
//                }
//                
//                if (In_Annular_flag != 2 && Difference(Annular_Lline, Annular_Rline) <= 15 && Annular_Lline != 0 && Annular_Rline != 0)//?
//                {
//                    if (Annular_Lline <= Annular_Rline)
//                    {
//                        ratio = ((float)(Lcr[Row_Pro_value_byte(Annular_Lline -5)].Center - Lcr[0].Center) / (Row_Pro_value_byte(Annular_Lline - 5)));//??
//                        constant = ((Lcr[Row_Pro_value_byte(Annular_Lline - 5)].Center - (float)(ratio * Row_Pro_value_byte(Annular_Lline - 5))));//??
//                    }
//                    else
//                    {
//                        ratio = ((float)(Lcr[Row_Pro_value_byte(Annular_Rline - 5)].Center - Lcr[0].Center) / (Row_Pro_value_byte(Annular_Rline - 5)));//??
//                        constant = ((Lcr[Row_Pro_value_byte(Annular_Rline - 5)].Center - (float)(ratio * Row_Pro_value_byte(Annular_Rline - 5))));//??
//                    }
//                    for (i = Annular_Rline; i < 55; i++)
//                    {
//                        if (left_car_line == 0 && P_Pixels[Row_Pro_value_byte(i)][ (uint8_t)(Pro_value_byte((int)(ratio*i+ constant) + car_fixvalue[i] / 2))] == 0)
//                        {
//                            left_car_line = (uint8_t)i;
//                            //setText?????("?" + left_car_line);
//                        }
//                        if (right_car_line == 0 && P_Pixels[Row_Pro_value_byte(i)][ (uint8_t)(Pro_value_byte((int)(ratio * i + constant) - car_fixvalue[i] / 2))] == 0)
//                        {
//                            right_car_line = (uint8_t)i;
//                            //setText?????("?" + right_car_line);
//                        }
//                        if (middle_car_line == 0 && P_Pixels[Row_Pro_value_byte(i)][ Pro_value_byte((int)(ratio * i + constant))] == 0)
//                        {
//                            middle_car_line = (uint8_t)i;
//                            //setText?????("?" + middle_car_line);
//                        }
//                        if (left_car_line != 0 && right_car_line != 0 && middle_car_line != 0) break;
//                    }
//                    if (left_car_line != 0 && right_car_line != 0 && middle_car_line != 0 && Left_flag[0] != 0 && Right_flag[0] != 0)
//                    {
//                        if (Difference(left_car_line, right_car_line) <= 5 && Difference(left_car_line, middle_car_line) <= 5 && Difference(right_car_line, middle_car_line) <= 5)
//                        {
//                            Annular_flag = 1;
//                            ////setText?????("???");
//                        }
//                    }
//                }
//            }
//            //#endregion
//            //???
//            //#region
//            if (RowNum != 0)
//            {

//                //#endregion
//                //?????
//                //#region
//                if (Annular_turn_right_flag == 1 && Annular_flag == 1 && Annular_Rline < 20)
//                {
//                    //if (Annular_Lline <= Annular_Rline)
//                    //{
//                    //    ratio = ((float)(Lcr[Row_Pro_value_byte(Annular_Lline - 5)].Center - Lcr[0].Center) / (Row_Pro_value_byte(Annular_Lline - 5)));//??
//                    //    constant = ((Lcr[Row_Pro_value_byte(Annular_Lline - 5)].Center - (float)(ratio * Row_Pro_value_byte(Annular_Lline - 5))));//??
//                    //}
//                    //else
//                    //{
//                    //    ratio = ((float)(Lcr[Row_Pro_value_byte(Annular_Rline - 5)].Center - Lcr[0].Center) / (Row_Pro_value_byte(Annular_Rline - 5)));//??
//                    //    constant = ((Lcr[Row_Pro_value_byte(Annular_Rline - 5)].Center - (float)(ratio * Row_Pro_value_byte(Annular_Rline - 5))));//??
//                    //}
//                    for (i = Annular_Rline; i < 55; i++)
//                    {
//                        //if (left_car_line == 0 && P_Pixels[Row_Pro_value_byte(i), (uint8_t)(Pro_value_byte((int)(ratio * i + constant) + car_fixvalue[i] / 2))] == 0)
//                        //{
//                        //    left_car_line = (uint8_t)i;
//                        //    //setText?????("?" + left_car_line);
//                        //    break;
//                        //}
//                        if (left_car_line == 0 && P_Pixels[Row_Pro_value_byte(i)][ (uint8_t)(Pro_value_byte(Lcr[0].Center + car_fixvalue[i] / 2))] == 0)
//                        {
//                            left_car_line = (uint8_t)i;
//                            //setText?????("?" + left_car_line);
//                            //setText?????("last_left_car_line" + last_left_car_line);
//                            if (Difference(last_left_car_line, left_car_line) > 10||left_car_line <= 30)
//                            {
//                                In_Annular_flag1 = 1;
//                            }
//                            break;
//                        }
//                    }
//                    if ((/*left_car_line > 60 || */((left_car_line <= 30 || In_Annular_flag1 == 1) && Left_flag[0] != 0 && Last_field_LBlack == 160)) && In_Annular_flag!=2)
//                    {
//                        Annular_flag = 0;
//                        Annular_count = 0;
//                        In_Annular_flag1 = 0;
//                        if (In_Annular_flag == 1)
//                            In_Annular_flag = 2;
//                        //setText?????("????");
//                    }
//                    Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);
//                    if (Annular_line == 0 && RowNum != 0 && Difference(Lcr[RowNum].LBlack, Lcr[RowNum - 1].LBlack) >= 15&& Difference(Lcr[RowNum].Center, Lcr[RowNum-1].Center) >= 5)
//                    {
//                        Annular_line = 1;//?????
//                    }
//                    if (Annular_line == 1 && Difference(Lcr[RowNum].LBlack, Lcr[RowNum - 1].LBlack) <= 3)
//                    {
//                        Annular_line = RowNum;
//                        //setText?????("Annular_line" + Annular_line);
//                    }
//                }
//                if (Annular_turn_left_flag == 1 && Annular_flag == 1&& Annular_Lline<20)
//                {
//                    //if (Annular_Lline <= Annular_Rline)
//                    //{
//                    //    ratio = ((float)(Lcr[Row_Pro_value_byte(Annular_Lline - 5)].Center - Lcr[0].Center) / (Row_Pro_value_byte(Annular_Lline - 5)));//??
//                    //    constant = ((Lcr[Row_Pro_value_byte(Annular_Lline - 5)].Center - (float)(ratio * Row_Pro_value_byte(Annular_Lline - 5))));//??
//                    //}
//                    //else
//                    //{
//                    //    ratio = ((float)(Lcr[Row_Pro_value_byte(Annular_Rline - 5)].Center - Lcr[0].Center) / (Row_Pro_value_byte(Annular_Rline - 5)));//??
//                    //    constant = ((Lcr[Row_Pro_value_byte(Annular_Rline - 5)].Center - (float)(ratio * Row_Pro_value_byte(Annular_Rline - 5))));//??
//                    //}
//                    for (i = Annular_Lline; i < 55; i++)
//                    {
//                        //if (right_car_line == 0 && P_Pixels[Row_Pro_value_byte(i), (uint8_t)(Pro_value_byte((int)(ratio * i + constant) - car_fixvalue[i] / 2))] == 0)
//                        //{
//                        //    right_car_line = (uint8_t)i;
//                        //    //setText?????("?" + right_car_line);
//                        //    break;
//                        //}
//                        if (right_car_line == 0 && P_Pixels[Row_Pro_value_byte(i)][ (uint8_t)(Pro_value_byte(Lcr[0].Center - car_fixvalue[i] / 2))] == 0)
//                        {
//                            right_car_line = (uint8_t)i;
//                            //setText?????("?" + right_car_line);
//                            //setText?????("last_right_car_line" + last_right_car_line);
//                            if (Difference(last_right_car_line, right_car_line) > 10||right_car_line <= 30)
//                            {
//                                In_Annular_flag1 = 1;
//                            }
//                            break;
//                        }
//                    }
//                    if ((/*right_car_line > 60 || */((right_car_line <= 30 || In_Annular_flag1 == 1) && Right_flag[0] != 0 && Last_field_RBlack == 0)) && In_Annular_flag != 2)
//                    {
//                        Annular_flag = 0;
//                        Annular_count = 0;
//                        In_Annular_flag1 = 0;
//                        if (In_Annular_flag==1)
//                        In_Annular_flag = 2;
//                        //setText?????("????");
//                    }
//                    Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);
//                    if (Annular_line == 0 && RowNum != 0 && Difference(Lcr[RowNum].RBlack, Lcr[RowNum - 1].RBlack) >= 15 && Difference(Lcr[RowNum].Center, Lcr[RowNum - 1].Center) >= 5)
//                    {
//                        Annular_line = 1;//?????
//                    }
//                    if (Annular_line == 1 && Difference(Lcr[RowNum].RBlack, Lcr[RowNum - 1].RBlack) <= 3)
//                    {
//                        Annular_line = RowNum;
//                        //setText?????("Annular_line" + Annular_line);
//                    }
//                }

//                //#endregion
//                //?????
//                //#region
//                if (Annular_turn_left_flag == 1 && In_Annular_flag == 2 && (Annular_Lline != 0 && Annular_Lline < 45 && RowNum < 50) && Annular_flag !=1)// && last_left_Annular_line >= 45&& Lcr[Annular_Lline].RBlack == 0 && Annular_Lline != 0)
//                {
//                    //Out_Annular_count++;
//                    Out_Annular_flag = 1;
//                }
//                if (Annular_turn_right_flag == 1 && In_Annular_flag == 2 && (Annular_Rline != 0 && Annular_Rline < 45 && RowNum < 50) && Annular_flag != 1)// && last_right_Annular_line >= 45&& Lcr[Annular_Rline].LBlack == 0 && Annular_Rline != 0)
//                {
//                    //Out_Annular_count++;
//                    Out_Annular_flag = 1;
//                }
//								if (Annular_turn_right_flag == 1 && In_Annular_flag == 2 && Out_Annular_flag == 1 && Left_flag[RowNum] == 0&& RowNum<=30)//&& Out_Annular_count>=3)
//                {
//                    Out_Annular_count++;

//                }
//                if (Annular_turn_left_flag == 1 && In_Annular_flag == 2 && Out_Annular_flag == 1 && Right_flag[RowNum] == 0 && RowNum <= 30)//&& Out_Annular_count >= 3)
//                {
//                    Out_Annular_count++;

//                }
//                
//                if (Annular_turn_left_flag == 1 && Out_Annular_flag == 1 && Annular_line == 0)//&& (Annular_Lline!=0|| last_left_Annular_line!=0))
//                {
//                    Right_sub = Lcr[RowNum - 1].RBlack - Lcr[RowNum].RBlack;
//                    if (Right_sub < -10)
//                        Annular_line = RowNum;
//                    if (Annular_line<=10&& Annular_line!=0)
//                    {
//                        
//                        Out_Annular_flag = 0;
//                        In_Annular_flag = 0;

//                    }
//                }
//                if (Annular_turn_right_flag == 1 && Out_Annular_flag == 1&& Annular_line==0 )//&& (Annular_Rline != 0|| last_right_Annular_line<=10))
//                {
//                    Left_sub = Lcr[RowNum].LBlack - Lcr[RowNum - 1].LBlack;
//                    if (Left_sub < -10)
//                        Annular_line = RowNum;
//                    if (Annular_line <= 10 && Annular_line != 0)//&& Out_Annular_count >= 3)
//                    {
//                        
//                        Out_Annular_flag = 0;
//                        In_Annular_flag = 0;

//                    }
//                }
//            }
//            //#endregion
//            /***************************************?S???****************************************/
//            //#region
//            if (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack <= fixvalue[RowNum]+5&& Lcr[RowNum].LBlack - Lcr[RowNum].RBlack >= fixvalue[RowNum] - 5)
//            {
//                Small_s_cnt++;
//            }
//            if (RowNum >= 1&& RowNum <= 66)
//            {
//                Left_sub = Lcr[RowNum - 1].LBlack - Lcr[RowNum].LBlack;
//                Right_sub = Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack;
//                if (Left_sub > 0 && trend_L_flag != 2)
//                {
//                    trend_L_cnt++;
//                    if (trend_L_cnt >= 3&& trend_L_flag!=2)
//                    {
//                        trend_L_flag = 2;
//                        Small_S_L_cnt++;
//                        trend_L_cnt = 0;
//                    }
//                }
//                if (Left_sub < 0 && trend_L_flag != 1)
//                {
//                    trend_L_cnt++;
//                    if (trend_L_cnt >= 3 && trend_L_flag != 1)
//                    {
//                        trend_L_flag = 1;
//                        Small_S_L_cnt++;
//                        trend_L_cnt = 0;
//                    }
//                }
//                if (Right_sub > 0 && trend_R_flag != 1)
//                {
//                    trend_R_cnt++;
//                    if (trend_R_cnt >= 3 && trend_R_flag != 1)
//                    {
//                        trend_R_flag = 1;
//                        Small_S_R_cnt++;
//                        trend_R_cnt = 0;
//                    }
//                }
//                if (Right_sub < 0 && trend_R_flag != 2)
//                {
//                    trend_R_cnt++;
//                    if (trend_R_cnt >= 3 && trend_R_flag != 2)
//                    {
//                        trend_R_flag = 2;
//                        Small_S_R_cnt++;
//                        trend_R_cnt = 0;
//                    }
//                }

//                //if ((Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack) * (Lcr[RowNum].RBlack - Lcr[RowNum + 1].RBlack) > 0 && (Lcr[RowNum].RBlack - Lcr[RowNum - 3].RBlack) * (Lcr[RowNum].RBlack - Lcr[RowNum + 3].RBlack) > 0)
//                //{
//                //    Small_S_R_cnt++;
//                //    //setText?????("Small_S_R_cnt" + RowNum);
//                //}
//                //if ((Lcr[RowNum].LBlack - Lcr[RowNum - 1].LBlack)*(Lcr[RowNum].LBlack - Lcr[RowNum+1].LBlack) > 0 && (Lcr[RowNum].LBlack - Lcr[RowNum - 3].LBlack) * (Lcr[RowNum].LBlack - Lcr[RowNum + 3].LBlack) > 0)
//                //{
//                //    Small_S_L_cnt++;
//                //    //setText?????("Small_S_L_cnt" + RowNum);
//                //}
//            }
//            //#endregion
//            /***************************************?????****************************************/
//            //#region
//             if (RowNum >= 1)
//            {
//                Left_sub = Lcr[RowNum].LBlack - Lcr[RowNum - 1].LBlack;
//                Right_sub = Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack;
////                Last_Left_sub = Lcr[RowNum-1].LBlack - Lcr[RowNum - 2].LBlack;
////                Last_Right_sub = Lcr[RowNum-1].RBlack - Lcr[RowNum - 2].RBlack;
//                if (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack <= fixvalue[RowNum] + 5 && Lcr[RowNum].LBlack - Lcr[RowNum].RBlack >= fixvalue[RowNum] - 5 && Left_sub >= -2 && Left_sub <= 0 && Right_sub <= 2 && Right_sub >= 0
//                     )//&& Last_Left_sub >= -2 && Last_Left_sub <= 0 && Last_Right_sub <= 2 && Last_Right_sub >= 0)
//                {
//                    straight_cnt++;
//                }
//            }
//            //#endregion
//            /***************************************?????****************************************/
//            //#region
//            if (RowNum <= 60 && (straight_cnt >= 5/*|| straight_cnt == 0*/) && Lcr[RowNum].LBlack - Lcr[RowNum].RBlack >= fixvalue[RowNum] *1.22 && Left_flag[RowNum] == 1 && Right_flag[RowNum] ==1 && Left_sub >= -2 && Left_sub <= 0 && Right_sub <= 2 && Right_sub >= 0)
//            {
//                ramp_cnt++;
//            }
//            //#endregion
//            /***************************************?????****************************************/
//            //#region

//            //#endregion
//            /***************************************?????****************************************/
//            //#region
//            if (RowNum >= 1 && obstacle_cnt == 0 && (Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack >= 6 || Lcr[RowNum].LBlack - Lcr[RowNum - 1].LBlack <= -6))
//            {
//                obstacle_cnt = 1;
//            }
//            if (obstacle_cnt != 0 && RowNum >= 1 && RowNum <= 50 && Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack <= 2 && Lcr[RowNum - 1].LBlack - Lcr[RowNum].LBlack<=2
//                && Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack >= 0 && Lcr[RowNum - 1].LBlack - Lcr[RowNum].LBlack >= 0
//                && Lcr[RowNum].LBlack - Lcr[RowNum].RBlack <= fixvalue[RowNum] - 12 && straight_cnt >= 10)
//            {
//                obstacle_cnt++;
//                if (obstacle_cnt == 2)
//                {
//                    obstacle_line = RowNum;
//                }
//            }
//            //#endregion
//            /***************************************????****************************************/
//            //#region
//            Lcr[RowNum].Center = Pro_value_byte((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);

//            //#endregion

//            /***************************************??****************************************/
//            //#region
//            if (RowNum > 10)
//            {

//                if (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack <= 12 && Starting_line_flag == 0)
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("??2");
//                    //if (Starting_line_cnt >= 5&& Starting_line_cnt < 10)
//                    //{
//                    //    Starting_line_flag = 1;
//                    //    LcrlenBool = 0;
//                    //}
//                }
//                if (Lcr[RowNum].LBlack < Lcr[RowNum].RBlack || Lcr[RowNum].Center < Lcr[RowNum].RBlack || Lcr[RowNum].Center > Lcr[RowNum].LBlack)
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("??1");
//                }
//                if (((Lcr[left_error_line].LBlack < 10 && left_error_line != 0) || (Lcr[right_error_line].RBlack > 110 && right_error_line != 0)))
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("????");
//                }
//                if ((RowNum >= 65) && ((Left_flag[RowNum] == 1) && (Left_flag[RowNum - 1] == 0) && (Right_flag[RowNum] == 1)))
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("???");
//                }
//                else if ((RowNum >= 65) && ((Right_flag[RowNum] == 1) && (Right_flag[RowNum - 1] == 0) && (Left_flag[RowNum] == 1)))
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("???");
//                }
//                if ((Right_flag[RowNum] == 0) && (Left_flag[RowNum] == 1) && Lcr[RowNum].RBlack > 120 && Ten_Road_flag == 0 && Annular_flag == 0 && In_Annular_flag == 0 && right_Annular_flag == 0 && left_Annular_flag == 0)
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("?????");
//                }
//                if ((Right_flag[RowNum] == 1) && (Left_flag[RowNum] == 0) && Lcr[RowNum].LBlack < 40 && Ten_Road_flag == 0 && Annular_flag == 0 && In_Annular_flag == 0 && right_Annular_flag == 0 && left_Annular_flag == 0)
//                {
//                    youxiao = RowNum;//youxiao=0????
//                    LcrlenBool = 1;
//                    //setText?????("?????");
//                }
//            }
//            if (LcrlenBool == 0)
//            {
//                if (RowNum == 0)
//                {
//                    if (Lcr[RowNum].Center >= 155 && Lcr[RowNum].Center != 255)
//                    {
//                        for (i = RowNum; i < 70; i++)
//                        {
//                            if (P_Pixels[i][ Lcr[RowNum].Center] == 0)
//                            {
//                                black_line = (uint8_t)i;
//                                break;
//                            }
//                        }
//                        if (black_line - RowNum <= 10)
//                        {
//                            Edge_flag = 1;
//                            Edge_line = RowNum;
//                            youxiao = RowNum;//youxiao=0????
//                            //setText?????("Edge_flag" + Edge_line);
//                        }
//                    }
//                    else if (Lcr[RowNum].Center <= 4)
//                    {
//                        for (i = RowNum; i < 70; i++)
//                        {
//                            if (P_Pixels[i][ Lcr[RowNum].Center] == 0)
//                            {
//                                black_line = (uint8_t)i;
//                                break;
//                            }
//                        }
//                        if (black_line - RowNum <= 10)
//                        {
//                            Edge_flag = 1;
//                            Edge_line = RowNum;
//                            youxiao = RowNum;//youxiao=0????
//                            //setText?????("Edge_flag" + Edge_line);
//                        }
//                    }
//                }
//                else
//                {
//                    if (Lcr[RowNum].Center >= 155 && Lcr[RowNum].Center != 255)
//                    {
//                        if (Edge_line_temp == 0) Edge_line_temp = RowNum;

//                        for (i = RowNum; i < 70; i++)
//                        {
//                            if (P_Pixels[i][ Lcr[RowNum].Center] == 0)
//                            {
//                                black_line = (uint8_t)i;
//                                break;
//                            }
//                        }
//                        if (black_line - RowNum <= 10 && Lcr[RowNum].RBlack - Lcr[RowNum - 1].RBlack >= 3)
//                        {
//                            Edge_flag = 1;
//                            Edge_line = Edge_line_temp;
//                            youxiao = RowNum;//youxiao=0????
//                            //setText?????("Edge_flag" + Edge_line_temp);
//                        }
//                    }
//                    else if (Lcr[RowNum].Center <= 4)
//                    {
//                        if (Edge_line_temp == 0) Edge_line_temp = RowNum;

//                        for (i = RowNum; i < 70; i++)
//                        {
//                            if (P_Pixels[i][ Lcr[RowNum].Center] == 0)
//                            {
//                                black_line = (uint8_t)i;
//                                break;
//                            }
//                        }
//                        if (black_line - RowNum <= 10 && Lcr[RowNum - 1].LBlack - Lcr[RowNum].LBlack >= 3)
//                        {
//                            Edge_flag = 1;
//                            Edge_line = Edge_line_temp;
//                            youxiao = RowNum;//youxiao=0????
//                            //setText?????("Edge_flag" + Edge_line_temp);
//                        }
//                    }
//                }
//            }
//            //#endregion
//            /***************************************??????****************************************/
//            //#region
//            //if (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack <= 12 && straight_cnt >= 8&& RowNum<=60)
//            //{
//            //    ////setText?????("???1??" + RowNum);
//            //    for (i = Row_Pro_value_byte(RowNum + 1); i < Row_Pro_value_byte(RowNum + 10); i++)
//            //    {
//            //        for (lie = 80; lie > Pro_value_byte(80 -fixvalue[i]/2); lie--)
//            //        {
//            //            if (P_Pixels[i, Pro_value_byte(lie)] == 0 && P_Pixels[i, Pro_value_byte(lie - 1)] == 0)//&& P[Pro_value_byte(lie - 2)] == 0)
//            //            {
//            //                Lcr[i].RBlack = lie;
//            //                Right_flag[i] = 1;
//            //                break;
//            //            }
//            //            if (Right_flag[i] != 1)
//            //            {
//            //                Lcr[i].RBlack = 0;
//            //            }
//            //        }
//            //        for (lie = 80; lie < Pro_value_byte(80 + fixvalue[i] / 2); lie++)
//            //        {
//            //            if (P_Pixels[i, Pro_value_byte(lie)] == 0 && P_Pixels[i, Pro_value_byte(lie + 1)] == 0)//&& P[Pro_value_byte(lie + 2)] == 0)
//            //            {
//            //                Lcr[i].LBlack = lie;
//            //                Left_flag[i] = 1;
//            //                break;
//            //            }
//            //            if (Left_flag[i] != 1)
//            //            {
//            //                Lcr[i].LBlack = 160;
//            //            }
//            //        }
//            //        if (Lcr[i].LBlack - Lcr[i].RBlack <= 12)
//            //        {
//            //            Starting_line_cnt++;
//            //            ////setText?????("???2??" + Starting_line_cnt);
//            //            if (Starting_line_cnt >= 1&& Starting_line==0)
//            //            {
//            //                LcrlenBool = 0;
//            //                Starting_line = RowNum;
//            //                Starting_line_flag = 1;
//            //                break;
//            //            }
//            //        }
//            //    }
//                
//                
//                
//            //}
//            //#endregion
//        }
//        void FieldProcess() //?????????
//        {
//					LCR  *Lcr=(LCR *)Sent_Data->Lcr;
//            ////setText?????("Last_field_RBlack"+ Last_field_RBlack);
//            ////setText?????("Last_field_LBlack" + Last_field_LBlack);
//            Ten_Road_flag = 0;
//            not_ten_flag = 0;
////            obstacle_flag = 0;
//            Starting_line_cnt = 0;
//            Starting_line_flag = 0;
//            //if (Starting_line == 0&& Starting_line_flag!=2)
//            //{
//            //    Starting_line_flag = 0;
//            //}
//            last_left_right_line = left_right_line;
//            last_right_right_line = right_right_line;
//            last_ten_line = ten_line;
//            last_left_Annular_line = Annular_Lline;//??????????
//            last_right_Annular_line = Annular_Rline;//??????????
//            //left_error_flag = 0;//???????
//            //right_error_flag = 0;//???????
//            //Annular_flag = 0;
//            if (youxiao == 0)
//                youxiao = 70;
//            /***************************************?????****************************************/
//            /***************************************??****************************************/
//            //#region
//            if(right_Annular_flag == 1)
//            //setText?????("???");
//            if (left_Annular_flag == 1)
//                //setText?????("???");
//            if (Annular_turn_right_flag == 1 && Out_Annular_flag == 1&& Left_flag[0] == 0)
//            {
//                Annular_cnt = 1;
//            }
//            if (Annular_cnt != 0 && Out_Annular_flag == 1&& Left_flag[0] == 1)
//            {
//                Annular_cnt++;
//                if (Annular_cnt > 120)
//                {
//                    Annular_cnt = 0;
//                    
//                    Out_Annular_flag = 0;
//                    In_Annular_flag = 0;
//                }
//            }
//            if (Annular_turn_left_flag == 1 && Out_Annular_flag == 1 && Right_flag[0] == 0)
//            {
//                Annular_cnt = 1;
//            }
//            if (Annular_cnt != 0 && Out_Annular_flag == 1 && Right_flag[0] == 1)
//            {
//                Annular_cnt++;
//                if (Annular_cnt > 60)
//                {
//                    Annular_cnt = 0;
//                    
//                    Out_Annular_flag = 0;
//                    In_Annular_flag = 0;
//                }
//            }
//            //#endregion
//            //???
//            //#region
//            if (In_Annular_flag == 2&& Annular_flag == 1)
//            {
//                In_Annular_flag = 1;
//            }
//            if (Annular_flag == 1 && Annular_count < 3)
//            {
//                Annular_flag = 0;
//                Annular_count++;
//            }
//            if (Annular_count >= 3)
//            {
//                In_Annular_flag = 1;
//            }
//            if (In_Annular_flag == 2)
//            {
//                //setText?????("???");
//            }
//            if (Annular_flag == 1)
//            {
//                //setText?????("???1");
//            }
//            last_left_car_line = left_car_line;
//            last_right_car_line = right_car_line;
//            if (Annular_turn_right_flag == 1 && Annular_flag == 1)//&& Annular_count>=3)//?
//            {
//                for (lie = 0; lie < youxiao; lie++)
//                {
//                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + fixvalue[lie] / 2));
//                }
//            }
//            if (Annular_turn_left_flag == 1 && Annular_flag == 1)//?
//            {
//                for (lie = 0; lie < youxiao; lie++)
//                {
//                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].LBlack - fixvalue[lie] / 2));
//                }
//            }
//            //#endregion
//            //???
//            //#region
////						if (straight_cnt >= 32&& Out_Annular_flag==1)
////            {
////                Out_Annular_flag = 0;
////                In_Annular_flag = 0;
////            }
//            if (Annular_turn_right_flag == 1 && In_Annular_flag == 2 && Out_Annular_flag == 1 && Out_Annular_count < 5 && Last_field_LBlack == 0 && Annular_Lline <= 10)//&& Out_Annular_count>=3)
//            {

//                Out_Annular_flag = 0;
//                In_Annular_flag = 0;

//            }
//            if (Annular_turn_left_flag == 1 && In_Annular_flag == 2 && Out_Annular_flag == 1 && Out_Annular_count < 5 && Last_field_RBlack == 0 && Annular_Rline <= 10)//&& Out_Annular_count >= 3)
//            {

//                Out_Annular_flag = 0;
//                In_Annular_flag = 0;

//            }
//            if (Annular_turn_left_flag == 1 && In_Annular_flag == 2 && (youxiao >= 60) && Annular_flag != 1 && Right_flag[0] != 0)// && last_left_Annular_line >= 45&& Lcr[Annular_Lline].RBlack == 0 && Annular_Lline != 0)
//            {
//                //Out_Annular_count++;
//                Out_Annular_sub = 0;
//            }
//            else Out_Annular_sub = 1;
//            if (Annular_turn_right_flag == 1 && In_Annular_flag == 2 && (youxiao >= 60) && Annular_flag != 1 && Left_flag[0] != 0)// && last_left_Annular_line >= 45&& Lcr[Annular_Lline].RBlack == 0 && Annular_Lline != 0)
//            {
//                //Out_Annular_count++;
//                Out_Annular_sub = 0;
//            }
//            else Out_Annular_sub = 1;
//            if (Annular_line == 0)
//                Out_Annular_flag = 0;
//            if (Annular_turn_right_flag == 1 && In_Annular_flag == 2)//?
//            {
//                if (Out_Annular_flag == 0)
//                {
//                    for (lie = 1; lie < youxiao; lie++)
//                    {
//                        if (Left_flag[lie] != 0)
//                        {
//                            Right_sub = Lcr[lie].RBlack - Lcr[lie - 1].RBlack;
//                            Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Right_sub);
//                            Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                        }
//                        else
//                            Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].RBlack + fixvalue[lie - 1] / 2);
//                    }
//                }
//                else
//                {
//                    //setText?????("???"+ Annular_line);
//                    for (lie = 1; lie < youxiao; lie++)
//                    {
//                        if (Annular_line != 0)
//                        {
//                            if (lie <= Annular_line)
//                                Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + fixvalue[lie] / 2));
//                            else
//                            {
//                                if (Left_flag[lie] == 1 && Right_flag[lie] == 1)
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                                else
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].LBlack - fixvalue[lie] / 2));
//                                //Left_sub = Lcr[lie].LBlack - Lcr[lie - 1].LBlack;
//                                //Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Left_sub);
//                            }
//                        }
//                        else
//                        {
//                            if (lie <= Annular_Rline)
//                                Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + fixvalue[lie] / 2));
//                            else
//                            {
//                                if (Left_flag[lie] == 1 && Right_flag[lie] == 1)
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                                else
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].LBlack - fixvalue[lie] / 2));
//                                //Left_sub = Lcr[lie].LBlack - Lcr[lie - 1].LBlack;
//                                //Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Left_sub);
//                            }
//                        }
//                    }
//                }
//            }
//            if (Annular_turn_left_flag == 1 && In_Annular_flag == 2)//?
//            {
//                if (Out_Annular_flag == 0)
//                {
//                    for (lie = 1; lie < youxiao; lie++)
//                    {
//                        if (Right_flag[lie] != 0)
//                        {
//                            Left_sub = Lcr[lie].LBlack - Lcr[lie - 1].LBlack;
//                            Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Left_sub);
//                            Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                        }
//                        else
//                            Lcr[lie].Center = Pro_value_byte((Lcr[lie - 1].LBlack - fixvalue[lie - 1] / 2));
//                    }
//                }
//                else
//                {
//                    //setText?????("???" + Annular_line);
//                    for (lie = 1; lie < youxiao; lie++)
//                    {
//                        if (Annular_line != 0)
//                        {
//                            if (lie <= Annular_line)
//                                Lcr[lie].Center = Pro_value_byte((Lcr[lie].LBlack - fixvalue[lie] / 2));
//                            else
//                            {
//                                if (Left_flag[lie] == 1 && Right_flag[lie] == 1)
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                                else
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + fixvalue[lie] / 2));
//                                //Right_sub = Lcr[lie].RBlack - Lcr[lie - 1].RBlack;
//                                //Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Right_sub);
//                            }
//                        }
//                        else
//                        {
//                            if (lie <= Annular_Lline)
//                                Lcr[lie].Center = Pro_value_byte((Lcr[lie].LBlack - fixvalue[lie] / 2));
//                            else
//                            {
//                                if (Left_flag[lie] == 1 && Right_flag[lie] == 1)
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                                else
//                                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + fixvalue[lie] / 2));
//                                //Right_sub = Lcr[lie].RBlack - Lcr[lie - 1].RBlack;
//                                //Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Right_sub);
//                            }
//                        }
//                    }
//                }
//            }
//            //#endregion
//            /***************************************??****************************************/

//            /*???? ????????????*/
//            if (Annular_flag == 0 && In_Annular_flag == 0 && right_Annular_flag == 0 && left_Annular_flag == 0)
//            {
//                //?????
//                //#region
//                if (((left_error_line <= 62 && right_error_line <= 62 && left_error_line >= 15 && right_error_line >= 15 && Difference(left_error_line, right_error_line) <= 10) || ((left_ten_flag == 1 || right_ten_flag == 1) && ten_error_cnt >= 5))
//                    || (ten_error_cnt >= 3) || (Right_flag[0] == 0 && Left_flag[0] == 0 && Right_flag[1] == 0 && Left_flag[1] == 0 && Right_flag[2] == 0 && Left_flag[2] == 0))
//                {
//                    Ten_Road_flag = 1;
//                    //setText?????("??");
//                }
//                else if (Ten_Road_flag != 1 && (left_error_line != 0 && left_error_line < 55 && left_error_line > 5 && (Right_flag[left_error_line] == 0 || Right_flag[left_error_line - 1] == 0
//                    || Right_flag[left_error_line - 2] == 0 || Right_flag[left_error_line - 3] == 0 || Right_flag[left_error_line - 4] == 0 || Right_flag[left_error_line - 5] == 0)))//&& (left_ten_flag == 1 && right_transmit_cnt >= 10 && left_error_line - right_transmit_cnt <= 3 && left_error_line < 50))
//                {
//                    Ten_Road_flag = 2;
//                    //setText?????("?????"+ left_error_line);
//                }
//                else if (Ten_Road_flag != 1 && (right_error_line != 0 && right_error_line < 55 && right_error_line > 5 && (Left_flag[right_error_line] == 0 || Left_flag[right_error_line - 1] == 0
//                    || Left_flag[right_error_line - 2] == 0 || Left_flag[right_error_line - 3] == 0 || Left_flag[right_error_line - 4] == 0 || Left_flag[right_error_line - 5] == 0)))//&& (right_ten_flag == 1 && left_transmit_cnt >= 10 && right_error_line - left_transmit_cnt <= 3 && right_error_line < 50))
//                {
//                    Ten_Road_flag = 3;
//                    //setText?????("?????"+ right_error_line);
//                }
//                if (Ten_Road_flag == 3 && right_right_line != 0)
//                {
//                    //setText?????("???");
//                }
//                if (Ten_Road_flag == 2 && left_right_line != 0)
//                {
//                    //setText?????("???");
//                }
//                if (Ten_Road_flag == 3 && (right_right_line == 0 || Lcr[right_right_line].RBlack > 140))
//                {
//                    not_ten_flag = 3;
//                    //setText?????("????");
//                }
//                if (Ten_Road_flag == 2 && (left_right_line == 0|| Lcr[left_right_line].LBlack<20))
//                {
//                    not_ten_flag = 2;
//                    //setText?????("????");
//                }
//                //#endregion
//                
//                /***************************************??????****************************************/
//                //#region
//                if (not_ten_flag == 0 && Ten_Road_flag != 0)
//                {

//                    if (Ten_Road_flag == 1)
//                    {
//                        //setText?????("???" + ten_line);
//                        if (left_error_line <= right_error_line && left_error_line != 0 && right_error_line != 0)
//                            start_line = Row_Pro_value_byte(left_error_line - 10);
//                        else if (left_error_line > right_error_line && left_error_line != 0 && right_error_line != 0)
//                            start_line = Row_Pro_value_byte(right_error_line - 10);
//                        else 
//                            start_line = 0;
//                        end_line = Row_Pro_value_byte(ten_line);
//                        Lcr[start_line].Center = Pro_value_byte((Lcr[start_line].RBlack + Lcr[start_line].LBlack) / 2);
//                        Lcr[end_line].Center = Pro_value_byte((Lcr[end_line].RBlack + Lcr[end_line].LBlack) / 2);
//                        //if (Left_flag[0] == 1 && Right_flag[0] == 1)
//                        //{
//                        //    Lcr[0].Center = Pro_value_byte((Lcr[0].RBlack + Lcr[0].LBlack) / 2);
//                        //}
//                        //if (Left_flag[0] != 1 || Right_flag[0] != 1)
//                        //{
//                        //    Lcr[0].Center = 80;
//                        //}
//                    }
//                    if (Ten_Road_flag == 2 && (right_right_line > 0 || left_right_line > 0))
//                    {
//                        start_line = Row_Pro_value_byte(left_error_line - 10);//???????
//                        end_line = Row_Pro_value_byte(left_right_line);//???????
//                        Lcr[start_line].Center = Pro_value_byte((Lcr[start_line].RBlack + Lcr[start_line].LBlack) / 2);
//                        Lcr[end_line].Center = Pro_value_byte((Lcr[end_line].RBlack + Lcr[end_line].LBlack) / 2);
//                        //if (Left_flag[0] == 1 && Right_flag[0] == 1)
//                        //{
//                        //    Lcr[0].Center = Pro_value_byte((Lcr[0].RBlack + Lcr[0].LBlack) / 2);
//                        //}
//                        //if (Left_flag[0] != 1 || Right_flag[0] != 1)
//                        //{
//                        //    Lcr[0].Center = 80;
//                        //}
//                    }
//                    if (Ten_Road_flag == 3 && (right_right_line > 0 || left_right_line > 0))
//                    {
//                        start_line = Row_Pro_value_byte(right_error_line - 10);//???????
//                        end_line = Row_Pro_value_byte(right_right_line);//???????
//                        Lcr[start_line].Center = Pro_value_byte((Lcr[start_line].RBlack + Lcr[start_line].LBlack) / 2);
//                        Lcr[end_line].Center = Pro_value_byte((Lcr[end_line].RBlack + Lcr[end_line].LBlack) / 2);
//                        //if (Left_flag[0] == 1 && Right_flag[0] == 1)
//                        //{
//                        //    Lcr[0].Center = Pro_value_byte((Lcr[0].RBlack + Lcr[0].LBlack) / 2);
//                        //}
//                        //if (Left_flag[0] != 1 || Right_flag[0] != 1)
//                        //{
//                        //    Lcr[0].Center = 80;
//                        //}
//                    }
//                    if (end_line > youxiao - 1)
//                    {
//                        end_line = Row_Pro_value_byte(youxiao - 1);
//                    }
//                    if (start_line <= 0)
//                    {
//                        start_line = 0;
//                    }

//                    if (end_line - start_line != 0)
//                    {
//                        ratio = ((float)(Lcr[end_line].Center - Lcr[start_line].Center) / (end_line - start_line));//??
//                        constant = ((Lcr[end_line].Center - (float)(ratio * end_line)));//??
//                        for (lie = start_line; lie < end_line; lie++)
//                        {
//                            Lcr[lie].Center = Pro_value_byte((uint8_t)(ratio * lie + constant));
//                            //if (Right_flag[0] == 0 && Left_flag[0] == 0)
//                            //{
//                            //    Lcr[lie].Center = Lcr[end_line].Center;
//                            //}
//                        }
//                        ////setText?????("start" + start_line);
//                        ////setText?????("end" + end_line);
//                        ////setText?????("k" + ratio);
//                        ////setText?????("b" + constant);
//                    }
//                }
//                if (not_ten_flag == 3)
//                {
//                    for (lie = 0; lie <= youxiao; lie++)
//                    {
//                        if (lie <= right_error_line)
//                        {
//                            //Right_sub = Lcr[Row_Pro_value_byte(lie)].RBlack - Lcr[Row_Pro_value_byte(lie - 1)].RBlack;
//                            //Lcr[Row_Pro_value_byte(lie)].Center = Pro_value_byte(Lcr[Row_Pro_value_byte(lie - 1)].Center + Right_sub);
//                            Lcr[lie].Center = Pro_value_byte(Lcr[lie].RBlack + fixvalue[lie] / 2 + Difference(Lcr[0].Center, Lcr[0].RBlack + fixvalue[0] / 2));
//                        }
//                        else
//                        {
//                            Lcr[Row_Pro_value_byte(lie)].Center = Pro_value_byte(Lcr[Row_Pro_value_byte(lie - 1)].Center);
//                        }
//                    }
//                }
//                if (not_ten_flag == 2)
//                {
//                    for (lie = 0; lie <= youxiao; lie++)
//                    {
//                        if (lie <= left_error_line)
//                        {
//                            //Left_sub = Lcr[Row_Pro_value_byte(lie)].LBlack - Lcr[Row_Pro_value_byte(lie - 1)].LBlack;
//                            //Lcr[Row_Pro_value_byte(lie)].Center = Pro_value_byte(Lcr[Row_Pro_value_byte(lie - 1)].Center + Left_sub);
//                            Lcr[lie].Center = Pro_value_byte(Lcr[lie].LBlack - fixvalue[lie] / 2 - Difference(Lcr[0].Center, Lcr[0].LBlack - fixvalue[0] / 2));
//                        }
//                        else
//                        {
//                            Lcr[Row_Pro_value_byte(lie)].Center = Pro_value_byte(Lcr[Row_Pro_value_byte(lie - 1)].Center);
//                        }
//                    }
//                }
//                if (Ten_Road_flag == 1&& (((left_error_line<=20 || right_error_line <= 20) || (right_error_line == 0 || left_error_line == 0)|| (Right_flag[0] == 0 && Left_flag[0] == 0)
//                    ||(right_error_line> ten_line&& ten_line!=0&& right_error_line!=0) || (left_error_line > ten_line && ten_line != 0 && left_error_line != 0))))// &&(Right_flag[0] == 0 || Left_flag[0] == 0)))
//                {
//                    //Lcr[0].Center = 80;
//                    start_line = 0;
//                    end_line = Row_Pro_value_byte(ten_line+3);
//                    //ratio = ((float)(Lcr[end_line].Center - Lcr[start_line].Center) / (end_line - start_line));//??
//                    //constant = ((Lcr[end_line].Center - (float)(ratio * end_line)));//??
//                    for (lie = start_line; lie < end_line; lie++)
//                    {
//                        //Lcr[lie].Center = Pro_value_byte((uint8_t)(ratio * lie + constant));
//                        //if (Right_flag[0] == 0 && Left_flag[0] == 0)
//                        //{
//                        Lcr[lie].Center = Lcr[end_line].Center;
//                        //}
//                    }
//                    //setText?????("???");
//                }
//                //#endregion
//            }
//            /***************************************???????****************************************/
//            //#region
//            if (Annular_flag == 0 && right_Annular_flag == 0 && left_Annular_flag == 0 && Out_Annular_flag == 0)
//            {
//                if (Turn_left_flag == 1 && Ten_Road_flag == 0)//??
//                {
//                    if (youxiao <= 65 && Turn_left_line < youxiao && Left_flag[youxiao - 8] == 0)
//                    {
//                        //setText?????("??");
//                        for (lie = (uint8_t)(Turn_left_line-1); lie < youxiao; lie++)
//                        {
//                            if (Left_flag[0] == 0 && Left_flag[lie] == 0)
//                            {
//                                Lcr[lie].Center = Pro_value_byte(Lcr[lie].RBlack + fixvalue[lie] / 2 + Difference(Lcr[0].Center, Lcr[0].RBlack + fixvalue[0] / 2));

//                                Road_flag = 3;
//                                //setText?????("???");
//                            }
//                            else if (Left_flag[lie] == 1 && Right_flag[lie] == 1)
//                            {
//                                //Right_sub = Lcr[lie].RBlack - Lcr[lie - 1].RBlack;
//                                //Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Right_sub);
//                                Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                            }
//                            else
//                            {
//                                Right_sub = Lcr[lie].RBlack - Lcr[lie - 1].RBlack;
//                                Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Right_sub);
//                            }
//                        }
//                    }
//                    else
//                    {
//                        Turn_left_flag = 0;
//                        left_miss_flag = 1;//????????    
//                        //setText?????("???");
//                    }
//                }
//                if (Turn_right_flag == 1 && Ten_Road_flag == 0)//??
//                {
//                    if (youxiao <= 65 && Turn_right_line < youxiao && Right_flag[youxiao - 8] == 0)
//                    {
//                        //setText?????("??");
//                        for (lie = (uint8_t)(Turn_right_line-1); lie < youxiao; lie++)
//                        {
//                            if (Right_flag[0] == 0 && Right_flag[lie] == 0)
//                            {
//                                Lcr[lie].Center = Pro_value_byte(Lcr[lie].LBlack - fixvalue[lie] / 2 - Difference(Lcr[0].Center, Lcr[0].LBlack - fixvalue[0] / 2));
//                                Road_flag = 3;
//                                //setText?????("???");
//                            }
//                            else if (Left_flag[lie] == 1 && Right_flag[lie] == 1)
//                            {
//                                //Left_sub = Lcr[lie].LBlack - Lcr[lie - 1].LBlack;
//                                //Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Left_sub);
//                                Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                            }
//                            else
//                            {
//                                Left_sub = Lcr[lie].LBlack - Lcr[lie - 1].LBlack;
//                                Lcr[lie].Center = Pro_value_byte(Lcr[lie - 1].Center + Left_sub);

//                            }
//                        }
//                    }
//                    else
//                    {
//                        Turn_right_flag = 0;
//                        right_miss_flag = 1;//????????
//                        //setText?????("???");
//                    }
//                }
//            }
//            //#endregion
//            
//            /***************************************???????****************************************/
//            //#region
//            
//            //if (Turn_left_flag == 0 && Turn_right_flag == 0 && Small_S_flag == 0 && Ten_Road_flag == 0 && Annular_flag == 0 && In_Annular_flag == 0
//            //    && Out_Annular_flag == 0 && youxiao >= 55 && (((Annular_Lline != 0 && Annular_Lline <= 60)|| (left_error_line!=0 && left_error_line <= 60)) && ((Annular_Rline != 0 && Annular_Rline <= 60) || (right_error_line != 0 && right_error_line <= 60))))// || left_miss_flag == 1 || right_miss_flag == 1))
//            //{
//            //    Road_flag = 4;
//            //    //setText?????("??");

//            //}
//            
//            if (straight_cnt >= 52 && Small_S_flag == 0 && left_miss_flag == 0 && right_miss_flag == 0 && Turn_left_flag == 0 && Turn_right_flag == 0 && Ten_Road_flag == 0
//                && Annular_flag == 0 && In_Annular_flag == 0 && Out_Annular_flag == 0 && youxiao >= 55 && Annular_Lline == 0 && Annular_Rline == 0)
//            {
//                Road_flag = 11;
//                //setText?????("???");
//                if (Starting_line_cnt < 5)
//                    Starting_line_cnt++;
//            }
//            if (straight_cnt >= 42 && Small_S_flag == 0 && Road_flag != 11 && Ten_Road_flag == 0 && Annular_flag == 0 && In_Annular_flag == 0 && Out_Annular_flag == 0 && youxiao >= 55 && Annular_Lline == 0 && Annular_Rline == 0)
//            {
//                Road_flag = 12;
//                //setText?????("???");
//                if (Starting_line_cnt < 5)
//                    Starting_line_cnt++;
//            }

//            if (Small_S_flag == 0 && Ten_Road_flag == 0 && Annular_flag == 0 && In_Annular_flag == 0 && Out_Annular_flag == 0 && youxiao >= 55 && ((Annular_Lline != 0 && Annular_Lline <= 60) || (Annular_Rline != 0 && Annular_Rline <= 60) || left_miss_flag == 1 || right_miss_flag == 1))
//            {
//                Road_flag = 2;
//                //setText?????("??");

//            }
//            if (straight_cnt>=3&&Road_flag != 2&&Road_flag != 3&&ramp_cnt >= 10 && Small_S_flag == 0 && left_miss_flag == 0 && right_miss_flag == 0 && Turn_left_flag == 0 && Turn_right_flag == 0 && Ten_Road_flag == 0
//                && Annular_flag == 0 && In_Annular_flag == 0 && Out_Annular_flag == 0 && youxiao >= 50 && Annular_Lline == 0 && Annular_Rline == 0)
//            {
//                ramp_flag = 1;
//                //setText?????("??");
//            }
//						if (ramp_flag!=1)
//						{
//						Obstacle_deal();
//            Small_S_road_deal();
//						if(Obstacle_location!=0)
//							obstacle_flag=1;
//					}
//						if (ramp_flag==1)
//            {
//                ramp_chang+=(EncoderA_Cnt+EncoderB_Cnt)/2;
//								Annular_flag = 0;
//								Out_Annular_flag = 0;
//                In_Annular_flag = 0;
//							Road_flag=0;
////							for(lie=0;lie<70;lie++)
////							{
////								Lcr[lie].Center = Pro_value_byte((Lcr[0].RBlack + Lcr[0].LBlack) / 2);
////							}
//                if (ramp_chang >= ramp_chang_yuzhi)
//                {
//									ramp_chang=0;
//                    ramp_flag = 0;
//                }
//								OLED_Write_Num5(1,4,ramp_chang);
//            }
//            if (left_miss_flag == 1 && right_miss_flag == 1 && Turn_left_flag != 1 && Turn_right_flag != 1 && Ten_Road_flag != 1 && Annular_flag != 1)
//            {
//                for (lie = 0; lie < youxiao; lie++)
//                {
//                    Lcr[lie].Center = Pro_value_byte((Lcr[lie].RBlack + Lcr[lie].LBlack) / 2);
//                }

//            }
//            if(brake_flag == 2) brake_flag = 0;
//            if ((last_Road_flag == 11|| last_Road_flag == 12)&& Road_flag!=11 && Road_flag != 12)
//            {
//                brake_flag = 1;
//            }
//            if (brake_flag == 1)
//            {
//                brake_cnt++;
//                if (Road_flag != 11 && Road_flag != 12)
//                {
//                    brake_cnt1++;
//                }
//                if(brake_cnt - brake_cnt1 != 0)
//                {
//                    brake_flag = 0;
//                    brake_cnt = 0;
//                    brake_cnt1 = 0;
//                }
//                if (brake_cnt1 >= 3)
//                {
//                    brake_flag = 2;
//                    brake_cnt = 0;
//                    brake_cnt1 = 0;
//                    //setText?????("??");
//                }
//            }
//                if (P_Pixels[0][Lcr[0].Center]==0&& P_Pixels[1][ Lcr[0].Center] == 0 && P_Pixels[2][ Lcr[0].Center] == 0)
//            {
//                stop_cnt++;
//                if (stop_cnt >= 50)
//                {
//                    stop_flag = 1;
//                    //setText?????("??");
//                }
//            }
//            if (stop_cnt!=0)
//            {
//                chang_cnt ++;
//                if (chang_cnt - stop_cnt >= 20)
//                {
//                    chang_cnt = 0;
//                    stop_cnt = 0;
//                }
//            }
//						if(Road_flag==2&&last_Road_flag!=2)
//						{
//							brake_flag=2;
//						}
//						if(obstacle_flag!=0||ramp_flag==1)
//						{
//							brake_flag=2;
//						}
//						if(Small_S_flag==0&&last_Small_S_flag==1)
//						{
//							brake_flag=2;
//						}
//						if((/*Annular_flag==1||*/Ten_Road_flag!=0&&(last_Road_flag==11||last_Road_flag==12))&&brake==0)
//						{
//							brake=1;
//							brake_flag=2;
//						}
//						last_Small_S_flag=Small_S_flag;
//            last_Road_flag = Road_flag;
//            //#endregion
//            /***************************************??????****************************************/
//            //#region 
//            //if (Starting_line_flag==1)
//            //{
//            //    Starting_line_chang++;
//            //    if (Starting_line_chang >= 5)
//            //    {
//            //        Starting_line_flag = 2;
//            //        Starting_line_chang = 0;
//            //        //setText?????("???" + Starting_line);
//            //    }
//            //}
//            //if (Starting_line_flag == 2)
//            //{
//            //    Starting_line_chang ++;
//            //    if (Starting_line_chang >= 6)
//            //    {
//            //        stop_flag = 1;
//            //    }
//            //}
//            //if(stop_flag == 1)
//            ////setText?????("??");
//            if (straight_cnt >= 16 && youxiao <= 40 && Small_S_flag == 0 && left_miss_flag == 0 && right_miss_flag == 0 && Turn_left_flag == 0 && Turn_right_flag == 0 && Ten_Road_flag == 0
//                && Annular_flag == 0 && In_Annular_flag == 0 && Out_Annular_flag == 0 && Annular_Lline == 0 && Annular_Rline == 0)
//            {
//							
//                for (lie = (uint8_t)(Lcr[0].RBlack); lie <= Pro_value_byte(Lcr[0].RBlack + fixvalue[0]); lie++)
//                {
//														
//                    //if ((P_Pixels[Row_Pro_value_byte(youxiao - 3), Pro_value_byte(i)] == 0 && P_Pixels[Row_Pro_value_byte(youxiao - 3), Pro_value_byte(i - 1)] == 1)
//                    //    || (P_Pixels[Row_Pro_value_byte(youxiao - 3), Pro_value_byte(i)] == 1 && P_Pixels[Row_Pro_value_byte(youxiao - 3), Pro_value_byte(i - 1)] == 0))
//                    if ((P_Pixels[Row_Pro_value_byte(youxiao - 2)][Pro_value_byte(lie)] == 0 && P_Pixels[Row_Pro_value_byte(youxiao - 2)][Pro_value_byte(lie + 1)] != 0)
//                        || (P_Pixels[Row_Pro_value_byte(youxiao - 2)][Pro_value_byte(lie)] != 0 && P_Pixels[Row_Pro_value_byte(youxiao - 2)][Pro_value_byte(lie + 1)] == 0))
//                    {
//                        Starting_line_cnt++;
//                        if (Starting_line_cnt >= 4)
//                        {
//                            Starting_line_flag = 1;
//													Starting_line_flag1=1;
////                            for (i = 0; i <= 69; i++)
////                                Lcr[i].Center = 80;
//                            break;
//                        }
//                    }
//                }
//            }
//						
//            if (delay_chag==0&&Starting_line_flag == 1)
//            {
//                Starting_line_chang++;
//                stop_flag = 1;
//            }
//            if (Starting_line_chang >= 3)
//            {
//                //setText?????("???");
//                stop_flag = 1;
//            }
//						if(Starting_line_flag1==1)
//						{
//							start_chang+=(EncoderA_Cnt+EncoderB_Cnt)/2;
//							if(start_chang>=start_chang_yuzhi)
//								Starting_line_flag1=0;
//						}
//						if(Starting_line_stop_flag==0)
//							{
//								stop_flag=0;
//								Starting_line_chang=0;
//							}
//						if (Starting_line_flag1 == 1)
//            {
//                for (i = 0; i <= 69; i++)
//                    Lcr[i].Center = Lcr[0].Center;
//            }

//            //#endregion
//            //setText?????("???" + youxiao); 
//                //setText?????("???" + straight_cnt); 
//                //setText?????("Small_s_cnt" + Small_s_cnt);
//            //setText?????("ramp_cnt" + ramp_cnt);
//						if (straight_cnt>=56&& Out_Annular_flag==1)
//            {
//                Out_Annular_flag = 0;
//                In_Annular_flag = 0;
//            }
//								if(straight_cnt>=5&&ramp_cnt>=3&&Road_flag!=2&&Road_flag!=3&& Small_S_flag == 0 && left_miss_flag == 0 && right_miss_flag == 0 && Turn_left_flag == 0 && Turn_right_flag == 0 && Ten_Road_flag == 0
//                && Annular_flag == 0 && In_Annular_flag == 0 && Out_Annular_flag == 0 && Annular_Lline == 0 && Annular_Rline == 0&& not_ten_flag == 0)BBB(1);//Annular_flag==1||In_Annular_flag==1||Out_Annular_flag==1)BBB(1);
//								else BBB(0);
//								
//        }
//        void SignalProcess()//????.left
//        {
//					LCR  *Lcr=(LCR *)Sent_Data->Lcr;
////					BBB(1);
//            Image_Init();//????? 
//            for (RowNum = 0; RowNum < Image_Height; RowNum++) //????
//            {
////							if(ramp_flag!=1)
//                P=Pixels+RowNum*Image_Width;
//                if (LcrlenBool != 0||Edge_flag ==1)
//                {
//                    Lcr[RowNum].LStart = Lcr[RowNum].LBlack = Lcr[RowNum].LEnd = Lcr[RowNum].Center =
//                    Lcr[RowNum].RStart = Lcr[RowNum].RBlack = Lcr[RowNum].REnd = 0xFF;//????????
//                    goto Line_ImageData_Process;    //?????
//                }
//                ImageProcess(); //????? ????
////								BBB(0);

//                Line_ImageData_Process: ;
//                //---------------------------------------------------------------------------------------------------------------
//            }
//            
//							FieldProcess();//?????????
//						
//            Last_field_Center = Lcr[0].Center; //????0???
//            Last_field_LBlack = Lcr[0].LBlack;
//            Last_field_RBlack = Lcr[0].RBlack;
//						if (youxiao <= 15)
//            {
//                Last_field_Center = 80;
//            }
//            ////////////setText?????("Turn_left_flag" + Turn_left_flag);
//            ////////////setText?????("Turn_right_flag" + Turn_right_flag);
//           // Last_field_T_center = Lcr[18].Center;
//        }
//void image_processe(void)
//{
//	SignalProcess();
//	Engine_Control();
//	Motor_Control();
//	
//	
//	
//}
	
