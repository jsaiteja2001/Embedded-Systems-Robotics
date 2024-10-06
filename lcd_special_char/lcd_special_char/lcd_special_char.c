/*! \mainpage Week-4 Challenge Activity 1: Display special characters on LCD
 *
 * @author     e-Yantra Team
 * @date       2020/04/01
 *
 * \subsection Aim
 * to display special characters on LCD.
 *
 * \subsection Connections (Proteus Project)
 * LCD Connections:								<br>
 *		 LCD Pins	  Micro-controller Pins     <br>
 *			  RS  --> PB0						<br>
 *			  RW  --> PB2						<br>
 *			  EN  --> PB1						<br>
 *			  DB7 --> PD7						<br>
 *			  DB6 --> PD6						<br>
 *			  DB5 --> PD5						<br>
 *			  DB4 --> PD4						<br>
 *
 */

//---------------------------------- HEADER FILES -----------------------------------------------------

#include "firebird_simulation.h"		// Header file included that contains macro definitions essential for Firebird V robot and Simulation
#include <util/delay.h>					// Standard AVR Delay Library
#include "lcd.h"						// LCD Header file included that contains function definitions essential to deal with LCD

//------------------------------------ Global Variables ---------------------------------------------------
unsigned int i;
unsigned char pattern_e[8] = {
	0b00011111,						
	0b00010001,
	0b00010011,
	0b00010110,
	0b00011100,
	0b00010000,
	0b00011111,
	0b00000000
};
unsigned char posrise[8]={0b00011,
	0b00100,
	0b01000,
	0b10000,
	0b00000,
	0b00000,
	0b00000,
0b00000};
unsigned char posfall[8]={0b11000,
	0b00100,
	0b00010,
	0b00001,
	0b00000,
	0b00000,
	0b00000,
0b00000};
unsigned char negfall[8]={0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b01000,
	0b00100,
	0b00011,
0b00000};
unsigned char negrise[8]={0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00010,
	0b00100,
	0b11000,
0b00000};

//------------------------------------ FUNCTIONS ---------------------------------------------------

/**
* @brief      Store the custom characters at CGRAM location.<br>
*		       
* @details    This function stores the 8 byte pattern at the CGRAM memort.<br>
*
* @param[in]  loc  			The address of CGRAM 1 - 7
* 			  *pattern 		Base address of array where the pattern is stored
*/

//<< NOTE >>: You should not change this function in order to get the required output
void lcd_custom_char (unsigned char loc, unsigned char *pattern)
{
	unsigned char i;
	if(loc<8)
	{
		lcd_wr_command(0x40 + (loc*8));		// Command 0x40 and onwards forces the device to point CGRAM address
		for(i=0;i<8;i++)					// Write 8 byte for generation of the custom character */
		lcd_wr_char(0,0,pattern[i]);
	}
}


/**
* @brief      Display the logo "e" using custom character.<br>
*		       
* @details    This function displays the pattern "e".<br>
*
*/		
void Display_logo()
{
	lcd_string(1,3,"Display Logo");
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	lcd_custom_char(1, pattern_e);		// Build Character1 at position 1
	lcd_wr_char(2,8,1);
}

