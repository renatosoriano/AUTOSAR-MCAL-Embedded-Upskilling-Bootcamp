/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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
*   @file
*
*   @addtogroup sai_ip_config Sai IPL Configuration
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
==================================================================================================*/
#include "Sai_Ip_VS_0_PBcfg.h"
#if (STD_ON == SAI_IP_ENABLE)
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
#include "Dma_Ip.h"
#endif /* (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE) */
#endif /* (STD_ON == SAI_IP_ENABLE) */


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_VS_0_PBCFG_VENDOR_ID_C                      43
#define SAI_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define SAI_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C       7
#define SAI_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define SAI_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C               2
#define SAI_IP_VS_0_PBCFG_SW_MINOR_VERSION_C               0
#define SAI_IP_VS_0_PBCFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sai_Ip_VS_0_PBcfg header file are of the same vendor */
#if (SAI_IP_VS_0_PBCFG_VENDOR_ID_C != SAI_IP_VS_0_PBCFG_VENDOR_ID)
#error "Sai_Ip_VS_0_PBcfg.c and Sai_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_VS_0_PBcfg header file are of the same Autosar version */
#if ((SAI_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C     != SAI_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C     != SAI_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C  != SAI_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_VS_0_PBcfg.c and Sai_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if current file and Sai_Ip_VS_0_PBcfg header file are of the same software version */
#if ((SAI_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != SAI_IP_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (SAI_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != SAI_IP_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (SAI_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != SAI_IP_VS_0_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip_VS_0_PBcfg.c and Sai_Ip_VS_0_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (STD_ON == SAI_IP_ENABLE)
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
/* Check if current file and Dma_Ip header file are of the same Autosar version */
#if ((SAI_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_VS_0_PBcfg.c and Dma_Ip.h are different"
#endif
#endif /* (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE) */
#endif /* (STD_ON == SAI_IP_ENABLE) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define I2S_START_SEC_VAR_INIT_UNSPECIFIED
#include "I2s_MemMap.h"




#define I2S_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "I2s_MemMap.h"

#define I2S_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2s_MemMap.h"




#define I2S_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2s_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
