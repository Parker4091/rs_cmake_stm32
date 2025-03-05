
#--------------------------------------------------------------------
add_library(stm32h7rsxx_hal_conf  INTERFACE)
add_library(stm32h7rsxx::hal_conf ALIAS stm32h7rsxx_hal_conf )

target_sources(stm32h7rsxx_hal_conf
  INTERFACE
    include/stm32h7rsxx_hal_conf.h
    system_stm32h7rsxx.c
)

target_include_directories(stm32h7rsxx_hal_conf
  INTERFACE
    include
)
#--------------------------------------------------------------------
