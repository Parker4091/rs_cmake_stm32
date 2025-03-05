/// @brief Mock for HalSys
#include "mock_stm32_hal_sys.h"

#include <cmock/cmock.h>

MockSTM32HALSys::MockSTM32HALSys()  = default;
MockSTM32HALSys::~MockSTM32HALSys() = default;

CMOCK_MOCK_FUNCTION(MockSTM32HALSys, void*, _sbrk, (ptrdiff_t incr))
