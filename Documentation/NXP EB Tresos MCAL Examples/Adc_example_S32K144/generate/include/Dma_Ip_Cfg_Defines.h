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
#define DMA_IP_IS_AVAILABLE                              STD_ON

#define DMA_IP_DMACRC_IS_AVAILABLE                       STD_OFF

/*-----------------------------------------------/
/  DMA IP VIRTUAL ADDRESS MAPPING SUPPORT        /
/-----------------------------------------------*/
#define DMA_IP_VIRTUAL_ADDRESS_MAPPING_IS_AVAILABLE      STD_ON

#define DMA_IP_MULTICORE_IS_AVAILABLE                    STD_OFF

#define DMA_IP_MASTER_ID_REPLICATION_IS_AVAILABLE        STD_OFF

#define DMA_IP_TRANSACTIONS_TYPE_IS_AVAILABLE            STD_OFF

#define DMA_IP_SECURITY_LEVEL_IS_AVAILABLE               STD_OFF

#define DMA_IP_PROTECTION_LEVEL_IS_AVAILABLE             STD_OFF

#define DMA_IP_BUFFERED_WRITES_IS_AVAILABLE              STD_OFF

#define DMA_IP_STORE_DST_ADDR_IS_AVAILABLE               STD_OFF

#define DMA_IP_END_OF_PACKET_SIGNAL_IS_AVAILABLE         STD_OFF

#define DMA_IP_BANDWIDTH_CONTROL_IS_AVAILABLE            STD_ON

#define DMA_IP_TRANSFER_MODE_CONTROL_IS_AVAILABLE        STD_OFF

#define DMA_IP_PREEMPTION_IS_AVAILABLE                   STD_ON

#define DMA_IP_DISABLE_PREEMPT_IS_AVAILABLE              STD_ON

#define DMA_IP_GROUP_PRIORITY_IS_AVAILABLE               STD_OFF

#define DMA_IP_SWAP_SIZE_IS_AVAILABLE                    STD_OFF

/*-----------------------------------------------/
/  DMA IP DEV ERROR DETECT SUPPORT               /
/-----------------------------------------------*/
#define DMA_IP_DEV_ERROR_DETECT                          STD_OFF

/*-----------------------------------------------/
/  DMA HARDWARE VERSION                          /
/-----------------------------------------------*/
#define DMA_IP_HWV2_IS_AVAILABLE                         STD_ON
#define DMA_IP_HARDWARE_VERSION_2                        ((uint8)2U)
#define DMA_IP_HWV3_IS_AVAILABLE                         STD_OFF
#define DMA_IP_HARDWARE_VERSION_3                        ((uint8)3U)

/*-------------------------------------------------------/
/  DMA PARAM LIST DIMENASION RELATED TO HARDWARE VERSION /
/-------------------------------------------------------*/
#define DMA_IP_HWV2_LOC_GLOBAL_PARAM_LIST_DIMENSION    ((uint32)7U)

/*-----------------------------------------------/
/  DMA HARDWARE INSTANCES                        /
/-----------------------------------------------*/
#define DMA_IP_HW_INST_0                                 ((uint8)(0U))

/*-----------------------------------------------/
/  DMA HARDWARE CHANNELS                         /
/-----------------------------------------------*/
#define DMA_IP_HW_CH_0                                   ((uint8)(0U))
#define DMA_IP_HW_CH_1                                   ((uint8)(1U))
#define DMA_IP_HW_CH_2                                   ((uint8)(2U))
#define DMA_IP_HW_CH_3                                   ((uint8)(3U))
#define DMA_IP_HW_CH_4                                   ((uint8)(4U))
#define DMA_IP_HW_CH_5                                   ((uint8)(5U))
#define DMA_IP_HW_CH_6                                   ((uint8)(6U))
#define DMA_IP_HW_CH_7                                   ((uint8)(7U))
#define DMA_IP_HW_CH_8                                   ((uint8)(8U))
#define DMA_IP_HW_CH_9                                   ((uint8)(9U))
#define DMA_IP_HW_CH_10                                  ((uint8)(10U))
#define DMA_IP_HW_CH_11                                  ((uint8)(11U))
#define DMA_IP_HW_CH_12                                  ((uint8)(12U))
#define DMA_IP_HW_CH_13                                  ((uint8)(13U))
#define DMA_IP_HW_CH_14                                  ((uint8)(14U))
#define DMA_IP_HW_CH_15                                  ((uint8)(15U))

/*-----------------------------------------------/
/  DMA CHANNEL PRIORITY                          /
/-----------------------------------------------*/
#define DMA_IP_LEVEL_PRIO0                               ((uint8)(0U))
#define DMA_IP_LEVEL_PRIO1                               ((uint8)(1U))
#define DMA_IP_LEVEL_PRIO2                               ((uint8)(2U))
#define DMA_IP_LEVEL_PRIO3                               ((uint8)(3U))
#define DMA_IP_LEVEL_PRIO4                               ((uint8)(4U))
#define DMA_IP_LEVEL_PRIO5                               ((uint8)(5U))
#define DMA_IP_LEVEL_PRIO6                               ((uint8)(6U))
#define DMA_IP_LEVEL_PRIO7                               ((uint8)(7U))
#define DMA_IP_LEVEL_PRIO8                               ((uint8)(8U))
#define DMA_IP_LEVEL_PRIO9                               ((uint8)(9U))
#define DMA_IP_LEVEL_PRIO10                              ((uint8)(10U))
#define DMA_IP_LEVEL_PRIO11                              ((uint8)(11U))
#define DMA_IP_LEVEL_PRIO12                              ((uint8)(12U))
#define DMA_IP_LEVEL_PRIO13                              ((uint8)(13U))
#define DMA_IP_LEVEL_PRIO14                              ((uint8)(14U))
#define DMA_IP_LEVEL_PRIO15                              ((uint8)(15U))
/*-----------------------------------------------/
/  DMA TRANSFER SIZE                             /
/-----------------------------------------------*/
#define DMA_IP_TRANSFER_SIZE_1_BYTE                      ((uint8)(0U))
#define DMA_IP_TRANSFER_SIZE_2_BYTE                      ((uint8)(1U))
#define DMA_IP_TRANSFER_SIZE_4_BYTE                      ((uint8)(2U))
#define DMA_IP_TRANSFER_SIZE_16_BYTE                     ((uint8)(4U))
#define DMA_IP_TRANSFER_SIZE_32_BYTE                     ((uint8)(5U))

/*-----------------------------------------------/
/  DMA BANDWIDTH CONTROL                         /
/-----------------------------------------------*/
#define DMA_IP_BWC_ENGINE_NO_STALL                       ((uint8)(0U))
#define DMA_IP_BWC_ENGINE_4CYCLE_STALL                   ((uint8)(2U))
#define DMA_IP_BWC_ENGINE_8CYCLE_STALL                   ((uint8)(3U))

/*-----------------------------------------------/
/  DMA CONVERT DCHPRI                            /
/-----------------------------------------------*/
#define DMA_CHN_TO_DCHPRI_INDEX(x)                       ((x) ^ 3U)


#ifdef __cplusplus
}
#endif

#endif  /* #ifndef DMA_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