/**
* @brief      Display the sine wave.<br>
*		       
* @details    This function displays the sine wave on LCD.<br>
*
*/		
void Display_sine_wave()
{
	lcd_string(1,3,"Sine Wave");
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
int i;
	/*
	<< TODO >> :
		displays the sine wave on LCD 
		Store the binary patterns for positive and negative cycle of sine wave in an array<br> 
*		and pass the base address of array to the lcd_custom_char function.
	*/
	
	
	//write custom character to cgram
	lcd_custom_char(2, posrise);
	lcd_custom_char(3, posfall);
	lcd_custom_char(4, negfall);
	lcd_custom_char(5, negrise);
    lcd_wr_char(1,1,2);
	lcd_wr_char(1,2,3);
	lcd_wr_char(1,3,4);
	lcd_wr_char(1,4,5);	
	lcd_wr_char(1,5,2);
	lcd_wr_char(1,6,3);
	lcd_wr_char(1,7,4);
	lcd_wr_char(1,8,5);
	lcd_wr_char(1,9,2);
	lcd_wr_char(1,10,3);
	lcd_wr_char(1,11,4);
	lcd_wr_char(1,12,5);
	lcd_wr_char(1,13,2);
	lcd_wr_char(1,14,3);
	lcd_wr_char(1,15,4);
	lcd_wr_char(1,16,5);
	lcd_wr_char(2,1,2);
	lcd_wr_char(2,2,3);
	lcd_wr_char(2,3,4);
	lcd_wr_char(2,4,5);
	lcd_wr_char(2,5,2);
	lcd_wr_char(2,6,3);
	lcd_wr_char(2,7,4);
	lcd_wr_char(2,8,5);
	lcd_wr_char(2,9,2);
	lcd_wr_char(2,10,3);
	lcd_wr_char(2,11,4);
	lcd_wr_char(2,12,5);
	lcd_wr_char(2,13,2);
	lcd_wr_char(2,14,3);
	lcd_wr_char(2,15,4);
	lcd_wr_char(2,16,5);	
}


/**
* @brief      Display the Special Characters.<br>
*		       
* @details    This function displays the special characters on LCD.<br>
*
*/		
void Display_special_characters()
{
	lcd_string(1,3,"Special Chars");
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD

	/*
	<< TODO >> :
		displays the given special characters on LCD - ! @ # $ % & *
		You may use lcd_string or lcd_wr_char function to display characters.
	*/
	lcd_wr_char(1,1,0b00100001);
	lcd_wr_char(1,2,0b01000000);
	lcd_wr_char(1,3,0b00100011);
	lcd_wr_char(1,4,0b00100100);
	lcd_wr_char(1,5,0b00100101);
	lcd_wr_char(1,6,0b00100110);
	lcd_wr_char(1,7,0b00101010);
}
/**
* @brief      Show more on LCD.<br>
*		       
* @details    You may use this function to display different patterns on LCD. <br>
*			  Use your creativity to display (Add )	
*
*/	
void Display_extra()
{
	/*
	<< TODO >> :
		Use your own creativity to showcase more on the LCD to make it more interesting and appealing 
		(you may also think of combining with scrolling display).
	*/
	lcd_string(1,3,"Display Extra");
	_delay_ms(2000);
	lcd_clear();
	lcd_wr_char(1,6,0b01010011);
	lcd_wr_char(1,7,0b01000001);
	lcd_wr_char(1,8,0b01001001);
	lcd_wr_char(1,9,0b01010100);
	lcd_wr_char(1,10,0b01000101);
	lcd_wr_char(1,11,0b01001010);
	lcd_wr_char(1,12,0b01000001);
	lcd_wr_char(2,1,0b01010000);
	lcd_wr_char(2,2,0b01010110);
	lcd_wr_char(2,3,0b01010000);
	lcd_wr_char(2,4,0b01010011);
	lcd_wr_char(2,5,0b01001001);
	lcd_wr_char(2,6,0b01010100);
	lcd_wr_char(2,7,0b00101000);
	lcd_wr_char(2,8,0b00110010);
	lcd_wr_char(2,9,0b00110000);
	lcd_wr_char(2,10,0b00110001);
	lcd_wr_char(2,11,0b00111000);
	lcd_wr_char(2,12,0b00101101);
	lcd_wr_char(2,13,0b00110010);
	lcd_wr_char(2,14,0b00110010);
	lcd_wr_char(2,15,0b00101001);	
}


//---------------------------------- MAIN ----------------------------------------------------------------
/**
 * @brief      Main Function
 *
 * @details    First Initializes the LCD
 *			   and displays the different patterns on LCD on by one. 
 */
 int main(void)
{
	lcd_port_config();					// Initialize the LCD port
	lcd_init();							// Initialize the LCD
	lcd_clear();						// Clear the LCD
    
	Display_logo();
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	Display_sine_wave();
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	Display_special_characters();
	_delay_ms(2000);
	lcd_clear();						// Clear the LCD
	Display_extra();
	
    while (1);
}
