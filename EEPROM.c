#include <xc.h>

int EEPROM_Write_Byte(uint8_t data,uint8_t addr)
{
    while(EECON1bits.WR); //Wait for the last attempt for write to be finished
    EEDATA = data; //Data to be written
    EEADR = addr;  //Adress of data to be written
    EECON1bits.EEPGD = 0; //Cleared to point EEPROM not program memory
    EECON1bits.WREN = 1; //Enable the operation
    INTCONbits.GIE = 0; //Disable all interupts until writing is done
    EECON2 = 0x55; //Part of writing mechanism
    EECON2 = 0xAA; //Part of writing mechanism
    EECON1bits.WR = 1; //Part of writing mechanism
    INTCONbits.GIE = 1; //Re enable interupts
    EECON1bits.WREN = 0; //Disable the operation
    EECON1bits.WR = 0; //Ready for next writing operation
    return 0;
}

uint8_t EEPROM_Read_Byte(uint8_t addr)
{
    uint8_t data;
    EEADR = addr; //Write the adress from which gonna get data
    EECON1bits.EEPGD = 0;//Cleared to Point EEPROM not program memory
    EECON1bits.RD = 1;//Start the read operation
    data = EEDATA;//Read the data
    return data;
}

uint8_t *char_to_uint8_t(char *data_ch)
{
    int s_data;
    s_data = sizeof(data_ch);
    uint8_t data[15];
    
    for (int i = 0; i < s_data; i++)
    {
        data_ch[i] = (uint8_t)atoi(data[i]);
    }
    return data;
}

int EEPROM_Write(char *data_ch, uint8_t addr)
{
    uint8_t address;
    uint8_t data[15] = char_to_uint8_t(data_ch);
    address = addr;
    
    
    int data_len = sizeof(data);
    for (int i = 0; i < data_len; i++)
    {
        EEPROM_Write_Byte(data[i]);
        address++;
    }
    return 0;
}

int EEPROM_Read(uint8_t addr)
{
    char data[15];
    uint8_t address = addr;
    
    for (int i = 0; int < 15; i++)
    {
        if (EEPROM_Read_Byte(address) == 0)
                break;
        data[i] = EEPROM_Read_Byte(address);
        address++;
    }
    return 0;
}