#include "include.h"

//uchar code Key_weizhi[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar key_num = 0;



void KBD(uchar e)
 {
  switch(e)
	{
		case 1:
	 	R1 = 0;
		R2 = R3 = R4 = 1;
		C1 = C2 = C3 = C4 = 1;//第一行行扫描
	  break;
	
		case 2:
	 	R2 = 0;
		R1 = R3 = R4 = 1;
		C1 = C2 = C3 = C4 = 1;//第二行行扫描
	  break;
				
		case 3:
	 	R3 = 0;
		R1 = R2 = R4 = 1;
		C1 = C2 = C3 = C4 = 1;//第三行行扫描
	  break;
						
		case 4:
	 	R4 = 0;
		R1 = R2 = R3 = 1;
		C1 = C2 = C3 = C4 = 1;//第四行行扫描
	  break;                
	
	}
 
 }

	
/*************************独立按键控制SMG循环显示*************************/

//void KeySMG()
//{
//  static	uchar i = 0;
//	if(S4 == 0)
//	{
//		delay(10);
//		if(S4 == 0)
//		{
//		if(i >= 21)
//		{
//			i = 0;
//		}
//		else
//		{
//		  i = i + 1;
//		}
//		while(S4 == 0);
//		}
//	}

//	SMGbit(SMG_duanma[i],SMG_weizhi[1]);
//}
// 
 
 
 
/**************************独立按键控制LED1点亮熄灭********************************/

//void KeyLED()
// {
//   if(S4 == 0)
//	 {
//	   delay(100);
//		 if(S4 == 0)
//		 {
//			 while(S4 == 0)
//			 L1 = ~L1;	 
//		 }		 
//	 }
// }


/***********************************独立按键控制LED灯位移********************************************/
//void KeyLED_weiyi()
// {
//	 
//   static uchar i = 0;
//   if(S4 == 0)
//	 {
//	   delay(100);
//		 if(S4 == 0)
//		 {
//			 if(i >= 8)
//			 {
//			  i = 0;
//			 }
//			 else
//			 {
//			  i = i + 1;
//			 }
//		 while(S4 == 0);
//		 }
//	 }
//   P0 = Key_weizhi[i];
// }




/**************************矩阵键盘控制数码管切换数字******************************/
//void ScanKey_SMG()
//{
// 
//	 static uchar i = 0;
//	 R4 = 0;
//	 R1 = R2 = R3 = 1;
//	 C1 = C2 = C3 = C4 = 1;
//	 
////	 if(C4 == 0)
////	 {
////	 while(C4 == 0)
////	 key_num = 15;
////	 SMGbit(SMG_duanma[key_num],SMG_weizhi[7]);
////	 }
//	 
//	 if(C4 == 0)
//	 {
//			if(i >= 21)
//		{
//			i = 0;
//		}
//		else
//		{
//		  i = i + 1;
//		}
//		while(C4 == 0);
//		}
//	

//	SMGbit(SMG_duanma[i],SMG_weizhi[1]);
//	 
//	 }
 














 
 
