#include <xc.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "LCD.h"
#include "firmware.h"
#include "keypad_4x4.h"
#include "SIM900A.h"
#include "EEPROM.h"
#include "helpers.h"
#include "LED.h"


//---------------------Running functions------------------------------


void start()
{
    while(1) 
        if (RD1==1)       
        {
            BlinkLED(1,1);
            MakeCall();
           
        }
        else if (RD3==1)
        {
            MakeCall();
            BlinkLED(1,2);
        }
        else 
        {
            sensor_leds_off();
        }
    
}
void sleep()
{
    while(RD5!=1);
    return;
}

//-----------------End of running functions-------------------------------
//---------------------Settings functions-----------------------------


void settings()
{
    char message[32] = "";
    LCD_display("Settings\nSave phone number(1) Read saved number(2)");
    if (read_keypad(RAW_MODE) == 1)
    {
        char *phone;
        LCD_display("Enter your phone");
        phone = read_keypad(CANONICAL_MODE);
        if (save_phone(phone) == 0)
            LCD_display("Phone saved successfully");
        else 
            LCD_display("Error saving phone");
        return;
    }
    char *saved_number;
    if (read_saved_phone() == "err")
    {
        LCD_display("Error reading number");
        return;
    }
    if (read_saved_phone() == "")
    {
        LCD_display("No number saved");
        return;
    }
    saved_number = read_saved_phone();
    
    
    
    if (read_keypad(RAW_MODE) == 2)
    {
        
        u8_concat("Saved phone number\n", (unsigned const char*)saved_number,message, sizeof(message));
        LCD_display(message);
    }
}
//---------------------End of settings functions----------------------

//----------------------Initializing functions-----------------------------
void init_trisio()
{
    //setting the input/output bits
    TRISD = 0b00001010;
    TRISB = 0b00000000;
}

void main_menu()
{
    LCD_display("GSM ALARM\n Start (1) Sleep(2) Settings(3)"); 
    if (read_keypad(RAW_MODE) == 1)
        start();
    else if(read_keypad(RAW_MODE) == 2)
        sleep();
    else if(read_keypad(RAW_MODE) == 3)
        settings();
    //if user presses wrong key do nothing
}

void boot()
{
   initialize_SIM900A();
   init_trisio();
   boot_led_blink();
   
}


//----------------------End of initializing functions----------------------

//OK