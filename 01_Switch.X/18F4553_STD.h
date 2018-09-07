/*******************************************************************************
 * File: 18F4553_STD.h
 * Author: Armstrong Subero
 * PIC: 18F4553 w/HS OSC @ 16MHz; PLL to 48MHz, 5v
 * Program: Header file to setup PIC18F4553
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version 2.0
 *         * Added delay functions
 *                  
 * Program Description: This program header will allows setup of configuration
 *                      bits and provides routines for setting up internal
 *                      oscillator and includes all devices and MCU modules
 *
 * Created on September 7th, 2018, 12:33 PM
 ******************************************************************************/

// Configuration Bits
#pragma config FOSC = HSPLL_HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config IESO = OFF             // Switch over Disabled, Put IESO = ON to enable
#pragma config PLLDIV = 4             // Divide by 4 (16MHz input)
#pragma config CPUDIV = OSC1_PLL2     // [OSC1/OSC2 Src: /1][96MHz PLL Src: /2]
#pragma config PWRT = ON              // Power up timer enabled
#pragma config BOR = ON
#pragma config BORV = 3               // Brown out voltage = 3V
#pragma config VREGEN = ON            // USB voltage regulator enabled
#pragma config WDT = OFF              // HW Disabled - SW Controlled
#pragma config WDTPS = 128            // 1:128 prescalar selected
#pragma config MCLRE = ON             // MCLR Enabled
#pragma config LPT1OSC = OFF          // Timer1 oscillator configured for high power
#pragma config PBADEN = OFF           // Pins are configured as digital I/O on Reset
#pragma config CCP2MX = ON            // CCP2 input/output is multiplexed with RC1
#pragma config STVREN = OFF           // Stack overflow reset
#pragma config LVP = OFF              // Low voltage programming mode OFF
#pragma config DEBUG = OFF            // Background debugger enabled
#pragma config WRTD = OFF             // Data EEPROM Write protection OFF
#pragma config WRTC = ON              // Configuration register protection ON


#include <xc.h>
#include <stdint.h>

void delay_us(uint16_t x);
void delay_ms(uint16_t ms);

