# -------------------------------------------------------------------
set(CMSIS_DEVICE_NAME stm32h7rsxxxx CACHE STRING "Device Name for CMSIS")

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

add_library(cmsis_device_h7rs INTERFACE EXCLUDE_FROM_ALL)

target_sources(cmsis_device_h7rs
  INTERFACE
    Include/stm32h7r3xx.h
    Include/stm32h7r7xx.h
    Include/stm32h7rsxx.h
    Include/stm32h7s3xx.h
    Include/stm32h7s7xx.h
    Include/system_stm32h7rsxx.h

    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7R3xx>: ${_template_dir}/gcc/startup_stm32h7r3xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7R7xx>: ${_template_dir}/gcc/startup_stm32h7r7xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7S3xx>: ${_template_dir}/gcc/startup_stm32h7s3xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32H7S7xx>: ${_template_dir}/gcc/startup_stm32h7s7xx.s>
)



set_target_properties(cmsis_device_h7rs PROPERTIES LINKER_LANGUAGE C)

target_compile_definitions(cmsis_device_h7rs
  INTERFACE
    ${CMSIS_DEVICE_NAME}
    USE_HAL_DRIVER
)

target_include_directories(cmsis_device_h7rs
  INTERFACE
    Include
)

target_link_libraries(cmsis_device_h7rs
  INTERFACE
        cmsis::core
)
