/* 
 * File:   ecu_7_seg_init.h
 * Author: Aya farid
 *
 * Created on September 20, 2023, 6:27 PM
 */
#include "ecu_7_seg_init.h"

/**
 * @breif intialize seven segment object
 * @param pointer to seven segment object (seven_segment_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
///Done

Std_ReturnType seven_segment_initialize(seven_segment_t* seven_segment_obj) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL) {
        Local_Status = E_NOT_OK;
    } else {
        for (int i = 0; i < PIN_NUM; i++) {
            gpio_pin_direction_intialize(&seven_segment_obj->seven_segment_pins[i]);
        }
        for (int i = 0; i < NUM_OF_MULTI_SEG; i++) {
            gpio_pin_direction_intialize(&seven_segment_obj->seven_segment_enable_bin[i]);
        }
        gpio_pin_direction_intialize(&seven_segment_obj->seven_segment_dot_pin);
        Local_Status = E_OK;
    }
    return Local_Status;
}

/**
 * @breif write number to seven segment
 * @param pointer to seven segment object (seven_segment_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
///Done

Std_ReturnType seven_segment_write_number(seven_segment_t* seven_segment_obj, uint8 number) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL || number > 9) {
        Local_Status = E_NOT_OK;
    } else {
        gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[0], number & 0x01);
        gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[1], number >> 1 & 0x01);
        gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[2], number >> 2 & 0x01);
        gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[3], number >> 3 & 0x01);
        Local_Status = E_OK;
    }
    return Local_Status;
}

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
///Done

Std_ReturnType seven_segment_clear_number(seven_segment_t* seven_segment_obj) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL) {
        Local_Status = E_NOT_OK;
    } else {
#if CONFIG_DECODED_STATUS==CONFIG_SEVEN_SEGMENT_DECODED
        if (seven_segment_obj->seven_segment_common_state == SEVEN_SEGMENT_COMMON_ANODE) {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[0], HIGH);
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[1], HIGH);
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[2], HIGH);
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[3], HIGH);
        } else {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[0], LOW);
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[1], LOW);
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[2], LOW);
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_pins[3], LOW);
        }
#endif
        Local_Status = E_OK;
    }
    return Local_Status;
}

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
Std_ReturnType seven_segment_setDot(seven_segment_t* seven_segment_obj) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL) {
        Local_Status = E_NOT_OK;
    } else {
#if CONFIG_DP_CONECT_STATUS==CONFIG_ENABLE_DP
        if (seven_segment_obj->seven_segment_common_state == SEVEN_SEGMENT_COMMON_ANODE) {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_dot_pin, LOW);
        } else {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_dot_pin, HIGH);
        }
#endif
        Local_Status = E_OK;
    }
    return Local_Status;
}

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
///?

Std_ReturnType seven_segment_clearDot(seven_segment_t* seven_segment_obj) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL) {
        Local_Status = E_NOT_OK;
    } else {
#if CONFIG_DP_CONECT_STATUS==CONFIG_ENABLE_DP
        if (seven_segment_obj->seven_segment_common_state == SEVEN_SEGMENT_COMMON_ANODE) {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_dot_pin, HIGH);
        } else {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_dot_pin, LOW);
        }
#endif
        Local_Status = E_OK;
    }
    return Local_Status;
}

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
///Done

Std_ReturnType seven_segment_enable(seven_segment_t* seven_segment_obj, uint8 segment_Index) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL || segment_Index > NUM_OF_MULTI_SEG) {
        Local_Status = E_NOT_OK;
    } else {
        if (seven_segment_obj->seven_segment_common_state == SEVEN_SEGMENT_COMMON_ANODE) {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_enable_bin[segment_Index], HIGH);
            Local_Status = E_NOT_OK;
        } else {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_enable_bin[segment_Index], LOW);
            Local_Status = E_NOT_OK;
        }
    }
    return Local_Status;
}
///Done

/**
 * 
 * @param seven_segment_obj
 * @param segment_Index
 * @return 
 */
Std_ReturnType seven_segment_disable(seven_segment_t* seven_segment_obj, uint8 segment_Index) {
    Std_ReturnType Local_Status = E_NOT_OK;
    if (seven_segment_obj == NULL || segment_Index > NUM_OF_MULTI_SEG) {
        Local_Status = E_NOT_OK;
    } else {
        if (seven_segment_obj->seven_segment_common_state == SEVEN_SEGMENT_COMMON_ANODE) {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_enable_bin[segment_Index], LOW);
            Local_Status = E_NOT_OK;
        } else {
            gpio_pin_write_logic(&seven_segment_obj->seven_segment_enable_bin[segment_Index], HIGH);
            Local_Status = E_NOT_OK;
        }
    }
    return Local_Status;
}
