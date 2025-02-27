
add_library(peripherals_delay STATIC)
add_library(peripherals::delay ALIAS peripherals_delay)

target_sources(peripherals_delay
    PRIVATE
        include/delay.h
        delay.c
)

target_include_directories(peripherals_delay
    PUBLIC
        include
)

target_link_libraries(peripherals_delay
    PRIVATE
        stm32l4xx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
