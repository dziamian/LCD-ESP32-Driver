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
/**
 * @file spi.h
 * @author Damian Ślusarczyk
 * @brief Contains functions required to communicate with device using SPI protocol.
 * 
 */
#ifndef SPI_H
#define SPI_H

#include "spi_error_codes.h"

#include "driver/spi_master.h"

/**
 * @brief Initializes SPI bus and registers the single device on it.
 * 
 * @param miso GPIO for MISO pin, or -1 if not used
 * @param mosi GPIO for MOSI pin
 * @param sclk GPIO for SCLK pin
 * @param wp GPIO for WP signal, or -1 if not used
 * @param hd GPIO for HD signal, or -1 if not used
 * @param cs GPIO for CS pin, or -1 if not used
 * @param maxTransferSize Maximum number of bytes available to send using SPI
 * @param queueSize Number of data bytes in the SPI queue
 * @param clockSpeedHz Desired frequency of SPI bus
 * @param host SPI host to initialize
 * @param dma SPI DMA channel to initialize
 * @param spi Handle for the device on SPI bus
 * @return spi_error_t Status code of the operation
 */
spi_error_t spi_init(const int miso, const int mosi, const int sclk, const int wp, const int hd, const int cs, const int maxTransferSize, 
    const int queueSize, const int clockSpeedHz, const spi_host_device_t host, const spi_dma_chan_t dma, spi_device_handle_t * const spi);

/**
 * @brief Frees SPI bus for specific host.
 * 
 * @param host SPI host to free
 * @return spi_error_t Status code of the operation
 */
spi_error_t spi_free(spi_host_device_t host);

/**
 * @brief Sends command address to the specific device available on the SPI bus.
 * 
 * @param spi Handle for the device on SPI bus
 * @param dcGpio GPIO for DC (data/command) pin
 * @param cmd Command address to be sent
 * @return spi_error_t Status code of the operation
 */
spi_error_t spi_send_cmd(spi_device_handle_t spi, const int dcGpio, const uint8_t cmd);

/**
 * @brief Sends data bytes to the specific device available on the SPI bus.
 * 
 * @param spi Handle for the device on SPI bus
 * @param dcGpio GPIO for DC (data/command) pin
 * @param data Pointer to array of data bytes to be sent
 * @param dataSize Number of data bytes included in the array
 * @return spi_error_t Status code of the operation
 */
spi_error_t spi_send_single_bytes(spi_device_handle_t spi, const int dcGpio, const uint8_t *data, const size_t dataSize);

/**
 * @brief Sends exactly two bytes of data to the specific device available on the SPI bus.
 * 
 * @param spi Handle for the device on SPI bus
 * @param dcGpio GPIO for DC (data/command) pin
 * @param data Data to be sent (exactly 2 bytes)
 * @return spi_error_t Status code of the operation
 */
spi_error_t spi_send_two_bytes(spi_device_handle_t spi, const int dcGpio, uint16_t data);

#endif /* SPI_H */
