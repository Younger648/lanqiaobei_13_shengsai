#ifndef __CONFIG_H_
#define __CONFIG_H_


	

//ds1302���Ŷ���
sbit SCK=P1^7;		
sbit SDA=P2^3;		
sbit RST = P1^3;   // DS1302��λ	





//IIC�������Ŷ���
//sbit SDA = P2^1;  /* ������ */
sbit SCL = P2^0;  /* ʱ���� */




//�����������Ŷ���
//sbit S7 = P3^0;
//sbit S6 = P3^1;
//sbit S5 = P3^2;
//sbit S4 = P3^3;




//����������Ŷ���

sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;

sbit C4 = P3^4;
sbit C3 = P3^5;
sbit C2 = P4^2;
sbit C1 = P4^4;



//LED�����Ŷ���
sbit L1 = P0^0;
sbit L2 = P0^1;
sbit L3 = P0^2;
sbit L4 = P0^3;
//sbit L5 = P0^4;
sbit L6 = P0^5;
sbit L7 = P0^6;
sbit L8 = P0^7;


sbit jidianqi = P0^4;


#define DELAY_TIME 5

#define SlaveAddrW 0xA0
#define SlaveAddrR 0xA1

#endif