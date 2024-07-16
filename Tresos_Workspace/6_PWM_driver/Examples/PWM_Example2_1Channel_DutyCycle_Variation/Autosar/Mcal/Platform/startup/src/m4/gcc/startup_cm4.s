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
*==================================================================================================
*   @file    startup_cm4.s
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - Startup file for ARM.
*   @details Startup file for ARM.
*            This file contains sample code only. It is not part of the production code deliverables
*=================================================================================================*/
#define WDOG_CS (0x40052000)
#define WDOG_TOVAL (0x40052008)

#define WDOG_CS_DISABLE (0x00002520)
 
	.syntax unified
    .arch armv7-m
/* Table for copying and zeroing */
/* Copy table:
  - Table entries count
    - entry one ram start
    - entry one rom start
    - entry one rom end
    ...
    - entry n ram start
    - entry n rom start
    - entry n rom end
  Zero Table:
    - Table entries count
      - entry one ram start
      - entry one ram end
*/
.section ".init_table", "a"
  .long 2
  .long __RAM_INIT_START
  .long __ROM_INIT_START
  .long __ROM_INIT_END
  .long __RAM_INTERRUPT_START
  .long __ROM_INTERRUPT_START
  .long __ROM_INTERRUPT_END  
.section ".zero_table", "a"
  .long 1
  .long __BSS_SRAM_START
  .long __BSS_SRAM_END

/* Flash Configuration */
    .section .flash_config, "a"
    .long 0xFFFFFFFF     /* 8 bytes backdoor comparison key           */
    .long 0xFFFFFFFF     /*                                           */
    .long 0xFFFFFFFF     /* 4 bytes program flash protection bytes    */
    .long 0xFFFF7FFE     /* FDPROT:FEPROT:FOPT:FSEC(0xFE = unsecured) */

.globl VTABLE
.section ".startup","ax"
.thumb
/************************************************************************/
/* Autosar synopsis of startup code (See MCU Specification):            */
/*                                                                      */
/*   Before the MCU driver can be initialized, a basic initialization   */
/*   of the MCU has to be executed. This MCU specific initialization is */
/*   typically executed in a start-up code. The start-up code of the    */
/*   MCU shall be executed after power up and any kind of micro-        */
/*   controller reset. It shall perform very basic and microcontroller  */
/*   specific start-up initialization and shall be kept short, because  */
/*   the MCU clock and PLL is not yet initialized. The start-up code    */
/*   shall cover MCU specific initialization, which is not part of      */
/*   other MCU services or other MCAL drivers. The following steps      */
/*   summarizes basic functionality which shall be included in the      */
/*   start-up code. They are listed for guidance, because some          */
/*   functionality might not be supported. No code will be found in     */
/*   case.                                                              */
/************************************************************************/
.set VTOR_REG, 0xE000ED08
.set CHIPCTL, 0x40048004
.set DISRAMRE, 0x00300000
.thumb 
.thumb_func
.globl Reset_Handler
.globl _start
_start:
Reset_Handler:
/*****************************************************/
/* Skip normal entry point as nothing is initialized */
/*****************************************************/
 cpsid i
 mov   r0, #0
 mov   r1, #0
 mov   r2, #0
 mov   r3, #0
 mov   r4, #0
 mov   r5, #0
 mov   r6, #0
 mov   r7, #0
 
/*****************************************************/
/* Configuring sram retention out of reset */
/*****************************************************/

/* Disable SRAM retention */
ldr  r0, =CHIPCTL
ldr  r1, =DISRAMRE
str  r1,[r0]

/*******************************************************************/
/* NXP Guidance 1 - Init registers to avoid lock-step issues */
/* N/A                                                             */
/*******************************************************************/

/*******************************************************************/
/* NXP Guidance 2 - MMU Initialization for CPU               */
/*  TLB0 - PbridgeB                                                */
/*  TLB1 - Internal Flash                                          */
/*  TLB2 - External SRAM                                           */
/*  TLB3 - Internal SRAM                                           */
/*  TLB4 - PbridgeA                                                */
/*******************************************************************/

/******************************************************************/
/* Autosar Guidance 1 - The start-up code shall initialize the    */
/* base addresses for interrupt and trap vector tables. These base*/
/* addresses are provided as configuration parameters or          */
/* linker/locator setting.                                        */
/******************************************************************/

SetVTOR:
/* relocate vector table to RAM */
ldr  r0, =VTOR_REG
ldr  r1, =__RAM_INTERRUPT_START
str  r1,[r0]

/******************************************************************/
/* Autosar Guidance 2 - The start-up code shall initialize the    */
/* interrupt stack pointer, if an interrupt stack is              */
/* supported by the MCU. The interrupt stack pointer base address */
/* and the stack size are provided as configuration parameter or  */
/* linker/locator setting.                                        */
/*                                                                */
/******************************************************************/


/******************************************************************/
/* Autosar Guidance 3 - The start-up code shall initialize the    */
/* user stack pointer. The user stack pointer base address and    */
/* the stack size are provided as configuration parameter or      */
/* linker/locator setting.                                        */
/******************************************************************/

