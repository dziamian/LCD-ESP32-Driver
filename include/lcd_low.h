/**
 * @file lcd_low.h
 * @author Damian Ślusarczyk
 * @brief Contains all structures required to proper communication with LCD display using different controllers.
 * 
 */
#ifndef LCD_LOW_H
#define LCD_LOW_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "lcd_error_codes.h"
#include "lcd_image.h"
#include "lcd_font.h"

typedef struct LCD_com_t            LCD_com_t;
typedef struct LCD_com_t *          LCD_com_handle_t;
typedef struct LCD_controller_t     LCD_controller_t;
typedef struct LCD_controller_t *   LCD_controller_handle_t;
typedef struct LCD_t                LCD_t;
typedef struct LCD_t *              LCD_handle_t;

/**
 * @brief 
 * 
 */
struct LCD_com_t
{
    bool (*write_cmd)(LCD_handle_t base, const uint8_t cmd);
    bool (*write_single_bytes)(LCD_handle_t base, const uint8_t *data, const size_t dataSize);
    bool (*write_two_bytes)(LCD_handle_t base, const uint16_t data);
};

/**
 * @brief 
 * 
 */
struct LCD_controller_t
{
    LCD_error_t (*Init)(LCD_handle_t base);
    LCD_error_t (*DisplayOn)(LCD_handle_t base);
    LCD_error_t (*DisplayOff)(LCD_handle_t base);
    LCD_error_t (*DrawRect)(LCD_handle_t base, const uint16_t x, const uint16_t y, const uint16_t width, 
        const uint16_t height, const uint16_t color);
    LCD_error_t (*DrawImage)(LCD_handle_t base, const uint16_t x, const uint16_t y, const LCD_image_t *image);
    LCD_error_t (*DrawText)(LCD_handle_t base, uint16_t x, uint16_t y, const char *text, 
        const int16_t letterSpacing, const int16_t lineSpacing, const LCD_font_t *font, 
        const uint16_t fontColor, const uint16_t bgrColor);
    LCD_error_t (*ClearScreen)(LCD_handle_t base, const uint16_t color);
    LCD_error_t (*Destroy)(LCD_handle_t base);
};

/**
 * @brief Structure describing characteristics of LCD display.
 * 
 */
struct LCD_t
{
    uint16_t                    width;      /**< Width of the display in pixels */
    uint16_t                    height;     /**< Height of the display in pixels */
    LCD_com_handle_t            com;        /**<  */
    LCD_controller_handle_t     controller; /**<  */
};

#endif /* LCD_LOW_H */
