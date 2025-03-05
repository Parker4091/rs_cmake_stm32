
#--------------------------------------------------------------------
FetchContent_GetProperties(cmsis_device_h7rs)
if(NOT cmsis_device_h7rs_POPULATED)
    FetchContent_Populate(cmsis_device_h7rs)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/cmsis_device_h7rs.cmake "${cmsis_device_h7rs_SOURCE_DIR}/CMakeLists.txt" COPYONLY)
    add_subdirectory(${cmsis_device_h7rs_SOURCE_DIR} ${cmsis_device_h7rs_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# No clang-tidy on this repo.
target_ignore_static_analysis(TARGET cmsis_device_h7rs CLANG_TIDY)

#--------------------------------------------------------------------

add_library(cmsis::device_h7rs ALIAS cmsis_device_h7rs )
