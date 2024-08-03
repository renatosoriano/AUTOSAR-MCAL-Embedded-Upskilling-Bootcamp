#Select a toolchain from the list: replace_toolchain_list
TOOLCHAIN = gcc

#The path to the GCC installation dir
GCC_DIR = C:/NXP/gcc-10.2-arm32-eabi

#The path to the DIAB installation dir
DIAB_DIR = replace_diab_dir

#The path to the EB Tresos installation dir
TRESOS_DIR = C:/EB/tresos

#The path to the T32 installation dir
#T32_DIR = replace_t32_dir

#The path to the VDK installation dir
VDK_DIR = 
VDK_TEMPLATE_NAME = replace_vdk_template_name
VDK_TEMPLATE_VERSION = replace_vdk_template_version
VDK_VPCONFIG_NAME = replace_vdk_vpconfig_name

#The path to the Tresos plugins directory
PLUGINS_DIR = C:/NXP/SW32K1_S32M24x_RTD_R21-11_2.0.0_P04/eclipse/plugins

#The path to the Tresos add-on plugins directory
PLUGINS_DIR_ADDON = C:/EB/tresos/plugins

#The paths to the additional directories to be included at build phase
ADDITIONAL_INCLUDE_DIRS = C:/NXP/SW32K1_S32M24x_RTD_R21-11_2.0.0_P04/eclipse/plugins/Platform_TS_T40D2M20I0R0/include

#Loading project to ram or flash
LOAD_TO=

# ------------------------------------------------------------------------------------
#Example specific parameters - do not modify 

#MCAL modules used
MCAL_MODULE_LIST := BaseNXP Det Platform Mcl Rte

#MCAL modules used - only for examples based on 2 software products
MCAL_MODULE_LIST_ADDON := 

#The package name for the MCAL release
AR_PKG_NAME = TS_T40D2M20I0R0

#The AUTOSAR module origin ('NXP')
AR_MODULE_ORIGIN = NXP

#The package name for the MCAL release - only for examples based on 2 software products
AR_PKG_NAME_ADDON = 

#The derivative of the device
EXAMPLE_DERIVATIVE = S32K144

#The core type of the device
EXAMPLE_CORE_TYPE = M4F

#The name of the elf file
ELFNAME = main

#The test base address 
TEST_BASE_ADDR = 0x1FFF8000

# The test block size
TEST_BLOCK_SIZE = 255

#The name of the Tresos project 
TRESOS_PROJECT_NAME = Platform_Mpu_Example_S32K144

#The number of variants for the Tresos project 
VARIANT_NO = 0

#Connection type of lauterbach
PBI = replace_pbi

RUN_SECOND_SAMPLEAPP_ENABLE = 
SECOND_SAMPLEAPP_DIR = 

