#include <stdint.h>
#include <stdbool.h>

#include "stc15x10x.h"

#include "globals.h"


#define ENABLE_IAP 0x80             // for SYSCLK<30MHz
#define EEPROM_CMD_IDLE 0
#define EEPROM_CMD_READ 1
#define EEPROM_CMD_PROGRAM 2
#define EEPROM_CMD_ERASE 3

#define EEPROM_ADDRESS_ESC_MODE 0x000
#define EEPROM_ADDRESS_TH_REVERSED 0x001

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
    esc_mode = EEPROM_ReadByte(EEPROM_ADDRESS_ESC_MODE);
    if (esc_mode >= ESC_MODE_COUNT) {
        esc_mode = 0;
    }

    channel[TH].reversed = EEPROM_ReadByte(EEPROM_ADDRESS_TH_REVERSED);
    if (channel[TH].reversed > 1) {
        channel[TH].reversed = 0;
    }
}


// ****************************************************************************
void write_persistent_storage(void)
{
    EEPROM_EraseSector(EEPROM_ADDRESS_ESC_MODE);
    EEPROM_ProgramByte(EEPROM_ADDRESS_ESC_MODE, esc_mode);
    EEPROM_ProgramByte(EEPROM_ADDRESS_TH_REVERSED, channel[TH].reversed);
}
