#include <REGX52.H>


sbit OneWire_DQ = P3^7;

//单总线初始化
//从机响应位，0为响应，1为未响应
unsigned char OneWire_Init()
{  
    unsigned char  i;
    unsigned char  AckBit;
    OneWire_DQ = 1;
    OneWire_DQ = 0;
    i = 247;while (--i);     //延时 500us
    OneWire_DQ = 1;
    i = 32;while (--i);      //延时 70us
	AckBit = OneWire_DQ;
	i = 247;while (--i);     //延时 500us
    return AckBit;
}

//单总线发送一位
void OneWire_SendBit(unsigned char Bit)
{
    unsigned char  i;
    OneWire_DQ = 0;
    i = 4;while (--i);	   //延时 10us
    OneWire_DQ = Bit;
    i = 24;while (--i);      //延时 50us
	 OneWire_DQ = 1;
    
} 


//单总线接收一位
unsigned char OneWire_ReceiveBit(void)
{
    unsigned char  i;
    unsigned char Bit;
    OneWire_DQ = 0;
    i = 2;while (--i);    //延时 5us
     OneWire_DQ = 1;
    i = 2;while (--i);    //延时 5us
	Bit = OneWire_DQ;
    i = 24;while (--i);      //延时 50us
    return Bit;
}


//单总线发送一位字节
void OneWire_SendByte(unsigned char Byte)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        OneWire_SendBit(Byte & (0x01 << i));
    }
}


//单总线接收一个字节
unsigned char OneWire_ReceiveByte(void)
{
     unsigned char i;
    unsigned char Byte = 0x00;
    for(i = 0; i < 8; i++)
    {
        if(OneWire_ReceiveBit()){Byte |= (0x01 << i);}
    }
    return Byte;
}