/// @brief Mock for CMSIS Device headers
#include "mock_cmsis_device_h7rs.h"

#include <cmock/cmock.h>

namespace
{
constexpr auto DefaultSystemCoreClock = 4000000U;
} // namespace

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
uint32_t SystemCoreClock = DefaultSystemCoreClock;

const uint8_t  AHBPrescTable[16] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U };
const uint8_t  APBPrescTable[8]  = { 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U };
const uint32_t MSIRangeTable[12] = { 100000U,  200000U,  400000U,   800000U,   1000000U,  2000000U,
                                     4000000U, 8000000U, 16000000U, 24000000U, 32000000U, 48000000U };

MockCmsisDevice::MockCmsisDevice()  = default;
MockCmsisDevice::~MockCmsisDevice() = default;

CMOCK_MOCK_FUNCTION( MockCmsisDevice, void, SystemInit, () )
CMOCK_MOCK_FUNCTION( MockCmsisDevice, void, SystemCoreClockUpdate, () )
