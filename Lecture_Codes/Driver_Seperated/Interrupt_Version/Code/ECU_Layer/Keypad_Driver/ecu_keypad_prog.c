/* 
 * File:   ecu_keypad_init.h
 * Author: Aya farid
 *
 * Created on September 25, 2023, 2:44 PM
 */
#include "ecu_keypad_init.h"
/**
 * @breif keypad initialize
 * @param pointer to keypad_obj
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
static const uint8 btn_values[ECU_KEYPAD_ROWS_NUM][ECU_KEYPAD_COLUMS_NUM]={
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'c','0','=','+'}
};
Std_ReturnType keypad_initialize(keypad_t* keypad_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    uint8 rowsCount=0;
    uint8 columsCount=0;
    if(keypad_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        for(rowsCount=0;rowsCount<ECU_KEYPAD_ROWS_NUM;rowsCount++){
            Local_Status=gpio_pin_intialize(&keypad_obj->keypad_rows_pins[rowsCount]);
        }
        for(columsCount=0;columsCount<ECU_KEYPAD_COLUMS_NUM;columsCount++){
            Local_Status=gpio_pin_intialize(&keypad_obj->keypad_colums_pins[columsCount]);
        }
    }
    return Local_Status;
}
/**
 * @breif keypad get key
 * @param pointer to keypad_obj
 * @return Std_ReturnType status of the function
 *         (E_OK)    : The function done successfully
 *         (E_NOT_OK): The function has issue to perform this action
 */
Std_ReturnType keypad_get_key(keypad_t* keypad_obj,uint8* value){
    Std_ReturnType Local_Status=E_NOT_OK;
    uint8 rowsCount=0;
    uint8 columsCount=0;
    uint8 pinState=LOW;
    uint8 flag=0;
    *value=0;
    if(keypad_obj==NULL || value==NULL){
        Local_Status=E_NOT_OK;
    }else{
        for(rowsCount=0;rowsCount<ECU_KEYPAD_ROWS_NUM;rowsCount++){
            Local_Status=gpio_pin_write_logic(&keypad_obj->keypad_rows_pins[rowsCount],HIGH);
            for(columsCount=0;columsCount<ECU_KEYPAD_COLUMS_NUM;columsCount++){
                Local_Status=gpio_pin_read_logic(&keypad_obj->keypad_colums_pins[columsCount],&pinState);
                if(pinState==HIGH){
                    while(pinState==HIGH){
                        Local_Status=gpio_pin_read_logic(&keypad_obj->keypad_colums_pins[columsCount],&pinState);
                    }
                    __delay_ms(10);
                    *value=btn_values[rowsCount][columsCount];
                    flag=1;
                    break;
                }
            }
            Local_Status=gpio_pin_write_logic(&keypad_obj->keypad_rows_pins[rowsCount],LOW);
            if(flag==1){
                break;
            }
        }
        Local_Status=E_OK;
    }
    return Local_Status;
}
