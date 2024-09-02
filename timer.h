
#include <stdint.h>
#include <inttypes.h>

#include <avr/io.h>
#include <avr/interrupt.h>



void Timer_init_PWM() {
    // Set PB2 as output (OC0)
    DDRD |= (1 << DDD6);
    
    // Fast PWM, non-inverted
    TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);  // Prescaler = 1
    TCCR0B |= (1 << CS00);
    TCNT0=0;

}

void Timer_set_PWM_duty(uint8_t duty) {
    OCR0A = duty; // Set duty cycle (0-255)
}


void Timer_reset_encoder() {
    cli();
  
    sei();
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



