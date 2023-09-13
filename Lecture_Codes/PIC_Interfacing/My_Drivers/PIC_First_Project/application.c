/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
pin_config_t led1={
  PORTC_INDEX,
  PIN0,
  OUTPUT,
  LOW
};
pin_config_t led2={
  PORTC_INDEX,
  PIN1,
  OUTPUT,
  LOW
};
pin_config_t led3={
  PORTC_INDEX,
  PIN2,
  OUTPUT,
  LOW
};
pin_config_t led4={
  PORTC_INDEX,
  PIN3,
  OUTPUT,
  LOW
};
pin_config_t led5={
  PORTC_INDEX,
  PIN4,
  OUTPUT,
  LOW
};
pin_config_t led6={
  PORTC_INDEX,
  PIN5,
  OUTPUT,
  LOW
};
pin_config_t led7={
  PORTC_INDEX,
  PIN6,
  OUTPUT,
  LOW
};
pin_config_t led8={
  PORTC_INDEX,
  PIN7,
  OUTPUT,
  LOW
};
pin_config_t button={
    PORTD_INDEX,
    PIN0,
    INPUT,
    LOW
};
Std_ReturnType ret;
logic_t logic;
direction_t led1_direction_status;
int main(int argc, char** argv) {
    while(1){
    gpio_port_direction_intialize(PORTC_INDEX,0x00);
    gpio_port_write_logic(PORTC_INDEX,0x55); // 0x55
    __delay_ms(3000);
    uint8 direction;
    gpio_port_get_direction_status(PORTC_INDEX,&direction);
    gpio_port_write_logic(PORTC_INDEX,direction); // 0x00
    __delay_ms(3000);
    gpio_port_toggle_logic(PORTC_INDEX); // 0xff
    __delay_ms(3000);
    uint8 logic;
    gpio_port_read_logic(PORTC_INDEX,&logic); // 0xff
    gpio_port_write_logic(PORTC_INDEX,logic); // 0xff
    __delay_ms(3000);
    }
    return (EXIT_SUCCESS);
}
void functionInitialize(){
        ret=gpio_pin_intialize(&led1);
        ret=gpio_pin_intialize(&led2);
        ret=gpio_pin_intialize(&led3);
        ret=gpio_pin_intialize(&led4);
        ret=gpio_pin_intialize(&led5);
        ret=gpio_pin_intialize(&led6);
        ret=gpio_pin_intialize(&led7);
        ret=gpio_pin_intialize(&led8);
        ret=gpio_pin_intialize(&button);
}

