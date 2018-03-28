BUILD := ./build
TARGET := $(BUILD)/rc-brake-lights.ihx

CPU_FREQUENCY_KHZ := 35000

CFLAGS = -mmcs51
CFLAGS += --std-c99
CFLAGS += --iram-size 128
CFLAGS += --code-size 0x1000
CFLAGS += --out-fmt-ihx

$(TARGET): main.c
	mkdir -p $(BUILD)
	sdcc $(CFLAGS) -o $(TARGET) $^

clean:
	$(RM) -r $(BUILD)

flash: $(TARGET)
	stcgal -t $(CPU_FREQUENCY_KHZ) -b 1200 $<