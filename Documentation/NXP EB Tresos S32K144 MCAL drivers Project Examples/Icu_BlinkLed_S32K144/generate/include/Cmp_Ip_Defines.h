/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CMP_IP_DEFINES_H
#define CMP_IP_DEFINES_H

/**
 *   @file    Cmp_Ip_Defines.h
 *   @version 2.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup cmp_icu_ip CMP IPL
 *   @{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Std_Types.h"

/* Include platform header file. */
#include "S32K144_CMP.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define CMP_IP_DEFINES_VENDOR_ID                       43
#define CMP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CMP_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define CMP_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CMP_IP_DEFINES_SW_MAJOR_VERSION                2
#define CMP_IP_DEFINES_SW_MINOR_VERSION                0
#define CMP_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CMP_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define CMP_IP_USED               (STD_OFF)

#if (STD_ON == CMP_IP_USED)
#define CMP_IP_NOT_SUPPORT_LOWPOWER
#define ICU_CMP_INSTANCE_COUNT    (CMP_INSTANCE_COUNT)

/** @brief Adds or removes all services related to input state functionality. */
#define CMP_IP_GET_INPUT_STATE_API          (STD_OFF)

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define CMP_IP_DEINIT_API                   (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define CMP_IP_SET_MODE_API                 (STD_OFF)

#define CMP_IP_DEV_ERROR_DETECT             (STD_OFF)

#endif /* CMP_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* CMP_IP_DEFINES_H */
