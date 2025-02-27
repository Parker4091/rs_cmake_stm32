/// @file usart.c
/// @brief This file provides code for the configuration
///        of the USART instances.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "usart.h"
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

/// @brief  Structure that holds the UART device handle and status
// NOLINTNEXTLINE(altera-struct-pack-align)
typedef struct UARTBusHandle_s
{
    UARTBusIndex_t      bus_index;       // Bus index
    UART_HandleTypeDef *p_device_handle; // Pointer to the UART peripheral
    UART_eventCB_t      callback;        // Pointer to the function callback called during interrupts
    bool                enabled;
    FWStatus_t          status; // Status
} UARTBusHandle_t;

#if defined( __clang__ )
#    pragma clang diagnostic pop
#endif // defined(__clang__)

/********************************** Constants *******************************************/
#define UART1_DEFAULT_BAUD_RATE ( 115200 ) ///< Default Baud rate for UART1.
#define UART3_DEFAULT_BAUD_RATE ( 921600 ) ///< Default Baud rate for UART3.

/********************************** Local Variables *******************************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static UART_HandleTypeDef huart1, huart2, huart3, huart4, huart5;
static DMA_HandleTypeDef  hdma_usart1_tx, hdma_usart3_tx;

static UARTBusHandle_t uart1 = { .bus_index = UARTBus1, .p_device_handle = &huart1, .status = FW_OK };
static UARTBusHandle_t uart2 = { .bus_index = UARTBus2, .p_device_handle = &huart2, .status = FW_OK };
static UARTBusHandle_t uart3 = { .bus_index = UARTBus3, .p_device_handle = &huart3, .status = FW_OK };
static UARTBusHandle_t uart4 = { .bus_index = UARTBus4, .p_device_handle = &huart4, .status = FW_OK };
static UARTBusHandle_t uart5 = { .bus_index = UARTBus5, .p_device_handle = &huart5, .status = FW_OK };

static UARTBusHandle_t *const g_uart_bus_handles[] = { &uart1, &uart2, &uart3, &uart4, &uart5 };
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/********************************** Local Function Declarations *******************************************/
/// @brief This function handles DMA1 channel3 global interrupt.
void DMA1_Channel3_IRQHandler( void );

/// @brief This function handles DMA1 channel4 global interrupt.
void DMA1_Channel4_IRQHandler( void );

/// @brief This function handles DMA1 channel5 global interrupt.
void DMA1_Channel5_IRQHandler( void );

/// @brief This function handles USART1 global interrupt.
void USART1_IRQHandler( void );

/// @brief This function handles USART3 global interrupt.
void USART3_IRQHandler( void );

/// @brief USART Rx Complete Callback
void USART_RxCpltCallback( UART_HandleTypeDef *huart );

/// @brief USART Tx Complete Callback
void USART_TxCpltCallback( UART_HandleTypeDef *huart );

/// @brief UART1 DMA init function
static void DMA_USART1_init( void );

/// @brief UART3 DMA init function
static void DMA_USART3_init( void );

/// @brief UART1 DMA deinit function
static void DMA_USART1_deinit( void );

/// @brief UART3 DMA deinit function
static void DMA_USART3_deinit( void );

/// @brief UART1 init function
static void UART1_enable( void );

/// @brief UART3 init function
static void UART3_enable( void );

/// @brief UART1 deinit function
void UART1_deinit( void );

/// @brief UART3 deinit function
void UART3_deinit( void );

/// @brief This function triggers the callback registered with the timer in question
/// @param[in] p_uart_device Pointer to the timer device for which the callback will be triggered
/// @param[in] event_type The event which caused the interrupt
static inline void trigger_callback( UART_HandleTypeDef *p_uart_device, UART_EventType_t event_type );

/// @brief This function triggers the callback registered with the timer in question
/// @param[in] uart_interface Index of the UART bus for which the handle is requested
/// @return Pointer to the UART bus
static inline UARTBusHandle_t *UART_get_handle( UARTBusIndex_t uart_interface );

