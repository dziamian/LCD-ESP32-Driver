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
#include "lcd_image.h"

/** Number of bytes per pixel */
#define LCD_IMAGE_PIXEL_BYTES       2
/** The most significant byte multiplier value for getting 16-bit full color value */
#define LCD_IMAGE_MSB_MULTIPLIER    256 

bool lcd_image_get_pixel(const LCD_image_t *image, const uint16_t x, const uint16_t y, uint16_t * const pixelOut)
{
    if (!pixelOut || x >= image->width || y >= image->height)
    {
        return false;
    }

    uint16_t index = y * image->width * LCD_IMAGE_PIXEL_BYTES + x * LCD_IMAGE_PIXEL_BYTES;
    *pixelOut = image->pixels[index] * LCD_IMAGE_MSB_MULTIPLIER + image->pixels[index + 1];
    
    return true;
}