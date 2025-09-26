#include "phone.h"
int save_phone(char *phone)
{
    EEPROM_Write(fast_atou(phone),PHONE_ADDR);
    return 0;
}
char *read_saved_phone()
{
    char *phone;
    //OK1
    u8_to_dec(EEPROM_Read(PHONE_ADDR),phone, strlen(phone));
    return phone;
}
void MakeCall()
{   
    const unsigned char* prefix = (const unsigned char*)"ATD";
    const unsigned char* suffix = (const unsigned char*)";\r\n";
    const unsigned char *AT_COMMAND = concatenate(prefix, (const unsigned char*)read_saved_phone());
    
    AT_COMMAND = concatenate(AT_COMMAND,suffix );
   _SIM900A_print(AT_COMMAND);
   BlinkLED(0,0);
   
   //To fix concat
}
