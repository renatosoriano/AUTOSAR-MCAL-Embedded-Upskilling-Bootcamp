/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CDD_MCL_CFG_DEFINES_H_
#define CDD_MCL_CFG_DEFINES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Cfg_Defines.h"
#include "Cache_Ip_Cfg_Defines.h"
#include "Trgmux_Ip_Cfg_Defines.h"
#include "Flexio_Mcl_Ip_Cfg_Defines.h"
#include "Ftm_Mcl_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCL_CFG_DEFINES_VENDOR_ID                       43
#define CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION                2
#define CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION                0
#define CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != DMA_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Dma_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Dma_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Dma_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != DMA_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != DMA_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Dma_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != CACHE_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Cache_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != CACHE_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Cache_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Cache_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != CACHE_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != CACHE_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Cache_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != TRGMUX_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Trgmux_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != TRGMUX_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Trgmux_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != TRGMUX_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != TRGMUX_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Trgmux_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != FLEXIO_MCL_IP_CFG_DEFINES_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Flexio_Mcl_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Flexio_Mcl_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != FLEXIO_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Flexio_Mcl_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Ftm_Mcl_Ip_Cfg.h file are of the same vendor */
#if (CDD_MCL_CFG_DEFINES_VENDOR_ID != FTM_MCL_IP_CFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg_Defines.h and Ftm_Mcl_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Ftm_Mcl_Ip_Cfg.h file are of the same Autosar version */
#if ((CDD_MCL_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FTM_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FTM_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != FTM_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg_Defines.h and Ftm_Mcl_Ip_Cfg.h are different"
#endif

/* Check if header file and Ftm_Mcl_Ip_Cfg.h file are of the same Software version */
#if ((CDD_MCL_CFG_DEFINES_SW_MAJOR_VERSION != FTM_MCL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_MINOR_VERSION != FTM_MCL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_MCL_CFG_DEFINES_SW_PATCH_VERSION != FTM_MCL_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcl_Cfg_Defines.h and Ftm_Mcl_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/*-----------------------------------------------/
/  DMA                                           /
/-----------------------------------------------*/
#define MCL_DMA_IS_AVAILABLE                       DMA_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  CACHE                                         /
/-----------------------------------------------*/
#define MCL_CACHE_IS_AVAILABLE                     CACHE_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  TRGMUX                                        /
/-----------------------------------------------*/
#define MCL_TRGMUX_IS_AVAILABLE                    TRGMUX_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  EMIOS                                         /
/-----------------------------------------------*/
#define MCL_EMIOS_IS_AVAILABLE                     STD_OFF

/*-----------------------------------------------/
/  ETIMER                                        /
/-----------------------------------------------*/
#define MCL_ETIMER_IS_AVAILABLE                    STD_OFF

/*-----------------------------------------------/
/  LCU                                           /
/-----------------------------------------------*/
#define MCL_LCU_IS_AVAILABLE                       STD_OFF

/*-----------------------------------------------/
/  FLEXIO                                        /
/-----------------------------------------------*/
#define MCL_FLEXIO_IS_AVAILABLE                    FLEXIO_IP_IS_AVAILABLE

/*-----------------------------------------------/
/  FTM                                           /
/-----------------------------------------------*/
#define MCL_COMMON_TIMEBASE_IS_AVAILABLE           FTM_MCL_SELECT_COMMON_TIMEBASE_API

/*-----------------------------------------------/
/  LLC                                           /
/-----------------------------------------------*/
#define MCL_LLC_IS_AVAILABLE                       STD_OFF

/*-----------------------------------------------/
/  SPFU                                          /
/-----------------------------------------------*/
#define MCL_SPFU_IS_AVAILABLE                      STD_OFF

/*-----------------------------------------------/
/  MULTICORE                                     /
/-----------------------------------------------*/
#define MCL_MULTICORE_IS_AVAILABLE                 STD_OFF

/*-----------------------------------------------/
/  VERSION INFO API                              /
/-----------------------------------------------*/
#define MCL_VERSION_INFO_API_IS_AVAILABLE          STD_OFF

#ifdef __cplusplus
}
#endif

#endif /* CDD_MCL_CFG_DEFINES_H_ */
