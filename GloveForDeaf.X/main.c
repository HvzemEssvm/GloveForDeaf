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
#undef __OPTIMIZE__ //SUPERRRRRRRRRRRRRRRRRR IMPORTANTTTTTTTTTTTTTTT!!!!!
#include <stdlib.h>

#include "TIMER.h"
#include "ADC.h"
#include "lcd1602.h"
#include "keypad_3x3.h"

#define SERVO_MIN_OCR 5
#define SERVO_MAX_OCR 35

volatile uint8_t val = SERVO_MIN_OCR;

//void change_duty_cycle()
//{
//    val = (ADC_READ()*(SERVO_MAX_OCR-SERVO_MIN_OCR)/1023)+SERVO_MIN_OCR;
//    TIMER0_SET_OCR (val);
//}

int main()
{
    // configuring pwm mode on TIMER0 with PB3
    TIMER0_MODE (TIMER_FPWM);
    TIMER0_OC_PIN (OC0_MODE_PWM_NORMAL);
    
//    // configuring ADC0
//    ADC_INIT (VREF_AVCC,ADC0,change_duty_cycle,ADC_PS_MIN,FALSE);
    
    // configuring keypad
    keypad_3x3_t KEY_1;
    KEYPAD_3X3_INIT (&KEY_1,D2,D3,D7,A1,A2,A3,FALSE);
    
    // configuring LCD
    lcd1602_t LCD_1;
    LCD1602_INIT (&LCD_1,A7,A6,A5,A4,B1,B2,FALSE,FALSE,FALSE);
    
    // starting timer
    sei();
    TIMER0_CLK (TIMER0_PS_1024);
    TIMER0_SET_OCR(val);
    
    _delay_ms(50);
    while(1)
    {
        int temp = KEYPAD_3X3_READ(&KEY_1);
        _delay_ms(100);
        if(temp == 6 && val < SERVO_MAX_OCR)
            val++;
        if (temp ==4 && val > SERVO_MIN_OCR)
            val--;
        TIMER0_SET_OCR (val);
        LCD1602_CMD (&LCD_1,CMD_CLEAR_DISPLAY_RETURN_HOME);
        LCD1602_STR (&LCD_1,"ANGLE: ");
        LCD1602_INT (&LCD_1,(val-SERVO_MIN_OCR)*180/(SERVO_MAX_OCR-SERVO_MIN_OCR));
//        LCD1602_INT (&LCD_1,KEYPAD_3X3_READ(&KEY_1));
//        ADC_MANUAL_SAMPLE ();
        _delay_ms (15);
    }
    
    return EXIT_SUCCESS;
}
