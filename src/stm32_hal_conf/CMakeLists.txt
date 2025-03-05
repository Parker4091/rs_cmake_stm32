
#--------------------------------------------------------------------
add_library(stm32h7xx_hal_conf  INTERFACE)
add_library(stm32h7xx::hal_conf ALIAS stm32h7xx_hal_conf )

target_sources(stm32h7xx_hal_conf
  INTERFACE
    include/stm32h7xx_hal_conf.h
    system_stm32h7xx.c
)

target_include_directories(stm32h7xx_hal_conf
  INTERFACE
    include
)
#--------------------------------------------------------------------
