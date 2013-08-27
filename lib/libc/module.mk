PWD		 := $(GET_PARENT)

INCLUDES += \
	-I $(PWD)/include

SOURCES += \
	$(PWD)/ctype.c  \
	$(PWD)/stdio.c	\
	$(PWD)/stdlib.c \
	$(PWD)/string.c \

#CFLAGS := -std=c99 -I $(DIR)/include
#CFLAGS += -dynamiclib -ffreestanding -nostdlib -undefined suppress -flat_namespace
