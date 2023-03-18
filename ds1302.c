#include "include.h"

uchar Write_ds1302_adrr [7] = {0x80,0x82,0x84,0x86,0x88,0x8a,0x8c};
uchar Read_ds1302_adrr [7] = {0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};
uchar Time [7] = {0x30,0x59,0x22,0x12,0x11,0x01,0x23};//秒，分，时，日，月，周，年


uint dat_2;
				

void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK=0;
		SDA=temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i,temp=0x00;
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1;	_nop_();
 	Write_Ds1302(address);
 	for (i=0;i<8;i++) 	
 	{		
		SCK=0;
		temp>>=1;	
 		if(SDA)
 		temp|=0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
	SCK=1;	_nop_();
	SDA=0;	_nop_();
	SDA=1;	_nop_();
	return (temp);			
}











void Ds1302_config()//配置DS1302
 {
   uchar i;
	 Write_Ds1302_Byte(0x8e,0x00);//打开写入保护
	 for(i = 0;i < 7;i ++)
	 {
	   Write_Ds1302_Byte(Write_ds1302_adrr [i],Time [i]);
	 }
	 Write_Ds1302_Byte(0x8e,0x80);//关闭写入保护
 }
 
 
 
 

void Read_ds1302_Timer()//读地址（将7个地址读出来）
 {
   uchar i;
	 for(i = 0; i < 7; i++)
	 {
	  Time [i] = Read_Ds1302_Byte(Read_ds1302_adrr [i]);
	 }
 
 }
 
 
 
 



void SMG_ds1302_scon()
{

		 static char b;
	   b ++;
		 if(b == 8)
		 b = 1;
		 switch(b)
		 {
		   case 1:
			   dat_2 = 17;
			   adree = 0;
			 break;
			 
		 	 case 2:
			   dat_2 = 2;
			   adree = 1;
			 break;
			 
			 case 3:
			   dat_2 = Time [2] / 16;
			   adree = 3;
			 break;
			 
			 case 4:
			   dat_2 = Time [2] % 16;
			   adree = 4;
			 break;
			 
			 case 5:
			   dat_2 = 19;
			   adree = 5;
			 break;
			 
			 case 6:
			   dat_2 = Time [1] / 16;
			   adree = 6;
			 break;
			 
			 case 7:
			   dat_2 = Time [1] % 16;
			   adree = 7;
			 break;
		 }
		 SMGbit(SMG_duanma[dat_2],SMG_weizhi[adree]);
 }	 
	 
	




 
 
 
 
 

 
 

 
 
 
 
 
 
 
 



