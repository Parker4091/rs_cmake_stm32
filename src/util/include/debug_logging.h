/// @file debug_logging.h
/// @brief This file provides a macro to print logs for debugging
/// @author Siddhant Modi (sidmodi)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#define DEBUG_LOG( ... ) printf( __VA_ARGS__ )

#ifdef __cplusplus
}
#endif
