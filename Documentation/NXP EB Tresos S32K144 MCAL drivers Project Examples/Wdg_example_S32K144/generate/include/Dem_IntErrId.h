/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   (c) Copyright 2020-2024 NXP Semiconductors
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

#ifndef DEM_INTERRID_H
#define DEM_INTERRID_H

/**
*   @file Dem_IntErrId.h
*
*   @addtogroup DEM_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEM_INTERRID_VENDOR_ID 43
#define DEM_INTERRID_MODULE_ID 54

#define DEM_INTERRID_AR_RELEASE_MAJOR_VERSION       4
#define DEM_INTERRID_AR_RELEASE_MINOR_VERSION       7
#define DEM_INTERRID_AR_RELEASE_REVISION_VERSION    0
#define DEM_INTERRID_SW_MAJOR_VERSION               2
#define DEM_INTERRID_SW_MINOR_VERSION               0
#define DEM_INTERRID_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#include "Dem_Types.h"
#include "Rte_Dem_Type.h"

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
      
  
/** @brief Identifier for DEM error FLS_E_ERASE_FAILED*/
#define DemConf_DemEventParameter_FLS_E_ERASE_FAILED   ((Dem_EventIdType) 0x4)

/** @brief Identifier for DEM error FLS_E_READ_FAILED*/
#define DemConf_DemEventParameter_FLS_E_READ_FAILED   ((Dem_EventIdType) 0x5)

/** @brief Identifier for DEM error FLS_E_UNEXPECTED_FLASH_ID*/
#define DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID   ((Dem_EventIdType) 0x7)

/** @brief Identifier for DEM error FLS_E_WRITE_FAILED*/
#define DemConf_DemEventParameter_FLS_E_WRITE_FAILED   ((Dem_EventIdType) 0x3)

/** @brief Identifier for DEM error GPT_E_FORBIDDEN_INVOCATION*/
#define DemConf_DemEventParameter_GPT_E_FORBIDDEN_INVOCATION   ((Dem_EventIdType) 0x18)

/** @brief Identifier for DEM error GPT_E_PERIODIC_CHECK*/
#define DemConf_DemEventParameter_GPT_E_PERIODIC_CHECK   ((Dem_EventIdType) 0x19)

/** @brief Identifier for DEM error MCEM_E_ERROR*/
#define DemConf_DemEventParameter_MCEM_E_ERROR   ((Dem_EventIdType) 0x6)

/** @brief Identifier for DEM error MCEM_E_ERROR_BACK*/
#define DemConf_DemEventParameter_MCEM_E_ERROR_BACK   ((Dem_EventIdType) 0x1)

/** @brief Identifier for DEM error MCL_DMA_E_BUS*/
#define DemConf_DemEventParameter_MCL_DMA_E_BUS   ((Dem_EventIdType) 0x14)

/** @brief Identifier for DEM error MCL_DMA_E_DESCRIPTOR*/
#define DemConf_DemEventParameter_MCL_DMA_E_DESCRIPTOR   ((Dem_EventIdType) 0x14)

/** @brief Identifier for DEM error MCL_DMA_E_ECC*/
#define DemConf_DemEventParameter_MCL_DMA_E_ECC   ((Dem_EventIdType) 0x14)

/** @brief Identifier for DEM error MCL_DMA_E_PRIORITY*/
#define DemConf_DemEventParameter_MCL_DMA_E_PRIORITY   ((Dem_EventIdType) 0x14)

/** @brief Identifier for DEM error MCU_E_CER_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_CER_FAILURE   ((Dem_EventIdType) 0x13)

/** @brief Identifier for DEM error MCU_E_CLOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE   ((Dem_EventIdType) 0x1)

/** @brief Identifier for DEM error MCU_E_DEFAULTCASE_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_DEFAULTCASE_FAILURE   ((Dem_EventIdType) 0x2)

/** @brief Identifier for DEM error MCU_E_DESTRESET_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_DESTRESET_FAILURE   ((Dem_EventIdType) 0xc)

/** @brief Identifier for DEM error MCU_E_FORBIDDEN_INVOCATION*/
#define DemConf_DemEventParameter_MCU_E_FORBIDDEN_INVOCATION   ((Dem_EventIdType) 0x3)

/** @brief Identifier for DEM error MCU_E_FUNCRESET_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_FUNCRESET_FAILURE   ((Dem_EventIdType) 0x4)

/** @brief Identifier for DEM error MCU_E_INVALIDMODE*/
#define DemConf_DemEventParameter_MCU_E_INVALIDMODE   ((Dem_EventIdType) 0xf)

/** @brief Identifier for DEM error MCU_E_INVALIDMODE_CONFIG*/
#define DemConf_DemEventParameter_MCU_E_INVALIDMODE_CONFIG   ((Dem_EventIdType) 0x10)

