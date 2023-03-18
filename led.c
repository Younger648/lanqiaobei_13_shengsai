#include "include.h"


unsigned P0_DAT = 0xff;





void LED_config(unsigned char ledx,unsigned char ledx_en)
{
	if(ledx_en == 0)
		P0_DAT |= 0x01<<(ledx-1);
	else
		P0_DAT &= ~(0x01<<(ledx-1));
	
	P0 = P0_DAT;
}



