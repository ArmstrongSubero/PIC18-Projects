/*
 * File: 18F4553_STD.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Library file to configure PIC18F4553
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 2.0
 *                *Added additional comments
 *                
 * Program Description: This Library allows you to setup a PIC18F4553, includes
 *                      delay functions
 *                      
 * Created on September 7th, 2018, 1:17 PM
 */


/*******************************************************************************
 * Includes and Defines
 *******************************************************************************/
#include "18F4553_STD.h"

/*******************************************************************************
 * Function: void delay_us(uint16_t x)
 *
 * Returns: Nothing
 *
 * Description: delays microseconds, assumes 48MHz clock
 ******************************************************************************/
void delay_us(uint16_t x) 
{ 
    unsigned char us; 
    us = x /(48000000/48000000)|1; 
    while(--us != 0) continue; 
} 

/*******************************************************************************
 * Function: void delay_ms(uint16_t ms)
 *
 * Returns: Nothing
 *
 * Description: delay no of milliseconds, assumes 48 MHz Clock
 ******************************************************************************/
void delay_ms(uint16_t ms)
{
  unsigned char i;
  do {
    i = 4;
    do {
      delay_us(250);
    } while(--i);
  }while(--ms);
}
