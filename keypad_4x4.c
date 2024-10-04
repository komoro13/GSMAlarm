#include "keypad_4x4.h"
#include <xc.h>
#include "config.h"

#define KEYPAD_PORT PORTB
#define COL1 RB0
#define COL2 RB1
#define COL3 RB2
#define COL4 RB3
#define ROW1 RB4
#define ROW2 RB5
#define ROW3 RB6
#define ROW4 RB7

//Keypad matrix 4x4
//Keypad has columns and 4 rows
//16 different characters
//pin 1 col1 pin 2 col 2 pin 3 col 3  pin 4 col4  
//pin 5 row1 pin 6 row 2 pin 7 row 3  pin 8 row 4
//
//       col 1 col 2 col 3 col 4        
//
//  row 1    1     2     3     A
//  
//  row 2    4     5     6     B
//
//  row 3    7     8     9     C
//
//  row 4    *     0     #     D
//
//All RB pins are reserved for the keypad

char characters[4][4] = {{"1","2","3","A"}, {"4","5","6","B"}, {"7","8","9","C"},{"*","0","#","D"}};

char read_keypad_pins()
{
    int ROW, COL;
    if (ROW1 == 1)
        ROW = 0;
    else if (ROW2 == 1)
        ROW = 1;
    else if (ROW3 == 1)
        ROW = 2;
    else if (ROW4 == 1)
        ROW = 3;
    else 
        return 0;
    if (COL1 == 1)
        COL = 0;
    else if (COL2 == 1)
        COL = 1;
    else if (COL3 == 1)
        COL = 2;
    else if (COL4 == 1)
        COL = 3;
    else 
        return 0;
    while (KEYPAD_PORT != 0x00); //waiting for keys to be released
        
    return characters[ROW][COL];
    
}

char read_keypad_char()
{
    char ch;
    //Program waits till a key is pressed
    while (1)
    {
        ch = read_keypad_pins();
        if (ch !=0)
            return ch;
    }
    
    return 0;
}
char *read_keypad(int mode)
{
    char *buffer;//Buffer has to be 15 char max
    if (mode == CANONICAL_MODE)
    {
        while(1)
        {          
            buffer = read_keypad_char();
            //OK1
            buffer++;
        }
        return buffer;
    }
    buffer = read_keypad_char();
    return buffer;
}