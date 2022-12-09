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
 * @file lcd_error_codes.h
 * @author Damian Ślusarczyk
 * @brief Contains error codes as an enumeration.
 * 
 * They describe the status of the performed operations with LCD display.
 */
#ifndef LCD_ERROR_CODES_H
#define LCD_ERROR_CODES_H

typedef enum LCD_error_t        LCD_error_t;

/**
 * @brief Describes the status of performed operation with LCD display.
 * 
 */
enum LCD_error_t
{
    LCD_OK = 0,     /**< No error occurred - everything went fine */
    LCD_INV_ARG,    /**< An invalid argument value has been passed into the function */
    LCD_INV_OP,     /**< An invalid operation - not supported by the specific implementation of LCD display driver */
    LCD_INV_RES,    /**< An error occurred while working with some resource (like image or font) */
    LCD_COM_FAIL,   /**< An error occurred while communicating with LCD display */
};

#endif /* LCD_ERROR_CODES_H */
