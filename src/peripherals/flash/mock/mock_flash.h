/// @brief Mock for Flash flash.h
#pragma once

#include <flash.h>

#include <cmock/cmock.h>

class MockFlash : public CMockMocker<MockFlash>
{
public:
    MockFlash();  ///< Default Constructor
    ~MockFlash(); ///< Destructor

    CMOCK_MOCK_METHOD( uint32_t, FLASH_get_error, () )
    CMOCK_MOCK_METHOD( FWStatus_t, FLASH_write_data, ( uint32_t start_address, const uint32_t *p_data, uint16_t word_count ) )
    CMOCK_MOCK_METHOD( void, FLASH_deinit, () )
    CMOCK_MOCK_METHOD( void, FLASH_initialize, () )
};
