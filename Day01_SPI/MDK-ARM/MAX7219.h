#ifndef _MAX7219_H
#define _MAX7219_H
#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "spi.h"
#include "stdio.h"
void Init_MAX7219(uint16_t deviceid);
void MX7219_Write_Byte(uint8_t Data);
void MAX7219_CS(uint16_t deviceid,GPIO_PinState PinState);
void MX7219_Write(uint16_t deviceid,uint8_t address, uint8_t Data);
#endif
