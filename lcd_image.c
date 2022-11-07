#include "lcd_image.h"

#define LCD_IMAGE_PIXEL_BYTES       2
#define LCD_IMAGE_MSB_MULTIPLIER    256

bool lcd_image_get_pixel(const LCD_image_t *image, uint16_t x, uint16_t y, uint16_t *pixelOut)
{
    if (!pixelOut || x >= image->width || y >= image->height)
    {
        return false;
    }

    uint16_t index = y * image->width * LCD_IMAGE_PIXEL_BYTES + x * LCD_IMAGE_PIXEL_BYTES;
    *pixelOut = image->pixels[index] * LCD_IMAGE_MSB_MULTIPLIER + image->pixels[index + 1];
    return true;
}