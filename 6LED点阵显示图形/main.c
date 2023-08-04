#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3^5;   //P3的第五位   //RCLK
sbit SCK = P3^6;                  //SRCLK
sbit SER = P3^4;                  //SER

#define MATRIX_LED_PORT P0
void _74HC595_WriteByte(unsigned char Byte)
    {
        unsigned char i = 0;
        for(i = 0; i < 8; i++)
        {
            SER = Byte & (0x80 >> i);    
            SCK = 1;
            SCK = 0;
        }
        RCK = 1;
        RCK = 0;
  
    }
    
    
void MatrixLED_ShoweColumn(unsigned char Column,unsigned char Data)
{
    _74HC595_WriteByte(Data);
    MATRIX_LED_PORT = ~(0x80 >> Column);
    Delay(1);
    MATRIX_LED_PORT = 0xFF;
}
int main()
{
   
    SCK = 0;
    RCK = 0;
    MatrixLED_ShoweColumn(7,0xF0);
    while(1)
    {
         MatrixLED_ShoweColumn(0,0x81);
         MatrixLED_ShoweColumn(1,0x40);
         MatrixLED_ShoweColumn(2,0x20);
         MatrixLED_ShoweColumn(3,0x10);
         MatrixLED_ShoweColumn(4,0x08);
        
    }
    
}