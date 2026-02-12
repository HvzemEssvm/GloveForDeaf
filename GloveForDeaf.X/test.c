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

/*uint16_t addressHasher(int states[5])
{
    uint16_t address = 0;
    int weight = 1;
    for (int i = 3; i >= 0; i--) {
        int base3_digit = states[i] - 1;
        address += base3_digit * weight;
        weight *= 3;
    }
    return (address*50)*2048;
}*/

uint16_t addressHasher(int states[4])
{
    uint16_t address = 0;
    uint16_t weight = 1;

    for (int i = 3; i >= 0; i--) {
        address += states[i] * weight;
        weight *= 3;
    }
   return address * 60;
}

void eepromWriter()
{
    //EEPROM_ClearALL();
    EEPROM_APPEND_CUSTOM_MEM ("Awesome!",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ("I Love U",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("I really love U",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("I watch U",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("You",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("Good job!",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("Question",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_HALF,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("I agree",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("Quote",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_CLOSED}));//msh shaghal
    EEPROM_APPEND_CUSTOM_MEM ("No",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_CLOSED}));//msh shaghal
    EEPROM_APPEND_CUSTOM_MEM ("Made me laugh",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_CLOSED,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("Hello",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ("Not sure",
                              addressHasher ((int[]){FLEX_STATE_OPEN,FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_CLOSED}));
    EEPROM_APPEND_CUSTOM_MEM ("I am fine",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_HALF,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ("Thanks",
                              addressHasher ((int[]){FLEX_STATE_CLOSED,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
    EEPROM_APPEND_CUSTOM_MEM ("Bye",
                              addressHasher ((int[]){FLEX_STATE_HALF,FLEX_STATE_OPEN,FLEX_STATE_OPEN,FLEX_STATE_OPEN}));
}   

void eepromReader(int states[5],char buffer[],int bufferSize)
{
    char str[bufferSize];
    EEPROM_ReadString (addressHasher (states),str,bufferSize);
    if(str == NULL || strlen(str)<=1)
    {
        strcpy (buffer,"");
    }
    else
    {
        strcpy (buffer,str);
    }    
}

void updateLCD(lcd1602_t* lcd,int states[],int prev_states[], uint8_t size)
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

void calib_flex(lcd1602_t* lcd, uint8_t port_pins_adc[], float RES_OPEN[],float RES_CLOSED[],int size)
{
    LCD1602_CMD (lcd,CMD_CLEAR_DISPLAY_RETURN_HOME);
    LCD1602_STR (lcd,"Calibrating...");
    _delay_ms(500);
    LCD1602_CMD (lcd,CMD_CLEAR_DISPLAY_RETURN_HOME);
    LCD1602_STR (lcd,"Open Hand Widely");
    _delay_ms(5000);
    
    for(int i=0;i<size;i++)
    {
        ADC_CHANGE_CHANNEL (port_pins_adc[i]);
        ADC_MANUAL_SAMPLE ();
        ADC_READ ();
        ADC_MANUAL_SAMPLE ();
        float val = (((float)ADC_READ())/1023.0f)*5;
        val = 47000.0f / (5.0f/val - 1.0f);
        RES_OPEN[i] = val;
    }
    
    LCD1602_CMD (lcd,CMD_CLEAR_DISPLAY_RETURN_HOME);
    LCD1602_STR (lcd,"Close Hand Firmly");
    _delay_ms(5000);
    
    for(int i=0;i<size;i++)
    {
        ADC_CHANGE_CHANNEL (port_pins_adc[i]);
        ADC_MANUAL_SAMPLE ();
        ADC_READ ();
        ADC_MANUAL_SAMPLE ();
        float val = (((float)ADC_READ())/1023.0f)*5;
        val = 47000.0f / (5.0f/val - 1.0f);
        RES_CLOSED[i] = val;
    }
    
    LCD1602_CMD (lcd,CMD_CLEAR_DISPLAY_RETURN_HOME);
    LCD1602_STR (lcd,"Finished calibration");
    _delay_ms(2000);
    LCD1602_CMD (lcd,CMD_CLEAR_DISPLAY_RETURN_HOME);
}

int main()
{
    lcd1602_t lcd_1;
    flex_t flexs[4];
    glove_t glove;
    int states[4]={FLEX_STATE_NULL};
    int prev_states[4]={FLEX_STATE_NULL};
    float RES_OPEN[4];
    float RES_CLOSED[4];
    uint8_t port_pins_adc[4] = {A0,A1,A2,A3};
    ADC_INIT_POLL(VREF_AVCC,0,ADC_PS_128,FALSE);
    LCD1602_INIT (&lcd_1,A7,A6,A5,A4,B1,B2,FALSE,FALSE,FALSE);
    _delay_ms(10);
    
    calib_flex(&lcd_1,port_pins_adc,RES_OPEN,RES_CLOSED,4);
    
    for(int i = 0; i<4;i++)
    {
//        LCD1602_CMD (&lcd_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//        LCD1602_FLOAT (&lcd_1,RES_OPEN[i]);
//        LCD1602_STR (&lcd_1,",");
//        LCD1602_FLOAT (&lcd_1,RES_CLOSED[i]);
//        _delay_ms(2000);
        FLEX_INIT (flexs+i,RES_CLOSED[i],RES_OPEN[i],port_pins_adc[i]); 
    }
    GLOVE_INIT (&glove,flexs,4);
    EEPROM_INIT ();    
    _delay_ms (50);
    eepromWriter ();
    sei();
    LCD1602_CMD (&lcd_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
    while(1)
    {
        GLOVE_SAMPLE (&glove);
        GLOVE_GET_STATES (&glove,states,4);
        
        updateLCD(&lcd_1,states,prev_states,4);
        _delay_ms (20);
    }
    
    return EXIT_SUCCESS;
}