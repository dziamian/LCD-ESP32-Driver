#include "spi.h"

#include <string.h>

#include "driver/gpio.h"

#define SPI_TRANS_INIT_VALUE  0
#define SPI_1BYTE_SIZE        8
#define SPI_2BYTES_SIZE       16

#define SPI_COMMAND           0
#define SPI_DATA              1

#define SPI_MODE              0

typedef struct spi_user_t   spi_user_t;

struct spi_user_t
{
    int dc_gpio;
    int dc_value;
};

static void spi_pre_transfer_dc_callback(spi_transaction_t *t);

bool spi_init(int miso, int mosi, int sclk, int wp, int hd, int cs, int maxTransferSize, 
    int queueSize, int clockSpeedHz, spi_host_device_t host, spi_dma_chan_t dma, spi_device_handle_t *spi)
{
    if (!spi)
    {
        return false;
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
        return false;
    }

    if (ESP_OK != spi_bus_add_device(host, &deviceConfig, spi))
    {
        return false;
    }

    return true;
}

bool spi_free(spi_host_device_t host)
{
    if (ESP_OK != spi_bus_free(host))
    {
        return false;
    }

    return true;
}

bool spi_send_cmd(spi_device_handle_t spi, const int dcGpio, const uint8_t cmd)
{
    spi_transaction_t t;
    memset(&t, SPI_TRANS_INIT_VALUE, sizeof(t));
    t.length = SPI_1BYTE_SIZE;
    t.tx_buffer = &cmd;
    spi_user_t user = {
        .dc_gpio = dcGpio,
        .dc_value = SPI_COMMAND
    };
    t.user = (void *) &user;
    return ESP_OK == spi_device_polling_transmit(spi, &t);
}

bool spi_send_single_bytes(spi_device_handle_t spi, const int dcGpio, const uint8_t *data, const size_t dataSize)
{
    spi_transaction_t t;
    memset(&t, SPI_TRANS_INIT_VALUE, sizeof(t));
    t.length = dataSize * SPI_1BYTE_SIZE;
    t.tx_buffer = data;
    spi_user_t user = {
        .dc_gpio = dcGpio,
        .dc_value = SPI_DATA
    };
    t.user = (void *) &user;
    return ESP_OK == spi_device_polling_transmit(spi, &t);
}

bool spi_send_two_bytes(spi_device_handle_t spi, const int dcGpio, uint16_t data)
{
    data = SPI_SWAP_DATA_TX(data, SPI_2BYTES_SIZE);
    spi_transaction_t t;
    memset(&t, SPI_TRANS_INIT_VALUE, sizeof(t));
    t.length = SPI_2BYTES_SIZE;
    t.tx_buffer = &data;
    spi_user_t user = {
        .dc_gpio = dcGpio,
        .dc_value = SPI_DATA
    };
    t.user = (void *) &user;
    return ESP_OK == spi_device_polling_transmit(spi, &t);
}

static void spi_pre_transfer_dc_callback(spi_transaction_t *t)
{
    spi_user_t user = *(spi_user_t *) t->user;
    gpio_set_level(user.dc_gpio, user.dc_value);
}