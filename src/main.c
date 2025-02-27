/// @file  main.c
/// @brief Main program body

/* Includes ------------------------------------------------------------------*/
#include "debug_logging.h"
#include "dma.h"
#include "gpio.h"
#include "spi.h"
#include "stm32l4xx_hal.h"
#include "string.h"
#include "timer.h"
#include "usart.h"
#include "watchdog.h"
#include <math.h>
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config( void );

/* Private user code ---------------------------------------------------------*/

/// @brief  The application entry point.
/// @retval int
int main( void )
{
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    GPIO_initialize();
    DMA_initialize();
    SPI_initialize();
    UART_initialize();

    // Init debug messages
    //NOLINTBEGIN clang-diagnostic-date-time
    DEBUG_LOG( "Launching application.\r\n" );
    //NOLINTEND clang-diagnostic-date-time

    // The above initialization takes longer than maximum watchdog timer period
    // Watchdog initialization needs to occur close enough to refresh
    IWDG_initialize();

    // Infinite loop
    while( 1 )
    {
        IWDG_refresh();
    }
}

/// @brief System Clock Configuration
/// @retval None
void SystemClock_Config()
{
    RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
    RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

    // Configure the main internal regulator output voltage
    HAL_PWREx_ControlVoltageScaling( PWR_REGULATOR_VOLTAGE_SCALE1_BOOST );

    // Initializes the RCC Oscillators according to the specified parameters
    // in the RCC_OscInitTypeDef structure.
    RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_MSI;
    RCC_OscInitStruct.MSIState            = RCC_MSI_ON;
    RCC_OscInitStruct.MSICalibrationValue = 0;
    RCC_OscInitStruct.MSIClockRange       = RCC_MSIRANGE_6;
    RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_MSI;
    RCC_OscInitStruct.PLL.PLLM            = 1;
    RCC_OscInitStruct.PLL.PLLN            = 60;
    RCC_OscInitStruct.PLL.PLLP            = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ            = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR            = RCC_PLLR_DIV2;
    HAL_RCC_OscConfig( &RCC_OscInitStruct );

    // Initializes the CPU, AHB and APB buses clocks
    RCC_ClkInitStruct.ClockType      = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig( &RCC_ClkInitStruct, FLASH_LATENCY_5 );
}
