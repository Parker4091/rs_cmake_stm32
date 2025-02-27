/// @brief Mock for Crc crc.h
#pragma once

#include <crc.h>

#include <cmock/cmock.h>

class MockCrc : public CMockMocker<MockCrc>
{
public:
    MockCrc();  ///< Default Constructor
    ~MockCrc(); ///< Destructor

    CMOCK_MOCK_METHOD( uint32_t, CRC32_calculate, ( void *buffer, uint32_t length ) )
    CMOCK_MOCK_METHOD( void, CRC32_deinit, () )
    CMOCK_MOCK_METHOD( void, CRC32_initialize, () )

    CMOCK_MOCK_METHOD( uint16_t, CRC16_calculate, ( void *buffer, uint32_t length ) )
    CMOCK_MOCK_METHOD( void, CRC16_deinit, () )
    CMOCK_MOCK_METHOD( void, CRC16_initialize, () )
};
