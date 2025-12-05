#include "glove.h"

void GLOVE_INIT(glove_t* GLOVE, flex_t FLEX[],uint8_t SIZE)
{
    GLOVE->SIZE = SIZE;
    GLOVE->FLEX = FLEX;
}

void GLOVE_SAMPLE(glove_t* GLOVE)
{
    for(int  i = 0;i <GLOVE->SIZE;i++)
    {
        FLEX_SAMPLE ((GLOVE->FLEX)+i);
    }
}

/*
 * @returns FLEX_STATE value in the given array
 */
void GLOVE_GET_STATES(const glove_t* GLOVE, uint8_t STATES_ARR[], uint8_t STATES_ARR_SIZE)
{
    if(STATES_ARR_SIZE<=GLOVE->SIZE)
    {
        for(int  i = 0;i <STATES_ARR_SIZE;i++)
        {
            STATES_ARR[i]=FLEX_GET_STATE ((GLOVE->FLEX)+i);
        }
    }
}
