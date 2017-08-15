# SSD1306_Extended_Char
Extends the [U8g2](https://github.com/olikraus/U8g2_Arduino) Arduino library, to provide cursor positioning based on character size, instead of pixels, and instant `print()`, by including `sendBuffer()` in the `print(...)` call.

Rough and ready Arduino library.

Uses `U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C` object only

Needs expanding.

Provides `setCursor()` for character resolution, instead of pixel. Works best for mono spaced fonts, such as `u8g2_font_6x10_mf`
Overrides `print()` and incorporates `sendBuffer()` into `print(...)`, for instant display. Can lead to flickering display.

These can be turned on and off using:

 - `setPrintMode(boolean sendBufferOn)`
 - `setCursorMode(boolean useCharacterResolution)`
