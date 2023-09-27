/* 
 * File:   application.c
 * Author: Aya farid
 *
 * Created on September 8, 2023, 11:07 PM
 */

#include "application.h"
uint8 str[6];
int main() {
    functionInitialize();
    
    /*
    lcd_send_string_position(&lcd1, "Count : ",1,1);
    */
    while (1) {
        for(int i=0;i<8;i++){
            lcd_send_custom_char_position(&lcd1,1,1,customChar[i],0);
            __delay_ms(200);
        }
        /*
        for(int count=0;count<256;count++){
            lcd_send_number_position(&lcd1,1,1,count);
            __delay_ms(100);
        }
        */
        /*
        for(uint16 count=0;count<65536;count++){
            lcd_convert_uint16_to_string(count,str);
            lcd_send_string_position(&lcd1,str,1,8);
            __delay_ms(250);
        }
         * */
        /*
        //----AYA FARID :)
        //    ------------
        for(int i=5;i<=7;i++) {
            lcd_send_string_position(&lcd1, "AYA FARID :)", 1, i);
            __delay_ms(1000);
            lcd_send_char_data_position(&lcd1,' ',1,i);
        }
        lcd_send_string_position(&lcd1, "            ", 1, 5);
        for(int i=7;i>=5;i--) {
            lcd_send_string_position(&lcd1, "AYA FARID :)", 1, i);
            __delay_ms(1000);
            lcd_send_char_data_position(&lcd1,' ',1,i+11);
        }
        */
    }
}

void functionInitialize() {
    ecu_layer_initialize();
}
