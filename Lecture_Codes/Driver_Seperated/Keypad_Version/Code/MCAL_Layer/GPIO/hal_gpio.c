/* 
 * File:   hal_gpio.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:10 PM
 */
#include "hal_gpio.h"
/**
 * @breif function to intialze the direction of any pin
 * @param pointer to Configration to the pin i would intialize (_pin_config)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATION
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t* _pin_config){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(_pin_config==NULL){
        LocalReturn=E_NOT_OK;
    }else{
        switch(_pin_config->directin){
            case INPUT:
                SET_BIT(*tris_register[_pin_config->port],_pin_config->pin);
                LocalReturn=E_OK;
                break;
            case OUTPUT:
                CLEAR_BIT(*tris_register[_pin_config->port],_pin_config->pin);
                LocalReturn=E_OK;
                break;
            }
    }
    return LocalReturn;
}
/**
 * @brief function to get the direction status of a certain pin
 * @param pointer to Configration to the pin i would intialize (_pin_config)
 * @param direction_status
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config,direction_t* direction_status){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(_pin_config==NULL || (_pin_config->port)>PORT_MAX_NUMBER || (_pin_config->pin)>PORT_PIN_MAX_NUMBER || direction_status==NULL){
        LocalReturn=E_NOT_OK;
    }else{
        *direction_status=READ_BIT(*tris_register[_pin_config->port],_pin_config->pin);
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @brief fucntion to write logic in a certain pin
 * @param pointer to Configration to the pin i would intialize (_pin_config)
 * @param logic
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config,logic_t logic){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(_pin_config==NULL || (_pin_config->port)>PORT_MAX_NUMBER || (_pin_config->pin)>PORT_PIN_MAX_NUMBER || (_pin_config->directin==INPUT)){
        LocalReturn=E_NOT_OK;
    }else{
        switch(logic){
            case HIGH:
                SET_BIT(*lat_register[_pin_config->port],_pin_config->pin);
                LocalReturn=E_OK;
                break;
            case LOW:
                CLEAR_BIT(*lat_register[_pin_config->port],_pin_config->pin);
                LocalReturn=E_OK;
                break;
        }
    }
    return LocalReturn;
}
/**
 * @brief function to read logic from a certain pin
 * @param pointer to Configration to the pin i would intialize (_pin_config)
 * @param logic
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t* logic){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(_pin_config==NULL || logic==NULL || (_pin_config->port)>PORT_MAX_NUMBER || (_pin_config->pin)>PORT_PIN_MAX_NUMBER){
        LocalReturn=E_NOT_OK;
    }else{
        *logic=READ_BIT(*port_register[_pin_config->port],_pin_config->pin);
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @brief function to initalize direction and logic of a certain pin
 * @param pointer to Configration to the pin i would intialize (_pin_config)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_pin_intialize(const pin_config_t* _pin_config){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(_pin_config==NULL || (_pin_config->port)>PORT_MAX_NUMBER || (_pin_config->pin)>PORT_PIN_MAX_NUMBER){
        LocalReturn=E_NOT_OK;
    }else{
        gpio_pin_direction_intialize(_pin_config);
        gpio_pin_write_logic(_pin_config,_pin_config->logic);
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @breif function to toggle logic of a certain pin
 * @param pointer to Configration to the pin i would intialize (_pin_config)
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(_pin_config==NULL || (_pin_config->port)>PORT_MAX_NUMBER || (_pin_config->pin)>PORT_PIN_MAX_NUMBER){
        LocalReturn=E_NOT_OK;
    }else{
        TOGGLE_BIT(*lat_register[_pin_config->port],_pin_config->pin);
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
#endif
#if PORT_COFIGRATION
/**
 * @brief intialize the direction of a certain port
 * @param port
 * @param direction
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_port_direction_intialize(port_index_t port,uint8 direction){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(port>PORT_MAX_NUMBER){
        LocalReturn=E_NOT_OK;
    }else{
        *tris_register[port]=direction;
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @brief get the direction of a certain port
 * @param port
 * @param directionPortStatus
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8* directionPortStatus){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(port>PORT_MAX_NUMBER || directionPortStatus==NULL){
        LocalReturn=E_NOT_OK;
    }else{
        *directionPortStatus=*tris_register[port];
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @brief write logic for a certain port
 * @param port
 * @param logic
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(port>PORT_MAX_NUMBER){
        LocalReturn=E_NOT_OK;
    }else{
        *lat_register[port]=logic;
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @brief read the logic of a certain port
 * @param port
 * @param logic
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8* logic){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(port>PORT_MAX_NUMBER || logic==NULL){
        LocalReturn=E_NOT_OK;
    }else{
        *logic=*lat_register[port];
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
/**
 * @brief toggle logic of a certain port
 * @param port
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    Std_ReturnType LocalReturn=E_NOT_OK;
    if(port>PORT_MAX_NUMBER){
        LocalReturn=E_NOT_OK;
    }else{
        *lat_register[port]^=GPIO_PORT_MASK;
        LocalReturn=E_OK;
    }
    return LocalReturn;
}
#endif