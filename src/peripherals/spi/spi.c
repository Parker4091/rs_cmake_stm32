/// @file  spi.h
/// @brief This file provides code for the configuration
///        of the SPI instances.
///
/// @author Siddhant Modi (sidmodi)

/************************************ Includes *********************************************/
#include "app_assert.h"
#include "board.h"
#include "dma.h"
#include "spi.h"
#include "stdbool.h"
#include "types.h"
#include <stm32l4xx_hal.h>

/*********************************** Types *************************************/
#if defined( __clang__ )
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wpadded"
#endif // defined(__clang__)

/// @brief  Structure that holds the SPI device handle and status
// NOLINTNEXTLINE(altera-struct-pack-align)
typedef struct SPIBusHandle_s
{
    SPIBusIndex_t      bus_index;       // Bus index
    SPI_HandleTypeDef *p_device_handle; // Pointer to the SPI peripheral
    SPI_eventCB_t      callback;        // Pointer to the function callback called during interrupts
    bool               enabled;
    FWStatus_t         status;          // Status
} SPIBusHandle_t;

#if defined( __clang__ )
#    pragma clang diagnostic pop
#endif // defined(__clang__)

/********************************** Constants *******************************************/
#define SPI_DEFAULT_CRC_POLYNOMIAL ( 7 )

/********************************** Local Variables *************************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static SPI_HandleTypeDef hspi1, hspi2, hspi3;

static DMA_HandleTypeDef hdma_spi1_rx;
static DMA_HandleTypeDef hdma_spi3_rx;

static SPIBusHandle_t spi1 = { .bus_index = SPIBus1, .p_device_handle = &hspi1, .callback = NULL, .status = FW_OK };
static SPIBusHandle_t spi2 = { .bus_index = SPIBus2, .p_device_handle = &hspi2, .callback = NULL, .status = FW_OK };
static SPIBusHandle_t spi3 = { .bus_index = SPIBus3, .p_device_handle = &hspi3, .callback = NULL, .status = FW_OK };

static SPIBusHandle_t *const g_spi_bus_handles[] = { &spi1, &spi2, &spi3 };
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/*******************************Local Function Declarations *******************************/

/// @brief This function handles SPI3 global interrupt.
void SPI3_IRQHandler( void );

/// @brief This function handles DMA1 channel1 global interrupt.
void DMA1_Channel1_IRQHandler( void );

/// @brief This function handles DMA1 channel2 global interrupt.
void DMA1_Channel2_IRQHandler( void );

/// @brief SPI Rx Complete Callback
static void SPI_RxCpltCallback( SPI_HandleTypeDef *hspi );

/// @brief SPI Tx Complete Callback
static void SPI_TxCpltCallback( SPI_HandleTypeDef *hspi );

static void SPI_MspInit( SPI_HandleTypeDef *hspi );

/// @brief SPI3 DMA init function
static void DMA_SPI3_init( void );

/// @brief SPI3 DMA deinit function
static void DMA_SPI3_deinit( void );

/// @brief SPI3 init function
static void SPI3_enable( void );

/// @brief SPI3 deinit function
static void SPI3_deinit( void );

/// @brief This function triggers the callback registered with the timer in question
/// @param[in] p_spi_device Pointer to the timer device for which the callback will be triggered
/// @param[in] event_type The event which caused the interrupt
static inline void trigger_callback( SPI_HandleTypeDef *p_spi_device, SPI_EventType_t event_type );

/****************************** Private Function Definitions ***********************************/

void SPI3_IRQHandler()
{
    HAL_SPI_IRQHandler( &hspi3 );
}

void DMA1_Channel1_IRQHandler()
{
    HAL_DMA_IRQHandler( &hdma_spi1_rx );
}

void DMA1_Channel2_IRQHandler()
{
    HAL_DMA_IRQHandler( &hdma_spi3_rx );
}

void SPI_RxCpltCallback( SPI_HandleTypeDef *hspi )
{
    trigger_callback( hspi, SPI_Event_Rx );
}

void SPI_TxCpltCallback( SPI_HandleTypeDef *hspi )
{
    trigger_callback( hspi, SPI_Event_Tx );
}

void SPI_MspInit( SPI_HandleTypeDef *hspi )
{
    if( hspi->Instance == SPI3 )
    {
        // SPI3 clock enable
        __HAL_RCC_SPI3_CLK_ENABLE();

        // Init the GPIO
        GPIO_SPI3_initialize();

        // SPI3 DMA Init
        DMA_SPI3_init();
        __HAL_LINKDMA( spi3.p_device_handle, hdmarx, hdma_spi3_rx );

        // SPI3 interrupt Init
        HAL_NVIC_SetPriority( SPI3_IRQn, 0, 0 );
        HAL_NVIC_EnableIRQ( SPI3_IRQn );

        // DMA1_Channel2_IRQn interrupt configuration
        HAL_NVIC_SetPriority( DMA1_Channel2_IRQn, 0, 0 );
        HAL_NVIC_EnableIRQ( DMA1_Channel2_IRQn );
    }
}

void DMA_SPI3_init()
{
    // SPI3_RX Init
    hdma_spi3_rx.Instance                 = DMA1_Channel2;
    hdma_spi3_rx.Init.Request             = DMA_REQUEST_SPI3_RX;
    hdma_spi3_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_spi3_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_spi3_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_spi3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi3_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_spi3_rx.Init.Mode                = DMA_NORMAL;
    hdma_spi3_rx.Init.Priority            = DMA_PRIORITY_LOW;
    app_assert( HAL_DMA_Init( &hdma_spi3_rx ) == HAL_OK );
}

