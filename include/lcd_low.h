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
 * @file lcd_low.h
 * @author Damian Ślusarczyk
 * @brief Contains all structures required for proper communication with LCD display that uses different controllers.
 * 
 */
#ifndef LCD_LOW_H
#define LCD_LOW_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "lcd_error_codes.h"
#include "lcd_image.h"
#include "lcd_font.h"

typedef struct LCD_com_t            LCD_com_t;
typedef struct LCD_controller_t     LCD_controller_t;
typedef struct LCD_t                LCD_t;

/** Handle type for LCD communication interface instance */
typedef struct LCD_com_t *          LCD_com_handle_t;
/** Handle type for LCD controller instance */
typedef struct LCD_controller_t *   LCD_controller_handle_t;
/** Handle type for LCD instance */
typedef struct LCD_t *              LCD_handle_t;

/**
 * @brief Structure containing function interface for low-level communication with specific LCD controller (some protocol like SPI is usually used). 
 * 
 * @note Handle for the structure is usually returned by getter methods of some communication protocol implementations (e.g. check lcd_spi.h file).
 */
struct LCD_com_t
{
    /** Pointer to function which writes address of the selected command to specific LCD controller bus */
    bool (*write_cmd)(LCD_handle_t base, const uint8_t cmd);
    /** Pointer to function which writes data bytes to specific LCD controller bus */
    bool (*write_single_bytes)(LCD_handle_t base, const uint8_t *data, const size_t dataSize);
    /** Pointer to function which writes exactly two bytes of data to specific LCD controller bus */
    bool (*write_two_bytes)(LCD_handle_t base, const uint16_t data);
};

/**
 * @brief Structure containing function interface to implement by specific LCD controller. 
 * 
 * @note Specific LCD controller implementation is initializing it internally (e.g. check lcd_ssd1283a.h file).
 */
struct LCD_controller_t
{
    /** Pointer to function which initializes selected LCD driver instance */
    LCD_error_t (*Init)(LCD_handle_t base);
    /** Pointer to function which turns on LCD display using selected driver instance */
    LCD_error_t (*DisplayOn)(LCD_handle_t base);
    /** Pointer to function which turns off LCD display using selected driver instance */
    LCD_error_t (*DisplayOff)(LCD_handle_t base);
    /** Pointer to function which draws rectangle on the LCD screen in specific position and color using selected driver instance */
    LCD_error_t (*DrawRect)(LCD_handle_t base, const uint16_t x, const uint16_t y, const uint16_t width, 
        const uint16_t height, const uint16_t color);
    /** Pointer to function which draws image on the LCD screen in specific position using selected driver instance */
    LCD_error_t (*DrawImage)(LCD_handle_t base, const uint16_t x, const uint16_t y, const LCD_image_t *image);
    /** Pointer to function which draws text on the LCD screen in specific position, font and colors (of the font and its background) 
     *  with defined letter and line spacing using selected driver instance 
     */
    LCD_error_t (*DrawText)(LCD_handle_t base, uint16_t x, uint16_t y, const char *text, 
        const int16_t letterSpacing, const int16_t lineSpacing, const LCD_font_t *font, 
        const uint16_t fontColor, const uint16_t bgrColor);
    /** Pointer to function which clears all LCD screen in specific color using selected driver instance */
    LCD_error_t (*ClearScreen)(LCD_handle_t base, const uint16_t color);
    /** Pointer to function which destroys selected driver instance */
    LCD_error_t (*Destroy)(LCD_handle_t base);
};

/**
 * @brief Base structure describing characteristics of LCD display and its driver.
 * 
 * @note Handle for the structure is returned by initialize method of specific LCD controller (e.g. check lcd_ssd1283a.h file).
 */
struct LCD_t
{
    uint16_t                    width;      /**< Width of the display in pixels */
    uint16_t                    height;     /**< Height of the display in pixels */
    LCD_com_handle_t            com;        /**< Handle to low-level communication interface */
    LCD_controller_handle_t     controller; /**< Handle to LCD controller implementation interface */
};

#endif /* LCD_LOW_H */
