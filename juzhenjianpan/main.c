#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;

int main()
{
    LCD_Init();
    LCD_ShowString(1,1,"MatrixKey");
    while(1)
    {
        KeyNum = MatrixKey();
        if(KeyNum != 0)
        {
            LCD_ShowNum(2,1,KeyNum,2);
        }
    }
}