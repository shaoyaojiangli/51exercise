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

int main()
{
    unsigned char LEDNUM;
    while(1)
    {
        if(P3_1 == 0)
        {
            Delay(20);
            while(P3_1 == 0)
            {
                
            }
            Delay(20);
            
//            P2++;
//            P2 = ~P2;
            
            LEDNUM++;
            P2 = ~LEDNUM;
        }
    }
        
}