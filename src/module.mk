# vim: set noexpandtab ts=4 sw=4
PWD			:= $(GET_PARENT)

INCLUDES 	+= -I $(PWD)
LDFLAGS 	+= -T $(LDSCRIPT) 
DEFINES 	+= -D CM_STACKSIZE=2048		\
			   -D CORTEX_M4=1			\

LDSCRIPT 	+= $(PWD)/cortex-m.ld
LDPATH		+= -L $(PWD)

SOURCES		+=				\
	$(PWD)/cortex-m.c		\
	$(PWD)/main.c			\
