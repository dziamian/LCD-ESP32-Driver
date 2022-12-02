#ifndef LCD_IMAGE_H
#define LCD_IMAGE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct LCD_image_t  LCD_image_t;

struct LCD_image_t
{
    const uint16_t           width;
    const uint16_t           height;
    const uint8_t            *pixels;
};

bool lcd_image_get_pixel(const LCD_image_t * const image, const uint16_t x, const uint16_t y, uint16_t * const pixelOut);

#endif /* LCD_IMAGE_H */
