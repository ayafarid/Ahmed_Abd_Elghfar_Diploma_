/* 
 * File:   ecu_clcd_init.h
 * Author: Aya farid
 *
 * Created on September 27, 2023, 4:08 PM
 */

#ifndef ECU_CLCD_INIT_H
#define	ECU_CLCD_INIT_H
/* Includes Section */
#include "ecu_clcd_config.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Macros Declarations Section */
#define _LCD_CLEAR                                   0x01
#define _LCD_RETRUN_HOME                             0x02
#define _LCD_ENTERY_MODE_DEC_SHIFT_OFF               0x04
#define _LCD_ENTERY_MODE_DEC_SHIFT_ON                0x05
#define _LCD_ENTERY_MODE_INC_SHIFT_OFF               0x06
#define _LCD_ENTERY_MODE_INC_SHIFT_ON                0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT                  0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT                 0x14
#define _LCD_DISPLAY_SHIFT_LEFT                      0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                     0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF     0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON      0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF     0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON       0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF                  0x08
#define _LCD_8BIT_MODE_2_LINE                        0x38
#define _LCD_4BIT_MODE_2_LINE                        0x28

#define _LCD_CGROM_START                             0x40
#define _LCD_DDRAM_START                             0x80

#define ROW1          1
#define ROW2          2
#define ROW3          3
#define ROW4          4

#define LCD_FOUR_BIT_MODE             4
#define LCD_EIGHT_BIT_MODE            8

#if CONFIG_LCD_BIT_STATUS==LCD_FOUR_BIT_MODE
#define LCD_DATA_PINS_NUM      4
#elif CONFIG_LCD_BIT_STATUS==LCD_EIGHT_BIT_MODE
#define LCD_DATA_PINS_NUM      8
#endif

/* Function Like Macros Declarations Section */

/* Data Types Declarations */
typedef struct{
    pin_config_t      lcd_rs;
    pin_config_t      lcd_en;
    pin_config_t      lcd_data[LCD_DATA_PINS_NUM];
}char_lcd_t;
/* Function Declarations Section */

/**
 * @breif function to initialize LCD
 * @param pointer to LCD object (lcd_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_initalize(const char_lcd_t* lcd_obj);
/**
 * @breif function to send command
 * @param pointer to LCD object (lcd_obj)
 * @param the command to be send (command)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_command(const char_lcd_t* lcd_obj,uint8 command);
/**
 * @breif function to send an character
 * @param pointer to LCD object (lcd_obj)
 * @param the data to be send (data)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_char_data(const char_lcd_t* lcd_obj,uint8 data);
/**
 * @breif function to display data at a certain position
 * @param pointer to LCD object (lcd_obj)
 * @param the data to be send (data)
 * @param the row number to display at (row)
 * @param the column number to display at (column)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_char_data_position(const char_lcd_t* lcd_obj,uint8 data,uint8 row,uint8 column);
/**
 * @breif function to send string to LCD
 * @param pointer to LCD object (lcd_obj)
 * @param poiter to char array (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_string(const char_lcd_t* lcd_obj,uint8* str);
/**
 * @breif function to send string 
 * @param pointer to LCD object (lcd_obj)
 * @param poiter to char array (str)
 * @param the row number to display at (row)
 * @param the column number to display at (column)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_string_position(const char_lcd_t* lcd_obj,uint8* str,uint8 row,uint8 column);
/**
 * @breif function to send custom character to LCD
 * @param pointer to LCD object (lcd_obj)
 * @param the array pattern of character to display (chr)
 * @param the position of the character on CGRAM (mem_pos)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_custom_char(const char_lcd_t* lcd_obj,const uint8 chr[],uint8 mem_pos);
/**
 * @breif function to send custom character to LCD at a certain position
 * @param pointer to LCD object (lcd_obj)
 * @param the row number to display at (row)
 * @param the column number to display at (column)
 * @param the array pattern of character to display (chr)
 * @param the position of the character on CGRAM (mem_pos)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_custom_char_position(const char_lcd_t* lcd_obj,uint8 row,uint8 column,const uint8 chr[],uint8 mem_pos);
/**
 * function to send number to LCD
 * @param pointer to LCD object (lcd_obj)
 * @param the number i would display it to LCD (num)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_number(const char_lcd_t* lcd_obj,uint32 num);
/**
 * function to send number to LCD at position
 * @param pointer to LCD object (lcd_obj)
 * @param the row number to display at (row)
 * @param the column number to display at (column)
 * @param the number i would display it to LCD (num)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_number_position(const char_lcd_t* lcd_obj,uint8 row,uint8 column,uint32 num);
/**
 * @breif function to convert number to char array
 * @param the number to be converted (value)
 * @param poiter to char array (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_convert_uint8_to_string(uint8 value,uint8* str);
/**
 * 
 * @breif function to convert number to char array
 * @param poiter to char (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_convert_uint16_to_string(uint16 value,uint8* str);
/**
 * @breif function to convert number to char array
 * @param the number to be converted (value)
 * @param poiter to char (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_convert_uint32_to_string(uint32 value,uint8* str);
#endif	/* ECU_CLCD_INIT_H */

