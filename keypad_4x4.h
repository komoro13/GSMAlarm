#define RAW_MODE 1
#define CANONICAL_MODE 2

//keypad has two modes
//Raw mode and canonical mode
//if it is set in raw mode
//every character pressed is 
//read as unique 
//In canonical mode characters
//are saved in a buffer
//until # is pressed

char read_keypad_char();
char *read_keypad(int mode);
