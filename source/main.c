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
    DDRC = 0xFF;PORTC = 0x00;
    
    unsigned char cntavail = 0;
    unsigned char parkingSpot = 0;

    /* Insert your solution below */
    while (1) {
        parkingSpot = PINA & 0x0F; //setting to PA3 down to PA0
        cntavail = 0;
        if((parkingSpot & 0x01) == 0x01){
            cntavail = cntavail +1;
        }
        else{
            cntavail = cntavail;
        }
        if((parkingSpot & 0x02) == 0x02){
            cntavail = cntavail +1;
        }
        else{
            cntavail = cntavail;
        }
        if((parkingSpot & 0x04) == 0x04){
            cntavail = cntavail +1;
        }
        else{
            cntavail = cntavail;
        }
        if((parkingSpot & 0x08) == 0x08){
            cntavail = cntavail +1;
        }
        else{
            cntavail = cntavail;
        }
        PORTC = cntavail;
    }
    return 1;
}
