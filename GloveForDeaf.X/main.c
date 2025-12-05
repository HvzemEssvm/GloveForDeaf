//#define F_CPU 16000000UL
//#undef __OPTIMIZE__ //SUPERRRRRRRRRRRRRRRRRR IMPORTANTTTTTTTTTTTTTTT!!!!!
//#include <stdlib.h>
//#include <stdio.h>
//#include <util/delay.h>
//
//#include "TIMER.h"
//#include "ADC.h"
//#include "lcd1602.h"
//#include "eeprom.h"
//#include "DIO.h"
//
//#define LCD_D0 A0
//#define LCD_D1 A1
//#define LCD_D2 A2
//#define LCD_D3 A3
//#define LCD_D4 A4
//#define LCD_D5 A5
//#define LCD_D6 A6
//#define LCD_D7 A7
//#define LCD_RS B1
//#define LCD_E B0
//
//lcd1602_t LCD_1;
//int main(){
//    LCD1602_INIT(&LCD_1,LCD_D7,LCD_D6,LCD_D5,LCD_D4,LCD_D3,LCD_D2,LCD_D1,LCD_D0,LCD_RS,LCD_E,TRUE,TRUE,FALSE);
//    
//    EEPROM_INIT();
////    EEPROM_ClearALL(); //run it ONLY ONCE before saving anything
////    
////    uint16_t addr_hello = EEPROM_APPEND((uint8_t)"Hello");
////    uint16_t addr_help = EEPROM_APPEND((uint8_t)"I need help");
////    uint16_t addr_bathroom = EEPROM_APPEND((uint8_t)"Bathroom");
////    uint16_t addr_yes = EEPROM_APPEND((uint8_t)"Yes");
////    uint16_t addr_no = EEPROM_APPEND((uint8_t)"No");
//      uint16_t addr_howru = EEPROM_APPEND((uint8_t)"How are you?");
//      uint16_t addr_fine = EEPROM_APPEND((uint8_t)"I'm fine.");
//    
////    EEPROM_Save_Address_Of_Sent_To_Block1(0,addr_hello);
////    EEPROM_Save_Address_Of_Sent_To_Block1(1,addr_help);
////    EEPROM_Save_Address_Of_Sent_To_Block1(2,addr_bathroom);
////    EEPROM_Save_Address_Of_Sent_To_Block1(3,addr_yes);
////    EEPROM_Save_Address_Of_Sent_To_Block1(4,addr_no);
//      EEPROM_Save_Address_Of_Sent_To_Block1(5,addr_howru);
//      EEPROM_Save_Address_Of_Sent_To_Block1(6,addr_fine);
//    
//    uint8_t buffer[50];
//    uint16_t target_addr;
//       
////     
//    
//        
//       
//       target_addr = EEPROM_Get_Address_From_Block1(0);
//       EEPROM_ReadString(target_addr,buffer);
//       LCD1602_STR(&LCD_1,buffer);
//       _delay_ms(100); // Wait 2 seconds
////       
//      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//      
//      //LCD1602_CMD(&LCD_1,CMD_8BIT_2LINE);
//      target_addr = EEPROM_Get_Address_From_Block1(1);
//      EEPROM_ReadString(target_addr,buffer);
//      LCD1602_STR(&LCD_1,buffer);
//      _delay_ms(100); // Wait 2 seconds
//      
//      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
////      
//      target_addr = EEPROM_Get_Address_From_Block1(2);
//      EEPROM_ReadString(target_addr,buffer);
//      LCD1602_STR(&LCD_1,buffer);
//       _delay_ms(100); // Wait 2 seconds
////       
//      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
////      
//       target_addr = EEPROM_Get_Address_From_Block1(3);
//      EEPROM_ReadString(target_addr,buffer);
//      LCD1602_STR(&LCD_1,buffer);
////     
//       _delay_ms(100); // Wait 2 seconds
////       
//      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
////      
//       target_addr = EEPROM_Get_Address_From_Block1(4);
//      EEPROM_ReadString(target_addr,buffer);
//      LCD1602_STR(&LCD_1,buffer);
//      
//      _delay_ms(100); // Wait 2 seconds
////       
//      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//      
//      //LCD1602_CMD(&LCD_1,CMD_8BIT_2LINE);
//      target_addr = EEPROM_Get_Address_From_Block1(5);
//      EEPROM_ReadString(target_addr,buffer);
//      LCD1602_STR(&LCD_1,buffer);
//      
//      _delay_ms(100); // Wait 2 seconds
////       
//      LCD1602_CMD(&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
//      
//      //LCD1602_CMD(&LCD_1,CMD_8BIT_2LINE);
//      target_addr = EEPROM_Get_Address_From_Block1(6);
//      EEPROM_ReadString(target_addr,buffer);
//      LCD1602_STR(&LCD_1,buffer);
//      
////      
//      
//      
//      
//      
//  
//    
//
//    
////    EEPROM_WriteByte(0x00,'A');
////    uint8_t words[] = "Hello Habiba";
////    EEPROM_WritePage(0x10,words,12);
////    char sentence[20];
////    uint8_t byte = EEPROM_ReadByte(0x00);
////    EEPROM_ReadSequential(0x10,sentence,13);
////    uint32_t byte2 = (uint32_t)EEPROM_ReadByte(500);   
////    _delay_ms (10);
//    
////    LCD1602_CHAR(&LCD_1,byte);
////    LCD1602_CMD(&LCD_1,CMD_SHIFT_CURSOR_RIGHT);
////    LCD1602_STR(&LCD_1,sentence);
//   
//    
//    
//    return EXIT_SUCCESS;
//}
