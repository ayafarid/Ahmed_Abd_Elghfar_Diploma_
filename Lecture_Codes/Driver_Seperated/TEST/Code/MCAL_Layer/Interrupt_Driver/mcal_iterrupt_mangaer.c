/* 
 * File:   mcal_interrupt_manager.c
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */
#include "mcal_interrupt_manager.h"
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
void __interrupt InterruptManagerHighPriority(void){ /*Will manage High Priority Interrupt*/
    
}
void __interrupt(low_priority) InterruptManagerLowPriority(void){ /*Will manage Low Priority Interrupt*/
    
}
#else
void __interrupt InterruptManager(void){
    if(INTCONbits.INT0IE==INTERRUPT_ENABLE && INTCONbits.INT0IF==INTERRUPT_OCCUR){
        INT0_ISR();
    }else if(INTCON3bits.INT1IE==INTERRUPT_ENABLE && INTCON3bits.INT1IF==INTERRUPT_OCCUR){
        INT1_ISR();
    }else if(INTCON3bits.INT2IE==INTERRUPT_ENABLE && INTCON3bits.INT2IF==INTERRUPT_OCCUR){
        INT2_ISR();
    }else{
        /*No thing*/
    }
}
#endif