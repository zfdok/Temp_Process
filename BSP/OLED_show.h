/************************************************************************/

#ifndef _OLED_show_H  //宏定义，定义文件名称
#define _OLED_show_H

#include "stm8s.h"//引用STM8头文件

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