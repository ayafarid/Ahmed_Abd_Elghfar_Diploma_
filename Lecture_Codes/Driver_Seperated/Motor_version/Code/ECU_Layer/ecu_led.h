/* 
 * File:   ecu_led.h
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:14 PM
 */

#ifndef ECU_LED_1_H
#define	ECU_LED_1_H
/* Includes Section */
#include "../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */

/* Data Types Declarations */
typedef enum {
    LED_OFF,
    LED_ON
} led_status_t;

typedef struct {
    uint8 port_index : 4;
    uint8 pin_num : 3;
    uint8 led_status : 1;
} led_t;

/* Function Like Macros Declarations Section*/


/* Function Declarations Section */
/**
 * @breif initialize a certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_initizlize(const led_t* led);
/**
 * @breif turning on a certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_turn_on(const led_t*led);
/**
 * @breif turning off certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_turn_off(const led_t*led);
/**
 * @breif toggle state of a certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_toggle(const led_t* led);
/**
 * @breif read status of a certain led
 * @param pointer to a certain led (led)
 * @param ledStatus
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_read_status(const led_t*led, led_status_t* ledStatus);
#endif	/* ECU_LED_H */

