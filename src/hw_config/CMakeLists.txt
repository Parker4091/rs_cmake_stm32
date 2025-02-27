add_library(mw_example_project_hw_config INTERFACE)
add_library(mw_example_project::hw_config ALIAS mw_example_project_hw_config)

target_sources(mw_example_project_hw_config
    INTERFACE
        include/board.h
)

target_include_directories(mw_example_project_hw_config
    INTERFACE
        include
)

target_link_libraries(mw_example_project_hw_config
    INTERFACE
        peripherals::gpio    
)

target_compile_definitions(mw_example_project_hw_config
    INTERFACE
        $<$<NOT:$<BOOL:${CMAKE_CROSSCOMPILING}>>:UNIX_SLEEP>
)