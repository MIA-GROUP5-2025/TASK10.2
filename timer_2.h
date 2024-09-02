#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  


#include <avr/io.h>
#include <avr/interrupt.h>

uint16_t overflow_count = 0; // Counter for Timer2 overflows

void Timer2_Init(void) {
    // Set Timer2 to Normal mode (overflow mode)
    TCCR2A = 0; // WGM21 = 0, WGM20 = 0 for Normal mode
    
    // Set prescaler to 1024
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // CS22:CS20 = 0b111 for prescaler 1024
    
    // Enable Timer2 overflow interrupt
    TIMSK2 |= (1 << TOIE2); // Enable overflow interrupt
    
    // Enable global interrupts
    sei();
}

// Timer2 Overflow Interrupt Service Routine
ISR(TIMER2_OVF_vect) {
    overflow_count++; // Increment overflow counter
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


