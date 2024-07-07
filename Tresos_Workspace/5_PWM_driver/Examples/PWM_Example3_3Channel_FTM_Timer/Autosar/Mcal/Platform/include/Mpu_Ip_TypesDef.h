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
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
#ifndef MPU_IP_TYPESDEF_H
#define MPU_IP_TYPESDEF_H

/**
*   @file Mpu_Ip_TypesDef.h
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "BasicTypes.h"
#include "Mpu_Ip_Cfg_Defines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_VENDOR_ID                      43
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION       4
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION       7
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION    0
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION               2
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION               0
#define CDD_PLATFORM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION               0

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef PLATFORM_IP_ENABLE_MPU
#if (PLATFORM_IP_ENABLE_MPU == STD_ON)
/**
* @brief          Enumeration listing access permissions in supervisor mode
*/

typedef enum
{
    MPU_SUPERVISOR_MODE_RWX                = 0x00U,    /*!< 0b00U : rwx| */
    MPU_SUPERVISOR_MODE_RX                 = 0x01U,    /*!< 0b01U : r-x| */
    MPU_SUPERVISOR_MODE_RW                 = 0x02U,    /*!< 0b10U : rw-| */
    MPU_SUPERVISOR_MODE_AS_USER_MODE       = 0x03U     /*!< 0b11U : ---| */
} Mpu_Ip_SupervisorAccessModeType;

/**
* @brief          Enumeration listing access permissions in user mode
*/

typedef enum
{
    MPU_USER_MODE_NONE               = 0x00U,    /*!< 0b000U : ---| */
    MPU_USER_MODE_X                  = 0x01U,    /*!< 0b001U : --x| */
    MPU_USER_MODE_W                  = 0x02U,    /*!< 0b010U : -w-| */
    MPU_USER_MODE_WX                 = 0x03U,    /*!< 0b011U : -wx| */
    MPU_USER_MODE_R                  = 0x04U,    /*!< 0b100U : r--| */
    MPU_USER_MODE_RX                 = 0x05U,    /*!< 0b101U : r-x| */
    MPU_USER_MODE_RW                 = 0x06U,    /*!< 0b110U : rw-| */
    MPU_USER_MODE_RWX                = 0x07U     /*!< 0b111U : rwx| */
} Mpu_Ip_UserAccessModeType;
/**
* @brief          Enumeration listing masters
*/
typedef enum
{
   MPU_MASTER_CORE              = 0x00U,
   MPU_MASTER_DEBUGGER          = 0x01U,
   MPU_MASTER_DMA               = 0x02U,
   MPU_MASTER_ENET              = 0x03U,
   MPU_MASTER_UNKNOWN           = 0xFFU
} Mpu_Ip_MasterType;

/**
* @brief          Configuration structure containing the region configuration
*/

typedef struct
{
    uint32                              u32StartAddr;                  /*!< Memory region start address  - Word 0    */
    uint32                              u32EndAddr;                    /*!< Memory region end address    - Word 1    */
    uint32                              u32Word2;                      /*!< Access permission for region - Word 2    */
    uint32                              u32Pid;                        /*!< Process Identifier           - Word 3    */
    uint32                              u32PidMask;                    /*!< Process Identifier Mask      - Word 3    */
} Mpu_Ip_RegionConfigType;

/**
* @brief          IP configuration structure
*/
typedef struct
{
    uint8 u8RegionCnt;                                         /*!< Region Count */
    const Mpu_Ip_RegionConfigType * pRegionConfigArr;          /*!< Region configuration array */
    const uint8 * pRegionNumberArr;                            /*!< Region Number array */
} Mpu_Ip_ConfigType;

/**
* @brief          Structure used to retrieve error attributes details
*/
typedef enum
{
    MPU_USER_MODE_INSTRUCTION_ACCESS         = 0x00U,
    MPU_USER_MODE_DATA_ACCESS                = 0x01U,
    MPU_SUPERVISOR_MODE_INSTRUCTION_ACCESS   = 0x02U,
    MPU_SUPERVISOR_MODE_DATA_ACCESS          = 0x03U,
    MPU_ERROR_UNKNOWN                        = 0xFFU
} Mpu_Ip_ErrorAttributesType;

/**
* @brief          Structure used to retrieve error attributes details
*/
typedef enum
{
    MPU_ACCESS_READ                 = 0x0U,
    MPU_ACCESS_WRITE                = 0x1U
} Mpu_Ip_AccessType;

/**
* @brief          Structure used to retrieve violation details
*/
typedef struct
{
    uint32 u32Address;                            /*!< Violation address */
    uint16 u16EACD;                               /*!< Error Access Control Detail */
    Mpu_Ip_MasterType eMaster;                       /*!< Violation master */
    Mpu_Ip_ErrorAttributesType  eErrorAttribute;  /*!< Type of Attribute violation */
    Mpu_Ip_AccessType           eErrorAccess;     /*!< Type of Access violation */
} Mpu_Ip_ErrorDetailsType;

#endif /* PLATFORM_IP_ENABLE_MPU == STD_ON */
#endif /* PLATFORM_IP_ENABLE_MPU */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_IP_TYPESDEF_H */
