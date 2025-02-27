
#--------------------------------------------------------------------
FetchContent_GetProperties(cmsis_core)
if(NOT cmsis_core_POPULATED)
    FetchContent_Populate(cmsis_core)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/cmsis_core.cmake "${cmsis_core_SOURCE_DIR}/CMakeLists.txt" COPYONLY)
    add_subdirectory(${cmsis_core_SOURCE_DIR} ${cmsis_core_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
target_ignore_static_analysis(TARGET cmsis_core CLANG_TIDY)

#--------------------------------------------------------------------

add_library(cmsis::core ALIAS cmsis_core )
