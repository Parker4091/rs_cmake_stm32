/// @brief Mock for Delay delay.h
#pragma once

#include <delay.h>

#include <cmock/cmock.h>

class MockDelay : public CMockMocker<MockDelay>
{
public:
    MockDelay();  ///< Default Constructor
    ~MockDelay(); ///< Destructor

    CMOCK_MOCK_METHOD( void, DELAY_ms, ( uint32_t delay_ms ) )
};
