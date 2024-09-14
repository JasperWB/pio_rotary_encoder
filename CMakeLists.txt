cmake_minimum_required(VERSION 3.29)
set(PICO_BOARD pico)
include(pico_sdk_import.cmake)
project(pio_rotary_encoder C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pio_rotary_encoder
    pio_rotary_encoder.c
)

target_include_directories(pio_rotary_encoder PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_generate_pio_header(pio_rotary_encoder ${CMAKE_CURRENT_LIST_DIR}/pio_rotary_encoder.pio)

target_sources(pio_rotary_encoder PRIVATE pio_rotary_encoder.c)

target_link_libraries(pio_rotary_encoder
    pico_stdlib
    hardware_pio
)

pico_enable_stdio_usb(pio_rotary_encoder 1)
pico_enable_stdio_uart(pio_rotary_encoder 0)

pico_add_extra_outputs(pio_rotary_encoder)
