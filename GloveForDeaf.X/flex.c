#include "flex.h"

uint16_t getFilteredADC(uint8_t ch)
{
    ADC_CHANGE_CHANNEL(ch);
    ADC_MANUAL_SAMPLE(); // throw first
    uint32_t sum = 0;
    const int SAMPLES = 16; // 8 to be more faster
    for(int i=0;i<SAMPLES;i++){
        ADC_MANUAL_SAMPLE();
        sum += ADC_READ();
    }
    return (uint16_t)(sum / SAMPLES);
}


void FLEX_INIT(flex_t* FLEX, uint16_t RES_CLOSED, uint16_t RES_OPEN, uint8_t PORT_PIN_ADC)
{
    ADC_INIT_POLL(VREF_AVCC, PORT_PIN_ADC, ADC_PS_128, FALSE); // prescaler 128
    FLEX->RES_CLOSED = RES_CLOSED;
    FLEX->RES_OPEN = RES_OPEN;
    FLEX->PORT_PIN_ADC = PORT_PIN_ADC;
    FLEX->STATE = FLEX_STATE_HALF;
}

void FLEX_SAMPLE(flex_t* FLEX)
{

    uint16_t val = getFilteredADC(FLEX->PORT_PIN_ADC);
    uint16_t range = FLEX->RES_CLOSED - FLEX->RES_OPEN;
    uint16_t margin = range/6;
    uint16_t open_range = FLEX->RES_OPEN + margin;
    uint16_t close_range = FLEX->RES_CLOSED - margin;
    
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