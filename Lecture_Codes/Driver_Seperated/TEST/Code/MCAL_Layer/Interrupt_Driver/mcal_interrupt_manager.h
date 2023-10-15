/* 
 * File:   mcal_interrupt_managaer.h
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 source);
void RB5_ISR(uint8 source);
void RB6_ISR(uint8 source);
void RB7_ISR(uint8 source);

void ADC_ISR(void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

