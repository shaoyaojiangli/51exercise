#include <REGX52.H>


void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
    while(xms)
    {
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
    while(1)
    {
//        P2_0 = 0;
//        Delay(500);
//        P2_0 = 1;
//        Delay(500);
        if(P3_1 == 0)
        {
            Delay(20);//消抖
            while(P3_1 == 0)//检测按钮按下
            {
                
            }
            Delay(20);
            
            P2_0 = ~P2_0;
            
        }
    }
}
