#ifndef __ONEWHILE_H__
#define __ONEWHILE_H__


unsigned char OneWire_Init();
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_ReceiveBit(void);
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte(void);
#endif