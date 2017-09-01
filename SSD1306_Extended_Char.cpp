/*
	SSD1306 - Derived from U8g2 for 0.91" TFT that use SSD1306.

// SSD1306_Extended_Char
//
// This extends U8g2 library by changing the method setCursor(), which allows the user to specify the cursor's position as if the display were character sized cursor based (6 pixels x 9 pixels), rather than pixels. 
//It is no longer possible to position the cursor, by pixel, as before using the setCursor() method - no longer true:
// It is possible to position the cursor, by pixel, as before using the setCursor() method, by calling setCursorMode(false).
// Calling setCursorMode(true) will revert the cursor positioning to character resolution. This is the default.

*/	

#include "SSD1306_Extended_Char.h"
//#include <limits.h>
//#include "pins_arduino.h"
//#include "wiring_private.h"
//#include <SPI.h>

//#if defined(SPI_HAS_TRANSACTION)
//	static SPISettings ILI9163C_SPI;
//#endif

/*
//Redundant
// Using which font?
//#define __Use_Font_u8g2_font_unifont_t_symbols__
//#define __Use_Font_u8g2_font_6x10_mf__
//#define __Use_Font_u8g2_font_ncenB08_tr__
//#define __Use_Font_u8g2_font_6x10_tf__
//#define __Use_Font_u8g2_font_ncenB14_tr__


#if defined (__Use_Font_u8g2_font_6x10_mf__)
// For u8g2_font_6x10_mf
//const int characterWidth = 6;
//const int characterHeight = 10;
#elif defined (__Use_Font_u8g2_font_unifont_t_symbols__)
// For u8g2_font_unifont_t_symbols
//const int characterWidth = 16;
//const int characterHeight = 16;
#endif

// For TFT_ILI9163C 1.44" 128x128
// TextSize = 1 gives display 20 characters wide, 14 characters high
// TextSize = 2 gives display 10 characters wide, 7 characters high
// TextSize = 3 gives display 7 characters wide, 4 characters high
const int characterSize = 1;

// For 0.91" 128x32
// TextSize = 6x10 gives display 20 characters wide, 3 characters high
// TextSize = 16x16 gives display 8 characters wide, 2 characters high
// TextSize = 8x16 gives display 16 characters wide, 2 characters high - ???
//Redundant
*/

 boolean characterResolutionOn = true;
 boolean sendBufferOn = true;

//constructors

SSD1306_Extended_Char::SSD1306_Extended_Char(const u8g2_cb_t *rotation, uint8_t reset = U8X8_PIN_NONE, uint8_t clock = U8X8_PIN_NONE, uint8_t data = U8X8_PIN_NONE) : U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C(rotation, reset, clock, data/*_TFTWIDTH,_TFTHEIGHT*/)
{
  characterResolutionOn = true;
  sendBufferOn = true;
}

void SSD1306_Extended_Char::setCursor(int16_t x, int16_t y) {
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::setCursor(x*characterWidth*characterSize, y+10*characterHeight*characterSize);
  int characterWidth = U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::getStrWidth("_"); // get the width of the widest character (no need to +2 for pixels either side, no additional spacing is required)
  int characterHeight = U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::getAscent()-U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::getDescent()+2; // get the character height and add a spare line
  if (characterResolutionOn){
    x = x*characterWidth;
    y = y*characterHeight+characterHeight-5;
  }
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::setCursor(x, y);
}

// +++++++
// print
// +++++++

size_t SSD1306_Extended_Char::print(const __FlashStringHelper *ifsh){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(ifsh);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const String &s){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(s);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const char str[]){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(str);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const char c){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(c);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(unsigned char b, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print((unsigned long) b, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print((long) n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(unsigned int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print((unsigned long) n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(unsigned long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(double n, int digits){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(n, digits);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const Printable& x){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(x);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

// +++++++
// println
// +++++++

size_t SSD1306_Extended_Char::println(const __FlashStringHelper *ifsh){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(ifsh);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const String &s){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(s);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const char str[]){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(str);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const char c){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(c);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(unsigned char b, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println((unsigned long) b, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println((long) n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(unsigned int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println((unsigned long) n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(unsigned long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(n, base);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(double n, int digits){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(n, digits);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const Printable& x){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(x);
  if (sendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

// +++++++++
// set modes
// +++++++++

void SSD1306_Extended_Char::setCursorMode(boolean characterResolutionMode){
  characterResolutionOn = characterResolutionMode;
}

void SSD1306_Extended_Char::setPrintMode(boolean sendBufferMode){
  sendBufferOn = sendBufferMode;
}



//  void SSD1306_Extended_Char::clear() {
//      clearBuffer();
//  }

// Delete - used only in Extended, not Extended_Char
//  void SSD1306_Extended_Char::setCursorChar(int16_t x, int16_t y) {
//      SSD1306_Extended_Char::setCursor(x*characterWidth*characterSize, y*characterHeight*characterSize);
//  }
// Delete - used only in Extended, not Extended_Char

//Arduino Uno, Leonardo, Mega, Teensy 2.0, etc




