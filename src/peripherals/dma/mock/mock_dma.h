/// @brief Mock for Dma dma.h
#pragma once

#include <dma.h>

#include <cmock/cmock.h>

class MockDma : public CMockMocker<MockDma>
{
public:
    MockDma();  ///< Default Constructor
    ~MockDma(); ///< Destructor

    CMOCK_MOCK_METHOD( void, DMA_initialize, () )
};
