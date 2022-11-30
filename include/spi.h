#ifndef SPI_H
#define SPI_H

#include <stdbool.h>

#include "driver/spi_master.h"

bool spi_init(int miso, int mosi, int sclk, int wp, int hd, int cs, int maxTransferSize, 
    int queueSize, int clockSpeedHz, spi_host_device_t host, spi_dma_chan_t dma, spi_device_handle_t *spi);
bool spi_free(spi_host_device_t host);

bool spi_send_cmd(spi_device_handle_t spi, const int dcGpio, const uint8_t cmd);
bool spi_send_single_bytes(spi_device_handle_t spi, const int dcGpio, const uint8_t *data, const size_t dataSize);
bool spi_send_two_bytes(spi_device_handle_t spi, const int dcGpio, uint16_t data);

#endif /* SPI_H */
