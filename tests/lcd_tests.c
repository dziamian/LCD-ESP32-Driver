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
#include "lcd_tests.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "spi.h"

#include "lcd.h"
#include "lcd_colors.h"
#include "lcd_ssd1283a.h"
#include "lcd_basic_font.h"

#define LCD_TAG             "LCD"

#define LCD_SPI_HOST        VSPI_HOST
#define LCD_SPI_DMA         SPI_DMA_CH_AUTO

#define LCD_MISO_GPIO       19
#define LCD_MOSI_GPIO       23
#define LCD_SCLK_GPIO       18
#define LCD_CS_GPIO         5
#define LCD_DC_GPIO         22
#define LCD_RST_GPIO        21
#define LCD_WP_GPIO         -1
#define LCD_HOLD_GPIO       -1

void lcd_test(void)
{
    spi_device_handle_t spi;
    if (SPI_OK != spi_init(LCD_MISO_GPIO, LCD_MOSI_GPIO, LCD_SCLK_GPIO, LCD_WP_GPIO, LCD_HOLD_GPIO, LCD_CS_GPIO, 
        SSD1283A_SPI_MAX_TRANSFER_SIZE, SSD1283A_SPI_QUEUE_SIZE, SSD1283A_SPI_CLOCK_SPEED, LCD_SPI_HOST, LCD_SPI_DMA, &spi))
    {
        ESP_LOGI(LCD_TAG, "SPI device initialization failed.");
        return;
    }

    LCD_handle_t lcd = lcd_ssd1283a_spi__Create(spi, LCD_DC_GPIO, LCD_RST_GPIO);

    if (LCD_OK != lcd__Init(lcd))
    {
        ESP_LOGI(LCD_TAG, "LCD device initialization failed.");
        return;
    }

    if (LCD_OK != lcd__ClearScreen(lcd, RGB565_WHITE))
    {
        ESP_LOGI(LCD_TAG, "Clearing screen failed.");
        return;
    }

    if (LCD_OK != lcd__DrawRect(lcd, SSD1283A_WIDTH / 2, SSD1283A_HEIGHT / 2, SSD1283A_WIDTH / 4, SSD1283A_HEIGHT / 4, RGB565_RED))
    {
        ESP_LOGI(LCD_TAG, "Drawing rectangle failed.");
        return;
    }
    
    if (LCD_OK != lcd__DrawText(lcd, 120, 10, "Temp: 25.6025 C", -2, 0, &LCD_BASIC_FONT, RGB565_BLACK, RGB565_WHITE))
    {
        ESP_LOGI(LCD_TAG, "Drawing text failed.");
        return;
    }

    while (1)
    {
        if (LCD_OK != lcd__DisplayOff(lcd))
        {
            ESP_LOGI(LCD_TAG, "Turning off the display failed.");
            return;
        }

        vTaskDelay(pdMS_TO_TICKS(5000));

        if (LCD_OK != lcd__DisplayOn(lcd))
        {
            ESP_LOGI(LCD_TAG, "Turning on the display failed.");
            return;
        }

        vTaskDelay(pdMS_TO_TICKS(5000));
    }

    if (LCD_OK != lcd__Destroy(&lcd))
    {
        ESP_LOGI(LCD_TAG, "Destroying driver instance failed.");
        return;
    }
}