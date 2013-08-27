OUTPUT := libc_test
DEFINES += -D WITH_HOST_LIBC
MODULE_DEPS := \
	lib/libc \
	app/libc_test

include make/host-cpp-binary.mk
