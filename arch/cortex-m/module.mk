# vim: set noexpandtab ts=4 sw=4
PWD			:= $(GET_PARENT)

INCLUDES 	+= -I $(PWD)
LDFLAGS 	+= -T $(LDSCRIPT) 
DEFINES 	+= -D CORTEX_M4 -D CM_STACKSIZE=2048		\

LDSCRIPT 	+= $(PWD)/cortex-m.ld
LDPATH		+= -L $(PWD)

MODULE_DEPS += \
	lib/libc

SOURCES		+=			\
	$(PWD)/cortex-m.c		\
