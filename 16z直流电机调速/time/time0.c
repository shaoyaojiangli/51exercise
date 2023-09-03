#include <REGX52.H>

//**    ��ʱ��0��ʼ��

void Timer0_Init(void)		//1����@12.000MHz
{
	//AUXR &= 0x7F;			//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x9C;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值

	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
    ET0 = 1;
    EA = 1;
    PT0 = 0; 
}


//**��ʱ���жϺ���ģ��
//void Timer0_Routine() interrupt 1
//{
//    static unsigned int T0Count = 0;
//   TL0 = 0x9C;				//设置定时初始值
//	TH0 = 0xFF;				//设置定时初始值
//    T0Count++;
//    if(T0Count >= 1000)
//    {
//        T0Count = 0;
//        P2_0 = ~P2_0;
//    }
//}