/* 
 * File:   mcal_external_interrupt.c
 * Author: Aya farid
 *
 * Created on October 2, 2023, 2:54 PM
 */

#include "mcal_external_interrupt.h"

/* Pointer to function to hold the callbacks for INTx */
static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;

static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;

static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;

static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj);

static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj);
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj);

static Std_ReturnType RB4_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void));
static Std_ReturnType RB5_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void));
static Std_ReturnType RB6_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void));
static Std_ReturnType RB7_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void));

static Std_ReturnType RBx_SetInterruptHandler(const interrupt_RBx_t *int_obj);

/**
 * @brief Initialize the external interrupt INT0, INT1 and INT2
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function (Std_ReturnType)
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Interrupt_INTx_Init(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK; /* NULL pointer detected */
    } else {
        /* Disable the External interrupt */
        ret = Interrupt_INTx_Disable(int_obj);
        /* Clear Interrupt Flag : External interrupt did not occur */
        ret |= Interrupt_INTx_Clear_Flag(int_obj);
        /* Configure External interrupt edge */
        ret |= Interrupt_INTx_Edge_Init(int_obj);
        /* Configure External interrupt I/O pin */
        ret |= Interrupt_INTx_Pin_Init(int_obj);
        /* Configure Default Interrupt CallBack */
        ret |= Interrupt_INTx_SetInterruptHandler(int_obj);
        /* Enable the External interrupt */
        ret |= Interrupt_INTx_Enable(int_obj);
    }
    return ret;
}

/**
 * External Interrupt 0 MCAL Helper function 
 */
void INT0_ISR(void) {
    /* The INT0 external interrupt occurred (must be cleared in software) */
    EXT_INT0_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if (INT0_InterruptHandler) {
        INT0_InterruptHandler();
    } else {
        /* Nothing */
    }
}

/**
 * External Interrupt 1 MCAL Helper function 
 */
void INT1_ISR(void) {
    /* The INT1 external interrupt occurred (must be cleared in software) */
    EXT_INT1_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if (INT1_InterruptHandler) {
        INT1_InterruptHandler();
    } else {
        /* Nothing */
    }
}

void INT2_ISR(void) {
    /* The INT1 external interrupt occurred (must be cleared in software) */
    EXT_INT2_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if (INT2_InterruptHandler) {
        INT2_InterruptHandler();
    } else {
        /* Nothing */
    }
}

/**
 * @brief DeInitialize the interrupt module
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        ret = Interrupt_INTx_Disable(int_obj);
    }
    return ret;
}

/**
 * @brief Enable the INTx interrupt source
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case INTERRUPT_EXTERNAL_INT0:
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
                INTERRUPT_GlobalInterruptHighEnable();
                EXT_INT1_HighPrioritySet();
#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT0_InterruptEnable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
                INTERRUPT_PriorityLevelsEnable();
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority) {
                    EXT_INT1_LowPrioritySet();
                    INTERRUPT_GlobalInterruptLowEnable();
                } else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority) {
                    INTERRUPT_GlobalInterruptHighEnable();
                    EXT_INT1_HighPrioritySet();
                } else {
                    /* Nothing */
                }
#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT1_InterruptEnable();
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
                INTERRUPT_PriorityLevelsEnable();
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority) {
                    EXT_INT2_LowPrioritySet();
                    INTERRUPT_GlobalInterruptLowEnable();
                } else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority) {
                    INTERRUPT_GlobalInterruptHighEnable();
                    EXT_INT2_HighPrioritySet();
                } else {
                    /* Nothing */
                }
#else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralInterruptEnable();
#endif
                EXT_INT2_InterruptEnable();
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case INTERRUPT_EXTERNAL_INT0:
                EXT_INT0_InterruptDisable(); /* Disable the INT0 external interrupt */
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                EXT_INT1_InterruptDisable(); /* Disable the INT1 external interrupt */
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT2_InterruptDisable(); /* Disable the INT2 external interrupt */
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 

