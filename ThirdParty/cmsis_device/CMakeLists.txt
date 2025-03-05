
#--------------------------------------------------------------------
FetchContent_GetProperties(cmsis_device_h7)
if(NOT cmsis_device_h7_POPULATED)
    FetchContent_Populate(cmsis_device_h7)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/cmsis_device_h7.cmake "${cmsis_device_h7_SOURCE_DIR}/CMakeLists.txt" COPYONLY)
    add_subdirectory(${cmsis_device_h7_SOURCE_DIR} ${cmsis_device_h7_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# No clang-tidy on this repo.
target_ignore_static_analysis(TARGET cmsis_device_h7 CLANG_TIDY)

#--------------------------------------------------------------------

add_library(cmsis::device_h7 ALIAS cmsis_device_h7 )
