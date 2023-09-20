/* 
 * File:   ecu_motor_init.h
 * Author: Aya farid
 *
 * Created on September 18, 2023, 3:37 PM
 */

#ifndef ECU_MOTOR_INIT_H
#define	ECU_MOTOR_INIT_H
/* Includes Section */
#include "ecu_motor_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */
#define MOTOR_PIN_STATUS_ON      0x01U
#define MOTOR_PIN_STATUS_OFF     0x00U

#define MOTOR_TURN_LEFT      0x00U
#define MOTOR_TURN_RIGH      0x01U

#define PIN_CONNECTED        0x01U
#define PIN_NOT_CONNECED     0x00U


/* Data Types Declarations */
typedef struct{
    uint8 motor_port:4;
    uint8 motor_pin:3;
    uint8 motor_pin_direction:1;
    uint8 motor_status:1;
}motor_pin_t;
typedef struct{
    motor_pin_t pinRight;
    motor_pin_t pinLeft;
}motor_t;
/* Function Like Macros Declarations Section*/

/* Function Declarations Section */
/**
 * @brief motor initialize 
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_initialize(motor_t* motor_obj);
/**
 * @brief motor turn right
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_turn_right(motor_t* motor_obj);
/**
 * @brief motor turn left
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_turn_left(motor_t* motor_obj);
/**
 * @brief motor turn off or stop
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_turn_off(motor_t* motor_obj);
#endif	/* ECU_MOTOR_INIT_H */

