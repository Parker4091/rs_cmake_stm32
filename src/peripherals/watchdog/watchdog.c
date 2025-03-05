/// @file watchdog.c
/// @brief This file provides code for the configuration
///        of the window and independent watchdog timer.
///
/// @author Parker Lloyd (plloyd)

/********************************** Includes *******************************************/
#include "watchdog.h"
#include "stm32h7rsxx_hal.h"

/************************************ Types ********************************************/

/********************************** Constants *******************************************/
#define LSE_CLK_FREQUENCY_HZ     32000
#define IWDG_RELOAD_TIME_SECONDS 5
#define IWDG_CONFIG_PRESCALAR    64
#define IWDG_STM32_PRESCALAR     IWDG_PRESCALER_64

/********************************** Local Variables *******************************************/
//NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
static WWDG_HandleTypeDef hwwdg;
//NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
static IWDG_HandleTypeDef hiwdg;

/********************************** Local Function Declarations *******************************************/

/****************************** Local Function Definitions *****************************/

/****************************** Public Function Definitions *****************************/
void WWDG_refresh( void )
{
    HAL_WWDG_Refresh( &hwwdg );
}

void WWDG_initialize( void )
{
    __HAL_RCC_WWDG_CLK_ENABLE();

    hwwdg.Instance       = WWDG;
    hwwdg.Init.Prescaler = WWDG_PRESCALER_8;
    //NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    hwwdg.Init.Window = 127;
    //NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    hwwdg.Init.Counter = 127;
    hwwdg.Init.EWIMode = WWDG_EWI_DISABLE;
    HAL_WWDG_Init( &hwwdg );
}

void IWDG_refresh( void )
{
    HAL_IWDG_Refresh( &hiwdg );
}

void IWDG_initialize( void )
{
    __HAL_RCC_WWDG_CLK_ENABLE();

    hiwdg.Instance       = IWDG;
    hiwdg.Init.Prescaler = IWDG_STM32_PRESCALAR;
    //NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    hiwdg.Init.Window = 4095;
    //NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    hiwdg.Init.Reload = LSE_CLK_FREQUENCY_HZ / IWDG_CONFIG_PRESCALAR * IWDG_RELOAD_TIME_SECONDS;
    HAL_IWDG_Init( &hiwdg );
}