/****************************** Local Function Definitions *****************************/
void DMA1_Channel3_IRQHandler()
{
    HAL_DMA_IRQHandler( &hdma_usart3_tx );
}

void DMA1_Channel4_IRQHandler()
{
    HAL_DMA_IRQHandler( &hdma_usart1_tx );
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler( uart1.p_device_handle );
}

void USART3_IRQHandler()
{
    HAL_UART_IRQHandler( uart3.p_device_handle );
}

void USART_RxCpltCallback( UART_HandleTypeDef *huart )
{
    trigger_callback( huart, UART_Event_Rx );
}

void USART_TxCpltCallback( UART_HandleTypeDef *huart )
{
    trigger_callback( huart, UART_Event_Tx );
}

void DMA_USART1_init()
{
    /* USART1 DMA Init */
    /* USART1_TX Init */
    hdma_usart1_tx.Instance                 = DMA1_Channel4;
    hdma_usart1_tx.Init.Request             = DMA_REQUEST_USART1_TX;
    hdma_usart1_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart1_tx.Init.Mode                = DMA_NORMAL;
    hdma_usart1_tx.Init.Priority            = DMA_PRIORITY_LOW;
    HAL_DMA_Init( &hdma_usart1_tx );
}

void DMA_USART3_init()
{
    /* USART3 DMA Init */
    /* USART3_TX Init */
    hdma_usart3_tx.Instance                 = DMA1_Channel3;
    hdma_usart3_tx.Init.Request             = DMA_REQUEST_USART3_TX;
    hdma_usart3_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_usart3_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart3_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart3_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart3_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart3_tx.Init.Mode                = DMA_NORMAL;
    hdma_usart3_tx.Init.Priority            = DMA_PRIORITY_LOW;
    HAL_DMA_Init( &hdma_usart3_tx );
}

static void DMA_USART1_deinit()
{
    HAL_DMA_DeInit( &hdma_usart1_tx );
}

static void DMA_USART3_deinit()
{
    HAL_DMA_DeInit( &hdma_usart3_tx );
}

void UART1_enable()
{
    if( !uart1.enabled )
    {
        RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

        // Init the MSP items (MCU specific package)

        // USART1 clock enable
        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
        PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
        HAL_RCCEx_PeriphCLKConfig( &PeriphClkInit );
        __HAL_RCC_USART1_CLK_ENABLE();

        // Init the GPIO
        GPIO_USART1_initialize();

        // USART1 DMA enable
        DMA_USART1_init();
        __HAL_LINKDMA( uart1.p_device_handle, hdmatx, hdma_usart1_tx );

        // USART1 interrupt enable
        HAL_NVIC_SetPriority( USART1_IRQn, 0, 0 );
        HAL_NVIC_EnableIRQ( USART1_IRQn );

        /* DMA1_Channel3_IRQn interrupt configuration */
        HAL_NVIC_SetPriority( DMA1_Channel3_IRQn, 0, 0 );
        HAL_NVIC_EnableIRQ( DMA1_Channel3_IRQn );

        /// Init the peripheral
        uart1.p_device_handle->Instance                    = USART1;
        uart1.p_device_handle->Init.BaudRate               = UART1_DEFAULT_BAUD_RATE;
        uart1.p_device_handle->Init.WordLength             = UART_WORDLENGTH_8B;
        uart1.p_device_handle->Init.StopBits               = UART_STOPBITS_1;
        uart1.p_device_handle->Init.Parity                 = UART_PARITY_NONE;
        uart1.p_device_handle->Init.Mode                   = UART_MODE_TX_RX;
        uart1.p_device_handle->Init.HwFlowCtl              = UART_HWCONTROL_NONE; // Note: Pins are connected but disabling until needed
        uart1.p_device_handle->Init.OverSampling           = UART_OVERSAMPLING_16;
        uart1.p_device_handle->Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
        uart1.p_device_handle->AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
        HAL_UART_Init( uart1.p_device_handle );
        HAL_UARTEx_SetTxFifoThreshold( uart1.p_device_handle, UART_TXFIFO_THRESHOLD_1_8 );
        HAL_UARTEx_SetRxFifoThreshold( uart1.p_device_handle, UART_RXFIFO_THRESHOLD_1_8 );
        HAL_UARTEx_DisableFifoMode( uart1.p_device_handle );

        // Register the callbacks
        HAL_UART_RegisterCallback( uart1.p_device_handle, HAL_UART_RX_COMPLETE_CB_ID, USART_RxCpltCallback );
        HAL_UART_RegisterCallback( uart1.p_device_handle, HAL_UART_TX_COMPLETE_CB_ID, USART_TxCpltCallback );

        uart1.enabled = true;
    }
}

