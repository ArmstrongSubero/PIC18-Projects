/*
 * File: Main.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: 12_SPI
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                        
 * Program Description: This Program Allows PIC18F4553 to use the SPI module to
 *                      communicate with a slave.
 * 
 * Hardware Description: A MCP4131 digital potentiometer is connected to the SPI
 *                       bus as follows:
 * 
 *                       Vss --> Vss
 *                       Vdd --> Vdd
 *                       SS  --> RA5
 *                       SCK --> RB1
 *                       SDI --> RC7
 *                       POB --> GND
 *                       POW --> LED via 1k resistor
 *                       POA --> Vdd
 * 
 * Created September 7th, 2018, 1:28 PM
 */

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include "18F4553_STD.h"
#include "SPI.h"

/*******************************************************************************
 * Function: Main
 *
 * Returns: Nothing
 *
 * Description: Writes a particular value to a MCP4131 digital potentiometer 
 ******************************************************************************/
void digiPot_write(int i){
    CS = 0;                   // Chip select low
    SPI_Write(0x00);          // Slave address
    SPI_Write(i);             // Data
    CS = 1;                   // Chip select High
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
    int i;
    INTCON2bits.RBPU=0;		    // PORTB weak pull-ups enable
    
    SPI_Init_Master();
    
    while(1)
    {
        for (i = 0; i <= 127; i++)
        {  
          // Write Value
            digiPot_write(i); 
            delay_ms(1000);
        }
    }

    return;
}
