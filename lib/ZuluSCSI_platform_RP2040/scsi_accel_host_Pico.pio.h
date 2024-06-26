// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// -------------------- //
// scsi_host_async_read //
// -------------------- //

#define scsi_host_async_read_wrap_target 0
#define scsi_host_async_read_wrap 6

static const uint16_t scsi_host_async_read_program_instructions[] = {
            //     .wrap_target
    0x90a0, //  0: pull   block           side 1     
    0xb027, //  1: mov    x, osr          side 1     
    0x3011, //  2: wait   0 gpio, 17      side 1     
    0x4009, //  3: in     pins, 9         side 0     
    0x4067, //  4: in     null, 7         side 0     
    0x2091, //  5: wait   1 gpio, 17      side 0     
    0x1042, //  6: jmp    x--, 2          side 1     
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program scsi_host_async_read_program = {
    .instructions = scsi_host_async_read_program_instructions,
    .length = 7,
    .origin = -1,
};

static inline pio_sm_config scsi_host_async_read_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + scsi_host_async_read_wrap_target, offset + scsi_host_async_read_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}
#endif
