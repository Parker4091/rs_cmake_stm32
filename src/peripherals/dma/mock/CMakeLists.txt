MockTarget (
    USE_GMOCK_C
    TARGET peripherals_dma
    SOURCES
        mock_dma.h
        mock_dma.cpp
)

if (TARGET Mock_peripherals_dma)
    target_ignore_static_analysis(TARGET Mock_peripherals_dma CLANG_TIDY)
endif()
