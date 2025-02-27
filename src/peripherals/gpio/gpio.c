/// @file  gpio.c
/// @brief This file provides code for the configuration
///        of all used GPIO pins.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "app_assert.h"
#include "board.h"
#include "gpio.h"
#include "stdbool.h"
#include "stm32l4xx_hal.h"
#include "types.h"

/************************************ Types ********************************************/

/********************************** Constants *******************************************/
// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
static GPIO_TypeDef  *g_port_lookup[GPIO_PORT_COUNT] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, GPIOI };
static const uint16_t g_pin_lookup[GPIO_PIN_COUNT]   = { GPIO_PIN_0,  GPIO_PIN_1,  GPIO_PIN_2,  GPIO_PIN_3, GPIO_PIN_4,  GPIO_PIN_5,
                                                         GPIO_PIN_6,  GPIO_PIN_7,  GPIO_PIN_8,  GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11,
                                                         GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15 };

/********************************** Local Variables *******************************************/

/********************************** Local Function Declarations *******************************************/

/****************************** Callbacks and Handlers ***********************************/

/****************************** Function Definitions ***********************************/
void GPIO_set_pin_state( gpio_port_t port, gpio_pin_t pin, gpio_pin_state_t state )
{
    app_assert( port < GPIO_PORT_COUNT );
    app_assert( pin < GPIO_PIN_COUNT );
    app_assert( state < GPIO_PIN_STATE_COUNT );
    HAL_GPIO_WritePin( g_port_lookup[port], g_pin_lookup[pin], (GPIO_PinState)state );
}

gpio_pin_state_t GPIO_get_pin_state( gpio_port_t port, gpio_pin_t pin )
{
    app_assert( port < GPIO_PORT_COUNT );
    app_assert( pin < GPIO_PIN_COUNT );
    return (gpio_pin_state_t)HAL_GPIO_ReadPin( g_port_lookup[port], g_pin_lookup[pin] );
}

void GPIO_SPI3_deinit()
{
    HAL_GPIO_DeInit( g_port_lookup[SPI3_SCK_GPIO_Port], g_pin_lookup[SPI3_SCK_Pin] | g_pin_lookup[SPI3_MISO_Pin] | g_pin_lookup[SPI3_MOSI_Pin] );
}

void GPIO_USART1_deinit()
{
    HAL_GPIO_DeInit( g_port_lookup[USART1_TX_GPIO_Port],
                     g_pin_lookup[USART1_TX_Pin] | g_pin_lookup[USART1_RX_Pin] | g_pin_lookup[USART1_CTS_Pin] | g_pin_lookup[USART1_RTS_Pin] );
}

void GPIO_USART3_deinit()
{
    HAL_GPIO_DeInit( g_port_lookup[USART3_TX_GPIO_Port], g_pin_lookup[USART3_TX_Pin] | g_pin_lookup[USART3_RX_Pin] );
    HAL_GPIO_DeInit( g_port_lookup[USART3_CTS_GPIO_Port], g_pin_lookup[USART3_CTS_Pin] );
    HAL_GPIO_DeInit( g_port_lookup[USART3_RTS_GPIO_Port], g_pin_lookup[USART3_RTS_Pin] );
}

void GPIO_SPI3_initialize()
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // SPI3 Enable
    GPIO_InitStruct.Pin       = g_pin_lookup[SPI3_SCK_Pin] | g_pin_lookup[SPI3_MISO_Pin] | g_pin_lookup[SPI3_MOSI_Pin];
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init( g_port_lookup[SPI3_SCK_GPIO_Port], &GPIO_InitStruct );
}

void GPIO_USART1_initialize()
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // USART1 GPIO enable
    GPIO_InitStruct.Pin   = g_pin_lookup[USART1_TX_Pin] | g_pin_lookup[USART1_RX_Pin] | g_pin_lookup[USART1_CTS_Pin] | g_pin_lookup[USART1_RTS_Pin];
    GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init( g_port_lookup[USART1_TX_GPIO_Port], &GPIO_InitStruct );
}

void GPIO_USART3_initialize()
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // USART3 GPIO enable
    GPIO_InitStruct.Pin       = g_pin_lookup[USART3_CTS_Pin];
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init( g_port_lookup[USART3_CTS_GPIO_Port], &GPIO_InitStruct );

    GPIO_InitStruct.Pin       = g_pin_lookup[USART3_TX_Pin] | g_pin_lookup[USART3_RX_Pin];
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init( g_port_lookup[USART3_TX_GPIO_Port], &GPIO_InitStruct );

    GPIO_InitStruct.Pin       = g_pin_lookup[USART3_RTS_Pin];
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init( g_port_lookup[USART3_RTS_GPIO_Port], &GPIO_InitStruct );
}

void GPIO_initialize()
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    HAL_PWREx_EnableVddIO2();

    // Configure GPIO pin Output Level - arbitrary example - some pins may need to init high
    GPIO_set_pin_state( EXAMPLE_1_GPIO_Port, EXAMPLE_1_Pin, GPIO_PIN_STATE_SET );
    GPIO_set_pin_state( EXAMPLE_2_GPIO_Port, EXAMPLE_2_Pin, GPIO_PIN_STATE_SET );
    GPIO_set_pin_state( EXAMPLE_3_GPIO_Port, EXAMPLE_3_Pin, GPIO_PIN_STATE_SET );
    GPIO_set_pin_state( EXAMPLE_4_GPIO_Port, EXAMPLE_4_Pin, GPIO_PIN_STATE_SET );

    // Configure GPIO pin Output Level - arbitrary example - some pins may need to init low
    GPIO_set_pin_state( EXAMPLE_5_GPIO_Port, EXAMPLE_5_Pin, GPIO_PIN_STATE_CLEAR );
    GPIO_set_pin_state( EXAMPLE_6_GPIO_Port, EXAMPLE_6_Pin, GPIO_PIN_STATE_CLEAR );
    GPIO_set_pin_state( EXAMPLE_7_GPIO_Port, EXAMPLE_7_Pin, GPIO_PIN_STATE_CLEAR );
    GPIO_set_pin_state( EXAMPLE_8_GPIO_Port, EXAMPLE_8_Pin, GPIO_PIN_STATE_CLEAR );
    GPIO_set_pin_state( EXAMPLE_9_GPIO_Port, EXAMPLE_9_Pin, GPIO_PIN_STATE_CLEAR );

    // Configure GPIO pin Output Level

    // Configure GPIO pins : Multiple Outputs
    GPIO_InitStruct.Pin = g_pin_lookup[EXAMPLE_1_Pin] | g_pin_lookup[EXAMPLE_2_Pin] | g_pin_lookup[EXAMPLE_3_Pin] | g_pin_lookup[EXAMPLE_4_Pin];
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init( g_port_lookup[EXAMPLE_1_GPIO_Port], &GPIO_InitStruct );

    // Configure GPIO pins : Multiple Inputs
    GPIO_InitStruct.Pin  = g_pin_lookup[EXAMPLE_6_Pin] | g_pin_lookup[EXAMPLE_7_Pin] | g_pin_lookup[EXAMPLE_8_Pin];
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init( g_port_lookup[EXAMPLE_6_GPIO_Port], &GPIO_InitStruct );

    // Configure GPIO pins : Output
    GPIO_InitStruct.Pin   = g_pin_lookup[EXAMPLE_9_Pin];
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init( g_port_lookup[EXAMPLE_9_GPIO_Port], &GPIO_InitStruct );
}