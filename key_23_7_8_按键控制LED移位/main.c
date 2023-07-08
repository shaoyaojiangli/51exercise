#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
    while(xms)
    {
        unsigned char i, j;

        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
        xms--;
    }
}

unsigned char LEDNum = 0;
int main()
{
    P2 = ~0x01;
    while(1)
    {
//    P2_0 = 0;
//    Delay(500);
//    P2_0 = 1;
//    Delay(500);
        
        if(P3_0 == 0)
        {
            Delay(100);
            while(P3_0 == 0)
            {
                
            }
            Delay(100);
            
            LEDNum++;
            if(LEDNum >= 8)
            {
                LEDNum = 0;
            }
            P2 = ~(0x01 << LEDNum);
          
            
        }
        
         
        if(P3_1 == 0)
        {
            Delay(100);
            while(P3_1 == 0)
            {
                
            }
            Delay(100);
            
              if(LEDNum = 0)
            {
                LEDNum = 7;
            }
            else 
            {
            LEDNum--;
            }
          
            P2 = ~(0x01 << LEDNum);
          
            
        }
    }
}