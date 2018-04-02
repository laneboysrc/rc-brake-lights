#include <stdint.h>
#include <stdbool.h>

#define __SYSTICK_IN_MS 20

#define TH 0

extern void load_persistent_storage(void);
extern void write_persistent_storage(void);

extern void process_setup(void);

extern void init_lights(void);
extern void process_lights(void);

extern void process_drive_mode(void);

extern void init_servo_reader(void);
extern void read_all_servo_channels(void);

extern uint16_t random_min_max(uint16_t min, uint16_t max);


// ****************************************************************************
typedef struct {
    uint16_t left;
    uint16_t centre;
    uint16_t right;
} SERVO_ENDPOINTS_T;

// ****************************************************************************
typedef struct {
    uint32_t raw_data;
    SERVO_ENDPOINTS_T endpoint;
    int16_t normalized;
    uint16_t absolute;
    uint8_t reversed;
} CHANNEL_T;

// ****************************************************************************
typedef struct {
    unsigned int systick : 1;               // Set for one mainloop every __SYSTICK_IN_MS
    unsigned int new_channel_data : 1;      // Set for one mainloop every time servo pulses were received

    unsigned int initializing : 1;

    unsigned int forward : 1;               // Set when the car is driving forward
    unsigned int braking : 1;               // Set when the brakes are enganged
    unsigned int reversing : 1;             // Set when the car is reversing

    unsigned int setup : 2;                 // Set when performing throttle reversing and ESC mode selection
} GLOBAL_FLAGS_T;

// ****************************************************************************
// ESC_FORWARD_BRAKE_REVERSE
// The user has to go for brake, then neutral, before reverse engages.
// Example: Tamiya ESCs
//
// ESC_FORWARD_BRAKE_REVERSE_TIMEOUT
// Reverse can be engaged if the user stays in neutral for a few seconds.
// Example: The China 320A ESC, HPI SC-15WP
//
// ESC_FORWARD_REVERSE
// Crawler ESC with drag brake, where the ESC switches from forward directly
// into reverse.
//
// ESC_FORWARD_BRAKE
// ESC in race mode where reversing is not allowed.
typedef enum {
    ESC_FORWARD_BRAKE_REVERSE_TIMEOUT,
    ESC_FORWARD_BRAKE_REVERSE,
    ESC_FORWARD_REVERSE,
    ESC_FORWARD_BRAKE,

    ESC_MODE_COUNT
} ESC_MODE_T;

// ****************************************************************************
typedef enum {
    SETUP_OFF = 0,
    SETUP_THROTTLE_REVERSING = 0x01,
    SETUP_ESC_MODE = 0x02
} SETUP_T;

// ****************************************************************************
extern CHANNEL_T channel[1];
extern GLOBAL_FLAGS_T global_flags;
extern ESC_MODE_T esc_mode;

// ****************************************************************************
// The entropy variable is incremented every mainloop. It can therefore serve
// as a random value in practical RC car application,
// Certainly not suitable for secure implementations...
extern uint32_t entropy;

