#include "eeprom.h"

void EEPROM_Init(){
    TWI_Init();
}

static uint8_t EEPROM_PrepareAddressWrite(uint16_t MemoryAddress){
    uint8_t page_bits = (MemoryAddress >> 8) & 0x07;
    uint8_t device_address = EEPROM_BASE_ADDR | (page_bits<<1);
    TWI_Start();
    TWI_WriteAddress(device_address);
    TWI_Write((uint8_t) MemoryAddress);
    return device_address;
}

void EEPROM_WriteByte(uint16_t MemoryAddress, uint8_t Data){
    EEPROM_PrepareAddressWrite(MemoryAddress);
    TWI_Write(Data); //Transmit byte data (master send data).
    TWI_Stop();      
    _delay_ms(10);
}

void EEPROM_WritePage(uint16_t MemoryAddress, uint8_t* Data,uint8_t length){
    EEPROM_PrepareAddressWrite(MemoryAddress);
    for(uint8_t i=0; i<length;i++){
        TWI_Write(Data[i]); //Transmit byte data (master send data).
    }
    TWI_Stop();
    
    _delay_ms(10);
}

uint8_t EEPROM_ReadByte(uint16_t MemoryAddress){
    
    uint8_t dev_addr_read = (EEPROM_PrepareAddressWrite(MemoryAddress)) | 0x01;  
        
    TWI_Start();
    TWI_WriteAddress(dev_addr_read);
    uint8_t data = TWI_ReadNACK();
    TWI_Stop();
    return data;
}

void EEPROM_ReadSequential(uint16_t MemoryAddress, uint8_t * Data,uint8_t length){
    uint8_t dev_addr_read = (EEPROM_PrepareAddressWrite(MemoryAddress)) | 0x01;    
    TWI_Start();
    TWI_WriteAddress(dev_addr_read);
    for(uint8_t i = 0; i<length;i++){
        if (i == length - 1){
            Data[i] = TWI_ReadNACK();}
        else{
            Data[i] = TWI_ReadACK();
        }
    }
    TWI_Stop();
}