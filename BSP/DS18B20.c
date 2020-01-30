#include "pbdata.h"
static u16 temp_u16=0;
static float temp_f=0;
float temp;
extern u8 wflag; 


u8 wflag=0;

void DS18B20_IO(u8 ds18b20_io)
{
  if (ds18b20_io)
  {
    GPIO_Init(DS18B20_PORT, DS18B20_PIN, GPIO_MODE_OUT_PP_HIGH_SLOW);
  }
  else
  {
    GPIO_Init(DS18B20_PORT, DS18B20_PIN, GPIO_MODE_IN_FL_NO_IT);
  }
}
void DS18B20_reset(void)
{
  u8 havenoDS=0,haveflag=0;
  u16 count=700;
  DS18B20_IO(1);
  GPIO_WriteHigh(DS18B20_PORT, DS18B20_PIN);
  delay(1700);
  GPIO_WriteLow(DS18B20_PORT, DS18B20_PIN);
  delay(1700);
  GPIO_WriteHigh(DS18B20_PORT, DS18B20_PIN);
  DS18B20_IO(0);
  delay(65);
  havenoDS=GPIO_ReadInputPin(DS18B20_PORT, DS18B20_PIN);
  //printf("I'm scaning~\r\n");
  while (count--)
  {
    if (!havenoDS) haveflag=1;
    if (haveflag) break;
  }
  if (!haveflag)
  {
    printf("I got nothing!\r\n");
  }
  delay(1150);
}
void DS18B20_Wbyte(u8 data)
{
  u8 i=0, k=0;
  for (i = 0; i < 8; i++)
  {
    k=data & 0X01;
    DS18B20_IO(1);
    if (k)
    {
      GPIO_WriteLow(DS18B20_PORT, DS18B20_PIN);
      delay(30);
      GPIO_WriteHigh(DS18B20_PORT, DS18B20_PIN);
      delay(100);
    }
    else
    {
      GPIO_WriteLow(DS18B20_PORT, DS18B20_PIN);
      delay(130);
      GPIO_WriteHigh(DS18B20_PORT, DS18B20_PIN);
    }
    data =data>>1;
  }
}
u8 DS18B20_RBit(void)
{
  u8 recive_data=0,x=0;
  DS18B20_IO(1);
  GPIO_WriteHigh(DS18B20_PORT, DS18B20_PIN);
  delay(2);
  GPIO_WriteLow(DS18B20_PORT, DS18B20_PIN);
  delay(5);
  GPIO_WriteHigh(DS18B20_PORT, DS18B20_PIN);
  DS18B20_IO(0);
  delay(10);
  x=GPIO_ReadInputPin(DS18B20_PORT, DS18B20_PIN);
  delay(150);
  if (x)
  {
    recive_data=0X80;
  }
  else
  {
    recive_data=0;
  }
  return recive_data;
}
u8 DS18B20_RByte(void)
{
  u8 recive_byte=0,temp_byte=0;
  for (u8 i = 0; i < 8; i++)
  {
    temp_byte=DS18B20_RBit();
    recive_byte=recive_byte>>1;
    recive_byte |= temp_byte;
  }
  return recive_byte;
}
void DS18B20_ReadTempRequest(void)
{
    DS18B20_reset();    
    delay(1000);
    DS18B20_Wbyte(0XCC);
    DS18B20_Wbyte(0X44);
}
float DS18B20_ReadTemp(void)
{
  u8 LSB=0,HSB=0;
  DS18B20_reset();
  delay(1000);
  DS18B20_Wbyte(0XCC);
  DS18B20_Wbyte(0XBE);
  delay(1000);
  LSB=DS18B20_RByte();
  HSB=DS18B20_RByte();
  //printf("HSB:%d\r\n",HSB);
  //printf("LSB:%d\r\n",LSB);
  temp_u16=HSB;
  temp_u16=temp_u16 << 8;
  temp_u16 |=LSB;
  //printf("temp_u16:%d\r\n",temp_u16);
  if (temp_u16<=0X07FF)
  {
    wflag=1;
    temp_f=temp_u16*0.0625;
  }
  else
  {
    wflag=0;
    temp_u16=~(temp_u16-1);
    temp_f=temp_u16*0.0625;
  }
  
//  printf("temp_f:%f\r\n",temp_f);
  return temp_f;
}
void TempGetAndSave(void)
{
    DS18B20_ReadTempRequest();
    temp= DS18B20_ReadTemp();
    if (temp<80)
    {
      if(wflag) 
      {
        printf("当前温度: %d℃\r\n",(int)(temp*100));
        printf("OLED_ON_FLAG%d\r\n",OLED_ON_FLAG);
        if(OLED_ON_FLAG)
        {
          OLED_ChangeTemp(0,temp);
        }
      }
      else
      {
        printf("当前温度:-%d℃\r\n",(int)(temp*100));
        printf("OLED_ON_FLAG%d\r\n",OLED_ON_FLAG);
        if(OLED_ON_FLAG)
        {
          OLED_ChangeTemp(1,temp);
        }
      }
    }
}