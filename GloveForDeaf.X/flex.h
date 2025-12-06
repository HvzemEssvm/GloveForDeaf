/* 
 * File:   flex.h
 * Author: Lenovo
 *
 */

#ifndef FLEX_H
#define	FLEX_H
#include "DIO.h"
#include "ADC.h"

#define FLEX_STATE_OPEN   1
#define FLEX_STATE_HALF   2
#define FLEX_STATE_CLOSED 3
#define FLEX_STATE_NULL   0

typedef struct
{
  float RES_CLOSED;
  float RES_OPEN;
  uint8_t PORT_PIN_ADC;
  int STATE;
}flex_t;

void FLEX_INIT(flex_t* FLEX,float RES_CLOSED,float RES_OPEN,uint8_t PORT_PIN_ADC);

void FLEX_SAMPLE(flex_t* FLEX);

int FLEX_GET_STATE(const flex_t* FLEX);

#endif	/* FLEX_H */

