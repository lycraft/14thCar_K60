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
//		int LcrlenBool = 0;//ͼ��ضϱ�־
uint8 colour[2] = {255, 0},black=1,white=0; //0 �� 1 �ֱ��Ӧ����ɫ
//ע��ɽ�������ͷ 0 ��ʾ ��ɫ��1��ʾ ��ɫ
extern uint8_t 	threshold;
uint8_t stop_line;


        uint8_t Last_field_T_center = 100;
        uint8_t Last_field_Center = 100;//�ϳ�0������ֵ
        uint8_t Last_field_LBlack = 170;
        uint8_t Last_field_RBlack = 35;
        uint8_t Search_sub = 10;//������������Χ��
        uint8_t Right_blank;
        uint8_t Left_blank;
        uint8_t Right_miss;
        uint8_t Left_miss;


        int Left_sub;//����������в�ֵ
        int Right_sub;//����������в�ֵ
        float Sub_d;//����΢��


        uint8_t Turn_left_flag_last = 0;
        uint8_t Turn_right_flag_last = 0;
        uint8_t Turn_line;//������

        float Turn_K1;//б��һ
        float Turn_K2;//б�ʶ�
        uint8_t Wait_flag = 0;//�ȴ����߱�־


        float Obstacle_slope;


        uint8_t Singlet_right = 0;

        uint8_t Huan_flag_lr [4]=
        {
            1,1,0,0,
        };

        uint8_t First_K = 0;
        int K_average = 0; //��������ʱ���ߵ�б��
        uint8_t Ten_cnt = 0;

        uint8_t Ten_first = 0;
        uint8_t Ten_two_void = 0;
        uint8_t No_black_count = 0;

        uint8_t Out_track_cnt = 0;

        uint8_t Edge_flag = 0;//���߱�Ե����־
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



        uint8_t Centerline_kalman(uint8_t data_now, uint8_t data_last)//���߿������˲�
        {
            uint8_t center_Q = 2;
            uint8_t center_R = 5;

            center_NowData_P = center_RealData_P + center_Q;
            center_Kg = center_NowData_P * center_NowData_P / (center_NowData_P * center_NowData_P + center_R * center_R);
            center_RealData = ((1 - center_Kg) * data_now + center_Kg * data_last);
            center_RealData_P = (1 - center_Kg) * center_NowData_P;
            return (uint8_t)center_RealData;
        }

        uint8_t Pro_value_byte(int value)   //��ֵԽ�籣������ (byte��)
        {
            if (value >= 158)
                value = 158;
            else if (value <= 2)
                value = 2;
            return (uint8_t)value;
        }

//        void Least_Square_Method(uint8_t BasedLine, uint8_t FinalLine) //��С���˷�
//        {
//            int AvaliableLines;
//            int MiddleLine;
//            int SumX, SumY, SumUp, SumDown;
//            int AverageX, AverageY;
//            int A, B;

//            AvaliableLines = FinalLine - BasedLine;
//            MiddleLine = (BasedLine + FinalLine) / 2;
//            SumX = 0;
//            SumY = 0;
//            for (i = BasedLine; i < FinalLine; i++)
//            {
//                SumX += i;
//                SumY += Lcr[i].Center;
//            }
//            AverageX = SumX / AvaliableLines;
//            AverageY = SumY / AvaliableLines;
//            SumUp = 0;
//            SumDown = 0;
//            for (i = BasedLine; i < FinalLine; i++)
//            {
//                SumUp += (Lcr[i].Center - AverageY) * (i - AverageX);
//                SumDown += (i - AverageX) * (i - AverageX);
//            }
//            if (SumDown == 0) B = 0;
//            else B = (int)(SumUp / SumDown);
//            A = (SumY - B * SumX) / AvaliableLines;

//            for (i = BasedLine; i < FinalLine; i++)
//            {
//                Lcr[i].Center = Pro_value_byte(A + B * i);
//            }

