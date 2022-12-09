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
 * @file lcd_spi.h
 * @author Damian Ślusarczyk
 * @brief Contains interface implementation of SPI communication with LCD display.
 * 
 */
#ifndef LCD_SPI_H
#define LCD_SPI_H

#include "driver/spi_master.h"

#include "lcd_low.h"

typedef struct LCD_spi_t        LCD_spi_t;
/** Handle type for LCD SPI communication interface instance */
typedef struct LCD_spi_t *      LCD_spi_handle_t;

/**
 * @brief Derived structure describing characteristics of LCD display that uses SPI protocol for communication.
 * 
 */
struct LCD_spi_t
{
    LCD_t                       base;       /**< Base structure of LCD display driver characteristics */
    spi_device_handle_t         spi;        /**< Handle for the device (LCD display) on SPI bus */
    int                         dcGpio;     /**< GPIO for DC (data/command) pin */
    int                         resetGpio;  /**< GPIO for reset pin */
};

/**
 * @brief Returns handle for interface implementation of SPI communication with LCD display.
 * 
 * @return LCD_com_handle_t Handle for interface implementation of SPI communication with LCD display
 */
LCD_com_handle_t lcd_spi__GetCom(void);

#endif /* LCD_SPI_H */
