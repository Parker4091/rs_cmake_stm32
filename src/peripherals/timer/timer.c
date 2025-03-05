/// @file  tim.h
/// @brief This file provides code for the configuration
///        of the Timer instances.
///
/// @author Siddhant Modi (sidmodi)

/****************************** Includes ************************************/
#include "app_assert.h"
#include "board.h"
#include "stm32h7rsxx_hal.h"
#include "timer.h"
#include "types.h"

/****************************** Types ******************************/
#if defined( __clang__ )
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wpadded"
#endif // defined(__clang__)

/// @brief  Structure that holds the UART device handle and status
// NOLINTNEXTLINE(altera-struct-pack-align)
typedef struct TimerHandle_s
{
    TimerIndex_t       bus_index;       // Bus index
    TIM_HandleTypeDef *p_device_handle; // Pointer to the Timer peripheral
    uint32_t           freq_Hz;         // Timer frequency in Hz
    TIMER_eventCB_t    callback;        // Pointer to the function callback called during interrupts
    bool               enabled;         // Init status
    FWStatus_t         status;          // Status
} TimerHandle_t;

#if defined( __clang__ )
#    pragma clang diagnostic pop
#endif // defined(__clang__)

typedef void ( *TIMER_enable_disable_t )( void );

/****************************** Constants ******************************/
#define MS_PER_SECOND         1000U
#define US_PER_SECOND         1000000U
#define TIMER_DEFAULT_FREQ_HZ 1000U
#define TIMER2_FREQ_HZ        TIMER_DEFAULT_FREQ_HZ
#define TIMER3_FREQ_HZ        10000U
#define TIMER4_FREQ_HZ        TIMER_DEFAULT_FREQ_HZ
#define TIMER5_FREQ_HZ        1000000U
#define TIMER15_FREQ_HZ       TIMER_DEFAULT_FREQ_HZ
#define TIMER16_FREQ_HZ       TIMER_DEFAULT_FREQ_HZ
#define TIMER17_FREQ_HZ       TIMER_DEFAULT_FREQ_HZ

/****************************** Local Function Declarations ******************************/
/// @brief This function handles TIM2 global interrupt.
void TIM2_IRQHandler( void );

/// @brief This function handles TIM3 global interrupt.
void TIM3_IRQHandler( void );

/// @brief This function handles TIM4 global interrupt.
void TIM4_IRQHandler( void );

/// @brief This function handles TIM5 global interrupt.
void TIM5_IRQHandler( void );

/// @brief This function handles TIM15 global interrupt.
void TIM1_BRK_TIM15_IRQHandler( void );

/// @brief This function handles TIM16 global interrupt.
void TIM1_UP_TIM16_IRQHandler( void );

/// @brief This function handles TIM17 global interrupt.
void TIM1_TRG_COM_TIM17_IRQHandler( void );

/// @brief This function handles all TIM period elapsed callbacks
void TIM_PeriodElapsedCallback( TIM_HandleTypeDef *htim );

/// @brief This function triggers the callback registered with the timer in question
/// @param[in] p_timer_device Pointer to the timer device for which the callback will be triggered
static inline void trigger_callback( TIM_HandleTypeDef *p_timer_device );

/// @brief TIM2 init function
static void TIMER2_enable( void );

/// @brief TIM3 init function
static void TIMER3_enable( void );

/// @brief TIM4 init function
static void TIMER4_enable( void );

/// @brief TIM5 init function
static void TIMER5_enable( void );

/// @brief TIM15 init function
static void TIMER15_enable( void );

/// @brief TIM16 init function
static void TIMER16_enable( void );

/// @brief TIM17 init function
static void TIMER17_enable( void );

/// @brief TIM2 disable function
static void TIMER2_disable( void );

/// @brief TIM3 disable function
static void TIMER3_disable( void );

/// @brief TIM4 disable function
static void TIMER4_disable( void );

/// @brief TIM5 disable function
static void TIMER5_disable( void );

/// @brief TIM15 disable function
static void TIMER15_disable( void );

/// @brief TIM16 disable function
static void TIMER16_disable( void );

/// @brief TIM17 disable function
static void TIMER17_disable( void );

