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
#include "spi.h"

#include <string.h>

#include "driver/gpio.h"

#define SPI_1BYTE_SIZE        8     /**< Number of bits in one byte */
#define SPI_2BYTES_SIZE       16    /**< Number of bits in two bytes */

#define SPI_COMMAND           0     /**< SPI DC pin value for sending commands */
#define SPI_DATA              1     /**< SPI DC pin value for sending data */

#define SPI_MODE              0     /**< SPI mode for communicating with devices */

typedef struct spi_user_t   spi_user_t;

/**
 * @brief Structure containing information required to communicating properly with the device that uses DC pin.
 * 
 */
struct spi_user_t
{
    int dc_gpio;    /**< GPIO chosen for DC pin */
    int dc_value;   /**< GPIO value to be set */
};

/**
 * @brief Callback to be called before a SPI transmission is started.
 * 
 * Sets DC pin according to the value passed in the user property of the SPI transaction.
 * 
 * @param t SPI transaction to transmit
 */
static void spi_pre_transfer_dc_callback(spi_transaction_t *t);

spi_error_t spi_init(const int miso, const int mosi, const int sclk, const int wp, const int hd, const int cs, const int maxTransferSize, 
    const int queueSize, const int clockSpeedHz, const spi_host_device_t host, const spi_dma_chan_t dma, spi_device_handle_t * const spi)
{
    if (!spi)
    {
        return SPI_INV_ARG;
    }

    spi_bus_config_t busConfig =
    {
        .miso_io_num = miso,
        .mosi_io_num = mosi,
        .sclk_io_num = sclk,
        .quadwp_io_num = wp,
        .quadhd_io_num = hd,
        .max_transfer_sz = maxTransferSize,
    };

    spi_device_interface_config_t deviceConfig = 
    {
        .clock_speed_hz = clockSpeedHz,
        .mode = SPI_MODE,
        .spics_io_num = cs,
        .queue_size = queueSize,
        .pre_cb = spi_pre_transfer_dc_callback
    };

    if (ESP_OK != spi_bus_initialize(host, &busConfig, dma))
    {
        return SPI_CONF_FAIL;
    }

    if (ESP_OK != spi_bus_add_device(host, &deviceConfig, spi))
    {
        return SPI_CONF_FAIL;
    }

    return SPI_OK;
}

spi_error_t spi_free(spi_host_device_t host)
{
    if (ESP_OK != spi_bus_free(host))
    {
        return SPI_OP_FAIL;
    }

    return SPI_OK;
}

spi_error_t spi_send_cmd(spi_device_handle_t spi, const int dcGpio, const uint8_t cmd)
{
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = SPI_1BYTE_SIZE;
    t.tx_buffer = &cmd;
    spi_user_t user = {
        .dc_gpio = dcGpio,
        .dc_value = SPI_COMMAND
    };
    t.user = (void *) &user;
    return (ESP_OK == spi_device_polling_transmit(spi, &t)) ? SPI_OK : SPI_OP_FAIL;
}

spi_error_t spi_send_single_bytes(spi_device_handle_t spi, const int dcGpio, const uint8_t *data, const size_t dataSize)
{
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = dataSize * SPI_1BYTE_SIZE;
    t.tx_buffer = data;
    spi_user_t user = {
        .dc_gpio = dcGpio,
        .dc_value = SPI_DATA
    };
    t.user = (void *) &user;
    return (ESP_OK == spi_device_polling_transmit(spi, &t)) ? SPI_OK : SPI_OP_FAIL;
}

spi_error_t spi_send_two_bytes(spi_device_handle_t spi, const int dcGpio, uint16_t data)
{
    data = SPI_SWAP_DATA_TX(data, SPI_2BYTES_SIZE);
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.length = SPI_2BYTES_SIZE;
    t.tx_buffer = &data;
    spi_user_t user = {
        .dc_gpio = dcGpio,
        .dc_value = SPI_DATA
    };
    t.user = (void *) &user;
    return (ESP_OK == spi_device_polling_transmit(spi, &t)) ? SPI_OK : SPI_OP_FAIL;
}

static void spi_pre_transfer_dc_callback(spi_transaction_t *t)
{
    spi_user_t user = *(spi_user_t *) t->user;
    gpio_set_level(user.dc_gpio, user.dc_value);
}