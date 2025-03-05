#include "app_assert.h"
#include "stm32h7xx_hal.h"

void assert_handler( const char* file_name, uint32_t line )
{
    // Do something with file_name and line
    (void)file_name;
    (void)line;
    
#if !defined(NDEBUG)
    __disable_irq();
    while (1)
    {
    }
#else
    // TODO(smodi) reset device
#endif // defined(NDEBUG)
}
