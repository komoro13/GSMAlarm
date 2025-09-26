#include <xc.h>
#include "SIM900A.h"
#include "UART.h"
#include "config.h"

void initialize_SIM900A(void)
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
void _SIM900A_putch(char bt)
{
    while(!TXIF);
    TXREG=bt;
}
char _SIM900A_getch()
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

void SIM900A_send_string(char* st_pt)
{
    while(*st_pt)
        _SIM900A_putch(*st_pt++);
}

void _SIM900A_print(unsigned const char *ptr)
{
    while (*ptr != 0)
    {
        _SIM900A_putch(*ptr++);
    }
}
//OK