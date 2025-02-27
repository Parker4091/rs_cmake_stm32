/// @brief Mock for Usart fmc.h
#pragma once

#include <gpio.h>

#include <cmock/cmock.h>

class MockGpio : public CMockMocker<MockGpio>
{
public:
    MockGpio();  ///< Default Constructor
    ~MockGpio(); ///< Destructor

    CMOCK_MOCK_METHOD( void, GPIO_set_pin_state, ( gpio_port_t port, gpio_pin_t pin, gpio_pin_state_t state ) )
    CMOCK_MOCK_METHOD( gpio_pin_state_t, GPIO_get_pin_state, ( gpio_port_t port, gpio_pin_t pin ) )
    CMOCK_MOCK_METHOD( void, GPIO_SPI3_deinit, () )
    CMOCK_MOCK_METHOD( void, GPIO_USART1_deinit, () )
    CMOCK_MOCK_METHOD( void, GPIO_USART3_deinit, () )
    CMOCK_MOCK_METHOD( void, GPIO_SPI3_initialize, () )
    CMOCK_MOCK_METHOD( void, GPIO_USART1_initialize, () )
    CMOCK_MOCK_METHOD( void, GPIO_USART3_initialize, () )
    CMOCK_MOCK_METHOD( void, GPIO_initialize, () )
};
