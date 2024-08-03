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

#ifndef RM_IPW_PBCFG_VS_0_H
#define RM_IPW_PBCFG_VS_0_H

/**
*   @file CDD_Rm_Ipw_PBcfg.h
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
#include "Dma_Mux_Ip.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_PBCFG_VS_0_VENDOR_ID                     43
#define RM_IPW_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION      4
#define RM_IPW_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION      7
#define RM_IPW_PBCFG_VS_0_AR_RELEASE_REVISION_VERSION   0
#define RM_IPW_PBCFG_VS_0_SW_MAJOR_VERSION              2
#define RM_IPW_PBCFG_VS_0_SW_MINOR_VERSION              0
#define RM_IPW_PBCFG_VS_0_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Dma_Mux_Ip.h */
#if (RM_IPW_PBCFG_VS_0_VENDOR_ID != RM_DMA_MUX_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_VS_0_PBcfg.h and Dma_Mux_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION    != RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION    != RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_VS_0_AR_RELEASE_REVISION_VERSION != RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_VS_0_PBcfg.h and Dma_Mux_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_VS_0_SW_MAJOR_VERSION != RM_DMA_MUX_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_VS_0_SW_MINOR_VERSION != RM_DMA_MUX_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_VS_0_SW_PATCH_VERSION != RM_DMA_MUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_VS_0_PBcfg.h and Dma_Mux_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_IPW_PBCFG_VS_0_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_IPW_PBCFG_VS_0_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_VS_0_PBcfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define RM_IPW_CONFIG_VS_0_PB \
    extern const Rm_Ipw_ConfigType Rm_Ipw_Config_VS_0;

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* RM_IPW_VS_0_PBCFG_H */

