#ifndef LCD_H
#define LCD_H

#include "lcd_low.h"

bool lcd__Init(LCD_handle_t device);
bool lcd__DisplayOn(LCD_handle_t device);
bool lcd__DisplayOff(LCD_handle_t device);
bool lcd__DrawRect(LCD_handle_t device, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color);
bool lcd__DrawImage(LCD_handle_t device, const uint16_t x, const uint16_t y, const LCD_image_t *image);
bool lcd__DrawText(LCD_handle_t device, uint16_t x, const uint16_t y, const char *text, 
        const int16_t spacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor);
bool lcd__ClearScreen(LCD_handle_t device, const uint16_t color);
bool lcd__Destroy(LCD_handle_t *device);

#endif /* LCD_H */