void UART3_enable()
{
    if( !uart3.enabled )
    {
        RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

        // Init the MSP items (MCU specific package)

        // USART3 clock enable
        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3;
        PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
        HAL_RCCEx_PeriphCLKConfig( &PeriphClkInit );
        __HAL_RCC_USART3_CLK_ENABLE();

        // Init the GPIO
        GPIO_USART3_initialize();

        // USART3 DMA enable
        DMA_USART3_init();
        __HAL_LINKDMA( uart3.p_device_handle, hdmatx, hdma_usart3_tx );

        // USART3 interrupt enable
        HAL_NVIC_SetPriority( USART3_IRQn, 0, 0 );
        HAL_NVIC_EnableIRQ( USART3_IRQn );

        /* DMA1_Channel4_IRQn interrupt configuration */
        HAL_NVIC_SetPriority( DMA1_Channel4_IRQn, 0, 0 );
        HAL_NVIC_EnableIRQ( DMA1_Channel4_IRQn );

        /// Init the peripheral
        uart3.p_device_handle->Instance                    = USART3;
        uart3.p_device_handle->Init.BaudRate               = UART3_DEFAULT_BAUD_RATE;
        uart3.p_device_handle->Init.WordLength             = UART_WORDLENGTH_8B;
        uart3.p_device_handle->Init.StopBits               = UART_STOPBITS_1;
        uart3.p_device_handle->Init.Parity                 = UART_PARITY_NONE;
        uart3.p_device_handle->Init.Mode                   = UART_MODE_TX_RX;
        uart3.p_device_handle->Init.HwFlowCtl              = UART_HWCONTROL_NONE; // Note: Pins are connected but disabling until needed
        uart3.p_device_handle->Init.OverSampling           = UART_OVERSAMPLING_16;
        uart3.p_device_handle->Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
        uart3.p_device_handle->AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
        HAL_UART_Init( uart3.p_device_handle );
        HAL_UARTEx_SetTxFifoThreshold( uart3.p_device_handle, UART_TXFIFO_THRESHOLD_1_8 );
        HAL_UARTEx_SetRxFifoThreshold( uart3.p_device_handle, UART_RXFIFO_THRESHOLD_1_8 );
        HAL_UARTEx_DisableFifoMode( uart3.p_device_handle );

        // Register the callbacks
        HAL_UART_RegisterCallback( uart3.p_device_handle, HAL_UART_RX_COMPLETE_CB_ID, USART_RxCpltCallback );
        HAL_UART_RegisterCallback( uart3.p_device_handle, HAL_UART_TX_COMPLETE_CB_ID, USART_TxCpltCallback );

        uart3.enabled = true;
    }
}

void UART1_deinit()
{
    if( uart1.enabled )
    {
        /* Peripheral clock disable */
        __HAL_RCC_USART1_CLK_DISABLE();

        // Deinit the GPIO
        GPIO_USART1_deinit();

        DMA_USART1_deinit();

        HAL_NVIC_DisableIRQ( USART1_IRQn );

        HAL_UART_UnRegisterCallback( uart1.p_device_handle, HAL_UART_RX_COMPLETE_CB_ID );
        HAL_UART_UnRegisterCallback( uart1.p_device_handle, HAL_UART_TX_COMPLETE_CB_ID );

        HAL_UART_DeInit( uart1.p_device_handle );

        uart1.enabled = false;
    }
}

