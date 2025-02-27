MockTarget (
    USE_GMOCK_C
    TARGET peripherals_timer
    SOURCES
        mock_timer.h
        mock_timer.cpp
)

if (TARGET Mock_peripherals_timer)
    target_ignore_static_analysis(TARGET Mock_peripherals_timer CLANG_TIDY)
endif()