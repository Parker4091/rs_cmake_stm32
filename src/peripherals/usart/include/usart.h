/// @file usart.h
/// @brief This file provides code for the configuration
///        of the USART instances.
///
/// @author Siddhant Modi (sidmodi)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes *******************************************/
#include "board.h"
#include "stdbool.h"
#include "types.h"

/********************************** Constants *******************************************/

/************************************ Types ********************************************/
// RX/TX Event Type Enumeration
typedef enum UART_EventType_e
{
    UART_Event_Rx,
    UART_Event_Tx,
    UART_Event_Count
} UART_EventType_t;

// Callback function prototype
typedef void ( *UART_eventCB_t )( UART_EventType_t eventType );

/****************************** Function Declarations ************************************/
/// @brief Send data on the UART bus while blocking
/// @param[in] uart_interface Index of the UART bus to send data on
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
/// @return FWStatus_t Command status
FWStatus_t UART_master_transmit( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size, uint32_t timeout_ms );

/// @brief Send data on the UART bus without blocking
/// @param uart_interface Index of the UART bus to send data on
/// @param p_data Pointer to the buffer of data to be sent
/// @param size Length of the buffer in bytes
/// @return FWStatus_t Command status
FWStatus_t UART_master_transmit_IT( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size );

/// @brief Send data on the UART bus using DMA
/// @param[in] uart_interface Index of the UART bus to send data on
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[in] size Length of the buffer in bytes
/// @return FWStatus_t Command status
FWStatus_t UART_master_transmit_DMA( UARTBusIndex_t uart_interface, const uint8_t *p_data, uint16_t size );

/// @brief Receive data on the UART bus while blocking
/// @param[in] uart_interface Index of the UART bus to send data on
/// @param[out] p_data Pointer to the buffer where the received data will be copied
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
/// @return FWStatus_t Command status
FWStatus_t UART_master_receive( UARTBusIndex_t uart_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms );

/// @brief Receive data on the UART bus without blocking
/// @param[in] uart_interface Index of the UART bus to send data on
/// @param[out] p_data Pointer to the buffer where the received data will be copied
/// @param[in] size Number of data elements to be received
/// @return FWStatus_t Command status
FWStatus_t UART_master_receive_IT( UARTBusIndex_t uart_interface, uint8_t *p_data, uint16_t size );

/// @brief Abort the ongoing receive data on the UART bus without blocking
/// @param[in] uart_interface Index of the UART bus to send data on
/// @return FWStatus_t Command status
FWStatus_t UART_master_abort_receive_IT( UARTBusIndex_t uart_interface );

/// @brief Register the callback function to be triggered on an interrupt
/// @param[in] uart_interface Index of the UART bus to send data on
/// @param[in] uart_event_callback Pointer to the function to be registered as the callback
/// @note to deregister the callback, use uart_event_callback = NULL.
void UART_register_callback( UARTBusIndex_t uart_interface, UART_eventCB_t uart_event_callback );

/// @brief Checks whether the provided UART interface is in the busy receiving state
/// @param uart_interface The UART interface to check
/// @return True if UART interface is in the busy receiving state
bool UART_is_rx_busy( UARTBusIndex_t uart_interface );

/// @brief Denit all the UART modules used by the project
void UART_deinit( void );

/// @brief Init all the UART modules used by the project
void UART_initialize( void );

#ifdef __cplusplus
}
#endif
