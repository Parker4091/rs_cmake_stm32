
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_timer STATIC)
add_library(peripherals::timer ALIAS peripherals_timer)

target_sources(peripherals_timer
    PRIVATE
        include/timer.h
        timer.c
)

target_include_directories( peripherals_timer
    PUBLIC
        include
)

target_compile_options(peripherals_timer
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_timer
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_timer
    PUBLIC
        mw_example_project::hw_config
        mw_example_project::util
    PRIVATE
        stm32h7rsxx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
