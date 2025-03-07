/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32h7rsxx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32h7rsxx_hal.h"
#include "assert.h"

/**
 * Initializes the Global MSP.
 * @retval None
 */
void HAL_MspInit( void )
{
    RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };

    /* Configure the system Power Supply */

    if( HAL_PWREx_ConfigSupply( PWR_LDO_SUPPLY ) != HAL_OK )
    {
        /* Initialization error */
        // Error_Handler();
    }

    __HAL_RCC_SBS_CLK_ENABLE();

    /* System interrupt init*/

    /* Enable the XSPIM_P2 interface */
    HAL_PWREx_EnableXSPIM2();

    /* The CSI is used by the compensation cells and must be enabled before enabling the
     compensation cells.
     For more details refer to RM0477 [SBS I/O compensation cell management] chapter.
  */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_CSI;
    RCC_OscInitStruct.CSIState       = RCC_CSI_ON;
    if( HAL_RCC_OscConfig( &RCC_OscInitStruct ) != HAL_OK )
    {
        // Error_Handler();
    }

    /* Configure the compensation cell */
    HAL_SBS_ConfigCompensationCell( SBS_IO_XSPI2_CELL, SBS_IO_CELL_CODE, 0U, 0U );

    /* Enable compensation cell */
    HAL_SBS_EnableCompensationCell( SBS_IO_XSPI2_CELL );

    /* wait ready before enabled IO */
    while( HAL_SBS_GetCompensationCellReadyStatus( SBS_IO_XSPI2_CELL_READY ) != 1U )
        ;

    /* high speed low voltage config */
    HAL_SBS_EnableIOSpeedOptimize( SBS_IO_XSPI2_HSLV );
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
