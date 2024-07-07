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

    SECTION .intvec:DATA:ROOT(2)
    EXTERN undefined_handler
    EXTERN undefined_handler
    PUBLIC VTABLE
    EXTERN __Stack_start_c0          /* Top of Stack for Initial Stack Pointer */
    EXTERN Reset_Handler             /* Reset Handler */
    EXTERN NMI_Handler               /* NMI Handler */
    EXTERN HardFault_Handler         /* Hard Fault Handler */
    EXTERN MemManage_Handler         /* Reserved */
    EXTERN BusFault_Handler          /* Bus Fault Handler */
    EXTERN UsageFault_Handler        /* Usage Fault Handler */
    EXTERN SVC_Handler               /* SVCall Handler */
    EXTERN DebugMon_Handler          /* Debug Monitor Handler */
    EXTERN PendSV_Handler            /* PendSV Handler */
    EXTERN SysTick_Handler           /* SysTick Handler */ /* 15*/

VTABLE
    DCD __Stack_start_c0          /* Top of Stack for Initial Stack Pointer */
    DCD Reset_Handler             /* Reset Handler */
    DCD NMI_Handler               /* NMI Handler */
    DCD HardFault_Handler         /* Hard Fault Handler */
    DCD MemManage_Handler         /* Reserved */
    DCD BusFault_Handler          /* Bus Fault Handler */
    DCD UsageFault_Handler        /* Usage Fault Handler */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD SVC_Handler               /* SVCall Handler */
    DCD DebugMon_Handler          /* Debug Monitor Handler */
    DCD 0                         /* Reserved */
    DCD PendSV_Handler            /* PendSV Handler */
    DCD SysTick_Handler           /* SysTick Handler */ /* 15*/

    DCD undefined_handler /*0*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*10*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*20*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*30*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler /*40*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler /*50*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*60*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*70*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*80*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*90*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*100*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*110*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*120*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*130*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*140*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*150*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*160*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*170*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler

    END
