MockTarget (
    USE_GMOCK_C
    TARGET peripherals_watchdog
    SOURCES
        mock_watchdog.h
        mock_watchdog.cpp
)

if (TARGET Mock_peripherals_watchdog)
    target_ignore_static_analysis(TARGET Mock_peripherals_watchdog CLANG_TIDY)
endif()
