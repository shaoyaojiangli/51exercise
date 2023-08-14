#include <REGX52.H>
#include "OneWhile.h"


#define DS18B20_SKIP_ROM          0xCC
#define DS18B20_CONVERT_T         0x44
#define DS18B20_READ_SCRATCHPAD   0xBE

//DS18B20开始进行温度转换
void DS18B20_ConvertT()
{
    OneWire_Init();
    OneWire_SendByte(DS18B20_SKIP_ROM);
    OneWire_SendByte(DS18B20_CONVERT_T);
}

//DS18B20读取温度
float DS18B20_ReadT()
{
    unsigned char TLSB,TMSB;
    int Temp;
    float T;
    OneWire_Init();
    OneWire_SendByte(DS18B20_SKIP_ROM);
    OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
    TLSB = OneWire_ReceiveByte();
    TMSB = OneWire_ReceiveByte();
    Temp = (TMSB << 8) | TLSB;
    T = Temp / 16.0;
    return T;
    
}
