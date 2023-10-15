/* 
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE

#else
    /*Nothing*/
#endif
/* ----------------- Macro Functions Declarations -----------------*/
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
/*Disable ADC Interrupt*/
#define ADC_InterruptDisable()                 (PIE1bits.ADIE=0)
/*Enable ADC Interrupt*/
#define ADC_InterruptEnable()                  (PIE1bits.ADIE=1)
/*ADC Clear flag*/
#define ADC_InterruptClearFlag()               (PIR1bits.ADIF=0)
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
/*ADC Interrupt high priority*/
#define ADC_InterruptHighPriority()            (IPR1bits.ADIP=1)
/*ADC Interrupt Low priority*/
#define ADC_InterruptLowPriority()            (IPR1bits.ADIP=0)
#endif
#else
    /*Nothing*/
#endif
/* ----------------- Data Type Declarations -----------------*/
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE

#else
    /*Nothing*/
#endif
/* ----------------- Software Interfaces Declarations -----------------*/
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE

#else
    /*Nothing*/
#endif
#endif	/* MCAL_INTERNAL_INTERRUPT_H */
