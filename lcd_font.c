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
#include "lcd_font.h"

#define LCD_FONT_FIRST_PIXEL_MASK   0x80    /**< Mask value for getting the first pixel in the character line */

/**
 * @brief Gets single pixel map line from the specific position of the font character. 
 * 
 * @param font Pointer to the selected font
 * @param character Selected character of the font
 * @param lineIndex Index of the pixel map line in X-axis
 * @param y Position of the pixel in Y-axis
 * @param lineOut Pointer to variable where value of the pixel map line will be stored
 * @return true Pixel map line value has been stored successfully
 * @return false Invalid values of the function parameters
 */
static bool lcd_font_get_line(const LCD_font_t * const font, const char character, const uint16_t lineIndex, const uint16_t y, uint8_t * const lineOut);

/**
 * @brief Gets index of the first pixel map line of the specific font character. 
 * 
 * @param font Pointer to the selected font
 * @param character Selected character of the font
 * @param indexOut Pointer to variable where value of the index will be stored
 * @return true Index value has been stored successfully
 * @return false Invalid values of the function parameters
 */
static bool lcd_font_character_index(const LCD_font_t * const font, const char character, uint16_t * const indexOut);

bool lcd_font_get_pixel(const LCD_font_t *font, const char character, const uint16_t x, const uint16_t y, bool * const pixelOut)
{
    if (!pixelOut)
    {
        return false;
    }

    uint8_t line;
    if (!lcd_font_get_line(font, character, x / LCD_FONT_BYTE_LINE, y, &line))
    {
        return false;
    }
    
    *pixelOut = !!(line & (LCD_FONT_FIRST_PIXEL_MASK >> (x % LCD_FONT_BYTE_LINE)));
    return true;
}

static bool lcd_font_get_line(const LCD_font_t *font, const char character, const uint16_t lineIndex, const uint16_t y, uint8_t * const lineOut)
{
    if (!lineOut)
    {
        return false;
    }

    uint16_t characterIndex;
    if (!lcd_font_character_index(font, character, &characterIndex))
    {
        return false;
    }

    if (lineIndex * LCD_FONT_BYTE_LINE >= font->width || y >= font->height)
    {
        return false;
    }
    
    *lineOut = font->pixelMap[characterIndex * font->lines * font->height + y * font->lines + lineIndex];
    return true;
}

static bool lcd_font_character_index(const LCD_font_t * const font, const char character, uint16_t * const indexOut)
{
    if (!indexOut)
    {
        return false;
    }

    *indexOut = character - font->firstCharacter;
    return *indexOut < font->characters;
}