//        }

        void Centerline_kalman_deal()//���߿������˲�
        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            //------------------------���߿������˲�------------------------------------------------
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
        uint8_t Pro_value_byte_1(int value)   //��ֵԽ�籣������ (byte��)
        {
            if (value >= 70)
                value = 70;
            return (uint8_t)value;
        }

        uint8_t lie;                         //��ɨ��
        uint8_t use_lie;                     //�ض���
        uint8_t first_start = 80;            //��һ��ɨ�����
		  uint8_t First_find_left = 0;         //���Ƽ�¼��һ���������//��һ��ûɨ������
        uint8_t First_find_right = 0;         //���Ƽ�¼��һ���������//��һ��ûɨ������
        uint8_t First_turn_left = 0;         //���Ƽ�¼��һ���������//��һ��ûɨ������
        uint8_t First_yuan_left = 0;         //���Ƽ�¼��һ���������//��һ��ûɨ������
        uint8_t First_yuan_right = 0;         //���Ƽ�¼��һ���������//��һ��ûɨ������
        uint8_t First_turn_right = 0;        //���Ƽ�¼��һ���ҹ�����
        uint8_t Second_turn_left = 0;         //���Ƽ�¼��һ���������//��һ��ûɨ������
        uint8_t Second_turn_right = 0;        //���Ƽ�¼��һ���ҹ�����
        uint8_t Turn_left_flag = 0;          //���ߴ���
        uint8_t Turn_right_flag = 0;         //�Ҷ��ߴ���
        uint8_t Turn_left_dui = 0;          //���ߴ���
        uint8_t Turn_right_dui = 0;         //�Ҷ��ߴ���
        uint8_t Left_flag [70];      //��û��ɨ�� 0û�� 1��
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
        /*********************************ʮ�ֱ���****************************************/
        uint8_t Ten_frist_flag = 0;                          //ʮ�ֹս�//��ʼ��
        uint8_t Ten_Road_flag = 0;                           //ʮ�ֱ�־λ//����//1��11��2��22��111��222��3
        uint8_t Ten_now_line = 0;                            //ʮ������ //������ 
        uint8_t Ten_state_change = 0;
        uint8_t Ten_Road_state = 0;                          //ʮ��λ��
        uint8_t Ten_Road_Times = 0;                          //ʮ�ִ���
        /*********************************���α���****************************************/
        //uint16_t Huan_Road_flag = 0;                          //���α�־λ
        uint8_t Huan_frist_flag = 0;                         //���ιս�
        uint8_t Huan_left_min = 0;
        uint8_t Huan_right_min = 0;
        uint8_t Huan_left_min_Row = 0;
        uint8_t Huan_right_min_Row = 0;
        uint8_t Huan_middle_Row = 0;
        uint8_t Huan_left_Black_Row = 0;
        uint8_t Huan_left_Black_lie = 0;
        uint8_t Huan_right_Black_Row = 0;
        uint8_t Huan_right_Black_lie = 0;
        uint8_t Huan_middle_Black_Row = 0;
        uint8_t Huan_state = 0;                              //����λ�ñ�־λ 0��δ������ 1�������� 2��������
        uint8_t Huan_state_change = 0;
        uint8_t Huan_times = 0;                              //�����δ���
        uint8_t Huan_Overtake = 0;
        uint8_t Huan_turn_flag [5]=                  //1����ת   2����ת
       {
          1,2,0,0,0
       };
        uint8_t Last_Center[70]=              
{
        101,100,99,98,97,96,94,94,92,91,
        90,89,88,86,86,84,83,82,81,80,
        78,77,76,74,73,71,71,70,68,68,
        66,66,64,63,62,61,60,58,58,56,
        55,54,52,51,50,49,47,47,45,43,
        43,41,41,39,38,37,35,35,33,31,
        31,29,27,27,25,23,23,21,20,18,
};
        /*********************************ͣ������****************************************/
        uint8_t Stop = 0;
        uint8_t Stop_found = 0;
        uint8_t First_left_start = 0;
        uint8_t First_right_start = 0;
        /*********************************ֱ������****************************************/
        uint8_t Straight_flag = 0;
        uint8_t Straight_error = 0;
        /*********************************ֱ������***************************************/
        uint8_t Straight_overtake_flag = 0;
        uint8_t Straight_overtake_temp = 0;
        uint8_t Straight_overtake_err = 0;
        uint8_t Straight_times = 0;
        uint8_t Straight_times_max = 3;
        uint8_t Straight_Record [3]=
{
            1,1,1
};
        /*********************************�ϰ�����****************************************/
        uint8_t obstacles_flag = 0;//�ϰ�λ�ñ�־  2Ϊ���ϰ���1λ���ϰ�
        uint8_t obstacles_wide = 0;          //�ϰ����־λ
        uint8_t Chang_times = 0;            //������ʱ��
        /*********************************СSԪ��****************************************/
        uint8_t Small_S_flag = 0; //����СS���жϱ�־
        uint8_t Small_S_center = 0;
        /*********************************�µ�Ԫ��****************************************/
        uint8_t Rampway = 0;
        uint8_t Ramp_Record[7]=             
{
            0,0,0,0,0,0,0
};


        uint8_t Fabs(int data)
        {
            if (data >= 0)
                return (uint8_t)data;
            else
                return (uint8_t)(-data);

        }
        float Center_variance(uint8_t line) //ÿ���е�ƫ��ķ���
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
            // setText�û��Զ���("·������" + f_sum);

            return f_sum;
        }
        void Small_S_road_deal() //СS�䴦��
        {LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            uint8_t left_min_value = 0, left_max_value = 0, right_max_value = 0, right_min_value = 0;//�����С��ֵ��
            uint8_t num;
            uint8_t effect_line = 0;
            uint8_t center_end_line = 0;
            float variance;


            for (num = 10; num < 60; num++)
            {
                if (Left_flag[num] == 1 && Right_flag[num] == 1)
                {
                    effect_line++;
                }
            }

            for (num = 0; num < 10; num++)
            {
                if (Left_flag[num] == 1 && Right_flag[num] == 1)
                {
                    center_end_line++;
                }
            }
            variance = Center_variance(45);
            //setText�û��Զ���("variance" + variance);

            if (effect_line >= 50 && variance <= 5 && center_end_line >= 8)
            {

                //#region
                for (num = 6; num < 62; num++)
                {
                    if (num <= 15 || num >= 55)
                    {
                        if (
                            Lcr[num].LBlack > Lcr[num - 6].LBlack + 1 &&
                            Lcr[num].LBlack > Lcr[num + 6].LBlack + 1 &&
                            Lcr[num + 6].LBlack != 0xFF &&
                            Lcr[num - 6].LBlack != 0xFF
                          )
                        {
                           // setText�û��Զ���("�󼫴�" + num);
                            left_max_value = num;
                            break;
                        }
                    }
                    else
                    {
                        if (
                            Lcr[num].LBlack > Lcr[num - 10].LBlack + 1 &&
                            Lcr[num].LBlack > Lcr[num + 10].LBlack + 1 &&
                            Lcr[num + 10].LBlack != 0xFF &&
                            Lcr[num - 10].LBlack != 0xFF
                            )
                        {
                          //  setText�û��Զ���("�󼫴�" + num);
                            left_max_value = num;
                            break;
                        }
                    }
                }
                for (num = 6; num < 62; num++)
                {
                    if (num <= 15 || num >= 55)
                    {
                        if (
                            Lcr[num].LBlack < Lcr[num - 6].LBlack - 1 &&
                            Lcr[num].LBlack < Lcr[num + 6].LBlack - 1 &&
                            Lcr[num + 6].LBlack != 0xFF &&
                            Lcr[num - 6].LBlack != 0xFF
                          )
                        {
                           // setText�û��Զ���("��С" + num);
                            left_min_value = num;
                            break;
                        }
                    }
                    else
                    {
                        if (
                            Lcr[num].LBlack < Lcr[num - 10].LBlack - 1 &&
                            Lcr[num].LBlack < Lcr[num + 10].LBlack - 1 &&
                            Lcr[num + 10].LBlack != 0xFF &&
                            Lcr[num - 10].LBlack != 0xFF
                            )
                        {

                           // setText�û��Զ���("��С" + num);
                            left_min_value = num;
                            break;
                        }
                    }
                }
                for (num = 6; num < 62; num++)
                {
                    if (num <= 15 || num >= 55)
                    {
                        if (
                             Lcr[num].RBlack > Lcr[num - 6].RBlack + 1 &&
                             Lcr[num].RBlack > Lcr[num + 6].RBlack + 1 &&
                             Lcr[num + 6].LBlack != 0xFF &&
                             Lcr[num - 6].LBlack != 0xFF
                          )
                        {
                          //  setText�û��Զ���("�Ҽ���" + num);
                            right_max_value = num;
                            break;
                        }
                    }
                    else
                    {
                        if (
                            Lcr[num].RBlack > Lcr[num - 10].RBlack + 1 &&
                            Lcr[num].RBlack > Lcr[num + 10].RBlack + 1 &&
                            Lcr[num + 10].LBlack != 0xFF &&
                            Lcr[num - 10].LBlack != 0xFF
                            )
                        {
                           // setText�û��Զ���("�Ҽ���" + num);
                            right_max_value = num;
                            break;
                        }
                    }
                }
                for (num = 6; num < 62; num++)
                {
                    if (num <= 15 || num >= 55)
                    {
                        if (
                             Lcr[num].RBlack < Lcr[num - 6].RBlack - 1 &&
                             Lcr[num].RBlack < Lcr[num + 6].RBlack - 1 &&
                             Lcr[num + 6].LBlack != 0xFF &&
                             Lcr[num - 6].LBlack != 0xFF
                          )
                        {
                           // setText�û��Զ���("�Ҽ�С" + num);
                            right_min_value = num;
                            break;
                        }
                    }
                    else
                    {
                        if (
                           Lcr[num].RBlack < Lcr[num - 10].RBlack - 1 &&
                           Lcr[num].RBlack < Lcr[num + 10].RBlack - 1 &&
                           Lcr[num + 10].LBlack != 0xFF &&
                           Lcr[num - 10].LBlack != 0xFF
                        )
                        {
                           // setText�û��Զ���("�Ҽ�С" + num);
                            right_min_value = num;
                            break;
                        }
                    }
                }
              //  #endregion

              //  setText�û��Զ���("��" + (Lcr[left_min_value].LBlack - Lcr[right_max_value].RBlack) + "��" + (Lcr[left_max_value].LBlack - Lcr[right_min_value].RBlack));
                //  setText�û��Զ���();
                if (left_min_value != 0 && right_max_value != 0 && Lcr[left_min_value].LBlack - Lcr[right_max_value].RBlack >= 20)
                {

                    //-------------ȡ�е�----------------------
                    Small_S_center = (uint8_t)((Lcr[left_min_value].LBlack + Lcr[right_max_value].RBlack) / 2);

                    if (Fabs(Small_S_center - Lcr[30].Center) <= 25)
                    {
                        Small_S_flag = 1;
                    //    setText�û��Զ���("СS��" + Small_S_center);
                    }
                    else if (Fabs(Small_S_center - Lcr[30].Center) > 25 && Fabs(Small_S_center - Lcr[30].Center) <= 45)
                    {

                        Small_S_flag = 2;
                        Small_S_center = (uint8_t)((Small_S_center + Lcr[30].Center) / 2);
                    //    setText�û��Զ���("��S��" + Small_S_center);
                    }
                }
                else if (left_max_value != 0 && right_min_value != 0 && Lcr[left_max_value].LBlack - Lcr[right_min_value].RBlack >= 20)
                {

                    //-------------ȡ�е�----------------------
                    Small_S_center = (uint8_t)((Lcr[left_max_value].LBlack + Lcr[right_min_value].RBlack) / 2);

                    if (Fabs(Small_S_center - Lcr[30].Center) <= 25)
                    {
                        Small_S_flag = 1;
                     //   setText�û��Զ���("СS��" + Small_S_center);
                    }
                    else if (Fabs(Small_S_center - Lcr[30].Center) > 25 && Fabs(Small_S_center - Lcr[30].Center) <= 45)
                    {

                        Small_S_flag = 2;
                        Small_S_center = (uint8_t)((Small_S_center + Lcr[30].Center) / 2);
                    //    setText�û��Զ���("��S��" + Small_S_center);
                    }
                }
                else
                {
                    Small_S_flag = 0;
                }

            }
            else
            {
                Small_S_flag = 0;
            }
        }
        void Image_Init()//��ÿ��ͼ��������������Ҫ��ʼ���ı�����ʼ�� 
        {
			 leftmaxhang = 0;
          
            rightmaxhang = 0;
            lefthang = 0;
            leftless = 160;
            leftmax = 0;
            righthang = 0;
            rightless = 0;
            rightmax = 160;
			ting=0;
            use_lie = 70;
            Stop_found = 0;
            Straight_error = 0;
            Straight_flag = 1;
            Turn_left_flag = 0;
            Turn_right_flag = 0;
            Turn_left_dui = 0;
            Turn_right_dui = 0;
            Ten_Road_flag = 0;
            Ten_now_line = 0;
            Ten_frist_flag = 0;
            First_turn_left = 70;
            First_turn_right = 70;
            First_yuan_left = 70;
            First_yuan_right = 70;
			  First_find_left = 70;
            First_find_right = 70;
            Second_turn_left = 70;
            Second_turn_right = 70;
            Straight_overtake_err = 0;
           /* if (Huan_Road_flag == 111)
            {
                Huan_Road_flag = 0;
            }*/
           //Huan_Road_flag = 0;
            Huan_left_min = 160;
            Huan_right_min = 0;
            for (i = 0; i < 70; i++)
            {
                Left_flag[i] = 0;
                Right_flag[i] = 0;
            }
            LcrlenBool = 0;//�ضϱ�־          
        }
        void ImageProcess()//ͼ���д���
        {
			LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            /******************��һ��ɨ��*******************/
           // #region
            if (RowNum == 0)
            {
				for (j = 159; j > 0; j--)
                {
					if(P_Pixels[RowNum][ j]==0)
						ting++;
				}
                Lcr[RowNum].LStart = first_start;
                Lcr[RowNum].RStart = first_start;
                Lcr[RowNum].REnd = 2;
                Lcr[RowNum].LEnd = 158;
                
                for (lie = Lcr[RowNum].LStart; lie <= Lcr[RowNum].LEnd; lie++)
                {
                    if (P_Pixels[RowNum][lie] == 0 && P_Pixels[RowNum][lie + 1] == 0)//��Ϊ0
                    {
                        Left_flag[RowNum] = 1;
                        Lcr[RowNum].LBlack =  lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].LEnd + 1)
                {
                    Left_flag[RowNum] = 0;
                    Lcr[RowNum].LBlack = 158;
                    if (Turn_left_flag == 0)
                    {
                       First_turn_left = RowNum;
                    }
                    Turn_left_flag++;
                }
                for (lie = Lcr[RowNum].RStart; lie >= Lcr[RowNum].REnd; lie--)
                {
                    if (P_Pixels[RowNum][lie] == 0 && P_Pixels[RowNum][lie - 1] == 0)
                    {
                        Right_flag[RowNum] = 1;
                        Lcr[RowNum].RBlack =  lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].REnd - 1)
                {
                    Right_flag[RowNum] = 0;
                    Lcr[RowNum].RBlack =  2;
                    if (Turn_right_flag == 0)
                    {
                       First_turn_right = RowNum;
                    }
                    Turn_right_flag++;
                }
                Lcr[RowNum].Center =  ((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);
                first_start = Lcr[RowNum].Center;
                if (Lcr[RowNum].LBlack == 80 && Lcr[RowNum].RBlack == 80)
                {
                    LcrlenBool = 1;
                }
            }
            //#endregion

            /******************���༸��ɨ��****************/
           // #region       
            else
            {
                Lcr[RowNum].LStart =  Pro_value_byte(Lcr[RowNum - 1].LBlack - 13);
                Lcr[RowNum].RStart =  Pro_value_byte(Lcr[RowNum - 1].RBlack + 13);
                Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum - 1].LBlack + 20);
                Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum - 1].RBlack - 20);
               
                //ʮ��ɨ��
              //  #region 
                if (Ten_Road_flag == 4)
                {
                    if (Lcr[RowNum - 1].Center < 80)
                    {
                        Lcr[RowNum].LStart =  Pro_value_byte(Lcr[RowNum - 1].Center + 10);
                        Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                        Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum - 1].LBlack + 60);
                        Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum - 1].RBlack - 20);
                    }
                    else
                    {
                        Lcr[RowNum].LStart =  Pro_value_byte(Lcr[RowNum - 1].Center - 10);
                        Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                        Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum - 1].LBlack + 20);
                        Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum - 1].RBlack - 60);
                    }
                    Ten_Road_flag = 0;
                }
                if (Ten_Road_flag == 1 && Ten_now_line == 0)
                {
                    Lcr[RowNum].LStart =  Pro_value_byte(Lcr[Ten_frist_flag].Center + Ten_frist_flag / 2);
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }
                if (Ten_Road_flag == 2 && Ten_now_line == 0 )
                {
                    Lcr[RowNum].LStart =  Pro_value_byte(Lcr[Ten_frist_flag].Center - Ten_frist_flag / 2);
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }
                if (Ten_Road_flag == 11 && Ten_now_line == 0)
                {
                    Lcr[RowNum].LStart =  Pro_value_byte((Lcr[0].LBlack + Lcr[0].Center) / 2 - 8);
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }
                if (Ten_Road_flag == 22 && Ten_now_line == 0 )
                {
                    Lcr[RowNum].LStart =  Pro_value_byte((Lcr[0].RBlack + Lcr[0].Center) / 2 + 8);
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }
                if (Ten_Road_flag == 111 && Ten_now_line == 0)
                {
                    Lcr[RowNum].LStart =  Pro_value_byte((Lcr[0].Center)+10);
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }
                if (Ten_Road_flag == 222 && Ten_now_line == 0)
                {
                    Lcr[RowNum].LStart =  Pro_value_byte((Lcr[0].Center)-10);
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }
                if (Ten_Road_flag == 3 && Ten_now_line == 0)
                {
                    Lcr[RowNum].LStart =  Pro_value_byte((Lcr[1].Center));
                    Lcr[RowNum].RStart = Lcr[RowNum].LStart;
                    Lcr[RowNum].LEnd =  Pro_value_byte(Lcr[RowNum].LStart + 100);
                    Lcr[RowNum].REnd =  Pro_value_byte(Lcr[RowNum].RStart - 100);
                }











               // #endregion

                //����ɨ��
              //  #region
                


               // #endregion
                //ɨ��
              //  #region
                for (lie = Lcr[RowNum].LStart; lie <= Lcr[RowNum].LEnd; lie++)
                {
                    if (P_Pixels[RowNum][lie] == 0 && P_Pixels[RowNum][lie + 1] == 0)
                    {
                        Left_flag[RowNum] = 1;
						 if (First_find_left == 70)
                            First_find_left = RowNum;
                        Lcr[RowNum].LBlack =  lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].LEnd + 1)
                {
                    Left_flag[RowNum] = 0;
                    Lcr[RowNum].LBlack =  158;
                    if (RowNum > 5 && Turn_left_dui == 0)
                        First_yuan_left = RowNum;
                    if (RowNum > 5)
                        Turn_left_dui++;
                    if (Turn_left_flag == 0)
                    {
                        First_turn_left = RowNum;
                        
                    }
                    Turn_left_flag++;
                    if (First_yuan_left != 70 && Second_turn_left == 70 && Left_flag[RowNum - 1] == 1 && Left_flag[RowNum] == 0 && RowNum > First_yuan_left)
                        Second_turn_left = RowNum;
                }

                for (lie = Lcr[RowNum].RStart; lie >= Lcr[RowNum].REnd; lie--)
                {
                    if (P_Pixels[RowNum][lie] == 0 && P_Pixels[RowNum][lie - 1] == 0)
                    {
                        Right_flag[RowNum] = 1;
						  if (First_find_right == 70)
                            First_find_right = RowNum;
                        Lcr[RowNum].RBlack =  lie;
                        break;
                    }
                }
                if (lie == Lcr[RowNum].REnd - 1)
                {
                    Right_flag[RowNum] = 0;
                    Lcr[RowNum].RBlack =  2;
                    if (RowNum > 5 && Turn_right_dui == 0)
                        First_yuan_right = RowNum;
                    if (RowNum > 5)
                        Turn_right_dui++;
                    if (Turn_right_flag == 0)
                    {
                        First_turn_right = RowNum;
                        
                    }
                    Turn_right_flag++;
                    if (First_yuan_right != 70 && Second_turn_right == 70 && Right_flag[RowNum - 1] == 1 && Right_flag[RowNum] == 0 && RowNum > First_yuan_right)
                        Second_turn_right = RowNum;
                }








               // #endregion
                Lcr[RowNum].Center =  ((Lcr[RowNum].RBlack + Lcr[RowNum].LBlack) / 2);
                Width[RowNum] =  (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack);	//���㱾���������
            if (RowNum > 20 && RowNum < 60 && Lcr[RowNum].LBlack>105)
                {
                    if (leftless >= Lcr[RowNum].LBlack)
                    {
                        leftless = Lcr[RowNum].LBlack;
                        lefthang = RowNum;
                    }
                }
                if (RowNum > 20 && RowNum < 60 && Lcr[RowNum].RBlack<55)
                {
                    if (rightless <= Lcr[RowNum].RBlack)
                    {
                        rightless = Lcr[RowNum].RBlack;
                        righthang = RowNum;
                    }
                }
                if (RowNum > 40 && RowNum < 70)
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
                }
            }
           // #endregion
           
            /*******************ʮ���ж�******************/
          //  #region
            /****             ��Զ������ж�ʮ�ֻ�б��б��ʮ��              ****/
            if (RowNum > 3 && RowNum < 50 && Ten_Road_flag == 0 && Lcr[RowNum].LBlack == 158 && Lcr[RowNum].RBlack <= Lcr[RowNum - 2].RBlack - 1 && Turn_left_flag > 0 )
            {
                Ten_frist_flag = RowNum;
                if (Ten_frist_flag * 2 / 5 <= Turn_left_flag)
                {
                    //setText�û��Զ���("��бʮ��1�ж�" + Ten_frist_flag);
                    Ten_Road_flag = 1;
                }
                else
                {
                    //setText�û��Զ���("��бʮ��11�ж�" + Ten_frist_flag);
                    Ten_Road_flag = 11;
                }
            }
            if (RowNum > 3 && RowNum < 50 && Ten_Road_flag == 0 && Lcr[RowNum].RBlack == 2 && Lcr[RowNum].LBlack >= Lcr[RowNum - 2].LBlack + 1 && Turn_right_flag > 0 )
            {
                Ten_frist_flag = RowNum;
                if (Ten_frist_flag * 2 / 5 <= Turn_right_flag)
                {
                    //setText�û��Զ���("��бʮ��2�ж�" + Ten_frist_flag);
                    Ten_Road_flag = 2;
                }
                else
                {
                    //setText�û��Զ���("��бʮ��22�ж�" + Ten_frist_flag);
                    Ten_Road_flag = 22;
                }
                //setText�û��Զ���("ʮ���ж�");
            }
            /****                     �������Ϊ����ӽ�ʮ�ֵ�ʱ������ж�Ϊʮ��                          ****/
            if (RowNum < 50 && Lcr[RowNum].LBlack == 158 && Lcr[RowNum].RBlack == 2 && Turn_right_flag >= 3 && Turn_left_flag >= 3 && (Ten_Road_flag != 111 && Ten_Road_flag != 222 && Ten_Road_flag != 3))
            {
                if (First_turn_right > First_turn_left)
                {
                    Ten_frist_flag = First_turn_left;
                    Ten_Road_flag = 111;
                    //setText�û��Զ���("��ֱʮ��111�ж�" + Ten_frist_flag);
                }
                else if (First_turn_right < First_turn_left)
                {
                    Ten_frist_flag = First_turn_right;
                    Ten_Road_flag = 222;
                    //setText�û��Զ���("��ֱʮ��222�ж�" + Ten_frist_flag);
                }
                else if (First_turn_right == First_turn_left)
                {
                    Ten_frist_flag = First_turn_right;
                    Ten_Road_flag = 3;
                    //setText�û��Զ���("ֱʮ����33�ж�" + Ten_frist_flag);
                }
                else if (First_turn_right == 0 && First_turn_right == 0)
                {
                    Ten_frist_flag = First_turn_right;
                    Ten_Road_flag = 3;
                    //setText�û��Զ���("ֱʮ����3�ж�" + Ten_frist_flag);
                }
                //setText�û��Զ���("ʮ���ж�");
            }
            /****               ɨ��ǲ���                 ****/
            if (RowNum > Ten_frist_flag + 8 && (Ten_Road_flag == 1 || Ten_Road_flag == 11) &&
                Lcr[RowNum].RBlack > Lcr[Ten_frist_flag].RBlack + 5 && Ten_now_line == 0 &&
                (Lcr[RowNum - 1].LBlack - Lcr[RowNum - 1].RBlack) < 54)
            {
                Ten_now_line = RowNum;
                //setText�û��Զ���("��ʮ�ּ��" + Ten_now_line);
            }
            if (RowNum > Ten_frist_flag + 8 && (Ten_Road_flag == 2 || Ten_Road_flag == 22) &&
                Lcr[RowNum].LBlack <= Lcr[Ten_frist_flag].LBlack - 5 && Ten_now_line == 0 &&
                (Lcr[RowNum - 1].LBlack - Lcr[RowNum - 1].RBlack) < 54)
            {
                Ten_now_line = RowNum;
                //setText�û��Զ���("��ʮ�ּ��" + Ten_now_line);
            }
            if ((Ten_Road_flag == 1 || Ten_Road_flag == 11 || Ten_Road_flag == 2 || Ten_Road_flag == 22 || Ten_Road_flag == 111 || Ten_Road_flag == 222 || Ten_Road_flag == 3) && (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack) == 0)
            {
                Ten_Road_flag = 4;
            }
            if (RowNum > Ten_frist_flag + 5 && (Ten_Road_flag == 111 || Ten_Road_flag == 222 || Ten_Road_flag == 3) &&
                (Lcr[RowNum].LBlack < Lcr[0].LBlack && Lcr[RowNum - 3].LBlack < Lcr[0].LBlack && Lcr[RowNum].RBlack > Lcr[0].RBlack && Lcr[RowNum - 3].RBlack > Lcr[0].RBlack) &&
                Ten_now_line == 0)
            {
                Ten_now_line = RowNum;
                //setText�û��Զ���("ֱʮ������" + Ten_now_line);
            }
         //   #endregion
            /*******************�����ж�******************/
          //  #region
            if (Left_flag[RowNum] == 0 && Right_flag[RowNum] == 1 && RowNum > 2 && Lcr[RowNum - 1].LBlack > Lcr[RowNum].LBlack)
                Lcr[RowNum].LBlack =  Lcr[RowNum-1].LBlack;
            if (Left_flag[RowNum] == 1 && Right_flag[RowNum] == 0 && RowNum > 2 && Lcr[RowNum - 1].RBlack < Lcr[RowNum ].RBlack)
                Lcr[RowNum].RBlack =  Lcr[RowNum - 1].RBlack;

          
