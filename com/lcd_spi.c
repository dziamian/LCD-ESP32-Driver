#include "lcd_spi.h"

#include "spi.h"

static bool lcd_spi_write_cmd(LCD_handle_t base, const uint8_t cmd);
static bool lcd_spi_write_single_bytes(LCD_handle_t base, const uint8_t *data, const size_t dataSize);
static bool lcd_spi_write_two_bytes(LCD_handle_t base, const uint16_t data);

static LCD_com_t lcd_spi =
{
    .write_cmd = lcd_spi_write_cmd,
    .write_single_bytes = lcd_spi_write_single_bytes,
    .write_two_bytes = lcd_spi_write_two_bytes,
};

LCD_com_handle_t lcd_spi__GetCom(void)
{
    return (LCD_com_handle_t) &lcd_spi;
}

static bool lcd_spi_write_cmd(LCD_handle_t base, const uint8_t cmd)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;
    return SPI_OK == spi_send_cmd(self->spi, self->dcGpio, cmd);
}

static bool lcd_spi_write_single_bytes(LCD_handle_t base, const uint8_t *data, const size_t dataSize)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;
    return SPI_OK == spi_send_single_bytes(self->spi, self->dcGpio, data, dataSize);
}

static bool lcd_spi_write_two_bytes(LCD_handle_t base, const uint16_t data)
{
    LCD_spi_handle_t self = (LCD_spi_handle_t) base;
    return SPI_OK == spi_send_two_bytes(self->spi, self->dcGpio, data);
}