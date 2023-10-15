/* 
 * File:   mcal_interrupt_manager.c
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */
#include "mcal_interrupt_manager.h"
uint8 RB4_Flag=1;
uint8 RB5_Flag=1;
uint8 RB6_Flag=1;
uint8 RB7_Flag=1;
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE

void __interrupt() InterruptManagerHigh(void){
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{ /* Nothing */ }
}
void __interrupt(low_priority) InterruptManagerLow(void){
    if((INTERRUPT_ENABLE == INTCON3bits.INT1E) && (INTERRUPT_OCCUR == INTCON3bits.INT1F)){
        INT1_ISR();
    }
    else{ /* Nothing */ }
}
#else

void __interrupt InterruptManager(void) {
    if (INTCONbits.INT0IE == INTERRUPT_ENABLE && INTCONbits.INT0IF == INTERRUPT_OCCUR) {
        INT0_ISR();
    }
    if (INTCON3bits.INT1IE == INTERRUPT_ENABLE && INTCON3bits.INT1IF == INTERRUPT_OCCUR) {
        INT1_ISR();
    }
    if (INTCON3bits.INT2IE == INTERRUPT_ENABLE && INTCON3bits.INT2IF == INTERRUPT_OCCUR) {
        INT2_ISR();
    }
    /*RB4*/
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB4==HIGH && RB4_Flag==1){
        RB4_Flag=0;
        RB4_ISR(PORTBbits.RB4);
    }
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB4==LOW && RB4_Flag==0){
        RB4_Flag=1;
        RB4_ISR(PORTBbits.RB4);
    }
    /*End*/
    
    /*RB5*/
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB5==HIGH && RB5_Flag==1){
        RB5_Flag=0;
        RB5_ISR(PORTBbits.RB5);
    }
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB5==LOW && RB5_Flag==0){
        RB5_Flag=1;
        RB5_ISR(PORTBbits.RB5);
    }
    /*End*/
    
    /*RB6*/
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB6==HIGH && RB6_Flag==1){
        RB6_Flag=0;
        RB6_ISR(PORTBbits.RB6);
    }
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB6==LOW && RB6_Flag==0){
        RB6_Flag=1;
        RB6_ISR(PORTBbits.RB6);
    }
    /*End*/
    
    /*RB7*/
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB7==HIGH && RB7_Flag==1){
        RB7_Flag=0;
        RB7_ISR(PORTBbits.RB7);
    }
    if (INTCONbits.RBIE==INTERRUPT_ENABLE && INTCONbits.RBIF==INTERRUPT_OCCUR && PORTBbits.RB7==LOW && RB7_Flag==0){
        RB7_Flag=1;
        RB7_ISR(PORTBbits.RB7);
    }
    /*End*/
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCUR == PIR1bits.ADIF)){
        ADC_ISR();
    }
    else{ /* Nothing */ }
    
}
#endif