/*
	ILI9163C - A fast SPI driver for TFT that use Ilitek ILI9163C.

// SSD1306_Extended_Char
//
// This extends U8g2 library by changing the method setCursor(), which allows the user to specify the cursor's position as if the display were character sized cursor based (6 pixels x 9 pixels), rather than pixels. 
// It is no longer possible to position the cursor, by pixel, as before using the setCursor() method.

*/	

#ifndef SSD1306CLIB_H_EXTENDED_CHAR
#define SSD1306CLIB_H_EXTENDED_CHAR


//defined(__MKL26Z64__)
#include "Arduino.h"
#include "Print.h"
//#include <Adafruit_GFX.h>
#include <U8g2lib.h>

//#include "_settings/TFT_ILI9163C_settings.h"

/*
#if !defined(_ADAFRUIT_GFX_VARIANT)
	#ifdef __AVR__
		#include <avr/pgmspace.h>
	#elif defined(__SAM3X8E__)
		#include <include/pio.h>
		#define PROGMEM
		#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
		#define pgm_read_word(addr) (*(const unsigned short *)(addr))
		typedef unsigned char prog_uchar;
	#endif
#endif
*/

//--------- Keep out hands from here!-------------

#define	BLACK   		0x0000
#define WHITE   		0xFFFF

//#include "_settings/TFT_ILI9163C_registers.h"



class SSD1306_Extended_Char : public U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C {

  public: 

    SSD1306_Extended_Char(const u8g2_cb_t *rotation, uint8_t reset = U8X8_PIN_NONE, uint8_t clock = U8X8_PIN_NONE, uint8_t data = U8X8_PIN_NONE);/* : U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C(rotation, reset, clock, data);/* {
    u8g2_Setup_ssd1306_i2c_128x32_univision_f(&u8g2, rotation, u8x8_byte_arduino_hw_i2c, u8x8_gpio_and_delay_arduino);
    u8x8_SetPin_HW_I2C(getU8x8(), reset, clock, data);
  }*/
        void setCursor(int16_t x,int16_t y);//char addressing

//added sendBuffer() to prints
    size_t print(const String &);
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
    size_t print(const Printable&);

//        void clear();

// Delete - used only in Extended, not Extended_Char
//        void setCursorChar(int16_t x,int16_t y);//char addressing
// Delete - used only in Extended, not Extended_Char

};

#endif


