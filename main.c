#include <xc.h>
#include "config.h"
#include "UART.h"
#include "firmware.h"
#include <stdint.h>

int main()
{
   boot();
   //OK
   main_menu();
   return 0; 
} 