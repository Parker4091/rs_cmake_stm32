#include "board.h"
#include "usart.h"

//NOLINTNEXTLINE(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)
int _write( int file, char *ptr, int len )
{
#if !defined( NDEBUG )
    (void)file;
    UART_master_transmit( DEBUG_LOGGING_UART_PERIPHERAL_INDEX, (uint8_t *)ptr, (uint16_t)len, 0xFFFF );
    return len;
#else
    (void)file;
    (void)ptr;
    (void)len;
    return 0;
#endif
}
