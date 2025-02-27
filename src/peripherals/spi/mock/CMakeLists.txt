MockTarget (
    USE_GMOCK_C
    TARGET peripherals_spi
    SOURCES
        mock_spi.h
        mock_spi.cpp
)

if (TARGET Mock_peripherals_spi)
    target_ignore_static_analysis(TARGET Mock_peripherals_spi CLANG_TIDY)
endif()