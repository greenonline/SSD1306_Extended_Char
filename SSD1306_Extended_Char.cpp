/*
	ILI9163C - A fast SPI driver for TFT that use Ilitek ILI9163C.

// SSD1306_Extended_Char
//
// This extends U8g2 library by changing the method setCursor(), which allows the user to specify the cursor's position as if the display were character sized cursor based (6 pixels x 9 pixels), rather than pixels. 
//It is no longer possible to position the cursor, by pixel, as before using the setCursor() method.

*/	

#include "SSD1306_Extended_Char.h"
//#include <limits.h>
//#include "pins_arduino.h"
//#include "wiring_private.h"
//#include <SPI.h>

//#if defined(SPI_HAS_TRANSACTION)
//	static SPISettings ILI9163C_SPI;
//#endif

const int kCharacterWidth = 6;
const int kCharacterHeight = 9;

// TextSize = 1 gives display 20 characters wide, 14 characters high
// TextSize = 2 gives display 10 characters wide, 7 characters high
// TextSize = 3 gives display 7 characters wide, 4 characters high
const int kCharacterSize = 1;

 boolean kCharacterResolution = true;
 boolean kSendBufferOn = true;

//constructors

SSD1306_Extended_Char::SSD1306_Extended_Char(const u8g2_cb_t *rotation, uint8_t reset = U8X8_PIN_NONE, uint8_t clock = U8X8_PIN_NONE, uint8_t data = U8X8_PIN_NONE) : U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C(rotation, reset, clock, data/*_TFTWIDTH,_TFTHEIGHT*/)
{
  kCharacterResolution = true;
  kSendBufferOn = true;
}

void SSD1306_Extended_Char::setCursor(int16_t x, int16_t y) {
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::setCursor(x*kCharacterWidth*kCharacterSize, y+10*kCharacterHeight*kCharacterSize);
  if (kCharacterResolution){
    x = x*kCharacterWidth*kCharacterSize;
    y = y*10+10;
//    y = y*kCharacterHeight*kCharacterSize+10
  }
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::setCursor(x, y);
}

// +++++++
// print
// +++++++

size_t SSD1306_Extended_Char::print(const __FlashStringHelper *ifsh){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(ifsh);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const String &s){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(s);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const char str[]){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(str);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const char c){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(c);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(unsigned char b, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print((unsigned long) b, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print((long) n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(unsigned int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print((unsigned long) n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(unsigned long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(double n, int digits){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(n, digits);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::print(const Printable& x){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::print(x);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

// +++++++
// println
// +++++++

size_t SSD1306_Extended_Char::println(const __FlashStringHelper *ifsh){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(ifsh);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const String &s){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(s);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const char str[]){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(str);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const char c){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(c);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(unsigned char b, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println((unsigned long) b, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println((long) n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(unsigned int n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println((unsigned long) n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(unsigned long n, int base){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(n, base);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(double n, int digits){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(n, digits);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

size_t SSD1306_Extended_Char::println(const Printable& x){
  U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::println(x);
  if (kSendBufferOn)
    U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C::sendBuffer();
}

// +++++++++
// set modes
// +++++++++

void SSD1306_Extended_Char::setCursorMode(boolean characterResolutionOn){
  kCharacterResolution = characterResolutionOn;
}

void SSD1306_Extended_Char::setPrintMode(boolean sendBufferOn){
  kSendBufferOn = sendBufferOn;
}



//  void SSD1306_Extended_Char::clear() {
//      clearBuffer();
//  }

// Delete - used only in Extended, not Extended_Char
//  void SSD1306_Extended_Char::setCursorChar(int16_t x, int16_t y) {
//      SSD1306_Extended_Char::setCursor(x*kCharacterWidth*kCharacterSize, y*kCharacterHeight*kCharacterSize);
//  }
// Delete - used only in Extended, not Extended_Char

//Arduino Uno, Leonardo, Mega, Teensy 2.0, etc




