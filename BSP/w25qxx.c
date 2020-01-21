#include "pbdata.h"

void W25QXX_GPIO(void)
{
    GPIO_Init(W25Q_CS_PORT, W25Q_CS_PIN, GPIO_MODE_OUT_OD_HIZ_SLOW);
}

u8 W25QXX_ReadSR(void)
{
    u8 byte=0;
    
    W25Q_CS_L;
    SPI_SendByte(W25X_ReadStatusReg);
    byte=SPI_SendByte(0);
    W25Q_CS_H;
    return byte;
}

void W25QXX_Write_Enable(void)
{    
    W25Q_CS_L;
    SPI_SendByte(W25X_WriteEnable);
    W25Q_CS_H;
}

void W25QXX_Wait_Busy(void)
{    
    while(W25QXX_ReadSR()&0x01==0x01);
}

void W25QXX_Erase_Chip(void)
{    
    W25QXX_Write_Enable();
    W25QXX_Wait_Busy();

    W25Q_CS_L;
    SPI_SendByte(W25X_ChipErase);
    W25Q_CS_H;

    W25QXX_Wait_Busy();
}

void W25QXX_Erase_Sector(u32 Dst_Addr)
{    
    Dst_Addr*=4096;
    
    W25QXX_Write_Enable();
    W25QXX_Wait_Busy();

    W25Q_CS_L;
    SPI_SendByte(W25X_SectorErase);
    SPI_SendByte((u8)(Dst_Addr>>16));
    SPI_SendByte((u8)(Dst_Addr>>8));
    SPI_SendByte((u8)(Dst_Addr));
    W25Q_CS_H;
    W25QXX_Wait_Busy();
}

void W25QXX_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead)
{
    u16 i=0;
  
    W25QXX_Wait_Busy();
    
    W25Q_CS_L;
    SPI_SendByte(W25X_ReadData);
    SPI_SendByte((u8)(ReadAddr>>16));
    SPI_SendByte((u8)(ReadAddr>>8));
    SPI_SendByte((u8)(ReadAddr));
    
    for(i=0;i<NumByteToRead;i++)
    {
        pBuffer[i]=SPI_SendByte(0);
    }
  
    W25Q_CS_H;
}

void W25QXX_Write_Page(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
    u16 i=0;
  
    W25QXX_Write_Enable();
    W25QXX_Wait_Busy();
    
    W25Q_CS_L;
    SPI_SendByte(W25X_PageProgram);
    SPI_SendByte((u8)(WriteAddr>>16));
    SPI_SendByte((u8)(WriteAddr>>8));
    SPI_SendByte((u8)(WriteAddr));
    
    for(i=0;i<NumByteToWrite;i++)
    {
        SPI_SendByte(pBuffer[i]);
    }
    W25Q_CS_H;
    W25QXX_Wait_Busy();
}

void W25QXX_Demo(void)
{
    u8 pBuffer1[]="1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    u8 pBuffer2[]="000000000000000000000000000000000000";
    
    W25QXX_Erase_Sector(0);
    
    W25QXX_Write_Page(pBuffer1,0,36);
    delay_ms(20);
    
    W25QXX_Read(pBuffer2,0,36);
    
    if(strcmp(pBuffer1,pBuffer2)==0)
    {
        printf("W25QXX ¶ÁÐ´¼ì²â¡¾³É¹¦¡¿\r\n");
        printf("%s\r\n",pBuffer2);
    }
    else
    {
        printf("W25QXX ¶ÁÐ´¼ì²â¡¾Ê§°Ü¡¿\r\n");
    }
}













