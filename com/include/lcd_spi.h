#ifndef LCD_SPI_H
#define LCD_SPI_H

#include "driver/spi_master.h"

#include "lcd_low.h"

typedef struct LCD_spi_t        LCD_spi_t;
typedef struct LCD_spi_t *      LCD_spi_handle_t;

struct LCD_spi_t
{
    LCD_t                       base;
    spi_device_handle_t         spi;
    int                         dcGpio;
    int                         resetGpio;
};

LCD_com_handle_t lcd_spi__GetCom(void);

#endif /* LCD_SPI_H */
