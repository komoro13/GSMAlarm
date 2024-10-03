# 1 "keypad_4x4.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.45\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "keypad_4x4.c" 2
# 1 "./keypad_4x4.h" 1
# 13 "./keypad_4x4.h"
char read_keypad_char();
char *read_keypad(int mode);
# 1 "keypad_4x4.c" 2



char read_keypad_char()
{
    char ch;

    return ch;
}
char *read_keypad(int mode)
{
    char *buffer;
    if (mode == 2)
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
