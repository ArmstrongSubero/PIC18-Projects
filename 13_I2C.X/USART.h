/*******************************************************************************
 * File: USART.h
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Header file to setup PIC18F4553 UART
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version 1.0
 *                  
 * Program Description: This header sets up the EUSART module
 * Created on September 7th, 2018, 8:44 PM
 ******************************************************************************/

#include "18F4553_STD.h"
#include <stdlib.h>

#define FREQ_CPU 48000000/64

void USART_Init(long baud_rate);
void USART_Write(char out);
void USART_Write_Text(char *text);
void USART_Write_Integer(int num);
void USART_Write_Float(float num);
char USART_RxChar();