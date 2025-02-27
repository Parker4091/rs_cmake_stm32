/// @brief Mock for the Flash layer
#include "mock_flash.h"

#include <cmock/cmock.h>

MockFlash::MockFlash()  = default;
MockFlash::~MockFlash() = default;

CMOCK_MOCK_FUNCTION( MockFlash, uint32_t, FLASH_get_error, () )
CMOCK_MOCK_FUNCTION( MockFlash, FWStatus_t, FLASH_write_data, ( uint32_t start_address, const uint32_t *p_data, uint16_t word_count ) )
CMOCK_MOCK_FUNCTION( MockFlash, void, FLASH_deinit, () )
CMOCK_MOCK_FUNCTION( MockFlash, void, FLASH_initialize, () )
