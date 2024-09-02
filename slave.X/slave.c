#include <avr/io.h>
#include <util/delay.h>  // Include delay library for delay functions

void SPI_SlaveInit(void) {
    // Set MISO as Output
    DDRB = (1<<DDB4);
    // Enable SPI
    SPCR = (1<<SPE);
}

char SPI_SlaveReceive(void) {
    // Wait for reception complete
    while(!(SPSR & (1<<SPIF)));
    // Return data register
    return SPDR;
}

int main(void) {
    // Initialize SPI as slave
    SPI_SlaveInit();
    // Receive data
    DDRD |= 1<< DDD0;
    while(1) {
        // Main loop
            char receivedData = SPI_SlaveReceive();  // Example reception
            if (receivedData == 'c'){    PORTD |= 1<<PORTD0 ; };
            _delay_ms(1000);
    }
}