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
*   Copyright 2020-2024 NXP Semiconductors
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

#include "AeWdog_Ip_VS_0_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_PBCFG_VENDOR_ID_C                      43
#define AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define AEWDOG_IP_PBCFG_SW_MAJOR_VERSION_C               2
#define AEWDOG_IP_PBCFG_SW_MINOR_VERSION_C               0
#define AEWDOG_IP_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and AeWdog_Ip_VS_0_PBcfg header file are of the same vendor */
#if (AEWDOG_IP_PBCFG_VENDOR_ID_C != AEWDOG_IP_PBCFG_VENDOR_ID)
#error "AeWdog_Ip_VS_0_PBcfg.c and AeWdog_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if current file and AeWdog_Ip_VS_0_PBcfg header file are of the same Autosar version */
#if ((AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != AEWDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION   ) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != AEWDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION   ) || \
     (AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != AEWDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of AeWdog_Ip_VS_0_PBcfg.c and AeWdog_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if current file and AeWdog_Ip_VS_0_PBcfg header file are of the same software version */
#if ((AEWDOG_IP_PBCFG_SW_MAJOR_VERSION_C != AEWDOG_IP_PBCFG_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_MINOR_VERSION_C != AEWDOG_IP_PBCFG_SW_MINOR_VERSION) || \
     (AEWDOG_IP_PBCFG_SW_PATCH_VERSION_C != AEWDOG_IP_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of AeWdog_Ip_VS_0_PBcfg.c and AeWdog_Ip_VS_0_PBcfg.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"


#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
