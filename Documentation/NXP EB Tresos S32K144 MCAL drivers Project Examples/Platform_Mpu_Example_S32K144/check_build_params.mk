# this file checks that the build parameters were set correctly 

ifeq ($(TOOLCHAIN),gcc)
    ifeq ("$(wildcard $(GCC_DIR)/bin/arm-none-eabi-gcc.exe)","")
        $(error Invalid path set to the GCC compiler. \
        The provided path: from project_parameters.mk GCC_DIR=$(GCC_DIR) is invalid!)
    endif
else ifeq ($(TOOLCHAIN),diab)
    ifeq ("$(wildcard $(DIAB_DIR)/WIN64/bin/dcc.exe)","")
        $(error Invalid path set to the DIAB compiler. \
        The provided path: from project_parameters.mk DIAB_DIR=$(DIAB_DIR) is invalid!)
    endif
else
    $(error The toolchain $(TOOLCHAIN) configured in project_parameters.mk is not supported.)
endif

ifeq ("$(wildcard $(TRESOS_DIR)/bin/tresos_cmd.bat)","")
    $(error Invalid path set to EB Tresos. \
    The provided path: from project_parameters.mk TRESOS_DIR=$(TRESOS_DIR) is invalid!)
endif

#ifeq ("$(wildcard $(T32_DIR)/bin/windows/t32marm.exe)","")
#    $(error Invalid path set to Trace32. \
#    The provided path: from project_parameters.mk T32_DIR=$(T32_DIR) is invalid!)
#endif
