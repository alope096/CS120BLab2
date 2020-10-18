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
    DDRB = 0x00;PORTB = 0xFF;
    DDRC = 0x00;PORTC = 0xFF;
    DDRD = 0xFF;PORTD = 0x00;
    
    unsigned char seatA = 0x00;
    unsigned char seatB = 0x00;
    unsigned char seatC = 0x00;
    unsigned char weight = 0x00;
    int totalweight = 0;
    int average = 0;
    /* Insert your solution below */
    while (1) {
        seatA = PINA & 0xFF;
        seatB = PINB & 0xFF;
        seatC = PINC & 0xFF;
        
        totalweight = seatA + seatB + seatC;
        average = totalweight/3;
        weight = average & 0xFC;

        if (totalweight > 140){
            weight = weight + 0x01;
        }
        if( ((seatA - seatB) > 80) || ((seatC - seatA) > 80)){
            weight = weight + 0x02;
        }
    PORTD = weight; 
    }
    return 1;
}
