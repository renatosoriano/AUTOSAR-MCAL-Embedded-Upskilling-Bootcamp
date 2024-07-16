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

#ifndef DET_H
#define DET_H

/**
*   @file Det.h
*
*   @addtogroup DET_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Det_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Det_h_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Det.h
* @requirements   DET001_PI
*/

#define DET_VENDOR_ID                       43
#define DET_MODULE_ID                       15
#define DET_AR_RELEASE_MAJOR_VERSION        4
#define DET_AR_RELEASE_MINOR_VERSION        7
#define DET_AR_RELEASE_REVISION_VERSION     0
#define DET_SW_MAJOR_VERSION                2
#define DET_SW_MINOR_VERSION                0
#define DET_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Max numbers of ECU cores supported */
#define DET_NO_ECU_CORES                        (uint8)(1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DET_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
/* Variables to store last DET error */
extern uint8 Det_InstanceId[DET_NO_ECU_CORES];                /**< @brief DET instance ID*/
extern uint8 Det_ApiId[DET_NO_ECU_CORES];                     /**< @brief DET API ID*/
extern uint8 Det_ErrorId[DET_NO_ECU_CORES];                   /**< @brief DET Error ID*/
/* Variables to store last DET runtime error */
extern uint8 Det_RuntimeInstanceId[DET_NO_ECU_CORES];         /**< @brief DET instance ID*/
extern uint8 Det_RuntimeApiId[DET_NO_ECU_CORES];              /**< @brief DET API ID*/
extern uint8 Det_RuntimeErrorId[DET_NO_ECU_CORES];            /**< @brief DET Error ID*/
/* Variables to store last DET transient error */
extern uint8 Det_TransientInstanceId[DET_NO_ECU_CORES];       /**< @brief DET instance ID*/
extern uint8 Det_TransientApiId[DET_NO_ECU_CORES];            /**< @brief DET API ID*/
extern uint8 Det_TransientFaultId[DET_NO_ECU_CORES];          /**< @brief DET Error ID*/
#define DET_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"
extern uint16 Det_TransientModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
extern uint16 Det_ModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
extern uint16 Det_RuntimeModuleId[DET_NO_ECU_CORES];       /**< @brief DET module ID*/
#define DET_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
/*
 * @violates @ref Det_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Det_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Det_MemMap.h"

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

void Det_Init(void);
Std_ReturnType Det_ReportError(uint16 ModuleId,
                               uint8 InstanceId,
                               uint8 ApiId,
                               uint8 ErrorId);
#if defined(ASR_REL_4_0_REV_0003)
#else
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId,
                                      uint8 InstanceId,
                                      uint8 ApiId,
                                      uint8 ErrorId);
Std_ReturnType Det_ReportTransientFault(uint16 ModuleId,
                                        uint8 InstanceId,
                                        uint8 ApiId,
                                        uint8 FaultId);
#endif /*if defined(ASR_REL_4_0_REV_0003)*/
void Det_Start(void);

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DET_H */
