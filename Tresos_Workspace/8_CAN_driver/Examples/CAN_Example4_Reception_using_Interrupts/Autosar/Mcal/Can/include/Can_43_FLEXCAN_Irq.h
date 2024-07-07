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

#ifndef CAN_43_FLEXCAN_IRQ_H
#define CAN_43_FLEXCAN_IRQ_H

/**
*   @file    Can_43_FLEXCAN_Irq.h
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
* @section Can_43_FLEXCAN_Irq_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
**
* @section Can_43_FLEXCAN_Irq_h_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor
* directives or comments.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_FLEXCAN_Ipw_Cfg.h"
#include "Can_Flexcan_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_43_FLEXCAN_IRQ_VENDOR_ID                   43
#define CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION    4
#define CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION    7
#define CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION 0
#define CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION            2
#define CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION            0
#define CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION            0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h header file are of the same vendor */
#if (CAN_43_FLEXCAN_IRQ_VENDOR_ID != CAN_43_FLEXCAN_IPW_CFG_VENDOR_ID)
    #error "Can_43_FLEXCAN_Irq.h and Can_43_FLEXCAN_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION    != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION    != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Irq.h and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION != CAN_43_FLEXCAN_IPW_CFG_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION != CAN_43_FLEXCAN_IPW_CFG_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION != CAN_43_FLEXCAN_IPW_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_43_FLEXCAN_Irq.h and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif

/* Check if current file and Can_Flexcan_Types.h header file are of the same vendor */
#if (CAN_43_FLEXCAN_IRQ_VENDOR_ID != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN_Irq.h and Can_Flexcan_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Flexcan_Types.h file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IRQ_AR_RELEASE_MAJOR_VERSION    != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_MINOR_VERSION    != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IRQ_AR_RELEASE_REVISION_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Irq.h and Can_Flexcan_Types.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Flexcan_Types header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IRQ_SW_MAJOR_VERSION != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IRQ_SW_MINOR_VERSION != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IRQ_SW_PATCH_VERSION != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_43_FLEXCAN_Irq.h and Can_Flexcan_Types.h are different"
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_Irq_h_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_43_FLEXCAN_MemMap.h"

#if ((CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON) || (CAN_43_FLEXCAN_FEATURE_HAS_PRETENDED_NETWORKING == STD_ON))
void Can_43_FLEXCAN_CommonIrqCallback(uint8 u8Instance,
                           Flexcan_Ip_EventType event,
                           uint32 u32buffIdx,
                           const Flexcan_Ip_StateType *driverState
                          );
#endif 

void Can_43_FLEXCAN_ErrorIrqCallback(uint8 u8Instance,
                          Flexcan_Ip_EventType event,
                          uint32 u32ErrStatus,
                          const Flexcan_Ip_StateType *driverState
                         );
 
#if (CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON)
/* Function process Message Buffer Interrupt */
void Can_43_FLEXCAN_ProcessMesgBufferCommonInterrupt
(
    uint8 u8CtrlOffset,
    uint8 u8MbIdx,
    Can_43_FLEXCAN_MbType mbType
);
#endif /* (CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON) */

/* Function process Bus Off Interrupt */
void Can_43_FLEXCAN_ProcessBusOffInterrupt
(
    uint8 u8CtrlOffset
);

#if (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
/* Function process Error Interrupt */
void Can_43_FLEXCAN_ProcessErrorInterrupt
(
    uint8 u8CtrlOffset,
    uint32 u32ErrStatus
);
#endif /* (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON) */

#if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
void Can_43_FLEXCAN_ProcessPNInterrupt(uint8 u8CtrlOffset);
#endif /* (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_OFF) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_Irq_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_Irq_h_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_43_FLEXCAN_IRQ_H */
