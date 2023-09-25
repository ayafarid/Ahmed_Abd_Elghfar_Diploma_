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

/* Macros Declarations Section */
#define _XTAL_FREQ 4000000UL

/* Data Types Declarations Section*/
extern keypad_t keypad1;
extern led_t led1;

/* Function Declarations Section */
void functionInitialize();
#endif	/* APPLICATION_H */

