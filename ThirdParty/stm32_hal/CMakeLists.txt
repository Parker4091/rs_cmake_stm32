
#--------------------------------------------------------------------
FetchContent_GetProperties(stm32l4xx_hal_driver)
if(NOT stm32l4xx_hal_driver_POPULATED)
    FetchContent_Populate(stm32l4xx_hal_driver)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/stm32l4xx_hal_driver.cmake "${stm32l4xx_hal_driver_SOURCE_DIR}/CMakeLists.txt" COPYONLY)
    add_subdirectory(${stm32l4xx_hal_driver_SOURCE_DIR} ${stm32l4xx_hal_driver_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# No clang-tidy on this repo.
target_ignore_static_analysis(TARGET stm32l4xx_hal_driver CLANG_TIDY)

#--------------------------------------------------------------------
macro(add_stm32l4xx_hal_sys_lib  TARGET)

add_library(${TARGET} STATIC)

target_sources(${TARGET}
    INTERFACE
         src/syscalls.c
         src/sysmem.c
         src/stm32l4xx_hal_msp.c
)

target_compile_options(${TARGET}
    PRIVATE
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-int-to-pointer-cast>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-identifier>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-variable-declarations>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-prototypes>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-strict-prototypes>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-pointer-to-int-cast>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-implicit-int-conversion>
         $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-declaration-after-statement>
)

endmacro()

add_stm32l4xx_hal_sys_lib(stm32l4xx_hal_sys)

target_link_libraries(stm32l4xx_hal_sys
    PRIVATE
        stm32l4xx::hal_driver
)


target_clang_tidy_definitions(TARGET stm32l4xx_hal_sys
    CHECKS
        -altera-unroll-loops
        -bugprone-easily-swappable-parameters
        -*-narrowing-conversions
        -bugprone-reserved-identifier
        -cert-dcl37-c
        -cert-dcl51-cpp
        -cppcoreguidelines-avoid-non-const-global-variables
        -cppcoreguidelines-init-variables
        -llvm-include-order
        -performance-no-int-to-ptr
        -readability-identifier-length
        -readability-non-const-parameter
)

add_library(stm32l4xx::hal_sys ALIAS stm32l4xx_hal_sys)
add_library(stm32l4xx::hal_driver ALIAS stm32l4xx_hal_driver )
