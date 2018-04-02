#include <stdio.h>
#include <stdbool.h>

#include "stc15x10x.h"

#include "globals.h"


#define TH_IN INT0

#define SERVO_PULSE_CLAMP_LOW 800
#define SERVO_PULSE_CLAMP_HIGH 2300

#define INITIAL_ENDPOINT_DELTA  250
#define SERVO_PULSE_MIN 600
#define SERVO_PULSE_MAX 2500

#define STARTUP_TIME (2000 / __SYSTICK_IN_MS)


static volatile bool new_data;
static volatile uint16_t raw_data;

static enum {
    WAIT_FOR_FIRST_PULSE,
    WAIT_FOR_TIMEOUT,
    NORMAL_OPERATION
} servo_reader_state = WAIT_FOR_FIRST_PULSE;

CHANNEL_T channel[1] = {
    {   // THROTTLE
        .normalized = 0,
        .absolute = 0,
        .reversed = false,
        .endpoint = {
            .left = 1250,
            .centre = 1500,
            .right = 1750,
        }
    }
};


// ****************************************************************************
static void initialize_channel(CHANNEL_T *c) {
    c->endpoint.centre = c->raw_data;
    c->endpoint.left = c->raw_data - INITIAL_ENDPOINT_DELTA;
    c->endpoint.right = c->raw_data + INITIAL_ENDPOINT_DELTA;
}


// ****************************************************************************
static void normalize_channel(CHANNEL_T *c)
{
    if (c->raw_data < SERVO_PULSE_MIN  ||  c->raw_data > SERVO_PULSE_MAX) {
        c->normalized = 0;
        c->absolute = 0;
        return;
    }

    if (c->raw_data < SERVO_PULSE_CLAMP_LOW) {
        c->raw_data = SERVO_PULSE_CLAMP_LOW;
    }

    if (c->raw_data > SERVO_PULSE_CLAMP_HIGH) {
        c->raw_data = SERVO_PULSE_CLAMP_HIGH;
    }

    if (c->raw_data == c->endpoint.centre) {
        c->normalized = 0;
    }
    else if (c->raw_data < c->endpoint.centre) {
        if (c->raw_data < c->endpoint.left) {
            c->endpoint.left = c->raw_data;
        }
        // In order to acheive a stable 100% value we actually calculate the
        // percentage up to 101%, and then clamp to 100%.
        c->normalized = (c->endpoint.centre - c->raw_data) * 101 /
            (c->endpoint.centre - c->endpoint.left);
        if (c->normalized > 100) {
            c->normalized = 100;
        }
        if (!c->reversed) {
            c->normalized = -c->normalized;
        }
    }
    else {
        if (c->raw_data > c->endpoint.right) {
            c->endpoint.right = c->raw_data;
        }
        c->normalized = (c->raw_data - c->endpoint.centre) * 101 /
            (c->endpoint.right - c->endpoint.centre);
        if (c->normalized > 100) {
            c->normalized = 100;
        }
        if (c->reversed) {
            c->normalized = -c->normalized;
        }
    }

    if (c->normalized < 0) {
        c->absolute = -c->normalized;
    }
    else {
        c->absolute = c->normalized;
    }
}


// ****************************************************************************
void init_servo_reader(void)
{
    // Setup timer 0 with a clock of 1 MHz. We run the CPU at 12 MHz, so the
    // default divide by 12 gives us just that.

    TMOD = 0x09;        // Use Timer0 Mode 1, enable gate mode of INT0
    TL0 = TH0 = 0;

    TH_IN = 1;          // Make the TH an input (weak pull-up)
    IT0 = 1;            // INT0 on falling edge only
}


// ****************************************************************************
void read_all_servo_channels(void)
{
    static uint8_t servo_reader_timer;
    static uint8_t remaining_pulse_count;

    bool new_channel_data = false;

    if (global_flags.systick) {
        if (servo_reader_timer) {
            --servo_reader_timer;
        }
    }

    if (new_data) {
        channel[TH].raw_data = raw_data;
        new_data = false;
        new_channel_data = true;
    }

    switch (servo_reader_state) {
        case WAIT_FOR_FIRST_PULSE:
            // Start Timer0 and enable INT0
            TR0 = 1;
            EX0 = 1;

            servo_reader_timer = STARTUP_TIME / __SYSTICK_IN_MS;
            servo_reader_state = WAIT_FOR_TIMEOUT;
            remaining_pulse_count = 50;
            break;

        case WAIT_FOR_TIMEOUT:
            if (new_channel_data) {
                if (remaining_pulse_count) {
                    --remaining_pulse_count;
                }
            }

            if (servo_reader_timer == 0  &&  remaining_pulse_count == 0) {
                initialize_channel(&channel[TH]);

                servo_reader_state = NORMAL_OPERATION;
                global_flags.initializing = 0;
            }
            break;

        case NORMAL_OPERATION:
            if (new_channel_data) {
                normalize_channel(&channel[TH]);
                global_flags.new_channel_data = true;
            }
            break;

        default:
            servo_reader_state = WAIT_FOR_FIRST_PULSE;
            break;
    }
}


// ****************************************************************************
// Interrupt triggered by the negative edge of the servo pulse
void exint0() __interrupt (0)
{
    // Only store new data if the last one was taken out already and
    // Timer0 was not overflowing.
    if (!new_data && !TF0) {
        new_data = 1;
        raw_data = (TH0 << 8) | TL0;
    }

    TH0 = TL0 = 0;
    TF0 = 0;
}