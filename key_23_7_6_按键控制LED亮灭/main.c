#include <REGX52.H>


int main()
{
//    P2 = 0xFE;
    P2_0 = 0;
    P2_0 = 1;
    while(1)
    {
        if(P3_1 == 0 && P3_0 == 0)
        {
            P2_0 = 0;
        }
        else
        {
            P2_0 = 1;
        }
    }
}