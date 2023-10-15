/* 
 * File:   mcal_adc_config.h
 * Author: Aya farid
 *
 * Created on October 14, 2023, 11:11 AM
 */
#include "mcal_adc_init.h"
volatile uint8 flag=0;
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
static InterruptHandler ADC_InterruptHandeler=NULL;
#endif
static Std_ReturnType ADC_input_channel_port_configure(ADC_Chanels_t channel);
/**
 * @brief ADC Initialize
 * @param pointer to ADC object   (adc_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType ADC_Init(const ADC_config_t* adc_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        ADC_InterruptHandeler=adc_obj->ADC_InterruptHandeler;
        /*Disable ADC*/
        ADC_CONVRTION_DISABLE();
        /*Configure the acquisition time*/
        ADCON2bits.ACQT=adc_obj->acquasition_time;
        /*Configure the conversion clock*/
        ADCON2bits.ADCS=adc_obj->conversion_clock;
        /*Configure the default Channel*/
        ADCON0bits.CHS=adc_obj->channel_selected;
        ADC_input_channel_port_configure(adc_obj->channel_selected);
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_DISABLE
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        ADC_InterruptEnable();
        ADC_InterruptClearFlag();
#elif INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
        ADC_InterruptEnable();
        INTERRUPT_PriorityLevelsEnable();
        if(adc_obj->priority==INTERRUPT_HIGH_PRIORITY){
            INTERRUPT_GlobalInterruptHighEnable();
            ADC_InterruptHighPriority();
        }else if(adc_obj->priority==INTERRUPT_LOW_PRIORITY){
            INTERRUPT_GlobalInterruptLowEnable();
            ADC_InterruptLowPriority();
        }
        ADC_InterruptClearFlag();
#endif
#else
    /*Nothing*/
