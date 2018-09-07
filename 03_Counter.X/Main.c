/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 03_Counter
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0  
 *                
 * Program Description: This Program Allows PIC18F4553 to use Timer0 as a counter
 *                      to count external pulses of a pushbutton connected to 
 *                      PIN T0CKI
 * 
 * Hardware Description: An LED is connected via a 1k resistor to PIN D0
 *                      
 * Created September 7th, 2018, 3:15 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include <xc.h>
#include "18F4553_STD.h"


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
    
    // Select counter mode
    T0CONbits.T0CS = 1;
    
    // Assign Timer0 clock to T0CKI
    T0CONbits.PSA = 1;
      
    // Zero Timer
    TMR0 = 0;
}


/*******************************************************************************
 * Function: uint8_t ReadTimer0(void)
 *
 * Returns:  uint8_t readVal;
 *
 * Description: Returns the value of Timer0
 ******************************************************************************/

uint8_t ReadTimer0(void)
{
    // Read value variable
    uint8_t readVal;

    // Set variable to timer0 value
    readVal = TMR0;

    // return value
    return readVal;
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
    
    // count variable
    uint8_t count;
    
    while(1)
    {
         // read timer with count
        count = ReadTimer0();
        
        // if counter has value of 5
        if (count == 5)
        {
            // turn LED on
            LATDbits.LATD0 = 1;
            
            // short delay to see LED on
            delay_ms(2000);
            
            // zero timer
            TMR0 = 0;
        }
        
        else
        {
            // keep LED off
            LATDbits.LATD0 = 0;
        }
    }
   

    return;
}
