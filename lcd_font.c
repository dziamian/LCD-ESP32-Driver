#include "lcd_font.h"

#define LCD_FONT_FIRST_PIXEL_MASK   0x80

static bool lcd_font_get_line(const LCD_font_t *font, char character, uint16_t lineIndex, uint16_t y, uint8_t *lineOut);

bool lcd_font_character_index(const LCD_font_t *font, char character, uint16_t *indexOut)
{
    if (!indexOut)
    {
        return false;
    }

    *indexOut = character - font->firstCharacter;
    return *indexOut < font->characters;
}

bool lcd_font_get_pixel(const LCD_font_t *font, char character, uint16_t x, uint16_t y, uint8_t *pixelOut)
{
    if (!pixelOut)
    {
        return false;
    }

    uint8_t line;
    if (!lcd_font_get_line(font, character, x / LCD_FONT_BYTE_LINE, y, &line))
    {
        return false;
    }
    
    *pixelOut = !!(line & (LCD_FONT_FIRST_PIXEL_MASK >> (x % LCD_FONT_BYTE_LINE)));
    return true;
}

static bool lcd_font_get_line(const LCD_font_t *font, char character, uint16_t lineIndex, uint16_t y, uint8_t *lineOut)
{
    if (!lineOut)
    {
        return false;
    }

    uint16_t characterIndex;
    if (!lcd_font_character_index(font, character, &characterIndex))
    {
        return false;
    }

    if (lineIndex * LCD_FONT_BYTE_LINE >= font->width || y >= font->height)
    {
        return false;
    }
    
    *lineOut = font->pixelMap[characterIndex * font->lines * font->height + y * font->lines + lineIndex];
    return true;
}