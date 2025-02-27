/// @brief Mock for the USART layer
#include "mock_watchdog.h"

#include <cmock/cmock.h>

MockWatchdog::MockWatchdog()  = default;
MockWatchdog::~MockWatchdog() = default;

CMOCK_MOCK_FUNCTION( MockWatchdog, void, WWDG_refresh, () )
CMOCK_MOCK_FUNCTION( MockWatchdog, void, WWDG_initialize, () )
CMOCK_MOCK_FUNCTION( MockWatchdog, void, IWDG_refresh, () )
CMOCK_MOCK_FUNCTION( MockWatchdog, void, IWDG_initialize, () )
