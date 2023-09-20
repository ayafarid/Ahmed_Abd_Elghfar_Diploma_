/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
#include "ECU_Layer/_7_Segment_Driver/ecu_7_seg_init.h"   
uint8 seconds = 0;
uint8 minutes = 16;
uint8 hours = 19;
seven_segment_t seven_seg_1 = {
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

    PORTD_INDEX,
    PIN0,
    OUTPUT,
    LOW,

    PORTD_INDEX,
    PIN1,
    OUTPUT,
    LOW,
    SEVEN_SEGMENT_COMMON_ANODE,

    PORTD_INDEX,
    PIN3,
    OUTPUT,
    LOW
};

int main() {
    functionInitialize();
    while (1) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 33; j++) {
                seven_segment_enable(&seven_seg_1, 0);
                seven_segment_disable(&seven_seg_1, 1);
                seven_segment_write_number(&seven_seg_1, i / 10);
                __delay_ms(10);
                seven_segment_enable(&seven_seg_1, 1);
                seven_segment_disable(&seven_seg_1, 0);
                seven_segment_write_number(&seven_seg_1, i % 10);
                __delay_ms(10);
            }
        }
    }
}

void functionInitialize() {
    seven_segment_initialize(&seven_seg_1);
}

