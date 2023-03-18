#ifndef __DS18B20_H_
#define __DS18B20_H_

 void show_ds18b20_DOT();
 void Read_DS18b20_config();
 void SMG_DS18b20_DOT();
 void SMG_DS18b20_NODOT();


extern uint temp;
//extern uint temp_0;
extern uint dat_1;
extern uint dat_3;
extern uchar count;

extern uchar SMGNO_DOT[11];
//extern uchar SMG_DOT[10];

#endif