/// @file  fmc.h
/// @brief This file provides code for the configuration
///        of the FMC peripheral.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "app_assert.h"
#include "board.h"
#include "fmc.h"
#include "stdbool.h"
#include "stm32h7rsxx_hal.h"
#include "types.h"

/************************************ Types *********************************************/

/********************************** Constants *******************************************/

/********************************** Local Variables *************************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static SRAM_HandleTypeDef hsram1;
static uint32_t           FMC_Initialized   = 0;
static uint32_t           FMC_DeInitialized = 0;
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/****************************** Local Function Declarations ******************************/

/****************************** Function Definitions ***********************************/

// FMC initialization function
void MX_FMC_Init( void )
{
    FMC_NORSRAM_TimingTypeDef Timing = { 0 };

    // Perform the SRAM1 memory initialization sequence
    hsram1.Instance = FMC_NORSRAM_DEVICE;
    hsram1.Extended = FMC_NORSRAM_EXTENDED_DEVICE;

    // hsram1.Init
    hsram1.Init.NSBank             = FMC_NORSRAM_BANK2;
    hsram1.Init.DataAddressMux     = FMC_DATA_ADDRESS_MUX_DISABLE;
    hsram1.Init.MemoryType         = FMC_MEMORY_TYPE_SRAM;
    hsram1.Init.MemoryDataWidth    = FMC_NORSRAM_MEM_BUS_WIDTH_16;
    hsram1.Init.BurstAccessMode    = FMC_BURST_ACCESS_MODE_DISABLE;
    hsram1.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
    hsram1.Init.WaitSignalActive   = FMC_WAIT_TIMING_BEFORE_WS;
    hsram1.Init.WriteOperation     = FMC_WRITE_OPERATION_DISABLE;
    hsram1.Init.WaitSignal         = FMC_WAIT_SIGNAL_DISABLE;
    hsram1.Init.ExtendedMode       = FMC_EXTENDED_MODE_DISABLE;
    hsram1.Init.AsynchronousWait   = FMC_ASYNCHRONOUS_WAIT_ENABLE;
    hsram1.Init.WriteBurst         = FMC_WRITE_BURST_DISABLE;
    hsram1.Init.ContinuousClock    = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
    hsram1.Init.WriteFifo          = FMC_WRITE_FIFO_ENABLE;
    hsram1.Init.NBLSetupTime       = 0;
    hsram1.Init.PageSize           = FMC_PAGE_SIZE_NONE;

    // Timing
    // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    Timing.AddressSetupTime      = 15;
    Timing.AddressHoldTime       = 15;
    Timing.DataSetupTime         = 255;
    Timing.DataHoldTime          = 0;
    Timing.BusTurnAroundDuration = 15;
    Timing.CLKDivision           = 16;
    Timing.DataLatency           = 17;
    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    Timing.AccessMode = FMC_ACCESS_MODE_A;
    // ExtTiming

    HAL_SRAM_Init( &hsram1, &Timing, NULL );
}

static void HAL_FMC_MspInit( void )
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if( FMC_Initialized )
    {
        return;
    }
    FMC_Initialized = 1;

    // Peripheral clock enable
    __HAL_RCC_FMC_CLK_ENABLE();

    // GPIO_InitStruct
    GPIO_InitStruct.Pin = GPIO_PIN_3 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 |
                          GPIO_PIN_15 | GPIO_PIN_0 | GPIO_PIN_1;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

    HAL_GPIO_Init( GPIOE, &GPIO_InitStruct );

    // GPIO_InitStruct
    GPIO_InitStruct.Pin =
        GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

    HAL_GPIO_Init( GPIOF, &GPIO_InitStruct );

    // GPIO_InitStruct
    GPIO_InitStruct.Pin       = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_9;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

    HAL_GPIO_Init( GPIOG, &GPIO_InitStruct );

    // GPIO_InitStruct
    GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 | GPIO_PIN_0 |
                          GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

    HAL_GPIO_Init( GPIOD, &GPIO_InitStruct );
}

void HAL_SRAM_MspInit( SRAM_HandleTypeDef *hsram )
{
    (void)hsram;
    HAL_FMC_MspInit();
}

static void HAL_FMC_MspDeInit( void )
{
    if( FMC_DeInitialized )
    {
        return;
    }
    FMC_DeInitialized = 1;

    // Peripheral clock enable
    __HAL_RCC_FMC_CLK_DISABLE();

    HAL_GPIO_DeInit( GPIOE, GPIO_PIN_3 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 |
                                GPIO_PIN_15 | GPIO_PIN_0 | GPIO_PIN_1 );

    HAL_GPIO_DeInit( GPIOF, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 |
                                GPIO_PIN_15 );

    HAL_GPIO_DeInit( GPIOG, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_9 );

    HAL_GPIO_DeInit( GPIOD, GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15 | GPIO_PIN_0 |
                                GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 );
}

void HAL_SRAM_MspDeInit( SRAM_HandleTypeDef *hsram )
{
    (void)hsram;
    HAL_FMC_MspDeInit();
}