static Std_ReturnType Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case INTERRUPT_EXTERNAL_INT1:
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority) {
                    EXT_INT1_LowPrioritySet();
                } else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority) {
                    EXT_INT1_HighPrioritySet();
                } else {
                    /* Nothing */
                }
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if (INTERRUPT_LOW_PRIORITY == int_obj->priority) {
                    EXT_INT2_LowPrioritySet();
                } else if (INTERRUPT_HIGH_PRIORITY == int_obj->priority) {
                    EXT_INT2_HighPrioritySet();
                } else {
                    /* Nothing */
                }
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case INTERRUPT_EXTERNAL_INT0:
                if (INTERRUPT_FALLING_EDGE == int_obj->edge) {
                    EXT_INT0_FallingEdgeSet();
                } else if (INTERRUPT_RISING_EDGE == int_obj->edge) {
                    EXT_INT0_RisingEdgeSet();
                } else {
                    /* Nothing */
                }
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                if (INTERRUPT_FALLING_EDGE == int_obj->edge) {
                    EXT_INT1_FallingEdgeSet();
                } else if (INTERRUPT_RISING_EDGE == int_obj->edge) {
                    EXT_INT1_RisingEdgeSet();
                } else {
                    /* Nothing */
                }
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                if (INTERRUPT_FALLING_EDGE == int_obj->edge) {
                    EXT_INT2_FallingEdgeSet();
                } else if (INTERRUPT_RISING_EDGE == int_obj->edge) {
                    EXT_INT2_RisingEdgeSet();
                } else {
                    /* Nothing */
                }
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        /* Initialize the MCU Pin for INTx with the needed configurations */
        ret = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case INTERRUPT_EXTERNAL_INT0:
                EXT_INT0_InterruptFlagClear(); /* Clears the interrupt flag for the external interrupt, INT0 */
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                EXT_INT1_InterruptFlagClear(); /* Clears the interrupt flag for the external interrupt, INT1 */
                ret = E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                EXT_INT2_InterruptFlagClear(); /* Clears the interrupt flag for the external interrupt, INT2 */
                ret = E_OK;
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief  
 * @param InterruptHandler
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler) {
        ret = E_NOT_OK;
    } else {
        /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
        INT0_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief  
 * @param InterruptHandler
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler) {
        ret = E_NOT_OK;
    } else {
        /* Set Default Interrupt Handler for INT1 External Interrupt : Application ISR */
        INT1_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief  
 * @param InterruptHandler
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler) {
        ret = E_NOT_OK;
    } else {
        /* Set Default Interrupt Handler for INT2 External Interrupt : Application ISR */
        INT2_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_INTx_SetInterruptHandler(const interrupt_INTx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch (int_obj->source) {
            case INTERRUPT_EXTERNAL_INT0:
                /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
                ret = INT0_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1:
                /* Set Default Interrupt Handler for INT1 External Interrupt : Application ISR */
                ret = INT1_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT2:
                /* Set Default Interrupt Handler for INT2 External Interrupt : Application ISR */
                ret = INT2_SetInterruptHandler(int_obj->EXT_InterruptHandler);
                break;
            default: ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj) {
    Std_ReturnType Local_State = E_NOT_OK;
    if (int_obj == NULL) {
        Local_State = E_NOT_OK;
    } else {
        Local_State = gpio_pin_direction_intialize(&(int_obj->mcu_pin));
    }
    return Local_State;
}

Std_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        EXT_RBx_InterruptDisable(); /*Disable External Interrupt On change Enable*/
        EXT_RBx_InterruptFlagClear(); /*Clear Flag of RBx external Interrupt*/

        Interrupt_RBx_Pin_Init(int_obj); /*Pin Initialize*/
        RBx_SetInterruptHandler(int_obj); /*Set Interrupt Handler*/
        Interrupt_RBx_Priority_Init(int_obj); /*Initialize Priority*/
        Interrupt_RBx_Enable(int_obj); /*Enable Interrupt*/
        ret = E_OK;
    }
    return ret;
}

/**
 * @brief  
 * @param int_obj  Pointer to the Interrupt configuration object
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        EXT_RBx_InterruptDisable();
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (int_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        EXT_RBx_InterruptEnable();
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (int_obj == NULL) {
        ret = E_NOT_OK;
    } else {
        EXT_RBx_InterruptDisable();
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (int_obj == NULL) {
        ret = E_NOT_OK;
    } else {
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE 
        INTERRUPT_PriorityLevelsEnable(); /*Enable Priority Levels*/
        if (int_obj->priority == INTERRUPT_LOW_PRIORITY) {
            INTERRUPT_GlobalInterruptLowEnable();
            EXT_RBx_Priority_Low();
        } else if (int_obj->priority == INTERRUPT_HIGH_PRIORITY) {
            EXT_RBx_Priority_High();
            INTERRUPT_GlobalInterruptHighEnable();
        } else {
            /*Do nothing*/
        }
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
#endif
    }
    return ret;
}

