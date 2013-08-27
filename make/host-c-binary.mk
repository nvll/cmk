CC       := clang
CFLAGS   := -std=c99 -O0 -Wall -W -Wno-unused-parameter
LD		 := clang

include make/host-binary.mk

# vim: set noexpandtab ts=4 sw=4 sts=4
