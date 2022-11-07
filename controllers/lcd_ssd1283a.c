#include "lcd_ssd1283a.h"

#include <string.h>

#include "driver/gpio.h"

#include "lcd_ssd1283a_registers.h"

#define SSD1283A_HIGH_LEVEL             1
#define SSD1283A_LOW_LEVEL              0

#define SSD1283A_DATA_SIZE              2
#define SSD1283A_COMMAND_HANDLE_SIZE    3

#define SSD1283A_RESET_US               15

static void lcd_ssd1283a__Destroy(LCD_handle_t self);
static bool lcd_ssd1283a__Init(LCD_handle_t base);
static bool lcd_ssd1283a__DisplayOn(LCD_handle_t base);
static bool lcd_ssd1283a__DrawRect(LCD_handle_t base, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color);
static bool lcd_ssd1283a__DrawImage(LCD_handle_t base, const uint16_t x, const uint16_t y, const LCD_image_t *image);
static bool lcd_ssd1283a__DrawText(LCD_handle_t base, uint16_t x, const uint16_t y, const char *text, 
        const int16_t spacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor);
static bool lcd_ssd1283a__ClearScreen(LCD_handle_t base, const uint16_t color);

static LCD_controller_t lcd_ssd1283a =
{
    .Init           = lcd_ssd1283a__Init,
    .DisplayOn      = lcd_ssd1283a__DisplayOn,
    .DisplayOff     = NULL,
    .DrawRect       = lcd_ssd1283a__DrawRect,
    .DrawImage      = lcd_ssd1283a__DrawImage,
    .DrawText       = lcd_ssd1283a__DrawText,
    .ClearScreen    = lcd_ssd1283a__ClearScreen,
    .Destroy        = lcd_ssd1283a__Destroy,
};

static const uint8_t displayOnCommands[][SSD1283A_COMMAND_HANDLE_SIZE] =
{
    {SSD1283A_DISPLAY_CTRL, SSD1283A_DISPLAY_CTRL_INIT1_MSB, SSD1283A_DISPLAY_CTRL_INIT1_LSB},
    {SSD1283A_OSCILLATION, SSD1283A_OSCILLATION_INIT_MSB, SSD1283A_OSCILLATION_INIT_LSB},
    {SSD1283A_DISPLAY_CTRL, SSD1283A_DISPLAY_CTRL_INIT2_MSB, SSD1283A_DISPLAY_CTRL_INIT2_LSB},
    {SSD1283A_POWER_CTRL_1, SSD1283A_POWER_CTRL_1_INIT_MSB, SSD1283A_POWER_CTRL_1_INIT_LSB},
    {SSD1283A_DISPLAY_CTRL, SSD1283A_DISPLAY_CTRL_INIT3_MSB, SSD1283A_DISPLAY_CTRL_INIT3_LSB},
};

static const uint8_t initCommands[][SSD1283A_COMMAND_HANDLE_SIZE] =
{
    {SSD1283A_DRIVER_OUTPUT_CTRL, SSD1283A_DRIVER_OUTPUT_CTRL_INIT_MSB, SSD1283A_DRIVER_OUTPUT_CTRL_INIT_LSB},
    {SSD1283A_ENTRY_MODE, SSD1283A_ENTRY_MODE_INIT_MSB, SSD1283A_ENTRY_MODE_INIT_LSB},
    {SSD1283A_DRIVER_AC_CTRL, SSD1283A_DRIVER_AC_CTRL_INIT_MSB, SSD1283A_DRIVER_AC_CTRL_INIT_LSB},
};

static bool lcd_ssd1283a_draw_char(LCD_handle_t base, const uint8_t x, const uint8_t y, const char character, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor);
static bool lcd_ssd1283a_init_window(LCD_handle_t base, const uint8_t x, const uint8_t y, const uint8_t width, const uint8_t height);

LCD_handle_t lcd_ssd1283a_spi__Create(spi_device_handle_t spi, int dc, int reset)
{
    LCD_spi_handle_t self   = malloc(sizeof (LCD_spi_t));
    self->base.width        = SSD1283A_WIDTH;
    self->base.height       = SSD1283A_HEIGHT;
    self->base.com          = lcd_spi__GetCom();
    self->base.controller   = (LCD_controller_handle_t) &lcd_ssd1283a;
    self->spi               = spi;
    self->dcGpio            = dc;
    self->resetGpio         = reset;
    return (LCD_handle_t) self;
}

static void lcd_ssd1283a__Destroy(LCD_handle_t self)
{
    free(self);
}

