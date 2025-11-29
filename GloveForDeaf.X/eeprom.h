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

void EEPROM_Init();
void EEPROM_WriteByte(uint16_t MemoryAddress, uint8_t Data);
void EEPROM_WritePage(uint16_t MemoryAddress, uint8_t* Data,uint8_t length);
uint8_t EEPROM_ReadByte(uint16_t MemoryAddress);
void EEPROM_ReadSequential(uint16_t MemoryAddress, uint8_t * Data,uint8_t length);

#define EEPROM_BASE_ADDR 0xA0 //1010   0     0    0     0
 //                                    p1    p2  p3    R/W                          
#endif	/* EEPROM_H */

