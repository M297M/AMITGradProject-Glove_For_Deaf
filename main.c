/*
 * File:   main.c
 * Author: Mayar
 *
 * Created on August 22, 2022, 11:39 PM
 */

#include <avr/io.h>
#include "config.h"
#include "ADC.h"
#include "I_O.h"
#include "LCD_4bit.h"
#include "Result.h"
#include <avr/interrupt.h>

int main() {
    init_LCD_4bit();
    init_ADC(AREF, PRE_128);
    int Results[5];

    while (1) {

        for (int ChannelNumber = 0; ChannelNumber < 5; ChannelNumber++) {
            ///Sweeping 5 Channels For Readings
            ADC_Channel_Select(ChannelNumber);
            ADC_StartConv();
            ///MAPPING POT TO FINGERS MOVEMENTS(4v FOR FLAT POSITION ,2v FOR 90BEND & 3v FOR 45BEND)
            Results[ChannelNumber] = ADC_read()*.00488;
        }

        LCD_CLEAR_4bit();
        Print_Result(Results);
        _delay_ms(300);
     

    }

}
