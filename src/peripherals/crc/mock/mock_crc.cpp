/// @brief Mock for the CRC layer
#include "mock_crc.h"

#include <cmock/cmock.h>

MockCrc::MockCrc()  = default;
MockCrc::~MockCrc() = default;

CMOCK_MOCK_FUNCTION( MockCrc, uint32_t, CRC32_calculate, ( void *buffer, uint32_t length ) )
CMOCK_MOCK_FUNCTION( MockCrc, void, CRC32_deinit, () )
CMOCK_MOCK_FUNCTION( MockCrc, void, CRC32_initialize, () )

CMOCK_MOCK_FUNCTION( MockCrc, uint16_t, CRC16_calculate, ( void *buffer, uint32_t length ) )
CMOCK_MOCK_FUNCTION( MockCrc, void, CRC16_deinit, () )
CMOCK_MOCK_FUNCTION( MockCrc, void, CRC16_initialize, () )
