/*
 * File:   maincode.c
 * Author: Lenovo
 *
 * Created on September 2, 2024, 12:13 AM
 */



#include <xc.h>
#include "Myheader.h"

void main(void) {
    
    //Declaring both INT0 , INT1 with initial value HIGH , preparing to fall edge interrupt
    
    DDRD &= ~(1<<DDD2);
    PORTD |= 1<<PORTD2 ;
    DDRD &= ~(1<<DDD3); 
    PORTD |= 1<<PORTD3 ; 
    
    cli();
    
    //fall edge mode on INT0 and INT1
    
    EICRA |= (1 << ISC01);  // Set ISC01 to high (1)
    EICRA &= ~(1 << ISC00); // Set ISC00 to low (0)

    EICRA |= (1 << ISC11);  // Set ISC11 to high (1)
    EICRA &= ~(1 << ISC10); // Set ISC10 to low (0)

    
    // enabling interrupt on INT0 and INT1 
    
    EIMSK |= 1<< INT0 ;
    EIMSK |= 1<< INT1 ;
    sei();
    
    while (1) {
        
    }
}

ISR(INT0_vect){
    // what will happen when you make INT0 low
}

ISR(INT1_vect){
    // what will happen when you make INT1 low
}
