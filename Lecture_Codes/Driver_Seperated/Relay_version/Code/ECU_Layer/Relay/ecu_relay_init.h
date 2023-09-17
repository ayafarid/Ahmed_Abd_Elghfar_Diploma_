/* 
 * File:   ecu_relay_init.h
 * Author: Aya farid
 *
 * Created on September 17, 2023, 2:51 PM
 */

#ifndef ECU_RELAY_INIT_H
#define	ECU_RELAY_INIT_H
/* Includes Section */
#include "ecu_relay_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */
#define RELAY_ON_STATUS      0x01u
#define RELAY_OFF_STATUS     0x00u

/* Function Like Macros Declarations Section*/

/* Data Types Declarations */
typedef struct{
    pin_config_t relay_pin_config;
    uint8 relay_status:1;
}relay_t;
/* Function Declarations Section */
/**
 * @breif initialize certain relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_initialize(const relay_t* relay_obj);
/**
 * @breif turn on the relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_turn_on(const relay_t* relay_obj);
/**
 * @breif turn off the relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_turn_off(const relay_t* relay_obj);
/**
 * @breif toggle the relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_toggle(const relay_t* relay_obj);
#endif	/* ECU_RELAY_INIT_H */

