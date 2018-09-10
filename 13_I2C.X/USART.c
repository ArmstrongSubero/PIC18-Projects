/*******************************************************************************
 * File: USART.c
 * Author: Armstrong Subero
 * PIC: 18F4553 w/Ext OSC @ 16MHz ; PLL to 48MHz, 5v
 * Program: Library file containing functions for the EUSART module
 * Compiler: XC8 (v1.38, MPLAX X v5.05)
 * Program Version: 1.0
 *                
 * Program Description: This Library allows you to use the EUSART module of the
 *                      PIC18F4553
 *                      
 * Created on September 7th, 2018, 8:46 PM
 ******************************************************************************/

/*******************************************************************************
 * Includes and Defines
 ******************************************************************************/
#include "USART.h"

/*******************************************************************************
 * Function: void USART_Init(long baud_rate)
 *
 * Returns: Nothing
 *
 * Description: Initializes the USART module
 ******************************************************************************/
void USART_Init(long baud_rate)
{
    float temp;
    
    // Set TX as output
    TRISCbits.TRISC6=0;	
    // Set RX as input
    TRISCbits.TRISC7=1; 

    //SPBRG = (FREQ_CPU /(64*9600))-1
    temp= (( (float) (FREQ_CPU) / (float) baud_rate ) - 1);     
    SPBRG = (int) temp;	

    TXSTA = 0x20;  	// Enable Transmit
    RCSTA = 0x90;  	// Enable Receive
}

/*******************************************************************************
 * Function: USART_Write(char out)
 *
 * Returns: Nothing
 *
 * Description: Writes to the UART module
 ******************************************************************************/
void USART_Write(char out)
{
   while (TXIF == 0);	// Wait for transmit interrupt flag
   TXREG = out;  	    // Write char data to transmit register  
}


/*******************************************************************************
 * Function: void USART_Write_Text(char *text)
 *
 * Returns: Nothing
 *
 * Description: Writes text via the UART module
 ******************************************************************************/
void USART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
  USART_Write(text[i]);  
}


/*******************************************************************************
 * Function: void USART_Write_Integer(int num)
 *
 * Returns: Nothing
 *
 * Description: Writes integer via the UART module
 ******************************************************************************/
void USART_Write_Integer(int num)
{
  unsigned char buf[8];
  USART_Write_Text(itoa(buf, num, 10));
}

/*******************************************************************************
 * Function: void USART_Write_Float(float num)
 *
 * Returns: Nothing
 *
 * Description: Writes float via the UART module
 ******************************************************************************/
void USART_Write_Float(float num)
{
  char* buf1;
  int status;

  buf1 = ftoa(num, &status);

  USART_Write_Text(buf1);
}

/*******************************************************************************
 * Function: char USART_RxChar()
 *
 * Returns: Nothing
 *
 * Description: Receive data via the UART module
 ******************************************************************************/
char USART_RxChar()
{

while(RCIF==0);        //wait for receive interrupt flag
    if(RCSTAbits.OERR)
    {           
        CREN = 0;
        NOP();
        CREN=1;
    }
    return(RCREG);    //receive data is stored in RCREG register and return
}