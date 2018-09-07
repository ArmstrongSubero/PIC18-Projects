/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 01_Switch
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 *                
 * Program Description: This Program Allows PIC18F4553 to read a pushbutton
 * 
 * Hardware Description: An LED is connected via a 1k resistor to PIN D0 and a
 *                       switch is connected to PIN D1 via a 10k pullup resistor
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
    
    // Configure D1 as input
    TRISDbits.TRISD1 = 1;
    
    
    while(1)
    {  
         // Turn on LED on pushbutton press
         LATDbits.LATD0 = !PORTDbits.RD1; 
    }

    return;
}
