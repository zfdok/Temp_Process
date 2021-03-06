/************************************************************************/

#ifndef _OLED12864_H  //宏定义，定义文件名称
#define _OLED12864_H
#include "stm8s.h"//引用STM8头文件

extern u8 OLED_ON_FLAG;
extern u8 time_shutOLED_count;//定时关闭OLED的计数器

void OLED_Wcmd(u8 cmd);
void OLED_Wdata(u8 data);
void OLED_SetPos(u8 x,u8 y);
void OLED_Fill(u8 bmp_dat);
void OLED_CLS(void);
void OLED_init(void);
void OLED_P6x8Str(u8 x,u8 y,u8 ch[]);
void OLED_P8x16Str(u8 x,u8 y,u8 ch[]);
void OLED_P16x16Ch(u8 x,u8 y,u8 N);
void OLED_P16x32Ch(u8 x,u8 y,u8 N);
void OLED_P32x32Ch(u8 x,u8 y,u8 N);
void OLED_ChangeTemp(u8 under0,float temp);
void OLED_ChangeTime(u8 hour,u8 min);
void OLED_ChangeDate(u16 year,u8 month,u8 day);
void OLED_ChangeRECNum(u32 num);
void OLED_ChangeRightSatus(u8 right);
void OLED_ChangeBLESatus(u8 on);
void OLED_ChangeRECSatus(u8 on);
void OLED_ChangePowerSatus(u8 percent);
void witeNum8X16(u8 x,u8 y,u8 num);
void witeNum6X8(u8 x,u8 y,u8 num);
void OLED_Welcome(void);
void OLED_Display();

#endif //定义文件名称结束