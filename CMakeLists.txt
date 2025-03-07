#######################################################################
#
cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0048 NEW) # project version
cmake_policy(SET CMP0065 NEW) # do not add rdynamic unless explicitly stated
cmake_policy(SET CMP0076 NEW) # full paths
cmake_policy(SET CMP0077 NEW) # options do nothing when defined as variable.
#cmake_policy(SET CMP0135 NEW) # fetchcontent url timestamp cmake 3.25

option(BUILD_TEST      "Builds the tests"           ON)
option(BUILD_DOC       "Builds the documentation"   OFF)
option(STATIC_ANALYSIS "Use Static Analysis tools." ON)
option(BUILD_BENCHMARK "No use of benchmark builds for this repo" OFF)

# Design & Implementation
include(FetchContent)

#options from front-end build environment: BUILD_TEST, STATIC_ANALYSIS, BUILD_DOC, VERILOG_TEST
#set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
FetchContent_Declare( cmake
  GIT_REPOSITORY https://github.com/Retlek-Systems-Inc/rs_cmake.git
  GIT_TAG        v0.4.5
)

FetchContent_GetProperties(cmake)
if(NOT cmake_POPULATED)
  FetchContent_Populate(cmake)
  include(${cmake_SOURCE_DIR}/Init.cmake)
endif()

########################################################################
#
# Project-wide settings
# Note: CXX is only for the test environment code.
project(mw_example_project VERSION 0.0.2 LANGUAGES C CXX)

if (CMAKE_CROSSCOMPILING)
    message(STATUS "Cross compiling Build targets")
    enable_language(ASM)
else()
    message(STATUS "Native compile for Build targets")
    # Now add the definitions of each
    include(CodeCoverage)
    include(Sanitizer)
endif()

########################################################################
# Requirements
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# For testing purposes
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

########################################################################
# Options
add_compile_options(
    $<$<COMPILE_LANG_AND_ID:C,GNU>:-fdiagnostics-color=always>
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-fcolor-diagnostics>

    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wall>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wextra>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wpedantic>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Werror>
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-Weverything>

    # Allow clang and gnu pramgmas.
    $<$<COMPILE_LANG_AND_ID:C,GNU>:-Wno-unknown-pragmas>
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-Wno-typedef-redefinition>

    # Documentation types
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-fcomment-block-commands=retval> # Doesn't recongize doxygen retval
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-fcomment-block-commands=copydetails> # Doesn't recongize doxygen copydetails

    # Cross compiling for STM32 Cortex-M4
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-mcpu=cortex-m4>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-mfpu=fpv4-sp-d16>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-mfloat-abi=hard>

    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-g3> # TODO Identify what this is
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-MMD> # Only use header files not system files.

    # For Unit Tests.
    $<$<COMPILE_LANG_AND_ID:CXX,GNU>:-fdiagnostics-color=always>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-fcolor-diagnostics>

    $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wall>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wextra>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wpedantic>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Werror>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Weverything>

    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-c++98-compat>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-c++98-compat-pedantic>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-Wno-c++20-designator>
)

if (CMAKE_CROSSCOMPILING)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT IPO_supported OUTPUT IPO_error)
    if( IPO_supported )
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)  # Enable Link-Time-Optimization for everything.
    else()
        message(STATUS "IPO / LTO not supported: <${IPO_error}>")
    endif()
endif()

# -----------------------------------------------------------------------------
add_subdirectory(src)
add_subdirectory(ThirdParty)

# -----------------------------------------------------------------------------
# Note need to do this last because requires all of the sub-components to
# add/append to the COVERAGE_LCOV_EXCLUDES cached variable.
# Don't include mock or tests as part of coverage.
list(APPEND COVERAGE_LCOV_EXCLUDES '*/mock/*' '*/test/*' '*/src/peripherals/*' '*/ThirdParty/*' '*/build/*'
    '*/src/stm32*' '*/src/main*' '*/src/cm4_handlers/*'
    "${stm32h7rsxx_hal_driver_SOURCE_DIR}/*"
    "${fmt_SOURCE_DIR}/*"
)
setup_code_coverage_target()

########################################################################
# Install rules
# Not intended for installation but for inclusion with a pre-existing
# cmake build environment.

#install(TARGETS ${PROJECT_NAME}
#  DESTINATION lib)
