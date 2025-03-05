
# -----------------------------------------------------------------------------
add_library(debug_logging STATIC)
add_library(mw_example_project::util::debug_logging ALIAS debug_logging)
target_sources(debug_logging
    PRIVATE
        include/debug_logging.h
    INTERFACE
        src/debug_logging.c
)
set_target_properties(debug_logging PROPERTIES LINKER_LANGUAGE C)

target_include_directories(debug_logging
    PUBLIC
        include
)

target_compile_options(debug_logging
    INTERFACE
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-identifier>
        $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-prototypes>
)

target_link_libraries(debug_logging
    INTERFACE
        peripherals::usart
    PRIVATE
        stm32h7xx::hal_driver
)

# -----------------------------------------------------------------------------
add_library(util STATIC)
add_library(mw_example_project::util ALIAS util)

target_sources( util
  PRIVATE
    include/app_assert.h
    include/types.h

    src/app_assert.c
)

target_include_directories( util
  PUBLIC
    include
)

target_clang_tidy_definitions(TARGET util
    CHECKS
        -altera-unroll-loops
)

target_compile_options(util
  PRIVATE
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-identifier>
)

target_link_libraries(util
    PUBLIC
        mw_example_project::hw_config
    PRIVATE
        peripherals::usart
        stm32h7xx::hal_driver
)
