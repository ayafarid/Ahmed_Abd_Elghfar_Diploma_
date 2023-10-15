/* 
 * File:   mcal_adc_init.h
 * Author: Aya farid
 *
 * Created on October 14, 2023, 11:11 AM
 */

#ifndef MCAL_ADC_INIT_H
#define	MCAL_ADC_INIT_H

/* ----------------- Includes -----------------*/
#include "mcal_adc_config.h"
#include "../GPIO/hal_gpio.h"
#include "pic18f4620.h"
#include "../std_types.h"
#include "../Interrupt_Driver/mcal_internal_interrupt.h"

/* ----------------- Macro Declarations -----------------*/
#define ADC_AN0__FUNCTIONALITY               0x0E
#define ADC_AN1__FUNCTIONALITY               0x0D
#define ADC_AN2__FUNCTIONALITY               0x0C
#define ADC_AN3__FUNCTIONALITY               0x0B
#define ADC_AN4__FUNCTIONALITY               0x0A
#define ADC_AN5__FUNCTIONALITY               0x09
#define ADC_AN6__FUNCTIONALITY               0x08
#define ADC_AN7__FUNCTIONALITY               0x07
#define ADC_AN8__FUNCTIONALITY               0x06
#define ADC_AN9__FUNCTIONALITY               0x05
#define ADC_AN10__FUNCTIONALITY              0x04
#define ADC_AN11__FUNCTIONALITY              0x03
#define ADC_AN12__FUNCTIONALITY              0x02

#define ADC_ALL_ANALOG_FUNCTIONALITY         0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY        0xff

#define DISABLE       1
#define ENABLE        0

#define RIGHT_FORMAT                         0x01U
#define LEFT_FORMAT                          0x00U

#define ZERO                                 0x00U
#define ONE                                  0x01U

#define COMPLETED                            0x01U
#define IN_PROCESS                           0x00U
/* ----------------- Macro Functions Declarations -----------------*/
#define ADC_CONVERSION_STATUS()                   (ADCON0bits.GO_DONE)
#define ADC_START_CONVERSION()                    (ADCON0bits.GO_DONE=1)
/**
 * @brief Analog-To-Digital Control
 * @note  ADC_CONVRTION_ENABLE()   : Enable the Analog-To-Digital
 *        ADC_CONVRTION_DISABLE()   : Disable the Analog-To-Digital
 */
#define ADC_CONVRTION_ENABLE()                    (ADCON0bits.ADON=1)
#define ADC_CONVRTION_DISABLE()                   (ADCON0bits.ADON=0)

#define ADC_ENABLE_VOLTAGE_REFERENCE()            do{ADCON1bits.VCFG1=1;    \
                                                     ADCON1bits.VCFG0=1;    \
                                                    }while(0);
#define ADC_DISABLE_VOLTAGE_REFERENCE()           do{ADCON1bits.VCFG1=0;    \
                                                     ADCON1bits.VCFG0=0;    \
                                                    }while(0);
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_config)   (ADCON1bits.PCFG=_config)

#define ADC_ENABLE_RIGHT_JUSTIFIED()              (ADCON2bits.ADFM=1)
#define ADC_ENABLE_LEFT_JUSTIFIED()               (ADCON2bits.ADFM=0)


/* ----------------- Data Type Declarations -----------------*/

typedef void (*InterruptHandler)(void);

typedef enum{
    ADC_CHANEL_AN0,
    ADC_CHANEL_AN1,
    ADC_CHANEL_AN2,
    ADC_CHANEL_AN3,
    ADC_CHANEL_AN4,
    ADC_CHANEL_AN5,
    ADC_CHANEL_AN6,
    ADC_CHANEL_AN7,
    ADC_CHANEL_AN8,
    ADC_CHANEL_AN9,
    ADC_CHANEL_AN10,
    ADC_CHANEL_AN11,
    ADC_CHANEL_AN12
}ADC_Chanels_t;

typedef enum{
    ADC_0_TAD=0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD, 
    ADC_16_TAD,
    ADC_20_TAD
}ADC_aquisition_time_t;

typedef enum{
    ADC_CONVERTION_CLOCK_FOSC_DIV_2=0,
    ADC_CONVERTION_CLOCK_FOSC_DIV_8,
    ADC_CONVERTION_CLOCK_FOSC_DIV_32,
    ADC_CONVERTION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERTION_CLOCK_FOSC_DIV_4,
    ADC_CONVERTION_CLOCK_FOSC_DIV_16,
    ADC_CONVERTION_CLOCK_FOSC_DIV_64,
}ADC_conversion_clock_t;

typedef struct{
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
    void (*ADC_InterruptHandeler)(void);
#else
    /*Nothing*/
#endif
    ADC_aquisition_time_t acquasition_time;
    ADC_conversion_clock_t conversion_clock;
    ADC_Chanels_t channel_selected;
    uint8 voltage_reference : 1;
    uint8 result_format : 1;
    uint8 : 6;
}ADC_config_t;
typedef uint16 adc_result_t;
/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType ADC_Init(const ADC_config_t* adc_obj);
Std_ReturnType ADC_DeInit(const ADC_config_t* adc_obj);
Std_ReturnType ADC_StartConversion(const ADC_config_t* adc_obj);
Std_ReturnType ADC_SelectChannel(const ADC_config_t* adc_obj,ADC_Chanels_t channel);
Std_ReturnType ADC_IsConversionCompleted(const ADC_config_t* adc_obj,uint8* conversion_status);
Std_ReturnType ADC_GetConversionResult(const ADC_config_t* adc_obj,adc_result_t* convesion_result);
#if ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_ENABLE
Std_ReturnType ADC_StartConversion_Interrupt(const ADC_config_t* adc_obj,ADC_Chanels_t channel);
#elif ADC_CONFIG_INTERRUPT_STATUS==INTERRUPT_FEATURE_DISABLE
Std_ReturnType ADC_GetConversion_Blocking(const ADC_config_t* adc_obj,ADC_Chanels_t channel,adc_result_t* convesion_result);
#endif

#endif	/* MCAL_ADC_INIT_H */

