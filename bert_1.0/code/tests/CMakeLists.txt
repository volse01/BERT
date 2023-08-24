cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(pump_test
pump_test.c
)
pico_enable_stdio_usb(pump_test 1)
pico_enable_stdio_uart(pump_test 0)
pico_add_extra_outputs(pump_test)
target_link_libraries(pump_test pico_stdlib hardware_gpio)