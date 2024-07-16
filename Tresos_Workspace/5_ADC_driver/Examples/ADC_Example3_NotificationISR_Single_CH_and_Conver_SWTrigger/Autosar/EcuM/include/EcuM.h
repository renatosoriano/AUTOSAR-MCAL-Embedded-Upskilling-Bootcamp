/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
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

#ifndef ECUM_H
#define ECUM_H

/**
*   @file
*
*   @addtogroup ECUM_MODULE EcuM Module
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "EcuM_Externals.h"
#include "EcuM_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_VENDOR_ID 43
#define ECUM_MODULE_ID 10
#define ECUM_AR_RELEASE_MAJOR_VERSION 4
#define ECUM_AR_RELEASE_MINOR_VERSION 7
#define ECUM_AR_RELEASE_REVISION_VERSION 0
#define ECUM_SW_MAJOR_VERSION 2
#define ECUM_SW_MINOR_VERSION 0
#define ECUM_SW_PATCH_VERSION 0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (ECUM_VENDOR_ID != ECUM_CBK_VENDOR_ID)
#error "EcuM_Cbk.h and EcuM.h have different vendor ids"
#endif

#if (ECUM_VENDOR_ID != ECUM_CFG_VENDOR_ID)
#error "EcuM_Cfg.h and EcuM.h have different vendor ids"
#endif


#if ((ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_AR_RELEASE_REVISION_VERSION != ECUM_CBK_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of EcuM_Cbk.h and EcuM.h are different"
#endif

#if ((ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION != ECUM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_AR_RELEASE_REVISION_VERSION != ECUM_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of EcuM_Cfg.h and EcuM.h are different"
#endif

#if ((ECUM_SW_MAJOR_VERSION != ECUM_CBK_SW_MAJOR_VERSION) || \
     (ECUM_SW_MINOR_VERSION != ECUM_CBK_SW_MINOR_VERSION) || \
     (ECUM_SW_PATCH_VERSION != ECUM_CBK_SW_PATCH_VERSION))
#error "Software Version Numbers of EcuM_Cbk.h and EcuM.h are different"
#endif

#if ((ECUM_SW_MAJOR_VERSION != ECUM_CFG_SW_MAJOR_VERSION) || \
     (ECUM_SW_MINOR_VERSION != ECUM_CFG_SW_MINOR_VERSION) || \
     (ECUM_SW_PATCH_VERSION != ECUM_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of EcuM_Cfg.h and EcuM.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ECUM_H */
