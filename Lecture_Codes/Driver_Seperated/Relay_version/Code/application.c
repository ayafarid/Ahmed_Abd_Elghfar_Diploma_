/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
#include "ECU_Layer/Relay/ecu_relay_init.h"
#include "MCAL_Layer/GPIO/hal_gpio.h"
relay_t relay1={
    PORTC_INDEX,
    PIN0,
    OUTPUT,
    LOW,
    RELAY_OFF_STATUS
};
int main(){
    functionInitialize();
    while(1){
        relay_turn_on(&relay1);
        __delay_ms(1000);
        relay_turn_off(&relay1);
        __delay_ms(1000);
    }
}
void functionInitialize(){
    relay_initialize(&relay1);
}
/*
Std_ReturnType ret;
logic_t logic;
button_t button_low = {
    PORTD_INDEX,
    PIN1,
    INPUT,
    LOW,
    BUTTON_RELEASED,
    BUTTON_ACTIVE_LOW
};
button_t button_high = {
    PORTD_INDEX,
    PIN0,
    INPUT,
    LOW,
    BUTTON_RELEASED,
    BUTTON_ACTIVE_HIGH
};
led_t led1 = {
    PORTC_INDEX,
    PIN0,
    LED_OFF
};
led_t led2 = {
    PORTC_INDEX,
    PIN1,
    LED_OFF
};
led_t led3 = {
    PORTC_INDEX,
    PIN2,
    LED_OFF
};
led_t led4 = {
    PORTC_INDEX,
    PIN3,
    LED_OFF
};
led_t led5 = {
    PORTC_INDEX,
    PIN4,
    LED_OFF
};
led_t led6 = {
    PORTC_INDEX,
    PIN5,
    LED_OFF
};
led_t led7 = {
    PORTC_INDEX,
    PIN6,
    LED_OFF
};
led_t led8 = {
    PORTC_INDEX,
    PIN7,
    LED_OFF
};
direction_t led1_direction_status;

int main(int argc, char** argv) {
    functionInitialize();
    button_initialize(&button_low);
    button_initialize(&button_high);
    button_chek button_low_state=BUTTON_RELEASED;
    button_chek button_high_state=BUTTON_RELEASED;
    while (1) {
        button_read_state(&button_low,&button_low_state);
        button_read_state(&button_high,&button_high_state);
        if(button_high_state==BUTTON_PRESSED){
            led_turn_on(&led1);
        }else{
            led_turn_off(&led1);
        }
        if(button_low_state==BUTTON_PRESSED){
            led_turn_on(&led2);
        }else{
            led_turn_off(&led2);
        }
    }
    return (EXIT_SUCCESS);
}

void functionInitialize() {
    led_initizlize(&led1);
    led_initizlize(&led2);
}
 */
