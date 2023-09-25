/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
#include "ECU_Layer/ecu_led.h"
int main() {
    functionInitialize();
    uint8 value=0;
    while (1) {
        keypad_get_key(&keypad1,&value);
        if(value=='c'){
            led_turn_on(&led1);
            __delay_ms(1000);
            led_turn_off(&led1);
            __delay_ms(1000);
        }
    }
}

void functionInitialize() {
    ecu_layer_initialize();
}

