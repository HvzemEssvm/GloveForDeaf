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
  int SIZE;
  flex_t* FLEX;
}glove_t;

void GLOVE_INIT(glove_t* GLOVE, flex_t FLEX[],int SIZE);

void GLOVE_SAMPLE(glove_t* GLOVE);

void GLOVE_GET_STATES(const glove_t*GLOVE, int STATES_ARR[], int STATES_ARR_SIZE);

#endif	/* GLOVE_H */

