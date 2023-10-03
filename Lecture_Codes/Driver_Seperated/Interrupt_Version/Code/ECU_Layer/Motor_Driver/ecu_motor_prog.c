/* 
 * File:   ecu_motor_init.h
 * Author: Aya farid
 *
 * Created on September 18, 2023, 3:37 PM
 */

#include "ecu_motor_init.h"
/**
 * @brief motor initialize 
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_initialize(motor_t* motor_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(motor_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_direction_intialize(&motor_obj->pinLeft);
        gpio_pin_direction_intialize(&motor_obj->pinRight);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @brief motor turn right
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_turn_right(motor_t* motor_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(motor_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_write_logic(&motor_obj->pinRight,HIGH);
        gpio_pin_write_logic(&motor_obj->pinLeft,LOW);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @brief motor turn left
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_turn_left(motor_t* motor_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(motor_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_write_logic(&motor_obj->pinRight,LOW);
        gpio_pin_write_logic(&motor_obj->pinLeft,HIGH);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @brief motor turn off or stop
 * @param pointer to motor object (motor_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType motor_turn_off(motor_t* motor_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(motor_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_write_logic(&motor_obj->pinRight,LOW);
        gpio_pin_write_logic(&motor_obj->pinLeft,LOW);
        Local_Status=E_OK;
    }
    return Local_Status;
}
