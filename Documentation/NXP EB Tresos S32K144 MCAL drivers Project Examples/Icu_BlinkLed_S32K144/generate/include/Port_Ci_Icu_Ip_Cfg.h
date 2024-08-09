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

#ifndef PORT_CI_ICU_IP_CFG_H
#define PORT_CI_ICU_IP_CFG_H

/**
 *   @file    Port_Ci_Icu_Ip_Cfg.h
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
#include "Port_Ci_Icu_Ip_VS_0_PBcfg.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define PORT_CI_ICU_IP_CFG_VENDOR_ID                       43
#define PORT_CI_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION        4
#define PORT_CI_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION        7
#define PORT_CI_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION     0
#define PORT_CI_ICU_IP_CFG_SW_MAJOR_VERSION                2
#define PORT_CI_ICU_IP_CFG_SW_MINOR_VERSION                0
#define PORT_CI_ICU_IP_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((PORT_CI_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_Cfg.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Port_Ci_Icu_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (PORT_CI_ICU_IP_CFG_VENDOR_ID != PORT_CI_ICU_IP_VS_0_PBCFG_VENDOR_ID)
    #error "Port_Ci_Icu_Ip_Cfg.h and Port_Ci_Icu_Ip_VS_0_PBcfg.h have different vendor IDs"
#endif

/* Check if header file and Port_Ci_Icu_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((PORT_CI_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_CI_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (PORT_CI_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION != PORT_CI_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_Cfg.h and Port_Ci_Icu_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if header file and Port_Ci_Icu_Ip_VS_0_PBcfg.h file are of the same software version */
#if ((PORT_CI_ICU_IP_CFG_SW_MAJOR_VERSION != PORT_CI_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (PORT_CI_ICU_IP_CFG_SW_MINOR_VERSION != PORT_CI_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (PORT_CI_ICU_IP_CFG_SW_PATCH_VERSION != PORT_CI_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Port_Ci_Icu_Ip_Cfg.h and Port_Ci_Icu_Ip_VS_0_PBcfg.h are different"
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define PORT_CI_ICU_CONFIG_EXT \
        PORT_CI_ICU_CONFIG_VS_0_PB \

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* PORT_CI_ICU_IP_CFG_H */
