# -------------------------------------------------------------------
add_library(cmsis_core  INTERFACE)

target_sources(cmsis_core
    INTERFACE
        Include/cmsis_armcc.h
        Include/cmsis_armclang_ltm.h
        Include/cmsis_armclang.h
        Include/cmsis_compiler.h
        Include/cmsis_gcc.h
        Include/cmsis_iccarm.h
        Include/cmsis_version.h
        Include/core_armv8mbl.h
        Include/core_armv8mml.h
        Include/core_armv81mml.h
        Include/core_cm0.h
        Include/core_cm0plus.h
        Include/core_cm1.h
        Include/core_cm3.h
        Include/core_cm4.h
        Include/core_cm7.h
        Include/core_cm23.h
        Include/core_cm33.h
        Include/core_cm35p.h
        Include/core_sc000.h
        Include/core_sc300.h
        Include/mpu_armv7.h
        Include/mpu_armv8.h
        Include/tz_context.h
)

# target_sources(cmsis_core
#     INTERFACE
#         Include/cmsis_armcc.h
#         Include/cmsis_armclang.h
#         Include/cmsis_armclang_ltm.h
#         Include/cmsis_compiler.h
#         Include/cmsis_gcc.h
#         Include/cmsis_iccarm.h
#         Include/cmsis_version.h
#         Include/core_armv81mml.h
#         Include/core_armv8mbl.h
#         Include/core_armv8mml.h
#         Include/core_cm0.h
#         Include/core_cm0plus.h
#         Include/core_cm1.h
#         Include/core_cm23.h
#         Include/core_cm3.h
#         Include/core_cm33.h
#         Include/core_cm35p.h
#         Include/core_cm4.h
#         Include/core_cm55.h
#         Include/core_cm7.h
#         Include/core_cm85.h
#         Include/core_sc000.h
#         Include/core_sc300.h
#         Include/core_starmc1.h
#         Include/mpu_armv7.h
#         Include/mpu_armv8.h
#         Include/pac_armv81.h
#         Include/pmu_armv8.h
#         Include/tz_context.h
# )

# target_compile_options(cmsis_core
# )

target_include_directories(cmsis_core SYSTEM
  INTERFACE
    Include
)
