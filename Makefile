# vim: set noexpandtab ts=4 sw=4 sts=4

include make/clear.mk
include make/defines.mk
ALL := 

# If clean is specified then short circuit everything
ifeq ($(MAKECMDGOALS),clean)
clean:
	rm -rf $(BUILDDIR)
else

# Every project listed on the command line should match a corresponding .mk
# file under projects/. By including them their deps and such will be setup
# and then $(ALL) receives all the targets
ifneq ($(MAKECMDGOALS),)
include $(addprefix projects/, $(addsuffix .mk, $(MAKECMDGOALS)))
endif
		
$(MAKECMDGOALS) all: $(ALL)
endif

.PHONY: all clean
