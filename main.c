#include <msp430.h>
#include "libs/leds.h"
#include "libs/sensor.h"
#include "libs/servomotor.h"

int servoPos;

void distFunction(float distance);

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    ledsConfig();   // Configure LEDs
    sensorConfig(); // Configure HC-SR04
    servoConfig(); // Configure the servomotor

    volatile float distance;

    while(1){
        distance = sensorTriggerPulse();    // Measure distance with HC-SR04
        __delay_cycles(5000);   // Wait 50ms to reduce interference between servo and HC-SR04
        distFunction(distance); // Function to position the servomotor and light up LEDs
    }
}

// Function to set LEDs states and servomotor position based on distance read by the HC-SR04
void distFunction(float distance){
    if (distance < 10){
        P1OUT &= ~BIT0;
        P4OUT &= ~BIT7;
        servoPos = (int)distance;
        servoSetPosition(servoPos);
    }
    else if (distance >= 10 && distance < 30){
        P1OUT &= ~BIT0;
        P4OUT |= BIT7;
        servoPos = (int)distance;
        servoSetPosition(servoPos);
    }
    else if (distance >= 30 && distance < 50){
        P1OUT |= BIT0;
        P4OUT &= ~BIT7;
        servoPos = (int)distance;
        servoSetPosition(servoPos);
    }
    else if (distance >= 50){
        P1OUT |= BIT0;
        P4OUT |= BIT7;
        servoPos = (int)distance;
        servoSetPosition(servoPos);
    }
}
