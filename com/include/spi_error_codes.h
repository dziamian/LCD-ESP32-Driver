#ifndef SPI_ERROR_CODES_H
#define SPI_ERROR_CODES_H

typedef enum spi_error_t    spi_error_t;

enum spi_error_t
{
    SPI_OK = 0,
    SPI_INV_ARG,
    SPI_CONF_FAIL,
    SPI_OP_FAIL,
};

#endif /* SPI_ERROR_CODES_H */
