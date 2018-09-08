/*******************************************************************************
 * File: ADC.h
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Header file to setup PIC18F4553 ADC
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version 1.0
 *                  
 * Program Description: This header sets up the ADC module
 * Created on September 7th, 2018, 8:44 PM
 ******************************************************************************/

#include "18F4553_STD.h"
void ADC_Init();
int ADC_Read(int channel);