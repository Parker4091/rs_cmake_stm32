# Third Party Software and Toolchain setup

This directory is for describing third-party code and information.

The reason for changing is to:
* Support upgrades and updates from latest repository changes instead of copying a version of the code here.
* Support native-compilation to allow compilation on linux for code analysis and linter tools.
* Support cross-compilation for the board as well to generate elf files.

List of third party:

See top-level CMakeLists.txt for full list and versions

* rscmake - the Retlek Systems CMake environment - tools for compilation and running unit tests with various sanitizers and linters
* googletest/googlemock - the preferred Locally compiled unit test environment.
* benchmark - a benchmark utility (not for embedded - but for native apps)
* fmt - format library for C++17 - used in unit tests.

* cmsis_core - the ARM CMSIS core code.
* cmsis_device - the ARM CMSIS device code.
* stm32_hal - the STM32 Hardware Adaptation Layer (HAL) code.
  * Also includes syscalls and sysmem definition.
