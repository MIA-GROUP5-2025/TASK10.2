#include <xc.h>
#include <stdio.h>
#include "ADC_turtlebot.h"

long value;
int main(void) {
    DDRD=0xFF;
    
    while (1) {
        ADC_init();
        value = read_ADC(0);
        PORTD=value;
        
    }
}