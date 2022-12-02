#ifndef SPI_H
#define SPI_H

#include "spi_error_codes.h"

#include "driver/spi_master.h"

spi_error_t spi_init(const int miso, const int mosi, const int sclk, const int wp, const int hd, const int cs, const int maxTransferSize, 
    const int queueSize, const int clockSpeedHz, const spi_host_device_t host, const spi_dma_chan_t dma, spi_device_handle_t * const spi);
spi_error_t spi_free(spi_host_device_t host);

spi_error_t spi_send_cmd(spi_device_handle_t spi, const int dcGpio, const uint8_t cmd);
spi_error_t spi_send_single_bytes(spi_device_handle_t spi, const int dcGpio, const uint8_t *data, const size_t dataSize);
spi_error_t spi_send_two_bytes(spi_device_handle_t spi, const int dcGpio, uint16_t data);

#endif /* SPI_H */
