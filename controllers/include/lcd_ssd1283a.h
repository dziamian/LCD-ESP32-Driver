#ifndef LCD_SSD1283A_H
#define LCD_SSD1283A_H

#include "lcd_spi.h"

#define SSD1283A_MAX_TRANSFER_SIZE      648
#define SSD1283A_QUEUE_SIZE             7
#define SSD1283A_CLOCK_SPEED            10*1000*1000

#define SSD1283A_INIT_POS_X             0
#define SSD1283A_INIT_POS_Y             0
#define SSD1283A_WIDTH                  132
#define SSD1283A_HEIGHT                 132

LCD_handle_t lcd_ssd1283a_spi__Create(spi_device_handle_t spi, const int dc, const int reset);

#endif /* LCD_SSD1283A_H */
