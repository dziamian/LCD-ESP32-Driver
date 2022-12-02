#ifndef LCD_FONT_H
#define LCD_FONT_H

#include <stdint.h>
#include <stdbool.h>

#define LCD_FONT_BYTE_LINE    8

typedef struct LCD_font_t       LCD_font_t;

struct LCD_font_t
{
    const uint16_t              width;
    const uint16_t              height;
    const char                  firstCharacter;
    const uint16_t              characters;
    const uint8_t               *pixelMap;

    const uint16_t              lines;
    const uint16_t              fullLines;
    const uint16_t              lastLine;
};

bool lcd_font_character_index(const LCD_font_t * const font, const char character, uint16_t * const indexOut);
bool lcd_font_get_pixel(const LCD_font_t * const font, const char character, const uint16_t x, const uint16_t y, uint8_t * const pixelOut);

#endif /* LCD_FONT_H */