/** @brief Identifier for DEM error MCU_E_INVALID_PARAMETER*/
#define DemConf_DemEventParameter_MCU_E_INVALID_PARAMETER   ((Dem_EventIdType) 0x5)

/** @brief Identifier for DEM error MCU_E_LOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_LOCK_FAILURE   ((Dem_EventIdType) 0xb)

/** @brief Identifier for DEM error MCU_E_MEMORY_CORRUPTION*/
#define DemConf_DemEventParameter_MCU_E_MEMORY_CORRUPTION   ((Dem_EventIdType) 0x6)

/** @brief Identifier for DEM error MCU_E_MODE_TRANSTION_COMPLETE*/
#define DemConf_DemEventParameter_MCU_E_MODE_TRANSTION_COMPLETE   ((Dem_EventIdType) 0xe)

/** @brief Identifier for DEM error MCU_E_PLLLOCK_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_PLLLOCK_FAILURE   ((Dem_EventIdType) 0x7)

/** @brief Identifier for DEM error MCU_E_QUARTZ_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_QUARTZ_FAILURE   ((Dem_EventIdType) 0x8)

/** @brief Identifier for DEM error MCU_E_SAFEMODE_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_SAFEMODE_FAILURE   ((Dem_EventIdType) 0xd)

/** @brief Identifier for DEM error MCU_E_SPURIOUSINT_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_SPURIOUSINT_FAILURE   ((Dem_EventIdType) 0x9)

/** @brief Identifier for DEM error MCU_E_SSCM_CER_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_SSCM_CER_FAILURE   ((Dem_EventIdType) 0x14)

/** @brief Identifier for DEM error MCU_E_SWITCHMODE_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_SWITCHMODE_FAILURE   ((Dem_EventIdType) 0xa)

/** @brief Identifier for DEM error MCU_E_TEMPERATURE_ERROR*/
#define DemConf_DemEventParameter_MCU_E_TEMPERATURE_ERROR   ((Dem_EventIdType) 0x12)

/** @brief Identifier for DEM error MCU_E_TIMEOUT_FAILURE*/
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_FAILURE   ((Dem_EventIdType) 0xb)

/** @brief Identifier for DEM error MCU_E_TIMEOUT_TRANSITION*/
#define DemConf_DemEventParameter_MCU_E_TIMEOUT_TRANSITION   ((Dem_EventIdType) 0xd)

/** @brief Identifier for DEM error MCU_E_VOLTAGE_ERROR*/
#define DemConf_DemEventParameter_MCU_E_VOLTAGE_ERROR   ((Dem_EventIdType) 0x11)

/** @brief Identifier for DEM error WDG_E_CORRUPT_CONFIG*/
#define DemConf_DemEventParameter_WDG_E_CORRUPT_CONFIG   ((Dem_EventIdType) 0x13)

/** @brief Identifier for DEM error WDG_E_DISABLE_REJECTED*/
#define DemConf_DemEventParameter_WDG_E_DISABLE_REJECTED   ((Dem_EventIdType) 0x11)

/** @brief Identifier for DEM error WDG_E_FORBIDDEN_INVOCATION*/
#define DemConf_DemEventParameter_WDG_E_FORBIDDEN_INVOCATION   ((Dem_EventIdType) 0x16)

/** @brief Identifier for DEM error WDG_E_FORBIDEN_INVOCATION*/
#define DemConf_DemEventParameter_WDG_E_FORBIDEN_INVOCATION   ((Dem_EventIdType) 0x16)

/** @brief Identifier for DEM error WDG_E_INVALID_CALL*/
#define DemConf_DemEventParameter_WDG_E_INVALID_CALL   ((Dem_EventIdType) 0x17)

/** @brief Identifier for DEM error WDG_E_INVALID_PARAMETER*/
#define DemConf_DemEventParameter_WDG_E_INVALID_PARAMETER   ((Dem_EventIdType) 0x15)

/** @brief Identifier for DEM error WDG_E_MEMORY_CORRUPTION*/
#define DemConf_DemEventParameter_WDG_E_MEMORY_CORRUPTION   ((Dem_EventIdType) 0x13)

/** @brief Identifier for DEM error WDG_E_MISS_TRIGGER*/
#define DemConf_DemEventParameter_WDG_E_MISS_TRIGGER   ((Dem_EventIdType) 0x12)

/** @brief Identifier for DEM error WDG_E_MODE_FAILED*/
#define DemConf_DemEventParameter_WDG_E_MODE_FAILED   ((Dem_EventIdType) 0x10)

/** @brief Identifier for DEM error WDG_E_UNLOCKED*/
#define DemConf_DemEventParameter_WDG_E_UNLOCKED   ((Dem_EventIdType) 0x14)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DEM_INTERRID_H */
