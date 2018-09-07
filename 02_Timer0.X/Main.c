/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 02_Counter
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0  
 *                
 * Program Description: This Program Allows PIC18F4553 to use Timer0 to 
 *                      blink an LED
 * 
 * Hardware Description: An LED is connected via a 1k resistor to PIN D0
 *                      
 * Created September 7th, 2018, 3:02 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include <xc.h>
#include "18F4553_STD.h"

// Counter variable
int count = 0;


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
        // When timer overflows TMR0 interrupt flag will be equal to 1
        while (INTCONbits.TMR0IF != 1);
            
        // Reset flag after overflow
        INTCONbits.TMR0IF = 0;
            
        // Increment count
        count++;
            
                                   
        // Value = fclk / (4 * 256 * 256 * fout)
        //                                   |-- Frequency out (in Hz)
        //                      |-- Prescaler value
        // Value =  16 000 000 / (262 144)
        // Value =  183.11 for 1 s
           
            
        // Turn on LED for 1 second on timer overflow
        if (count == 183)
        {
            LATDbits.LATD0= 1;
            count = 0;
        }
        
        // Else turn LED off
        else 
        {
            LATDbits.LATD0= 0;
        }     
    }

    return;
}
