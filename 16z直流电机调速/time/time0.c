#include <REGX52.H>

//**    定时器0初始化

void Timer0_Init(void)		//1毫秒@12.000MHz
{
	//AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x9C;				//璁剧疆瀹氭椂鍒濆鍊�
	TH0 = 0xFF;				//璁剧疆瀹氭椂鍒濆鍊�

	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
    ET0 = 1;
    EA = 1;
    PT0 = 0; 
}


//**定时器中断函数模板
//void Timer0_Routine() interrupt 1
//{
//    static unsigned int T0Count = 0;
//   TL0 = 0x9C;				//璁剧疆瀹氭椂鍒濆鍊�
//	TH0 = 0xFF;				//璁剧疆瀹氭椂鍒濆鍊�
//    T0Count++;
//    if(T0Count >= 1000)
//    {
//        T0Count = 0;
//        P2_0 = ~P2_0;
//    }
//}