//            if (First_yuan_right > 20 && Second_turn_left > 50 && Turn_right_dui > 5 && Right_flag[Second_turn_right - 5] == 1 && Turn_left_dui < 15 && Lcr[First_yuan_right - 2].LBlack < Lcr[First_yuan_right - 3].LBlack && Lcr[First_yuan_right - 2].RBlack < Lcr[First_yuan_right - 3].RBlack
//                && Lcr[First_yuan_right + Turn_right_dui + 1].RBlack > 10 && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 8)
//                Huan_Road_flag = 3;
//             if (First_yuan_left > 10 && First_yuan_left < 30 && Second_turn_right > 50 && Turn_left_dui > 5 && Turn_right_dui < 15 && Lcr[First_yuan_left - 2].LBlack < Lcr[First_yuan_left - 1].LBlack && Lcr[First_yuan_left - 1].RBlack > Lcr[First_yuan_left - 2].RBlack
//                && Lcr[First_yuan_left + Turn_left_dui + 1].LBlack < 148 && (First_yuan_right == 10 || First_yuan_right > 50) && Huan_Road_flag == 0)
//                Huan_Road_flag = 6;
          /*  if (First_yuan_right > 10 && First_yuan_right < 25 && Second_turn_left > 50 && Turn_right_dui > 5 && Right_flag[Second_turn_right - 5] == 1 && Turn_left_flag < 15 && Lcr[First_yuan_right - 2].LBlack < Lcr[First_yuan_right - 3].LBlack && Lcr[First_yuan_right - 2].RBlack > Lcr[First_yuan_right - 3].RBlack
                && Lcr[First_yuan_right + Turn_right_dui + 1].RBlack >10 && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 0)
                Huan_Road_flag = 8;
            if (First_yuan_right == 10 && Second_turn_right > 30 && Second_turn_right < 60 && Second_turn_left > 50 && Turn_right_dui > 2 && Right_flag[Second_turn_right - 5] == 1 && Turn_left_flag < 15 && Lcr[Second_turn_right - 1].RBlack < Lcr[Second_turn_right - 2].RBlack && Lcr[Second_turn_right - 2].LBlack < Lcr[Second_turn_right - 3].LBlack
                && Lcr[Second_turn_right-5].RBlack >35 && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 0)
                Huan_Road_flag = 8;*/
			
          //  #endregion
            /*********************�ض�**********************/
          //  #region
            
            if ((Lcr[RowNum].RBlack + 8 >= Lcr[RowNum].LBlack || Lcr[RowNum].LBlack - 8 <= Lcr[RowNum].RBlack) && Ten_Road_flag != 4)
            {
                LcrlenBool = 1;
                use_lie = RowNum;
            }
            if (RowNum > 65 &&
                (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack > Lcr[RowNum - 1].LBlack - Lcr[RowNum - 1].RBlack + 3 || Lcr[RowNum].LBlack - Lcr[RowNum].RBlack > 120) &&
                Ten_Road_flag != 4 && Huan_Road_flag == 0)
            {
                LcrlenBool = 1;
            }
            if (Lcr[RowNum].LBlack - Lcr[RowNum].RBlack < 12 && Ten_Road_flag != 4)
            {
                LcrlenBool = 1;
                use_lie = RowNum;
            }
         //   #endregion

           
        }
        void FieldProcess() //ͼ�񳡴���������
        {
			LCR  *Lcr=(LCR *)Sent_Data->Lcr;
            float xl;
            uint8_t Width_RowNum;
			  if (First_yuan_left == 6 &&leftmaxhang > lefthang && Width[leftmaxhang] > 80 && lefthang > 40 && lefthang < 55 && leftless < 135 && leftless > 80 && Lcr[35].LBlack < 145 && righthang > 55
               && Right_flag[leftmaxhang] == 1 && leftmaxhang <65&& Lcr[leftmaxhang].RBlack <= Lcr[leftmaxhang - 1].RBlack + 2 && Huan_Road_flag == 0 && Lcr[First_find_right].RBlack < 5)
                Huan_Road_flag = 6;
            if (Left_flag[20] == 1 && Huan_Road_flag == 6) Huan_Road_flag = 61;
            if (First_yuan_left == 6 && Turn_left_dui > 20
               && (First_yuan_right == 6 || First_yuan_right > 50) && Huan_Road_flag == 61)
                Huan_Road_flag = 11;
            if (First_yuan_right == 6 &&rightmaxhang > righthang && Width[rightmaxhang] > 80 && righthang > 40 && righthang < 55 && rightless > 25 && rightless < 80 && Lcr[35].RBlack > 15 && lefthang > 55
            && Left_flag[rightmaxhang] == 1 && rightmaxhang<65 && Lcr[rightmaxhang - 1].LBlack <= Lcr[rightmaxhang].LBlack + 2 && Huan_Road_flag == 0 && Lcr[First_find_left].LBlack > 155)
                Huan_Road_flag = 8;
            if (Right_flag[20] == 1 && Huan_Road_flag == 8) Huan_Road_flag = 81;
            if (First_yuan_right == 6  && Turn_right_dui > 20 
               && (First_yuan_left == 6 || First_yuan_left > 50) && Huan_Road_flag == 81)
                Huan_Road_flag = 33;
			  if (Turn_right_flag > 50&&Turn_right_flag < 56 && (Huan_Road_flag == 0)&& Lcr[Turn_right_flag].RBlack > 40 && (First_yuan_left == 6 || First_yuan_left > 50))
                Huan_Road_flag = 52;
			   if (Turn_left_flag > 50&&Turn_left_flag < 56 && (Huan_Road_flag == 0)&& Lcr[Turn_left_flag].LBlack <120 && (First_yuan_right == 6 || First_yuan_right > 50))
                Huan_Road_flag = 92;
//			  if (First_yuan_right == 10  && Second_turn_left > 50 && Turn_right_dui > 5 && Turn_left_dui < 15 && Lcr[30].LBlack < Lcr[29].LBlack && righthang>40&&righthang <65&&rightless>25&& rightless <80&& Lcr[35].RBlack>15
//               && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 0&& Lcr[First_find_left].LBlack >155)
//                Huan_Road_flag = 8;
//			  
//			  if (First_yuan_right > 10 && Huan_Road_flag == 8) Huan_Road_flag = 81;
//            if (First_yuan_right ==10 && Second_turn_left > 50 && Turn_right_dui > 20 && Turn_left_dui < 15 
//               && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 81)
//                Huan_Road_flag = 32;
//			  if (First_yuan_left == 70 && Second_turn_left > 50 && Turn_left_dui < 15 && Lcr[30].LBlack < Lcr[29].LBlack && righthang > 35 && righthang < 49 && rightless < 20 && Lcr[35].RBlack <20 && Width[righthang+5]>60
//             && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 0 && Lcr[First_find_left].LBlack > 155)
//                Huan_Road_flag = 88;
//            if (First_yuan_right == 10 && Second_turn_left > 50 && Turn_right_dui > 20 && Turn_left_dui < 15
//              && (First_yuan_left == 10 || First_yuan_left > 50) && Huan_Road_flag == 88)
//                Huan_Road_flag = 52;
			/*if (First_yuan_right == 10 && Second_turn_left > 50 && Turn_right_flag <35 && Turn_right_flag > 15 && Turn_left_flag < 15 && Lcr[Turn_right_flag].RBlack > Lcr[Turn_right_flag -1].RBlack && Lcr[Turn_right_flag - 3].LBlack > Lcr[Turn_right_flag - 2].LBlack
                && Lcr[45].RBlack > 15 && Lcr[45].RStart<80 && (First_yuan_left == 10 || First_yuan_left > 50) &&( Huan_Road_flag == 0||Huan_Road_flag == 8))
                Huan_Road_flag = 88;
            if (First_yuan_right > 20   && Turn_left_dui < 15 && Lcr[First_yuan_right - 1].LBlack < Lcr[First_yuan_right - 2].LBlack && Lcr[First_yuan_right - 1].RBlack < Lcr[First_yuan_right - 2].RBlack
                 && (First_yuan_left == 10 || First_yuan_left > 50)&&Huan_Road_flag == 88 )
                Huan_Road_flag = 5;*/
         /* setText�û��Զ���("���״ζ���" + First_yuan_left);
          setText�û��Զ���("����ζ���" + Second_turn_left);
           // setText�û��Զ���("���ߴ���" + Turn_left_dui);
            setText�û��Զ���("���״ζ���" + First_yuan_right);
            setText�û��Զ���("�Ҷ��ζ���" + Second_turn_right);
            //setText�û��Զ���("�Ҷ��ߴ���" + Turn_right_dui);
            //setText�û��Զ���("�ض�" + use_lie);
           // setText�û��Զ���("ʮ�ֿ�ʼ" + Ten_frist_flag);
            //setText�û��Զ���("ʮ���ж�" + Ten_Road_flag);
            setText�û��Զ���("�����ж�" + Huan_Road_flag);*/
            /************************ʮ�ִ���**************************/
          //  #region
            if ((Ten_Road_flag == 1 || Ten_Road_flag == 2 || Ten_Road_flag == 11 || Ten_Road_flag == 22) && Ten_now_line != 0)
            { xl = Xielv(Lcr[0].Center, Lcr[Ten_now_line].Center, Ten_now_line);
                for (RowNum = 0; RowNum < Pro_value_byte_1(Ten_now_line + 3); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                //setText�û��Զ���("ʮ��1����" + Ten_frist_flag);
            }
            if ((Ten_Road_flag == 111 || Ten_Road_flag == 222 || Ten_Road_flag == 3) && Ten_now_line != 0)
            {
                xl = Xielv(Lcr[0].Center, Lcr[Ten_now_line].Center, Ten_now_line);
                for (RowNum = 0; RowNum < Pro_value_byte(Ten_now_line); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                //setText�û��Զ���("ʮ��2����" + Ten_frist_flag);
            }
            if (Ten_Road_flag != 0 && First_turn_right == 0 && First_turn_left == 0)
            {
                Ten_state_change = 1;
            }
            if (Ten_Road_state == 0 && Ten_state_change == 1 && First_turn_right != 0 && First_turn_left != 0)
            {
                Ten_state_change = 0;
                Ten_Road_state = 1;
            }
            if (Ten_Road_state == 2)
            {
                Ten_Road_Times++;
                Ten_Road_state = 0;
            }
            if (Ten_Road_state == 1 && Ten_state_change == 1 && First_turn_right != 0 && First_turn_left != 0)
            {
                Ten_state_change = 0;
                Ten_Road_state = 2;
            }
            /*setText�û��Զ���("ʮ�ִ���" + Ten_Road_Times);
            setText�û��Զ���("ʮ��λ��" + Ten_Road_state);
            setText�û��Զ���("ʮ�ָı�" + Ten_state_change);*/
           // #endregion
            /************************���δ���**************************/
          
          //      #region
            if (Huan_Road_flag == 6||Huan_Road_flag == 61)
            {

                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].RBlack - RowNum + 88);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                

            }
            if (Huan_Road_flag == 1)
            {
                xl = Xielv(Lcr[0].Center, 158, 37);
                for (RowNum = 10; RowNum < Pro_value_byte_1(40); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum-10) + Lcr[0].Center);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_turn_left == 0 && Second_turn_left>50)
                    Huan_Road_flag = 11;
            
            }
            if (Huan_Road_flag == 11 || Huan_Road_flag == 12)
            {
                xl = Xielv(Lcr[0].Center, 158, 37);
                for (RowNum = 0; RowNum < Pro_value_byte_1(39); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center-5);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_turn_right == 0&& Turn_right_dui>2)
                    Huan_Road_flag = 12;
                if (Right_flag [1]==1&& Huan_Road_flag == 12)
                    Huan_Road_flag = 111;

            }
            if (Huan_Road_flag == 111)
            {
				    Lcr[RowNum].Center =  (Lcr[RowNum].RBlack - RowNum+80);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);	
                if (First_yuan_right != 70 && First_yuan_right != 6 && Lcr[First_yuan_right - 2].RBlack <88)
                    Huan_Road_flag = 2;

            }
            if (Huan_Road_flag == 2 || Huan_Road_flag == 22)
            {
                xl = Xielv(Lcr[0].Center, 158, 37);
                for (RowNum = 0; RowNum < Pro_value_byte_1(39); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center-8);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_right == 6&& Turn_right_flag>20)
                    Huan_Road_flag = 22;
                if (First_yuan_right != 6 && Huan_Road_flag == 22 && Turn_right_flag <10)
                    Huan_Road_flag = 222;


            }
            if (Huan_Road_flag == 222)
            {
                
                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].RBlack - RowNum+70);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_right != 6 && First_yuan_left != 6)
                    Huan_Road_flag = 0;

            }

            if (Huan_Road_flag == 8||Huan_Road_flag == 81)
            {

                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].LBlack + RowNum - 83);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }


            }
            if (Huan_Road_flag == 3)
            {
                xl = Xielv(Lcr[0].Center, 2, 37);
                for (RowNum = 10; RowNum < Pro_value_byte_1(40); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum - 10) + Lcr[0].Center);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_turn_right == 0 && Second_turn_right > 50)
                    Huan_Road_flag = 33;

            }
            if (Huan_Road_flag == 33 || Huan_Road_flag == 32)
            {
                xl = Xielv(Lcr[0].Center, 2, 37);
                for (RowNum = 0; RowNum < Pro_value_byte_1(39); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center+8);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_turn_left == 0&& Turn_left_dui>2)
                    Huan_Road_flag = 32;
                if (Left_flag [1]==1&& Huan_Road_flag == 32 )
                    Huan_Road_flag = 333;

            }
            if (Huan_Road_flag == 333)
            {
					Lcr[RowNum].Center =  (Lcr[RowNum].LBlack + RowNum - 80);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                if (First_yuan_left < 60 && First_yuan_left != 6 && Lcr[First_yuan_left-2].LBlack>70)
                    Huan_Road_flag = 4;

            }
            if (Huan_Road_flag == 4 || Huan_Road_flag == 44)
            {
                xl = Xielv(Lcr[0].Center, 2, 37);
                for (RowNum = 0; RowNum < Pro_value_byte_1(39); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center+4);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_left == 6&&Turn_left_flag>20)
                    Huan_Road_flag = 44;
                if (Left_flag [1]==1 && Huan_Road_flag == 44 && Turn_left_flag < 10)
                    Huan_Road_flag = 444;


            }
            if (Huan_Road_flag == 444)
            {

                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].LBlack + RowNum - 80);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_left != 6 && First_yuan_right != 6)
                    Huan_Road_flag = 0;

            }
			
			 if (Huan_Road_flag == 88)
            {

                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].LBlack + RowNum - 90);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }


            }

            if (Huan_Road_flag == 5)
            {
                xl = Xielv(Lcr[0].Center, 50, 50);
                for (RowNum = 10; RowNum < Pro_value_byte_1(50); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum - 10) + Lcr[0].Center);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (Lcr[30].RBlack<25)
                    Huan_Road_flag = 55;

            }
            if (Huan_Road_flag == 55 || Huan_Road_flag == 52)
            {
                xl = Xielv(Lcr[0].Center, 2, 50);
                for (RowNum = 0; RowNum < Pro_value_byte_1(50); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center+4);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
//                if (First_yuan_left == 6)
//                    Huan_Road_flag = 52;
                if (Left_flag [1]==1 && Huan_Road_flag == 52)
                    Huan_Road_flag = 555;

            }
            if (Huan_Road_flag == 555)
            {

                if (First_yuan_left != 70 && First_yuan_left != 6 && Lcr[First_yuan_left - 2].LBlack > 70)
                    Huan_Road_flag = 7;

            }
            if (Huan_Road_flag == 7 || Huan_Road_flag == 77)
            {
                xl = Xielv(Lcr[0].Center, 2, 50);
                for (RowNum = 0; RowNum < Pro_value_byte_1(50); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center+8);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_left == 6 && Turn_left_flag > 20)
                    Huan_Road_flag = 77;
                if (First_yuan_left != 6 && Huan_Road_flag == 77 && Turn_left_flag < 10)
                    Huan_Road_flag = 777;


            }
            if (Huan_Road_flag == 777)
            {

                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].LBlack + RowNum - 80);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_left != 6 && First_yuan_right != 6&&Width[First_yuan_right]<70)
                    Huan_Road_flag = 0;

            }

	

            if (Huan_Road_flag == 99 || Huan_Road_flag == 92)
            {
                xl = Xielv(Lcr[0].Center, 158, 50);
                for (RowNum = 0; RowNum < Pro_value_byte_1(50); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center-8);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
//                if (First_yuan_left == 6)
//                    Huan_Road_flag = 52;
                if (Right_flag [1]==1&& Huan_Road_flag == 92)
                    Huan_Road_flag = 999;

            }
            if (Huan_Road_flag == 999)
            {

                if (First_yuan_right != 70 && First_yuan_right != 6 && Lcr[First_yuan_right - 2].RBlack <90)
                    Huan_Road_flag = 10;

            }
            if (Huan_Road_flag == 10 || Huan_Road_flag == 100)
            {
                xl = Xielv(Lcr[0].Center, 158, 50);
                for (RowNum = 0; RowNum < Pro_value_byte_1(50); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (xl * (RowNum) + Lcr[0].Center-8);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_right == 6 && Turn_right_flag > 20)
                    Huan_Road_flag = 100;
                if (First_yuan_right != 6 && Huan_Road_flag == 100 && Turn_right_flag < 10)
                    Huan_Road_flag = 1000;


            }
            if (Huan_Road_flag == 1000)
            {

                for (RowNum = 0; RowNum < Pro_value_byte_1(60); RowNum++) //ѭ������
                {
                    Lcr[RowNum].Center =  (Lcr[RowNum].RBlack - RowNum + 80);
                    Lcr[RowNum].Center =  Pro_value_byte(Lcr[RowNum].Center);
                }
                if (First_yuan_right != 6 && First_yuan_left != 6&&Width[First_yuan_right]<70)
                    Huan_Road_flag = 0;

            }
			
			
