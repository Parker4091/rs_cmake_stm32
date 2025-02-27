/// @brief Mock for watchdog timer watchdog.h
#pragma once

#include "watchdog.h"

#include <cmock/cmock.h>

class MockWatchdog : public CMockMocker<MockWatchdog>
{
public:
    MockWatchdog();  ///< Default Constructor
    ~MockWatchdog(); ///< Destructor

    CMOCK_MOCK_METHOD( void, WWDG_refresh, () )
    CMOCK_MOCK_METHOD( void, WWDG_initialize, () )
    CMOCK_MOCK_METHOD( void, IWDG_refresh, () )
    CMOCK_MOCK_METHOD( void, IWDG_initialize, () )
};
