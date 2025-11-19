/* 
 * File:   Timer.h
 * Author: Lenovo
 *
 * Created on September 13, 2025, 8:50 PM
 */

#ifndef TIMER_H
#define	TIMER_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include "DIO.h"
#include <stdint.h>
#define F_CPU 16000000UL


#define OC0 B3 
#define OC0_MODE_DISABLE 0x00
#define OC0_MODE_TOGGLE  0x10
#define OC0_MODE_RESET   0x20
#define OC0_MODE_SET     0x30
#define OC0_MODE_PWM_NORMAL OC0_MODE_RESET 
#define OC0_MODE_PWM_INVERTING OC0_MODE_SET 

#define TIMER_NORMAL 0
#define TIMER_PWM 1
#define TIMER_CTC 2
#define TIMER_FPWM 3

#define TIMER0_PS_DISABLE 0
#define TIMER0_PS_1 1
#define TIMER0_PS_8 2
#define TIMER0_PS_64 3
#define TIMER0_PS_256 4
#define TIMER0_PS_1024 5
#define TIMER0_PS_EXT_FALLING 6
#define TIMER0_PS_EXT_RISING 7

/**
 * 
 * @param TIMER0_PS You could use it as a counter by setting TIMER0_PS to either TIMER0_PS_FALLING or TIMER0_PS_RISING
 *                  and connect the src on T0 (D4) PIN  (it could be configured as output and make software counting!!!)
 */
void TIMER0_CLK(uint8_t TIMER0_PS);

/**
 * ONLY USE IT IF TIMER0 OVERFLOW INTERRUPT IS DISABLED TO CLEAR THE FLAG MANUALLY
 */
void TIMER0_CLEAR_OVERFLOW_FLAG();

/**
 * ONLY USE IT IF TIMER0 COMPARE MATCH INTERRUPT IS DISABLED TO CLEAR THE FLAG MANUALLY
 */
void TIMER0_CLEAR_COMPARE_MATCH_FLAG();

/**
 * 
 * @param MODE : [ TIMER_NORMAL, TIMER_PWM, TIMER_CTC, TIMER_FPWM
 */
void TIMER0_MODE(uint8_t MODE);
void TIMER0_OC_PIN(uint8_t OC0_MODE);
void TIMER0_SET_OCR(uint8_t VAL);
void TIMER0_OVERFLOW_INT_ENABLE();
void TIMER0_OVERFLOW_INT_DISABLE();
void TIMER0_COMPARE_MATCH_INT_ENABLE();
void TIMER0_COMPARE_MATCH_INT_DISABLE();

#endif	/* TIMER_H */