/****************************** Local Variables ******************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static TIM_HandleTypeDef htim1, htim2, htim3, htim4, htim5, htim6, htim7, htim8, htim15, htim16, htim17;

static TimerHandle_t timer1  = { .bus_index = TIMER1, .p_device_handle = &htim1, .freq_Hz = TIMER_DEFAULT_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer2  = { .bus_index = TIMER2, .p_device_handle = &htim2, .freq_Hz = TIMER2_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer3  = { .bus_index = TIMER3, .p_device_handle = &htim3, .freq_Hz = TIMER3_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer4  = { .bus_index = TIMER4, .p_device_handle = &htim4, .freq_Hz = TIMER4_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer5  = { .bus_index = TIMER5, .p_device_handle = &htim5, .freq_Hz = TIMER5_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer6  = { .bus_index = TIMER6, .p_device_handle = &htim6, .freq_Hz = TIMER_DEFAULT_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer7  = { .bus_index = TIMER7, .p_device_handle = &htim7, .freq_Hz = TIMER_DEFAULT_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer8  = { .bus_index = TIMER8, .p_device_handle = &htim8, .freq_Hz = TIMER_DEFAULT_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer15 = { .bus_index = TIMER15, .p_device_handle = &htim15, .freq_Hz = TIMER15_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer16 = { .bus_index = TIMER16, .p_device_handle = &htim16, .freq_Hz = TIMER16_FREQ_HZ, .status = FW_OK };
static TimerHandle_t timer17 = { .bus_index = TIMER17, .p_device_handle = &htim17, .freq_Hz = TIMER17_FREQ_HZ, .status = FW_OK };

static TimerHandle_t *const g_timer_handles[] = { &timer1, &timer2, &timer3,  &timer4,  &timer5, &timer6,
                                                  &timer7, &timer8, &timer15, &timer16, &timer17 };

static TIMER_enable_disable_t g_enable_table[] = { NULL, TIMER2_enable, TIMER3_enable,  TIMER4_enable,  TIMER5_enable, NULL,
                                                   NULL, NULL,          TIMER15_enable, TIMER16_enable, TIMER17_enable };

static TIMER_enable_disable_t g_disable_table[] = { NULL, TIMER2_disable, TIMER3_disable,  TIMER4_disable,  TIMER5_disable, NULL,
                                                    NULL, NULL,           TIMER15_disable, TIMER16_disable, TIMER17_disable };
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/****************************** Function Definitions ******************************/

// -------------------- STM32 HAL Interrupt Handlers --------------------

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler( timer2.p_device_handle );
}

void TIM3_IRQHandler()
{
    HAL_TIM_IRQHandler( timer3.p_device_handle );
}

void TIM4_IRQHandler()
{
    HAL_TIM_IRQHandler( timer4.p_device_handle );
}

void TIM5_IRQHandler()
{
    HAL_TIM_IRQHandler( timer5.p_device_handle );
}

void TIM1_BRK_TIM15_IRQHandler()
{
    HAL_TIM_IRQHandler( timer15.p_device_handle );
}

void TIM1_UP_TIM16_IRQHandler()
{
    HAL_TIM_IRQHandler( timer16.p_device_handle );
}

void TIM1_TRG_COM_TIM17_IRQHandler()
{
    HAL_TIM_IRQHandler( timer17.p_device_handle );
}

void TIM_PeriodElapsedCallback( TIM_HandleTypeDef *htim )
{
    trigger_callback( htim );
}

// -------------------- Private Functions --------------------

inline void trigger_callback( TIM_HandleTypeDef *p_timer_device )
{
    for( TimerIndex_t i = (TimerIndex_t)0; i < TIMER_COUNT; i++ )
    {
        if( g_timer_handles[i]->p_device_handle == p_timer_device )
        {
            if( g_timer_handles[i]->callback != NULL )
            {
                g_timer_handles[i]->callback( i );
            }
            break;
        }
    }
}

