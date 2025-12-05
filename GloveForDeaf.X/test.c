/* 
 * File:   main.c
 * Author: Hazem
 */

#define F_CPU 16000000UL
#undef __OPTIMIZE__ //SUPERRRRRRRRRRRRRRRRRR IMPORTANTTTTTTTTTTTTTTT!!!!!
#include <stdlib.h>
#include <string.h>

#include "ADC.h"
#include "lcd1602.h"
#include "glove.h"
#include "eeprom.h"

lcd1602_t lcd_1;

uint16_t addressHasher(int combination[5])
{
    uint16_t idx = 0;
    int weight = 1;
    for (int i = 4; i >= 0; i--) {
        int base3_digit = combination[i] - 1;
        idx += base3_digit * weight;
        weight *= 3;
    }
    
    LCD1602_CMD (&lcd_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
    LCD1602_INT (&lcd_1,(idx*50)%2048);
    _delay_ms (2000);
    return (idx*50)%2048;
}

void eepromWriter()
{
    EEPROM_ClearALL();
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Awesome!",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"I Love U",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"I really love U",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"I watch U",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"You",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Good job!",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Question",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_HALF,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"I agree",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Quote",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"No",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Made me laugh",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Hello",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Not sure",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"I am fine",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Thanks",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ((uint8_t*)"Thanks",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
}   

void eepromReader(uint8_t states[5],char buffer[],int bufferSize)
{
    char str[bufferSize];
    EEPROM_ReadString (addressHasher (states),(uint8_t*)str,bufferSize);
    if(str == NULL || strlen(str)<=1)
    {
        strcpy (buffer,"");
    }
    else
    {
        strcpy (buffer,str);
    }    
}

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
        char str[50];
        eepromReader (states,str,50);
        LCD1602_STR (lcd,str);
    }
}

int main()
{
    
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
    
    EEPROM_INIT ();
    _delay_ms (50);
    eepromWriter ();
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

