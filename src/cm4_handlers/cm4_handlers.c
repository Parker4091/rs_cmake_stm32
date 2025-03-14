/// @file    cm4_handlers.c
/// @brief   Interrupt Service Routines.

/* Includes ------------------------------------------------------------------*/
#include "cm4_handlers.h"
#include "stm32h7rsxx_hal.h"

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
// NOLINTBEGIN(clang-diagnostic-missing-prototypes)

/// @brief This function handles Non maskable interrupt.
void NMI_Handler( void )
{
    while( 1 )
    {
    }
}

/// @brief This function handles Hard fault interrupt.
void HardFault_Handler( void )
{
    while( 1 )
    {
    }
}

/// @brief This function handles Memory management fault.
void MemManage_Handler( void )
{
    while( 1 )
    {
    }
}

/// @brief This function handles Prefetch fault, memory access fault.
void BusFault_Handler( void )
{
    while( 1 )
    {
    }
}

/// @brief This function handles Undefined instruction or illegal state.
void UsageFault_Handler( void )
{
    while( 1 )
    {
    }
}

/// @brief This function handles System service call via SWI instruction.
void SVC_Handler( void )
{
}

/// @brief This function handles Debug monitor.
void DebugMon_Handler( void )
{
}

/// @brief This function handles Pendable request for system service.
void PendSV_Handler( void )
{
}

/// @brief This function handles System tick timer.
void SysTick_Handler( void )
{
    HAL_IncTick();
}

// NOLINTEND(clang-diagnostic-missing-prototypes)