void TIMER2_enable()
{
    TIM_MasterConfigTypeDef sMasterConfig = { 0 };
    TIM_IC_InitTypeDef      sConfigIC     = { 0 };

    timer2.p_device_handle->Instance               = TIM2;
    timer2.p_device_handle->Init.Prescaler         = 0;
    timer2.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer2.p_device_handle->Init.Period            = UINT32_MAX;
    timer2.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer2.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_IC_Init( timer2.p_device_handle );

    // HAL_TIM_RegisterCallback( timer2.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization( timer2.p_device_handle, &sMasterConfig );

    sConfigIC.ICPolarity  = TIM_INPUTCHANNELPOLARITY_RISING;
    sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
    sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
    sConfigIC.ICFilter    = 0;
    HAL_TIM_IC_ConfigChannel( timer2.p_device_handle, &sConfigIC, TIM_CHANNEL_1 );

    timer2.enabled = true;
}

void TIMER3_enable()
{
    TIM_ClockConfigTypeDef  sClockSourceConfig = { 0 };
    TIM_MasterConfigTypeDef sMasterConfig      = { 0 };

    // TIM3 clock enable
    __HAL_RCC_TIM3_CLK_ENABLE();

    timer3.p_device_handle->Instance               = TIM3;
    timer3.p_device_handle->Init.Prescaler         = ( SYSCLK_HZ / timer3.freq_Hz ) - 1;
    timer3.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer3.p_device_handle->Init.Period            = TIMER3_FREQ_HZ - 1; // Default to 1s period
    timer3.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer3.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init( timer3.p_device_handle );

    HAL_TIM_RegisterCallback( timer3.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource( timer3.p_device_handle, &sClockSourceConfig );

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization( timer3.p_device_handle, &sMasterConfig );

    // TIM3 interrupt Init
    HAL_NVIC_SetPriority( TIM3_IRQn, 0, 0 );
    HAL_NVIC_EnableIRQ( TIM3_IRQn );

    timer3.enabled = true;
}

void TIMER4_enable()
{
    TIM_ClockConfigTypeDef  sClockSourceConfig = { 0 };
    TIM_MasterConfigTypeDef sMasterConfig      = { 0 };

    // TIM4 clock enable
    __HAL_RCC_TIM4_CLK_ENABLE();

    timer4.p_device_handle->Instance               = TIM4;
    timer4.p_device_handle->Init.Prescaler         = 0;
    timer4.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer4.p_device_handle->Init.Period            = UINT16_MAX;
    timer4.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer4.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE; // enabled for periodic temperature reads
    HAL_TIM_Base_Init( timer4.p_device_handle );

    HAL_TIM_RegisterCallback( timer4.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource( timer4.p_device_handle, &sClockSourceConfig );

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization( timer4.p_device_handle, &sMasterConfig );

    // TIM4 interrupt Init
    HAL_NVIC_SetPriority( TIM4_IRQn, 0, 0 );
    HAL_NVIC_EnableIRQ( TIM4_IRQn );

    timer4.enabled = true;
}

void TIMER5_enable()
{
    TIM_MasterConfigTypeDef sMasterConfig = { 0 };
    TIM_IC_InitTypeDef      sConfigIC     = { 0 };

    timer5.p_device_handle->Instance               = TIM5;
    timer5.p_device_handle->Init.Prescaler         = 0;
    timer5.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer5.p_device_handle->Init.Period            = UINT32_MAX;
    timer5.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer5.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_IC_Init( timer5.p_device_handle );

    // HAL_TIM_RegisterCallback( timer5.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization( timer5.p_device_handle, &sMasterConfig );

    sConfigIC.ICPolarity  = TIM_INPUTCHANNELPOLARITY_RISING;
    sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
    sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
    sConfigIC.ICFilter    = 0;
    HAL_TIM_IC_ConfigChannel( timer5.p_device_handle, &sConfigIC, TIM_CHANNEL_3 );

    timer5.enabled = true;
}

void TIMER15_enable()
{
    TIM_ClockConfigTypeDef  sClockSourceConfig = { 0 };
    TIM_MasterConfigTypeDef sMasterConfig      = { 0 };

    // TIM15 clock enable
    __HAL_RCC_TIM15_CLK_ENABLE();

    timer15.p_device_handle->Instance               = TIM15;
    timer15.p_device_handle->Init.Prescaler         = 0;
    timer15.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer15.p_device_handle->Init.Period            = UINT16_MAX;
    timer15.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer15.p_device_handle->Init.RepetitionCounter = 0;
    timer15.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init( timer15.p_device_handle );

    HAL_TIM_RegisterCallback( timer15.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource( timer15.p_device_handle, &sClockSourceConfig );

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization( timer15.p_device_handle, &sMasterConfig );

    // TIM15 interrupt Init
    HAL_NVIC_SetPriority( TIM1_BRK_TIM15_IRQn, 0, 0 );
    HAL_NVIC_EnableIRQ( TIM1_BRK_TIM15_IRQn );

    timer15.enabled = true;
}

void TIMER16_enable()
{
    // TIM16 clock enable
    __HAL_RCC_TIM16_CLK_ENABLE();

    timer16.p_device_handle->Instance               = TIM16;
    timer16.p_device_handle->Init.Prescaler         = 0;
    timer16.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer16.p_device_handle->Init.Period            = UINT16_MAX;
    timer16.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer16.p_device_handle->Init.RepetitionCounter = 0;
    timer16.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init( timer16.p_device_handle );

    HAL_TIM_RegisterCallback( timer16.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    // TIM16 interrupt Init
    HAL_NVIC_SetPriority( TIM1_UP_TIM16_IRQn, 0, 0 );
    HAL_NVIC_EnableIRQ( TIM1_UP_TIM16_IRQn );

    timer16.enabled = true;
}

void TIMER17_enable()
{
    // TIM17 clock enable
    __HAL_RCC_TIM17_CLK_ENABLE();

    timer17.p_device_handle->Instance               = TIM17;
    timer17.p_device_handle->Init.Prescaler         = 0;
    timer17.p_device_handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
    timer17.p_device_handle->Init.Period            = UINT16_MAX;
    timer17.p_device_handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    timer17.p_device_handle->Init.RepetitionCounter = 0;
    timer17.p_device_handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init( timer17.p_device_handle );

    HAL_TIM_RegisterCallback( timer17.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID, TIM_PeriodElapsedCallback );

    // TIM17 interrupt Init
    HAL_NVIC_SetPriority( TIM1_TRG_COM_TIM17_IRQn, 0, 0 );
    HAL_NVIC_EnableIRQ( TIM1_TRG_COM_TIM17_IRQn );

    timer17.enabled = true;
}

void TIMER2_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM2_CLK_DISABLE();

    // TIM3 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM2_IRQn );

    HAL_TIM_IC_DeInit( timer2.p_device_handle );

    timer2.enabled = false;
}

void TIMER3_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM3_CLK_DISABLE();

    // TIM3 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM3_IRQn );

    HAL_TIM_UnRegisterCallback( timer3.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID );

    HAL_TIM_Base_DeInit( timer3.p_device_handle );

    timer3.enabled = false;
}

void TIMER4_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM4_CLK_DISABLE();

    // TIM4 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM4_IRQn );

    HAL_TIM_UnRegisterCallback( timer4.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID );

    HAL_TIM_Base_DeInit( timer4.p_device_handle );

    timer4.enabled = false;
}

void TIMER5_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM5_CLK_DISABLE();

    // TIM4 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM5_IRQn );

    HAL_TIM_IC_DeInit( timer5.p_device_handle );

    timer5.enabled = false;
}

