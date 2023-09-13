/* 
 * File:   hal_gpio.h
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:10 PM
 */
/// File Garde
#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Includes Section */

#include "pic18f4620.h"
#include "../std_types.h"
#include "../device_config.h"
#include "hal_gpio_config.h"

/* Macros Declarations Section */
#define BIT_MASK                             (uint8)1
#define GPIO_PORT_MASK                       (uint8)0xFF
#define PORT_PIN_MAX_NUMBER                  8
#define PORT_MAX_NUMBER                      5
#define PORT_PIN_CONFIGRATION                CONFIG_ENABLE
#define PORT_COFIGRATION                     CONFIG_ENABLE

/* Function Like Macros Declarations Section*/
#define HWRREG(_x)                   (*((uint8 *)(_x)))
#define SET_BIT(REG,BIT_NUM)         REG|=(BIT_MASK<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM)       REG&=(~(BIT_MASK<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)      REG^=(BIT_MASK<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)         (REG>>BIT_NUM)&BIT_MASK

/* Data type declarations */
typedef enum{
    LOW,
    HIGH
}logic_t;

typedef enum{
    OUTPUT,
    INPUT
}direction_t;
typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;
typedef enum{
    PORTC_INDEXPORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;
typedef struct{
    uint8 port : 3;          /* Bit field must be constant integer & @ref port_index_t */ 
    uint8 pin : 3;           /* @ref pin_index_t */
    uint8 directin : 1;      /* @ref direction_t */
    uint8 logic : 1;         /* @ref logic_t     */
}pin_config_t;

/* Function Declarations Section */
#if PORT_PIN_CONFIGRATION
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config,direction_t* direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t* logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_intialize(const pin_config_t* _pin_config);
#endif
#if PORT_COFIGRATION
Std_ReturnType gpio_port_direction_intialize(port_index_t port,uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port,uint8* directionPortStatus);
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port,uint8* logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);
#endif 

#endif	/* HAL_GPIO_H */

