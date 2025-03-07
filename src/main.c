/// @file  main.c
/// @brief Main program body

/* Includes ------------------------------------------------------------------*/
// #include "debug_logging.h"
// #include "dma.h"
// #include "gpio.h"
// #include "spi.h"
#include "stm32h7rsxx_hal.h"
#include "string.h"
// #include "timer.h"
// #include "usart.h"
// #include "watchdog.h"
#include <math.h>
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void Error_Handler( void );
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
    // GPIO_initialize();
    // DMA_initialize();
    // SPI_initialize();
    // UART_initialize();

    // Init debug messages
    //NOLINTBEGIN clang-diagnostic-date-time
    // DEBUG_LOG( "Launching application.\r\n" );
    //NOLINTEND clang-diagnostic-date-time

    // The above initialization takes longer than maximum watchdog timer period
    // Watchdog initialization needs to occur close enough to refresh
    // IWDG_initialize();

    // Infinite loop
    while( 1 )
    {
        // IWDG_refresh();
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler( void )
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while( 1 )
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config( void )
{
    RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
    RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

    /** Configure the main internal regulator output voltage
  */
    if( HAL_PWREx_ControlVoltageScaling( PWR_REGULATOR_VOLTAGE_SCALE0 ) != HAL_OK )
    {
        // Error_Handler();
    }

    /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
    RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSI;
    RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
    RCC_OscInitStruct.HSIDiv              = RCC_HSI_DIV1;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.LSIState            = RCC_LSI_ON;
    RCC_OscInitStruct.PLL1.PLLState       = RCC_PLL_ON;
    RCC_OscInitStruct.PLL1.PLLSource      = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL1.PLLM           = 4;
    RCC_OscInitStruct.PLL1.PLLN           = 37;
    RCC_OscInitStruct.PLL1.PLLP           = 1;
    RCC_OscInitStruct.PLL1.PLLQ           = 2;
    RCC_OscInitStruct.PLL1.PLLR           = 2;
    RCC_OscInitStruct.PLL1.PLLS           = 2;
    RCC_OscInitStruct.PLL1.PLLT           = 2;
    RCC_OscInitStruct.PLL1.PLLFractional  = 4096;
    RCC_OscInitStruct.PLL2.PLLState       = RCC_PLL_ON;
    RCC_OscInitStruct.PLL2.PLLSource      = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL2.PLLM           = 4;
    RCC_OscInitStruct.PLL2.PLLN           = 25;
    RCC_OscInitStruct.PLL2.PLLP           = 2;
    RCC_OscInitStruct.PLL2.PLLQ           = 2;
    RCC_OscInitStruct.PLL2.PLLR           = 2;
    RCC_OscInitStruct.PLL2.PLLS           = 2;
    RCC_OscInitStruct.PLL2.PLLT           = 2;
    RCC_OscInitStruct.PLL2.PLLFractional  = 0;
    RCC_OscInitStruct.PLL3.PLLState       = RCC_PLL_NONE;
    if( HAL_RCC_OscConfig( &RCC_OscInitStruct ) != HAL_OK )
    {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
  */
    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK4 | RCC_CLOCKTYPE_PCLK5;
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
    RCC_ClkInitStruct.APB5CLKDivider = RCC_APB5_DIV2;

    if( HAL_RCC_ClockConfig( &RCC_ClkInitStruct, FLASH_LATENCY_7 ) != HAL_OK )
    {
        Error_Handler();
    }
}