/// @brief Mock for the USART layer
#include "mock_usart.h"

#include <cmock/cmock.h>

MockUsart::MockUsart()  = default;
MockUsart::~MockUsart() = default;

CMOCK_MOCK_FUNCTION( MockUsart, FWStatus_t, UART_master_transmit,
                     ( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size, uint32_t timeout_ms ) )
CMOCK_MOCK_FUNCTION( MockUsart, FWStatus_t, UART_master_transmit_IT, ( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size ) )
CMOCK_MOCK_FUNCTION( MockUsart, FWStatus_t, UART_master_transmit_DMA, ( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size ) )
CMOCK_MOCK_FUNCTION( MockUsart, FWStatus_t, UART_master_receive,
                     ( UARTBusIndex_t uart_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms ) )
CMOCK_MOCK_FUNCTION( MockUsart, FWStatus_t, UART_master_receive_IT, ( UARTBusIndex_t uart_interface, uint8_t *p_data, uint16_t size ) )
CMOCK_MOCK_FUNCTION( MockUsart, FWStatus_t, UART_master_abort_receive_IT, ( UARTBusIndex_t uart_interface ) )
CMOCK_MOCK_FUNCTION( MockUsart, void, UART_register_callback, ( UARTBusIndex_t uart_interface, UART_eventCB_t uart_event_callback ) )
CMOCK_MOCK_FUNCTION( MockUsart, bool, UART_is_rx_busy, ( UARTBusIndex_t uart_interface ) )
CMOCK_MOCK_FUNCTION( MockUsart, void, UART_deinit, () )
CMOCK_MOCK_FUNCTION( MockUsart, void, UART_initialize, () )
