/******************************************************************************

    Simulates the state machine in the ESC and updates the variable drive_mode
    accordingly.

    +/-10: forward = 0, reverse = 0
    >+10: forward = 1, brake_armed = 1
    <-10:
      if brake_armed: brake = 1
      if not brake_armed: reverse = 1, brake = 0
    2 seconds in Neutral: brake_armed = 0
    Brake -> Neutral: brake = 0, brake_armed = 0
    Reverse -> Neutral: brake = 1 for 2 seconds

******************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "globals.h"

// ****************************************************************************
void process_drive_mode(void)
{

}


