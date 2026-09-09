TARGET = bai2

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CFLAGS = -mcpu=cortex-m3 -mthumb \
         -O2 \
         -Wall \
         -ffreestanding \
         -fno-builtin

LDFLAGS = -Tstm32f103.ld \
          -nostdlib \
          -Wl,--gc-sections

SRC = src/main.c startup/startup.s

all: $(TARGET).elf $(TARGET).bin $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) -o $@
	$(SIZE) $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

clean:
	rm -f $(TARGET).elf $(TARGET).bin $(TARGET).hex

.PHONY: all clean
