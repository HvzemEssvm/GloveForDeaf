/* 
 * File:   main.c
 * Author: Hazem
 */

#define F_CPU 16000000UL
#undef __OPTIMIZE__ //SUPERRRRRRRRRRRRRRRRRR IMPORTANTTTTTTTTTTTTTTT!!!!!
#include <stdlib.h>
#include "ADC.h"
#include "lcd1602.h"
#include "glove.h"
#include <string.h>


void updateLCD(lcd1602_t* lcd,uint8_t states[],uint8_t prev_states[], uint8_t size)
{
    bool_t isDiff = FALSE;
    for(int i = 0 ; i<size;i++)
    {
        if(states[i]!=prev_states[i])
        {
            isDiff = TRUE;
            prev_states[i] = states[i];
        }
    }
    if(isDiff)
    {
        LCD1602_CMD (lcd,CMD_CLEAR_DISPLAY_RETURN_HOME);
        for(int i = 0 ; i<size;i++)
        {
            LCD1602_INT (lcd,states[i]);
            LCD1602_STR (lcd,",");
        }
    }
}

int main()
{
    lcd1602_t lcd_1;
    flex_t flexs[5];
    glove_t glove;
    uint8_t states[5]={FLEX_STATE_NULL,FLEX_STATE_NULL,FLEX_STATE_NULL,FLEX_STATE_NULL,FLEX_STATE_NULL};;
    uint8_t prev_states[5]={FLEX_STATE_NULL,FLEX_STATE_NULL,FLEX_STATE_NULL,FLEX_STATE_NULL,FLEX_STATE_NULL};
    
    
    FLEX_INIT (flexs+0,43500.0f,43000.0f,A0);
    FLEX_INIT (flexs+1,82000.0f,80000.0f,A1);
    FLEX_INIT (flexs+2,53300.0f,52500.0f,A2);
    FLEX_INIT (flexs+3,57500.0f,56500.0f,A3);
    FLEX_INIT (flexs+4,61500.0f,60500.0f,A4);
    GLOVE_INIT (&glove,flexs,5);
    
    LCD1602_INIT (&lcd_1,A7,A6,A5,A4,B1,B2,FALSE,FALSE,FALSE);
    
    sei();
    
    LCD1602_CMD (&lcd_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
    while(1)
    {
        SET_PORTA_DIR (INPUT);// to handle that kit has A4 for LCD and ADC
        _delay_ms(5);
        GLOVE_SAMPLE (&glove);
        GLOVE_GET_STATES (&glove,states,5);
        SET_PORTA_DIR (OUTPUT);// to handle that kit has A4 for LCD and ADC
        _delay_ms(5);
        updateLCD(&lcd_1,states,prev_states,5);
        _delay_ms (10);
    }
    
    return EXIT_SUCCESS;
}

