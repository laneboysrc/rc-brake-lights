#include <stdint.h>
#include <stdbool.h>

#include "stc15x10x.h"

#include "globals.h"


#define PERSISTENT_DATA_VERSION 1

#define ENABLE_IAP 0x80             // for SYSCLK<30MHz
#define EEPROM_CMD_IDLE 0
#define EEPROM_CMD_READ 1
#define EEPROM_CMD_PROGRAM 2
#define EEPROM_CMD_ERASE 3

//----------------------------------------------------------------------------
// EEPROM functions taken straight from the datasheet
static void EEPROM_Idle()
{
    IAP_CONTR = 0;
    IAP_CMD = 0;
    IAP_TRIG = 0;
    IAP_ADDRH = 0x80;
    IAP_ADDRL = 0;
}

static uint8_t EEPROM_ReadByte(uint16_t addr)
{
    uint8_t data;

    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = EEPROM_CMD_READ;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
    IAP_TRIG = 0x5a;
    IAP_TRIG = 0xa5;
    NOP();
    data = IAP_DATA;
    EEPROM_Idle();
    return data;
}

static void EEPROM_ProgramByte(uint16_t addr, uint8_t data)
{
    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = EEPROM_CMD_PROGRAM;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
    IAP_DATA = data;
    IAP_TRIG = 0x5a;
    IAP_TRIG = 0xa5;
    NOP();
    EEPROM_Idle();
}

static void EEPROM_EraseSector(uint16_t addr)
{
    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = EEPROM_CMD_ERASE;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
    IAP_TRIG = 0x5a;
    IAP_TRIG = 0xa5;
    NOP();
    EEPROM_Idle();
}

// ****************************************************************************
void load_persistent_storage(void)
{
    // uint32_t defaults[6];
    // const volatile uint32_t *ptr;
    // const volatile uint32_t *persistent_data = HAL_persistent_storage_read();

    // defaults[OFFSET_VERSION] = PERSISTENT_DATA_VERSION;
    // defaults[OFFSET_STEERING_REVERSED] = false;
    // defaults[OFFSET_THROTTLE_REVERSED] = false;
    // defaults[OFFSET_SERVO_LEFT] = 1000;
    // defaults[OFFSET_SERVO_CENTRE] = 1500;
    // defaults[OFFSET_SERVO_RIGHT] = 2000;

    // if (defaults[0] != persistent_data[0]) {
    //     ptr = defaults;
    // }
    // else {
    //     ptr = persistent_data;
    // }

    // channel[ST].reversed = ptr[OFFSET_STEERING_REVERSED];
    // channel[TH].reversed = ptr[OFFSET_THROTTLE_REVERSED];
    // servo_output_endpoint.left = ptr[OFFSET_SERVO_LEFT];
    // servo_output_endpoint.centre = ptr[OFFSET_SERVO_CENTRE];
    // servo_output_endpoint.right = ptr[OFFSET_SERVO_RIGHT];
}


// ****************************************************************************
void write_persistent_storage(void)
{
    // uint32_t new_data[6];
    // const char *error_message;

    // new_data[OFFSET_VERSION] = PERSISTENT_DATA_VERSION;
    // new_data[OFFSET_STEERING_REVERSED] = channel[ST].reversed;
    // new_data[OFFSET_THROTTLE_REVERSED] = channel[TH].reversed;
    // new_data[OFFSET_SERVO_LEFT] = servo_output_endpoint.left;
    // new_data[OFFSET_SERVO_CENTRE] = servo_output_endpoint.centre;
    // new_data[OFFSET_SERVO_RIGHT] = servo_output_endpoint.right;

    // error_message = HAL_persistent_storage_write(new_data);

    // if (error_message) {
    //     fprintf(STDOUT_DEBUG, error_message);
    //     fprintf(STDOUT_DEBUG, "\n");
    // }
}
