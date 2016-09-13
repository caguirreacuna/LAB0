/* 
 * File:   main.c
 * Author: Cesar Aguirre
 * Description: lab 0.
 * Created on September 5, 2016, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"
#include "switch.h"



typedef enum stateTypeEnum {
    LED1,
    LED2,
    LED3
} stateType;

volatile stateType state=LED1;
volatile int led = 1;

int main() {
    SYSTEMConfigPerformance(10000000); //Configures low-level system parameters for 10 MHz clock
    enableInterrupts(); //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
    
    /*-----------------------PART 1----------------------------*/
        while (1) {
            switch (state) {
                case LED1:
                    turnOnLED(1); //Turn on LED
                    state = LED2;
                    delay();
                    break;
                case LED2:
                    turnOnLED(2);
                    state = LED3;
                    delay();
                    break;
                case LED3:
                    turnOnLED(3);
                    state = LED1;
                    delay();
                    break;
            }
        }
        return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt(void) {
    IFS1bits.CNDIF = 0; //put down the flag
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt(void) {
    IFS0bits.T1IF = 0; //put down the flag
}
    
