/// @file i2c.h
/// @brief This file provides code for the configuration
///        of the I2C instances.
///
/// @author Parker Lloyd (plloyd)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes *******************************************/
#include "board.h"
#include "types.h"

/********************************** Constants *******************************************/

/************************************ Types ********************************************/
// NOLINTNEXTLINE altera-struct-pack-align
typedef struct i2c_slave_device_info_s
{
    I2CBusIndex_t i2cBusIndex;
    uint16_t      slaveAddr;
    uint16_t      slaveAddrSize;
} i2c_slave_device_info_t;

// RX/TX Event Type Enumeration
typedef enum I2C_EventType_e
{
    I2C_Event_Rx,
    I2C_Event_Tx,
    I2C_Event_Count
} I2C_EventType_t;

/****************************** Function Declarations ************************************/
/// @brief Send data on the I2C bus while blocking
/// @param[in] i2c_interface Index of the I2C bus to send data on
/// @param[in] devAddr The address of the I2C slave
/// @param[in] memAddr The slave memory address to write
/// @param[in] memAddrSize The size of the slave memory address
/// @param[in] p_data Pointer to the buffer of data to be sent
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
/// @return FWStatus_t Command status
FWStatus_t I2C_master_mem_write( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, const uint8_t *p_data,
                                 uint16_t size, uint32_t timeout_ms );

/// @brief Receive data on the I2C bus while blocking
/// @param[in] i2c_interface Index of the I2C bus to send data on
/// @param[in] devAddr The address of the I2C slave
/// @param[in] memAddr The slave memory address to read
/// @param[in] memAddrSize The size of the slave memory address
/// @param[out] p_data Pointer to the buffer where the received data will be copied
/// @param[in] size Length of the buffer in bytes
/// @param[in] timeout_ms The time in ms for which this function should block
/// @return FWStatus_t Command status
FWStatus_t I2C_master_mem_read( I2CBusIndex_t i2c_interface, uint16_t devAddr, uint16_t memAddr, uint16_t memAddrSize, uint8_t *p_data, uint16_t size,
                                uint32_t timeout_ms );

/// @brief Denit all the I2C modules used by the project
void I2C_deinit( void );

/// @brief Init all the I2C modules used by the project
void I2C_initialize( void );

#ifdef __cplusplus
}
#endif
