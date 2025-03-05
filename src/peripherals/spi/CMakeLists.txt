
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_spi STATIC)
add_library(peripherals::spi ALIAS peripherals_spi)

target_sources(peripherals_spi
    PRIVATE
        include/spi.h
        spi.c
)

target_include_directories( peripherals_spi
    PUBLIC
        include
)

target_compile_options(peripherals_spi
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-unused-function>
)

target_clang_tidy_definitions(TARGET peripherals_spi
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_spi
    PUBLIC
        mw_example_project::util
    PRIVATE
        mw_example_project::hw_config
        peripherals::dma
        stm32h7xx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
