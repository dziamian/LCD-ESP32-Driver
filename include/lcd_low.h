#ifndef LCD_LOW_H
#define LCD_LOW_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "lcd_image.h"
#include "lcd_font.h"

typedef struct LCD_com_t            LCD_com_t;
typedef struct LCD_com_t *          LCD_com_handle_t;
typedef struct LCD_controller_t     LCD_controller_t;
typedef struct LCD_controller_t *   LCD_controller_handle_t;
typedef struct LCD_t                LCD_t;
typedef struct LCD_t *              LCD_handle_t;

struct LCD_com_t
{
    bool (*write_cmd)(LCD_handle_t base, const uint8_t cmd);
    bool (*write_single_bytes)(LCD_handle_t base, const uint8_t *data, size_t dataSize);
    bool (*write_two_bytes)(LCD_handle_t base, const uint16_t data);
};

struct LCD_controller_t
{
    bool (*Init)(LCD_handle_t base);
    bool (*DisplayOn)(LCD_handle_t base);
    bool (*DisplayOff)(LCD_handle_t base);
    bool (*DrawRect)(LCD_handle_t base, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color);
    bool (*DrawImage)(LCD_handle_t base, const uint16_t x, const uint16_t y, const LCD_image_t *image);
    bool (*DrawText)(LCD_handle_t base, uint16_t x, const uint16_t y, const char *text, 
        const int16_t spacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor);
    bool (*ClearScreen)(LCD_handle_t base, const uint16_t color);
    void (*Destroy)(LCD_handle_t base);
};

struct LCD_t
{
    uint16_t                    width;
    uint16_t                    height;
    LCD_com_handle_t            com;
    LCD_controller_handle_t     controller;
};

#endif /* LCD_LOW_H */
