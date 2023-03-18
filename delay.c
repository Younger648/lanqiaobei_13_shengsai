#include "include.h"

void delay(uint z)
 {
   uint x, y;
	 for(x = z; x > 0; x--)
    for(y = 114; y > 0; y--);
 }
 
 void delaySMG(uint l)
 {
  while(l--);
 }

 
 //单总线延时函数
void Delay_OneWire(unsigned int t)  //STC89C52RC
{
	while(t--);
}


/********************************************5ms****************************************************/
void Delay5ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
