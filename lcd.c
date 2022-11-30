#include "lcd.h"

bool lcd__Init(LCD_handle_t device)
{
    if (!device || !device->controller || !device->controller->Init)
    {
        return false;
    }

    return device->controller->Init(device);
}

bool lcd__DisplayOn(LCD_handle_t device)
{
    if (!device || !device->controller || !device->controller->DisplayOn)
    {
        return false;
    }

    return device->controller->DisplayOn(device);
}

bool lcd__DisplayOff(LCD_handle_t device)
{
    if (!device || !device->controller || !device->controller->DisplayOff)
    {
        return false;
    }

    return device->controller->DisplayOff(device);
}

bool lcd__DrawRect(LCD_handle_t device, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color)
{
    if (!device || !device->controller || !device->controller->DrawRect)
    {
        return false;
    }

    return device->controller->DrawRect(device, x, y, width, height, color);
}

bool lcd__DrawImage(LCD_handle_t device, const uint16_t x, const uint16_t y, const LCD_image_t *image)
{
    if (!device || !device->controller || !device->controller->DrawImage)
    {
        return false;
    }

    return device->controller->DrawImage(device, x, y, image);
}

bool lcd__DrawText(LCD_handle_t device, uint16_t x, uint16_t y, const char *text, 
        const int16_t letterSpacing, const int16_t lineSpacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor)
{
    if (!device || !device->controller || !device->controller->DrawText)
    {
        return false;
    }

    return device->controller->DrawText(device, x, y, text, letterSpacing, lineSpacing, font, fontColor, bgrColor);
}

bool lcd__ClearScreen(LCD_handle_t device, const uint16_t color)
{
    if (!device || !device->controller || !device->controller->ClearScreen)
    {
        return false;
    }

    return device->controller->ClearScreen(device, color);
}

bool lcd__Destroy(LCD_handle_t *device)
{
    if (!(*device) || !(*device)->controller || !(*device)->controller->Destroy)
    {
        return false;
    }

    (*device)->controller->Destroy(*device);
    *device = NULL;
    
    return true;
}