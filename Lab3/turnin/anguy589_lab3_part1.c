/*	Author: anguy589
 *  Partner(s) Name: 
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


//from Zybooks Figure 1.12.5
//returns either 1 or 0, depending on what is at each position
unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}

int main(void) {

  //initialize ports
  DDRA = 0x00; PORTA = 0x0FF;
  DDRB = 0x00; PORTB = 0xFF;
  DDRC = 0x00; PORTC = 0x00;

  //temporary variables
  unsigned char tmpA = 0x00;
  unsigned char tmpB = 0x00;

  //misc.
  unsigned char i = 0;
  unsigned char count = 0;

  while(1) {
    tmpA = PINA;
    tmpB = PINB;

    //iterate through each port, adding 1 or 0 to count
    for(i = 0; i < 8; i++) {
        count += GetBit(tmpA, i);
        count += GetBit(tmpB, i);

      


    }

    PORTC = count;

}

return 1;
}
