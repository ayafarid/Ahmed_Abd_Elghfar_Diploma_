/* 
 * File:   ecu_relay_init.h
 * Author: Aya farid
 *
 * Created on September 17, 2023, 2:51 PM
 */
#include "ecu_relay_init.h"
/**
 * @breif initialize certain relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_initialize(const relay_t* relay_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(relay_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_intialize(&relay_obj->relay_pin_config);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif turn on the relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_turn_on(const relay_t* relay_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(relay_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_write_logic(&relay_obj->relay_pin_config,HIGH);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif turn off the relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_turn_off(const relay_t* relay_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(relay_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_write_logic(&relay_obj->relay_pin_config,LOW);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif toggle the relay
 * @param pointer to relay object (relay_obj)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType relay_toggle(const relay_t* relay_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(relay_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        gpio_pin_toggle_logic(&relay_obj->relay_pin_config);
        Local_Status=E_OK;
    }
    return Local_Status;
}