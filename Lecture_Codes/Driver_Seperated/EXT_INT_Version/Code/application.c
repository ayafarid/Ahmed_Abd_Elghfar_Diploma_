/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
#include "ECU_Layer/LED_Driver/ecu_led_init.h"
#include "MCAL_Layer/Interrupt_Driver/mcal_external_interrupt.h"
void INT0_APP_ISR(){
    led_toggle(&led1);
}
void INT1_APP_ISR(){
    led_toggle(&led2);
}
void INT2_APP_ISR(){
    led_toggle(&led3);
}
/*
    void (* EXT_InterruptHandler)(void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg priority;
 */
interrupt_INTx_t INT0_obj={
    INT0_APP_ISR,
    PORTB_INDEX,
    PIN0,
    INPUT,
    LOW,
    INTERRUPT_RISING_EDGE,
    INTERRUPT_EXTERNAL_INT0,
    INTERRUPT_HIGH_PRIORITY
};
interrupt_INTx_t INT1_obj={
    INT1_APP_ISR,
    PORTB_INDEX,
    PIN1,
    INPUT,
    LOW,
    INTERRUPT_RISING_EDGE,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_HIGH_PRIORITY
};
interrupt_INTx_t INT2_obj={
    INT2_APP_ISR,
    PORTB_INDEX,
    PIN2,
    INPUT,
    LOW,
    INTERRUPT_RISING_EDGE,
    INTERRUPT_EXTERNAL_INT2,
    INTERRUPT_HIGH_PRIORITY
};
int main() {
    functionInitialize();
    Interrupt_INTx_Init(&INT0_obj);
    Interrupt_INTx_Init(&INT1_obj);
    Interrupt_INTx_Init(&INT2_obj);
    while (1) {
    }
}

void functionInitialize() {
    ecu_layer_initialize();
}
