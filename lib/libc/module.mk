PWD		 := $(GET_PARENT)

INCLUDES += -I $(PWD)/include

OBJECTSS += \
	$(LOCAL_DIR)/stdio.c	\
	$(LOCAL_DIR)/string.c 	\
	$(LOCAL_DIR)/ctype.c	

LOCAL_CC := gcc
LOCAL_CFLAGS := -std=c99 -I $(LOCAL_DIR)/include
LOCAL_LIB_CFLAGS += -dynamiclib -ffreestanding -nostdlib -undefined suppress -flat_namespace
LOCAL_LIB_SRCS :=	$(LOCAL_DIR)/stdio.c \
					$(LOCAL_DIR)/string.c \
					$(LOCAL_DIR)/ctype.c
LOCAL_TEST_SRCS := $(LOCAL_DIR)/test.c
LOCAL_OUT := libc.dylib

CLEAN_OBJS += $(LOCAL_OUT) libc_test

libc:
	$(LOCAL_CC) $(LOCAL_CFLAGS) $(LOCAL_LIB_CFLAGS) $(LOCAL_LIB_SRCS) -o $(LOCAL_OUT)
	$(LOCAL_CC) $(LOCAL_CFLAGS) $(LOCAL_TEST_SRCS) -o libc_test
