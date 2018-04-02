.DEFAULT_GOAL := all

BUILD_DIR := ./build

###############################################################################
# Pretty-print setup
VERBOSE ?= $V
ifeq ("$(VERBOSE)", "1")
ECHO :=
else
ECHO := @
endif

###############################################################################
CPU_FREQUENCY_KHZ := 12000

# Note: main.c must the the first file in the list! SDCC requirement.
SOURCES := main.c
SOURCES += drive_mode.c
SOURCES += lights.c
SOURCES += persistent_storage.c
SOURCES += random.c
SOURCES += servo_reader.c
SOURCES += setup.c

CFLAGS := -mmcs51
CFLAGS += --std-c99

LDFLAGS := -mmcs51
LDFLAGS += --iram-size 128
LDFLAGS += --code-size 0x1000
LDFLAGS += --out-fmt-ihx

DEPENDENCIES := Makefile
DEPENDENCIES += globals.h

###############################################################################
# TARGET and object file setup
OBJECTS = $(addprefix $(BUILD_DIR)/, $(notdir %/$(subst .c,.rel, $(SOURCES))))
TARGET := $(BUILD_DIR)/rc-brake-lights.ihx

all: $(TARGET)

$(OBJECTS): $(DEPENDENCIES) $(SOURCES)

$(BUILD_DIR):
	@echo [MKDIR] $@
	$(ECHO) mkdir -p $@

%.rel:
	@echo [CC] $@
	$(ECHO) sdcc $(CFLAGS) -c -o $@ $(filter %/$(subst .rel,.c,$(@F)), $(addprefix ./,$(SOURCES)))

$(TARGET): $(BUILD_DIR) $(OBJECTS)
	@echo [LD] $@
	$(ECHO) sdcc $(LDFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	@echo [RM] $(BUILD_DIR)
	$(ECHO) $(RM) -r $(BUILD_DIR)

flash: $(TARGET)
	@echo [FLASH] $<
	$(ECHO) stcgal -t $(CPU_FREQUENCY_KHZ) -b 1200 $<

program: flash

.PHONY : all clean flash program
