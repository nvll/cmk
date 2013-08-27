CC		  := clang
CFLAGS	  := -std=c99 -O0 -Wall -W -Wno-unused-parameter -Wno-c++11-extensions
CXX       := clang++
CXXFLAGS  := -std=c++11 -O0 -Wall -W -Wno-unused-parameter -Wno-c++11-extensions
LD		  := clang++

include make/host-binary.mk

# vim: set noexpandtab ts=4 sw=4 sts=4
