
add_library(peripherals_crc STATIC)
add_library(peripherals::crc ALIAS peripherals_crc)

target_sources(peripherals_crc
    PRIVATE
        include/crc.h
        crc.c
)

target_include_directories(peripherals_crc
    PUBLIC
        include
)

target_compile_options(peripherals_crc
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
)

target_clang_tidy_definitions(TARGET peripherals_crc
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_crc
    PUBLIC
        mw_example_project::hw_config
        mw_example_project::util
    PRIVATE
        stm32h7rsxx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
