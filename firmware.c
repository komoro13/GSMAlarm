#include <xc.h>
#include "config.h"
#include "LCD.h"
#include "keypad_4x4.h"
#include "SIM900A.h"
#include <stdlib.h>
#include <string.h>
//---------------------------String functions--------------------------

char *concatenate(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcpy(result, s2);
    return result;
}

//---------------------------End of string functions-------------------

//---------------------------LED functions-----------------------------
void BlinkMainLED()
{
    RB1=1;
    __delay_ms(200);
    RB1=0;
    __delay_ms(200);
    RB1=1;
    __delay_ms(200);
    RB1=0;
    __delay_ms(200);
    RB1=1;
    __delay_ms(200);
    RB1=0;    
}
void blink_sensor_led(int sensor)
{    
    if (sensor == 1)
    {    
        RB3=1;
        __delay_ms(1000);
        RB3=0;
        return;
    }
    RB3=1;
    __delay_ms(1000);
    RB3=0;
    
}
void sensor_leds_off()
{
    RB3=0;
    RB4=0;
}
void boot_led_blink()
{
    RB3 = 1;
    RB4 = 1;
    __delay_ms(1000);
    RB3 = 0;
    RB4 = 0;
}
//---------------------------End of LED functions---------------------

//-----------------------Call functions-------------------------------
void MakeCall()
{   
    char *AT_COMMAND = concatenate("ATD", read_saved_phone());
    AT_COMMAND = concatenate(AT_COMMAND, ";\r\n");
   _SIM900A_print(AT_COMMAND);
   BlinkMainLED();
}
//-----------------------End of call functions------------------------

//---------------------Running functions------------------------------


void start()
{
    while(1) 
        if (RD1==1)       
        {
            blink_sensor_led(1);
            MakeCall();
           
        }
        else if (RD3==1)
        {
            MakeCall();
            blink_sensor_led(2);
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
int save_phone(char *phone)
{
    return 0;
}
char *read_saved_phone()
{
    char *phone;
    //OK1
    return phone;
}
void settings()
{
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
        LCD_display(concatenate("Saved phone number\n", saved_number));
        
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
   //OK
}


//----------------------End of initializing functions----------------------