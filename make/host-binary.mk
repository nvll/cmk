# vim: set noexpandtab ts=4 sw=4 sts=4
ARCH	 := $(shell uname -m)

include make/compile.mk

ALL += $(OUTPUT)

include make/clear.mk
