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
 * @file lcd_image.h
 * @author Damian Ślusarczyk
 * @brief Contains representation of the images to be drawn on LCD display and methods that simplify the work with them.
 */
#ifndef LCD_IMAGE_H
#define LCD_IMAGE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct LCD_image_t  LCD_image_t;

/**
 * @brief Describes properties of the image to be drawn on LCD display.
 * 
 */
struct LCD_image_t
{
    const uint16_t           width;     /**< Width of the image in pixels */
    const uint16_t           height;    /**< Height of the image in pixels */
    /** 
     * Pointer to array of the image pixels. Each element of the array is interpreted as single byte of the RGB565 color (the most significant byte first). 
     * Order of the pixels should be kept horizontally from the left top corner to the right bottom corner of the image. 
     * Total size of the array should be equal 2 times the width and height of the image.
     */
    const uint8_t            *pixels;
};

/**
 * @brief Gets pixel (color value) from specific position of the image.
 * 
 * @param image Pointer to the selected image
 * @param x Position of the pixel in X-axis
 * @param y Position of the pixel in Y-axis
 * @param pixelOut Pointer to variable where value of the pixel will be stored
 * @return true Pixel value has been stored successfully
 * @return false Invalid values of the function parameters
 */
bool lcd_image_get_pixel(const LCD_image_t * const image, const uint16_t x, const uint16_t y, uint16_t * const pixelOut);

#endif /* LCD_IMAGE_H */
