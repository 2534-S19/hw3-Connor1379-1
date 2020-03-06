/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"



// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
#define LED1 BIT0
#define LED2RED BIT0
#define LED2GREEN BIT1
#define LED2BLUE BIT2
#define BLEDRED BIT6
#define BLEDGREEN BIT4
#define BLEDBLUE BIT6
#define L1 BIT1
#define L2 BIT4
#define B1 BIT1
#define B2 BIT5


void initGPIO()
{
    // Launchpad S1
    P1DIR |= L1;
    P1REN = P1REN | L1;
    P1OUT |= L1;
    P1DIR = P1DIR & ~L1;
    // Launchpad S2
    P1DIR |= L2;
    P1REN |= L2;
    P1OUT |= L2;
    P1DIR = P1DIR & ~L2;
    // Boosterpack S1
    P5DIR |= B1;
    P5OUT |= B1;
    P5REN |= B1;
    P5DIR = P5DIR & ~B1;
    // Boosterpack S2
    P3DIR |= B2;
    P3OUT |= B2;
    P3REN |= B2;
    P3DIR = P3DIR & ~B2;
    // Launchpad LED1
    P1DIR |= LED1;

    // Launchpad LED2 Red
    P2DIR |= LED2RED;
    // Launchpad LED2 Green
    P2DIR |= LED2GREEN;
    // Launchpad LED2 Blue
    P2DIR |= LED2BLUE;
    // Boosterpack LED Red
    P2DIR |= BLEDRED;
    // Boosterpack LED Green
    P2DIR |= BLEDGREEN;
    // Boosterpack LED Blue
    P5DIR |= BLEDBLUE;

    // Turn off all LEDs at the start.
    P1OUT = P1OUT & ~LED1;
    P2OUT = P2OUT & ~LED2RED;
    P2OUT = P2OUT & ~LED2GREEN;
    P2OUT = P2OUT & ~LED2BLUE;
    P2OUT = P2OUT & ~BLEDRED;
    P2OUT = P2OUT & ~BLEDGREEN;
    P5OUT = P5OUT & ~BLEDBLUE;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ~P1IN & L1;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ~P1IN & L2;
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ~P5IN & B1;

}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ~P3IN & B2;
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT= P2OUT | LED2RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LED2RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT= P2OUT | LED2GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LED2GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LED2BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LED2BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BLEDRED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BLEDRED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BLEDGREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BLEDGREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BLEDBLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BLEDBLUE;
}
