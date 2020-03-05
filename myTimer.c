/*
 * myTimer.c
 *
 *  Created on:
 *      Author:
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"

// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count.
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{

    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule(timer, preScaler,TIMER32_32BIT, TIMER32_PERIODIC_MODE);

    // For the specified timer, pass the count value.
    Timer32_setCount(TIMER32_0_BASE, count);

    // For the specified timer, configure the timer to repeat once it elapses.
    Timer32_startTimer(TIMER32_0_BASE, true);


}

// TODO: Write a function that indicates whether Timer0 has expired.
// You have been given a such a function in the lecture slides.
bool timer0Expired(void)
{
    unsigned int currentSnap = Timer32_getValue(TIMER32_0_BASE);
    if (currentSnap == 0){
        Timer32_setCount(TIMER32_0_BASE, 3000000);
        Timer32_startTimer(TIMER32_0_BASE, true);
        return true;

    }
    return false;

}

// TODO: Write a function that indicates whether Timer1 has expired.
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired(void)
{
    unsigned int currentSnap = Timer32_getValue(TIMER32_1_BASE);
        if (currentSnap == 0){
            Timer32_setCount(TIMER32_1_BASE, 3000);
            Timer32_startTimer(TIMER32_1_BASE, true);
            return true;

        }
        return false;
}
