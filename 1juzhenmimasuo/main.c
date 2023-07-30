#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum = 0;
unsigned int Password = 0;
unsigned int count = 0;

int main()
{
    LCD_Init();
    LCD_ShowString(1,1,"Password");
    while(1)
    {
        KeyNum = MatrixKey();
        if(KeyNum != 0)
        {
            if(KeyNum <= 10)     //���S1~S10�������£���������
            {
                if(count < 4)      //��������ֻ����λ
                {
                Password *= 10;            //��������һλ
                Password += KeyNum % 10;    //��ȡһλ����
                count++;                        //�ƴμ�һ
                }
                LCD_ShowNum(2,1,Password,4);   //������ʾ   
               
                
            }
            if(KeyNum == 11)   //S11��ȷ�ϼ�
            {
                if(Password == 2345)     //�ж������Ƿ���ȷ
                {
                    LCD_ShowString(1,14,"OK ");
                    Password = 0;  //��������
                    count = 0;      //�ƴ�����
                    LCD_ShowNum(2,1,Password,4);   //������ʾ 
                }
                else
                {
                    LCD_ShowString(1,14,"ERR");
                     Password = 0;  //��������
                    count = 0;      //�ƴ�����
                    LCD_ShowNum(2,1,Password,4);   //������ʾ 
                }
            }
            if(KeyNum == 12)    //S12��ȡ����
            {
                    Password = 0;  //��������
                    count = 0;      //�ƴ�����
                    LCD_ShowNum(2,1,Password,4);   //������ʾ 
            }                 
            
        }
    }
}