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
 * @file lcd_font.h
 * @author Damian Ślusarczyk
 * @brief Contains representation of the fonts to be drawn on LCD display and methods that simplify the work with them.
 * 
 */
#ifndef LCD_FONT_H
#define LCD_FONT_H

#include <stdint.h>
#include <stdbool.h>

#define LCD_FONT_BYTE_LINE      8               /**< Number of bits for single pixel map line of the font */

typedef struct LCD_font_t       LCD_font_t;

/**
 * @brief Describes properties of the font to be drawn on LCD display.
 * 
 * @note An example of structure initialization for the basic font can be seen in the lcd_basic_file.h file.
 */
struct LCD_font_t
{
    const uint16_t              width;          /**< Width of the single font character in pixels */
    const uint16_t              height;         /**< Height of the single font character in pixels */
    const char                  firstCharacter; /**< First character contained in the pixel map */
    const uint16_t              characters;     /**< Number of characters contained in the font */
    /** 
     * Pointer to array of pixel font map. The single element of the array is interpreted as a pixel map line - each bit 
     * in the line determines whether pixel exists (1 - pixel, 0 - no pixel). Consecutive font characters have to be arranged 
     * linearly in the array (representing a 2-D array in one dimension) and ordered according to the ASCII table.
     * Order of the pixel map lines for a character should be kept horizontally from the left top corner to the right bottom corner.
     */
    const uint8_t               *pixelMap;

    const uint16_t              lines;          /**< Number of pixel map lines horizontally per single character */
    const uint16_t              fullLines;      /**< Number of the full horizontal pixel map lines (all bits of the line are interpretable) of the single character */
    const uint16_t              lastLine;       /**< Number of interpretable bits in the last horizontal line of the single character */
};

/**
 * @brief Gets information about pixel existance in specific position of the font character.
 * 
 * @param font Pointer to the selected font
 * @param character Selected character of the font
 * @param x Position of the pixel in X-axis
 * @param y Position of the pixel in Y-axis
 * @param pixelOut Pointer to variable where information of the pixel existance will be stored (1 - pixel, 0 - no pixel)
 * @return true Information about pixel existance has been stored successfully
 * @return false Invalid values of the function parameters
 */
bool lcd_font_get_pixel(const LCD_font_t * const font, const char character, const uint16_t x, const uint16_t y, bool * const pixelOut);

#endif /* LCD_FONT_H */