static Std_ReturnType RBx_SetInterruptHandler(const interrupt_RBx_t *int_obj) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == int_obj) {
        ret = E_NOT_OK;
    } else {
        switch ((int_obj->mcu_pin).pin) {
            case PIN4:
                RB4_SetInterruptHandler(int_obj->EXT_InterruptHandler_HIGH,int_obj->EXT_InterruptHandler_LOW);
                ret = E_OK;
                break;
            case PIN5:
                RB5_SetInterruptHandler(int_obj->EXT_InterruptHandler_HIGH,int_obj->EXT_InterruptHandler_LOW);
                ret = E_OK;
                break;
            case PIN6:
                RB6_SetInterruptHandler(int_obj->EXT_InterruptHandler_HIGH,int_obj->EXT_InterruptHandler_LOW);
                ret = E_OK;
                break;
            case PIN7:
                RB7_SetInterruptHandler(int_obj->EXT_InterruptHandler_HIGH,int_obj->EXT_InterruptHandler_LOW);
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}

static Std_ReturnType RB4_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler_1 || InterruptHandler_2==NULL){
        ret = E_NOT_OK;
    } else {
        RB4_InterruptHandler_HIGH = InterruptHandler_1;
        RB4_InterruptHandler_LOW  = InterruptHandler_2;
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType RB5_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler_1 || InterruptHandler_2==NULL) {
        ret = E_NOT_OK;
    } else {
        RB5_InterruptHandler_HIGH = InterruptHandler_1;
        RB5_InterruptHandler_LOW  = InterruptHandler_2;
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType RB6_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler_1 || InterruptHandler_2==NULL) {
        ret = E_NOT_OK;
    } else {
        RB6_InterruptHandler_HIGH = InterruptHandler_1;
        RB6_InterruptHandler_LOW  = InterruptHandler_2;
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType RB7_SetInterruptHandler(void (*InterruptHandler_1)(void),void (*InterruptHandler_2)(void)) {
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == InterruptHandler_1 || InterruptHandler_2==NULL) {
        ret = E_NOT_OK;
    } else {
        RB7_InterruptHandler_HIGH = InterruptHandler_1;
        RB7_InterruptHandler_LOW  = InterruptHandler_2;
        ret = E_OK;
    }
    return ret;
}

/**
 * RB4 Interrupt Service Routine Function
 */
void RB4_ISR(uint8 source){
    EXT_RBx_InterruptFlagClear(); /* Clear Flag*/
    /*Do Some code*/
    if(RB4_InterruptHandler_HIGH && source==HIGH){
        RB4_InterruptHandler_HIGH(); /*Call Back Function*/
    }
    if(RB4_InterruptHandler_LOW && source==LOW){
        RB4_InterruptHandler_LOW(); /*Call Back Function*/
    }
}
/**
 * RB5 Interrupt Service Routine Function
 */
void RB5_ISR(uint8 source){
    EXT_RBx_InterruptFlagClear(); /* Clear Flag*/
    /*Do Some code*/
    if(RB5_InterruptHandler_HIGH && source==HIGH){
        RB5_InterruptHandler_HIGH(); /*Call Back Function*/
    }
    if(RB5_InterruptHandler_LOW && source==LOW){
        RB5_InterruptHandler_LOW(); /*Call Back Function*/
    }
}
/**
 * RB6 Interrupt Service Routine Function
 */
void RB6_ISR(uint8 source){
    EXT_RBx_InterruptFlagClear(); /* Clear Flag*/
    /*Do Some code*/
    if(RB6_InterruptHandler_HIGH && source==HIGH){
        RB6_InterruptHandler_HIGH(); /*Call Back Function*/
    }
    if(RB6_InterruptHandler_LOW && source==LOW){
        RB6_InterruptHandler_LOW(); /*Call Back Function*/
    }
}
/**
 * RB7 Interrupt Service Routine Function
 */
void RB7_ISR(uint8 source){
    EXT_RBx_InterruptFlagClear(); /* Clear Flag*/
    /*Do Some code*/
    if(RB7_InterruptHandler_HIGH && source==HIGH){
        RB7_InterruptHandler_HIGH(); /*Call Back Function*/
    }
    if(RB7_InterruptHandler_LOW && source==LOW){
        RB7_InterruptHandler_LOW(); /*Call Back Function*/
    }
}