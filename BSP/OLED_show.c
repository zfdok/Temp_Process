#include "pbdata.h"
#include "OLED_codeTab.h"
void OLED_Welcome(void)
{
	OLED_init();
	OLED_P8x16Str(72,0,"AL-201B");
	OLED_P32x32Ch(0,2,2);
	OLED_P32x32Ch(32,2,4);
	OLED_P32x32Ch(64,2,6);
	OLED_P32x32Ch(96,2,8);
	OLED_P6x8Str(10,7,"www.anleng-tec.com");
}
void OLED_Display()
{
	OLED_init();
	OLED_ChangeRightSatus(1);     	//判断本次货品合格性
	OLED_ChangeBLESatus(1);	 		//蓝牙状态
	OLED_P16x16Ch(32,0,12);			//是否记录中
	OLED_P16x16Ch(48,0,22);			//是否记录中
	OLED_ChangeTime(7,18); 		//默认时间7：18
	OLED_ChangePowerSatus(40);		//电池电量百分比
	OLED_ChangeTemp(0,0);   		//默认温度0.0
	OLED_P32x32Ch(96,2,0); 			//℃
	OLED_ChangeRECNum(0);		//改变记录条数
    OLED_ChangeDate(2020,12,21);    //
}
void OLED_ChangeTemp(u8 under0,float temp)
{
	if (under0)
	{
		OLED_P16x32Ch(0,2,13);
	}
	else
	{
		OLED_P16x32Ch(0,2,17);
	}
	OLED_P16x32Ch(16,2,((int)temp)/10);
	OLED_P16x32Ch(32,2,((int)temp)%10);
	OLED_P16x32Ch(48,2,10);
	OLED_P16x32Ch(64,2,((int)(temp*10))%10);
	OLED_P16x32Ch(80,2,((int)(temp*100))%10);
}
void OLED_ChangeTime(u8 hour,u8 min)
{
	witeNum8X16(72,0,hour/10);
	witeNum8X16(80,0,hour%10);
	OLED_P8x16Str(88,0,":");
	witeNum8X16(94,0,min/10);
	witeNum8X16(102,0,min%10);
}
void OLED_ChangeDate(u16 year,u8 month,u8 day)
{
	witeNum6X8(64,7,year/1000);
	witeNum6X8(70,7,(year%1000)/100);
	witeNum6X8(76,7,(year%100)/10);
	witeNum6X8(82,7,(year%10));
	OLED_P6x8Str(88,7,"-");
	witeNum6X8(92,7,month/10);
	witeNum6X8(98,7,month%10);
	OLED_P6x8Str(104,7,"-");
	witeNum6X8(110,7,day/10);
	witeNum6X8(116,7,day%10);
}
void OLED_ChangeRECNum(u32 num)
{
	if (num>99999)
	{
		witeNum6X8(0,7,num/100000);
		witeNum6X8(6,7,(num%100000)/10000);
		witeNum6X8(12,7,(num%10000)/1000);
		witeNum6X8(18,7,(num%1000)/100);
		witeNum6X8(24,7,(num%100)/10);
		witeNum6X8(30,7,num%10);
	}
	if (num>9999 & num<100000 )
	{
		witeNum6X8(0,7,(num%100000)/10000);
		witeNum6X8(6,7,(num%10000)/1000);
		witeNum6X8(12,7,(num%1000)/100);
		witeNum6X8(18,7,(num%100)/10);
		witeNum6X8(24,7,num%10);
	}
	if (num>999 & num<10000)
	{
		witeNum6X8(0,7,(num%10000)/1000);
		witeNum6X8(6,7,(num%1000)/100);
		witeNum6X8(12,7,(num%100)/10);
		witeNum6X8(18,7,num%10);
	}
	if (num>99& num<1000)
	{
		witeNum6X8(0,7,(num%1000)/100);
		witeNum6X8(6,7,(num%100)/10);
		witeNum6X8(12,7,num%10);
	}
	if (num>9& num<100)
	{
		witeNum6X8(0,7,(num%100)/10);
		witeNum6X8(6,7,num%10);
	}
		if (num<10)
	{
		witeNum6X8(0,7,num);
	}
}
void OLED_ChangeRightSatus(u8 right)
{
	if (right) OLED_P16x16Ch(0,0,13);
	else OLED_P16x16Ch(0,0,11);
}
void OLED_ChangeBLESatus(u8 on)
{
	if (on) OLED_P16x16Ch(16,0,21);
	else OLED_P16x16Ch(16,0,0);
}
void OLED_ChangeRECSatus(u8 on)
{
	if (on) OLED_P16x16Ch(32,0,12);
	else OLED_P16x16Ch(32,0,0);
}
void OLED_ChangePowerSatus(u8 percent)
{
	switch (percent)
	{
	case 100:
		OLED_P16x16Ch(112,0,14);
		break;
	case 80:
		OLED_P16x16Ch(112,0,15);
		break;
	case 60:
		OLED_P16x16Ch(112,0,16);
		break;
	case 40:
		OLED_P16x16Ch(112,0,17);
		break;
	case 20:
		OLED_P16x16Ch(112,0,18);
		break;
	case 10:
		OLED_P16x16Ch(112,0,19);
		break;
	case 0:
		OLED_P16x16Ch(112,0,20);
		break;
	default:
		break;
	}
}
void witeNum8X16(u8 x,u8 y,u8 num)
{       
	OLED_SetPos(x,y);
	for (u8 i = 0; i < 8; i++)
	{
		OLED_Wdata(F8X16[(num+16)*16+i]);
	}
	OLED_SetPos(x,y+1);
	for (u8 i = 8; i < 16; i++)
	{
		OLED_Wdata(F8X16[(num+16)*16+i]);
	}
}
void witeNum6X8(u8 x,u8 y,u8 num)
{
	OLED_SetPos(x,y);
	for (u8 i = 0; i < 6; i++)
	{
		OLED_Wdata(F6x8[16+num][i]);
	}
}