void DMA_SPI3_deinit()
{
    HAL_DMA_DeInit( &hdma_spi3_rx );
}

void SPI3_enable()
{
    if( !spi3.enabled )
    {
        app_assert( HAL_SPI_RegisterCallback( spi3.p_device_handle, HAL_SPI_MSPINIT_CB_ID, SPI_MspInit ) == HAL_OK );

        spi3.p_device_handle->Instance               = SPI3;
        spi3.p_device_handle->Init.Mode              = SPI_MODE_MASTER;
        spi3.p_device_handle->Init.Direction         = SPI_DIRECTION_2LINES;
        spi3.p_device_handle->Init.DataSize          = SPI_DATASIZE_8BIT;
        spi3.p_device_handle->Init.CLKPolarity       = SPI_POLARITY_HIGH;
        spi3.p_device_handle->Init.CLKPhase          = SPI_PHASE_2EDGE;
        spi3.p_device_handle->Init.NSS               = SPI_NSS_SOFT;
        spi3.p_device_handle->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; // TODO(smodi): Change back to 2?
        spi3.p_device_handle->Init.FirstBit          = SPI_FIRSTBIT_MSB;
        spi3.p_device_handle->Init.TIMode            = SPI_TIMODE_DISABLE;
        spi3.p_device_handle->Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
        spi3.p_device_handle->Init.CRCPolynomial     = SPI_DEFAULT_CRC_POLYNOMIAL;
        spi3.p_device_handle->Init.CRCLength         = SPI_CRC_LENGTH_DATASIZE;
        spi3.p_device_handle->Init.NSSPMode          = SPI_NSS_PULSE_DISABLE;
        app_assert( HAL_SPI_Init( spi3.p_device_handle ) == HAL_OK );

        // Register the callbacks
        app_assert( HAL_SPI_RegisterCallback( spi3.p_device_handle, HAL_SPI_RX_COMPLETE_CB_ID, SPI_RxCpltCallback ) == HAL_OK );
        app_assert( HAL_SPI_RegisterCallback( spi3.p_device_handle, HAL_SPI_TX_COMPLETE_CB_ID, SPI_TxCpltCallback ) == HAL_OK );

        spi3.enabled = true;
    }
}

void SPI3_deinit()
{
    if( spi3.enabled )
    {
        // Peripheral clock disable
        __HAL_RCC_SPI3_CLK_DISABLE();

        // Deinit the GPIO
        GPIO_SPI3_deinit();

        // SPI3 DMA DeInit
        DMA_SPI3_deinit();

        // SPI3 interrupt Deinit
        HAL_NVIC_DisableIRQ( SPI3_IRQn );

        // De-register the callbacks
        HAL_SPI_UnRegisterCallback( spi3.p_device_handle, HAL_SPI_RX_COMPLETE_CB_ID );
        HAL_SPI_UnRegisterCallback( spi3.p_device_handle, HAL_SPI_TX_COMPLETE_CB_ID );

        HAL_SPI_DeInit( spi3.p_device_handle );

        spi3.enabled = false;
    }
}

void trigger_callback( SPI_HandleTypeDef *p_spi_device, SPI_EventType_t event_type )
{
    for( SPIBusIndex_t i = (SPIBusIndex_t)0; i < NumSPIBuses; i++ )
    {
        if( g_spi_bus_handles[i]->p_device_handle == p_spi_device )
        {
            if( g_spi_bus_handles[i]->callback != NULL )
            {
                g_spi_bus_handles[i]->callback( event_type );
            }
            break;
        }
    }
}

/****************************** Public Function Definitions ***********************************/
FWStatus_t SPI_master_transmit( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_Transmit( spi_bus->p_device_handle, p_data, size, timeout_ms );
    return spi_bus->status;
}

FWStatus_t SPI_master_transmit_IT( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_Transmit_IT( spi_bus->p_device_handle, p_data, size );
    return spi_bus->status;
}

FWStatus_t SPI_master_transmitreceive( SPIBusIndex_t spi_interface, uint8_t *p_data, uint8_t *r_data, uint16_t size, uint32_t timeout_ms )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_TransmitReceive( spi_bus->p_device_handle, p_data, r_data, size, timeout_ms );
    return spi_bus->status;
}

FWStatus_t SPI_master_transmit_DMA( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_Transmit_DMA( spi_bus->p_device_handle, p_data, size );
    return spi_bus->status;
}

FWStatus_t SPI_master_receive( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_Receive( spi_bus->p_device_handle, p_data, size, timeout_ms );
    return spi_bus->status;
}

FWStatus_t SPI_master_receive_IT( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_Receive_IT( spi_bus->p_device_handle, p_data, size );
    return spi_bus->status;
}

FWStatus_t SPI_master_receive_DMA( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size )
{
    SPIBusHandle_t *spi_bus = NULL;
    app_assert( spi_interface < NumSPIBuses );
    spi_bus         = g_spi_bus_handles[spi_interface];
    spi_bus->status = (FWStatus_t)HAL_SPI_Receive_DMA( spi_bus->p_device_handle, p_data, size );
    return spi_bus->status;
}

void SPI_register_callback( SPIBusIndex_t spi_interface, SPI_eventCB_t spi_event_callback )
{
    app_assert( spi_interface < NumSPIBuses );
    g_spi_bus_handles[spi_interface]->callback = spi_event_callback;
}

void SPI_deinit( void )
{
    SPI3_deinit();
}

void SPI_initialize( void )
{
    SPI3_enable();
}
