/* 
 * File:   eeprom.h
 * Author: Habiba
 *
 * Created on November 24, 2025, 6:56 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include "TWI.h"
#include <util/delay.h>
#include <string.h>

#define EEPROM_BASE_DEV_ADDR 0xA0 //1010   0     0    0     0
 //                                    p1    p2  p3    R/W   
#define EEPROM_BLOCK1_START 256

void EEPROM_Save_Address_Of_Sent_To_Block1(uint8_t index, uint16_t sentence_address);
uint16_t EEPROM_Get_Address_From_Block1(uint8_t index);

void EEPROM_ReadString(uint16_t startAddr, char buffer[],unsigned int bufferSize);

void EEPROM_ClearALL();
uint16_t EEPROM_APPEND(char data[]);
uint16_t EEPROM_APPEND_CUSTOM_MEM(char data[],uint16_t StartAddress);
void EEPROM_INIT();
void EEPROM_WriteByte(uint16_t MemoryAddress, char Data);
void EEPROM_WritePage(uint16_t MemoryAddress, char Data[],uint8_t length);
uint8_t EEPROM_ReadByte(uint16_t MemoryAddress);
void EEPROM_ReadSequential(uint16_t MemoryAddress, uint8_t * Data,uint8_t length);


#endif	/* EEPROM_H */

