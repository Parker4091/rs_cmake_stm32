MockTarget (
    USE_GMOCK_C
    TARGET peripherals_usart
    SOURCES
        mock_usart.h
        mock_usart.cpp
)

if (TARGET Mock_peripherals_usart)
    target_ignore_static_analysis(TARGET Mock_peripherals_usart CLANG_TIDY)
endif()