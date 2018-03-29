#include <stdint.h>

extern void load_persistent_storage(void);
extern void write_persistent_storage(void);

extern void reversing_setup_action(uint8_t ch3_clicks);
extern void process_channel_reversing_setup(void);

extern void init_lights(void);
extern void process_lights(void);

extern void process_drive_mode(void);

extern void init_servo_reader(void);
extern void read_all_servo_channels(void);
