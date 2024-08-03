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

/* Prevention from multiple including the same header */
#ifndef DMA_IP_CFG_DEFINES_H_
#define DMA_IP_CFG_DEFINES_H_

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
#include "StandardTypes.h"
#include "BasicTypes.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_CFG_DEFINES_VENDOR_ID                       43
#define DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define DMA_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define DMA_IP_CFG_DEFINES_SW_MAJOR_VERSION                2
#define DMA_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define DMA_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((DMA_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Dma_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/*-----------------------------------------------/
/  DMA IP USER MODE SUPPORT                      /
/-----------------------------------------------*/
#define DMA_IP_USER_MODE_SUPPORT_IS_AVAILABLE            STD_OFF

#define DMA_IP_REG_PROT_AVAILABLE                        STD_OFF
#define DMA_IP_MP_REG_PROT_AVAILABLE                     STD_OFF
#define DMA_IP_TCD_REG_PROT_AVAILABLE                    STD_OFF

/*-----------------------------------------------/
/  DMA IP SUPPORT                                /
/-----------------------------------------------*/
#define DMA_IP_IS_AVAILABLE                              STD_OFF

#define DMA_IP_DMACRC_IS_AVAILABLE                       STD_OFF

#define DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE      STD_OFF

#define DMA_IP_MULTICORE_IS_AVAILABLE                    STD_OFF

#define DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE        STD_OFF

#define DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE            STD_OFF

#define DMA_IP_SECURITY_LEVEL_IS_AVAILABLE               STD_OFF

#define DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE             STD_OFF

#define DMA_IP_BUFFERED_WRITES_IS_AVAILABLE              STD_OFF

#define DMA_IP_STORE_DST_ADDR_IS_AVAILABLE               STD_OFF

#define DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE         STD_OFF

#define DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE            STD_OFF

#define DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE        STD_OFF

#define DMA_IP_PREEMPTION_IS_AVAILABLE                   STD_OFF

#define DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE              STD_OFF

#define DMA_IP_GROUP_PRIORITY_IS_AVAILABLE               STD_OFF

#define DMA_IP_SWAP_SIZE_IS_AVAILABLE                    STD_OFF

/*-----------------------------------------------/
/  DMA IP DEV ERROR DETECT SUPPORT               /
/-----------------------------------------------*/
#define DMA_IP_DEV_ERROR_DETECT                          STD_OFF


#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DMA_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
