#include "include.h"

char Scon = 1;







/*********独立键盘切换模式菜单系统****************/ 
void Key_menu()
{
	KBD(4);
	if(C3 == 0)
	{ 	 
		Delay5ms(); 
		if(C3 == 0)
		{ 
			Scon++;
			if(Scon == 4)
			Scon = 1;
		}
		while(C3 == 0); 
	}
}
	
	


void menu_TIMER()
{
	//菜单1
	if(Scon == 1)
		SMG_ds18b20_scon();
	//菜单2
	else if(Scon == 2)
		SMG_ds1302_scon();
	//菜单3
	else if(Scon == 3)
		SMG_ds18b20_scon1();
}
