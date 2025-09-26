#include <xc.h>
#include <string.h>

int EEPROM_Write(uint8_t data,uint8_t addr)
{
    while(EECON1bits.WR); //Wait for the last attempt for write to be finished
    
    EEDATA = data; //Data to be written
    EEADR = addr;  //Address of data to be written
    
    EECON1bits.EEPGD = 0; //Cleared to point EEPROM not program memory
    EECON1bits.WREN = 1;//Enable the writing operation
    
    INTCONbits.GIE = 0; //Disable all interrupts until writing is done
    
    EECON2 = 0x55; //Part of writing mechanism
    EECON2 = 0xAA; //Part of writing mechanism
    EECON1bits.WR = 1; //Part of writing mechanism
    
    INTCONbits.GIE = 1; //Re enable interrupts
    EECON1bits.WREN = 0; //Disable the operation
    EECON1bits.WR = 0; //Ready for next writing operation
    return 0;
}

uint8_t EEPROM_Read(uint8_t addr)
{
    uint8_t data;
    EEADR = addr; //Write the address from which gonna get data
    
    EECON1bits.EEPGD = 0;//Cleared to Point EEPROM not program memory
    EECON1bits.RD = 1;//Start the read operation
    
    data = EEDATA;//Read the data
    return data;
}

//OK 