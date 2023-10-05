/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
void INT0_APP_ISR(){
    led_toggle(&led1);
    __delay_ms(250);
}
void INT1_APP_ISR(){
    led_toggle(&led2);
    __delay_ms(250);
}
void INT2_APP_ISR(){
    led_toggle(&led3);
    __delay_ms(250);
}

void RB4_APP_ISR_HIGH(){
    led_turn_on(&led4);
    __delay_ms(500);
}
void RB4_APP_ISR_LOW(){
    led_turn_off(&led4);
}

void RB5_APP_ISR_HIGH(){
    led_turn_off(&led4);
}
void RB5_APP_ISR_LOW(){
    led_turn_on(&led4);
}

void RB6_APP_ISR_HIGH(){
    led_turn_on(&led5);
}
void RB6_APP_ISR_LOW(){
    led_turn_off(&led5);
}

void RB7_APP_ISR_HIGH(){
    led_turn_off(&led5);
}
void RB7_APP_ISR_LOW(){
    led_turn_on(&led5);
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
    INTERRUPT_LOW_PRIORITY
};
interrupt_INTx_t INT2_obj={
    INT2_APP_ISR,
    PORTB_INDEX,
    PIN2,
    INPUT,
    LOW,
    INTERRUPT_RISING_EDGE,
    INTERRUPT_EXTERNAL_INT2,
    INTERRUPT_LOW_PRIORITY
};

interrupt_RBx_t RB4_obj={
  RB4_APP_ISR_HIGH,
  RB4_APP_ISR_LOW,
  PORTB_INDEX,
  PIN4,
  INPUT,
  LOW,
  INTERRUPT_LOW_PRIORITY
};
interrupt_RBx_t RB5_obj={
  RB5_APP_ISR_HIGH,
  RB5_APP_ISR_LOW,
  PORTB_INDEX,
  PIN5,
  INPUT,
  LOW,
  INTERRUPT_LOW_PRIORITY
};
interrupt_RBx_t RB6_obj={
  RB6_APP_ISR_HIGH,
  RB6_APP_ISR_LOW,
  PORTB_INDEX,
  PIN6,
  INPUT,
  LOW,
  INTERRUPT_LOW_PRIORITY
};
interrupt_RBx_t RB7_obj={
  RB7_APP_ISR_HIGH,
  RB7_APP_ISR_LOW,
  PORTB_INDEX,
  PIN7,
  INPUT,
  LOW,
  INTERRUPT_LOW_PRIORITY
};
int main() {
    functionInitialize();
    while (1) {
        led_turn_on(&led1);
        __delay_ms(250);
        led_turn_off(&led1);
        __delay_ms(250);
    }
}

void functionInitialize() {
    ecu_layer_initialize();
    Interrupt_RBx_Init(&RB4_obj);
    Interrupt_RBx_Init(&RB5_obj);
    Interrupt_RBx_Init(&RB6_obj);
    Interrupt_RBx_Init(&RB7_obj);
    Interrupt_INTx_Init(&INT0_obj);
    Interrupt_INTx_Init(&INT1_obj);
    Interrupt_INTx_Init(&INT2_obj);
}
