/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*
* GCC Linker Command File: This linker is demo and  is not part of the production code deliverables.
* 0x00000000    0x0007FFFF  512KB   Flash
* 0x1FFF8000    0x1FFFFFFF  32768  SRAM_L
* 0x20000000    0x20006FFF  28672  SRAM_U
*/


MEMORY
{
    int_flash_interrupts    : ORIGIN = 0x00000000, LENGTH = 0x00000400    /* 1K */    /* Do not change this section */
    int_flash_config        : ORIGIN = 0x00000400, LENGTH = 0x00000010    /* 16bytes */ /* Do not change this section */
    int_flash               : ORIGIN = 0x00000410, LENGTH = 0x0007FBF0    /* ~511KB */
    int_sram_results        : ORIGIN = 0x1FFF8000, LENGTH = 0x00000100    /* 256bytes */
    int_sram                : ORIGIN = 0x1FFF8100, LENGTH = 0x0000DF00    /* ~56K */
    int_sram_stack_c0       : ORIGIN = 0x20006000, LENGTH = 0x00001000    /* 4K  */
    ram_rsvd2               : ORIGIN = 0x20007000, LENGTH = 0             /* End of SRAM */
}


HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x00000200;

ENTRY(Reset_Handler)

SECTIONS
{

    .flash_interrupts :
    {
        . = ALIGN(2048);
        __interrupts_rom_start = .;
        KEEP(*(.intc_vector))
        . = ALIGN(4);
        __interrupts_rom_end = .;
    } > int_flash_interrupts

    .flash_config :
    {
        KEEP(*(.flash_config))
    } > int_flash_config

    .flash :
    {
        . = ALIGN(4);
        *(.startup)
        . = ALIGN(4);
        *(.systeminit)
        . = ALIGN(4);
        *(.text.startup)
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
        *(.mcal_text)
        . = ALIGN(4);
        acfls_code_rom_start = .;
        . = ALIGN(0x4);
        *(.acfls_code_rom)
        . = ALIGN(4);
        *(.acmem_43_INFLS_code_rom)
        . = ALIGN(4);
        acfls_code_rom_end = .;
        KEEP(*(.init))
        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        *(.mcal_const_cfg)
        . = ALIGN(4);
        *(.mcal_const)
        . = ALIGN(4);
        *(.mcal_const_no_cacheable)
        . = ALIGN(4);
        __init_table = .;
        KEEP(*(.init_table))
        . = ALIGN(4);
        __zero_table = .;
        KEEP(*(.zero_table))

        . = ALIGN(4);
        *(.acmcu_code_rom)
        . = ALIGN(4);
        _etext = .;
        __DATA_ROM = .;
    } > int_flash

    . = ALIGN(4);
    PROVIDE(__exidx_start = .);
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    }> int_sram
    . = ALIGN(4);
    PROVIDE(__exidx_end = .);

    .ARM.extab :
    {
        *(.ARM.extab*)
        . = ALIGN(4);
    } > int_sram

    .sram_interrupts :
    {
        . = ALIGN(2048);
        __interrupts_ram_start = .;
        . += (__interrupts_rom_end - __interrupts_rom_start);
        . = ALIGN(4);
        __interrupts_ram_end = .;
    } > int_sram

    .sram_data :  AT(__DATA_ROM)
    {
        . = ALIGN(4);
        __data_ram_start = .;
        *(.ramcode)
        . = ALIGN(4);
        *(.data)
        *(.data*)
        . = ALIGN(4);
        *(.mcal_data)
        . = ALIGN(4);
        *(.mcal_data_no_cacheable)
        . = ALIGN(4);
        __data_ram_end = .;
    } > int_sram

    __DATA_ROM_END = __DATA_ROM + (__data_ram_end - __data_ram_start);

    .sram_bss (NOLOAD) :
    {
        . = ALIGN(16);
        __sram_bss_start = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(16);
        *(.mcal_bss)
        . = ALIGN(16);
        __non_cacheable_bss_start = .;
        *(.mcal_bss_no_cacheable)
        . = ALIGN(4);
        __non_cacheable_bss_end = .;
        __sram_bss_end = .;
    } > int_sram


    .acfls_code_ram :
    {
        . += (acfls_code_rom_end - acfls_code_rom_start );
    } > int_sram

    /* heap section */
    .heap (NOLOAD):
    {
        .  = ALIGN(4);
        _end = .;
        end = .;
        _heap_start = .;
        . += HEAP_SIZE;
        _heap_end = .;
    } > int_sram


    int_results (NOLOAD):
    {
        . = ALIGN(4);
        KEEP(*(.int_results))
        . += 0x100;
    } > int_sram_results

    __Stack_end_c0           = ORIGIN(int_sram_stack_c0);
    __Stack_start_c0         = ORIGIN(int_sram_stack_c0) + LENGTH(int_sram_stack_c0);

    __INT_SRAM_START         = ORIGIN(int_sram_results);
    __INT_SRAM_END           = ORIGIN(ram_rsvd2);

    __RAM_INIT_START    = __data_ram_start;
    __RAM_INIT_END      = __data_ram_end;
    __ROM_INIT_START    = __DATA_ROM;
    __ROM_INIT_END      = __DATA_ROM_END;

    __BSS_SRAM_START         = __sram_bss_start;
    __BSS_SRAM_END           = __sram_bss_end;
    __BSS_SRAM_SIZE          = __sram_bss_end - __sram_bss_start;

    __RAM_INTERRUPT_START    = __interrupts_ram_start;
    __ROM_INTERRUPT_START    = __interrupts_rom_start;
    __ROM_INTERRUPT_END      = __interrupts_rom_end;

    __INIT_TABLE             = __init_table;
    __ZERO_TABLE             = __zero_table;

    __RAM_INIT               = 1;

    /* Fls module access code support */
    Fls_ACEraseRomStart         = acfls_code_rom_start;
    Fls_ACEraseRomEnd           = acfls_code_rom_end;
    Fls_ACEraseSize             = acfls_code_rom_end - acfls_code_rom_start;

    Fls_ACWriteRomStart         = acfls_code_rom_start;
    Fls_ACWriteRomEnd           = acfls_code_rom_end;
    Fls_ACWriteSize             = acfls_code_rom_end - acfls_code_rom_start;

    _ERASE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);

    __ENTRY_VTABLE              = __RAM_INTERRUPT_START;
}
