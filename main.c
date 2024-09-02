#include "ADC_turtlebot.h"
#include "Interrupt.h"
#include "SPI.h"
#include "timer.h"
#include "Counter.h"
#include <xc.h>
#include "timer_2.h"
#include <util/delay.h>  // Include delay library for delay functions

void main(void) {
     // Initialization
 
      ADC_init();
    EXT_INT_init();  // External interrupt initialization
    Timer_init_PWM();
    Timer2_Init();
    SPI_MasterInit();
    
    int pot_value;
//    short motor_speed;

    while (1) {
        // Read potentiometer value
        pot_value = read_ADC(0);  // Assuming potentiometer is connected to ADC0
        
        // Set PWM duty cycle based on potentiometer value
        Timer_set_PWM_duty( pot_value );  // Scale 10-bit ADC to 8-bit PWM
         


         // Check if enough overflows have occurred for 1 second (approx. 31 overflows)
         if (overflow_count >= 31) {
        
        overflow_count = 0;  // Reset overflow counter
         //             *60 (second to mins) /3 because 3 ppr =20 
         SPI_MasterTransmit(20*encoder_count);
        encoder_count = 0;
            }
        // Calculate motor speed (RPM) based on encoder count
       // motor_speed = calculate_RPM(Timer_get_encoder_count());
        
        // Send motor speed to SPI debugger
        //SPI_MasterTransmit((motor_speed >> 8) & 0xFF);  // Send high byte
        //SPI_MasterTransmit(motor_speed & 0xFF);         // Send low byte
        _delay_ms(50);  // Delay for stabilization, adjust as needed
    }
}

short calculate_RPM(short pulses) {
    return (pulses * 60);
}

//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>  // For delay functions
//
//// Global variable to keep track of encoder counts
//volatile uint16_t encoder_count = 0;
//
//// Function prototypes
//void ADC_init(void);
//int read_ADC(int channel);
//void EXT_INT_init(void);
//void Timer_init_PWM(void);
//void Timer_set_PWM_duty(uint8_t duty);
//uint16_t Timer_get_encoder_count(void);
//void Timer_reset_encoder(void);
//void SPI_SlaveInit(void);
//void SPI_SendData(char data);
//uint16_t calculate_RPM(uint16_t pulses);
//
//int main(void) {
//    // Initialization
//    ADC_init();
//    EXT_INT_init();
//    Timer_init_PWM();
//    SPI_SlaveInit();
//    
//    uint16_t pot_value;
//    uint16_t motor_speed;
//
//    while (1) {
//        // Read potentiometer value
//        pot_value = read_ADC(0);  // Assuming potentiometer is connected to ADC0
//        
//        // Set PWM duty cycle based on potentiometer value
//        Timer_set_PWM_duty(pot_value >> 2);  // Scale 10-bit ADC to 8-bit PWM
//        
//        // Calculate motor speed (RPM) based on encoder count
//        motor_speed = calculate_RPM(Timer_get_encoder_count());
//        
//        // Send motor speed to SPI debugger
//        SPI_SendData((motor_speed >> 8) & 0xFF);  // Send high byte
//        SPI_SendData(motor_speed & 0xFF);         // Send low byte
//        
//        Timer_reset_encoder();  // Reset encoder count for next cycle
//        _delay_ms(100);  // Delay for stabilization, adjust as needed
//    }
//}
//
//// ADC initialization
//void ADC_init() {
//    // Set reference voltage to AVcc (5V) and select ADC0 channel
//    ADMUX = (1 << REFS0);  // REFS0 = 1 (AVcc with external capacitor at AREF pin)
//
//    // Enable ADC, set prescaler to 128 (for 16MHz clock, ADC frequency = 16MHz/128 = 125kHz)
//    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
//}
//
//// Start ADC Conversion
//int read_ADC(int channel) {
//    channel &= 0b00000111;  // Limit channel to 0-7
//    ADMUX = (ADMUX & 0xF8) | channel;  // Set the channel
//    ADCSRA |= (1 << ADSC);  // Start conversion
//    
//    // Wait for conversion to complete
//    while (ADCSRA & (1 << ADSC));
//    
//    // Return ADC value
//    return ADC;
//}
//
//// External Interrupt initialization
//void EXT_INT_init() {
//    DDRD &= ~(1 << DDD2);  // Clear PD2 (INT0) pin
//    PORTD |= (1 << PORTD2); // Enable pull-up on PD2
//    
//    DDRD &= ~(1 << DDD3);  // Clear PD3 (INT1) pin
//    PORTD |= (1 << PORTD3); // Enable pull-up on PD3
//    
//    cli(); // Disable global interrupts
//    
//    // Set INT0 and INT1 to trigger on falling edge
//    EICRA |= (1 << ISC01);
//    EICRA &= ~(1 << ISC00);
//    EICRA |= (1 << ISC11);
//    EICRA &= ~(1 << ISC10);
//    
//    // Enable INT0 and INT1
//    EIMSK |= (1 << INT0) | (1 << INT1);
//    
//    sei(); // Enable global interrupts
//}
//
//// ISR for encoder pulses (External Interrupts INT0 and INT1)
//ISR(INT0_vect) {
//    encoder_count++;
//}
//
//ISR(INT1_vect) {
//    encoder_count++;
//}
//
//// Timer0 for PWM
//void Timer_init_PWM() {
//    // Set PB2 as output (OC0)
//    DDRB |= (1 << PB2);
//    
//    // Fast PWM, non-inverted
//    TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << CS00); // Prescaler = 1
//}
//
//void Timer_set_PWM_duty(uint8_t duty) {
//    OCR0A = duty; // Set duty cycle (0-255)
//}
//
//// Timer functions for encoder
//uint16_t Timer_get_encoder_count() {
//    uint16_t count;
//    cli(); // Disable interrupts
//    count = encoder_count;
//    sei(); // Enable interrupts
//    return count;
//}
//
//void Timer_reset_encoder() {
//    cli();
//    encoder_count = 0;
//    sei();
//}
//
//// SPI initialization
//void SPI_SlaveInit(void) {
//    // Set MISO as Output
//    DDRB = (1 << DDB4);
//    // Enable SPI
//    SPCR = (1 << SPE);
//}
//
//// Send data over SPI
//void SPI_SendData(char data) {
//    SPDR = data;
//    while (!(SPSR & (1 << SPIF))); // Wait until transmission is complete
//}
//
//// Calculate RPM based on encoder pulses
//#define PULSES_PER_REV 20  // Example: 20 pulses per revolution
//
//uint16_t calculate_RPM(uint16_t pulses) {
//    return (pulses * 60) / PULSES_PER_REV;
//}


