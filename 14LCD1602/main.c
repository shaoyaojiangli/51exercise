#include <REGX52.H>
#include "LCD1602.h"

int main()
{
    LCD_Init();
    LCD_ShowChar(2,3,'A');
    LCD_ShowString(1,3,"HELLo");
    LCD_ShowNum(1,9,66,2);
    LCD_ShowSignedNum(1,12,-88,2);
    LCD_ShowHexNum(2,1,0xA5,2);
    while(1)
    {
        
        
    }
}