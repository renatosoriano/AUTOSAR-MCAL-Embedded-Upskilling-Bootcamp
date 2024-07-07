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
==================================================================================================*/

#ifndef SYSTEM_IP_DEVICE_REGISTERS_H_
#define SYSTEM_IP_DEVICE_REGISTERS_H_

/**
*   @file
*
*   @addtogroup System_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_TYPES_VENDOR_ID                    43
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION                   2
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION        0

#if defined(S32K116)
    #include "S32K116.h"
#elif defined(S32K118)
    #include "S32K118.h"
#elif defined(S32K142)
    #include "S32K142.h"
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#elif defined(S32K142W)
    #include "S32K142W.h"
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#elif defined(S32K144)
    #include "S32K144.h"
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#elif defined(S32K144W)
    #include "S32K144W.h"
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#elif defined(S32K146)
    #include "S32K146.h"
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#elif defined(S32K148)
    #include "S32K148.h"    
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#elif defined(S32M244) || defined(S32M242) || defined(S32M241) || defined(S32M243)
    #include "S32M24x.h"
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define MCM_CPCR_CM7_AHBSPRI_MASK MCM_CPCR_CBRR_MASK
#else
    #error "Unknown platform!"
#endif


#endif /* SYSTEM_IP_DEVICE_REGISTERS_H_ */

/** @} */
