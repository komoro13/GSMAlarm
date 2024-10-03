#include "keypad_4x4.h"


char read_keypad_char()
{
    char ch;
    
    return ch;
}
char *read_keypad(int mode)
{
    char *buffer;
    if (mode == CANONICAL_MODE)
    {
        while(1)
        {      
            buffer = read_keypad_char();
            buffer++;
        }
        return buffer;
    }
    buffer = read_keypad_char();
    return buffer;
}