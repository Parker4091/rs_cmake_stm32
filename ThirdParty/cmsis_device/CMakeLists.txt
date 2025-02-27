
#--------------------------------------------------------------------
FetchContent_GetProperties(cmsis_device_l4)
if(NOT cmsis_device_l4_POPULATED)
    FetchContent_Populate(cmsis_device_l4)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/cmsis_device_l4.cmake "${cmsis_device_l4_SOURCE_DIR}/CMakeLists.txt" COPYONLY)
    add_subdirectory(${cmsis_device_l4_SOURCE_DIR} ${cmsis_device_l4_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# No clang-tidy on this repo.
target_ignore_static_analysis(TARGET cmsis_device_l4 CLANG_TIDY)

#--------------------------------------------------------------------

add_library(cmsis::device_l4 ALIAS cmsis_device_l4 )
