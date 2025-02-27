/// @brief Mock for I2C i2c.h
#pragma once

#include <i2c.h>

#include <cmock/cmock.h>

class MockI2C : public CMockMocker<MockI2C>
{
public:
    MockI2C();  ///< Default Constructor
    ~MockI2C(); ///< Destructor

    CMOCK_MOCK_METHOD( FWStatus_t, I2C_master_mem_write,
                       ( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, const uint8_t *p_data, uint16_t size,
                         uint32_t timeout_ms ) )
    CMOCK_MOCK_METHOD( FWStatus_t, I2C_master_mem_read,
                       ( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, uint8_t *p_data, uint16_t size,
                         uint32_t timeout_ms ) )
    CMOCK_MOCK_METHOD( void, I2C_deinit, () )
    CMOCK_MOCK_METHOD( void, I2C_initialize, () )
};
