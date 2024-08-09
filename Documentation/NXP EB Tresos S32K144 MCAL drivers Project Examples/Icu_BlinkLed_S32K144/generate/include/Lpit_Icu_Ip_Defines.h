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

#ifndef LPIT_ICU_IP_DEFINES_H
#define LPIT_ICU_IP_DEFINES_H

/**
 * @file    Lpit_Icu_Ip_Defines.h
 * @version 2.0.0
 *
 * @addtogroup lpit_icu_ip LPIT IPL
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
/* Include platform header file. */
#include "S32K144_LPIT.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPIT_ICU_IP_DEFINES_VENDOR_ID                       43
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define LPIT_ICU_IP_DEFINES_SW_MAJOR_VERSION                2
#define LPIT_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define LPIT_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Lpit_Icu_Ip.h and Std_Types.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Macros that indicate LPIT instances used by ICU. */

/* MIER start bit mask. */
#define LPIT_MIER_TIE_START_MASK                (uint32)0x1U

/* MSR start bit mask. */
#define LPIT_MSR_TIF_START_MASK                 (uint32)0x1U

/* Channels trigger select defines. */
#define LPIT_ICU_TRG_CH0                        ((uint8)0U)
#define LPIT_ICU_TRG_CH1                        ((uint8)1U)
#define LPIT_ICU_TRG_CH2                        ((uint8)2U)
#define LPIT_ICU_TRG_CH3                        ((uint8)3U)

/* Channels trigger source defines. */
#define LPIT_ICU_CH_INTERNAL_TRIGGER            ((uint8)1U)
#define LPIT_ICU_CH_EXTERNAL_TRIGGER            ((uint8)0U)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define LPIT_ICU_IP_DEV_ERROR_DETECT            (STD_OFF)

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define LPIT_ICU_DEINIT_API                     (STD_ON)

/** @brief Adds or removes all services related to the edge detect functionality. */
#define LPIT_ICU_EDGE_DETECT_API                (STD_ON)

/** @brief Adds or removes all services related to the timestamp functionality. */
#define LPIT_ICU_TIMESTAMP_API                  (STD_OFF)

/** @brief Adds or removes all services related to input state functionality. */
#define LPIT_ICU_GET_INPUT_STATE_API            (STD_OFF)

/** @brief Adds or removes all services related to mode set functionality. */
#define LPIT_ICU_IP_SET_MODE_API                (STD_OFF)

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

#endif  /* LPIT_ICU_IP_DEFINES_H */

/** @} */

