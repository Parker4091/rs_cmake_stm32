MockTarget (
  USE_GMOCK_C
  TARGET cmsis_device_h7
  SOURCES
    mock_cmsis_device_h7.h
    mock_cmsis_device_h7.cpp
)

if (TARGET Mock_cmsis_device_h7)
    target_compile_options(Mock_cmsis_device_h7
        PRIVATE
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-reserved-identifier>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-invalid-noreturn>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-missing-prototypes>
    )
    
    target_link_libraries(Mock_cmsis_device_h7
        PUBLIC
            cmsis::core
    )

    target_ignore_static_analysis(TARGET Mock_cmsis_device_h7 CLANG_TIDY)
endif()