//			for (RowNum = 0; RowNum < 60; RowNum++)
//            { 
//				P_Pixels[RowNum][Lcr[RowNum].Center]=0;
//            }

          //  #endregion

    
                
        }






         void SignalProcess()//��Ϣ����.left
        {
			LCR  *Lcr=(LCR *)Sent_Data->Lcr;
			
		
			
            Image_Init();//������ʼ�� 
			
            for (RowNum = 0; RowNum < 70; RowNum++) //ѭ������
            {
               

//                if (LcrlenBool != 0 || Edge_flag == 1)
//                {
//                    Lcr[RowNum].LStart = Lcr[RowNum].LBlack = Lcr[RowNum].LEnd = Lcr[RowNum].Center =
//                    Lcr[RowNum].RStart = Lcr[RowNum].RBlack = Lcr[RowNum].REnd = 0xFF;//���ضϵ���Ϣȥ��
//                    goto Line_ImageData_Process;    //�����д���
//                }
                ImageProcess(); //ͼ���д��� ��������
            Line_ImageData_Process:;
                //---------------------------------------------------------------------------------------------------------------
            }

            FieldProcess();//ͼ�񳡴���������
            Last_field_Center = Lcr[0].Center; //��¼�ϳ�0������
            Last_field_LBlack = Lcr[0].LBlack;
            Last_field_RBlack = Lcr[0].RBlack;
		//	if(ting>100) {run=0;Mode.OLED_Image_Live=1;}
            //setText�û��Զ���("Turn_left_flag" + Turn_left_flag);
            //setText�û��Զ���("Turn_right_flag" + Turn_right_flag);
            // Last_field_T_center = Lcr[18].Center;
			point=Lcr[line].Center;	
        }

		int32 range_protect(int32 duty, int32 min, int32 max)//�޷�����
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
	SignalProcess();
	if(run==1||run==2)
	Engine_Control();
