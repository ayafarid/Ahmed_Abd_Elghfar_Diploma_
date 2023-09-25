/* 
 * File:   ecu_led_init.h
 * Author: Aya farid
 *
 * Created on September 25, 2023, 4:34 PM
 */
#include "ecu_led_init.h"
/**
 * @breif initialize a certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_initizlize(const led_t* led){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(NULL == led){
        Local_Status=E_NOT_OK;
    }else{
        CLEAR_BIT(*tris_register[led->port_index],led->pin_num);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif turning on a certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_turn_on(const led_t*led){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(led==NULL){
        LocalReturn=E_NOT_OK;
    }else{
        SET_BIT(*lat_register[led->port_index],led->pin_num);
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @breif turning off certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_turn_off(const led_t*led){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(NULL == led){
        Local_Status=E_NOT_OK;
    }else{
        CLEAR_BIT(*port_register[led->port_index],led->pin_num);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif toggle state of a certain led
 * @param pointer to a certain led (led)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_toggle(const led_t* led){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(NULL == led){
        Local_Status=E_NOT_OK;
    }else{
        TOGGLE_BIT(*lat_register[led->port_index],led->pin_num);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif read status of a certain led
 * @param pointer to a certain led (led)
 * @param ledStatus
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType led_read_status(const led_t*led, led_status_t* ledStatus){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(NULL == led || NULL==ledStatus || led->port_index>PORT_MAX_NUMBER || led->pin_num>PORT_PIN_MAX_NUMBER){
        Local_Status=E_NOT_OK;
    }else{
        *ledStatus=TOGGLE_BIT(*lat_register[led->port_index],led->pin_num);
        Local_Status=E_OK;
    }
    return Local_Status;
}
