#include "include.h"

char Scon = 1;







/*********���������л�ģʽ�˵�ϵͳ****************/ 
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
