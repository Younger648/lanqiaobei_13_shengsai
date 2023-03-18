#ifndef __DS1302_H_
#define __DS1302_H_

void Write_Ds1302(unsigned char temp);
void Write_Ds1302_Byte( unsigned char address,unsigned char dat );
unsigned char Read_Ds1302_Byte( unsigned char address );
void Ds1302_config();
void Read_ds1302_Timer();
void SMG_DS1302();
void ShowSMG_DS1302();
extern uchar Write_ds1302_adrr [7];
extern uchar Read_ds1302_adrr [7];
extern uchar Time [7];

extern uint dat_2;


#endif
