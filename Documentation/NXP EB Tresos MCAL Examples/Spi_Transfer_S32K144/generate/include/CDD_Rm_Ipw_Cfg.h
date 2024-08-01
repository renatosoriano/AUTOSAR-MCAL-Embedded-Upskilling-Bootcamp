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

#ifndef CDD_RM_IPW_CFG_H
#define CDD_RM_IPW_CFG_H

/**
*   @file CDD_Rm_Ipw_Cfg.h
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
#include "CDD_Rm_Ipw_VS_0_PBcfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_CFG_VENDOR_ID                    43
#define RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_IPW_CFG_AR_RELEASE_MINOR_VERSION     7
#define RM_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_IPW_CFG_SW_MAJOR_VERSION             2
#define RM_IPW_CFG_SW_MINOR_VERSION             0
#define RM_IPW_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Ipw_VS_0_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_VS_0_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_0_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_VS_0_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_0_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_VS_0_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_VS_0_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_VS_0_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_VS_0_PBcfg.h are different"
#endif


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_IPW_ENABLE_DMA_MUX                             (STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct
{
#if (STD_ON == RM_IPW_ENABLE_DMA_MUX)
    const Dma_Mux_Ip_ConfigType      *Rm_Ipw_pDma_MuxConfig;
#endif
} Rm_Ipw_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

RM_IPW_CONFIG_VS_0_PB

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CDD_RM_IPW_CFG_H */