void UART3_deinit()
{
    if( uart3.enabled )
    {
        /* Peripheral clock disable */
        __HAL_RCC_USART3_CLK_DISABLE();

        // Deinit the GPIO
        GPIO_USART3_deinit();

        DMA_USART3_deinit();

        HAL_NVIC_DisableIRQ( USART3_IRQn );

        HAL_UART_UnRegisterCallback( uart3.p_device_handle, HAL_UART_RX_COMPLETE_CB_ID );
        HAL_UART_UnRegisterCallback( uart3.p_device_handle, HAL_UART_TX_COMPLETE_CB_ID );

        HAL_UART_DeInit( uart3.p_device_handle );

        uart3.enabled = false;
    }
}

inline void trigger_callback( UART_HandleTypeDef *p_uart_device, UART_EventType_t event_type )
{
    for( UARTBusIndex_t i = (UARTBusIndex_t)0; i < NumUARTBuses; i++ )
    {
        if( g_uart_bus_handles[i]->p_device_handle == p_uart_device )
        {
            if( g_uart_bus_handles[i]->callback != NULL )
            {
                g_uart_bus_handles[i]->callback( event_type );
            }
            break;
        }
    }
}

static inline UARTBusHandle_t *UART_get_handle( UARTBusIndex_t uart_interface )
{
    app_assert( uart_interface < NumUARTBuses );
    return g_uart_bus_handles[uart_interface];
}

/****************************** Public Function Definitions *****************************/
FWStatus_t UART_master_transmit( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size, uint32_t timeout_ms )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );
    uart_bus->status          = (FWStatus_t)HAL_UART_Transmit( uart_bus->p_device_handle, p_data, size, timeout_ms );
    return uart_bus->status;
}

FWStatus_t UART_master_transmit_IT( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );
    uart_bus->status          = (FWStatus_t)HAL_UART_Transmit_IT( uart_bus->p_device_handle, p_data, size );
    return uart_bus->status;
}

FWStatus_t UART_master_transmit_DMA( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );
    uart_bus->status          = (FWStatus_t)HAL_UART_Transmit_DMA( uart_bus->p_device_handle, p_data, size );
    return uart_bus->status;
}

FWStatus_t UART_master_receive( UARTBusIndex_t uart_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );
    uart_bus->status          = (FWStatus_t)HAL_UART_Receive( uart_bus->p_device_handle, p_data, size, timeout_ms );
    return uart_bus->status;
}

FWStatus_t UART_master_receive_IT( UARTBusIndex_t uart_interface, uint8_t *p_data, uint16_t size )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );
    uart_bus->status          = (FWStatus_t)HAL_UART_Receive_IT( uart_bus->p_device_handle, p_data, size );
    return uart_bus->status;
}

FWStatus_t UART_master_abort_receive_IT( UARTBusIndex_t uart_interface )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );
    uart_bus->status          = (FWStatus_t)HAL_UART_AbortReceive_IT( uart_bus->p_device_handle );
    return uart_bus->status;
}

void UART_register_callback( UARTBusIndex_t uart_interface, UART_eventCB_t uart_event_callback )
{
    app_assert( uart_interface < NumUARTBuses );
    g_uart_bus_handles[uart_interface]->callback = uart_event_callback;
}

bool UART_is_rx_busy( UARTBusIndex_t uart_interface )
{
    UARTBusHandle_t *uart_bus = UART_get_handle( uart_interface );

    return ( uart_bus->p_device_handle->RxState == HAL_UART_STATE_BUSY_RX );
}

void UART_deinit( void )
{
    UART1_deinit();
    UART3_deinit();
}

void UART_initialize( void )
{
    UART1_enable();
    UART3_enable();
}
