/// @brief Mock for Fmc fmc.h
#pragma once

#include <fmc.h>

#include <cmock/cmock.h>

class MockFmc : public CMockMocker<MockFmc>
{
public:
    MockFmc();  ///< Default Constructor
    ~MockFmc(); ///< Destructor

    CMOCK_MOCK_METHOD(void, MX_FMC_Init, ())
};
