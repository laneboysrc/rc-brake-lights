/******************************************************************************

    Setup mode takes care of the light controller configuration.
    The following items can be configured:

    * Throttle channel reversing
    * ESC mode

    To enter setting mode the user has to hold down the button for 3 seconds.

    After 3 seconds throttle channel reversing is entered. All LEDs flash.
    The user shall now push the throttle forward. Once the light controller
    observes a throttle signal of >50% it uses the signal polarity to set
    the reversing flag accordingly, and exits setup mode.

    When the user presses the button while in throttle channel reversing mode,
    the ESC selection mode is entered. The light controller flashes the current
    ESC mode number, e.g. 1 flash for ESC_FORWARD_BRAKE_REVERSE_TIMEOUT
    The user can press the button briefly to change to the next ESC mode.
    When the desired ESC mode is reached, the user can hold the button for
    3 seconds to store the ESC mode.

******************************************************************************/
#include <stdint.h>

#include "stc15x10x.h"

#include "globals.h"


#define SWITCH P35
#define PRESSED 0           // The push-button is active low

#define SWITCH_HOLD_TIME (3000 / __SYSTICK_IN_MS)
#define THROTTLE_THRESHOLD 50

static enum {
    SETUP_STATE_IDLE = 0,
    SETUP_STATE_ENTER_WAIT,
    SETUP_STATE_THROTTLE_WAIT_RELEASE,
    SETUP_STATE_THROTTLE,
    SETUP_STATE_ESC_WAIT_RELEASE,
    SETUP_STATE_ESC,
    SETUP_STATE_EXIT_WAIT
} setup_state;

static uint8_t setup_counter;


// ****************************************************************************
void process_setup(void)
{
    // Only process the switch every __SYSTICK_IN_MS
    if (!global_flags.systick) {
        return;
    }

    switch (setup_state) {
        case SETUP_STATE_IDLE:
            if (SWITCH == PRESSED) {
                setup_state = SETUP_STATE_ENTER_WAIT;
                setup_counter = SWITCH_HOLD_TIME;
            }
            break;

        case SETUP_STATE_ENTER_WAIT:
            if (SWITCH != PRESSED) {
                setup_state = SETUP_STATE_IDLE;
                break;
            }

            --setup_counter;
            if (setup_counter == 0) {
                setup_state = SETUP_STATE_THROTTLE_WAIT_RELEASE;
                global_flags.setup = SETUP_THROTTLE_REVERSING;
            }
            break;

        case SETUP_STATE_THROTTLE_WAIT_RELEASE:
            if (SWITCH != PRESSED) {
                setup_state = SETUP_STATE_THROTTLE;
            }
            break;

        case SETUP_STATE_THROTTLE:
            if (SWITCH == PRESSED) {
                setup_state = SETUP_STATE_ESC_WAIT_RELEASE;
                global_flags.setup = SETUP_ESC_MODE;
            }

            if (channel[TH].absolute > THROTTLE_THRESHOLD) {
                // The user is expected to have pushed the throttle in "forward"
                // direction. So if we read a negative throttle value we must
                // reverse the direction.
                if (channel[TH].normalized < 0) {
                    channel[TH].reversed = channel[TH].reversed ? 0 : 1;
                    write_persistent_storage();
                }
                global_flags.setup = SETUP_OFF;
                setup_state = SETUP_STATE_IDLE;
            }
            break;

        case SETUP_STATE_ESC_WAIT_RELEASE:
            if (SWITCH != PRESSED) {
                setup_state = SETUP_STATE_ESC;
            }
            break;

        case SETUP_STATE_ESC:
            if (SWITCH == PRESSED) {
                setup_state = SETUP_STATE_EXIT_WAIT;
                setup_counter = SWITCH_HOLD_TIME;
            }
            break;

        case SETUP_STATE_EXIT_WAIT:
            // If the switch is pressed for less than 3 seconds then cycle to
            // to the next ESC mode.
            if (SWITCH != PRESSED) {
                ++esc_mode;
                if (esc_mode == ESC_MODE_COUNT) {
                    esc_mode = 0;
                }
                setup_state = SETUP_STATE_ESC;
                break;
            }

            --setup_counter;
            if (setup_counter == 0) {
                global_flags.setup = SETUP_OFF;
                setup_state = SETUP_STATE_IDLE;
                write_persistent_storage();
            }
            break;

        default:
            setup_state = SETUP_STATE_IDLE;
            break;
    }
}
