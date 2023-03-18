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
	
	