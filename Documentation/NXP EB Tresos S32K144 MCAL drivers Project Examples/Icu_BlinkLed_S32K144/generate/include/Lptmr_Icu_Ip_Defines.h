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

#ifndef LPTMR_ICU_IP_DEFINES_H
#define LPTMR_ICU_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup lptmr_icu_ip LPTMR IPL
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
#include "S32K144_LPTMR.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPTMR_ICU_IP_DEFINES_VENDOR_ID                       43
#define LPTMR_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LPTMR_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define LPTMR_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define LPTMR_ICU_IP_DEFINES_SW_MAJOR_VERSION                2
#define LPTMR_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define LPTMR_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Macros that indicate LPTMR instances used by ICU. */
/** @brief Switches the Development Error Detection and Notification on or off.  */
#define LPTMR_ICU_IP_DEV_ERROR_DETECT               (STD_OFF)

/** @brief The number of LPTMR instances available on platform */
#define LPTMR_ICU_IP_NUM_OF_MODULES                 (1U)

/** @brief Adds or removes all services related to the edge detect functionality. */
#define LPTMR_ICU_EDGE_DETECT_API                   (STD_ON)

/** @brief Adds or removes all services related to the standby wakeup supported */
#define LPTMR_ICU_STANDBY_WAKEUP_SUPPORT            (STD_OFF)

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define LPTMR_ICU_DEINIT_API                        (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define LPTMR_ICU_SET_MODE_API                      (STD_OFF)

/** @brief Adds or removes all services related to edge count functionality. */
#define LPTMR_ICU_EDGE_COUNT_API                    (STD_OFF)

/** @brief Adds or removes all services related to input state functionality. */
#define LPTMR_ICU_GET_INPUT_STATE_API               (STD_OFF)

/** @brief Support for User mode.If this parameter has been configured to STD_ON,
 *  the LPTMR driver code can be executed from both supervisor and user mode. */
#define LPTMR_ICU_ENABLE_USER_MODE_SUPPORT          (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #if (defined (LPTMR_ICU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == LPTMR_ICU_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
 #endif
#endif

/** @brief Get LPTMR type for each platform. */
#define Lptmr_Icu_Ip_BaseType                       LPTMR_Type

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* LPTMR_ICU_IP_DEFINES_H */

/** @} */

