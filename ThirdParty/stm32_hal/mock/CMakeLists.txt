MockTarget (
    USE_GMOCK_C
    TARGET stm32h7rsxx_hal_sys
    SOURCES
        mock_stm32_hal_sys.h
        mock_stm32_hal_sys.cpp
)

if (TARGET Mock_stm32h7rsxx_hal_sys)
    target_ignore_static_analysis(TARGET Mock_stm32h7rsxx_hal_sys CLANG_TIDY)
    target_compile_options(Mock_stm32h7rsxx_hal_sys
        PRIVATE
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-reserved-identifier>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-invalid-noreturn>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-missing-prototypes>
    )
endif()

# -------------------------------------------------------------------
MockTarget (
    USE_GMOCK_C
    TARGET stm32h7rsxx_hal_driver
    SOURCES
        mock_stm32_hal_driver.h
        mock_stm32_hal_driver.cpp
)

if (TARGET Mock_stm32h7rsxx_hal_driver)
    target_ignore_static_analysis(TARGET Mock_stm32h7rsxx_hal_driver CLANG_TIDY)
endif()
