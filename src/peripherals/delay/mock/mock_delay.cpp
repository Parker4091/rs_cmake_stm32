/// @brief Mock for the DELAY layer
#include "mock_delay.h"

#include <cmock/cmock.h>

MockDelay::MockDelay()  = default;
MockDelay::~MockDelay() = default;

CMOCK_MOCK_FUNCTION( MockDelay, void, DELAY_ms, ( uint32_t delay_ms ) )
