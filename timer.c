#include "timer.h"

volatile uint16_t encoder_count = 0;

// Timer0 for PWM
void Timer_init_PWM() {
    // Set PB2 as output (OC0)
    DDRB |= (1 << PB2);
    
    // Fast PWM, non-inverted
    TCCR0 |= (1 << WGM00) | (1 << WGM01) | 
             (1 << COM01) | (1 << CS00); // Prescaler = 1
}

void Timer_set_PWM_duty(uint8_t duty) {
    OCR0 = duty; // duty cycle (0-255)
}

// Timer1 for Encoder (Example)
void Timer_init_encoder() {
    // Configure Timer1 for external interrupts if needed
    // For simplicity, assuming external interrupts INT0 and INT1 handle encoder
    // Initialize Timer1 for timekeeping if necessary
}

// ISR for encoder pulses (External Interrupts INT0 and INT1)
ISR(INT0_vect) {
    encoder_count++;
}

ISR(INT1_vect) {
    encoder_count++;
}

uint16_t Timer_get_encoder_count() {
    uint16_t count;
    cli(); // Disable interrupts
    count = encoder_count;
    sei(); // Enable interrupts
    return count;
}

void Timer_reset_encoder() {
    cli();
    encoder_count = 0;
    sei();
}
