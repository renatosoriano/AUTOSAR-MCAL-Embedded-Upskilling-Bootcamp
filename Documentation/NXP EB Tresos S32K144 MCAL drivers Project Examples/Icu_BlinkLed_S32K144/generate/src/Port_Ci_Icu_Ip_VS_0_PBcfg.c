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
 *   @file    Port_Ci_Icu_Ip_VS_0_PBcfg.c
 *   @version 2.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module
 *   @details Contains the information that will be exported by the module, as requested by AUTOSAR.
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
#include "Port_Ci_Icu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define PORT_CI_ICU_IP_VS_0_PBCFG_VENDOR_ID_C                       43
#define PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C        7
#define PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define PORT_CI_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C                2
#define PORT_CI_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION_C                0
#define PORT_CI_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_VS_0_PBcfg.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (PORT_CI_ICU_IP_VS_0_PBCFG_VENDOR_ID_C != PORT_CI_ICU_IP_TYPES_VENDOR_ID)
    #error "Port_Ci_Icu_Ip_VS_0_PBcfg.c and Port_Ci_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != PORT_CI_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != PORT_CI_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != PORT_CI_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_VS_0_PBcfg.c and Port_Ci_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((PORT_CI_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != PORT_CI_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (PORT_CI_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != PORT_CI_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (PORT_CI_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != PORT_CI_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Port_Ci_Icu_Ip_VS_0_PBcfg.c and Port_Ci_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/*
 *  @brief    PB_VS_0 PORT_CI Channels Configuration
 */
const Port_Ci_Icu_Ip_ChannelConfigType Port_Ci_Icu_Ip_3_ChannelConfig_PB_VS_0[1U] =
{
    /** @brief IcuPortChannels_0 */
    {
        /** @brief Assigned Port_Ci channel id */
        14U,
        /** @brief Port_Ci Edge type */
        PORT_CI_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        /** @brief The notification functions */
        NULL_PTR,
        /** @brief Callback Param1*/
        1U
    }
};
/*
 *  @brief    PB_VS_0 Default PORT_CI IP Configuration
 */
const Port_Ci_Icu_Ip_ConfigType Port_Ci_Icu_Ip_3_Config_PB_VS_0 = 
{
    /** @brief Number of Port_Ci channels in the Icu configuration */
    (uint8)1U,
    /** @brief Pointer to the array of Port_Ci channel configurations */
    &Port_Ci_Icu_Ip_3_ChannelConfig_PB_VS_0
};
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
