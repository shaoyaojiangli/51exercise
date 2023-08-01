#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "timer0.h"


unsigned char Sec;
unsigned char Min;
unsigned char Hour;
int main()
{
    LCD_Init();
    Timer0_Init();
    LCD_ShowString(1,1,"Clock:");
    LCD_ShowString(2,3,":");
    LCD_ShowString(2,6,":");
    
    while(1)
    {
        LCD_ShowNum(2,1,Hour,2);
        LCD_ShowNum(2,4,Min,2);
        LCD_ShowNum(2,7,Sec,2);
        
    }
}


void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count = 0;
    TH0 = 64535 / 256;
    TL0 - 54535 % 256;
    T0Count++;
    if(T0Count >= 1000)
    {
        T0Count = 0;
       Sec++;
        if(Sec >= 60)
        {
            Sec = 0;
            Min++;
            if(Min >= 60)
            {
                Min = 0;
                Hour++;
                if(Hour >= 24)
                {
                    Hour = 0;
                }
            }
        }
            
    }
}