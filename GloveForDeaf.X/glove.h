/* 
 * File:   glove.h
 * Author: Lenovo
 *
 * Created on December 4, 2025, 12:42 AM
 */

#ifndef GLOVE_H
#define	GLOVE_H
#include "DIO.h"
#include "flex.h"

typedef struct
{
  uint8_t SIZE;
  flex_t* FLEX;
}glove_t;

void GLOVE_INIT(glove_t* GLOVE, flex_t FLEX[],uint8_t SIZE);

void GLOVE_SAMPLE(glove_t* GLOVE);

void GLOVE_GET_STATES(const glove_t*GLOVE, uint8_t STATES_ARR[], uint8_t STATES_ARR_SIZE);

#endif	/* GLOVE_H */

