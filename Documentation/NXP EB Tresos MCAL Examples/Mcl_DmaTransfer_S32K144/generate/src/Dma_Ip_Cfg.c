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
#include "Dma_Ip_Cfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_VENDOR_ID_C                       43
#define DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define DMA_IP_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define DMA_IP_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define DMA_IP_CFG_SW_MAJOR_VERSION_C                2
#define DMA_IP_CFG_SW_MINOR_VERSION_C                0
#define DMA_IP_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_Cfg.c file and Dma_Ip_Cfg.h file are of the same vendor */
#if (DMA_IP_CFG_VENDOR_ID_C != DMA_IP_CFG_VENDOR_ID)
    #error "Dma_Ip_Cfg.c and Dma_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Dma_Ip_Cfg.c file and Dma_Ip_Cfg.h file are of the same Autosar version */
#if ((DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_CFG_AR_RELEASE_REVISION_VERSION_C != DMA_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Cfg.c and Dma_Ip_Cfg.h are different"
#endif

/* Check if Dma_Ip_Cfg.c file and Dma_Ip_Cfg.h file are of the same Software version */
#if ((DMA_IP_CFG_SW_MAJOR_VERSION_C != DMA_IP_CFG_SW_MAJOR_VERSION) || \
     (DMA_IP_CFG_SW_MINOR_VERSION_C != DMA_IP_CFG_SW_MINOR_VERSION) || \
     (DMA_IP_CFG_SW_PATCH_VERSION_C != DMA_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Cfg.c and Dma_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2012 violations
**/




#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/* DMA Logic Instance Reset Configuration */
const Dma_Ip_LogicInstanceConfigType Dma_Ip_xLogicInstanceResetConfig =
{
    {
        /* uint32 logicInstId; */ 0U,
        /* uint8 hwVersId;     */ DMA_IP_HARDWARE_VERSION_2,
        /* uint8 hwInst;       */ 0U,
    },
    /* boolean EnDebug; */                 (boolean)FALSE,
    /* boolean EnRoundRobin; */            (boolean)FALSE,
    /* boolean EnHaltAfterError; */        (boolean)FALSE,
    /* boolean EnChLinking; */             (boolean)FALSE,
    /* boolean EnGlMasterIdReplication; */ (boolean)FALSE,
};

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"



#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/* DMA Logic Channel Reset Configuration */
const Dma_Ip_GlobalConfigType GlobalResetConfig =
{
    {
        /* boolean EnMasterIdReplication; */ (boolean)FALSE,
        /* boolean EnBufferedWrites; */      (boolean)FALSE,
    }, /* Control */
    {
        /* boolean EnRequest; */             (boolean)FALSE,
    }, /* Request */
    {
        /* boolean EnErrorInt; */            (boolean)FALSE,
    }, /* Interrupt */
       {
        /* uint8 SwapSize; */                0U,
    }, /* Swap */
    {
        /* uint8 Group; */                   0U,
        /* uint8 Level; */                   0U,
        /* boolean EnPreemption; */          (boolean)FALSE,
        /* boolean DisPreempt; */            (boolean)FALSE,
    }, /* Priority */
};

const Dma_Ip_TransferConfigType TransferResetConfig =
{
    {
        /* uint32 ScatterGatherAddr; */      0U,
        /* uint32 DestinationStoreAddr; */   0,
        /* uint8 BandwidthControl; */        0,
        /* uint8 TransferModeControl; */     0,
        /* boolean EnStart; */               (boolean)FALSE,
        /* boolean EnMajorInt; */            (boolean)FALSE,
        /* boolean EnHalfMajorInt; */        (boolean)FALSE,
        /* boolean DisAutoHwRequest; */      (boolean)FALSE,
        /* boolean EnEndOfPacketSignal; */   (boolean)FALSE,
    }, /* Control */
    {
        /* uint32 Addr; */         0U,
        /* sint32 LastAddrAdj; */  0,
        /* sint16 SignedOffset; */ 0,
        /* uint8 TransferSize; */  0U,
        /* uint8 Modulo; */        0U,
    }, /* Source */
    {
        /* uint32 Addr; */         0U,
        /* sint32 LastAddrAdj; */  0,
        /* sint16 SignedOffset; */ 0,
        /* uint8 TransferSize; */  0U,
        /* uint8 Modulo; */        0U,
    }, /* Destination */
    {
        /* uint32 Size; */         0U,
        /* sint32 Offset; */       0,
        /* uint8 LogicLinkCh; */   0U,
        /* boolean EnLink; */      (boolean)FALSE,
        /* boolean EnSrcOffset; */ (boolean)FALSE,
        /* boolean EnDstOffset; */ (boolean)FALSE,
    }, /* MinorLoop */
    {
        /* uint16 Count; */        0U,
        /* uint8 LogicLinkCh; */   0U,
        /* boolean EnLink; */      (boolean)FALSE,
    }, /* MajorLoop */
};

const Dma_Ip_LogicChannelConfigType Dma_Ip_xLogicChannelResetConfig =
{
    {
        /* uint32 logicChId; */               0U,
        /* uint8 hwVersId; */                 DMA_IP_HARDWARE_VERSION_2,
        /* uint8 hwInst; */                   0U,
        /* uint8 hwChId; */                   0U,
        /* Dma_Ip_Callback IntCallback; */    NULL_PTR,
        /* Dma_Ip_Callback ErrIntCallback; */ NULL_PTR,
    }, /* Dma_Ip_LogicChannelIdType */
    &GlobalResetConfig,
    &TransferResetConfig,
    NULL_PTR,
};

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"


#ifdef __cplusplus
}
#endif

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
