#include "include.h"


uchar adree;//定义数码管位置的变量

/************************************数码管选值**********************************/
uchar code SMG_duanma[22] ={	
	0xc0,//0
	0xf9,//1
	0xa4,//2
	0xb0,//3
	0x99,//4
	0x92,//5
	0x82,//6
	0xf8,//7
	0x80,//8
	0x90,//9
	0x88,//A
	0x83,//B
	0xc6,//C
	0xa1,//D
	0x86,//E
	0x8e, //F
	0x8c,//P
	0xc1,//U
	0x91,//Y,L
	0xbf,//-
	0x7f,
  0xff};


/*********************************数码管位置***************************************/
uchar code SMG_weizhi[8] ={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};





 
void SMGbit(uchar dat,uchar pos)//配置数码管显示位置和数据
 {
	 SelectHC573(6);
	 P0 = pos;
	 delaySMG(1);
	 SelectHC573(7);
	 P0 = dat;
 } 

 
 
 
 
//void Display_ALL(uchar dat)//数码管全选中
// {
//   SelectHC573(6);
//	 P0 = 0xff;
//	 SelectHC573(7);
//	 P0 = dat;
// }
// 
 
 
