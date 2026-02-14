#include "gloveMapper.h"

unsigned int getIdx(int combination[5])
{
    unsigned int idx = 0;
    int weight = 1;
    for (int i = 4; i >= 0; i--) {
        int base3_digit = combination[i] - 1;
        idx += base3_digit * weight;
        weight *= 3;
    }
    return idx;
}

void addAddress (gloveMapper_t* mapper,int combination[5],uint16_t address)
{
    mapper->sentenceAddress[getIdx(combination)] = address;
}

uint16_t getAddress(const gloveMapper_t* mapper,int combination[5])
{
    int address = 
}

void GLOVEMAPPER_INIT(gloveMapper_t* mapper)
{
    mapper->sentenceAddress = {-1};
    mapper->getAddress = getAddress;
    mapper->addAddress = addAddress;
}
