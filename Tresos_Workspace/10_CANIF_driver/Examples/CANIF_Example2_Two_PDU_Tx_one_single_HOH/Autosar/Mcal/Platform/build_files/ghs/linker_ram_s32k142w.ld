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
* 0x1FFFC000    0x1FFFFFFF  16384  SRAM_L
* 0x20000000    0x20002FFF  12288  SRAM_U
*/


MEMORY
{
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
    .intc_vector                                 ALIGN(2048)  : > int_sram
    .startup                                     ALIGN(4)     : > . /* Reset code*/
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

    /* Discard boot header in RAM */
    /DISCARD/ : { *(.flash_config) }

    __Stack_end_c0           = ADDR(int_sram_stack_c0);
    __Stack_start_c0         = ADDR(int_sram_stack_c0) + SIZEOF(int_sram_stack_c0);

    __INT_SRAM_START         = ADDR(int_sram_results);
    __INT_SRAM_END           = ADDR(ram_rsvd2);

    __RAM_RAM_CODE_INIT_START     = 0;
    __RAM_RAM_CODE_INIT_END       = 0;
    __ROM_RAM_CODE_INIT_START     = 0;
    __ROM_RAM_CODE_INIT_END       = 0;

    __RAM_AC_MCU_CODE_INIT_START  = 0;
    __RAM_AC_MCU_CODE_INIT_END    = 0;
    __ROM_AC_MCU_CODE_INIT_START  = 0;
    __ROM_AC_MCU_CODE_INIT_END    = 0;

    __RAM_DATA_INIT_START         = 0;
    __RAM_DATA_INIT_END           = 0;
    __ROM_DATA_INIT_START         = 0;
    __ROM_DATA_INIT_END           = 0;

    __RAM_MCAL_DATA_INIT_START    = 0;
    __RAM_MCAL_DATA_INIT_END      = 0;
    __ROM_MCAL_DATA_INIT_START    = 0;
    __ROM_MCAL_DATA_INIT_END      = 0;

    __RAM_MCAL_DATA_NC_INIT_START = 0;
    __RAM_MCAL_DATA_NC_INIT_END   = 0;
    __ROM_MCAL_DATA_NC_INIT_START = 0;
    __ROM_MCAL_DATA_NC_INIT_END   = 0;

    __BSS_SRAM_START              = ADDR(.bss);
    __BSS_SRAM_SIZE               = (ADDR(.mcal_bss_no_cacheable) + SIZEOF(.mcal_bss_no_cacheable)) - ADDR(.bss);
    __BSS_SRAM_END                = ADDR(.mcal_bss_no_cacheable) + SIZEOF(.mcal_bss_no_cacheable);

    __RAM_INTERRUPT_START         = ADDR(.intc_vector);
    __ROM_INTERRUPT_START         = 0;
    __ROM_INTERRUPT_END           = 0;

    __INIT_TABLE                  = ADDR(.init_table);
    __ZERO_TABLE                  = ADDR(.zero_table);

    __RAM_INIT                    = 0;

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
