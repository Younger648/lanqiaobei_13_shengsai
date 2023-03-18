#include <STC15F2K60S2.H>

void Init_INT0()
 {
  IT0 = 1;
	EA = 1;
	EX0 = 1;
 }