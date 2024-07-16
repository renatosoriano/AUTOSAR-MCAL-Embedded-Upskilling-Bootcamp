#Nombre del proyecto
TARGET = temp
#Application user files to compile
SRCS  = main.c
#Mcal Modules to use
MCAL_SRCS = Platform Base Rte Mcu Port Dio
#BSW Modules to use
BSW_SRCS = EcuM Rte Det
#BSW Modules to use
RTT_SRCS = SEGGER_RTT.c SEGGER_RTT_printf.c
#archivo linker a usar
LINKER = Autosar/Mcal/Platform/build_files/gcc/linker_flash_s32k144.ld
#Simbolos gloobales del programa (#defines globales)
SYMBOLS  = -DS32K1XX -DS32K144 -DGCC -DEU_DISABLE_ANSILIB_CALLS -DUSE_SW_VECTOR_MODE
SYMBOLS += -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DVV_RESULT_ADDRESS=0x1FFF8000
SYMBOLS += -DI_CACHE_ENABLE -DENABLE_FPU

#directorios con archivos a compilar (.c y .s)
SRC_PATHS  = $(foreach Module, $(MCAL_SRCS), Autosar/Mcal/$(Module)/src)
SRC_PATHS += $(foreach Module, $(BSW_SRCS), Autosar/$(Module)/src)
SRC_PATHS += Autosar/Mcal/Platform/startup/src
SRC_PATHS += Autosar/Mcal/Platform/startup/src/m4
SRC_PATHS += Autosar/Mcal/Platform/startup/src/m4/gcc
SRC_PATHS += Build/cfg/src
SRC_PATHS += Rtt/SEGGER

#direcotrios con archivos .h
INC_PATHS  = $(foreach Module, $(MCAL_SRCS), Autosar/Mcal/$(Module)/include)
INC_PATHS += $(foreach Module, $(BSW_SRCS), Autosar/$(Module)/include)
INC_PATHS += Autosar/Mcal/Base/header
INC_PATHS += Autosar/Mcal/Platform/startup/include
INC_PATHS += Build/cfg/include
INC_PATHS += Rtt/SEGGER
INC_PATHS += Rtt/Config

TOOLCHAIN = /c/NXP/gcc-10.2-arm32-eabi/bin/arm-none-eabi
CLIB = "/c/NXP/gcc-10.2-arm32-eabi/arm-none-eabi/newlib"
CPU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 

#opciones de compilacion
CFLAGS  = $(CPU) -mlittle-endian
CFLAGS += --sysroot=$(CLIB)
CFLAGS += -O0                       # Compile with Size Optimizations (O0, O1, O2, O3, Os)
CFLAGS += -ggdb3                    # Debugging information level (g1, g2, g3)
CFLAGS += -std=c99                  # Comply with C11
CFLAGS += -Wall                     # Be anal Enable All Warnings
CFLAGS += -Wextra                   # Be extra anal Enable Extra Warnings
CFLAGS += -pedantic                 # Be extra anal More ANSI Checks
CFLAGS += -Wstrict-prototypes       # Warn if a function is declared or defined without specifying the argument types
CFLAGS += -Wundef 					# Warn if an undefined identifier is evaluated in an #if directive.
CFLAGS += -Wunused 					# Warn whenever a function, variable, label, value, macro is unused
CFLAGS += -Wsign-compare 			# Warn when a comparison between signed and unsigned values could produce an incorrect result when the signed value is converted to unsigned.
CFLAGS += -Wdouble-promotion 		# Warn if float is implicit promoted to double
CFLAGS += -fno-short-enums 			# Do not allocate to an enum type only as many bytes as it needs for the declared range of possible values.
CFLAGS += -ffunction-sections       # Create a separate function section
CFLAGS += -fdata-sections           # Create a separate data section
CFLAGS += -fno-builtin              # Don't recognize built-in functions that do not begin with ‘__builtin_’ as prefix
CFLAGS += -funsigned-char           # char is treated as unsigned by default
CFLAGS += -funsigned-bitfields 		# Bitfields are always unsigned
CFLAGS += -fno-common 				# In C code, controls the placement of uninitialized global variables. It is generally more efficient to use -fno-common to keep uninitialized global variables out of the data section.
CFLAGS += -fstack-usage 			# Emits stack usage information for the program, on a per-function basis, when compiling with -g or -gline-tables-only. The option -fstack-usage is enabled by default.
CFLAGS += -fdump-ipa-all 			# Dump all interprocedural optimization passes and their results.
CFLAGS += -fdiagnostics-color=always # color the output
CFLAGS += -fomit-frame-pointer      # Don't keep the frame pointer in a register for functions that don't need one
CFLAGS += -fverbose-asm             # Put extra commentary information in the generated assembly code
CFLAGS += -specs=nano.specs 		# nano version of stdlib
CFLAGS += -specs=nosys.specs 		# no syscalls
CFLAGS += -MT"$(@)" -MMD -MP -MF"Build/obj/$(*).d"

#opciones de ensamblador
AFLAGS  = $(CPU) 
AFLAGS += -x assembler-with-cpp

#opciones de linker
LFLAGS  = $(CPU) -mlittle-endian
LFLAGS += --sysroot=$(CLIB) 
LFLAGS += -Wl,--gc-sections				# Remove unused sections
LFLAGS += --entry=Reset_Handler 		# entry point
LFLAGS += -nostartfiles 				# do not use the standard system startup files when linking
LFLAGS += -ggdb3 						# produce debugging information for use by GDB
LFLAGS += -lc 							# Use the C library
LFLAGS += -lm 							# Use the math library
LFLAGS += -lgcc 						# Use the gcc library
LFLAGS += -n 							# Turn off page alignment of sections, and disable linking against shared libraries
LFLAGS += -specs=nano.specs 			# nano version of stdlib
LFLAGS += -specs=nosys.specs 			# no syscalls
LFLAGS += -Wl,-Map=Build/$(TARGET).map	# Generate map file 


# Get the Mcal files to compile according to the modules selected 
SRCS += $(foreach Dir, $(SRC_PATHS), $(notdir $(wildcard $(Dir)/*.c))) 
SRCS += $(foreach Dir, $(SRC_PATHS), $(notdir $(wildcard $(Dir)/*.s)))

#substituccion de prefijos y postfijos
OBJS = $(SRCS:%.c=Build/obj/%.o)
OBJS := $(OBJS:%.s=Build/obj/%.o)
DEPS = $(OBJS:%.o=%.d)

VPATH = $(SRC_PATHS)
INCLS = $(addprefix -I ,$(INC_PATHS))

#---Instrucciones de compilacion
all : build $(TARGET)

$(TARGET) : $(addprefix Build/, $(TARGET).elf)
	$(TOOLCHAIN)-objcopy -Oihex $< Build/$(TARGET).hex
	$(TOOLCHAIN)-objdump -S $< > Build/$(TARGET).lst
	$(TOOLCHAIN)-size --format=berkeley $<

Build/$(TARGET).elf : $(OBJS)
	$(TOOLCHAIN)-gcc $(LFLAGS) -T $(LINKER) -o $@ $^

Build/obj/%.o : %.c
	$(TOOLCHAIN)-gcc $(CFLAGS) $(INCLS) $(SYMBOLS) -o $@ -c $<

Build/obj/%.o : %.s
	$(TOOLCHAIN)-gcc $(AFLAGS) $(SYMBOLS) -o $@ -c $<

-include $(DEPS)

#---Create the build directories
.PHONY : build
build :
	mkdir -p Build/obj

#---Remove the compilation build files
.PHONY : clean
clean :
	rm -rf Build