//	else
//	cmt_pwm_duty(Engine_InitialDutyCycle);
//	Motor_Control();
	
	
	
}

uint8_t otsuThreshold( uint16 col, uint16 row)
{
    #define GrayScale 256
    uint16 width = col;
    uint16 height = row;
//		int n=0;//
//		int N=20;
//    int pixelCount[GrayScale];
//    float pixelPro[GrayScale];
//		int pixel[GrayScale];
//		int pixelAVG[GrayScale];//����ƽ���Ҷ�ֵ
//		int pij[GrayScale][GrayScale];
    int i, j, pixelSum = width * height;
//	int thresholdMax=0,thresholdMin = 0,thresholdsecond=0;
    uint8 threshold = 0;   
//	float maxPro = 0.0;
//	int a, b, Temp = 0, thresholdSunMax = 0, thresholdSunMin = 0;
//	float f1, g1, g2, w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
	int sum=0;
//    for (i = 0; i < GrayScale; i++)
//    {
//        pixelCount[i] = 0;
//        pixelPro[i] = 0;

//    }
    //ͳ�ƻҶȼ���ÿ������������ͼ���еĸ���  
    for (i = 0; i < 70; i++)
    {
        for(j=0;j<20;j++)  
				{
					sum+= (data[i*160+j*8]);
					sum+= (data[i*160+j*8+1]);
					sum+= (data[i*160+j*8+2]);
					sum+= (data[i*160+j*8+3]);
					sum+= (data[i*160+j*8+4]);
					sum+= (data[i*160+j*8+5]);
					sum+= (data[i*160+j*8+6]);
					sum+= (data[i*160+j*8+7]);
    }
}
threshold=sum/pixelSum;
  

    return threshold;
}
	
