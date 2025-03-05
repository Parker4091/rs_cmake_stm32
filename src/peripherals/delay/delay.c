/// @file delay.c
/// @brief This file provides code for the configuration
///        of the DELAY module.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "delay.h"
#include "stm32h7rsxx_hal.h"

/************************************ Types ********************************************/

/********************************** Constants *******************************************/

/********************************** Local Variables *******************************************/

/********************************** Local Function Declarations *******************************************/

/****************************** Public Function Definitions *****************************/
void DELAY_ms( uint32_t delay_ms )
{
    HAL_Delay( delay_ms );
}
