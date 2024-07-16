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
*   @file    Vector_Table.s
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - Vector table
*   @details Vector table.
*            This file contains sample code only. It is not part of the production code deliverables
*=================================================================================================*/

.section  ".intc_vector","ax"
.align 2
.thumb
.globl undefined_handler
.globl undefined_handler
.globl VTABLE
.globl __Stack_start_c0          /* Top of Stack for Initial Stack Pointer */
.globl Reset_Handler             /* Reset Handler */
.globl NMI_Handler               /* NMI Handler */
.globl HardFault_Handler         /* Hard Fault Handler */
.globl MemManage_Handler         /* Reserved */
.globl BusFault_Handler          /* Bus Fault Handler */
.globl UsageFault_Handler        /* Usage Fault Handler */
.globl SVC_Handler               /* SVCall Handler */
.globl DebugMon_Handler          /* Debug Monitor Handler */
.globl PendSV_Handler            /* PendSV Handler */
.globl SysTick_Handler           /* SysTick Handler */ /* 15*/

VTABLE:

.long __Stack_start_c0          /* Top of Stack for Initial Stack Pointer */
.long Reset_Handler+1           /* Reset Handler need plus 1 because Reset_Handler is generated with LSB bit =0*/
.long NMI_Handler               /* NMI Handler */
.long HardFault_Handler         /* Hard Fault Handler */
.long MemManage_Handler         /* Reserved */
.long BusFault_Handler          /* Bus Fault Handler */
.long UsageFault_Handler        /* Usage Fault Handler */
.long 0                         /* Reserved */
.long 0                         /* Reserved */
.long 0                         /* Reserved */
.long 0                         /* Reserved */
.long SVC_Handler+1             /* SVCall Handler */
.long DebugMon_Handler          /* Debug Monitor Handler */
.long 0                         /* Reserved */
.long PendSV_Handler            /* PendSV Handler */
.long SysTick_Handler           /* SysTick Handler */ /* 15*/

.long undefined_handler /*0*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*10*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*20*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*30*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler /*40*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler /*50*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*60*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*70*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*80*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*90*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler 
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*100*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*110*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*120*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*130*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*140*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*150*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*160*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler /*170*/
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler
.long undefined_handler




.size VTABLE, . - VTABLE

