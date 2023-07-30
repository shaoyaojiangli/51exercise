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
            if(KeyNum <= 10)     //如果S1~S10按键按下，输入密码
            {
                if(count < 4)      //限制密码只有四位
                {
                Password *= 10;            //密码左移一位
                Password += KeyNum % 10;    //获取一位密码
                count++;                        //计次加一
                }
                LCD_ShowNum(2,1,Password,4);   //更新显示   
               
                
            }
            if(KeyNum == 11)   //S11是确认键
            {
                if(Password == 2345)     //判断密码是否正确
                {
                    LCD_ShowString(1,14,"OK ");
                    Password = 0;  //密码清零
                    count = 0;      //计次清零
                    LCD_ShowNum(2,1,Password,4);   //更新显示 
                }
                else
                {
                    LCD_ShowString(1,14,"ERR");
                     Password = 0;  //密码清零
                    count = 0;      //计次清零
                    LCD_ShowNum(2,1,Password,4);   //更新显示 
                }
            }
            if(KeyNum == 12)    //S12是取消键
            {
                    Password = 0;  //密码清零
                    count = 0;      //计次清零
                    LCD_ShowNum(2,1,Password,4);   //更新显示 
            }                 
            
        }
    }
}