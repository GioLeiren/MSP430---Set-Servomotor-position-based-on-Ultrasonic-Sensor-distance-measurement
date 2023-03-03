#include <msp430.h>

void servoConfig(void) {
    // Initialize timer
    TA0CCR0 = 20000 - 1; // Set PWM period
    TA0CCTL1 = OUTMOD_7; // Set output mode to reset/set
    TA0CCR1 = 600; // Set initial duty cycle
    TA0CTL = TASSEL_2 | MC_1; // Select SMCLK as clock source and set to up mode

    // Configure PWM pin as output
    P1DIR |= BIT2;
    P1SEL |= BIT2;
}

void servoSetPosition(unsigned int position) {
    // Calculate the duty cycle for the desired position
    unsigned int duty_cycle = 600 + (2400 - 600) * position / 10;

    // Update the duty cycle
    TA0CCR1 = duty_cycle;
}
