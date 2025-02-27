/// @file flash.h
/// @brief This file provides code for the configuration
///        of the Flash module.
///
/// @author Siddhant Modi (sidmodi)

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

/****************************** Function Declarations ************************************/

/// @brief Get the FLASH error code from the physical layer
/// @return The error code from the HAL flash module
uint32_t FLASH_get_error( void );

/// @brief Write data to the flash memory - entire page will be erased before write
/// @param[in] start_address Address to start writing from
/// @param[in] p_data Pointer to the buffer of data to be written
/// @param[in] word_count Length of the buffer in words (4B)
/// @return FWStatus_t Command status
FWStatus_t FLASH_write_data( uint32_t start_address, const uint32_t *p_data, uint16_t word_count );

/// @brief Denit all the UART modules used by the project
void FLASH_deinit( void );

/// @brief Init all the UART modules used by the project
void FLASH_initialize( void );

#ifdef __cplusplus
}
#endif
