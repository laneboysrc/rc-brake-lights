#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "stc15x10x.h"

#include "globals.h"

#define BRAKE_LED P30
#define REVERSING_LED P31

static uint8_t flash_counter;
static uint8_t esc_mode_counter;


// ****************************************************************************
static void process_setup_lights(void)
{
    ++flash_counter;

    switch (global_flags.setup) {
        case SETUP_THROTTLE_REVERSING:
            // Flash all LEDs at 5 Hz
            if (flash_counter == (100 / __SYSTICK_IN_MS)) {
                BRAKE_LED = REVERSING_LED = 1;
            }

            if (flash_counter >= (200 / __SYSTICK_IN_MS)) {
                flash_counter = 0;
                BRAKE_LED = REVERSING_LED = 0;
            }
            break;

        case SETUP_ESC_MODE:
            // Flash the ESC mode number (0 => 1 flash, 1 => 2 flashes ...)
            // Each on or off period takes 100 ms
            if (flash_counter >= (100 / __SYSTICK_IN_MS)) {
                flash_counter = 0;


                // The LEDs are turned off at every odd count
                if (esc_mode_counter & 1) {
                    BRAKE_LED = REVERSING_LED = 0;
                }
                // The LEDs are turned on at even counts which value is less
                // than or equal two times the ESC mode number
                else if (esc_mode_counter <= (esc_mode << 1)) {
                    BRAKE_LED = REVERSING_LED = 1;
                }

                //The sequence repeats every 15 counts.
                ++esc_mode_counter;
                if (esc_mode_counter == 15) {
                    esc_mode_counter = 0;
                }
            }
            break;

        default:
            break;
    }
}


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
    // Process the lights only every __SYSTICK_IN_MS
    // This way we can easily time blinking and flash effects
    if (!global_flags.systick) {
        return;
    }

    // Setup modes
    if (global_flags.setup) {
        process_setup_lights();
        return;
    }

    // Normal operation
    REVERSING_LED = global_flags.reversing;
    BRAKE_LED = global_flags.braking;

    flash_counter = 0;
    esc_mode_counter = 0;
}
