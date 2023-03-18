#include "include.h"


 
 
void SMG_1302()
{
	SMGbit(SMGNO_DOT[Time[1] / 16],SMG_weizhi[0]);
	delay(10);
	SMGbit(SMGNO_DOT[Time[1] % 16],SMG_weizhi[1]);
	delay(10);
	SMGbit(SMGNO_DOT[Time[0] / 16],SMG_weizhi[2]);
	delay(10);
	SMGbit(SMGNO_DOT[Time[0] % 16],SMG_weizhi[3]);
	delay(10);
	SMGbit(0xff,SMG_weizhi[4]);
	delay(10);
	SMGbit(0xff,SMG_weizhi[5]);
	delay(10);
	SMGbit(0xff,SMG_weizhi[6]);
	delay(10);
	SMGbit(0xff,SMG_weizhi[7]);
	delay(10);

}




