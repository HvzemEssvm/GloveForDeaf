/* 
 * File:   TWI.h
 * Author: Nour
 *
 * Created on November 21, 2025, 8:18 PM
 */

#ifndef TWI_H
#define	TWI_H
#define F_CPU 16000000UL
#define SCL_CLOCK 100000UL
#include <stdio.h>
#include <stdint.h>
#include <avr//io.h>
#include "DIO.h"

void TWI_Init(void);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_WriteAddress(uint8_t address);
void TWI_Write(uint8_t data);
uint8_t TWI_ReadACK(void);
uint8_t TWI_ReadNACK(void);

#endif


