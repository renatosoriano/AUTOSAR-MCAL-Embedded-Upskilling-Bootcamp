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
 *   @file    Icu_Cfg.c
 *   @version 2.0.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup icu Icu Driver
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*=================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Icu.h"
#include "Icu_Ipw.h"

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
#include "CDD_Mcl.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define ICU_VENDOR_ID_PCCFG_C                       43
#define ICU_AR_RELEASE_MAJOR_VERSION_PCCFG_C        4
#define ICU_AR_RELEASE_MINOR_VERSION_PCCFG_C        7
#define ICU_AR_RELEASE_REVISION_VERSION_PCCFG_C     0
#define ICU_SW_MAJOR_VERSION_PCCFG_C                2
#define ICU_SW_MINOR_VERSION_PCCFG_C                0
#define ICU_SW_PATCH_VERSION_PCCFG_C                0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check Icu_Cfg.c against Icu.h file versions */
#if (ICU_VENDOR_ID_PCCFG_C != ICU_VENDOR_ID)
    #error "Icu_Cfg.c and Icu.h have different vendor IDs"
#endif

#if ((ICU_AR_RELEASE_MAJOR_VERSION_PCCFG_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_PCCFG_C != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_PCCFG_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Cfg.c and Icu.h are different"
#endif

#if ((ICU_SW_MAJOR_VERSION_PCCFG_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_PCCFG_C != ICU_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_PCCFG_C != ICU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Cfg.c and Icu.h are different"
#endif

/* Check Icu_Cfg.c against Icu_Ipw.h file versions */
#if (ICU_VENDOR_ID_PCCFG_C != ICU_IPW_VENDOR_ID)
    #error "Icu_Cfg.c and Icu_Ipw.h have different vendor IDs"
#endif

#if ((ICU_AR_RELEASE_MAJOR_VERSION_PCCFG_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_PCCFG_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_PCCFG_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Icu_Cfg.c and Icu_Ipw.h are different"
#endif

#if ((ICU_SW_MAJOR_VERSION_PCCFG_C != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_PCCFG_C != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_PCCFG_C != ICU_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Cfg.c and Icu_Ipw.h are different"
#endif

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/* Check Icu_Cfg.c against CDD_Mcl.h file versions */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CDD_MCL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION_PCCFG_C != CDD_MCL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Cfg.c and CDD_Mcl.h are different"
    #endif
#endif
#endif /* ICU_TIMESTAMP_USES_DMA == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} */
