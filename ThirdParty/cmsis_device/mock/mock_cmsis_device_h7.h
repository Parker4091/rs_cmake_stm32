/// @brief Mock for CMSIS Device L4 files
#pragma once

#include <cmock/cmock.h>

// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
extern uint32_t       SystemCoreClock;   /*!< System Clock Frequency (Core Clock) */
extern const uint8_t  AHBPrescTable[16]; /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8];  /*!< APB prescalers table values */
extern const uint32_t MSIRangeTable[12]; /*!< MSI ranges table values     */

class MockCmsisDevice : public CMockMocker<MockCmsisDevice>
{
public:
    MockCmsisDevice();  ///< Default Constructor
    ~MockCmsisDevice(); ///< Destructor

    // system_stm32h7xx.h
    CMOCK_MOCK_METHOD(void, SystemInit, ())
    CMOCK_MOCK_METHOD(void, SystemCoreClockUpdate, ())
};
