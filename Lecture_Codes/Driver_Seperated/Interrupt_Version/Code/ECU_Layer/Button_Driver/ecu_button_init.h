/* 
 * File:   ecu_button_init.h
 * Author: Aya farid
 *
 * Created on September 15, 2023, 7:32 PM
 */

#ifndef ECU_BUTTON_INIT_H
#define	ECU_BUTTON_INIT_H
/* Includes Section */
#include "ecu_button_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */

/* Function Like Macros Declarations Section*/

/* Data Types Declarations */
typedef enum {
    BUTTON_RELEASED,
    BUTTON_PRESSED
}button_chek;
typedef enum{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}button_active;
typedef struct {
    pin_config_t button_pin;
    button_active button_presed;
    button_chek button_active;
}button_t;
/* Function Declarations Section */
/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_read_state(const button_t *btn, button_chek *btn_state);
#endif	/* ECU_BUTTON_INIT_H */

