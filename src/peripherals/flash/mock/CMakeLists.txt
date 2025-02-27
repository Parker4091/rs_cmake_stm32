MockTarget (
    USE_GMOCK_C
    TARGET peripherals_flash
    SOURCES
        mock_flash.h
        mock_flash.cpp
)

if (TARGET Mock_peripherals_flash)
    target_ignore_static_analysis(TARGET Mock_peripherals_flash CLANG_TIDY)
endif()
