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

/**
*   @file Dma_Mux_Ip_VS_0_PBcfg.c
*
*   @addtogroup DMA_MUX_IP DMA_MUX IPV Driver
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
#include "Dma_Mux_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_DMA_MUX_IP_VS_0_PBCFG_VENDOR_ID_C                     43
#define RM_DMA_MUX_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_DMA_MUX_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_DMA_MUX_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_DMA_MUX_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C              2
#define RM_DMA_MUX_IP_VS_0_PBCFG_SW_MINOR_VERSION_C              0
#define RM_DMA_MUX_IP_VS_0_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Dma_Mux_Ip_Cfg.h */
#if (RM_DMA_MUX_IP_VS_0_PBCFG_VENDOR_ID_C != RM_DMA_MUX_IP_CFG_VENDOR_ID)
    #error "Dma_Mux_Ip_VS_0_PBcfg.c and Dma_Mux_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_DMA_MUX_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_DMA_MUX_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_DMA_MUX_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_DMA_MUX_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_DMA_MUX_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_DMA_MUX_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dma_Mux_Ip_VS_0_PBcfg.c and Dma_Mux_Ip_Cfg.h are different"
#endif
#if ((RM_DMA_MUX_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != RM_DMA_MUX_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_DMA_MUX_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != RM_DMA_MUX_IP_CFG_SW_MINOR_VERSION) || \
     (RM_DMA_MUX_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != RM_DMA_MUX_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Mux_Ip_VS_0_PBcfg.c and Dma_Mux_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

#define DMAMUX_CHANNEL_CFG_ENBL_MASK        DMAMUX_CHCFG_ENBL_MASK
#define DMAMUX_CHANNEL_CFG_TRIG                DMAMUX_CHCFG_TRIG
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
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"


static const Dma_Mux_Ip_ChannelConfigType Dma_Mux_Channel_Config_VS_0[4] =
{
    {
        DMA_MUX_INSTANCE_0,
        0U,
        (DMA_MUX_0_ADC_0_DMA_REQUEST | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG(0U))
    },
    {
        DMA_MUX_INSTANCE_0,
        1U,
        (DMA_MUX_0_ADC_1_DMA_REQUEST | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG(0U))
    },
    {
        DMA_MUX_INSTANCE_0,
        2U,
        (DMA_MUX_0_REQ_DISABLED | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG(0U))
    },
    {
        DMA_MUX_INSTANCE_0,
        3U,
        (DMA_MUX_0_REQ_DISABLED | DMAMUX_CHANNEL_CFG_ENBL_MASK | DMAMUX_CHANNEL_CFG_TRIG(0U))
    }
};

const Dma_Mux_Ip_ConfigType Dma_Mux_Config_VS_0 =
{
    4U,
    Dma_Mux_Channel_Config_VS_0
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
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

