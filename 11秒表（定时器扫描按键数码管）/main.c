#include <REGX52.H>
#include "time0.h"
#include "key.h"
#include "Nixie.h"
#include "Delay.h"
#include "AT24C02.h"

unsigned char KeyNum;
unsigned char Min,Sec,MiniSec;
unsigned char RunFlag =0;

int main()
{
    Timer0_Init();
    while(1)
    {
        KeyNum = Key();
        if(KeyNum == 1)
        {
            RunFlag = !RunFlag;
        }
         if(KeyNum == 2)
        {
            Min = 0;
            Sec = 0;
            MiniSec = 0;
        }
         if(KeyNum == 3)
        {
           AT24C02_WriteByte(0,Min);
            Delay(5);
              AT24C02_WriteByte(1,Sec);
            Delay(5);
              AT24C02_WriteByte(2,MiniSec);
            Delay(5);
        }
         if(KeyNum == 4)
        {
           Min = AT24C02_ReadByte(0);
             Sec = AT24C02_ReadByte(1);
             MiniSec = AT24C02_ReadByte(2);
        }
            Nixie_SetBuf(1,Min / 10);
            Nixie_SetBuf(2,Min % 10);
            Nixie_SetBuf(3,11);
             Nixie_SetBuf(4,Sec / 10);
            Nixie_SetBuf(5,Sec % 10);
            Nixie_SetBuf(6,11);
             Nixie_SetBuf(7,MiniSec / 10);
            Nixie_SetBuf(8,MiniSec % 10);
            
        
      
    }
}
void Sec_Loop()
{
    if(RunFlag)
    {
        
        MiniSec++;
        if(MiniSec >= 100)
        {
            MiniSec = 0;
            Sec++;
            if(Sec >= 60)
            {
                Sec = 0;
                if(Min >= 60)
                {
                   Min = 0; 
                }
            }
        }
    }
}


void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count1 = 0;
    static unsigned int T0Count2 = 0;
    static unsigned int T0Count3 = 0;
    TH0 = 0xFC;
    TL0 = 0x18;
    T0Count1++;
    if(T0Count1 >= 20)
    {
        T0Count1 = 0;
        Key_Loop();
    }
    
    
    T0Count2++;
    if(T0Count2>= 2)
    {
        T0Count2 = 0;
       Nixie_Loop();
    }
     T0Count3++;
    if(T0Count3>= 10)
    {
        T0Count3 = 0;
       Sec_Loop();
    }
}