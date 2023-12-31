#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"



unsigned char code Animation[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x08,0x50,0xEC,0x4A,0xE9,0x4F,0x09,
    0x5F,0xEA,0x48,0xF2,0x4B,0x0E,0x00,0x66,
    0x18,0xFF,0x26,0x6C,0xD5,0x2E,0x08,0x00,
    0x23,0x3A,0x2A,0xBF,0x6A,0x3A,0x23,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int main()
{
    unsigned char i,Offset = 0,Count = 0;
    MatrixLED_Init();
    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            MatrixLED_ShowColumn(i,Animation[i + Offset]);
        }
        Count++;
        if(Count > 10)//类似延时
        {
            Count = 0;
            Offset++;
            if(Offset > 32)
            {
                Offset = 0;
            }
            
        }
    }
    
}