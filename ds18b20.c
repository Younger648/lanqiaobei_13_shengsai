#include "include.h"

uchar SMGNO_DOT[11] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x7f};//不带小数点的段选表
//uchar SMG_DOT[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};//带小数点的段选表

uint temp;
uint dat_1;
uint dat_3;
uchar count = 23;

///************************带小数点的数码管显示***************************/



void SMG_ds18b20_scon()
{	 
     static char a; 
	   a ++;
		 if(a == 7)
		 a = 1;
		 switch(a)
		 {
		   case 1:
			   dat_3 = 17;
			   adree = 0;
			 break;
			 
		 	 case 2:
			   dat_3 = 1;
			   adree = 1;
			 break;
			 
			 case 3:
			   dat_3 = temp / 100;
			   adree = 5;
			 break;
			 
			 case 4:
			   dat_3 = (temp % 100) / 10;
			   adree = 6;
			 break;
						 
			 case 5:
			   dat_3 = 20;
			   adree = 6;
			 break;
			 
			 case 6:
			   dat_3 = temp % 10;
			   adree = 7;
			 break;
		 }
		 SMGbit(SMG_duanma[dat_3],SMG_weizhi[adree]);
 }

 




/************************不带小数点的数码管显示***************************/
 


void SMG_ds18b20_scon1()
{
	
	  static char c; 
		c ++;
		if(c == 5)
		c = 1;
		switch(c)
		{
			case 1:
			dat_1 = 17;
			adree = 0;
			break;

			case 2:
			dat_1 = 3;
			adree = 1;
			break;

			case 3:
			dat_1 = count / 10;
			adree = 6;
			break;

			case 4:
			dat_1 = count % 10;
			adree = 7;
			break;

		}
	SMGbit(SMG_duanma[dat_1],SMG_weizhi[adree]);		 
}


void add_minus_key()
{
//S16按下数字增加
	KBD(3);
	if(C4 == 0)
	{
//		 EA = 0;
		 Delay5ms();
		 if(C4 == 0)
		 {
			count ++;
		 }
		 while(C4 == 0);
//		 EA = 1;
	}


		
		
//矩阵键盘S7按下数字减小
  	KBD(4);
		if(C4 == 0)
		{
//			EA = 0;
		  Delay5ms();//按键消抖
			if(C4 == 0)
			{
				count --;
			}	
			while(C4 == 0);	//按键松手检测
//      EA = 1;			
	}
		
		
	if(count >= 99)
  count = 99;
  
  if(count <= 10)
  count = 10;		
		
		
}


 
 
/************************带小数点的配置***************************/ 
void Read_DS18b20_config()//带小数点的配置
 {
	 uchar LSB ,HSB;
	 EA = 0;
   init_ds18b20();
	 EA = 1;
	 Write_DS18B20(0xcc);
   Write_DS18B20(0x44);
		
	 delaySMG(10000);
		EA = 0;
	 init_ds18b20();
	 	EA = 1;
	 Write_DS18B20(0xcc);
   Write_DS18B20(0xbe);
		
	 LSB = Read_DS18B20();//高八位
   HSB = Read_DS18B20();//低八位
		
		temp = HSB;
		temp = (temp << 8) | LSB;
		if((temp & 0x800) == 0x0000)
		{
		 temp >>= 4;
		 temp = temp * 10;
		 temp = temp + (LSB & 0x0f) * 0.625;
		
		}
 }

 
 
 
 
 
 
 
 
 
 
 
 
 
 
///************************不带小数点的配置***************************/
//void Read_DS18b20_config_0()
// {
//	 uchar LSB_0,HSB_0;
//   init_ds18b20();
//	 Write_DS18B20(0xcc);
//   Write_DS18B20(0x44);
//		
//	 delaySMG(100);
//		
//	 init_ds18b20();
//	 Write_DS18B20(0xcc);
//   Write_DS18B20(0xbe);
//		
//	 LSB_0 = Read_DS18B20();//高八位
//   HSB_0 = Read_DS18B20();//低八位
//		
//		temp_0 = HSB_0;
//		temp_0 = (temp_0 << 8) | LSB_0;
//		temp_0 >>= 4;
//		
//		}
 

	

		

	

 
 
 