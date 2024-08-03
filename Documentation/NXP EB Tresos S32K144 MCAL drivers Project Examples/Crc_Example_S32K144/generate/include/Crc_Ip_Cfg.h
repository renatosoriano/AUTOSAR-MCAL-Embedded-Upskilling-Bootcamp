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

/* Prevention from multiple including the same header */
#ifndef CRC_IP_CFG_H
#define CRC_IP_CFG_H

/**
*   @file       Crc_Ip_Cfg.h
*   @implements Crc_Ip_Cfg.h_Artifact
*   @version    2.0.0
*
*   @brief      AUTOSAR Crc Post-Build(PB) configuration file code template.
*   @details    Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CRC_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crc_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRC_IP_CFG_VENDOR_ID                      43
#define CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_CFG_AR_RELEASE_MINOR_VERSION       7
#define CRC_IP_CFG_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_CFG_SW_MAJOR_VERSION               2
#define CRC_IP_CFG_SW_MINOR_VERSION               0
#define CRC_IP_CFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ip_Cfg.h and Crc_Ip_Types.h are of the same version */
#if (CRC_IP_CFG_VENDOR_ID != CRC_IP_TYPES_VENDOR_ID)
    #error "Crc_Ip_Cfg.h and Crc_Ip_Types.h have different vendor ids"
#endif

/* Check if Crc_Ip_Cfg.h and Crc_Ip_Types.h are of the same Autosar version */
#if ((CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_MINOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_REVISION_VERSION != CRC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Cfg.h and Crc_Ip_Types.h are different"
#endif

/* Check if Crc_Ip_Cfg.h and Crc_Ip_Types.h are of the same Software version */
#if ((CRC_IP_CFG_SW_MAJOR_VERSION != CRC_IP_TYPES_SW_MAJOR_VERSION) || \
     (CRC_IP_CFG_SW_MINOR_VERSION != CRC_IP_TYPES_SW_MINOR_VERSION) || \
     (CRC_IP_CFG_SW_PATCH_VERSION != CRC_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Cfg.h and Crc_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Number Of Configured Logic Channel */
#define CRC_IP_NUM_LOGIC_CHANNEL_MAX                   ((uint32)3U)

/* Logic Channel Name */
#define CRC_LOGIC_CHANNEL_0                             ((uint32)0U)
#define CRC_LOGIC_CHANNEL_1                             ((uint32)1U)
#define CRC_LOGIC_CHANNEL_2                             ((uint32)2U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"
/**
 * @brief  Crc Ip Initialization
 * */
extern const Crc_Ip_InitType CrcIp_xConfigInit;

#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_CFG_H */
