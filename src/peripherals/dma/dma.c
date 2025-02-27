/// @file  dma.c
/// @brief This file provides code for the configuration
///        of all the requested memory to memory DMA transfers.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "dma.h"
#include "stm32l4xx_hal.h"

/****************************** Types ******************************/

/****************************** Constants ******************************/

/****************************** Local Variables ******************************/

/****************************** Local Function Declarations ******************************/

/****************************** Function Definitions ******************************/
void DMA_initialize()
{
    /* DMA controller clock enable */
    __HAL_RCC_DMAMUX1_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();
}
