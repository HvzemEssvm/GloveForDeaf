#include "eeprom.h"
//static void EEPROM_Find_empty_slot();
static void EEPROM_LoadLastAddress();
static void EEPROM_SaveLastAddress();
static uint8_t EEPROM_PrepareAddressWrite(uint16_t MemoryAddress);

static uint16_t MemoryAddress = 0x00; 

//static void EEPROM_Find_empty_slot(){
//    uint16_t addr = 0;
//    while(addr<2047){
//        uint8_t val = EEPROM_ReadByte(addr);
//        if(val == 0 && EEPROM_ReadByte(addr+1) == 0){
//            if(addr == 0){ //Memory is totally full starting from beginning
//                MemoryAddress = 0;
//            }
//            else{
//                MemoryAddress = addr + 1;
//            }
//            return;
//        }
//        addr ++;
//    }
//    MemoryAddress = 2047;
//}

static void EEPROM_SaveLastAddress(){
    uint8_t address = MemoryAddress;
    uint8_t block_bits_address = (MemoryAddress >> 8) & 0x07; //memory address/256
    EEPROM_WriteByte(2046,address & 0xFF);
    EEPROM_WriteByte(2047,block_bits_address & 0xFF);
}

static void EEPROM_LoadLastAddress(){
    uint8_t address = EEPROM_ReadByte(2046);
    uint8_t block_bits_address = EEPROM_ReadByte(2047);
    
    MemoryAddress = (block_bits_address<<8) | address;
    
    if (MemoryAddress >= 2046) {
        MemoryAddress = 0;
    }
}


static uint8_t EEPROM_PrepareAddressWrite(uint16_t MemoryAddress){
    uint8_t block_bits = (MemoryAddress >> 8) & 0x07;
    uint8_t device_address = EEPROM_BASE_DEV_ADDR | (block_bits<<1);
    TWI_Start();
    TWI_WriteAddress(device_address);
    TWI_Write((uint8_t) MemoryAddress);
    return device_address;
}

//-------------------------------------------------------------------------------

void EEPROM_ClearALL(){
    uint8_t clearBuffer[16];
    
    for(uint8_t i = 0; i < 16; i++) {
        clearBuffer[i] = 0x00; 
    }
    // Loop through the memory in 16-byte chunks (Pages)
    // We start at 0 and jump by 16 (0, 16, 32... 2032)
    // The loop stops when we reach 2048 (Total Size)
    for (uint16_t addr = 0; addr < 2048; addr += 16) {
        EEPROM_WritePage(addr, clearBuffer, 16);
    }
}

void EEPROM_INIT(){
    TWI_Init();
//    EEPROM_Find_empty_slot();
    EEPROM_LoadLastAddress();
}

uint16_t EEPROM_APPEND(const uint8_t * data){
   return EEPROM_APPEND_CUSTOM_MEM(data,MemoryAddress);
}

uint16_t EEPROM_APPEND_CUSTOM_MEM(const uint8_t * data,uint16_t StartAddress){
    
    MemoryAddress = StartAddress;
    uint16_t len = 0;
    while(data[len] != 0) {
        len++;
    }
    uint16_t totalBytes = len + 1; // Include null terminator
    uint16_t bytesWritten = 0;
    uint8_t position_In_Page,empty_in_page,length,remaining;
   
    while(bytesWritten < totalBytes){
        position_In_Page = MemoryAddress % 16;
        empty_in_page = 16 - position_In_Page;
        remaining = totalBytes - bytesWritten;
        if(remaining<=empty_in_page){
            length = remaining;
        }
        else{
            length = empty_in_page;
            }
        EEPROM_WritePage(MemoryAddress,data+bytesWritten,length); 
        MemoryAddress += length;
        bytesWritten += length;
        
    }
//    EEPROM_SaveLastAddress();
    return MemoryAddress;
    
}

void EEPROM_ReadString(uint16_t startAddr, uint8_t * buffer,unsigned int bufferSize) {
    
    uint8_t dev_addr_read = (EEPROM_PrepareAddressWrite(startAddr)) | 0x01;
    TWI_Start();
    TWI_WriteAddress(dev_addr_read);
    
    uint8_t i = 0;
    uint8_t data;
    while(1) {
        data = TWI_ReadACK();
        buffer[i] = data;
        
        if (data == 0 || i>=bufferSize){
            TWI_ReadNACK();
            break;
        }
        i++;  
    }
    TWI_Stop();
}

void EEPROM_Save_Address_Of_Sent_To_Block1(uint8_t index, uint16_t sentence_address){
    uint16_t loc = EEPROM_BLOCK1_START + (2*index);
    
    EEPROM_WriteByte(loc, sentence_address &0xFF);
    EEPROM_WriteByte(loc+1, (sentence_address >> 8) & 0xFF);
}

uint16_t EEPROM_Get_Address_From_Block1(uint8_t index){
    uint16_t loc = EEPROM_BLOCK1_START + (index * 2);
    
    uint8_t low = EEPROM_ReadByte(loc);
    uint8_t high = EEPROM_ReadByte(loc + 1);
    
    return (high << 8) | low;
}
//-------------------------------------------------------------------------------

void EEPROM_WriteByte(uint16_t MemoryAddress, const uint8_t Data){
    EEPROM_PrepareAddressWrite(MemoryAddress);
    TWI_Write(Data); //Transmit byte data (master send data).
    TWI_Stop();      
    _delay_ms(10);
}

void EEPROM_WritePage(uint16_t MemoryAddress, const uint8_t* Data,uint8_t length){
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


