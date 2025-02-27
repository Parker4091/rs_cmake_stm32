/// @file types.h
/// @brief Various data types used in the project
///
/// @author Siddhant Modi (sidmodi)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes *******************************************/
#include "stdint.h"

/************************************ Types ********************************************/
typedef enum FWStatus_e
{
    FW_OK = 0,
    FW_ERROR,
    FW_BUSY,
    FW_TIMEOUT,
    FW_STATUS_COUNT
} FWStatus_t;

typedef enum SPIBusIndex_e
{
    SPIBus1 = 0,
    SPIBus2 = 1,
    SPIBus3 = 2,
    NumSPIBuses
} SPIBusIndex_t;

typedef enum TimerIndex_e
{
    TIMER1  = 0,
    TIMER2  = 1,
    TIMER3  = 2,
    TIMER4  = 3,
    TIMER5  = 4,
    TIMER6  = 5,
    TIMER7  = 6,
    TIMER8  = 7,
    TIMER15 = 8,
    TIMER16 = 9,
    TIMER17 = 10,
    TIMER_COUNT
} TimerIndex_t;

typedef enum UARTBusIndex_e
{
    UARTBus1 = 0,
    UARTBus2 = 1,
    UARTBus3 = 2,
    UARTBus4 = 3,
    UARTBus5 = 4,
    NumUARTBuses
} UARTBusIndex_t;

typedef enum I2CBusIndex_e
{
    I2CBus1 = 0,
    I2CBus2 = 1,
    I2CBus3 = 2,
    I2CBus4 = 3,
    I2CBus5 = 4,
    NumI2CBuses
} I2CBusIndex_t;

#ifdef __cplusplus
}
#endif