static bool lcd_ssd1283a__Init(LCD_handle_t base)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;

    // Init non-SPI GPIOs
    gpio_set_direction(self->dcGpio, GPIO_MODE_OUTPUT);
    gpio_set_direction(self->resetGpio, GPIO_MODE_OUTPUT);

    // Reset display
    gpio_set_level(self->resetGpio, SSD1283A_LOW_LEVEL);
    ets_delay_us(SSD1283A_RESET_US);
    gpio_set_level(self->resetGpio, SSD1283A_HIGH_LEVEL);
    ets_delay_us(SSD1283A_RESET_US);

    base->controller->DisplayOn(base);

    size_t initCommandsSize = sizeof(initCommands) / sizeof(initCommands[0]);
    for (size_t i = 0; i < initCommandsSize; ++i)
    {
        base->com->write_cmd(base, initCommands[i][0]);
        base->com->write_single_bytes(base, &initCommands[i][1], 2);
    }

    return true;
}

static bool lcd_ssd1283a__DisplayOn(LCD_handle_t base)
{
    size_t displayOnCommandsSize = sizeof(displayOnCommands) / sizeof(displayOnCommands[0]);
    for (size_t i = 0; i < displayOnCommandsSize; ++i)
    {
        base->com->write_cmd(base, displayOnCommands[i][0]);
        base->com->write_single_bytes(base, &displayOnCommands[i][1], 2);
    }

    return true;
}

static bool lcd_ssd1283a__DrawRect(LCD_handle_t base, const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height, const uint16_t color)
{
    if (!lcd_ssd1283a_init_window(base, x, y, width, height))
    {
        return false;
    }

    base->com->write_cmd(base, SSD1283A_RAM_WRITE);
    uint16_t rectSize = width * height;
    for (int i = 0; i < rectSize; ++i)
    {
        base->com->write_two_bytes(base, color);
    }

    return true;
}

static bool lcd_ssd1283a__DrawImage(LCD_handle_t base, const uint16_t x, const uint16_t y, const LCD_image_t *image)
{
    if (!lcd_ssd1283a_init_window(base, x, y, image->width, image->height))
    {
        return false;
    }

    base->com->write_cmd(base, SSD1283A_RAM_WRITE);
    for (int i = 0; i < image->height; ++i)
    {
        for (int j = 0; j < image->width; ++j)
        {
            uint16_t pixel;
            if (!lcd_image_get_pixel(image, j, i, &pixel))
            {
                return false;
            }
            base->com->write_two_bytes(base, pixel);
        }
    }

    return true;
}



static bool lcd_ssd1283a__DrawText(LCD_handle_t base, uint16_t x, const uint16_t y, const char *text, 
        const int16_t spacing, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor)
{
    if (!text)
    {
        return false;
    }

    size_t textLength = strlen(text);
    for (size_t textIndex = 0; textIndex < textLength; ++textIndex)
    {
        if (!lcd_ssd1283a_draw_char(base, x, y, text[textIndex], font, fontColor, bgrColor))
        {
            return false;
        }

        x -= (font->width + spacing);
    }

    return true;
}

static bool lcd_ssd1283a__ClearScreen(LCD_handle_t base, const uint16_t color)
{
    return base->controller->DrawRect(base, SSD1283A_INIT_POS_X, SSD1283A_INIT_POS_Y, SSD1283A_WIDTH, SSD1283A_HEIGHT, color);
}

static bool lcd_ssd1283a_draw_char(LCD_handle_t base, const uint8_t x, const uint8_t y, const char character, const LCD_font_t *font, const uint16_t fontColor, const uint16_t bgrColor)
{
    if (!lcd_ssd1283a_init_window(base, x, y, font->width, font->height))
    {
        return false;
    }

    base->com->write_cmd(base, SSD1283A_RAM_WRITE);
    for (int i = 0; i < font->height; ++i)
    {
        for (int j = 0; j < font->width; ++j)
        {
            uint8_t pixel;
            if (!lcd_font_get_pixel(font, character, j, i, &pixel))
            {
                return false;
            }
            base->com->write_two_bytes(base, pixel ? fontColor : bgrColor);
        }
    }

    return true;
}

static bool lcd_ssd1283a_init_window(LCD_handle_t base, const uint8_t x, const uint8_t y, const uint8_t width, const uint8_t height)
{
    if (!width || !height)
    {
        return false;
    }

    uint8_t data[SSD1283A_DATA_SIZE];
    data[0] = x + width - 1;
    data[1] = x;
    base->com->write_cmd(base, SSD1283A_HORIZONTAL_RAM_SET);
    base->com->write_single_bytes(base, data, 2);

    data[0] = y + height - 1;
    data[1] = y;
    base->com->write_cmd(base, SSD1283A_VERTICAL_RAM_SET);
    base->com->write_single_bytes(base, data, 2);

    data[0] = y;
    data[1] = x + width - 1;
    base->com->write_cmd(base, SSD1283A_RAM_SET);
    base->com->write_single_bytes(base, data, 2);

    return true;
}