void TIMER15_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM15_CLK_DISABLE();

    // TIM15 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM1_BRK_TIM15_IRQn );

    HAL_TIM_UnRegisterCallback( timer15.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID );

    HAL_TIM_Base_DeInit( timer15.p_device_handle );

    timer15.enabled = false;
}

void TIMER16_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM16_CLK_DISABLE();

    // TIM16 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM1_UP_TIM16_IRQn );

    HAL_TIM_UnRegisterCallback( timer16.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID );

    HAL_TIM_Base_DeInit( timer16.p_device_handle );

    timer16.enabled = false;
}

void TIMER17_disable()
{
    // Peripheral clock disable
    __HAL_RCC_TIM17_CLK_DISABLE();

    // TIM17 interrupt Deinit
    HAL_NVIC_DisableIRQ( TIM1_TRG_COM_TIM17_IRQn );

    HAL_TIM_UnRegisterCallback( timer17.p_device_handle, HAL_TIM_PERIOD_ELAPSED_CB_ID );

    HAL_TIM_Base_DeInit( timer17.p_device_handle );

    timer17.enabled = false;
}

// -------------------- Public Functions --------------------
void TIMER_set_period_us( TimerIndex_t index, uint32_t period_us )
{
    uint32_t auto_reload = 0;
    app_assert( index < TIMER_COUNT );
    app_assert( period_us > 0 );

    auto_reload = ( period_us * g_timer_handles[index]->freq_Hz / US_PER_SECOND ) - 1;
    __HAL_TIM_SET_AUTORELOAD( g_timer_handles[index]->p_device_handle, auto_reload );
}

