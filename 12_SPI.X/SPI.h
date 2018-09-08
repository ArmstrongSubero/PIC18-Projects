/*******************************************************************************
 * File: SPI.h
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Header file to setup PIC18F4553 SPI
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version 1.0
 *                  
 * Program Description: This header sets up the SPI module
 * Created on September 7th, 2018, 10:47 PM
 ******************************************************************************/

#include "18F4553_STD.h"

void SPI_Init_Master();
void SPI_Write(unsigned char x);
unsigned char SPI_Read();

#define CS LATA5