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

int EEPROM_Write(char *data)
{
    int data_len = sizeof(data);
    for (int i = 0; i < data_len; i++)
    {
       
    }
    return 0;
}

int EEPROM_Read()
{
    
    return 0;
}