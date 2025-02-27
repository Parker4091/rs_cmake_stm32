MockTarget (
    USE_GMOCK_C
    TARGET peripherals_fmc
    SOURCES
        mock_fmc.h
        mock_fmc.cpp
)

if (TARGET Mock_peripherals_fmc)
    target_ignore_static_analysis(TARGET Mock_peripherals_fmc CLANG_TIDY)
endif()
