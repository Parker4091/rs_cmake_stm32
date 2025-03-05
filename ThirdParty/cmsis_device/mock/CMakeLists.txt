MockTarget (
  USE_GMOCK_C
  TARGET cmsis_device_h7rs
  SOURCES
    mock_cmsis_device_h7rs.h
    mock_cmsis_device_h7rs.cpp
)

if (TARGET Mock_cmsis_device_h7rs)
    target_compile_options(Mock_cmsis_device_h7rs
        PRIVATE
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-reserved-identifier>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-invalid-noreturn>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-missing-prototypes>
    )
    
    target_link_libraries(Mock_cmsis_device_h7rs
        PUBLIC
            cmsis::core
    )

    target_ignore_static_analysis(TARGET Mock_cmsis_device_h7rs CLANG_TIDY)
endif()
