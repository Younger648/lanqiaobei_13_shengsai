#include "include.h"





void  InitTimer0()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	EA = 1;
	ET0 = 1;
}

void serviceTimer0() interrupt 1
{
	
  static uint i = 0;
	static uint i_flag = 0;

	
	P0 = 0xff;

	TL0 = 0x66;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值

	
	
	
	
/*********************当温度超过温度参数时LED0.1秒闪烁*************************/
	SelectHC573(4);
	
	
	if(temp / 10 >= count)
	{
	i++;
	if(i >= 100)
	{
		
		i = 0;
		i_flag = ~i_flag;
		if(i_flag)
			LED_config(3,0);
		else
			LED_config(3,1);
	}
  }
	else
	LED_config(3,0);
	SelectHC573(0);
	
	
	
	SelectHC573(4);
	if(Time [1] == 0 && Time [0] < 6)
	{
		i ++;
		if(i >= 100)
			i_flag = ~i_flag;
		if(i_flag)
			LED_config(1,0);
		else
			LED_config(1,1);	
	}
		else
			LED_config(1,0);
	SelectHC573(0);

	
	
	
	led_TIMER();
	menu_TIMER();
	jidianqi_scon();
}




void led_TIMER()//菜单1，led2点亮
{
	if(Scon == 1)
	{
		SelectHC573(4);
		LED_config(2,1);

	}
	else
	{
		SelectHC573(4);
		LED_config(2,0);
		
	}
}




































 
//void serviceTimer0() interrupt 1
//{
//	TH0 = (65535-50000) / 256;
//	TL0 = (65535-50000) % 256;


//	static char SMG_wei_num;
//	SMGbit(SMG_duanma[6], SMG_weizhi[SMG_wei_num]);/*0-7*/
//	SMG_wei_num++;
//	if(SMG_wei_num == 8)
//	SMG_wei_num=0;
//	
//	
//	SMG_wei_num++;
//	if(SMG_wei_num == 8)
//	SMG_wei_num=1;
//	switch(SMG_wei_num)
//	{
//		case 1:
//			//1"U"
//		case 2:
//			//2"1"
//		case 3:
//			//5"1"跳过3，4直接扫描5并且赋值
//		case 4:
//			//6"3"
//		case 5:
//			//6"."灭掉6数码管，再次扫描6数码管然后赋值“.”
//	
//	}
//}	