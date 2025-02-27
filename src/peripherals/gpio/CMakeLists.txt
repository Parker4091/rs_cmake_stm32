
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_gpio STATIC)
add_library(peripherals::gpio ALIAS peripherals_gpio)

target_sources(peripherals_gpio
    PRIVATE
        include/gpio.h
        gpio.c
)

target_include_directories( peripherals_gpio
    PUBLIC
        include
)

target_compile_options(peripherals_gpio
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_gpio
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_gpio
    PUBLIC
        mw_example_project::hw_config
        mw_example_project::util
    PRIVATE
        stm32l4xx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
