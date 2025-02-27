/// @file  timer.h
/// @brief This file contains all the function prototypes for
///        the timer.c file
///
/// @author Siddhant Modi (sidmodi)

#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

/****************************** Includes ************************************/
#include "stdbool.h"
#include "types.h"

/********************************** Constants *******************************************/

/************************************ Types ********************************************/
// Callback function prototype
typedef void ( *TIMER_eventCB_t )( TimerIndex_t index );

/****************************** Functions ************************************/
/// @brief Set the state of the auto-reload preload functionality for the timer
/// @param[in] index Index of the Timer
/// @param[in] enabled The state of the auto-reload preload functionality
void TIMER_set_autoreload_preload( TimerIndex_t index, bool enabled );

/// @brief Set the state of the auto-reload preload functionality for the timer
/// @param[in] index Index of the Timer
/// @param[in] period_us the period to be set in microseconds
void TIMER_set_period_us( TimerIndex_t index, uint32_t period_us );

/// @brief Set the period for the timer
/// @param[in] index Index of the Timer
/// @param[in] period_ms The period to be set in milliseconds
void TIMER_set_period( TimerIndex_t index, uint16_t period_ms );

/// @brief Start the timer in blocking mode
/// @param[in] index Index of the Timer
void TIMER_start( TimerIndex_t index );

/// @brief Stop the timer in blocking mode
/// @param[in] index Index of the Timer
void TIMER_stop( TimerIndex_t index );

/// @brief Get the update flag status for the specified timer
/// @param[in] index Index of the timer
/// @return The flag status
int TIMER_get_update_flag( TimerIndex_t index );

/// @brief Clear the update flag for the specified timer
/// @param[in] index Index of the timer
void TIMER_clear_update_flag( TimerIndex_t index );

/// @brief Start the timer in non-blocking mode
/// @param[in] index Index of the Timer
void TIMER_start_IT( TimerIndex_t index );

/// @brief Stop the timer in non-blocking mode
/// @param[in] index Index of the Timer
void TIMER_stop_IT( TimerIndex_t index );

/// @brief Register the callback function to be triggered on an interrupt
/// @param[in] index Index of the Timer to register the callback
/// @param[in] callback Pointer to the function to be registered as the callback
/// @note to deregister the callback, use callback = NULL.
void TIMER_register_callback( TimerIndex_t index, TIMER_eventCB_t callback );

/// @brief Disable the timer
/// @param[in] index Index of the Timer to disable
void TIMER_disable( TimerIndex_t index );

/// @brief Enable the timer
/// @param[in] index Index of the Timer to enable
void TIMER_enable( TimerIndex_t index );

#ifdef __cplusplus
}
#endif
