# vim: set noexpandtab ts=4 sw=4 sts=4

# pull in module dependencies
include $(addsuffix /module.mk, $(MODULE_DEPS))

# move everything to the build directory
C_SOURCES	 := $(filter %.c,$(SOURCES))
CXX_SOURCES  := $(filter %.cpp,$(SOURCES))
C_OBJECTS    := $(addprefix $(BUILDDIR)/$(ARCH)/, $(subst .c,.o,$(C_SOURCES)))
CXX_OBJECTS  := $(addprefix $(BUILDDIR)/$(ARCH)/, $(subst .cpp,.o,$(CXX_SOURCES)))
OUTPUT	 	 := $(addprefix $(BUILDDIR)/, $(OUTPUT))

# The variables in front of the targets allow each project file to define and use the immediate
# values before clear.mk clears them all out again
$(OUTPUT): LD := $(LD)
$(OUTPUT): LDFLAGS := $(LDFLAGS)
$(OUTPUT): LDPATH := $(LDPATH)
$(OUTPUT): LDSCRIPT := $(LDSCRIPT)
$(OUTPUT): $(C_OBJECTS) $(CXX_OBJECTS)
	$(ECHO) echo "[$(LD)] linking $@"
	$(ECHO) $(LD) $(LDPATH) $(LDFLAGS) $(LDSCRIPT) $^ -o $@

$(BUILDDIR)/$(ARCH)/%.o: DEFINES := $(DEFINES)
$(BUILDDIR)/$(ARCH)/%.o: CFLAGS := $(CFLAGS)
$(BUILDDIR)/$(ARCH)/%.o: INCLUDES := $(INCLUDES)
$(BUILDDIR)/$(ARCH)/%.o: CC := $(CC)
$(BUILDDIR)/$(ARCH)/%.o: %.c
	@$(MKDIR)
	$(ECHO) echo "[$(CC)] compiling $<"
	$(ECHO) $(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -MD $< -c -o $@

$(BUILDDIR)/$(ARCH)/%.o: DEFINES := $(DEFINES)
$(BUILDDIR)/$(ARCH)/%.o: CXXFLAGS := $(CXXFLAGS)
$(BUILDDIR)/$(ARCH)/%.o: INCLUDES := $(INCLUDES)
$(BUILDDIR)/$(ARCH)/%.o: CXX := $(CXX)
$(BUILDDIR)/$(ARCH)/%.o: %.cpp
	@$(MKDIR)
	$(ECHO) echo "[$(CXX)] compiling $<"
	$(ECHO) $(CXX) $(DEFINES) $(CXXFLAGS) $(INCLUDES) -MD $< -c -o $@

$(OUTPUT).bin: OBJCOPY := $(OBJCOPY)
$(OUTPUT).bin: $(OUTPUT)
	$(ECHO) echo "generating $@"
	$(ECHO) $(OBJCOPY) -O binary $< $@

$(OUTPUT).sym: NM := $(NM)
$(OUTPUT).sym: $(OUTPUT) 
	$(ECHO) echo "generating $@"
	$(ECHO) $(NM) $< > $@

$(OUTPUT).lst: OBJDUMP := $(OBJDUMP)
$(OUTPUT).lst: $(OUTPUT)
	$(ECHO) echo "generating $@"
	$(ECHO) $(OBJDUMP) -S $< > $@

$(OUTPUT).size: SIZE := $(SIZE)
$(OUTPUT).size: $(OUTPUT)
	$(ECHO) echo "generating $@"
	$(ECHO) $(SIZE) $^ >> $@

# .d files are generated via the -MD passed to gcc/clang in the c/cpp rules
-include $(C_OBJECTS:.o=.d)
-include $(CXX_OBJECTS:.o=.d)
