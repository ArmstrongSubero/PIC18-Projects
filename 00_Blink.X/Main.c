/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 00_Blink
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 *                
 * Program Description: This Program Allows PIC18F4553 to blink an LED at 
 *                      50% duty cycle
 * 
 * Hardware Description: An LED is connected via a 1k resistor to PIN D0
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
    // Configure pin D0 as output 
    TRISDbits.TRISD0 = 0;     
    
    while(1)
    {
        // Toggle PIND0
        LATDbits.LATD0 = !LATDbits.LATD0;
        
        // Delay 500 ms
        delay_ms(500);
    }

    return;
}
