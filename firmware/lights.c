#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "stc15x10x.h"

#include "globals.h"

#define BRAKE_LED P30
#define REVERSING_LED P31


// ****************************************************************************
void init_lights(void)
{
    BRAKE_LED = 0;
    REVERSING_LED = 0;

    // Make P3.0 and P3.1 a push-pull output
    P3M0 = (1 << 0) | (1 << 1);
    P3M1 = 0x00;
}


// ****************************************************************************
void process_lights(void)
{
    if (global_flags.reversing) {
        REVERSING_LED = 1;
    }
    else {
        REVERSING_LED = 0;
    }

    if (global_flags.braking) {
        BRAKE_LED = 1;
    }
    else {
        BRAKE_LED = 0;
    }
}
