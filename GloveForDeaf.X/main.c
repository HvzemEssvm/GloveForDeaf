/* 
 * File:   main.c
 * Author: Lenovo
 *
 * Created on August 8, 2025, 8:45 AM
 * 
 * * VIP NOTES:
 * 1) Better to make typedef enum for state_t and dir_t
 * 2) lowercase_t convention is to indicate that this is a data type
 * 3) While changing a whole register with known values then assign to the needed value but do not use loops
 * 4) make it a convention to express values as hex --> 0x00 to 0xff
 * 
 * 5) when a certain pin to be output and accessed it by PINX will result to checking the current value assigned to it
 * 6) when a certain pin to be input, then you could control the Pull-up feature by manipulating with PORTX:
 *      6.1) Enable pull-up by 1 to the corresponding pin
 *      6.2) Disable pull-up by 0 to the corresponding pin
 * 
 * 7) all methods here "DIO.h" are considered as building MCAL
 *      7.1) MCAL:
 *                  Microcontroller Abstraction Layer (MCAL) is the layer where the manipulation 
 *                  and accessing the registers of the MCU, also it is changed when we change 
 *                  the MCU with other architecture.
 *                  It includes (DIO - ADC - Timers - Interrupts ..)
 *                                                          |
 *                                                          |
 *      7.2) HAL:
 *                  Hardware Abstraction Layer (HAL) is a broader layer which includes device drivers 
 *                  for all other hardware which is not in the MCU.
 *                  It includes (LED - BUZZER - Sensors ..)
 *                                                          |
 *                                                          |
 *      7.3) Application:       
 *                  In this layer we use HAL methods to do a specific application.
 *                  It includes (main.c)
 * 
 * 8) generally use switch-case instead of if-else
 * 9) convention when making methods in HAL layer like "xxx.h" to make the methods xxx_function
 * 10) delays should be included in the main file after each init/setup of pins
 * 11) better to use const ptr with structs as arguments to read-only method, not to copy the whole struct in the stack
 *     and take more RAM usage also to be const to ensure no modifying is occurred on the data.
 * 12) MCAL libs are named UPPER_CASE conventionally, while HAL libs are named lower_case conventionally
 */
#define F_CPU 16000000UL
//#undef __OPTIMIZE__ //SUPERRRRRRRRRRRRRRRRRR IMPORTANTTTTTTTTTTTTTTT!!!!!
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

#include "TIMER.h"
#include "ADC.h"
#include "lcd1602.h"
#include "eeprom.h"
#include "DIO.h"

#define LCD_D0 A0
#define LCD_D1 A1
#define LCD_D2 A2
#define LCD_D3 A3
#define LCD_D4 A4
#define LCD_D5 A5
#define LCD_D6 A6
#define LCD_D7 A7
#define LCD_RS B1
#define LCD_E B0

lcd1602_t LCD_1;
int main(){
    LCD1602_INIT(&LCD_1,LCD_D7,LCD_D6,LCD_D5,LCD_D4,LCD_D3,LCD_D2,LCD_D1,LCD_D0,LCD_RS,LCD_E,TRUE,TRUE,FALSE);
    
    EEPROM_Init();
//    EEPROM_ClearALL(); //run it ONLY ONCE before saving anything
//    
//    uint16_t addr_hello = EEPROM_APPEND((uint8_t)"Hello");
//    uint16_t addr_help = EEPROM_APPEND((uint8_t)"I need help");
//    uint16_t addr_bathroom = EEPROM_APPEND((uint8_t)"Bathroom");
//    uint16_t addr_yes = EEPROM_APPEND((uint8_t)"Yes");
//    uint16_t addr_no = EEPROM_APPEND((uint8_t)"No");
      uint16_t addr_howru = EEPROM_APPEND((uint8_t)"How are you?");
      uint16_t addr_fine = EEPROM_APPEND((uint8_t)"I'm fine.");
    
//    EEPROM_Save_Address_Of_Sent_To_Block1(0,addr_hello);
//    EEPROM_Save_Address_Of_Sent_To_Block1(1,addr_help);
//    EEPROM_Save_Address_Of_Sent_To_Block1(2,addr_bathroom);
//    EEPROM_Save_Address_Of_Sent_To_Block1(3,addr_yes);
//    EEPROM_Save_Address_Of_Sent_To_Block1(4,addr_no);
      EEPROM_Save_Address_Of_Sent_To_Block1(5,addr_howru);
      EEPROM_Save_Address_Of_Sent_To_Block1(6,addr_fine);
    
    uint8_t buffer[50];
    uint16_t target_addr;
       
//     
    
        
       
       target_addr = EEPROM_Get_Address_From_Block1(0);
       EEPROM_ReadString(target_addr,buffer);
       LCD1602_STR(&LCD_1,buffer);
       _delay_ms(100); // Wait 2 seconds
//       
      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
      
      //LCD1602_CMD(&LCD_1,CMD_8BIT_2LINE);
      target_addr = EEPROM_Get_Address_From_Block1(1);
      EEPROM_ReadString(target_addr,buffer);
      LCD1602_STR(&LCD_1,buffer);
      _delay_ms(100); // Wait 2 seconds
      
      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//      
      target_addr = EEPROM_Get_Address_From_Block1(2);
      EEPROM_ReadString(target_addr,buffer);
      LCD1602_STR(&LCD_1,buffer);
       _delay_ms(100); // Wait 2 seconds
//       
      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//      
       target_addr = EEPROM_Get_Address_From_Block1(3);
      EEPROM_ReadString(target_addr,buffer);
      LCD1602_STR(&LCD_1,buffer);
//     
       _delay_ms(100); // Wait 2 seconds
//       
      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//      
       target_addr = EEPROM_Get_Address_From_Block1(4);
      EEPROM_ReadString(target_addr,buffer);
      LCD1602_STR(&LCD_1,buffer);
      
      _delay_ms(100); // Wait 2 seconds
//       
      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
      
      //LCD1602_CMD(&LCD_1,CMD_8BIT_2LINE);
      target_addr = EEPROM_Get_Address_From_Block1(5);
      EEPROM_ReadString(target_addr,buffer);
      LCD1602_STR(&LCD_1,buffer);
      
      _delay_ms(100); // Wait 2 seconds
//       
      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
      
      //LCD1602_CMD(&LCD_1,CMD_8BIT_2LINE);
      target_addr = EEPROM_Get_Address_From_Block1(6);
      EEPROM_ReadString(target_addr,buffer);
      LCD1602_STR(&LCD_1,buffer);
      
//      
      
      
      
      
  
    

    
//    EEPROM_WriteByte(0x00,'A');
//    uint8_t words[] = "Hello Habiba";
//    EEPROM_WritePage(0x10,words,12);
//    char sentence[20];
//    uint8_t byte = EEPROM_ReadByte(0x00);
//    EEPROM_ReadSequential(0x10,sentence,13);
//    uint32_t byte2 = (uint32_t)EEPROM_ReadByte(500);   
//    _delay_ms (10);
    
//    LCD1602_CHAR(&LCD_1,byte);
//    LCD1602_CMD(&LCD_1,CMD_SHIFT_CURSOR_RIGHT);
//    LCD1602_STR(&LCD_1,sentence);
   
    
    
    return EXIT_SUCCESS;
}
