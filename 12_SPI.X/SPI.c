/*******************************************************************************
 * File: SPI.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Library file containing functions for the SPI module
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 * Program Description: This Library allows you to use the SPI module of the
 *                      PIC18F4553
 *                      
 * Created on September 7th, 2018, 10:47 PM
 ******************************************************************************/

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/


#include "SPI.h"


/*******************************************************************************
 * Function: void SPI_Init_Master()
 *
 * Returns: Nothing
 *
 * Description: Initializes the SPI module
 ******************************************************************************/
void SPI_Init_Master()
{
    TRISBbits.TRISB0 =1;	// RB0 as input(SDI) 
    TRISBbits.TRISB1 =0;	// B1 as output(SCK) 
    TRISAbits.TRISA5 =0;	// RA5 as a output(SS) 
    TRISCbits.TRISC7 =0;	// RC7 as output(SDO) 
    
    CS = 1;                 // CS HIGH
    SSPSTAT=0x40;		    // Rising edge of clk , BF=0
    
    SSPCON1bits.CKP = 0;    // Idle Low
    SSPCON1bits.SSPEN = 1;  // Enable serial port
    
    // Fosc/16 Master mode
    SSPCON1bits.SSPM0 = 1;
    SSPCON1bits.SSPM1 = 0;
    SSPCON1bits.SSPM2 = 0;
    SSPCON1bits.SSPM3 = 0; 

    PIR1bits.SSPIF=0;       // Make sure interrupt flag is clear

    // Configure multiplexed pins as digital
    ADCON0=0;		
    ADCON1=0x0F;	
}


/*******************************************************************************
 * Function: void SPI_Write(unsigned char x)
 *
 * Returns: Nothing
 *
 * Description: Writes a byte to the SPI module
 ******************************************************************************/
void SPI_Write(unsigned char x)
{
    unsigned char data_flush;
    SSPBUF=x;			      // Copy data in SSBUF to transmit 
    while(!PIR1bits.SSPIF);	  // Wait for complete 1 byte transmission 
    PIR1bits.SSPIF=0;		  // Clear SSPIF flag 
    data_flush=SSPBUF;		  // Flush the data 
}

/*******************************************************************************
 * Function: unsigned char SPI_Read()
 *
 * Returns: Nothing
 *
 * Description: Reads a byte from the SPI module
 ******************************************************************************/
unsigned char SPI_Read()
{    
    SSPBUF=0xff;		      // Copy flush byte in SSBUF 
    while(!PIR1bits.SSPIF);	  // Wait for complete 1 byte transmission 
    PIR1bits.SSPIF=0;
    return(SSPBUF);		      //Return received byte   
}