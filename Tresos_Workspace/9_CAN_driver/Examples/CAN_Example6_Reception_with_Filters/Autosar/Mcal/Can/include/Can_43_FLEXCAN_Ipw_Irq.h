/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_43_FLEXCAN_IPW_IRQ_H
#define CAN_43_FLEXCAN_IPW_IRQ_H

/**
*   @file    Can_Ipw_Irq.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface.
*   @details API header for CAN driver.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/*
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
* @section Can_43_FLEXCAN_Ipw_Irq_h_REF_1
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like macro where they are interchangeable.
* Function like macro are used to reduce code complexity.
*
* @section Can_43_FLEXCAN_Ipw_Irq_h_REF_2
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* The macro is used as depending on configuration.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_FLEXCAN_Irq.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_FLEXCAN_IPW_IRQ_VENDOR_ID                   43
#define CAN_43_FLEXCAN_IPW_IRQ_AR_RELEASE_MAJOR_VERSION    4
#define CAN_43_FLEXCAN_IPW_IRQ_AR_RELEASE_MINOR_VERSION    7
#define CAN_43_FLEXCAN_IPW_IRQ_AR_RELEASE_REVISION_VERSION 0
#define CAN_43_FLEXCAN_IPW_IRQ_SW_MAJOR_VERSION            2
#define CAN_43_FLEXCAN_IPW_IRQ_SW_MINOR_VERSION            0
#define CAN_43_FLEXCAN_IPW_IRQ_SW_PATCH_VERSION            0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_43_FLEXCAN_Irq.h are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_IRQ_VENDOR_ID != CAN_43_FLEXCAN_IRQ_VENDOR_ID)
#error "Can_43_FLEXCAN_IPW_Irq.h and Can_43_FLEXCAN_Irq.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Irq.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_IRQ_AR_RELEASE_MAJOR_VERSION != CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_IRQ_AR_RELEASE_MINOR_VERSION != CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_IRQ_AR_RELEASE_REVISION_VERSION != CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
  #error "AutoSar Version Numbers of Can_43_FLEXCAN_IPW_Irq.h and Can_43_FLEXCAN_Irq.h are different"
#endif

/* Check if current file and Can_43_FLEXCAN_Irq.h are of the same software version */
#if ((CAN_43_FLEXCAN_IPW_IRQ_SW_MAJOR_VERSION != CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_IRQ_SW_MINOR_VERSION != CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_IRQ_SW_PATCH_VERSION != CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Can_43_FLEXCAN_IPW_Irq.h and Can_43_FLEXCAN_Irq.h are different"
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/* @violates @ref Can_43_FLEXCAN_Ipw_Irq_h_REF_1 MISRA 2012 Advisory Rule 4.9 */
/* @violates @ref Can_43_FLEXCAN_Ipw_Irq_h_REF_2 MISRA 2012 Advisory Rule 2.5 */
#define Can_43_FLEXCAN_Ipw_ProcessMesgBufferCommonInterrupt(u8CtrlOffset, u8FirstMbIdx, u8LastMbIdx)    Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt((u8CtrlOffset), (u8FirstMbIdx), (u8LastMbIdx))
/* @violates @ref Can_43_FLEXCAN_Ipw_Irq_h_REF_1 MISRA 2012 Advisory Rule 4.9 */
/* @violates @ref Can_43_FLEXCAN_Ipw_Irq_h_REF_2 MISRA 2012 Advisory Rule 2.5 */
#define Can_43_FLEXCAN_Ipw_ProcessBusOffInterrupt(u8CtrlOffset)    Can_43_FLEXCAN_ProcessBusOffInterrupt(u8CtrlOffset)
/* @violates @ref Can_43_FLEXCAN_Ipw_Irq_h_REF_1 MISRA 2012 Advisory Rule 4.9 */
/* @violates @ref Can_43_FLEXCAN_Ipw_Irq_h_REF_2 MISRA 2012 Advisory Rule 2.5 */
#define Can_43_FLEXCAN_Ipw_ProcessErrorInterrupt(u8CtrlOffset, bIsErrFast)     Can_43_FLEXCAN_ProcessErrorInterrupt(u8CtrlOffset, bIsErrFast)
/* @violates @ref Can_Ipw_Irq_h_REF_1 MISRA 2012 Advisory Rule 4.9 */
/* @violates @ref Can_Ipw_Irq_h_REF_2 MISRA 2012 Advisory Rule 2.5 */
#define Can_43_FLEXCAN_Ipw_ProcessEnhancedFiFoInterrupt(u8CtrlOffset)     Can_43_FLEXCAN_ProcessEnhancedFiFoInterrupt(u8CtrlOffset)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_43_FLEXCAN_IPW_IRQ_H */