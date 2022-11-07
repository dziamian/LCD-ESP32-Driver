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
    if (!spi_init(LCD_MISO_GPIO, LCD_MOSI_GPIO, LCD_SCLK_GPIO, LCD_WP_GPIO, LCD_HOLD_GPIO, LCD_CS_GPIO, 
        SSD1283A_MAX_TRANSFER_SIZE, SSD1283A_QUEUE_SIZE, SSD1283A_CLOCK_SPEED, LCD_SPI_HOST, LCD_SPI_DMA, &spi))
    {
        ESP_LOGI(LCD_TAG, "SPI device initialization failed.");
        return;
    }

    LCD_handle_t lcd = lcd_ssd1283a_spi__Create(spi, LCD_DC_GPIO, LCD_RST_GPIO);

    if (!lcd__Init(lcd))
    {
        ESP_LOGI(LCD_TAG, "LCD device initialization failed.");
        return;
    }

    if (!lcd__ClearScreen(lcd, RGB565_WHITE))
    {
        ESP_LOGI(LCD_TAG, "Clearing screen failed.");
        return;
    }

    if (!lcd__DrawRect(lcd, SSD1283A_WIDTH / 2, SSD1283A_HEIGHT / 2, SSD1283A_WIDTH / 4, SSD1283A_HEIGHT / 4, RGB565_RED))
    {
        ESP_LOGI(LCD_TAG, "Drawing rectangle failed.");
        return;
    }
    
    if (!lcd__DrawText(lcd, 120, 10, "Temp: 25.6025 C", -2, &LCD_BASIC_FONT, RGB565_BLACK, RGB565_WHITE))
    {
        ESP_LOGI(LCD_TAG, "Drawing text failed.");
        return;
    }

    lcd__Destroy(&lcd);
}