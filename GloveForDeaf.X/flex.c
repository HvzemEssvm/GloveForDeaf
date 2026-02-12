#include "flex.h"

void FLEX_INIT(flex_t* FLEX,float RES_CLOSED,float RES_OPEN,uint8_t PORT_PIN_ADC)
{
    ADC_INIT_POLL(VREF_AVCC,PORT_PIN_ADC,ADC_PS_MIN,FALSE);
    FLEX->RES_CLOSED = RES_CLOSED;
    FLEX->RES_OPEN = RES_OPEN;
    FLEX->PORT_PIN_ADC = PORT_PIN_ADC;
    
}

void FLEX_SAMPLE(flex_t* FLEX)
{
    ADC_CHANGE_CHANNEL (FLEX->PORT_PIN_ADC);
    ADC_MANUAL_SAMPLE ();
    ADC_READ ();
    ADC_MANUAL_SAMPLE ();
    float val = (((float)ADC_READ())/1023.0f)*5;
    val = 47000.0f / (5.0f/val - 1.0f);
//    if(val<=FLEX->RES_OPEN)
//    {
//        FLEX->STATE = FLEX_STATE_OPEN;
//    }else if(val<=FLEX->RES_CLOSED)
//    {
//        FLEX->STATE = FLEX_STATE_HALF;
//    }
//    else
//    {
//        FLEX->STATE = FLEX_STATE_CLOSED;
//    }
    float range = FLEX->RES_CLOSED - FLEX->RES_OPEN;
    float open_range = FLEX->RES_OPEN + (range*0.4);
    float close_range = FLEX->RES_CLOSED - (range*0.4);
    if(val<=open_range)
    {
        FLEX->STATE = FLEX_STATE_OPEN;
    }
    else if(val>=close_range)
    {
        FLEX->STATE = FLEX_STATE_CLOSED;
    }
    else
    {
        FLEX->STATE = FLEX_STATE_HALF;
    }
}

int FLEX_GET_STATE(const flex_t* FLEX)
{
    return FLEX->STATE;
}