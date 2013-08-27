# vim: set noexpandtab ts=4 sw=4 sts=4
TOOLCHAIN  := arm-eabi-
CC 		 := $(TOOLCHAIN)gcc
LD 		 := $(TOOLCHAIN)ld
NM 		 := $(TOOLCHAIN)nm
SIZE 	 := $(TOOLCHAIN)size
OBJDUMP  := $(TOOLCHAIN)objdump
OBJCOPY  := $(TOOLCHAIN)objcopy
CFLAGS 	 := -std=c99 -g -Os -Wall -W -mcpu=cortex-m3 -mthumb 
CFLAGS 	 += -ffreestanding -nostdlib -fno-builtin
CFLAGS	 += -fdata-sections -ffunction-sections -Wno-unused-parameter
LDFLAGS  := -gc-sections
LDPATH	 := 
LDSCRIPT :=
DEFINES  :=
INCLUDES :=
SOURCES	 :=
ARCH	 := arm-m

include make/compile.mk

ALL += $(OUTPUT) $(OUTPUT).bin $(OUTPUT).sym $(OUTPUT).lst $(OUTPUT).size

include make/clear.mk
