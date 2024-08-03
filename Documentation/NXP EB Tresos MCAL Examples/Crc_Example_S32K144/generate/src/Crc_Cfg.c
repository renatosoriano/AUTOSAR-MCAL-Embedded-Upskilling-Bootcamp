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
*   @file       Crc_Cfg.c
*   @implements Crc_Cfg.c_Artifact
*   @version    2.0.0
*
*   @brief      AUTOSAR Crc Configuration file for the driver.
*   @details    Precompile parameters and extern configuration.
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
#include "Crc_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRC_CFG_VENDOR_ID_C                      43
#define CRC_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CRC_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define CRC_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CRC_CFG_SW_MAJOR_VERSION_C               2
#define CRC_CFG_SW_MINOR_VERSION_C               0
#define CRC_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crc_Cfg.c and Crc_Cfg.h are of the same Autosar version */
#if (CRC_CFG_VENDOR_ID_C != CRC_CFG_VENDOR_ID)
    #error "Crc_Cfg.c and Crc_Cfg.h have different vendor ids"
#endif

/* Check if Crc_Cfg.c and CRC.h are of the same Autosar version */
#if ((CRC_CFG_AR_RELEASE_MAJOR_VERSION_C    != CRC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_CFG_AR_RELEASE_MINOR_VERSION_C    != CRC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRC_CFG_AR_RELEASE_REVISION_VERSION_C != CRC_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Cfg.c and Crc_Cfg.h are different"
#endif

/* Check if Crc_Cfg.c and CRC.h are of the same Software version */
#if ((CRC_CFG_SW_MAJOR_VERSION_C != CRC_CFG_SW_MAJOR_VERSION) || \
     (CRC_CFG_SW_MINOR_VERSION_C != CRC_CFG_SW_MINOR_VERSION) || \
     (CRC_CFG_SW_PATCH_VERSION_C != CRC_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Cfg.c and Crc_Cfg.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#define CRC_START_SEC_CONST_32
#include "Crc_MemMap.h"

/* CRC Autosar Channel */
const uint32 Crc_au32Crc8BitSaeJ1850[]     = {CRC_LOGIC_CHANNEL_0};
const uint32 Crc_au32Crc8BitH2f[]          = {CRC_IP_CHANNEL_INVALID_U32};
const uint32 Crc_au32Crc16BitCcittFalse[]  = {CRC_IP_CHANNEL_INVALID_U32};
const uint32 Crc_au32Crc16BitArc[]         = {CRC_IP_CHANNEL_INVALID_U32};
const uint32 Crc_au32Crc32BitEthernet[]    = {CRC_IP_CHANNEL_INVALID_U32};
const uint32 Crc_au32Crc32BitE2ep4[]       = {CRC_IP_CHANNEL_INVALID_U32};
const uint32 Crc_au32Crc64BitEcma[]        = {CRC_IP_CHANNEL_INVALID_U32};

#define CRC_STOP_SEC_CONST_32
#include "Crc_MemMap.h"


#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/**
 * @brief  Crc IP Logic Channel of Partition
 * */
static const uint32 Crc_ChannelOfPartition[] =
{
    CRC_LOGIC_CHANNEL_0,
    CRC_LOGIC_CHANNEL_1,
    CRC_LOGIC_CHANNEL_2
};

/**
 * @brief  Crc Partition Configuration
 * */
const Crc_PartitionType Crc_xConfigPartition =
{
    /* uint32 ChannelMax    */ 3U,
    /* uint32 * ChannelList */ &Crc_ChannelOfPartition[0]
};


/**
 * @brief  Configure CRC driver initialization
 * */
const Crc_InitType Crc_xConfigInit =
{
    &CrcIp_xConfigInit
};

#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
