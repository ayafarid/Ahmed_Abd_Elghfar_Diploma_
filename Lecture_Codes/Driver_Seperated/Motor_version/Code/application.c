/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
#include "ECU_Layer/Motor_Driver/ecu_motor_init.h"
motor_t motorOne={
  PORTC_INDEX,
  PIN0,
  OUTPUT,
  MOTOR_PIN_STATUS_OFF ,
  PORTC_INDEX,
  PIN1,
  OUTPUT,
  MOTOR_PIN_STATUS_ON
};
int main(){
    functionInitialize();
    while(1){
        motor_turn_right(&motorOne);
        __delay_ms(1000);
        motor_turn_left(&motorOne);
        __delay_ms(1000);
    }
}
void functionInitialize(){
    motor_initialize(&motorOne);
}

