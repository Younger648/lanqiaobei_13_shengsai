#include "include.h"


 
void jidianqi_scon()
{
  SelectHC573(5);
	
	if((temp / 10 >= count) || (Time [1] == 0 && Time [0] < 6))
	{
		
		jidianqi = 1;
		BUZZ = 0;
	}
	
	else
	{

		jidianqi = 0;
		BUZZ = 0;
	}
	

}




	
	
	
