
# -----------------------------------------------------------------------------
# Configure the version based on the project version defined in project()

CreateVersion(
    PROJECT mw_example_project
    TARGET env_fw_version
    FILENAME project_version
    VARIABLE mw_example_projectVersion
    OUTDIR ${CMAKE_CURRENT_LIST_DIR}/version
    LANGUAGE C)
add_library(env::fw_version ALIAS env_fw_version)
target_compile_options(env_fw_version
  INTERFACE
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-padded>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wno-padded>
)

# -----------------------------------------------------------------------------
add_executable(mw_example_project)

target_sources(mw_example_project
  PRIVATE
    cm4_handlers/cm4_handlers.h
    cm4_handlers/cm4_handlers.c
    main.c
)

target_include_directories(mw_example_project
  PRIVATE
    include
)

target_compile_options(mw_example_project
  PRIVATE
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-date-time>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-missing-noreturn>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-reserved-macro-identifier>
    $<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-Wno-shorten-64-to-32> # TODO(smodi): Figure out how to get rid of this
)

target_clang_tidy_definitions(TARGET mw_example_project
    CHECKS
        -altera-unroll-loops
        -*-magic-numbers
)

target_link_options(mw_example_project
  PRIVATE
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-mcpu=cortex-m4>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-mfpu=fpv4-sp-d16>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-mfloat-abi=hard>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-specs=nosys.specs>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-T${CMAKE_CURRENT_LIST_DIR}/STM32L4S5ZITx_FLASH.ld>
    $<$<BOOL:${CMAKE_CROSSCOMPILING}>:LINKER:--no-warn-rwx-segments> # https://community.st.com/s/question/0D53W00001vno1oSAA/warning-elffile-has-a-load-segment-with-rwx-permissions
)

target_link_libraries(mw_example_project
    PRIVATE
        mw_example_project::hw_config
        mw_example_project::peripherals
        mw_example_project::util
        mw_example_project::util::debug_logging
        stm32h7xx::hal_sys
        stm32h7xx::hal_driver
        $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-Wl,--start-group>
        $<$<BOOL:${CMAKE_CROSSCOMPILING}>:gcc>
        $<$<BOOL:${CMAKE_CROSSCOMPILING}>:c>
        $<$<BOOL:${CMAKE_CROSSCOMPILING}>:-Wl,--end-group>
)

target_link_options(mw_example_project
    PRIVATE
        -ffreestanding
        -Wl,--gc-sections
        -Wl,--print-memory-usage
)

#set_target_properties(mw_example_project PROPERTIES LINK_DEPENDS STM32L4S5ZITx_FLASH.ld)

# Note: This copies the name with the appropriate postfix CMAKE_PROJECT_VERSION is defined by project()
# in the top level CMakeLists.txt file.
if (CMAKE_CROSSCOMPILING)
    string(CONCAT _elfTargetPostFix ${CMAKE_PROJECT_VERSION} ".elf")
    string(CONCAT _hexTargetPostFix ${CMAKE_PROJECT_VERSION} ".hex")
    string(CONCAT _binTargetPostFix ${CMAKE_PROJECT_VERSION} ".bin")
    add_custom_command(TARGET mw_example_project POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:mw_example_project> $<TARGET_FILE:mw_example_project>-${_elfTargetPostFix}
        COMMAND ${TOOLCHAIN_OBJCOPY} -O ihex $<TARGET_FILE:mw_example_project>-${_elfTargetPostFix} $<TARGET_FILE:mw_example_project>-${_hexTargetPostFix}
        COMMAND ${TOOLCHAIN_OBJCOPY} -O binary $<TARGET_FILE:mw_example_project>-${_elfTargetPostFix} $<TARGET_FILE:mw_example_project>-${_binTargetPostFix}
    )
endif()

# -----------------------------------------------------------------------------
add_subdirectory(hw_config)
add_subdirectory(peripherals)
add_subdirectory(stm32_hal_conf)
add_subdirectory(util)
