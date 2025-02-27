# -------------------------------------------------------------------
set(CMSIS_DEVICE_NAME STM32L4S5xx CACHE STRING "Device Name for CMSIS")

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

add_library(cmsis_device_l4 INTERFACE EXCLUDE_FROM_ALL)

target_sources(cmsis_device_l4
  INTERFACE
    Include/stm32l4a6xx.h
    Include/stm32l4p5xx.h
    Include/stm32l4q5xx.h
    Include/stm32l4r5xx.h
    Include/stm32l4r7xx.h
    Include/stm32l4r9xx.h
    Include/stm32l4s5xx.h
    Include/stm32l4s7xx.h
    Include/stm32l4s9xx.h
    Include/stm32l4xx.h
    Include/stm32l412xx.h
    Include/stm32l422xx.h
    Include/stm32l431xx.h
    Include/stm32l432xx.h
    Include/stm32l433xx.h
    Include/stm32l442xx.h
    Include/stm32l443xx.h
    Include/stm32l451xx.h
    Include/stm32l452xx.h
    Include/stm32l462xx.h
    Include/stm32l471xx.h
    Include/stm32l475xx.h
    Include/stm32l476xx.h
    Include/stm32l485xx.h
    Include/stm32l486xx.h
    Include/stm32l496xx.h
    Include/system_stm32l4xx.h
 
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L412xx>: ${_template_dir}/startup_stm32l412xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L422xx>: ${_template_dir}/startup_stm32l422xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L431xx>: ${_template_dir}/startup_stm32l431xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L432xx>: ${_template_dir}/startup_stm32l432xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L433xx>: ${_template_dir}/startup_stm32l433xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L442xx>: ${_template_dir}/startup_stm32l442xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L443xx>: ${_template_dir}/startup_stm32l443xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L451xx>: ${_template_dir}/startup_stm32l451xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L452xx>: ${_template_dir}/startup_stm32l452xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L462xx>: ${_template_dir}/startup_stm32l462xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L471xx>: ${_template_dir}/startup_stm32l471xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L475xx>: ${_template_dir}/startup_stm32l475xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L476xx>: ${_template_dir}/startup_stm32l476xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L485xx>: ${_template_dir}/startup_stm32l485xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L486xx>: ${_template_dir}/startup_stm32l486xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L496xx>: ${_template_dir}/startup_stm32l496xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4A6xx>: ${_template_dir}/startup_stm32l4a6xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4P5xx>: ${_template_dir}/startup_stm32l4p5xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4Q5xx>: ${_template_dir}/startup_stm32l4q5xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4R5xx>: ${_template_dir}/startup_stm32l4r5xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4R7xx>: ${_template_dir}/startup_stm32l4r7xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4R9xx>: ${_template_dir}/startup_stm32l4r9xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4S5xx>: ${_template_dir}/startup_stm32l4s5xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4S7xx>: ${_template_dir}/startup_stm32l4s7xx.s>
    $<$<STREQUAL:${CMSIS_DEVICE_NAME},STM32L4S9xx>: ${_template_dir}/startup_stm32l4s9xx.s>
)

set_target_properties(cmsis_device_l4 PROPERTIES LINKER_LANGUAGE C)

target_compile_definitions(cmsis_device_l4
  INTERFACE
    ${CMSIS_DEVICE_NAME}
    USE_HAL_DRIVER
)

target_include_directories(cmsis_device_l4
  INTERFACE
    Include
)

target_link_libraries(cmsis_device_l4
  INTERFACE
        cmsis::core
)
