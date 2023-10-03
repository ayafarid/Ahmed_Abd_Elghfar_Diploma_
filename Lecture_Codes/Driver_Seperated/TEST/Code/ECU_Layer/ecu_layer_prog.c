/* 
 * File:   ecu_layer_int.h
 * Author: Aya farid
 *
 * Created on September 25, 2023, 3:36 PM
 */
#include "ecu_layer_int.h"
#include "Keypad_Driver/ecu_keypad_init.h"
#include "LED_Driver/ecu_led_init.h"

keypad_t keypad1={
  //Rows Pins
  PORTC_INDEX,
  PIN0,
  OUTPUT,
  LOW,  
  
  PORTC_INDEX,
  PIN1,
  OUTPUT,
  LOW,
  
  PORTC_INDEX,
  PIN2,
  OUTPUT,
  LOW,
  
  PORTC_INDEX,
  PIN3,
  OUTPUT,
  LOW,
  //Columns Pins
  PORTC_INDEX,
  PIN4,
  INPUT,
  LOW,  
  
  PORTC_INDEX,
  PIN5,
  INPUT,
  LOW,
  
  PORTC_INDEX,
  PIN6,
  INPUT,
  LOW,
  
  PORTC_INDEX,
  PIN7,
  INPUT,
  LOW,
};
led_t led1={
    PORTD_INDEX,
    PIN0,
    LED_OFF
};
led_t led2={
    PORTD_INDEX,
    PIN1,
    LED_OFF
};
led_t led3={
    PORTD_INDEX,
    PIN2,
    LED_OFF
};
Std_ReturnType ecu_layer_initialize(){
    Std_ReturnType ret=E_NOT_OK;
    ret=led_initizlize(&led1);
    ret=led_initizlize(&led2);
    ret=led_initizlize(&led3);
    return ret;
}
