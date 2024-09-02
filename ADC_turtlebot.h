
#define	XC_HEADER_TEMPLATE_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <avr/io.h>

//#define ADC0() (ADMUX=(1<<REFS0))
//#define ADC1() (ADCSRA=(1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));

 void ADC_init() {
    // Set reference voltage to AVcc (5V) and select ADC0 channel
    ADMUX = (1 << REFS0);  // REFS0 = 1 (AVcc with external capacitor at AREF pin)

    // Enable ADC, set prescaler to 128 (for 16MHz clock, ADC frequency = 16MHz/128 = 125kHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Start ADC Conversion
int read_ADC (int channel) {
   
    channel &=0b00000111; //remove gain bit and prepare to choose  channel
    
    ADMUX = (ADMUX & 0xF8 |channel);  //0xf8  means F for the 4 MSB to be unchanged and  1000 for the 4 LSB 
    // Start the conversion
    ADCSRA |= (1 << ADSC);
    
    // Wait for the conversion to complete (ADSC becomes '0' when complete)
    while (ADCSRA & (1 << ADSC));

    // Read and return the ADC value
    return (ADCL);
}
//uint16_t read_ADC(uint8_t channel) {
//    // Select ADC channel, clearing the previous channel selection
//    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
//    
//    // Start the conversion
//    ADCSRA |= (1 << ADSC);
//    
//    // Wait for the conversion to complete (ADSC becomes '0' when complete)
//    while (ADCSRA & (1 << ADSC));
//
//    // Read and return the ADC value
//    return (ADCL);
//}

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


