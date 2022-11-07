#ifndef LCD_IMAGE_H
#define LCD_IMAGE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct LCD_image_t  LCD_image_t;

struct LCD_image_t
{
    uint16_t                width;
    uint16_t                height;
    uint8_t                 *pixels;
};

bool lcd_image_get_pixel(const LCD_image_t *image, uint16_t x, uint16_t y, uint16_t *pixelOut);

#endif /* LCD_IMAGE_H */
