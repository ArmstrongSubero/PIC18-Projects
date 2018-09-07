/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 04_Internal_Interrupt
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0  
 *                
 * Program Description: This Program Allows PIC18F4553 to use a Timer0 interrupt
 *                      to blink an LED
 * 
 * Hardware Description: An LED is connected via a 1k resistor to PIN D0
 *                      
 * Created September 7th, 2018, 4:40 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include <xc.h>
#include "18F4553_STD.h"


// timer 0 interrupt
void interrupt TMR0_ISR(void);

/*******************************************************************************
 * Function: void initMain()
 *
 * Returns: Nothing
 *
 * Description: Contains initializations for main
 ******************************************************************************/
void initMain()
{
    ////////////////////////
    // Configure Pins
    ///////////////////////
    
    // Configure pin D0 as output 
    TRISDbits.TRISD0 = 0;     
    
    ///////////////////////
    /// Configure Timer0
    //////////////////////
    
     // Select timer mode
    T0CONbits.T0CS = 0;
    
    // Assign Timer0 clock to prescaler
    T0CONbits.PSA = 0;
    
    // Set Prescaler to 256
    T0CONbits.T0PS0 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 1;
    
    // Zero Timer
    TMR0 = 0;
     RCONbits.IPEN = 1;
    GIE = 1;
    INTCONbits.PEIE = 1;
    
    // Enable timer0 interrupts and clear interrupt flag
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0; 
}



/*******************************************************************************
 * Function: Main
 *
 * Returns: Nothing
 *
 * Description: Program entry point
 ******************************************************************************/
void main(void)
{
    initMain();
    
    
    while(1)
    {
      // Do nothing
    }

    return;
}

/*******************************************************************************
 * Function: void interrupt isr(void)
 *
 * Returns: Nothing
 *
 * Description: Timer0 interrupt at a rate of 1 second
 ******************************************************************************/

void interrupt TMR0_ISR(void)
{   
    static int count = 0;
    
    // Reset flag after overflow
    INTCONbits.TMR0IF = 0;
    
    TMR0 = 0;
        
    // Increment count
    count++;
    
     // Value = fclk / (4 * 256 * 256 * fout)
     //                                   |-- Frequency out (in Hz)
     //                      |-- Prescaler value
     // Value =  48 000 000 / (262 144)
     // Value =  183.11 for 1 s
               
    // Turn on LED for 1 second on timer overflow
    if (count == 183)
    {
        LATDbits.LATD0 = 1;
        count = 0;
    }
    
    // Else keep LED off
    else 
    {
        LATDbits.LATD0 = 0;
    }  
}

