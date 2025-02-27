/// @file watchdog.h
/// @brief This file provides code for the configuration
///        of the window and independent watchdog Timer.
///
/// @author Parker Lloyd (plloyd)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes *******************************************/

/********************************** Constants *******************************************/

/************************************ Types ********************************************/

/****************************** Function Declarations ************************************/
/// @brief Refresh the WWDG downcounter to prevent an MCU reset
void WWDG_refresh( void );

/// @brief Init the window watchdog timer
void WWDG_initialize( void );

/// @brief Refresh the IWDG downcounter to prevent an MCU reset
void IWDG_refresh( void );

/// @brief Init the independant watchdog timer
void IWDG_initialize( void );

#ifdef __cplusplus
}
#endif
