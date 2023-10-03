/* 
 * File:   ecu_7_seg_init.h
 * Author: Aya farid
 *
 * Created on September 20, 2023, 6:27 PM
 */

#ifndef ECU_7_SEG_INIT_H
#define	ECU_7_SEG_INIT_H

/* Includes Section */
#include "ecu_7_seg_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */
#define SEVEN_SEG_PINA     0
#define SEVEN_SEG_PINB     1
#define SEVEN_SEG_PINC     2
#define SEVEN_SEG_PIND     3
#define SEVEN_SEG_PINE     4
#define SEVEN_SEG_PINF     5
#define SEVEN_SEG_PING     6
#define SEVEN_SEG_PIN_DP   7

#define SEVEN_SEGMENT_COMMON_ANODE   0
#define SEVEN_SEGMENT_COMMON_CATHODE   1

#define NUM_OF_MULTI_SEG               2

/* Data Types Declarations Section */
typedef struct{
    pin_config_t seven_segment_pins[PIN_NUM];
    pin_config_t seven_segment_enable_bin[NUM_OF_MULTI_SEG];
    uint8 seven_segment_common_state:1;
    pin_config_t seven_segment_dot_pin;
}seven_segment_t;

/* Function Declarations */
/**
 * @breif intialize seven segment object
 * @param pointer to seven segment object (seven_segment_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType seven_segment_initialize(seven_segment_t* seven_segment_obj);

/**
 * @breif write number to seven segment
 * @param pointer to seven segment object (seven_segment_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType seven_segment_write_number(seven_segment_t* seven_segment_obj, uint8 number);

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
Std_ReturnType seven_segment_clear_number(seven_segment_t* seven_segment_obj);
/**
 * 
 * @param seven_segment_obj
 * @return 
 */
Std_ReturnType seven_segment_setDot(seven_segment_t* seven_segment_obj);

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
Std_ReturnType seven_segment_clearDot(seven_segment_t* seven_segment_obj);

/**
 * 
 * @param seven_segment_obj
 * @return 
 */
Std_ReturnType seven_segment_enable(seven_segment_t* seven_segment_obj,uint8 segment_Index);
/**
 * 
 * @param seven_segment_obj
 * @param segment_Index
 * @return 
 */
Std_ReturnType seven_segment_disable(seven_segment_t* seven_segment_obj,uint8 segment_Index);
#endif	/* ECU_7_SEG_INIT_H */

