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

#ifndef PORT_CI_ICU_IP_DEFINES_H
#define PORT_CI_ICU_IP_DEFINES_H

/**
 *   @file    Port_Ci_Icu_Ip_Defines.h
 *   @version 2.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup port_ci_icu_ip PORT_CI IPL
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
#include "S32K144_PORT.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define PORT_CI_ICU_IP_DEFINES_VENDOR_ID                      43
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION       4
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION       7
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION    0
#define PORT_CI_ICU_IP_DEFINES_SW_MAJOR_VERSION               2
#define PORT_CI_ICU_IP_DEFINES_SW_MINOR_VERSION               0
#define PORT_CI_ICU_IP_DEFINES_SW_PATCH_VERSION               0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* Macros that indicate PORT instances used by ICU. */
/** @brief PORT 3 ISR enable/disable */
#define PORT_CI_ICU_IP_PORT_3_ISR_USED                    (STD_ON)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define PORT_CI_ICU_IP_DEV_ERROR_DETECT           (STD_OFF)

/** @brief The number of PORT_CI instances available on platform */
#define ICU_NUM_PORT_CI_HW_MODULE_U8              ((uint8)5U)

/** @brief Adds or removes all services related to the edge detect functionality. */
#define PORT_CI_ICU_IP_EDGE_DETECT_API            (STD_ON)

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define PORT_CI_ICU_IP_DEINIT_API                 (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define PORT_CI_ICU_IP_SET_MODE_API               (STD_OFF)

/** @brief Add or remove all functions related to input state. */
#define PORT_CI_ICU_IP_GET_INPUT_STATE_API        (STD_OFF)

/** @brief Support for User mode. If this parameter has been configured to STD_ON, the PORT driver 
 *         code can be executed from both supervisor and user mode. */
#define PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* PORT_CI_ICU_IP_DEFINES_H */
