/// @brief Mock for the USART layer
#include "mock_i2c.h"

#include <cmock/cmock.h>

MockI2C::MockI2C()  = default;
MockI2C::~MockI2C() = default;

CMOCK_MOCK_FUNCTION( MockI2C, FWStatus_t, I2C_master_mem_write,
                     ( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, const uint8_t *p_data, uint16_t size,
                       uint32_t timeout_ms ) )
CMOCK_MOCK_FUNCTION( MockI2C, FWStatus_t, I2C_master_mem_read,
                     ( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, uint8_t *p_data, uint16_t size,
                       uint32_t timeout_ms ) )
CMOCK_MOCK_FUNCTION( MockI2C, void, I2C_deinit, () )
CMOCK_MOCK_FUNCTION( MockI2C, void, I2C_initialize, () )
