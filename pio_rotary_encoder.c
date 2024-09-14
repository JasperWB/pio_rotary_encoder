/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pio_rotary_encoder.pio.h"

#define jmp_pin 18
#define in_pin 16
#define in_pin_count 2
#define frequency 2000

int main() {
    stdio_init_all();
    
    gpio_init(16);
    gpio_init(17);
    gpio_init(18);
    gpio_set_dir(16,false);
    gpio_set_dir(17,false);
    gpio_set_dir(18,false);

    PIO pio = pio0;
    uint sm_id = 0;
    uint offset = 0; 
    pio_add_program(pio, &rotary_encoder_program);
    rotary_encoder_program_init(pio, sm_id, offset, jmp_pin, in_pin, in_pin_count, frequency);

    while(true){
        int word = pio_sm_get_blocking(pio, sm_id);
        printf("%d\n", word);
    }
}

