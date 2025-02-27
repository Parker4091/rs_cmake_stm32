/// @file app_assert.h
/// @brief Assert module for the application
///
/// @author Siddhant Modi (sidmodi)
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/********************************** Includes *******************************************/
#include "assert.h"
#include "stdint.h"

/********************************** Macros *******************************************/
#define app_assert( x ) assert( x )

#define app_assert_custom( x ) \
    if( ( x ) == 0 )           \
    assert_handler( __FILE__, __LINE__ )

/****************************** Function Declarations ************************************/
/// @brief  Assert handler function for any issues.
void assert_handler( const char *file_name, uint32_t line );

#ifdef __cplusplus
}
#endif
