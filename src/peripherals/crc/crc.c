/// @file crc.c
/// @brief This file provides code for the configuration
///        of the CRC module.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "crc.h"
#include "stdbool.h"
#include "stm32h7rsxx_hal.h"

/************************************ Types ********************************************/

/********************************** Constants *******************************************/

/********************************** Local Variables *******************************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static CRC_HandleTypeDef g_crc_32     = { 0 };
static bool              g_is_init_32 = false;

static CRC_HandleTypeDef g_crc_16     = { 0 };
static bool              g_is_init_16 = false;
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/********************************** Local Function Declarations *******************************************/

/****************************** Public Function Definitions *****************************/
uint32_t CRC32_calculate( void *buffer, uint32_t length )
{
    // Need to do the ~ of the result here to match the CRC algo on the Linux compute side
    // Reference: https://web.archive.org/web/20230504175523/https://m0agx.eu/2021/04/09/matching-stm32-hardware-crc-with-standard-crc-32/
    return g_is_init_32 ? ~HAL_CRC_Calculate( &g_crc_32, (uint32_t *)buffer, length / sizeof( uint32_t ) ) : 0;
}

void CRC32_deinit( void )
{
    if( g_is_init_32 )
    {
        __HAL_RCC_CRC_CLK_DISABLE();
        HAL_CRC_DeInit( &g_crc_32 );
        g_is_init_32 = false;
    }
}

void CRC32_initialize( void )
{
    if( !g_is_init_32 )
    {
        // CRC clock enable
        __HAL_RCC_CRC_CLK_ENABLE();

        // Init the CRC Module
        g_crc_32.Instance                     = CRC;
        g_crc_32.Init.DefaultPolynomialUse    = DEFAULT_POLYNOMIAL_ENABLE;
        g_crc_32.Init.DefaultInitValueUse     = DEFAULT_INIT_VALUE_ENABLE;
        g_crc_32.Init.InputDataInversionMode  = CRC_INPUTDATA_INVERSION_WORD;
        g_crc_32.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_ENABLE;
        g_crc_32.InputDataFormat              = CRC_INPUTDATA_FORMAT_WORDS;
        HAL_CRC_Init( &g_crc_32 );
        g_is_init_32 = true;
    }
}

uint16_t CRC16_calculate( void *buffer, uint32_t length )
{
    return g_is_init_16 ? (uint16_t)HAL_CRC_Calculate( &g_crc_16, (uint32_t *)buffer, length ) : 0;
}

void CRC16_deinit( void )
{
    if( g_is_init_16 )
    {
        __HAL_RCC_CRC_CLK_DISABLE();
        HAL_CRC_DeInit( &g_crc_16 );
        g_is_init_16 = false;
    }
}

void CRC16_initialize( void )
{
    if( !g_is_init_16 )
    {
        // CRC clock enable
        __HAL_RCC_CRC_CLK_ENABLE();

        /* CRC configured */
        g_crc_16.Instance = CRC;

        /* The CRC-16-CCIT polynomial is used */
        g_crc_16.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_DISABLE;
        //NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        g_crc_16.Init.GeneratingPolynomial = 0x1021U;
        g_crc_16.Init.CRCLength            = CRC_POLYLENGTH_16B;

        /* The zero init value is used */
        g_crc_16.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_DISABLE;
        g_crc_16.Init.InitValue           = 0U;

        /* The input data are not inverted */
        g_crc_16.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;

        /* The output data are not inverted */
        g_crc_16.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;

        /* The input data are 32-bit long words */
        g_crc_16.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;

        if( HAL_CRC_Init( &g_crc_16 ) != HAL_OK )
        {
            /* Initialization Error */
            while( 1 )
            {
            }
        }
    }
}
