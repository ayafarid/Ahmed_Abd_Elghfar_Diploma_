/* 
 * File:   ecu_button_config.h
 * Author: Aya farid
 *
 * Created on September 15, 2023, 7:33 PM
 */
#include "ecu_button_init.h"
Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;
    if(NULL == btn){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(btn->button_pin));
    }
    return ret;
}

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_read_state(const button_t *btn, button_chek *btn_state){
    Std_ReturnType ret = E_NOT_OK;
    logic_t Pin_Logic_Status = LOW;
    if((NULL == btn) || (NULL == btn_state)){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_read_logic(&(btn->button_pin), &Pin_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == btn->button_active){
            if(HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_active){
            if(HIGH == Pin_Logic_Status){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else { /* Nothing */ }
        ret = E_OK;
    }
    return ret;
}
