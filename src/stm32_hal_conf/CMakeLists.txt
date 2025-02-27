
#--------------------------------------------------------------------
add_library(stm32l4xx_hal_conf  INTERFACE)
add_library(stm32l4xx::hal_conf ALIAS stm32l4xx_hal_conf )

target_sources(stm32l4xx_hal_conf
  INTERFACE
    include/stm32l4xx_hal_conf.h
    system_stm32l4xx.c
)

target_include_directories(stm32l4xx_hal_conf
  INTERFACE
    include
)
#--------------------------------------------------------------------