#endif  
        /*Configure the result format*/
        if(adc_obj->result_format==RIGHT_FORMAT){
            ADC_ENABLE_RIGHT_JUSTIFIED();
        }else if(adc_obj->result_format==LEFT_FORMAT){
            ADC_ENABLE_LEFT_JUSTIFIED();
        }
        /*Configure the voltage reference*/
        if((adc_obj->voltage_reference) == ENABLE){
            ADC_ENABLE_VOLTAGE_REFERENCE();
        }else if(( adc_obj->voltage_reference) == DISABLE){
            ADC_DISABLE_VOLTAGE_REFERENCE();
        }
        /*Enable ADC*/
        ADC_CONVRTION_ENABLE();
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @brief ADC De Initialize
 * @param pointer to ADC object   (adc_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType ADC_DeInit(const ADC_config_t* adc_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        /*Disable The ADC*/
        ADC_CONVRTION_DISABLE();
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
        /*Disable the interrupt*/
        ADC_InterruptDisable();
        INTERRUPT_GlobalInterruptDisable();
        INTERRUPT_PeripheralInterruptDisable();
#else
    /*Nothing*/
#endif   
        /**/
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @brief ADC De Start Conversion
 * @param pointer to ADC object   (adc_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType ADC_StartConversion(const ADC_config_t* adc_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        /*Enable Go/Done Bit*/
        ADC_START_CONVERSION();
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @brief Select a certain Channel of ADC
 * @param pointer to ADC object   (adc_obj)
 * @param the channel to be selected (channel)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType ADC_SelectChannel(const ADC_config_t* adc_obj,ADC_Chanels_t channel){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        ADCON0bits.CHS=channel;
        ADC_input_channel_port_configure(channel);
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif check if conversion is completed or not
 * @param pointer to ADC object   (adc_obj)
 * @param the conversion status is completed or in process (conversion_status)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType ADC_IsConversionCompleted(const ADC_config_t* adc_obj,uint8* conversion_status){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL || conversion_status==NULL){
        Local_Status=E_NOT_OK;
    }else{
        if(ADC_CONVERSION_STATUS()==ZERO){
            *conversion_status=COMPLETED;
            Local_Status=E_OK;
        }else if(ADC_CONVERSION_STATUS()==ONE){
            *conversion_status=IN_PROCESS;
            Local_Status=E_OK;
        }else{
            Local_Status=E_NOT_OK;
        }
    }
    return Local_Status;
}
/**
 * @breif return the result of ADC conversion 
 * @param pointer to ADC object   (adc_obj)
 * @param the result of ADC conversion (convesion_result)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType ADC_GetConversionResult(const ADC_config_t* adc_obj,adc_result_t* convesion_result){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL || convesion_result==NULL){
        Local_Status=E_NOT_OK;
    }else{
        if(RIGHT_FORMAT == adc_obj->result_format){
            *convesion_result = (adc_result_t)((ADRESH << 8) + ADRESL);
        }
        else if(LEFT_FORMAT == adc_obj->result_format){
            *convesion_result = (adc_result_t)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else{
            *convesion_result = (adc_result_t)((ADRESH << 8) + ADRESL);
        }
        Local_Status=E_OK;
    }
    return Local_Status;
}
/**
 * @breif return the conversion result
 * @param pointer to ADC object   (adc_obj)
 * @param the channel to be selected to get the result from (channel)
 * @param the result of ADC conversion (convesion_result)
 * @return 
 */
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_DISABLE
Std_ReturnType ADC_GetConversion_Blocking(const ADC_config_t* adc_obj,ADC_Chanels_t channel,adc_result_t* convesion_result){
    Std_ReturnType Local_Status=E_NOT_OK;
    uint8 conversion_status=IN_PROCESS;
    if(adc_obj==NULL || convesion_result==NULL){
        Local_Status=E_NOT_OK;
    }else{
        /*Select Channel*/
        Local_Status |= ADC_SelectChannel(adc_obj,channel);
        /*Start ADC conversion*/
        Local_Status |= ADC_StartConversion(adc_obj);
        /*Check if conversion is completed*/
        Local_Status |= ADC_IsConversionCompleted(adc_obj,&conversion_status);
        while(ADC_CONVERSION_STATUS());
        Local_Status |= ADC_GetConversionResult(adc_obj,convesion_result);
    }
    return Local_Status;
}
#elif ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
Std_ReturnType ADC_StartConversion_Interrupt(const ADC_config_t* adc_obj,ADC_Chanels_t channel){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(adc_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        ADC_InterruptClearFlag();
        /*Select Channel*/
        Local_Status |= ADC_SelectChannel(adc_obj,channel);
        /*Start ADC conversion*/
        Local_Status |= ADC_StartConversion(adc_obj);
    }
    return Local_Status;
}
#endif
static Std_ReturnType ADC_input_channel_port_configure(ADC_Chanels_t channel){
    switch(channel){
        case ADC_CHANEL_AN0: 
            SET_BIT(TRISA,_TRISA_RA0_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN1: 
            SET_BIT(TRISA,_TRISA_RA1_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN2: 
            SET_BIT(TRISA,_TRISA_RA2_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN3: 
            SET_BIT(TRISA,_TRISA_RA3_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN4: 
            SET_BIT(TRISA,_TRISA_RA5_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN5: 
            SET_BIT(TRISE,_TRISE_RE0_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN6: 
            SET_BIT(TRISE,_TRISE_RE1_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN7: 
            SET_BIT(TRISE,_TRISE_RE2_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN8: 
            SET_BIT(TRISB,_TRISB_RB2_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN9: 
            SET_BIT(TRISB,_TRISB_RB3_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN10: 
            SET_BIT(TRISB,_TRISB_RB1_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN11: 
            SET_BIT(TRISB,_TRISB_RB4_POSN);
            return E_OK;
            break;
        case ADC_CHANEL_AN12: 
            SET_BIT(TRISB,_TRISB_RB0_POSN);
            return E_OK;
            break;
        default:
            return E_NOT_OK;
    }
}
void ADC_ISR(void){
    ADC_InterruptClearFlag();
    if(ADC_InterruptHandeler){
        ADC_InterruptHandeler();
    }
}

