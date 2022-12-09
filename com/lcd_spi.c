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
#include "lcd_spi.h"

#include "spi.h"

/**
 * @brief Sends command address to the LCD display using SPI protocol.
 * 
 * @param base Handle for the base structure of LCD driver 
 * @param cmd Command address to be sent
 * @return true The operation has been done successfully
 * @return false The operation failed
 */
static bool lcd_spi_write_cmd(LCD_handle_t base, const uint8_t cmd);

/**
 * @brief Sends data bytes to the LCD display using SPI protocol.
 * 
 * @param base Handle for the base structure of LCD driver 
 * @param data Pointer to array of data bytes to be sent
 * @param dataSize Number of data bytes included in the array
 * @return true The operation has been done successfully
 * @return false The operation failed
 */
static bool lcd_spi_write_single_bytes(LCD_handle_t base, const uint8_t *data, const size_t dataSize);

/**
 * @brief Sends exactly two bytes of data to the LCD display using SPI protocol.
 * 
 * @param base Handle for the base structure of LCD driver 
 * @param data Data to be sent (exactly 2 bytes)
 * @return true The operation has been done successfully
 * @return false The operation failed
 */
static bool lcd_spi_write_two_bytes(LCD_handle_t base, const uint16_t data);

/** Instance of LCD SPI communication interface */
static const LCD_com_t lcd_spi =
{
    .write_cmd = lcd_spi_write_cmd,
    .write_single_bytes = lcd_spi_write_single_bytes,
    .write_two_bytes = lcd_spi_write_two_bytes,
};

LCD_com_handle_t lcd_spi__GetCom(void)
{
    return (LCD_com_handle_t) &lcd_spi;
}

static bool lcd_spi_write_cmd(LCD_handle_t base, const uint8_t cmd)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;
    return SPI_OK == spi_send_cmd(self->spi, self->dcGpio, cmd);
}

static bool lcd_spi_write_single_bytes(LCD_handle_t base, const uint8_t *data, const size_t dataSize)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;
    return SPI_OK == spi_send_single_bytes(self->spi, self->dcGpio, data, dataSize);
}

static bool lcd_spi_write_two_bytes(LCD_handle_t base, const uint16_t data)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;
    return SPI_OK == spi_send_two_bytes(self->spi, self->dcGpio, data);
}