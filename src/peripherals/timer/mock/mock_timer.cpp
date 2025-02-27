/// @brief Mock for the Timer layer

#include "mock_timer.h"

#include <cmock/cmock.h>

MockTimer::MockTimer()  = default;
MockTimer::~MockTimer() = default;

CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_set_period, ( TimerIndex_t index, uint16_t period_ms ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_start_IT, ( TimerIndex_t index ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_stop_IT, ( TimerIndex_t index ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_register_callback, ( TimerIndex_t index, TIMER_eventCB_t callback ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_disable, ( TimerIndex_t index ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_enable, ( TimerIndex_t index ) )

CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_start, ( TimerIndex_t index ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_stop, ( TimerIndex_t index ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_set_period_us, ( TimerIndex_t index, uint32_t period_us ) )
CMOCK_MOCK_FUNCTION( MockTimer, int, TIMER_get_update_flag, ( TimerIndex_t index ) )
CMOCK_MOCK_FUNCTION( MockTimer, void, TIMER_clear_update_flag, ( TimerIndex_t index ) )
