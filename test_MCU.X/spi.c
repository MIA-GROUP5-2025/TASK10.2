/*
 * File:   spi.c
 * Author: GGsya
 *
 * Created on September 2, 2024, 11:36 AM
 */
#define SS_PIN PORTB2
#include <xc.h>
#include <util/delay.h>  // Include delay library for delay functions

  void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DDRB = (1<<DDB3)|(1<<DDB5)|(1<<DDB2);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

}
  
void SPI_MasterTransmit(char cData)
{
 PORTB &= ~(1<<SS_PIN);
/* Start transmission */
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));

 PORTB |= (1<<SS_PIN);
}

void main(void) {
    SPI_MasterInit();
    DDRD |= 1<< DDD0;
    PORTD |= 1<<PORTD0;

    // Transmit data repeatedly
    while(1) {
        SPI_MasterTransmit('d');
        _delay_ms(1000);

    }

}