void TIMER_set_period( TimerIndex_t index, uint16_t period_ms )
{
    uint32_t auto_reload = 0;
    app_assert( index < TIMER_COUNT );
    app_assert( period_ms > 0 );

    auto_reload = ( period_ms * g_timer_handles[index]->freq_Hz / MS_PER_SECOND ) - 1;
    __HAL_TIM_SET_AUTORELOAD( g_timer_handles[index]->p_device_handle, auto_reload );
}

void TIMER_start( TimerIndex_t index )
{
    app_assert( index < TIMER_COUNT );
    __HAL_TIM_CLEAR_FLAG( g_timer_handles[index]->p_device_handle, (uint32_t)TIM_FLAG_UPDATE );
    HAL_TIM_Base_Start( g_timer_handles[index]->p_device_handle );
}

void TIMER_stop( TimerIndex_t index )
{
    app_assert( index < TIMER_COUNT );
    HAL_TIM_Base_Stop( g_timer_handles[index]->p_device_handle );

    // Reset the timer counter back to 0
    __HAL_TIM_SET_COUNTER( g_timer_handles[index]->p_device_handle, 0 );
}

int TIMER_get_update_flag( TimerIndex_t index )
{
    return __HAL_TIM_GET_FLAG( g_timer_handles[index]->p_device_handle, TIM_FLAG_UPDATE );
}

void TIMER_clear_update_flag( TimerIndex_t index )
{
    __HAL_TIM_CLEAR_FLAG( g_timer_handles[index]->p_device_handle, (uint32_t)TIM_FLAG_UPDATE );
}

void TIMER_start_IT( TimerIndex_t index )
{
    app_assert( index < TIMER_COUNT );

    if( !g_timer_handles[index]->enabled )
    {
        return;
    }

    __HAL_TIM_CLEAR_FLAG( g_timer_handles[index]->p_device_handle, (uint32_t)TIM_FLAG_UPDATE );
    HAL_TIM_Base_Start_IT( g_timer_handles[index]->p_device_handle );
}

void TIMER_stop_IT( TimerIndex_t index )
{
    app_assert( index < TIMER_COUNT );

    if( !g_timer_handles[index]->enabled )
    {
        return;
    }

    HAL_TIM_Base_Stop_IT( g_timer_handles[index]->p_device_handle );

    // Reset the timer counter back to 0
    __HAL_TIM_SET_COUNTER( g_timer_handles[index]->p_device_handle, 0 );
}

void TIMER_register_callback( TimerIndex_t index, TIMER_eventCB_t callback )
{
    app_assert( index < TIMER_COUNT );
    g_timer_handles[index]->callback = callback;
}

void TIMER_disable( TimerIndex_t index )
{
    app_assert( index < TIMER_COUNT );
    app_assert( g_disable_table[index] != NULL );

    if( !g_timer_handles[index]->enabled )
    {
        return;
    }

    g_disable_table[index]();

    // Reset the timer counter back to 0
    __HAL_TIM_SET_COUNTER( g_timer_handles[index]->p_device_handle, 0 );
}

void TIMER_enable( TimerIndex_t index )
{
    app_assert( index < TIMER_COUNT );
    app_assert( g_enable_table[index] != NULL );

    if( g_timer_handles[index]->enabled )
    {
        return;
    }

    g_enable_table[index]();

    // Reset the timer counter back to 0
    __HAL_TIM_SET_COUNTER( g_timer_handles[index]->p_device_handle, 0 );
}
