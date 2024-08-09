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

#ifndef FTM_ICU_IP_DEFINES_H
#define FTM_ICU_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup ftm_icu_ip FTM IPL
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
#include "S32K144_FTM.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define FTM_ICU_IP_DEFINES_VENDOR_ID                       43
#define FTM_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define FTM_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define FTM_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define FTM_ICU_IP_DEFINES_SW_MAJOR_VERSION                2
#define FTM_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define FTM_ICU_IP_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftm_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Macros that indicate FTM instances used by ICU. */
#ifndef FTM_0_USED
    #define FTM_0_USED
#else
    #error "FTM_0 instance cannot be used by ICU. Instance locked by another driver!"
#endif
/** @brief FTM 0 CH0 CH1 ISR enable/disable */
#define FTM_ICU_0_CH_0_CH_1_ISR_USED        (STD_ON)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define FTM_ICU_IP_DEV_ERROR_DETECT        (STD_OFF)

/** @brief The number of channels available on each FTM instance */
#define FTM_ICU_IP_NUM_OF_CHANNELS         (8U)

/** TODO:Generate @brief The number of channels with filter on each FTM instance */
#define FTM_FILTER_MAX_NO_CH               (4U)

/** @brief Adds or removes all services related to the timestamp functionality. */
#define FTM_ICU_TIMESTAMP_API              (STD_OFF)

/** @brief Adds or removes all services related to the edge detect functionality. */
#define FTM_ICU_EDGE_DETECT_API            (STD_ON)

/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define FTM_ICU_SIGNAL_MEASUREMENT_API     (STD_OFF)

/** @brief Adds or removes all services related to the input level. */
#define FTM_ICU_GET_INPUT_LEVEL_API        (STD_ON)

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define FTM_ICU_DEINIT_API                 (STD_ON)

/** @brief Adds or removes all services related to mode set functionality. */
#define FTM_ICU_SET_MODE_API               (STD_OFF)

/** @brief Adds or removes all services related to edge count functionality. */
#define FTM_ICU_EDGE_COUNT_API             (STD_OFF)

/** @brief  Adds or removes the service Icu_GetTimeElapsed() from the code. */
#define FTM_ICU_GET_TIME_ELAPSED_API       (STD_OFF)

/** @brief  Adds or removes the service Icu_GetDutyCycleValues() from the code. */
#define FTM_ICU_GET_DUTY_CYCLE_VALUES_API   (STD_OFF)

/** @brief Adds or removes all services related to input state functionality. */
#define FTM_ICU_GET_INPUT_STATE_API        (STD_OFF)

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define FTM_ICU_DUAL_CLOCK_MODE_API        (STD_ON)

/** @brief Adds or removes all services related to capture register functionality. */
#define FTM_ICU_CAPTURERGISTER_API         (STD_ON)

/** @brief Adds or Removes the code related to overflow notification */
#define FTM_ICU_OVERFLOW_NOTIFICATION_API  (STD_OFF)

/** @brief Adds or removes the support measurement with DMA*/
#define FTM_ICU_TIMESTAMP_USES_DMA         (STD_OFF)

/** @brief Support for User mode.If this parameter has been configured to STD_ON,
 *  the FTM driver code can be executed from both supervisor and user mode.
 */
#define FTM_ICU_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (FTM_ICU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == FTM_ICU_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif
#endif

/** @brief Get FTM type for each platform. */
#define Ftm_Icu_Ip_BaseType                   FTM_Type

/* Define used for FTM instance with distinct lines for overflow IRQ and event IRQ. */
#define FTM_ICU_TOF_DISTINCT_LINE             (STD_ON)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == FTM_ICU_TIMESTAMP_API)
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific micro-controller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 Ftm_Icu_ValueType;
#endif
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* FTM_ICU_IP_DEFINES_H */

/** @} */

