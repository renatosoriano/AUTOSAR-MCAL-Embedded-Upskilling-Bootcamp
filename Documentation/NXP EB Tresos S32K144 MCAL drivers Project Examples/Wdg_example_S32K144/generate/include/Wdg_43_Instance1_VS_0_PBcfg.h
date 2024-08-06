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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef WDG_43_INSTANCE1_VS_0_PBCFG_H
#define WDG_43_INSTANCE1_VS_0_PBCFG_H

/**
*   @file
*
*   @addtogroup Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/
#include "Wdg_ChannelTypes.h"
#include "Wdg_43_Instance1_Ipw_VS_0_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_43_INSTANCE1_VENDOR_ID_VS_0_PBCFG                    43
#define WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG     4
#define WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG     7
#define WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG  0
#define WDG_43_INSTANCE1_SW_MAJOR_VERSION_VS_0_PBCFG             2
#define WDG_43_INSTANCE1_SW_MINOR_VERSION_VS_0_PBCFG             0
#define WDG_43_INSTANCE1_SW_PATCH_VERSION_VS_0_PBCFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_ChannelTypes header file are of the same vendor */
#if (WDG_43_INSTANCE1_VENDOR_ID_VS_0_PBCFG != WDG_CHANNEL_TYPES_VENDOR_ID)
#error "Wdg_43_Instance1_VS_0_PBcfg.h and Wdg_ChannelTypes.h have different vendor ids"
#endif

/* Check if current file and Wdg_ChannelTypes header file are of the same Autosar version */
#if ((WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG     != WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG     != WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG  != WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_43_Instance1_VS_0_PBcfg.h and Wdg_ChannelTypes.h are different"
#endif

/* Check if current file and Wdg_ChannelTypes header file are of the same software version */
#if ((WDG_43_INSTANCE1_SW_MAJOR_VERSION_VS_0_PBCFG != WDG_CHANNEL_TYPES_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_MINOR_VERSION_VS_0_PBCFG != WDG_CHANNEL_TYPES_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_PATCH_VERSION_VS_0_PBCFG != WDG_CHANNEL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_43_Instance1_VS_0_PBcfg.h and Wdg_ChannelTypes.h are different"
#endif

/* Check if current file and Wdg_43_Instance1_Ipw_VS_0_PBcfg configuration header file are of the same vendor */
#if (WDG_43_INSTANCE1_VENDOR_ID_VS_0_PBCFG != WDG_43_INSTANCE1_IPW_VENDOR_ID_VS_0_PBCFG)
#error "Wdg_43_Instance1_VS_0_PBcfg.h and Wdg_43_Instance1_Ipw_VS_0_PBcfg.h have different vendor ids"
#endif

#if ((WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG    != WDG_43_INSTANCE1_IPW_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
     (WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG    != WDG_43_INSTANCE1_IPW_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
     (WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG != WDG_43_INSTANCE1_IPW_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG))
#error "AutoSar Version Numbers of Wdg_43_Instance1_VS_0_PBcfg.h and Wdg_43_Instance1_Ipw_VS_0_PBcfg.h are different"
#endif

#if ((WDG_43_INSTANCE1_SW_MAJOR_VERSION_VS_0_PBCFG != WDG_43_INSTANCE1_IPW_SW_MAJOR_VERSION_VS_0_PBCFG) || \
     (WDG_43_INSTANCE1_SW_MINOR_VERSION_VS_0_PBCFG != WDG_43_INSTANCE1_IPW_SW_MINOR_VERSION_VS_0_PBCFG) || \
     (WDG_43_INSTANCE1_SW_PATCH_VERSION_VS_0_PBCFG != WDG_43_INSTANCE1_IPW_SW_PATCH_VERSION_VS_0_PBCFG))
#error "Software Version Numbers of Wdg_43_Instance1_VS_0_PBcfg.h and Wdg_43_Instance1_Ipw_VS_0_PBcfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define WDG_43_INSTANCE1_CONFIG_VS_0_PB \
extern const Wdg_ConfigType Wdg_Config_1_VS_0;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_43_INSTANCE'1`_VS_0_PBCFG_H */
