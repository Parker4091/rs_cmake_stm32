/// @file crc.h
/// @brief This file provides code for the configuration
///        of the CRC module.
///
/// @author Siddhant Modi (sidmodi)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes *******************************************/
#include "stdint.h"

/********************************** Constants *******************************************/

/************************************ Types ********************************************/

/****************************** Function Declarations ************************************/
/// @brief Calculate the 32-bit CRC with the default initial value and default polynomial
/// @param[in] buffer Pointer to byte buffer for which CRC is to be calculated
/// @param[in] length Length of buffer in bytes
/// @return Calculated 32-bit CRC value
///
/// @note default polynomial: 0x04C11DB7U  X^32 + X^26 + X^23 + X^22 + X^16 + X^12 + X^11 + X^10 + X^8 + X^7 + X^5 + X^4 + X^2 + X + 1
///       default initial value: 0xFFFFFFFFU
uint32_t CRC32_calculate( void *buffer, uint32_t length );

/// @brief Denit the CRC32 module
void CRC32_deinit( void );

/// @brief Init the CRC32 module
void CRC32_initialize( void );

/// @brief Calculate the 16-bit CRC with the default initial value and default polynomial
/// @param[in] buffer Pointer to byte buffer for which CRC is to be calculated
/// @param[in] length Length of buffer in bytes
/// @return Calculated 16-bit CRC value
uint16_t CRC16_calculate( void *buffer, uint32_t length );

/// @brief Denit the CRC16 module
void CRC16_deinit( void );

/// @brief Init the CRC16 module
void CRC16_initialize( void );

#ifdef __cplusplus
}
#endif
