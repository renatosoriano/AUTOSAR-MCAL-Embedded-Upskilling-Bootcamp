/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   (c) Copyright 2020-2024 NXP Semiconductors
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

#ifndef AEWDOG_IP_PBCFG_H
#define AEWDOG_IP_PBCFG_H

/**
*   @file
*
*   @addtogroup AeWdog_Ip
*   @{
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

#include "AeWdog_Ip_Cfg_Defines.h"
#include "AeWdog_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_PBCFG_VENDOR_ID                    43
#define AEWDOG_IP_PBCFG_MODULE_ID                    102
#define AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION     4
#define AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION     7
#define AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION  0
#define AEWDOG_IP_PBCFG_SW_MAJOR_VERSION             2
#define AEWDOG_IP_PBCFG_SW_MINOR_VERSION             0
#define AEWDOG_IP_PBCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Cfg_Defines.h are of the same vendor */
#if (AEWDOG_IP_PBCFG_VENDOR_ID != AEWDOG_IP_CFG_DEFINES_VENDOR_ID)
#error "AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Cfg_Defines.h are of the same Autosar version */
#if ((AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Cfg_Defines.h are different"
#endif

/* Check if AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Cfg_Defines.h are of the same Software version */
#if ((AEWDOG_IP_PBCFG_SW_MAJOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_MINOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_PATCH_VERSION != AEWDOG_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Cfg_Defines.h are different"
#endif

/* Check if AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Types.h are of the same vendor */
#if (AEWDOG_IP_PBCFG_VENDOR_ID != AEWDOG_IP_TYPES_VENDOR_ID)
#error "AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Types.h have different vendor ids"
#endif

/* Check if AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Types.h are of the same Autosar version */
#if ((AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Types.h are different"
#endif

/* Check if AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Types.h are of the same Software version */
#if ((AEWDOG_IP_PBCFG_SW_MAJOR_VERSION != AEWDOG_IP_TYPES_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_MINOR_VERSION != AEWDOG_IP_TYPES_SW_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_PATCH_VERSION != AEWDOG_IP_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of AeWdog_Ip_VS_0_PBcfg.h and AeWdog_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEWDOG_IP_PBCFG_H */
