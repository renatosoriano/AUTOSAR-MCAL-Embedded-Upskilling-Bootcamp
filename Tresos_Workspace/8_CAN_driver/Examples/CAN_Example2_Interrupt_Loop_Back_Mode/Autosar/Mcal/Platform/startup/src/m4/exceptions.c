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
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/
/*==================================================================================================
*   @file    exceptions.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - Interrupts table.
*   @details Interrupts table.
*            This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Types.h"
#include "Mcal.h"
#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 

#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 

void NMI_Handler(void)                  __attribute__ ((weak));               /* NMI Handler */
void HardFault_Handler(void)            __attribute__ ((weak));         /* Hard Fault Handler */
void MemManage_Handler(void)            __attribute__ ((weak));         /* Reserved */
void BusFault_Handler(void)             __attribute__ ((weak));          /* Bus Fault Handler */
void UsageFault_Handler(void)           __attribute__ ((weak));        /* Usage Fault Handler */
void DebugMon_Handler(void)             __attribute__ ((weak));          /* Debug Monitor Handler */
void PendSV_Handler(void)               __attribute__ ((weak));            /* PendSV Handler */
void SysTick_Handler(void)              __attribute__ ((weak));           /* SysTick Handler */
void undefined_handler(void);         /* Undefined Handler */
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
void SVCHandler_main(uint32 * svc_args);
void Suspend_Interrupts(void);
void Resume_Interrupts(void);
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#ifndef __ICCARM__
/* Define the SVC handler in assembly, to ensure there is no extra PUSH instruction at the beginning of the C handler.*/
ASM_KEYWORD(".globl SVC_Handler");
ASM_KEYWORD(".weak SVC_Handler");
ASM_KEYWORD("SVC_Handler:");
/*Load in R0 the stack pointer (depneding on context from which SVC is called)*/
ASM_KEYWORD("tst     lr, #4");
ASM_KEYWORD("ite eq");
ASM_KEYWORD("mrseq   r0, MSP");
ASM_KEYWORD("mrsne   r0, PSP");
/* stack pointer is passed to SVCHandler_main, it will be used to extract the parameter given to svc call*/
ASM_KEYWORD("b       SVCHandler_main");
#else
void SVC_Handler(void) __attribute__((naked, weak));
void SVC_Handler(void)
{
    ASM_KEYWORD("tst lr, #4\n"\
                "ite eq\n" \
                "mrseq   r0, MSP\n" \
                "mrsne   r0, PSP\n");
    /* stack pointer is passed to SVCHandler_main, it will be used to extract the parameter given to svc call*/
    ASM_KEYWORD("b       SVCHandler_main");
}
#endif
#endif


void NMI_Handler(void)
{
    while(TRUE){};
}
void HardFault_Handler(void)
{
    while(TRUE){};
}
void MemManage_Handler(void)
{
    while(TRUE){};
}
void BusFault_Handler(void)
{
    while(TRUE){};
}
void UsageFault_Handler(void)
{
    while(TRUE){};
}

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
void SVC_Handler(void)  __attribute__ ((weak));               /* SVCall Handler */
void SVC_Handler(void)
{
    while(TRUE){};
}
#else
void SVCHandler_main(uint32 * svc_args)
{
    uint32 svc_number;    /* Stack contains:    * r0, r1, r2, r3, r12, r14, the return address and xPSR   */
                                /* First argument (r0) is svc_args[0]  */
    /* svc_args[6] =  SP + 0x18  PC(r15) */
    /* ((char *)svc_args[6])[-2]; = first two bytes, lsb, of the instruction which caused the SVC */
    /* this will nto work if optimization compiler options are changed*/
    svc_number = ((uint8 *)svc_args[6])[-2];
    switch(svc_number)
    {
        case 1:
            /* Handle SVC 01*/
            ASM_KEYWORD("mov   r0, #0x1");   /* Set User mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 0:
            /* Handle SVC 00*/
            ASM_KEYWORD("mov   r0, #0x0");   /* Set Supervisor mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 2:
            /* Handle SVC 02*/
            Resume_Interrupts();
            break;
        case 3:
            /* Handle SVC 03*/
            Suspend_Interrupts();

            break;
        default:
            /* Unknown SVC*/
            break;
    }
}

void Suspend_Interrupts(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("mov   r0, #0x10");
    ASM_KEYWORD(" msr BASEPRI, r0");
    ASM_KEYWORD("pop {r0}");
}

void Resume_Interrupts(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("mov   r0, #0x0");
    ASM_KEYWORD("msr BASEPRI, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif
void DebugMon_Handler(void)
{
    while(TRUE){};
}
void PendSV_Handler(void)
{
    while(TRUE){};
}
void SysTick_Handler(void)
{
    while(TRUE){};
}
void undefined_handler(void)
{
   while(TRUE){};
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes =
#endif

#ifdef __cplusplus
}
#endif



