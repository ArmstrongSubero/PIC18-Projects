/*******************************************************************************
 * File: ADC.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Library file containing functions for the ADC module
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 * Program Description: This Library allows you to use the ADC module of the
 *                      PIC18F4553
 *                      
 * Created on September 7th, 2018, 9:06 PM
 ******************************************************************************/

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include "ADC.h"

/*******************************************************************************
 * Function: void ADC_Init()
 *
 * Returns: Nothing
 *
 * Description: Initializes the ADC module
 ******************************************************************************/
void ADC_Init()
{    
    TRISA = 0xFF;	// Set as input port 
    ADCON1 = 0x0E;	// Configure as analog
    ADCON2 = 0x92;	// Right Justified, 4Tad and Fosc/32.
    ADRESH=0;		// Flush ADC output Register 
    ADRESL=0;   
}   

/*******************************************************************************
 * Function: int ADC_Read(int channel)
 *
 * Returns: Nothing
 *
 * Description: Read ADC channel
 ******************************************************************************/
int ADC_Read(int channel)
{
    int result;

    // select channel, disable ADC
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);  
    
    // enable ADC, start conversion
    ADCON0 |= ((1<<ADON)|(1<<GO));

    // Wait for conversion
    while(ADCON0bits.GO_nDONE==1);

    // get 12 bit result
    result = (ADRESH*256) | (ADRESL);
    return(result);
}