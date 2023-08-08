#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_Init();
void DS1302_WriteByte(unsigned char Command,Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_ReadTime();
void DS1302_SetTime();
extern unsigned char DS1302_Time[];
#endif