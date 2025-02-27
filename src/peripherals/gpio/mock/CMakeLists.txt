MockTarget (
    USE_GMOCK_C
    TARGET peripherals_gpio
    SOURCES
        mock_gpio.h
        mock_gpio.cpp
)

if (TARGET Mock_peripherals_gpio)
    target_ignore_static_analysis(TARGET Mock_peripherals_gpio CLANG_TIDY)
endif()
