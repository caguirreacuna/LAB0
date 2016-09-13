/* 
 * File:   timer.c
 * Author: Cesar Aguirre
 *
 * 
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 seconds. Enable its interrupt
    TMR1 = 0;
    PR1 = 39062; // 1 Second
    T1CONbits.TCKPS = 3; // Prescalar 256
    T1CONbits.TCS = 0;
    IEC0bits.T1IE = 1;
    IFS0bits.T1IF = 0;
    IPC1bits.T1IP = 7;
    T1CONbits.ON = 1;
}

void delay()
{
    TMR1 = 1;
    PR1 = 39062; // 1 Second
    T1CONbits.TCKPS = 3; // Prescalar 256
    T1CONbits.TCS = 0;
    T1CONbits.TON = 1; // Start the timer
    while(IFS0bits.T1IF == 0); // Do nothing until the flag goes up
    IFS0bits.T1IF = 0; // Put the flag back down
    T1CONbits.TON = 0; // Turn off the timer
}

