
#--------------------------------------------------------------------

FetchContent_Declare( cmsis_core
  GIT_REPOSITORY https://github.com/STMicroelectronics/cmsis_core
  GIT_TAG        v5.6.0
)

FetchContent_Declare( cmsis_device_l4
  GIT_REPOSITORY https://github.com/STMicroelectronics/cmsis_device_l4
  GIT_TAG        v1.7.2
)

FetchContent_Declare( stm32l4xx_hal_driver
  GIT_REPOSITORY https://github.com/STMicroelectronics/stm32l4xx_hal_driver
  GIT_TAG        v1.13.3
)

FetchContent_Declare( fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        8.0.1
)

#--------------------------------------------------------------------
FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    list(APPEND COVERAGE_LCOV_EXCLUDES '${fmt_SOURCE_DIR}/*')
    add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# No clang-tidy on this repo.
target_ignore_static_analysis(TARGET fmt CLANG_TIDY)
target_ignore_static_analysis(TARGET fmt-header-only CLANG_TIDY)

#--------------------------------------------------------------------
add_subdirectory(cmsis_core)
add_subdirectory(cmsis_device)
add_subdirectory(stm32_hal)
