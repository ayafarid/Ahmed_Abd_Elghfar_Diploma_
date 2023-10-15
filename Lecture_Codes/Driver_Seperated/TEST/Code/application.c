/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
volatile uint8 adc_flag=0;
uint16 adc_res_1=0,adc_res_2,adc_res_3,adc_res_4;
void ADC_DefaultInterruptHandeler(void);
ADC_config_t adc_1={
  ADC_DefaultInterruptHandeler,
  ADC_12_TAD,
  ADC_CONVERTION_CLOCK_FOSC_DIV_16,
  ADC_CHANEL_AN0,
  DISABLE,
  RIGHT_FORMAT
};
void ADC_DefaultInterruptHandeler(void){
    ADC_GetConversionResult(&adc_1,&adc_res_1);
}
ADC_config_t adc_2={
  NULL,
  ADC_12_TAD,
  ADC_CONVERTION_CLOCK_FOSC_DIV_16,
  ADC_CHANEL_AN1,
  DISABLE,
  RIGHT_FORMAT
};
ADC_config_t adc_3={
  NULL,
  ADC_12_TAD,
  ADC_CONVERTION_CLOCK_FOSC_DIV_16,
  ADC_CHANEL_AN2,
  DISABLE,
  RIGHT_FORMAT
};
ADC_config_t adc_4={
  NULL,
  ADC_12_TAD,
  ADC_CONVERTION_CLOCK_FOSC_DIV_16,
  ADC_CHANEL_AN3,
  DISABLE,
  RIGHT_FORMAT
};
int main() {
    functionInitialize();
    ADC_StartConversion_Interrupt(&adc_1,ADC_CHANEL_AN0);
    while (1) {
    }
}

void functionInitialize() {
    ecu_layer_initialize();
    ADC_Init(&adc_1);
    ADC_Init(&adc_2);
    ADC_Init(&adc_3);
    ADC_Init(&adc_4);
}