/* 
 * File:   mcal_eeprom_prog.c
 * Author: Aya farid
 *
 * Created on October 7, 2023, 2:10 PM
 */
#include "mcal_eeprom_init.h"
/**
 * @breif Write Byte to EEPROM
 * @param Address of the Byte (byteAddress)
 * @param the data to be added in byte (data)
 * @return 
 */
Std_ReturnType EEPROM_Write_DataByByte(uint16 byteAddress,uint8 data){
    Std_ReturnType Local_State=E_NOT_OK;
    /*Writer the address (10 Bits) to EEADR and EEADRH*/
    EEADRH=((uint8)(byteAddress>>8)&0x03);
    EEADR =(uint8)(byteAddress&0x0ff);
    /*Write the data to EEDATA*/
    EEDATA=data;
    /*Clear EEPGD to access EEPROM*/
    CLEAR_EEPGD_CONTROL_BIT_EECON_BIT7();
    /*Clear the CFGS to access FLASH_OR_EEPROM*/
    CLEAR_CFGS_TOACCESS_EEPROM();
    /*set the WREN*/
    EECON1bits.WREN=WRITE_ENABLE_TO_FLASH_PROGRAM_DATA_EEPROM_WREN;
    /*Disable all interrupts and save its status*/
    INTERRUPT_GlobalInterruptDisable();
    uint8 interrupt_Status=INTCONbits.GIE;
    /*The write will not begin if this sequence is not exactly
followed (write 55h to EECON2, write 0AAh to
EECON2*/
    EECON2=0x55;
    EECON2=0xAA;
    /*set WR bit*/
    EECON1bits.WR=WRITE_OPERATION_INITATES_EEPROM_ERASE;
    /*wait for write complete*/
    while(EECON1bits.WR); /*it cleared automatically if the write operation completed*/
    /*Clear The WREN*/
    EECON1bits.WREN=INHIBITS_WRITE_CYCLES_TO_FLASH_PROGRAM_OR_DATA_EEPROM_WREN;
    /*Restore interrupt state*/
    INTCONbits.GIE=interrupt_Status;
    
    return Local_State;
}
/**
 * @breif Read Byte frin EEPROM
 * @param Address of the Byte (byteAddress)
 * @param pointer of the data to be stored in it after reading using data address in EEPROM (data)
 * @return 
 */
Std_ReturnType EEPROM_Read_DataByByte(uint16 byteAddress,uint8* data){
    Std_ReturnType Local_State=E_NOT_OK;
    if(data==NULL){
        Local_State=E_NOT_OK;
    }else{
        /*First Write the address to the EEADRH:EEADR register pair*/
        EEADRH=((uint8)(byteAddress>>8)&0x03);
        EEADR =(uint8)(byteAddress&0x0ff);
        /*clear the control bit (EECON1<7>)*/
        CLEAR_EEPGD_CONTROL_BIT_EECON_BIT7();
        /*Clear the CFGS to access data EEPROM*/
        CLEAR_CFGS_TOACCESS_EEPROM();
        /*Set the Read Control bit from EECON1*/
        SET_READ_CONTROL_BIT_OF_EEPROM_EECON1();
        /*Perform 2 No Operation*/
        NOP();
        NOP();
        /*Return the value from the EEDATA*/
        *data=EEDATA;
        Local_State=E_OK;
    }
    return Local_State;
}
