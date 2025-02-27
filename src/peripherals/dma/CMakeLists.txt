
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_dma STATIC)
add_library(peripherals::dma ALIAS peripherals_dma)

target_sources(peripherals_dma
    PRIVATE
        include/dma.h
        dma.c
)

target_include_directories( peripherals_dma
    PUBLIC
        include
)

target_compile_options(peripherals_dma
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_dma
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)


target_link_libraries(peripherals_dma
    PRIVATE
        stm32l4xx::hal_driver
        mw_example_project::hw_config
        mw_example_project::util
)
# -----------------------------------------------------------------------------
add_subdirectory(mock)
