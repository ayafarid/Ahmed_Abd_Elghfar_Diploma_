/* 
 * File:   ecu_keypad_init.h
 * Author: Aya farid
 *
 * Created on September 25, 2023, 2:44 PM
 */

#ifndef ECU_KEYPAD_INIT_H
#define	ECU_KEYPAD_INIT_H

/* Includes Section */
#include "ecu_keypad_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */
#define ECU_KEYPAD_ROWS_NUM      4
#define ECU_KEYPAD_COLUMS_NUM    4

#define _XTAL_FREQ 4000000UL

/* Data Types Declarations Section*/
typedef struct{
    pin_config_t keypad_rows_pins[ECU_KEYPAD_ROWS_NUM];
    pin_config_t keypad_colums_pins[ECU_KEYPAD_COLUMS_NUM];
}keypad_t;

/* Function Declarations Section */
/**
 * @breif keypad initialize
 * @param pointer to keypad_obj
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType keypad_initialize(keypad_t* keypad_obj);
/**
 * @breif keypad get key
 * @param pointer to keypad_obj
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType keypad_get_key(keypad_t* keypad_obj,uint8* value);
#endif	/* ECU_KEYPAD_INIT_H */

