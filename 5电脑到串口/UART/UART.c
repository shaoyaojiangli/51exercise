#include <REGX52.H>

//串口初始化，4800bps@12.000MHz



void UART_Init()
{
    SCON = 0x50;
   PCON |= 0x80;
    	
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x20;			//设置定时器模式
	TL1 = 0xF4;			//设置定时初始值
	TH1 = 0xF4;			//设置定时重载值
    ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
    EA = 1;
    ES = 1; 

}


//串口发送一个字节数据
//Byte要返回的数据
void UART_SendByte(unsigned char Byte)
{
    SBUF = Byte;
    while(TI == 0);
    TI = 0;
}



////串口中断函数模板
//void UART_Routine() interrupt 4
//{
//    if(RI == 1)
//    {
//      
//        RI == 0;
//    }
//}