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
* 0x00000000    0x0001FFFF  128KB  Flash
* 0x1FFFC000    0x1FFFFFFF  16384  SRAM_L
* 0x20000000    0x20002FFF  12288  SRAM_U
*/


MEMORY
{
    int_flash_interrupts    : ORIGIN = 0x00000000, LENGTH = 0x00000400    /* 1K */    /* Do not change this section */
    int_flash_config        : ORIGIN = 0x00000400, LENGTH = 0x00000010    /* 16bytes */ /* Do not change this section */
    int_flash               : ORIGIN = 0x00000410, LENGTH = 0x0001FBF0    /* ~126KB */
    int_sram_results        : ORIGIN = 0x1FFFC000, LENGTH = 0x00000100    /* 256bytes */
    int_sram                : ORIGIN = 0x1FFFC100, LENGTH = 0x00005F00    /* ~24K */
    int_sram_stack_c0       : ORIGIN = 0x20002000, LENGTH = 0x00001000    /* 4K  */
    ram_rsvd2               : ORIGIN = 0x20003000, LENGTH = 0             /* End of SRAM */
}



DEFAULTS
{
    int_results_reserve = 0x100
}

SECTIONS
{
    .intc_vector                                 ALIGN(2048)  : > int_flash_interrupts
    .flash_config                                ALIGN(4)     : > int_flash_config
    .startup                                     ALIGN(4)     : > int_flash /* Reset code*/
    .systeminit                                  ALIGN(4)     : > . /* SystemInit */
    .text.startup                                ALIGN(4)     : > .
    .text                                        ALIGN(4)     : > .
    .mcal_text                                   ALIGN(4)     : > .
    .acfls_code_rom                              ALIGN(4)     : > .
    .acmem_43_INFLS_code_rom                     ALIGN(4)     : > .

    .rodata                                     ALIGN(4)      : > .
    .mcal_const_cfg                             ALIGN(4)      : > .
    .mcal_const                                 ALIGN(4)      : > .
    .mcal_const_no_cacheable                   ALIGN(4)       : > .
    .init_table                                 ALIGN(4)      : > .
    .zero_table                                 ALIGN(4)      : > .

    /* ROM sections for initialized data */
    .ROM.ramcode                  ROM(.ramcode)                 ALIGN(4)      : > .
    .ROM.acmcu_code_rom           ROM(.acmcu_code_rom)          ALIGN(4)      : > .
    .ROM.data                     ROM(.data)                    ALIGN(4)      : > .
    .ROM.mcal_data                ROM(.mcal_data)               ALIGN(4)      : > .
    .ROM.mcal_data_no_cacheable   ROM(.mcal_data_no_cacheable)  ALIGN(4)      : > .

    .intc_vector_ram     ALIGN(2048) PAD(SIZEOF(.intc_vector))  : > int_sram

    .ramcode                                ABS ALIGN(4)      : > .
    .acmcu_code_rom                             ALIGN(4)      : > .
    .data                                       ALIGN(4)      : > .
    .mcal_data                                  ALIGN(4)      : > .
    .mcal_data_no_cacheable                     ALIGN(4)      : > .
    .bss                               (NOLOAD) ALIGN(16)     : > .
    .mcal_bss                          (NOLOAD) ALIGN(16)     : > .
    .mcal_bss_no_cacheable            (NOLOAD) ALIGN(16)      : > .
    // reserve space for .acfls_code_ram
    .acfls_code_ram                             ALIGN(4) : {. += SIZEOF(.acfls_code_rom);} > .

    .int_results           ALIGN(4) PAD(int_results_reserve) (NOLOAD) : > int_sram_results

    __Stack_end_c0           = ADDR(int_sram_stack_c0);
    __Stack_start_c0         = ADDR(int_sram_stack_c0) + SIZEOF(int_sram_stack_c0);

    __INT_SRAM_START         = ADDR(int_sram_results);
    __INT_SRAM_END           = ADDR(ram_rsvd2);

    __RAM_RAM_CODE_INIT_START     = ADDR(.ramcode);
    __RAM_RAM_CODE_INIT_END       = ADDR(.ramcode) + SIZEOF(.ramcode);
    __ROM_RAM_CODE_INIT_START     = ADDR(.ROM.ramcode);
    __ROM_RAM_CODE_INIT_END       = ADDR(.ROM.ramcode) + SIZEOF(.ROM.ramcode);

    __RAM_AC_MCU_CODE_INIT_START  = ADDR(.acmcu_code_rom);
    __RAM_AC_MCU_CODE_INIT_END    = ADDR(.acmcu_code_rom) + SIZEOF(.acmcu_code_rom);
    __ROM_AC_MCU_CODE_INIT_START  = ADDR(.ROM.acmcu_code_rom);
    __ROM_AC_MCU_CODE_INIT_END    = ADDR(.ROM.acmcu_code_rom) + SIZEOF(.ROM.acmcu_code_rom);

    __RAM_DATA_INIT_START         = ADDR(.data);
    __RAM_DATA_INIT_END           = ADDR(.data) + SIZEOF(.data);
    __ROM_DATA_INIT_START         = ADDR(.ROM.data);
    __ROM_DATA_INIT_END           = ADDR(.ROM.data) + SIZEOF(.ROM.data);

    __RAM_MCAL_DATA_INIT_START    = ADDR(.mcal_data);
    __RAM_MCAL_DATA_INIT_END      = ADDR(.mcal_data) + SIZEOF(.mcal_data);
    __ROM_MCAL_DATA_INIT_START    = ADDR(.ROM.mcal_data);
    __ROM_MCAL_DATA_INIT_END      = ADDR(.ROM.mcal_data) + SIZEOF(.ROM.mcal_data);

    __RAM_MCAL_DATA_NC_INIT_START = ADDR(.mcal_data_no_cacheable);
    __RAM_MCAL_DATA_NC_INIT_END   = ADDR(.mcal_data_no_cacheable) + SIZEOF(.mcal_data_no_cacheable);
    __ROM_MCAL_DATA_NC_INIT_START = ADDR(.ROM.mcal_data_no_cacheable);
    __ROM_MCAL_DATA_NC_INIT_END   = ADDR(.ROM.mcal_data_no_cacheable) + SIZEOF(.ROM.mcal_data_no_cacheable);

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss_no_cacheable) + SIZEOF(.mcal_bss_no_cacheable)) - ADDR(.bss);
    __BSS_SRAM_END                = ADDR(.mcal_bss_no_cacheable) + SIZEOF(.mcal_bss_no_cacheable);

    __RAM_INTERRUPT_START         = ADDR(.intc_vector_ram);
    __ROM_INTERRUPT_START         = ADDR(.intc_vector);
    __ROM_INTERRUPT_END           = ADDR(.intc_vector) + SIZEOF(.intc_vector);

    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __RAM_INIT                    = 1;

    /* Fls module access code support */
    Fls_ACEraseRomStart         = ADDR(.acfls_code_rom);
    Fls_ACEraseRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACEraseSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    Fls_ACWriteRomStart         = ADDR(.acfls_code_rom);
    Fls_ACWriteRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACWriteSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    _ERASE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);

    __ENTRY_VTABLE              = ADDR(.intc_vector);

}
