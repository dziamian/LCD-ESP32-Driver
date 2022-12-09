/*
 * MIT License
 *
 * Copyright (c) 2022 Damian Ślusarczyk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include "lcd.h"

LCD_error_t lcd__Init(LCD_handle_t device)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->Init)
    {
        return LCD_INV_OP;
    }

    return device->controller->Init(device);
}

LCD_error_t lcd__DisplayOn(LCD_handle_t device)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->DisplayOn)
    {
        return LCD_INV_OP;
    }

    return device->controller->DisplayOn(device);
}

LCD_error_t lcd__DisplayOff(LCD_handle_t device)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->DisplayOff)
    {
        return LCD_INV_OP;
    }

    return device->controller->DisplayOff(device);
}

LCD_error_t lcd__DrawRect(LCD_handle_t device, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->DrawRect)
    {
        return LCD_INV_OP;
    }

    return device->controller->DrawRect(device, x, y, width, height, color);
}

LCD_error_t lcd__DrawImage(LCD_handle_t device, const uint16_t x, const uint16_t y, const LCD_image_t *image)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->DrawImage)
    {
        return LCD_INV_OP;
    }

    return device->controller->DrawImage(device, x, y, image);
}

LCD_error_t lcd__DrawText(LCD_handle_t device, uint16_t x, uint16_t y, const char *text, 
        const int16_t letterSpacing, const int16_t lineSpacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->DrawText)
    {
        return LCD_INV_OP;
    }

    return device->controller->DrawText(device, x, y, text, letterSpacing, lineSpacing, font, fontColor, bgrColor);
}

LCD_error_t lcd__ClearScreen(LCD_handle_t device, const uint16_t color)
{
    if (!device || !device->controller)
    {
        return LCD_INV_ARG;
    }
    if (!device->controller->ClearScreen)
    {
        return LCD_INV_OP;
    }

    return device->controller->ClearScreen(device, color);
}

LCD_error_t lcd__Destroy(LCD_handle_t *device)
{
    if (!(*device) || !(*device)->controller)
    {
        return LCD_INV_ARG;
    }
    if (!(*device)->controller->Destroy)
    {
        return LCD_INV_OP;
    }

    LCD_error_t status = (*device)->controller->Destroy(*device);
    if (LCD_OK == status)
    {
        *device = NULL;
    }
    return status;
}