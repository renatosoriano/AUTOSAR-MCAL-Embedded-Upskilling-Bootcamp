/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
#ifndef CDD_RM_CFG_H
#define CDD_RM_CFG_H

/**
*   @file CDD_Rm_Cfg.h
*
*   @addtogroup RM_MODULE RM Driver 
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "CDD_Rm_VS_0_PBcfg.h"
#include "CDD_Rm_Ipw_Cfg.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_CFG_VENDOR_ID                       43
#define RM_CFG_AR_RELEASE_MAJOR_VERSION        4
#define RM_CFG_AR_RELEASE_MINOR_VERSION        7
#define RM_CFG_AR_RELEASE_REVISION_VERSION     0
#define RM_CFG_SW_MAJOR_VERSION                2
#define RM_CFG_SW_MINOR_VERSION                0
#define RM_CFG_SW_PATCH_VERSION                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_VS_0_PBcfg.h */
#if (RM_CFG_VENDOR_ID != RM_PBCFG_VS_0_VENDOR_ID)
    #error "CDD_Rm_Cfg.h and CDD_Rm_VS_0_PBcfg.h have different vendor ids"
#endif
#if ((RM_CFG_AR_RELEASE_MAJOR_VERSION    != RM_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION) || \
     (RM_CFG_AR_RELEASE_MINOR_VERSION    != RM_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION) || \
     (RM_CFG_AR_RELEASE_REVISION_VERSION != RM_PBCFG_VS_0_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_VS_0_PBcfg.h are different"
#endif
#if ((RM_CFG_SW_MAJOR_VERSION != RM_PBCFG_VS_0_SW_MAJOR_VERSION) || \
     (RM_CFG_SW_MINOR_VERSION != RM_PBCFG_VS_0_SW_MINOR_VERSION) || \
     (RM_CFG_SW_PATCH_VERSION != RM_PBCFG_VS_0_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_VS_0_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_CFG_VENDOR_ID != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Cfg.h and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_CFG_SW_MAJOR_VERSION != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_CFG_SW_MINOR_VERSION != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_CFG_SW_PATCH_VERSION != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Cfg.h and CDD_Rm_Ipw_Cfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_CONFIG_EXT \
    RM_CONFIG_VS_0_PB
/* Rm Pre Compile Switch */
#define RM_PRECOMPILE_SUPPORT                   (STD_ON)

/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define RM_DEV_ERROR_DETECT                     (STD_OFF)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Rm_GetVersionInfo() from the code.
*        STD_ON: Rm_GetVersionInfo() can be used. STD_OFF: Rm_GetVersionInfo() can not be used.
*
*/
#define RM_GET_VERSION_INFO_API                 (STD_OFF)

/**
* @brief            Support for User mode.
*                   STD_ON: the Rm driver can be executed from both supervisor and user mode.
*                   STD_OFF: the Rm driver can be executed only from supervisor mode.
*/
#define RM_ENABLE_USER_MODE_SUPPORT             (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == RM_ENABLE_USER_MODE_SUPPORT)
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running RM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == RM_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*********************************** DMA MUX SECTION ******************************/
#define RM_ENABLE_DMA_MUX                             (STD_ON)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief This type is used to group all multiple configurations.
*/
typedef struct
{
    const Rm_Ipw_ConfigType *Rm_pIpwConfig;
} Rm_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* CDD_RM_CFG_H */

