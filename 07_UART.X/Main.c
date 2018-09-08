/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 07_UART
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 *                
 * Program Description: This Program Allows PIC18F4553 to use the USART module
 *                      and characters are send via TX pin to a serial LCD 
 * Hardware Description: A 2x16 Parallax LCD RX pin is connected to RC6
 *                      
 * Created September 7th, 2018, 8:43 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include "18F4553_STD.h"
#include "USART.h"


/*******************************************************************************
 * Function: Main
 *
 * Returns: Nothing
 *
 * Description: Program entry point
 ******************************************************************************/
void main(void)
{
    char my_char[] = "Test";
    
    USART_Init(19200);
    delay_ms(1000);
     
    while(1)
    {
       // Write Text
       USART_Write_Text(my_char);
       delay_ms(3000);
       USART_Write(12);
       USART_Write(13);
       
       // Write Integer 
       USART_Write_Integer(10);
       delay_ms(3000);
       USART_Write(12);
       USART_Write(13);
    
       // Write Float
       USART_Write_Float(191.00);
       delay_ms(3000);
       USART_Write(12);
       USART_Write(13);
    }
    
    return;
}
