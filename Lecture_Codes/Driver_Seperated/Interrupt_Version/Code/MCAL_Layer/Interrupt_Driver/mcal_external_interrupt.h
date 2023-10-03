/* 
 * File:   mcal_internal_interrupt.h
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */
#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* ----------------- Includes -----------------*/
#include "mcal_interrupt_config.h"

/* ----------------- Macro Declarations -----------------*/

/* ----------------- Macro Functions Declarations -----------------*/
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXT_INT0_InterruptDisable()         (INTCONbits.INT0IE = 0)   /*Disable Interrupt INT0*/
#define EXT_INT0_InterruptEnable()          (INTCONbits.INT0IE = 1)   /*Enable Interrupt INT0*/
#define EXT_INT0_InterruptFlagClear()       (INTCONbits.INT0IF = 0)   /*Clear Flag of Interrupt INT0*/
#define EXT_INT0_RisingEdgeSet()            (INTCON2bits.INTEDG0 = 1) /*Set Edge of INT0 to Rising Edge*/
#define EXT_INT0_FallingEdgeSet()           (INTCON2bits.INTEDG0 = 0) /*Set Edge of INT0 to Failing Edge*/

#define EXT_INT1_InterruptDisable()         (INTCON3bits.INT1IE = 0)  /*Disable Interrupt INT1*/
#define EXT_INT1_InterruptEnable()          (INTCON3bits.INT1IE = 1)  /*Enable Interrupt INT1*/
#define EXT_INT1_InterruptFlagClear()       (INTCON3bits.INT1IF = 0)  /*Clear Flag of Interrupt INT1*/
#define EXT_INT1_RisingEdgeSet()            (INTCON2bits.INTEDG1 = 1) /*Set Edge of INT1 to Rising Edge*/
#define EXT_INT1_FallingEdgeSet()           (INTCON2bits.INTEDG1 = 0) /*Set Edge of INT0 to Failing Edge*/

#define EXT_INT2_InterruptDisable()         (INTCON3bits.INT2IE = 0)  /*Disable Interrupt INT2*/
#define EXT_INT2_InterruptEnable()          (INTCON3bits.INT2IE = 1)  /*Enable Interrupt INT2*/
#define EXT_INT2_InterruptFlagClear()       (INTCON3bits.INT2IF = 0)  /*Clear Flag of Interrupt INT2*/
#define EXT_INT2_RisingEdgeSet()            (INTCON2bits.INTEDG2 = 1) /*Set Edge of INT2 to Rising Edge*/
#define EXT_INT2_FallingEdgeSet()           (INTCON2bits.INTEDG2 = 0) /*Set Edge of INT1 to Failing Edge*/

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
#define EXT_INT1_HighPrioritySet()           (INTCON3bits.INT1IP = 1) /*Set Priority High to INT1*/
#define EXT_INT1_LowPrioritySet()            (INTCON3bits.INT1IP = 0) /*Set Priority Low to INT1*/

#define EXT_INT2_HighPrioritySet()           (INTCON3bits.INT2IP = 1) /*Set Priority High to INT2*/
#define EXT_INT2_LowPrioritySet()            (INTCON3bits.INT2IP = 0) /*Set Priority Low to INT2*/
#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
#define EXT_RBx_InterruptDisable()         (INTCONbits.RBIE = 0) /*Disable RBx On change Interrupt*/
#define EXT_RBx_InterruptEnable()          (INTCONbits.RBIE = 1) /*Enable RBx On change Interrupt*/
#define EXT_RBx_InterruptFlagClear()       (INTCONbits.RBIF = 0) /*Clear Flag Of RBx On change Interrupt*/

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
#define EXT_RBx_Priority_High()            (INTCON2bits.RBIP = 1) /*Set priority High to RBx on change Interrupt*/
#define EXT_RBx_Priority_Low()             (INTCON2bits.RBIP = 0) /*Set priority Low to RBx on change Interrupt*/
#endif

#endif

/* ----------------- Data Type Declarations -----------------*/
typedef void (*InterruptHandler)(void);

typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}interrupt_INTx_edge;

typedef enum{
    INTERRUPT_EXTERNAL_INT0 =  0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
}interrupt_INTx_src;

typedef struct{
    void (* EXT_InterruptHandler)(void);
    pin_config_t mcu_pin;
    interrupt_INTx_edge edge;
    interrupt_INTx_src source;
    interrupt_priority_cfg priority;
}interrupt_INTx_t;

typedef struct{
    void (* EXT_InterruptHandler_HIGH)(void);
    void (* EXT_InterruptHandler_LOW)(void);
    pin_config_t mcu_pin;
    interrupt_priority_cfg priority;
}interrupt_RBx_t;

/* ----------------- Software Interfaces Declarations -----------------*/
/**
 * @breif function to Initialization the external interrupt INTx
 * @param pointer to external Interrupt INTx (int_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj);

/**
 * @breif function to DeIntiate the external interrupt INTx
 * @param pointer to external Interrupt INTx (int_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj);

/**
 * @breif function to Initialization to Interrupt of type On change
 * @param pointer to Interrupt On change Object (int_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj);

/**
 * @breif function to deIntitalte the RBx
 * @param pointer to Interrupt On change Object (int_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */
