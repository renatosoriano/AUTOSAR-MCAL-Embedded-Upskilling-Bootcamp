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
*   @file       Crc_Ip_Cfg.c
*   @implements Crc_Ip_Cfg.c_Artifact
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
#include "Crc_Ip_Cfg.h"
#include "Dma_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define CRC_IP_CFG_VENDOR_ID_C                      43
#define CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CRC_IP_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define CRC_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CRC_IP_CFG_SW_MAJOR_VERSION_C               2
#define CRC_IP_CFG_SW_MINOR_VERSION_C               0
#define CRC_IP_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Crc header file are of the same vendor */
#if (CRC_IP_CFG_VENDOR_ID_C != CRC_IP_CFG_VENDOR_ID)
    #error "CRC_Ip_Cfg.c and CRC_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Crc header file are of the same Autosar version */
#if ((CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CRC_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CRC_Ip_Cfg.c and CRC_Ip_Cfg.h are different"
#endif
/* Check if current file and Crc header file are of the same Software version */
#if ((CRC_IP_CFG_SW_MAJOR_VERSION_C != CRC_IP_CFG_SW_MAJOR_VERSION) || \
     (CRC_IP_CFG_SW_MINOR_VERSION_C != CRC_IP_CFG_SW_MINOR_VERSION) || \
     (CRC_IP_CFG_SW_PATCH_VERSION_C != CRC_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CRC_Ip_Cfg.c and CRC_Ip_Cfg.h are different"
#endif

/* Check if current file and Dma_Ip_Cfg.h header file are of the same vendor */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if CDD_Mcl.c file and Mcal header file are of the same Autosar version */
#if ((CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_MINOR_VERSION_C != DMA_IP_CFG_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CRC_Ip_Cfg.c and Dma_Ip_Cfg.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
/* Generated Look-Up Tables */



/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


#define CRC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief CRC Logic Channel 0 Configuration
**/
static Crc_Ip_LogicChannelConfigType LogicChannelCfg_0 =
{
    /* Crc_Ip_ProtocolType Protocol         */ CRC_PROTOCOL_8BIT_SAE_J1850,
    /* uint64  PolynomialValue              */ 0x1dU,
    /* boolean WriteBitSwap                 */ (boolean)FALSE,
    /* boolean WriteByteSwap                */ (boolean)FALSE,
    /* boolean ReadBitSwap                  */ (boolean)FALSE,
    /* boolean ReadByteSwap                 */ (boolean)FALSE,
    /* boolean InverseEnable                */ (boolean)TRUE,
    /* Look-Up Table Address                */ NULL_PTR
};
#define CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief CRC Logic Channel Type 0 Configuration
**/
static const Crc_Ip_LogicChannelType LogicChannelType_0 =
{
    /* uint8 CalculationType                               */ CRC_IP_TABLE_CALCULATION,
    /* uint8 HwInstance                                    */ CRC_HW_INSTANCE_0,
    /* uint8 HwChannel                                     */ CRC_HW_CHANNEL_0,
    /* boolean DmaLogicChannelEnable                       */ (boolean)FALSE,
    /* uint32 DmaLogicChannelName                          */ DMA_LOGIC_CH_0,
    /* Crc_Ip_DmaTransferSize DmaLogicChannelTransferSize  */ CRC_DMA_TRANSFER_SIZE_1_BYTE,
    /* uint8 DmaLogicChannelOffset                         */ (1U),
    /* LogicChannelConfig                                  */ &LogicChannelCfg_0
};
#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief CRC Logic Channel 1 Configuration
**/
static Crc_Ip_LogicChannelConfigType LogicChannelCfg_1 =
{
    /* Crc_Ip_ProtocolType Protocol         */ CRC_PROTOCOL_16BIT_CCITT_FALSE,
    /* uint64  PolynomialValue              */ 0x1021U,
    /* boolean WriteBitSwap                 */ (boolean)FALSE,
    /* boolean WriteByteSwap                */ (boolean)FALSE,
    /* boolean ReadBitSwap                  */ (boolean)FALSE,
    /* boolean ReadByteSwap                 */ (boolean)FALSE,
    /* boolean InverseEnable                */ (boolean)FALSE,
    /* Look-Up Table Address                */ NULL_PTR
};
#define CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief CRC Logic Channel Type 1 Configuration
**/
static const Crc_Ip_LogicChannelType LogicChannelType_1 =
{
    /* uint8 CalculationType                               */ CRC_IP_RUNTIME_CALCULATION,
    /* uint8 HwInstance                                    */ CRC_HW_INSTANCE_0,
    /* uint8 HwChannel                                     */ CRC_HW_CHANNEL_0,
    /* boolean DmaLogicChannelEnable                       */ (boolean)FALSE,
    /* uint32 DmaLogicChannelName                          */ DMA_LOGIC_CH_0,
    /* Crc_Ip_DmaTransferSize DmaLogicChannelTransferSize  */ CRC_DMA_TRANSFER_SIZE_1_BYTE,
    /* uint8 DmaLogicChannelOffset                         */ (1U),
    /* LogicChannelConfig                                  */ &LogicChannelCfg_1
};
#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief CRC Logic Channel 2 Configuration
**/
static Crc_Ip_LogicChannelConfigType LogicChannelCfg_2 =
{
    /* Crc_Ip_ProtocolType Protocol         */ CRC_PROTOCOL_32BIT_ETHERNET,
    /* uint64  PolynomialValue              */ 0x4c11db7U,
    /* boolean WriteBitSwap                 */ (boolean)TRUE,
    /* boolean WriteByteSwap                */ (boolean)FALSE,
    /* boolean ReadBitSwap                  */ (boolean)TRUE,
    /* boolean ReadByteSwap                 */ (boolean)TRUE,
    /* boolean InverseEnable                */ (boolean)TRUE,
    /* Look-Up Table Address                */ NULL_PTR
};
#define CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief CRC Logic Channel Type 2 Configuration
**/
static const Crc_Ip_LogicChannelType LogicChannelType_2 =
{
    /* uint8 CalculationType                               */ CRC_IP_HARDWARE_CALCULATION,
    /* uint8 HwInstance                                    */ CRC_HW_INSTANCE_0,
    /* uint8 HwChannel                                     */ CRC_HW_CHANNEL_0,
    /* boolean DmaLogicChannelEnable                       */ (boolean)TRUE,
    /* uint32 DmaLogicChannelName                          */ DMA_LOGIC_CH_0,
    /* Crc_Ip_DmaTransferSize DmaLogicChannelTransferSize  */ CRC_DMA_TRANSFER_SIZE_1_BYTE,
    /* uint8 DmaLogicChannelSignedOffset                   */ (1U),
    /* LogicChannelConfig                                  */ &LogicChannelCfg_2
};
#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"


#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/**
 * @brief  Crc Ip List Logic Channel Configuration
 * */
static const Crc_Ip_LogicChannelType * const paxLogicChannelConfig[] =
{
    &LogicChannelType_0,
    &LogicChannelType_1,
    &LogicChannelType_2
};

/**
 * @brief  Crc Ip Initialization
 * */
const Crc_Ip_InitType CrcIp_xConfigInit =
{
    /* LogicChannelConfigList */ paxLogicChannelConfig
};

#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

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
