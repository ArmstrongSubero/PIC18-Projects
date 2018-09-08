/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 08_ADC
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 *                
 * Program Description: This Program Allows PIC18F4553 to use the ADC module
 *                      and results are sent via TX pin to a serial LCD 
 * Hardware Description: A 2x16 Parallax LCD RX pin is connected to RC6 and 
 *                       a potentiometer is connected to PIN RA0 (AN0).
 *                      
 * Created September 7th, 2018, 9:09 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include "18F4553_STD.h"
#include "USART.h"
#include "ADC.h"


/*******************************************************************************
 * Function: Main
 *
 * Returns: Nothing
 *
 * Description: Program entry point
 ******************************************************************************/
void main(void)
{
    int result;
    
    // initialize 12 bit ADC
    ADC_Init();			
    delay_ms(1000);
   
    USART_Init(19200);
    delay_ms(1000);
      
    while(1)
    {
      // read channel 0
      result = ADC_Read(0);
      
      // Write Result
      USART_Write_Integer(result);
      delay_ms(3000);
      USART_Write(12);
    }
    
    return;
}
