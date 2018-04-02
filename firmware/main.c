#include "stdint.h"
#include "stdbool.h"

#include "stc15x10x.h"

#include "globals.h"

#define T2_RELOAD_VALUE ((uint16_t)(0xffff - (__SYSTICK_IN_MS * 1000) + 1))

GLOBAL_FLAGS_T global_flags;
uint32_t entropy;

static volatile bool tick_interrupt_fired;


// ****************************************************************************
static void service_systick(void)
{
    ++entropy;

    global_flags.systick = 0;
    if (tick_interrupt_fired) {
        tick_interrupt_fired = false;
        global_flags.systick = 1;
    }
}


// ----------------------------------------------------------------------------
static void init_softtimer(void)
{
    T2H = T2_RELOAD_VALUE >> 8;
    T2L = T2_RELOAD_VALUE & 0xff;
    AUXR |= 0x10;   // Start Timer2
    IE2 |= 0x04;    // Enable Timer2 interrupt
}


//----------------------------------------------------------------------------
void main()
{
    global_flags.initializing = true;

    init_softtimer();
    init_lights();
    init_servo_reader();
    load_persistent_storage();

    EA = 1;                 // Enable interrupts

    while (1) {
        service_systick();

        read_all_servo_channels();
        process_drive_mode();
        process_setup();
        process_lights();
    }
}


// ----------------------------------------------------------------------------
extern void exint0(void) __interrupt (0);

void timer2int(void) __interrupt (12)
{
    tick_interrupt_fired = 1;
}
