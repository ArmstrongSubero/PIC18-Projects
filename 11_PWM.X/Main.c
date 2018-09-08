/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 11_PWM
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                         
 * Program Description: This Program Allows PIC18F4553 to generate a PWM signal
 *
 * Hardware Description: An LED is connected via a 1k resistor to PIN C2
 *                      
 * Created September 7th, 2018, 1:28 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include "18F4553_STD.h"


/*******************************************************************************
 * Function: Main
 *
 * Returns: Nothing
 *
 * Description: Program entry point
 ******************************************************************************/
void main(void)
{
    // Generate 80 KHz PWM signal
    TRISCbits.TRISC2 = 0;		// Set CCP1 pin as output for PWM out 
    PR2 = 149;		            // Load period value 
    CCPR1L = 50;	            // Load duty cycle value
    T2CON = 0;		            // Timer2 off, no pre-scale
    CCP1CON = 0x0C;	            // Set PWM mode, no decimal
    TMR2 = 0;		            // Clear Timer2
    TMR2ON = 1;		            // Timer2 ON 
    
    while(1)
    {
        // vary duty cycle
        int i;
        for(i = 0; i <= 100; i++)
        {
            CCPR1L = i;
            delay_ms(1000);
        } 
    }

    return;
}
