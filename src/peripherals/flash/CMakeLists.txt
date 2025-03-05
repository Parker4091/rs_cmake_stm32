
add_library(peripherals_flash STATIC)
add_library(peripherals::flash ALIAS peripherals_flash)

target_sources(peripherals_flash
    PRIVATE
        include/flash.h
        flash.c
)

target_include_directories(peripherals_flash
    PUBLIC
        include
)

target_compile_options(peripherals_flash
    PRIVATE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-int-to-void-pointer-cast>  # TODO(smodi): Figure out how to get rid of this
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-int-to-pointer-cast>  # TODO(smodi): Figure out how to get rid of this
)

target_clang_tidy_definitions(TARGET peripherals_flash
    CHECKS
        -altera-unroll-loops
        -performance-no-int-to-ptr
)

target_link_libraries(peripherals_flash
    PUBLIC
        mw_example_project::hw_config
        mw_example_project::util
    PRIVATE
        stm32h7xx::hal_driver
)

# -----------------------------------------------------------------------------
add_subdirectory(mock)
