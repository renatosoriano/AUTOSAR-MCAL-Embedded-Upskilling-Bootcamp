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

/**
 * @file    Lpit_Icu_Ip_VS_0_PBcfg.c
 * @version 2.0.0
 *
 * @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 * @details Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 * @addtogroup lpit_icu_ip LPIT IPL
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpit_Icu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPIT_ICU_IP_VS_0_PBCFG_VENDOR_ID_C                    43
#define LPIT_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define LPIT_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define LPIT_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define LPIT_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C             2
#define LPIT_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION_C             0
#define LPIT_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Lpit_Icu_Ip_Types.h file are of the same vendor */
#if (LPIT_ICU_IP_VS_0_PBCFG_VENDOR_ID_C != LPIT_ICU_IP_TYPES_VENDOR_ID)
    #error "Lpit_Icu_Ip_VS_0_PBcfg.c and Lpit_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and Lpit_Icu_Ip_Types.h file are of the same AutoSar version */
#if ((LPIT_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPIT_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != LPIT_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != LPIT_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lpit_Icu_Ip_VS_0_PBcfg.c and Lpit_Icu_Ip_Types.h are different"
#endif
/* Check if source file and Lpit_Icu_Ip_Types.h file are of the same Software version */
#if ((LPIT_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != LPIT_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPIT_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != LPIT_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (LPIT_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != LPIT_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lpit_Icu_Ip_VS_0_PBcfg.c and Lpit_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

/** @brief Signature of wakeup and overflow interrupt function. */
extern void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow);

/** @brief Signature of change logic channel state function. */
extern void Icu_LogicChStateCallback(uint16 logicChannel, uint8 mask, boolean set);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"



#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
