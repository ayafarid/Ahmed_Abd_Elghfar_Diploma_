/* 
 * File:   mcal_interrupt_config.h
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* ----------------- Includes -----------------*/
#include "pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "mcal_interrupt_gen_config.h"

/* ----------------- Macro Declarations -----------------*/
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCCUR     1
#define INTERRUPT_NOT_OCCUR 0
#define INTERRUPT_PRIORITY_ENABLE    1
#define INTERRUPT_PRIORITY_DISABLE   0

/* ----------------- Macro Functions Declarations -----------------*/

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
#define INTERRUPT_PriorityLevelsEnable()  (RCONbits.IPEN = 1) /*Enable Priority Levels*/
#define INTERRUPT_PriorityLevelsDisable() (RCONbits.IPEN = 0) /*Disable Priority Levels*/

#define INTERRUPT_GlobalInterruptHighEnable()  (INTCONbits.GIEH = 1) /*Enable Global High Priority*/
#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH = 0) /*Disable Global High Priority*/

#define INTERRUPT_GlobalInterruptLowEnable()   (INTCONbits.GIEL = 1) /*Enable Low Priority global Interrupt*/
#define INTERRUPT_GlobalInterruptLowDisable()  (INTCONbits.GIEL = 0) /*Disable Low Priority global Interrupt*/
#else
#define INTERRUPT_GlobalInterruptEnable()  (INTCONbits.GIE = 1) /*Enable Global Interrupt*/
#define INTERRUPT_GlobalInterruptDisable() (INTCONbits.GIE = 0) /*Disable Global Interrupt*/

#define INTERRUPT_PeripheralInterruptEnable()  (INTCONbits.PEIE = 1) /*Enable Peripheral Interrupt Enable*/
#define INTERRUPT_PeripheralInterruptDisable() (INTCONbits.PEIE = 0) /*Disable Peripheral Interrupt Enable*/
#endif

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority_cfg;

/* ----------------- Software Interfaces Declarations -----------------*/


#endif	/* MCAL_INTERRUPT_CONFIG_H */
