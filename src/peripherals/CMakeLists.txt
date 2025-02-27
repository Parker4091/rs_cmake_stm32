
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

# -----------------------------------------------------------------------------
add_library(peripherals INTERFACE)
add_library(mw_example_project::peripherals ALIAS peripherals)

target_link_libraries(peripherals
    INTERFACE
        peripherals::crc
        peripherals::delay
        peripherals::dma
        peripherals::flash
        # peripherals::fmc
        peripherals::gpio
        peripherals::i2c
        peripherals::spi
        peripherals::timer
        peripherals::usart
        peripherals::watchdog
)

# -----------------------------------------------------------------------------
add_subdirectory(crc)
add_subdirectory(delay)
add_subdirectory(dma)
add_subdirectory(flash)
# add_subdirectory(fmc) # Enable when it will be used
add_subdirectory(gpio)
add_subdirectory(i2c)
add_subdirectory(spi)
add_subdirectory(timer)
add_subdirectory(usart)
add_subdirectory(watchdog)

