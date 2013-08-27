# vim: set noexpandtab ts=4 sw=4 sts=4
MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
GET_PARENT = $(patsubst %/, %, $(dir $(lastword $(MAKEFILE_LIST))))
BUILDDIR 	:= build
ECHO 		:= @
ALL			:=
