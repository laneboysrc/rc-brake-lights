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
CPU_FREQUENCY_KHZ := 35000

SOURCES := main.c
SOURCES += channel_reversing.c
SOURCES += servo_reader.c
SOURCES += persistent_storage.c
SOURCES += lights.c
SOURCES += drive_mode.c

CFLAGS := -mmcs51
CFLAGS += --std-c99
CFLAGS += --iram-size 128
CFLAGS += --code-size 0x1000

LDFLAGS := -mmcs51
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


.PHONY : all clean flash
