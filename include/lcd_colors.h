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
 * @file lcd_colors.h
 * @author Damian Ślusarczyk
 * @brief Contains values of the most basic colors in different formats as a set of macros.
 * 
 */
#ifndef LCD_COLORS_H
#define LCD_COLORS_H

#define RGB565_RED      0xF800  /**< Value of the *RED* color in RGB565 format */
#define RGB565_GREEN    0x07E0  /**< Value of the *GREEN* color in RGB565 format */
#define RGB565_BLUE     0x001F  /**< Value of the *BLUE* color in RGB565 format */
#define RGB565_BLACK    0x0000  /**< Value of the *BLACK* color in RGB565 format */
#define RGB565_WHITE    0xFFFF  /**< Value of the *WHITE* color in RGB565 format */

#endif /* LCD_COLORS_H */
