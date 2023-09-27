/* 
 * File:   ecu_clcd_config.h
 * Author: Aya farid
 *
 * Created on September 27, 2023, 4:09 PM
 */
#include "ecu_clcd_init.h"
void *memset(void *str, int c, size_t n){
    unsigned char* tempStr=str;
    if(tempStr!=NULL){
        while(n--){
            *tempStr++=(char)c;
        }
    }else{
        return NULL;
    }
    return str;
}
static Std_ReturnType lcd_send_4_Bits(const char_lcd_t* lcd_obj,uint8 data_command){
    Std_ReturnType Local_Status=E_NOT_OK;
    for(int i=0;i<4;i++){
        Local_Status=gpio_pin_write_logic(&(lcd_obj->lcd_data[i]),(data_command>>i)&0x01);
    }
    return Local_Status;
}
static Std_ReturnType lcd_send_enable_sginal(const char_lcd_t* lcd){
    Std_ReturnType Local_Status=E_NOT_OK;
    Local_Status=gpio_pin_write_logic(&(lcd->lcd_en),HIGH);
    __delay_us(5);
    Local_Status=gpio_pin_write_logic(&(lcd->lcd_en),LOW);
    return Local_Status;
}
static Std_ReturnType lcd_set_cusor_postion(const char_lcd_t* lcd_obj,uint8 row,uint8 column){
    Std_ReturnType Local_Status=E_NOT_OK;
    column--;
    switch(row){
        case ROW1 : Local_Status = lcd_send_command(lcd_obj, (0x80 + column)); break; /* 0x00 -> Decimal : 0  */
        case ROW2 : Local_Status = lcd_send_command(lcd_obj, (0xc0 + column)); break; /* 0x40 -> Decimal : 64 */
        case ROW3 : Local_Status = lcd_send_command(lcd_obj, (0x94 + column)); break; /* 0x14 -> Decimal : 20 */
        case ROW4 : Local_Status = lcd_send_command(lcd_obj, (0xd4 + column)); break; /* 0x54 -> Decimal : 84 */
        default : ;
    }
    return Local_Status;
}
/**
 * @breif function to initialize LCD
 * @param pointer to LCD object (lcd_obj)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_initalize(const char_lcd_t* lcd_obj){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=gpio_pin_intialize(&lcd_obj->lcd_rs);
        Local_Status=gpio_pin_intialize(&lcd_obj->lcd_en);
        for(int Pin_counter=0;Pin_counter<LCD_DATA_PINS_NUM;Pin_counter++){
            Local_Status=gpio_pin_intialize(&lcd_obj->lcd_data[Pin_counter]);
        }
        __delay_ms(20);
        Local_Status=lcd_send_command(lcd_obj,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        Local_Status=lcd_send_command(lcd_obj,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        
        Local_Status=lcd_send_command(lcd_obj,_LCD_CLEAR);
        Local_Status=lcd_send_command(lcd_obj,_LCD_RETRUN_HOME);
        Local_Status=lcd_send_command(lcd_obj,_LCD_ENTERY_MODE_INC_SHIFT_OFF);
        Local_Status=lcd_send_command(lcd_obj,_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
#if CONFIG_LCD_BIT_STATUS==LCD_FOUR_BIT_MODE
        Local_Status=lcd_send_command(&lcd_obj,_LCD_4BIT_MODE_2_LINE);
#elif CONFIG_LCD_BIT_STATUS==LCD_EIGHT_BIT_MODE
        Local_Status=lcd_send_command(&lcd_obj,_LCD_8BIT_MODE_2_LINE);
#endif
        Local_Status=lcd_send_command(&lcd_obj,_LCD_DDRAM_START);
    }
    return Local_Status;
}
/**
 * @breif function to send command
 * @param pointer to LCD object (lcd_obj)
 * @param the command to be send (command)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_command(const char_lcd_t* lcd_obj,uint8 command){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=gpio_pin_write_logic(&(lcd_obj->lcd_rs),LOW);
#if CONFIG_LCD_BIT_STATUS==LCD_FOUR_BIT_MODE
        Local_Status=lcd_send_4_Bits(lcd_obj,command>>4);
        Local_Status=lcd_send_enable_sginal(lcd_obj);
        Local_Status=lcd_send_4_Bits(lcd_obj,command);
        Local_Status=lcd_send_enable_sginal(lcd_obj);
#elif CONFIG_LCD_BIT_STATUS==LCD_EIGHT_BIT_MODE
        for(int i=0;i<8;i++){
            Local_Status=gpio_pin_write_logic(&(lcd_obj->lcd_data[i]),(command>>i)&(0x01));
        }
        Local_Status=lcd_send_enable_sginal(lcd_obj);
#endif
    }
    return Local_Status;
}
/**
 * @breif function to send an character
 * @param pointer to LCD object (lcd_obj)
 * @param the data to be send (data)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_char_data(const char_lcd_t* lcd_obj,uint8 data){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
#if CONFIG_LCD_BIT_STATUS==LCD_FOUR_BIT_MODE
        Local_Status=gpio_pin_write_logic(&(lcd_obj->lcd_rs),HIGH);
        Local_Status=lcd_send_4_Bits(lcd_obj,data>>4);
        Local_Status=lcd_send_enable_sginal(lcd_obj);
        Local_Status=lcd_send_4_Bits(lcd_obj,data);
        Local_Status=lcd_send_enable_sginal(lcd_obj);
#elif CONFIG_LCD_BIT_STATUS==LCD_EIGHT_BIT_MODE
        for(int i=0;i<8;i++){
            Local_Status=gpio_pin_write_logic(&(lcd_obj->lcd_data[i]),(command>>i)&(0x01));
        }
        Local_Status=lcd_send_enable_sginal(lcd_obj);
#endif
    }
    return Local_Status;
}
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
Std_ReturnType lcd_send_char_data_position(const char_lcd_t* lcd_obj,uint8 data,uint8 row,uint8 column){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=lcd_set_cusor_postion(lcd_obj,row,column);
        Local_Status=lcd_send_char_data(lcd_obj,data);
    }
    return Local_Status;
}
/**
 * @breif function to send string to LCD
 * @param pointer to LCD object (lcd_obj)
 * @param poiter to char array (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_string(const char_lcd_t* lcd_obj,uint8* str){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL || str==NULL){
        Local_Status=E_NOT_OK;
    }else{
        while(*str){
            Local_Status=lcd_send_char_data(lcd_obj,*str);
            str++;
        }
    }
    return Local_Status;
}
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
Std_ReturnType lcd_send_string_position(const char_lcd_t* lcd_obj,uint8* str,uint8 row,uint8 column){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL || str==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=lcd_set_cusor_postion(lcd_obj,row,column);
        while(*str){
            Local_Status=lcd_send_char_data(lcd_obj,*str);
            str++;
        }
    }
    return Local_Status;
}
/**
 * @breif function to send custom character to LCD
 * @param pointer to LCD object (lcd_obj)
 * @param the array pattern of character to display (chr)
 * @param the position of the character on CGRAM (mem_pos)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_custom_char(const char_lcd_t* lcd_obj,const uint8 chr[],uint8 mem_pos){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=lcd_send_command(lcd_obj,_LCD_CGROM_START+(mem_pos*8));
        for(int i=0;i<8;i++){
            Local_Status=lcd_send_char_data(lcd_obj,chr[i]);
        }
        Local_Status=lcd_send_char_data(lcd_obj,mem_pos);
    }
    return Local_Status;
}
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
Std_ReturnType lcd_send_custom_char_position(const char_lcd_t* lcd_obj,uint8 row,uint8 column,const uint8 chr[],uint8 mem_pos){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=lcd_send_command(lcd_obj,_LCD_CGROM_START+(mem_pos*8));
        for(int i=0;i<8;i++){
            Local_Status=lcd_send_char_data(lcd_obj,chr[i]);
        }
        Local_Status=lcd_send_char_data_position(lcd_obj,mem_pos,row,column);
    }
    return Local_Status;
}
/**
 * function to send number to LCD
 * @param pointer to LCD object (lcd_obj)
 * @param the number i would display it to LCD (num)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_send_number(const char_lcd_t* lcd_obj,uint32 num){
    Std_ReturnType Local_Status=E_NOT_OK;
    uint32 arr[11];
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=lcd_convert_uint32_to_string(num,arr);
        Local_Status=lcd_send_string(lcd_obj,arr);
    }
    return Local_Status;
}
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
Std_ReturnType lcd_send_number_position(const char_lcd_t* lcd_obj,uint8 row,uint8 column,uint32 num){
    Std_ReturnType Local_Status=E_NOT_OK;
    uint32 arr[11];
    if(lcd_obj==NULL){
        Local_Status=E_NOT_OK;
    }else{
        Local_Status=lcd_convert_uint32_to_string(num,arr);
        Local_Status=lcd_send_string_position(lcd_obj,arr,row,column);
    }
    return Local_Status;
}
/**
 * @breif function to convert number to char array
 * @param the number to be converted (value)
 * @param poiter to char array (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_convert_uint8_to_string(uint8 value,uint8* str){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(str==NULL){
        Local_Status=E_NOT_OK;
    }else{
        memset(str,'\0',4);
        sprintf(str,"%i",value);
    }
    return Local_Status;
}
/**
 * 
 * @breif function to convert number to char array
 * @param poiter to char (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_convert_uint16_to_string(uint16 value,uint8* str){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(str==NULL){
        Local_Status=E_NOT_OK;
    }else{
        memset(str,'\0',6);
        sprintf(str,"%i",value);
    }
    return Local_Status;
}
/**
 * @breif function to convert number to char array
 * @param the number to be converted (value)
 * @param poiter to char (str)
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType lcd_convert_uint32_to_string(uint32 value,uint8* str){
    Std_ReturnType Local_Status=E_NOT_OK;
    if(str==NULL){
        Local_Status=E_NOT_OK;
    }else{
        memset(str,'\0',11);
        sprintf(str,"%i",value);
    }
    return Local_Status;
}
