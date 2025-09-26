void BlinkLED(int mode,int sensor)
{
    if (mode == 0)
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
    if (mode == 1)
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
