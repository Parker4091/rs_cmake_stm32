/// @brief Mock for the DMA layer
#include "mock_dma.h"

#include <cmock/cmock.h>

MockDma::MockDma()  = default;
MockDma::~MockDma() = default;

CMOCK_MOCK_FUNCTION( MockDma, void, DMA_initialize, () )
