MockTarget (
    USE_GMOCK_C
    TARGET peripherals_delay
    SOURCES
        mock_delay.h
        mock_delay.cpp
)

if (TARGET Mock_peripherals_delay)
    target_ignore_static_analysis(TARGET Mock_peripherals_delay CLANG_TIDY)
endif()
