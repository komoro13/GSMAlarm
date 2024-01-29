

#include <xc.h>
#include "config.h"
#include "UART.h"
#include <stdint.h>


void intialize_SIM900(void)
{
    TRISC6 = 0;
    TRISC7 = 1;
    SPBRG =((_XTAL_FREQ/16)/BaudRate)-1;
    BRGH = 1;
    SYNC = 0;
    SPEN = 1;
    TXEN=1;
    CREN=1;
    TX9=0;
    RX9=0;
       
}
void _SIM900_putch(char bt)
{
    while(!TXIF);
    TXREG=bt;
}
char _SIM900_getch()
{
    if(OERR)
    {
        CREN=0;
        CREN=1;
    }
    while(!RCIF)
    {
        return RCREG;
    }
}

void SIM900_send_string(char* st_pt)
{
    while(*st_pt)
        _SIM900_putch(*st_pt++);
}

void _SIM900_print(unsigned const char *ptr)
{
    while (*ptr != 0)
    {
        _SIM900_putch(*ptr++);
    }
}

int a;

void BlinkLED()
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
void MakeCall()
{   
   _SIM900_print("ATD6986951309;\r\n");
   BlinkLED();
}

int main()
{
    
    TRISD = 0b00001010;
    TRISB = 0b00000000;
    {
    RB3 = 1;
    RB4 = 1;
    __delay_ms(1000);
    RB3 = 0;
    RB4 = 0;
    intialize_SIM900();
    while(1) 
        if (RD1==1)       
        {
            MakeCall();
            RB3=1;
            __delay_ms(1000);
            RB3=0;
        }
        else if (RD3==1)
        {
            MakeCall();
            RB4=1;
            __delay_ms(1000);
            RB4=0;
        }
        else 
        {
            RB3=0;
            RB4=0;
        }
 
    }
    return 0;
} 