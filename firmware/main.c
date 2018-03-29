#include "stdint.h"
#include "stdbool.h"

#include "stc15x10x.h"

#include "globals.h"


#define BRAKE_LED P31
#define REVERSIONG_LED P32
#define TH P33


//----------------------------------------------------------------------------
void main()
{
    init_lights();
    init_servo_reader();

    while (1) {
        if (TH) {
            REVERSIONG_LED = 1;
            BRAKE_LED = 1;
        }
        else {
            REVERSIONG_LED = 0;
            BRAKE_LED = 0;
        }

        read_all_servo_channels();
        process_channel_reversing_setup();
        process_drive_mode();
        process_lights();
    }
}

//----------------------------------------------------------------------------
void exint2() __interrupt (10)
{
}
