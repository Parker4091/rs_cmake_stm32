/// @file i2c.c
/// @brief This file provides code for the configuration
///        of the I2C instances.
///
/// @author Parker Lloyd (plloyd)

/********************************** Includes *******************************************/
#include "i2c.h"
#include "gpio.h"

#include "app_assert.h"
#include "board.h"
#include "stdbool.h"
#include "stm32l4xx_hal.h"
#include "types.h"

/************************************ Types ********************************************/
#if defined( __clang__ )
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wpadded"
#endif // defined(__clang__)

/// @brief  Structure that holds the I2C device handle and status
// NOLINTNEXTLINE(altera-struct-pack-align)
typedef struct I2CBusHandle_s
{
    I2CBusIndex_t      bus_index;       // Bus index
    I2C_HandleTypeDef *p_device_handle; // Pointer to the I2C peripheral
    bool               enabled;
    FWStatus_t         status; // Status
} I2CBusHandle_t;

#if defined( __clang__ )
#    pragma clang diagnostic pop
#endif // defined(__clang__)

/********************************** Constants *******************************************/
//#define I2C2_DEFAULT_BAUD_RATE ( 115200 ) ///< Default Baud rate for I2C2.
//#define I2C3_DEFAULT_BAUD_RATE ( 115200 ) ///< Default Baud rate for I2C2.

/********************************** Local Variables *******************************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static I2C_HandleTypeDef hi2c1, hi2c2, hi2c3, hi2c4;

static I2CBusHandle_t i2c1 = { .bus_index = I2CBus1, .p_device_handle = &hi2c1, .status = FW_OK };
static I2CBusHandle_t i2c2 = { .bus_index = I2CBus2, .p_device_handle = &hi2c2, .status = FW_OK };
static I2CBusHandle_t i2c3 = { .bus_index = I2CBus3, .p_device_handle = &hi2c3, .status = FW_OK };
static I2CBusHandle_t i2c4 = { .bus_index = I2CBus4, .p_device_handle = &hi2c4, .status = FW_OK };

static I2CBusHandle_t *const g_i2c_bus_handles[] = { &i2c1, &i2c2, &i2c3, &i2c4 };
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/********************************** Local Function Declarations *******************************************/

/// @brief I2C2 init function
static void I2C2_enable( void );

/// @brief I2C2 deinit function
void I2C2_deinit( void );

/// @brief This function triggers the callback registered with the timer in question
/// @param[in] i2c_interface Index of the I2C bus for which the handle is requested
/// @return Pointer to the I2C bus
static inline I2CBusHandle_t *I2C_get_handle( I2CBusIndex_t i2c_interface );

/****************************** Local Function Definitions *****************************/

void I2C2_enable()
{
    if( !i2c2.enabled )
    {
        RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

        // Init the MSP items (MCU specific package)

        // I2C2 clock enable
        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C2;
        PeriphClkInit.I2c1ClockSelection   = RCC_I2C2CLKSOURCE_PCLK1;
        HAL_RCCEx_PeriphCLKConfig( &PeriphClkInit );
        __HAL_RCC_I2C2_CLK_ENABLE();

        // Init the GPIO
        GPIO_I2C2_initialize();

        /// Init the peripheral
        hi2c2.Instance = I2C2;
        //NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        hi2c2.Init.Timing           = 0x307075B1;
        hi2c2.Init.OwnAddress1      = 0;
        hi2c2.Init.AddressingMode   = I2C_ADDRESSINGMODE_7BIT;
        hi2c2.Init.DualAddressMode  = I2C_DUALADDRESS_DISABLE;
        hi2c2.Init.OwnAddress2      = 0;
        hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
        hi2c2.Init.GeneralCallMode  = I2C_GENERALCALL_DISABLE;
        hi2c2.Init.NoStretchMode    = I2C_NOSTRETCH_DISABLE;
        HAL_I2C_Init( &hi2c2 );
        HAL_I2CEx_ConfigAnalogFilter( &hi2c2, I2C_ANALOGFILTER_ENABLE );
        HAL_I2CEx_ConfigDigitalFilter( &hi2c2, 0 );

        i2c2.enabled = true;
    }
}

void I2C2_deinit()
{
    if( i2c2.enabled )
    {
        /* Peripheral clock disable */
        __HAL_RCC_I2C2_CLK_DISABLE();

        // Deinit the GPIO
        GPIO_I2C2_deinit();

        i2c2.enabled = false;
    }
}

static inline I2CBusHandle_t *I2C_get_handle( I2CBusIndex_t i2c_interface )
{
    app_assert( i2c_interface < NumI2CBuses );
    return g_i2c_bus_handles[i2c_interface];
}

/****************************** Public Function Definitions *****************************/
//NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
FWStatus_t I2C_master_mem_write( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, const uint8_t *p_data,
                                 uint16_t size, uint32_t timeout_ms )
{
    I2CBusHandle_t *i2c_bus = I2C_get_handle( i2c_interface );

// Hal driver doesn't support `const` pointers so removing cast here.
#if defined( __clang__ )
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wcast-qual"
#endif // defined(__clang__)

    i2c_bus->status         = (FWStatus_t)HAL_I2C_Mem_Write( i2c_bus->p_device_handle, devAddr, memAddr, memAddrSize, (uint8_t *)p_data, size, timeout_ms );

#if defined( __clang__ )
#    pragma clang diagnostic pop
#endif // defined(__clang__)

    return i2c_bus->status;
}

//NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
FWStatus_t I2C_master_mem_read( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, uint8_t *p_data, uint16_t size,
                                uint32_t timeout_ms )
{
    I2CBusHandle_t *i2c_bus = I2C_get_handle( i2c_interface );
    i2c_bus->status         = (FWStatus_t)HAL_I2C_Mem_Read( i2c_bus->p_device_handle, devAddr, memAddr, memAddrSize, p_data, size, timeout_ms );
    return i2c_bus->status;
}

/// @brief This function will deinit the MCU Support Package (MSP)
/// @param hi2c Pointer to I2C_HandleTypeDef - handle to deinit
void HAL_I2C_MspDeInit( I2C_HandleTypeDef *hi2c )
{
    if( hi2c->Instance == I2C2 )
    {
        I2C2_deinit();
    }
}

void I2C_deinit( void )
{
    I2C2_deinit();
}

void I2C_initialize( void )
{
    I2C2_enable();
}
