/// @brief Mock for the USART layer
#include "mock_gpio.h"

#include <cmock/cmock.h>

MockGpio::MockGpio()  = default;
MockGpio::~MockGpio() = default;

CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_set_pin_state, ( gpio_port_t port, gpio_pin_t pin, gpio_pin_state_t state ) )
CMOCK_MOCK_FUNCTION( MockGpio, gpio_pin_state_t, GPIO_get_pin_state, ( gpio_port_t port, gpio_pin_t pin ) )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_SPI3_deinit, () )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_USART1_deinit, () )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_USART3_deinit, () )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_SPI3_initialize, () )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_USART1_initialize, () )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_USART3_initialize, () )
CMOCK_MOCK_FUNCTION( MockGpio, void, GPIO_initialize, () )
