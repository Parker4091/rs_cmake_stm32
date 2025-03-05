/// @file flash.c
/// @brief This file provides code for the configuration
///        of the Flash module.
///
/// @author Siddhant Modi (sidmodi)

/********************************** Includes *******************************************/
#include "app_assert.h"
#include "board.h"
#include "flash.h"
#include "stdbool.h"
#include "stm32h7xx_hal.h"
#include "string.h"
#include "types.h"

/************************************ Types ********************************************/

/********************************** Constants *******************************************/
#define FLASH_BANK_PAGE_COUNT 256
#define SIZE_OF_WORD          ( sizeof( uint32_t ) )
#define SIZE_OF_DOUBLE_WORD   ( 2 * SIZE_OF_WORD )
#define WORDS_PER_PAGE        ( FLASH_PAGE_SIZE / SIZE_OF_WORD )
#define DOUBLE_WORDS_PER_PAGE ( FLASH_PAGE_SIZE / SIZE_OF_DOUBLE_WORD )

/********************************** Macros *******************************************/
#define GET_PAGE_ALIGNED_ADDRESS( addr ) ( addr & ~( FLASH_PAGE_SIZE - 1 ) )
#define IS_WORD_ALIGNED( address )       ( ( (uintptr_t)(address)&0x3 ) == 0 )

/********************************** Local Variables *******************************************/
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static uint32_t g_error;
static uint32_t g_page_buf[WORDS_PER_PAGE];
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

/********************************** Local Function Declarations *******************************************/
/// @brief This function returns the page index of a given page_address
/// @param page_address The page address to find the page index for
/// @return The page number
static inline uint32_t get_page( uint32_t page_address );

/// @brief This function returns the bank of a given page_address
/// @param page_address The page address to find the bank index for
/// @return Bank1 or Bank2
static inline uint32_t get_bank( uint32_t page_address );

/// @brief This function returns the offset of a given flash address in its page
/// @param flash_address The address in flash
/// @return The position of the address in a given page
uint32_t get_address_in_page( uint32_t flash_address );

/****************************** Local Function Definitions *****************************/
uint32_t get_page( uint32_t page_address )
{
    // Verify that the page_address is valid (i.e., above FLASH_BASE)
    app_assert( page_address >= FLASH_BASE );

    // Determine the page number based on the address
    return ( ( page_address - FLASH_BASE ) / FLASH_PAGE_SIZE ) % FLASH_BANK_PAGE_COUNT; // % FLASH_BANK_PAGE_COUNT is because of dual-bank
}

uint32_t get_bank( uint32_t page_address )
{
    // Verify that the page_address is valid (i.e., above FLASH_BASE)
    app_assert( page_address >= FLASH_BASE );

    // Determine the bank number based on the address
    return ( ( page_address - FLASH_BASE ) < FLASH_BANK_SIZE ? FLASH_BANK_1 : FLASH_BANK_2 );
}

uint32_t get_address_in_page( uint32_t flash_address )
{
    // Verify that the page_address is valid (i.e., above FLASH_BASE)
    app_assert( flash_address >= FLASH_BASE );
    return flash_address % FLASH_PAGE_SIZE;
}

/****************************** Public Function Definitions *****************************/
uint32_t FLASH_get_error()
{
    return g_error;
}

FWStatus_t FLASH_write_data( uint32_t start_address, const uint32_t *p_data, uint16_t word_count )
{
    FLASH_EraseInitTypeDef erase_init_struct       = { 0 };
    uint32_t               page_error              = 0;
    uint32_t               start_page              = 0;
    uint32_t               end_page                = 0;
    uint32_t               end_address             = 0;
    uint32_t               buffer_word_idx         = 0;
    uint32_t               start_addr_page_aligned = GET_PAGE_ALIGNED_ADDRESS( start_address );
    uint32_t               words_remaining_in_page = 0;
    uint32_t               words_to_write          = 0;
    uint32_t               words_written           = 0;

    app_assert( start_address >= FLASH_BASE );
    app_assert( IS_WORD_ALIGNED( start_address ) );

    // Unlock the Flash to enable the flash control register access
    HAL_FLASH_Unlock();

    // Calculate end_address and check if the desired write leaks between banks
    end_address = start_address + word_count * SIZE_OF_WORD;
    // assert because this is only called with params chosen by programmer, nothing external that cannot be controlled
    app_assert( get_bank( start_address ) == get_bank( end_address ) );

    // Get start and end page indices
    start_page = get_page( start_address );
    end_page   = get_page( end_address );

    // Fill erase_init_struct structure
    erase_init_struct.TypeErase = FLASH_TYPEERASE_PAGES;
    erase_init_struct.Banks     = get_bank( start_address );
    erase_init_struct.NbPages   = ( end_page - start_page ) + 1;

    // Carry out the operation page-by-page
    // NOLINTNEXTLINE altera-unroll-loops
    for( uint32_t page_idx = 0; page_idx < erase_init_struct.NbPages; page_idx++ )
    {
        // Copy data from flash page into local memory
        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
        memcpy( (void *)g_page_buf, (void *)( start_addr_page_aligned + ( page_idx * FLASH_PAGE_SIZE ) ), sizeof( g_page_buf ) );

        erase_init_struct.Page = start_page + page_idx;
        if( HAL_FLASHEx_Erase( &erase_init_struct, &page_error ) != HAL_OK )
        {
            // Error occurred while page erase
            g_error = HAL_FLASH_GetError();
            return FW_ERROR;
        }

        // Edit the local copy of the flash word by word
        buffer_word_idx         = get_address_in_page( start_address + words_written ) / SIZE_OF_WORD;
        words_remaining_in_page = WORDS_PER_PAGE - buffer_word_idx; // Number of words between idx and end of page
        words_to_write          = words_remaining_in_page > word_count - words_written ? word_count - words_written : words_remaining_in_page;

        //NOLINTNEXTLINE(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
        memcpy( &g_page_buf[buffer_word_idx], &p_data[words_written], words_to_write * SIZE_OF_WORD );
        words_written += words_to_write;

        // Program the user Flash area double-word by double-word
        for( uint32_t dbl_word_idx = 0; dbl_word_idx < DOUBLE_WORDS_PER_PAGE; dbl_word_idx++ )
        {
            if( HAL_FLASH_Program( FLASH_TYPEPROGRAM_DOUBLEWORD, start_addr_page_aligned, ( (uint64_t *)g_page_buf )[dbl_word_idx] ) == HAL_OK )
            {
                start_addr_page_aligned += SIZE_OF_DOUBLE_WORD;
            }
            else
            {
                // Error occurred while writing data in Flash memory
                g_error = HAL_FLASH_GetError();
                return FW_ERROR;
            }
        }
    }

    // Lock the Flash to disable the flash control register access
    HAL_FLASH_Lock();

    return 0;
}

void FLASH_deinit( void )
{
}

void FLASH_initialize( void )
{
    __HAL_FLASH_CLEAR_FLAG( FLASH_FLAG_OPTVERR );
}
