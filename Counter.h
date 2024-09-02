
#define	XC_HEADER_TEMPLATE_H
#include <avr/io.h>
#include <avr/interrupt.h>
#include <xc.h> // include processor files - each processor file is guarded.  
uint16_t counter = 0; // 16-bit counter variable

void Timer0_Counter_Init(void) {
    // Configure PD7 as input
    DDRD &= ~(1 << DDD4); // Set PD7 (T2) as input
    
    // Enable pull-up resistor on PD7 if needed
    PORTD |= (1 << PD4);
    
    // Set Timer0 to use external clock source on T0 pin (PD4)
    // Use external clock source on the rising edge
    TCCR0B |= (1 << CS02) | (1 << CS01) | (1 << CS00) & ~(1 << WGM00) & ~(1 << WGM01);

    // Enable Timer2 overflow interrupt (if you need an interrupt on overflow)
    TIMSK0 |= (1 << TOIE0);
    
    // Enable global interrupts
    sei();
    TCNT0=0;
}


// Timer2 Compare Match A interrupt service routine
ISR(TIMER0_COMPA_vect) {
    counter++;  // Increment the counter every second
}

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */



