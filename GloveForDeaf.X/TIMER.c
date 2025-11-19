#include "TIMER.h"

void TIMER0_MODE(uint8_t MODE)
{
    TIMER0_OC_PIN(OC0_MODE_DISABLE);
    switch (MODE)
    {
        case TIMER_NORMAL:
            TCCR0 &= ~(1<<WGM00);
            TCCR0 &= ~(1<<WGM01);
            break;
            
        case TIMER_PWM:
            TCCR0 |= (1<<WGM00);
            TCCR0 &= ~(1<<WGM01);
            break;
            
        case TIMER_CTC:
            TCCR0 &= ~(1<<WGM00);
            TCCR0 |= (1<<WGM01);
            break;
            
        case TIMER_FPWM:
            TCCR0 |= (1<<WGM00);
            TCCR0 |= (1<<WGM01);
            break;
    }
}

/**
 * 
 * @param TIMER0_PS You could use it as a counter by setting TIMER0_PS to either TIMER0_PS_FALLING or TIMER0_PS_RISING
 *                  and connect the src on T0 (D4) PIN 
 */
void TIMER0_CLK(uint8_t TIMER0_PS)
{
    TCCR0 &= 0xF8;
    TCCR0 |= TIMER0_PS;
}

void TIMER0_OC_PIN(uint8_t OC0_MODE)
{
    switch(OC0_MODE)
    {
        case OC0_MODE_DISABLE:
            TCCR0 &= ~((1<<COM01)|(1<<COM00));
            break;
         
        case OC0_MODE_TOGGLE:
            if((TCCR0&(1<<WGM01))!=0&&(TCCR0&(1<<WGM00))==0)
            {
                SET_PIN_DIR (OC0,OUTPUT);
                TCCR0 &= ~(1<<COM01);
                TCCR0 |= (1<<COM00);
            }
            break;
            
        case OC0_MODE_RESET:
            if((TCCR0&((1<<WGM01)|(1<<WGM00)))==0)
                return;
            SET_PIN_DIR (OC0,OUTPUT);
            TCCR0 |= (1<<COM01);
            TCCR0 &= ~(1<<COM00);
            break;
            
        case OC0_MODE_SET:
            if((TCCR0&((1<<WGM01)|(1<<WGM00)))==0)
                return;
            SET_PIN_DIR (OC0,OUTPUT);
            TCCR0 |= (1<<COM01);
            TCCR0 |= (1<<COM00);
            break;    
    }
}

void TIMER0_SET_OCR(uint8_t VAL)
{
    OCR0 = VAL;
}

void TIMER0_OVERFLOW_INT_ENABLE()
{
    TIMSK |= 1<<TOIE0;
}

void TIMER0_OVERFLOW_INT_DISABLE()
{
    TIMSK &= ~(1<<TOIE0);
}

void TIMER0_COMPARE_MATCH_INT_ENABLE()
{
    TIMSK |= 1<<OCIE0;
}

void TIMER0_COMPARE_MATCH_INT_DISABLE()
{
    TIMSK &= ~(1<<OCIE0);
}

/**
 * ONLY USE IT IF TIMER0 OVERFLOW INTERRUPT IS DISABLED TO CLEAR THE FLAG MANUALLY
 */
void TIMER0_CLEAR_OVERFLOW_FLAG()
{
    TIFR |= 1<<TOV0;
}

/**
 * ONLY USE IT IF TIMER0 COMPARE MATCH INTERRUPT IS DISABLED TO CLEAR THE FLAG MANUALLY
 */
void TIMER0_CLEAR_COMPARE_MATCH_FLAG()
{
    TIFR |= 1<<OCF0;
}