
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_fmc STATIC)
add_library(peripherals::fmc ALIAS peripherals_fmc)

target_sources(peripherals_fmc
    PRIVATE
        include/fmc.h
        fmc.c
)

target_include_directories(peripherals_fmc
    PUBLIC
        include
)

target_compile_options(peripherals_fmc
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_fmc
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_fmc
    PRIVATE
        mw_example_project::hw_config
        mw_example_project::util
        stm32h7rsxx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
