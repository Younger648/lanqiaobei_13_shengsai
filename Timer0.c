#include "include.h"




void menu_TIMER();
void led_TIMER();
void  InitTimer0()
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x66;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	EA = 1;
	ET0 = 1;
}

void serviceTimer0() interrupt 1
{
	
  static uint i = 0;
	static uint i_flag = 0;
	static char Sec = 0;
	
	P0 = 0xff;
	TL0 = 0x66;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ

	
	
	
	
/*********************���¶ȳ����¶Ȳ���ʱLED0.1����˸*************************/
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
	

	

	
	
	
	
	
	led_TIMER();
	menu_TIMER();
	jidianqi_scon();
}




void led_TIMER()//�˵�1��led2����
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





void menu_TIMER()
{
	//�˵�1
	if(Scon == 1)
		SMG_ds18b20_scon();
	//�˵�2
	else if(Scon == 2)
		SMG_ds1302_scon();
	//�˵�3
	else if(Scon == 3)
		SMG_ds18b20_scon1();
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
//			//5"1"����3��4ֱ��ɨ��5���Ҹ�ֵ
//		case 4:
//			//6"3"
//		case 5:
//			//6"."���6����ܣ��ٴ�ɨ��6�����Ȼ��ֵ��.��
//	
//	}
//}	