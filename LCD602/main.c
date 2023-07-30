#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
int Result;

int main()
{
    LCD_Init();
//    LCD_ShowChar(1,1,'A');         //显示字符
//    LCD_ShowString(2,3,"Hello");   //显示字符串
//    LCD_ShowNum(1,3,66,3);         //显示数字
//    LCD_ShowSignedNum(1,7,-7,2);   //显示有符号数字
//    LCD_ShowHexNum(1,11,0xFE,3);   //显示十六进制数
//    LCD_ShowBinNum(2,9,0xFF,8);    //显示二进制数
    Result = 1 + 1;
    
    while(1)
    {
        Result++;
        Delay(1000);
        LCD_ShowNum(1,1,Result,3);
    }
}