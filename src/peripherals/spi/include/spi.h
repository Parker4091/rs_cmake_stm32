/// @file  spi.h
/// @brief This file contains all the function prototypes for
///        the spi.c file
///
/// @author Siddhant Modi (sidmodi)

#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes ********************************/
#include "types.h"

/********************************** Constants  ******************************/

/************************************ Types *********************************/
// RX/TX Event Type Enumeration
typedef enum SPI_EventType_e
{
    SPI_Event_Rx,
    SPI_Event_Tx,
    SPI_Event_Count
} SPI_EventType_t;

// Callback function prototype
typedef void ( *SPI_eventCB_t )( SPI_EventType_t eventType );

/****************************** Function Declarations ************************************/
/// @brief Send data on the SPI bus while blocking
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
FWStatus_t SPI_master_transmit( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms );

/// @brief Send data on the SPI bus using interrupt
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[in] size Length of the buffer in bytes
FWStatus_t SPI_master_transmit_IT( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size );

/// @brief Send data on the SPI bus using DMA
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[in] size Length of the buffer in bytes
FWStatus_t SPI_master_transmit_DMA( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size );

/// @brief Receive data on the SPI bus while blocking
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[out] p_data Pointer to the buffer where the data will be received
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
FWStatus_t SPI_master_receive( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size, uint32_t timeout_ms );

/// @brief Receive data on the SPI bus using Interrupt
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[out] p_data Pointer to the buffer where the data will be received
/// @param[in] size number of data elements to be received
FWStatus_t SPI_master_receive_IT( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size );

/// @brief Receive data on the SPI bus using DMA
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[out] p_data Pointer to the buffer where the data will be received
/// @param[in] size number of data elements to be received
FWStatus_t SPI_master_receive_DMA( SPIBusIndex_t spi_interface, uint8_t *p_data, uint16_t size );

/// @brief Transmit and Receive data on the SPI bus while blocking
/// @param[in] spi_interface Index of the SPI bus to send data on
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[out] r_data Pointer to the buffer where the data will be received
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
FWStatus_t SPI_master_transmitreceive( SPIBusIndex_t spi_interface, uint8_t *p_data, uint8_t *r_data, uint16_t size, uint32_t timeout_ms );

/// @brief Register the callback function to be triggered on an interrupt
/// @param[in] spi_interface Index of the Timer to register the callback
/// @param[in] spi_event_callback Pointer to the function to be registered as the callback
/// @note to deregister the callback, use spi_event_callback = NULL.
void SPI_register_callback( SPIBusIndex_t spi_interface, SPI_eventCB_t spi_event_callback );

/// @brief Deinit all the SPI modules used by the project
void SPI_deinit( void );

/// @brief Init all the SPI modules used by the project
void SPI_initialize( void );

#ifdef __cplusplus
}
#endif
