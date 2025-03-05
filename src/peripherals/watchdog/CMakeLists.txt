
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals_watchdog STATIC)
add_library(peripherals::watchdog ALIAS peripherals_watchdog)

target_sources(peripherals_watchdog
    PRIVATE
        include/watchdog.h
        watchdog.c
)

target_include_directories(peripherals_watchdog
    PUBLIC
        include
)

target_compile_options(peripherals_watchdog
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
)

target_clang_tidy_definitions(TARGET peripherals_watchdog
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_watchdog
    PRIVATE
        stm32h7rsxx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
