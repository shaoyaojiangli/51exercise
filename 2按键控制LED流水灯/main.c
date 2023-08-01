#include <REGX52.H>
#include  "timer0.h"
#include  "key.h"
#include <INTRINS.H>




unsigned char KeyNum;
unsigned char LEDMode;
int main()
{
    P2 = 0xFE;   //�������λLED������ֵ
    Timer0_Init();
    while(1)
    {
        KeyNum = Key();
        if(KeyNum)
        {
            if(KeyNum == 1)
            {
                LEDMode++;
                if(LEDMode >= 2)LEDMode = 0;
            }
        }
    }
}



void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count = 0;
    TH0 = 64535 / 256;
    TL0 - 54535 % 256;
    T0Count++;
    if(T0Count >= 500)
    {
        T0Count = 0;
        if(LEDMode == 0)
            P2 = _crol_(P2,1);
        if(LEDMode ==1)
            P2 = _cror_(P2,1);
        
    }
}













