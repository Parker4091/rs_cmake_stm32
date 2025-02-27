MockTarget (
    USE_GMOCK_C
    TARGET peripherals_crc
    SOURCES
        mock_crc.h
        mock_crc.cpp
)

if (TARGET Mock_peripherals_crc)
    target_ignore_static_analysis(TARGET Mock_peripherals_crc CLANG_TIDY)
endif()
