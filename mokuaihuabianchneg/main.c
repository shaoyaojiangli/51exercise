#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

int main()
{
    while(1)
    {
       Nixie(1,1);
//        Delay(20);
        Nixie(2,2);
//        Delay(20);
        Nixie(3,3);
//        Delay(20);
        Nixie(4,4);
        Nixie(5,5);
        Nixie(6,6);
    }
}
