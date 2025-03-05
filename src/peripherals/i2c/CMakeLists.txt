
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_i2c STATIC)
add_library(peripherals::i2c ALIAS peripherals_i2c)

target_sources(peripherals_i2c
    PRIVATE
        include/i2c.h
        i2c.c
)

target_include_directories(peripherals_i2c
    PUBLIC
        include
)

target_compile_options(peripherals_i2c
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_i2c
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_i2c
    PUBLIC
        mw_example_project::hw_config
        mw_example_project::util
    PRIVATE
        stm32h7xx::hal_driver
        peripherals::gpio
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
