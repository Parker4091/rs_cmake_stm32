# -------------------------------------------------------------------
set(CMSIS_DEVICE_NAME STM32H7xxxx CACHE STRING "Device Name for CMSIS")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(_template_dir Source/Templates/gcc)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "IAR")
    set(_template_dir Source/Templates/iar)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "ARMCC")
    set(_template_dir Source/Templates/arm)
else()
    message(WARNING "Unsupported Compiler: ${CMAKE_CXX_COMPILER_ID}. Assuming GNU compatible")
    set(_template_dir Source/Templates/gcc)
endif()

# -------------------------------------------------------------------

add_library(cmsis_device_h7 INTERFACE EXCLUDE_FROM_ALL)

target_sources(cmsis_device_h7
  INTERFACE
    Include/stm32h723xx.h
    Include/stm32h725xx.h
    Include/stm32h730xx.h
    Include/stm32h730xxq.h
    Include/stm32h733xx.h
    Include/stm32h735xx.h
    Include/stm32h742xx.h
    Include/stm32h743xx.h
    Include/stm32h745xg.h
    Include/stm32h745xx.h
    Include/stm32h747xg.h
    Include/stm32h747xx.h
    Include/stm32h750xx.h
    Include/stm32h753xx.h
    Include/stm32h755xx.h
    Include/stm32h757xx.h
    Include/stm32h7a3xx.h
    Include/stm32h7a3xxq.h
    Include/stm32h7b0xx.h
    Include/stm32h7b0xxq.h
    Include/stm32h7b3xx.h
    Include/stm32h7b3xxq.h
    Include/stm32h7xx.h
    Include/system_stm32h7xx.h

    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H723xx>: ${_template_dir}/startup_stm32h723xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H725xx>: ${_template_dir}/startup_stm32h725xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H730xx>: ${_template_dir}/startup_stm32h730xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H730xxQ>: ${_template_dir}/startup_stm32h730xxq.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H733xx>: ${_template_dir}/startup_stm32h733xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H735xx>: ${_template_dir}/startup_stm32h735xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H742xx>: ${_template_dir}/startup_stm32h742xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H743xx>: ${_template_dir}/startup_stm32h743xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H745xG>: ${_template_dir}/startup_stm32h745xg.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H745xx>: ${_template_dir}/startup_stm32h745xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H747xG>: ${_template_dir}/startup_stm32h747xg.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H747xx>: ${_template_dir}/startup_stm32h747xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H750xx>: ${_template_dir}/startup_stm32h750xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H753xx>: ${_template_dir}/startup_stm32h753xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H755xx>: ${_template_dir}/startup_stm32h755xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H757xx>: ${_template_dir}/startup_stm32h757xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7A3xx>: ${_template_dir}/startup_stm32h7a3xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7A3xxQ>: ${_template_dir}/startup_stm32h7a3xxq.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7B0xx>: ${_template_dir}/startup_stm32h7b0xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7B0xxQ>: ${_template_dir}/startup_stm32h7b0xxq.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7B3xx>: ${_template_dir}/startup_stm32h7b3xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7B3xxQ>: ${_template_dir}/startup_stm32h7b3xxq.s>
)


set_target_properties(cmsis_device_h7 PROPERTIES LINKER_LANGUAGE C)

target_compile_definitions(cmsis_device_h7
  INTERFACE
    ${CMSIS_DEVICE_NAME}
    USE_HAL_DRIVER
)

target_include_directories(cmsis_device_h7
  INTERFACE
    Include
)

target_link_libraries(cmsis_device_h7
  INTERFACE
        cmsis::core
)
