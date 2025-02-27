/// @brief Mock for Spi
#pragma once

#include <spi.h>

#include <cmock/cmock.h>

class MockSpi : public CMockMocker<MockSpi>
{
public:
    MockSpi();  ///< Default Constructor
    ~MockSpi(); ///< Destructor

    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_transmit, ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms ) )
    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_transmit_DMA, ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size ) )
    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_transmit_IT, ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size ) )
    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_receive, ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms ) )
    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_receive_IT, ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size ) )
    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_receive_DMA, ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size ) )
    CMOCK_MOCK_METHOD( FWStatus_t, SPI_master_transmitreceive,
                       ( SPIBusIndex_t spi_interface, uint8_t *p_data, uint8_t *r_data, uint16_t size, uint32_t timeout_ms ) )
    CMOCK_MOCK_METHOD( void, SPI_register_callback, ( SPIBusIndex_t spi_interface, SPI_eventCB_t spi_event_callback ) )
    CMOCK_MOCK_METHOD( void, SPI_deinit, () )
    CMOCK_MOCK_METHOD( void, SPI_initialize, () )
};