SetCore0Stack:
  /* set up stack; r13 SP*/
  ldr  r0, =__Stack_start_c0
  msr MSP, r0
  b DisableSWT0

/******************************************************************/
/* Autosar Guidance 4 - If the MCU supports context save          */
/* operation, the start-up code shall initialize the memory which */
/* is used for context save operation. The maximum amount of      */
/* consecutive context save operations is provided as             */
/* configuration parameter or linker/locator setting.             */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 5 - The start-up code shall ensure that the   */
/* MCU internal watchdog shall not be serviced until the watchdog */
/* is initialized from the MCAL watchdog driver. This can be      */
/* done for example by increasing the watchdog service time.      */
/*                                                                */
/******************************************************************/

/* Note from manual: For any operation to be performed on an SWT  */
/* instance, its respective core must be enabled.                 */
DisableSWT0:
  ldr  r0, =WDOG_CS
  ldr  r1, =WDOG_CS_DISABLE
  str  r1, [r0]
  ldr  r0, =WDOG_TOVAL
  ldr  r1, =0xFFFF
  str  r1, [r0]
  b    RamInit

/******************************************************************/
/* Autosar Guidance 13 - The start-up code shall initialize a     */
/* minimum amount of RAM in order to allow proper execution of    */
/* the MCU driver services and the caller of these services.      */
/******************************************************************/
RamInit:
    /* Initialize SRAM ECC */
    ldr  r0, =__RAM_INIT
    cmp  r0, 0
    /* Skip if __SRAM_INIT is not set */
    beq SRAM_LOOP_END
    ldr r1, =__INT_SRAM_START
    ldr r2, =__INT_SRAM_END
    
    subs    r2, r1
    subs    r2, #1
    ble SRAM_LOOP_END

    movs    r0, 0
    movs    r3, 0
SRAM_LOOP:
    stm r1!, {r0,r3}
    subs r2, 8
    bge SRAM_LOOP
SRAM_LOOP_END:

DebuggerHeldCoreLoop:
  ldr  r0, =RESET_CATCH_CORE
  ldr  r0, [r0]
  ldr  r1, =0x5A5A5A5A
  cmp  r0, r1
  beq	DebuggerHeldCoreLoop

/************************/
/* Erase ".bss Section" */
/************************/
_DATA_INIT:
    b	 _INIT_DATA_BSS

_INIT_DATA_BSS:
  bl init_data_bss


/******************************************************************/
/* Autosar Guidance 6 - If the MCU supports cache memory for data */
/* and/or code, it shall be initialized and enabled in the        */
/* start-up code.                                                 */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 7 - The start-up code shall initialize MCU    */
/* specific features of internal memory like memory protection.   */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 8 - If external memory is used, the memory    */
/* shall be initialized in the start-up code. The start-up code   */
/* shall be prepared to support different memory configurations   */
/* depending on code location. Different configuration options    */
/* shall be taken into account for code execution from            */
/* external/internal memory.                                      */
/* N/A - external memory is not used                              */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 9 - The settings of the different memories    */
/* shall be provided to the start-up code as configuration        */
/* parameters.                                                    */
/* N/A - all memories are already configured                      */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 10 - In the start-up code a default           */
/* initialization of the MCU clock system shall be performed      */
/* including global clock prescalers.                             */
/******************************************************************/
__SYSTEM_INIT:
  bl SystemInit

/******************************************************************/
/* Autosar Guidance 5 - The start-up code shall ensure that the   */
/* MCU internal watchdog shall not be serviced until the watchdog */
/* is initialized from the MCAL watchdog driver. This can be      */
/* done for example by increasing the watchdog service time.      */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 11 - The start-up code shall enable           */
/* protection mechanisms for special function registers(SFR's),   */
/* if supported by the MCU.                                       */
/* N/A - will be handled by Autosar OS                            */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 12 - The start-up code shall initialize all   */
/* necessary write once registers or registers common to several  */
/* drivers where one write, rather than repeated writes, to the   */
/* register is required or highly desirable.                      */
/******************************************************************/

/*********************************/
/* Set the small ro data pointer */
/*********************************/


/*********************************/
/* Set the small rw data pointer */
/*********************************/

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
_MAIN:
  cpsie i
  bl startup_go_to_user_mode
  bl main

/******************************************************************/
/* Init runtime check data space                                  */
/******************************************************************/
.globl MCAL_LTB_TRACE_OFF
 MCAL_LTB_TRACE_OFF:
    nop

#ifdef CCOV_ENABLE
    /* code coverage is requested */
    bl ccov_main
#endif

    /*BKPT #1 - removed to avoid debug fault being escalated to hardfault when debugger is not attached or on VDK*/ /* last instruction for the debugger to dump results data */
.globl _end_of_eunit_test
_end_of_eunit_test:
    b .

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
.globl startup_getControlRegisterValue
startup_getControlRegisterValue:
mrs r0, CONTROL
bx r14

.globl startup_getAipsRegisterValue
startup_getAipsRegisterValue:
mrs r0, IPSR
bx r14
#endif

.align 4
.ltorg
