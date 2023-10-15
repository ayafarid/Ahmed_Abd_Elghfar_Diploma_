/* 
 * File:   application.h
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:15 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Includes Section */
#include "ECU_Layer/ecu_layer_int.h"
#include "ECU_Layer/LED_Driver/ecu_led_init.h"
#include "MCAL_Layer/EEPROM_Driver/mcal_eeprom_init.h"
#include "MCAL_Layer/Interrupt_Driver/mcal_external_interrupt.h"
#include "MCAL_Layer/ADC_Driver/mcal_adc_init.h"
/* Macros Declarations Section */
#define _XTAL_FREQ 4000000UL

/* Data Types Declarations Section*/
extern keypad_t keypad1;
extern led_t led1;
extern led_t led2;
extern led_t led3;
extern led_t led4;
extern led_t led5;
/* Function Declarations Section */
void functionInitialize();
void ADC_DefaultInterruptHandeler(void);
void program1();
void progarm2();
#endif	/* APPLICATION_H */

