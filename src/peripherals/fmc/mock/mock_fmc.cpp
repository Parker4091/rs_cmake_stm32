/// @brief Mock for the FMC layer
#include "mock_fmc.h"

#include <cmock/cmock.h>

MockFmc::MockFmc()  = default;
MockFmc::~MockFmc() = default;

CMOCK_MOCK_FUNCTION(MockFmc, void, MX_FMC_Init, ())
