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
 * @file lcd_ssd1283a.h
 * @author Damian Ślusarczyk
 * @brief Contains interface implementation of the LCD driver to work with SSD1283A controller.
 * 
 */
#ifndef LCD_SSD1283A_H
#define LCD_SSD1283A_H

#include "lcd_spi.h"

#define SSD1283A_SPI_MAX_TRANSFER_SIZE  648             /**< Preferred maximum size of data to be transferred through SPI line during one transaction */
#define SSD1283A_SPI_QUEUE_SIZE         7               /**< Preferred SPI transaction queue size */
#define SSD1283A_SPI_CLOCK_SPEED        10*1000*1000    /**< Preferred SPI bus frequency in Hz */

#define SSD1283A_WIDTH                  132             /**< Width of the LCD screen in pixels */
#define SSD1283A_HEIGHT                 132             /**< Height of the LCD screen in pixels */

/**
 * @brief Creates the instance of LCD driver to communicate with SSD1283A controller using SPI interface.
 * 
 * @note Memory for LCD driver instance is allocated dynamically.
 * 
 * @param spi Handle for the SPI bus device
 * @param dc GPIO value for DC (data/command) pin
 * @param reset GPIO value for RESET pin
 * @return LCD_handle_t Handle for LCD driver instance or NULL if out of memory
 */
LCD_handle_t lcd_ssd1283a_spi__Create(spi_device_handle_t spi, const int dc, const int reset);

#endif /* LCD_SSD1283A_H */
