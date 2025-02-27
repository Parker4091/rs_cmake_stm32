/// @file delay.h
/// @brief This file provides code for the configuration
///        of the DELAY module.
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
/// @brief Blocking delay using hardware
/// @param[in] delay_ms Time to delay in milliseconds
void DELAY_ms( uint32_t delay_ms );

#ifdef __cplusplus
}
#endif
