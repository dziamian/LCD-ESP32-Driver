#ifndef LCD_FONT_H
#define LCD_FONT_H

#include <stdint.h>
#include <stdbool.h>

#define LCD_FONT_BYTE_LINE    8

typedef struct LCD_font_t     LCD_font_t;

struct LCD_font_t
{
    uint16_t    width;
    uint16_t    height;
    char        firstCharacter;
    uint16_t    characters;
    uint8_t     *pixelMap;

    uint16_t    lines;
    uint16_t    fullLines;
    uint16_t    lastLine;
};

bool lcd_font_character_index(const LCD_font_t *font, char character, uint16_t *indexOut);
bool lcd_font_get_pixel(const LCD_font_t *font, char character, uint16_t x, uint16_t y, uint8_t *pixelOut);

#endif /* LCD_FONT_H */
