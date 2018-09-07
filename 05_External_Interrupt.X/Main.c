/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 05_External_Interrupt
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0  
 *                
 * Program Description: This Program Allows PIC18F4553 to use a External Interrupt
 *                      to flash an LED 
 * 
 * Hardware Description: An LED is connected via a 1k resistor to PIN D0 and 
 *                       a pushbutton is connected via 10k resistor to PINB2
 *                      
 * Created September 7th, 2018, 7:27 PM
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
    
    // Configure INT2 pin as input
    TRISBbits.TRISB2 = 1;
       
    ///////////////////////
    /// Configure EXTINT2
    //////////////////////
    INTCONbits.GIEH=1;          //Enabling High priority interrupts
    INTCONbits.GIEL=1;          //Enabling Low priority interrupts
    RCONbits.IPEN=1;            //Enabling Interrupt priority
    INTCON2bits.INTEDG2 = 0;    // Interrupt on falling edge
       
    INTCON3bits.INT2IE=1;       //Enabling INT2 interrupt
    INTCON3bits.INT2IF=0;       //Clearing INT2 interrupt flag
    INTCON3bits.INT2IP=0;       //Setting INT2 interrupt priority as high
    
}

/*******************************************************************************
 * Function: void interrupt isr(void)
 *
 * Returns: Nothing
 *
 * Description: Timer0 interrupt at a rate of 1 second
 ******************************************************************************/

void interrupt PORTB_ISR()                           // PORTB ISR
{
   
    if (INTCON3bits.INT2IF == 1)                     // If interrupt 
    {
        for (int i = 0; i <= 10; i++)
        {
            LATDbits.LATD0 = ~LATDbits.LATD0;        // flash LED 10 times
            delay_ms(250);
        }
        
        INTCON3bits.INT2IF = 0;                      //clearing INT0 interrupt flag
    }
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
    
    LATDbits.LATD0 = 0;     // Set LED off initially
    
    while(1)
    {
      // Do nothing
    }

    return;
}


