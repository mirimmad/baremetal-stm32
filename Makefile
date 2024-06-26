TARGET = main

LD_SCRIPT = linker.ld
MCU_SPEC = cortex-m4

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump
OS = arm-none-eabi-size

CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -mthumb
CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -fmessage-length=0
CFLAGS += --specs=nosys.specs
CFLAGS += -ICMSIS/
CFLAGS += -Idrivers/
CFLAGS += -Idrivers/clk
CFLAGS += -Idrivers/gpio
CFLAGS += -Idrivers/NVIC
CFLAGS += -Idrivers/core

LSCRIPT = ./$(LD_SCRIPT)
LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -lgcc
LFLAGS += -T$(LSCRIPT)

SRC = $(shell find ./ -type f -name '*.c' ! -path "./demos/*")
BUILDDIR = build
OBJS = $(patsubst ./%.c, $(BUILDDIR)/%.o, $(SRC))

.PHONY: all
all: $(TARGET).bin

.PHONY: %.o
$(BUILDDIR)/%.o : %.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@
.PHONY: %.o
$(TARGET).elf: $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET).elf
	rm -f $(TARGET).bin

flash:
	st-flash write $(TARGET).bin 0x08000000


