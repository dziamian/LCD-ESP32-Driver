/*
 * MIT License
 *
 * Copyright (c) 2022 Damian Ślusarczyk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
/**
 * @file lcd.h
 * @author Damian Ślusarczyk
 * @brief Contains driver functions to communicate with LCD display using different protocols and controllers.
 * 
 */
#ifndef LCD_H
#define LCD_H

#include "lcd_low.h"

/**
 * @brief Initializes the specific LCD device.
 * 
 * Prepares the LCD display to work with the driver.
 * @note This method need to be called before using any other driver functions.
 * 
 * @param device Handle for the selected LCD device
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__Init(LCD_handle_t device);

/**
 * @brief Turns on the LCD display for the specific device.
 * 
 * @note Display should be turned on after using lcd__Init() function.
 * 
 * @param device Handle for the selected LCD device
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__DisplayOn(LCD_handle_t device);

/**
 * @brief Turns off the LCD display for the specific device.
 * 
 * @param device Handle of the selected LCD device
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__DisplayOff(LCD_handle_t device);

/**
 * @brief Draws rectangle on the LCD display in specific position and color.
 * 
 * @param device Handle of the selected LCD device
 * @param x Position of the top left pixel of the rectangle in X-axis
 * @param y Position of the top left pixel of the rectangle in Y-axis
 * @param width Width of the rectangle (in pixels)
 * @param height Height of the rectangle (in pixels)
 * @param color 16-bit color value (format RGB565) of the rectangle
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__DrawRect(LCD_handle_t device, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color);

/**
 * @brief Draws image on the LCD display in specific position.
 * 
 * @param device Handle of the selected LCD device
 * @param x Position of the top left pixel of the image in X-axis
 * @param y Position of the top left pixel of the image in Y-axis
 * @param image Pointer to the image to be drawn
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__DrawImage(LCD_handle_t device, const uint16_t x, const uint16_t y, const LCD_image_t *image);

/**
 * @brief Draws text on the LCD display with specified properties.
 * 
 * @param device Handle of the selected LCD device
 * @param x Position of the top left pixel of the first character in X-axis
 * @param y Position of the top left pixel of the first character in Y-axis
 * @param text Text to be drawn
 * @param letterSpacing Letter spacing value in pixels
 * @param lineSpacing Line spacing value in pixels
 * @param font Pointer to the font of the drawn text
 * @param fontColor 16-bit color value (format RGB565) of the font
 * @param bgrColor 16-bit color value (format RGB565) of the text background
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__DrawText(LCD_handle_t device, uint16_t x, uint16_t y, const char *text, 
        const int16_t letterSpacing, const int16_t lineSpacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor);

/**
 * @brief Clears the screen of the LCD display with specified color.
 * 
 * @param device Handle of the selected LCD device
 * @param color 16-bit color value (format RGB565) to fill the screen
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__ClearScreen(LCD_handle_t device, const uint16_t color);

/**
 * @brief Destroys the specific LCD driver instance.
 * 
 * Frees the memory allocated dynamically for the driver instance.
 * 
 * @param device Pointer to handle for the selected LCD device
 * @return LCD_error_t Status code of the operation
 */
LCD_error_t lcd__Destroy(LCD_handle_t *device);

#endif /* LCD_H */
