/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
volatile uint8 program_selectd=0;
void INT0_APP_ISR(){
    program_selectd++;
    if(program_selectd==3){
        program_selectd=1;
    }
    EEPROM_Write_DataByByte(0x3ff,program_selectd);
}
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
int main() {
    functionInitialize();
    /*EEPROM and interrupt*/
    EEPROM_Read_DataByByte(0x3ff,&program_selectd);
    while (1) {
        if(1==program_selectd){
            program1();
        }else if(2==program_selectd){
            progarm2();
        }
    }
    /*Using variable*/
    /*
    EEPROM_Write_DataByByte(0x3ff,0);
    while (1) {
        EEPROM_Write_DataByByte(0x3ff,eeprom_val1++);
        __delay_ms(1000);
        EEPROM_Read_DataByByte(0x3ff,&eeprom_val2);
        if(15>=eeprom_val2){
            led_turn_on(&led1);
            __delay_ms(100);
        }else{
            led_turn_off(&led1);
            __delay_ms(100);
        }
    }*/
}

void functionInitialize() {
    ecu_layer_initialize();
    Interrupt_INTx_Init(&INT0_obj);
}
void program1(){
    led_turn_on(&led1);
    __delay_ms(250);
    led_turn_off(&led1);
    __delay_ms(250);
}
void progarm2(){
    led_turn_on(&led2);
    __delay_ms(250);
    led_turn_off(&led2);
    __delay_ms(250);
}
