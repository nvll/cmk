# vim: set noexpandtab ts=4 sw=4 sts=4
MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
GET_PARENT = $(patsubst %/, %, $(dir $(lastword $(MAKEFILE_LIST))))

TOOLCHAIN	:= arm-eabi-
CC 			:= $(TOOLCHAIN)gcc
LD 			:= $(TOOLCHAIN)ld
NM 			:= $(TOOLCHAIN)nm
SIZE 		:= $(TOOLCHAIN)size
OBJDUMP 	:= $(TOOLCHAIN)objdump
OBJCOPY 	:= $(TOOLCHAIN)objcopy

BUILDDIR 	:= build
TARGET		:= output
OUTPUT 		:= $(BUILDDIR)/$(TARGET)
CFLAGS 		:= -std=c99 -mcpu=cortex-m3 -g -mthumb -Os -Wall -W
CFLAGS 		+= -ffreestanding -nostartfiles -nostdlib -fno-builtin
CFLAGS		+= -fdata-sections -ffunction-sections -Wno-unused-parameter

LDFLAGS 	:= -gc-sections
LDPATH		:= 
LDSCRIPT 	:=
ECHO 		:= @
OBJS 		:=
DEFINES 	:=
INCLUDES 	:=
SOURCES		:=

all: buildall

include lib/*/module.mk
include src/module.mk

OBJECTS := $(addprefix $(BUILDDIR)/, $(subst .c,.o,$(SOURCES)))

buildall: $(OBJECTS)
	$(ECHO) $(SIZE) -t $(OBJECTS)
	$(ECHO) echo "linking $(OUTPUT).elf"
	$(ECHO) $(LD) $(LDPATH) $(LDFLAGS) $(LDSCRIPT) $^ -o $(OUTPUT).elf
	$(ECHO) $(OBJDUMP) -S $(OUTPUT).elf > $(OUTPUT).lst
	$(ECHO) $(NM) -Sn $(OUTPUT).elf > $(OUTPUT).sym
	$(ECHO) $(SIZE) $(OUTPUT).elf
	$(ECHO) $(OBJCOPY) -O binary $(OUTPUT).elf $(OUTPUT).bin

$(BUILDDIR)/%.o: %.c
	@$(MKDIR)
	$(ECHO) echo "compiling $<"
	$(ECHO) $(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $< -c -o $@
	$(ECHO) $(OBJDUMP) -Mreg-names-raw -S $@ > $@.lst
	$(ECHO) $(NM) -Sn $@ > $@.sym


clean:
	rm -rf $(BUILDDIR)

.PHONY: all buildall
