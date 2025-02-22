#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

#define STATE_BUTTONPRESS 1
#define STATE_BUTTONRELEASE 0

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned int buttonhistory=0;
    unsigned int buttonReleased=1;
    unsigned int i = 0;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired()){
            if (count0 < 6){
                count0++;
            }
            else {
                count0 = 0;
            }
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c

        if (timer1Expired()){
            unsigned char curButton = (checkStatus_BoosterpackS1());
            curButton = curButton >> 1;
            if (curButton) {
               if (buttonReleased) {
                  buttonhistory = buttonhistory << 1;
                  buttonhistory = buttonhistory | curButton;
               }
            }
            else {
               buttonReleased = 1;
            }
        }

        if (fsmBoosterpackButtonS1(buttonhistory)) {
           buttonhistory = 0;
           buttonReleased = 0;
           if (count1 == 6) {
              count1 = 0;
           }
           else {
             count1++;
           }
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.



        // TODO: If a completed, debounced button press has occurred, increment count1.
        /*
        if(i == 8){
            i = 0;
            if (fsmBoosterpackButtonS1(buttonhistory)){
                if (count1 < 6){
                    count1++;
                }
                else {
                    count1=0;
                }
            }
        }
        */
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{

    if (count == 0){
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
    else if (count == 1){
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }

    else if (count == 2){
        turnOn_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
    }
    else if (count == 3){
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();

    }
    else if (count == 4){
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
    }
    else if (count == 5){
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
    }
    else if (count == 6){
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
    }


}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    if (count == 0){
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }
        else if (count == 1){
            turnOff_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }

        else if (count == 2){
            turnOn_BoosterpackLEDRed();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDBlue();
        }
        else if (count == 3){
            turnOff_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDBlue();

        }
        else if (count == 4){
            turnOn_BoosterpackLEDBlue();
            turnOn_BoosterpackLEDRed();
            turnOff_BoosterpackLEDGreen();
        }
        else if (count == 5){
            turnOn_BoosterpackLEDBlue();
            turnOn_BoosterpackLEDGreen();
            turnOff_BoosterpackLEDRed();
        }
        else if (count == 6){
            turnOn_BoosterpackLEDBlue();
            turnOn_BoosterpackLEDGreen();
            turnOn_BoosterpackLEDRed();
        }

}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
   unsigned char stable = 0xFF;
   unsigned char check = buttonhistory & stable;

    if ((buttonhistory & stable) == 0xFF) {
       return true;
    }
    return false;

}
