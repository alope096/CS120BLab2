/*	Author: lab
 *  Partner(s) Name: None
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;PORTA = 0xFF;
    DDRB = 0xFF;PORTB = 0x00;
    
    unsigned char garageDoorSensor = 0;
    unsigned char lightSensor = 0;
    unsigned char ledOutput =0;

    /* Insert your solution below */
    while (1) {
        garageDoorSensor = PINA & 0x01; //setting to PA0
        lightSensor = PINA & 0x02; //setting to PA1
        
        if(garageDoorSensor && !lightSensor){
            ledOutput = 0x01;
        }
        else{
            ledOutput = 0x00;
        }
        PORTB = ledOutput;

    }
    return 1;
}
