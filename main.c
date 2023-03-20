#include "include.h"




void main()
{

	Ds1302_config();
	InitTimer0();

	while(1) 
	{
		  
		Read_ds1302_Timer();
		Read_DS18b20_config();
		Key_menu();
		add_minus_key();

	}
}
