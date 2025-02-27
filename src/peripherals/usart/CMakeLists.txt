
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_usart STATIC)
add_library(peripherals::usart ALIAS peripherals_usart)

target_sources(peripherals_usart
    PRIVATE
        include/usart.h
        usart.c
)

target_include_directories(peripherals_usart
    PUBLIC
        include
)

target_compile_options(peripherals_usart
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_usart
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_usart
    PUBLIC
        mw_example_project::hw_config
        mw_example_project::util
    PRIVATE
        stm32l4xx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
