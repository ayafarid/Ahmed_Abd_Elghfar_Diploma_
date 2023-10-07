/* 
 * File:   mcal_eeprom_init.h
 * Author: Aya farid
 *
 * Created on October 7, 2023, 2:10 PM
 */

#ifndef MCAL_EEPROM_INIT_H
#define	MCAL_EEPROM_INIT_H


/* Includes Section */
#include "pic18f4620.h"
#include "../std_types.h"
#include "../Interrupt_Driver/mcal_internal_interrupt.h"

/* Macros Declarations Section */
#define ACCESS_FLASH_PROGRAM_MEMORY_EEPGD                                   1
#define ACCESS_EEPROM_PROGRAM_MEMORY_EEPGD                                  0

#define ACCESS_CONFIGRATION_REGISTERS_CFGS                                  1
#define ACCESS_FLASH_PROGRAM_OR_EEPROM_CFGS                                 0

#define WRITE_ENABLE_TO_FLASH_PROGRAM_DATA_EEPROM_WREN                      1
#define INHIBITS_WRITE_CYCLES_TO_FLASH_PROGRAM_OR_DATA_EEPROM_WREN          0

#define WRITE_OPERATION_INITATES_EEPROM_ERASE                                     1

#define READ_OPERATION_INITATES_EEPROM                                      1

/* Function Like Macros Declarations Section*/
#define CLEAR_EEPGD_CONTROL_BIT_EECON_BIT7()                     (EECON1bits.EEPGD=0)
#define CLEAR_CFGS_TOACCESS_EEPROM()                             (EECON1bits.CFGS=0)
#define SET_READ_CONTROL_BIT_OF_EEPROM_EECON1()                  (EECON1bits.RD=1)
#define SET_CONTROL_BIT_RD_EECON1()                              (EECON1bits.RD=1)
/* Data Type Declarations */

/* Function Declarations Section */
/**
 * @breif Write Byte to EEPROM
 * @param Address of the Byte (byteAddress)
 * @param the data to be added in byte (data)
 * @return 
 */
Std_ReturnType EEPROM_Write_DataByByte(uint16 byteAddress,uint8 data);
/**
 * @breif Read Byte frin EEPROM
 * @param Address of the Byte (byteAddress)
 * @param pointer of the data to be stored in it after reading using data address in EEPROM (data)
 * @return 
 */
Std_ReturnType EEPROM_Read_DataByByte(uint16 byteAddress,uint8* data);
#endif	/* MCAL_EEPROM_INIT_H */

