#include "TWI.h"

void TWI_Init(void)
{
    
TWBR = ((F_CPU / SCL_CLOCK) - 16) / 2;
TWSR = 0x00; 
TWCR = (1 << TWEN); 

}

void TWI_Start(void)
{
TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
while (!(TWCR & (1 << TWINT))); // Wait for start to be transmitted
}

void TWI_Stop(void)
{
TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWI_WriteAddress(uint8_t address)
{
TWDR = address;
TWCR = (1 << TWINT) | (1 << TWEN);
while (!(TWCR & (1 << TWINT))); // Wait for address transmission
}


void TWI_Write(uint8_t data)
{
TWDR = data;
TWCR = (1 << TWINT) | (1 << TWEN);
while (!(TWCR & (1 << TWINT))); // Wait for data transmission
}


uint8_t TWI_ReadACK(void)
{
TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA); // Send ACK
while (!(TWCR & (1 << TWINT))); // Wait for reception
return TWDR;
}


uint8_t TWI_ReadNACK(void)
{
TWCR = (1 << TWINT) | (1 << TWEN); // No ACK
while (!(TWCR & (1 << TWINT)));
return TWDR;
}