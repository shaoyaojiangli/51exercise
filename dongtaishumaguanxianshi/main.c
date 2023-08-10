#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"







int main()
{
    
   while(1)
    {
        Nixie(1,2);
//        Delay(20);
        Nixie(2,7);
//        Delay(20);
        Nixie(3,3);
//        Delay(20);
    }
}