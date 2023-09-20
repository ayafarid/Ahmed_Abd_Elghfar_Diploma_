/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
#include "MCAL_Layer/GPIO/hal_gpio.h"    
uint8 seconds = 0;
uint8 minutes = 16;
uint8 hours = 19;
uint8 segment_array[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
uint8 delay_required=3333;
int main() {
    functionInitialize();
    while (1) {
        /*Multiplexed*/
        for (int count = 0; count < 10; count++) {
            // 1111 1110
            gpio_port_write_logic(PORTD_INDEX, 0xFE);
            gpio_port_write_logic(PORTC_INDEX, ((uint8) (hours / 10)));
            __delay_us(3333);
            // 1111 1101
            gpio_port_write_logic(PORTD_INDEX, 0xFD);
            gpio_port_write_logic(PORTC_INDEX, ((uint8) (hours % 10)));
            __delay_us(3333);
            // 1111 0111
            gpio_port_write_logic(PORTD_INDEX, 0xF7);
            gpio_port_write_logic(PORTC_INDEX, ((uint8) (minutes / 10)));
            __delay_us(3333);
            // 1110 1111
            gpio_port_write_logic(PORTD_INDEX, 0xEF);
            gpio_port_write_logic(PORTC_INDEX, ((uint8) (minutes % 10)));
            __delay_us(3333);
            // 1011 1111
            gpio_port_write_logic(PORTD_INDEX, 0xBF);
            gpio_port_write_logic(PORTC_INDEX, ((uint8) (seconds / 10)));
            __delay_us(3333);
            // 0111 1111
            gpio_port_write_logic(PORTD_INDEX, 0x7F);
            gpio_port_write_logic(PORTC_INDEX, ((uint8) (seconds % 10)));
            __delay_us(3333);
        }
        seconds++;
        if(seconds==60){
            seconds=0;
            minutes++;
        }
        if(minutes==60){
            minutes=0;
            hours++;
        }
        if(hours==24){
            hours=0;
        }
        /*Decoded*/
        /*
        for(int i=0;i<100;i++){
            gpio_port_write_logic(PORTC_INDEX,((uint8)(i%10)|((uint8)(i/10)<<4)));
            __delay_ms(200);
        }*/
        /*normal*/
        /*
        for(int i=0;i<10;i++){
            gpio_port_write_logic(PORTC_INDEX,segment_array[i]);
            __delay_ms(2000);
        }*/
    }
}

void functionInitialize() {
    gpio_port_direction_intialize(PORTC_INDEX, 0x00);
    gpio_port_direction_intialize(PORTD_INDEX, 0x00);
}

