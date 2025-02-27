MockTarget (
    USE_GMOCK_C
    TARGET peripherals_i2c
    SOURCES
        mock_i2c.h
        mock_i2c.cpp
)

if (TARGET Mock_peripherals_i2c)
    target_ignore_static_analysis(TARGET Mock_peripherals_i2c CLANG_TIDY)
endif()