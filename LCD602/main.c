#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
int Result;

int main()
{
    LCD_Init();
//    LCD_ShowChar(1,1,'A');         //��ʾ�ַ�
//    LCD_ShowString(2,3,"Hello");   //��ʾ�ַ���
//    LCD_ShowNum(1,3,66,3);         //��ʾ����
//    LCD_ShowSignedNum(1,7,-7,2);   //��ʾ�з�������
//    LCD_ShowHexNum(1,11,0xFE,3);   //��ʾʮ��������
//    LCD_ShowBinNum(2,9,0xFF,8);    //��ʾ��������
    Result = 1 + 1;
    
    while(1)
    {
        Result++;
        Delay(1000);
        LCD_ShowNum(1,1,Result,3);
    }
}